//     Project: openETCS libenvsim
//      Module: tcl / track.c
// Description: Tcl interface for management of track messages
//
// History:
// - 23.09.15, J. Kastner: initial version
// - 28.10.15, J. Kastner: add track_clear() and track_title()
// - 11.11.15, J. Kastner: add track::radio subcommands
// - 24.11.15, J. Kastner: add track::train subcommands

#include <stdio.h>
#include <stdlib.h>
#include "track.h"
#include "../trackmsg.h"
#include "../logging.h"

#ifdef WINDOWS
char* mystrsep(char** stringp, const char* delim)
{
  char* start = *stringp;
  char* p;

  p = (start != NULL) ? strpbrk(start, delim) : NULL;

  if (p == NULL)
  {
    *stringp = NULL;
  }
  else
  {
    *p = '\0';
    *stringp = p + 1;
  }

  return start;
}
#else
#define mystrsep strsep
#endif // WINDOWS

const size_t es_tcl_track_bmsize = sizeof(CompressedBaliseMessage_TM);
const size_t es_tcl_track_rmsize = sizeof(CompressedRadioMessage_TM);
const size_t es_tcl_track_tmsize = sizeof(M_TrainTrack_Message_T_TM_radio_messages);

// static buffer for reading/writing of balise messages
CompressedBaliseMessage_TM es_tcl_track_balise_buf;
// static buffer for reading/writing of RBC radio messages
CompressedRadioMessage_TM es_tcl_track_radio_buf;
// static buffer for reading/writing of train radio messages
M_TrainTrack_Message_T_TM_radio_messages es_tcl_track_train_buf;


es_Status es_tcl_track_balise_load_raw(char* hexdata) {
  es_hex_to_bytes(es_tcl_track_bmsize,hexdata,(char*)&es_tcl_track_balise_buf);
  return ES_OK;
}

es_Status es_tcl_track_balise_load_index(int i) {
  es_ListEntry *e = es_list_get(es_tracksim_track.bmsgs,i);

  if(e==NULL) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid balise index=%d",i);
    return ES_TCL_ERROR;
  }

  es_tcl_track_balise_buf = ((es_TriggeredBaliseMessage*)e->data)->msg;

  return ES_OK;
}


es_Status es_tcl_track_radio_load_raw(char* hexdata) {
  es_hex_to_bytes(es_tcl_track_rmsize,hexdata,(char*)&es_tcl_track_radio_buf);
  return ES_OK;
}


es_Status es_tcl_track_radio_load_index(int i) {
  es_ListEntry *e = es_list_get(es_tracksim_track.rmsgs,i);

  if(e==NULL) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid radio index=%d",i);
    return ES_TCL_ERROR;
  }

  es_tcl_track_radio_buf = ((es_TriggeredRadioMessage*)e->data)->msg;
  return ES_OK;
}

// retrieve data values from the balise message buffer
es_Status es_tcl_track_balise_get(char* subcmd, void (*appendResult)(char*, es_ClientData), es_ClientData data) {
  CompressedBaliseMessage_TM *bm = &es_tcl_track_balise_buf;

  if(!strcmp("header",subcmd)) {
    snprintf(es_msg_buf, ES_MSG_BUF_SIZE,
             "{nid_bg %d} {n_pig %d} {n_total %d} {m_dup %d} {m_mcount %d} {m_version %d} "
             "{nid_c %d} {q_link %d} {q_media %d} {q_updown %d}",
             bm->Header.nid_bg,
             bm->Header.n_pig,
             bm->Header.n_total,
             bm->Header.m_dup,
             bm->Header.m_mcount,
             bm->Header.m_version,
             bm->Header.nid_c,
             bm->Header.q_link,
             bm->Header.q_media,
             bm->Header.q_updown);
    appendResult(es_msg_buf, data);
    return ES_OK;
  }
  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command '%s': expected 'header'",subcmd);
  return ES_TCL_ERROR;
}

// set data values in the balise message buffer
es_Status es_tcl_track_balise_set(char* subcmd, char* arg, void (*appendResult)(char*, es_ClientData), es_ClientData data) {
  CompressedBaliseMessage_TM *bm = &es_tcl_track_balise_buf;

  // header
  if( subcmd != NULL && !strcmp("header",subcmd) ) {
    if (arg == NULL) {
      snprintf(es_msg_buf, ES_MSG_BUF_SIZE, "invalid sub command 'set header': missing argument");
      return ES_TCL_ERROR;
    }

    char *varname, *next;
    arg = strdup(arg);
    next = arg;
    appendResult(es_msg_buf, data);
    while ((varname = mystrsep(&next, " ")) != NULL) {
      char *v = mystrsep(&next, " ");
      if (v == NULL) {
        snprintf(es_msg_buf, ES_MSG_BUF_SIZE, "missing value for variable %s", varname);
        return ES_TCL_ERROR;
      }
      int value = atoi(v);
      if (!strcmp("nid_bg", varname)) {
        bm->Header.nid_bg = value;
      }
      else if (!strcmp("n_pig", varname)) {
        bm->Header.n_pig = value;
      }
      else if (!strcmp("n_total", varname)) {
        bm->Header.n_total = value;
      }
      else if (!strcmp("m_dup", varname)) {
        bm->Header.m_dup = value;
      }
      else if (!strcmp("m_mcount", varname)) {
        bm->Header.m_mcount = value;
      }
      else if (!strcmp("m_version", varname)) {
        bm->Header.m_version = value;
      }
      else if (!strcmp("nid_c", varname)) {
        bm->Header.nid_c = value;
      }
      else if (!strcmp("q_link", varname)) {
        bm->Header.q_link = value;
      }
      else if (!strcmp("q_media", varname)) {
        bm->Header.q_media = value;
      }
      else if (!strcmp("q_updown", varname)) {
        bm->Header.q_updown = value;
      }
      else {
        snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid balise header variable: %s",varname);
        free(arg);
        return ES_TCL_ERROR;
      }
    }
    free(arg);
    return ES_OK;
  }

  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command '%s': expected 'header'",subcmd);
  return ES_TCL_ERROR;
}

es_Status es_tcl_track_balise_addpkt(char* arg1, char* arg2, void (*appendResult)(char*,es_ClientData), es_ClientData data) {
  MetadataElement_T_Common_Types_Pkg *hdr = NULL;

  if(arg2==NULL) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"missing argument: packet data");
    return ES_TCL_ERROR;
  }

  int i;
  int spos = 0;
  for(i=0; i<MAX_NUM_PACKETS; i++) {
    hdr = &(es_tcl_track_balise_buf.Messages.PacketHeaders[i]);
    if( ! hdr->valid )
      break;
    spos = hdr->endAddress + 1;
  }

  if(hdr->valid) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"cannot add balise packet: maximum number of packets reached");
    return ES_TCL_ERROR;
  }

  hdr->nid_packet = atoi(arg1);
  hdr->q_dir = (hdr->nid_packet / 100000) % 10;
  hdr->valid = true;
  hdr->startAddress = spos;
  size_t len = strlen(arg2) / 2;
  hdr->endAddress = spos + (len/4) - 1;
  if(len > 500 ) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"cannot add balise packet: packet too big (%lu bytes)",len);
    return ES_TCL_ERROR;
  }
  char buf[500];
  es_hex_to_bytes(len,arg2,buf);
  memcpy(&es_tcl_track_balise_buf.Messages.PacketData[spos],buf,len);

  return ES_OK;
}

es_Status es_tcl_track_balise(char* subcmd, char* arg1, char* arg2, void (*appendResult)(char*,es_ClientData), es_ClientData data) {
  if(!strcmp("load",subcmd)) {
    return es_tcl_track_balise_load_index(atoi(arg1));
  }
  if(!strcmp("raw",subcmd)) {
    return es_tcl_track_balise_load_raw(arg1);
  }
  if(!strcmp("get",subcmd)) {
    return es_tcl_track_balise_get(arg1,appendResult,data);
  }
  if(!strcmp("clear",subcmd)) {
    memset(&es_tcl_track_balise_buf,0,es_tcl_track_bmsize);
    return ES_OK;
  }
  if(!strcmp("addpkt",subcmd)) {
    return es_tcl_track_balise_addpkt(arg1,arg2,appendResult,data);
  }
  if(!strcmp("set",subcmd)) {
    return es_tcl_track_balise_set(arg1,arg2,appendResult,data);
  }
  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command for 'track::balise': %s",subcmd);
  return ES_TCL_ERROR;
}

es_Status es_tcl_track_train_load_raw(char *hexdata) {
  es_hex_to_bytes(es_tcl_track_tmsize,hexdata,(char*)&es_tcl_track_train_buf);
  return ES_OK;
}

es_Status es_tcl_track_train_load_index(int i) {
  es_ListEntry *e = es_list_get(es_tracksim_track.tmsgs,i);

  if(e==NULL) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid train message index=%d",i);
    return ES_TCL_ERROR;
  }

  es_tcl_track_train_buf = ((es_TriggeredTrainMessage*)e->data)->msg;
  return ES_OK;
}


es_Status es_tcl_track_train(char* subcmd, char* arg, void (*appendResult)(char*,es_ClientData), es_ClientData data) {
  if(!strcmp("raw",subcmd)) {
    return es_tcl_track_train_load_raw(arg);
  }
  if(!strcmp("load",subcmd)) {
    return es_tcl_track_train_load_index(atoi(arg));
  }
  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command for 'track::train': %s",subcmd);
  return ES_TCL_ERROR;
}

// retrieve data values from the radio message buffer
es_Status es_tcl_track_radio_get(char* subcmd, void (*appendResult)(char*, es_ClientData), es_ClientData data) {
  CompressedRadioMessage_TM *rm = &es_tcl_track_radio_buf;

  if(subcmd != NULL && !strcmp("header",subcmd)) {
    snprintf(es_msg_buf, ES_MSG_BUF_SIZE,
             "{nid_message %d} {d_emergencystop %d} {d_ref %d} {d_sr %d} {m_ack %d} {m_version %d} "
             "{nid_em %d} {nid_lrbg %d} {q_dir %d} {q_scale %d} {radioDevice %d} {receivedSystemTime %d} "
             "{t_sh_rqst %d} {t_train %d} {t_train_reference %d}",
             rm->Header.nid_message,
             rm->Header.d_emergencystop,
             rm->Header.d_ref,
             rm->Header.d_sr,
             rm->Header.m_ack,
             rm->Header.m_version,
             rm->Header.nid_em,
             rm->Header.nid_lrbg,
             rm->Header.q_dir,
             rm->Header.q_scale,
             rm->Header.radioDevice,
             rm->Header.receivedSystemTime,
             rm->Header.t_sh_rqst,
             rm->Header.t_train,
             rm->Header.t_train_reference
    );
    appendResult(es_msg_buf, data);
    return ES_OK;
  }
  else if(subcmd != NULL && !strcmp("raw",subcmd) ) {
    int hexlen = es_tcl_track_rmsize*2;
    char buf[hexlen+1];
    buf[hexlen] = 0;
    es_bytes_to_hex(es_tcl_track_rmsize, (char*)&es_tcl_track_radio_buf,buf);
    appendResult(buf,data);
    return ES_OK;
  }
  /*else if(subcmd != NULL && !strcmp("bytes",subcmd) ) {
    char buf[es_tcl_track_rmsize+1];
    memcpy(buf,&es_tcl_track_radio_buf,es_tcl_track_rmsize);
    buf[es_tcl_track_rmsize] = 0;
    appendResult(buf,data);
    return ES_OK;
  }*/
  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command '%s': expected 'header' | 'raw'",subcmd);
  return ES_TCL_ERROR;
}

// set data values in the radio message buffer
es_Status es_tcl_track_radio_set(char* subcmd, char* arg, void (*appendResult)(char*, es_ClientData), es_ClientData data) {
  CompressedRadioMessage_TM *rm = &es_tcl_track_radio_buf;

  // header
  if( subcmd != NULL && !strcmp("header",subcmd) ) {
    if(arg==NULL) {
      snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command 'set header': missing argument");
      return ES_TCL_ERROR;
    }

    char *varname, *next;
    arg = strdup(arg);
    next = arg;
    appendResult(es_msg_buf,data);
    while((varname = mystrsep(&next," ")) != NULL) {
      char *v = mystrsep(&next," ");
      if( v == NULL ) {
        snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"missing value for variable %s",varname);
        return ES_TCL_ERROR;
      }
      int value = atoi(v);
      if( !strcmp("nid_message",varname) ) {
        rm->Header.nid_message = value;
      }
      else if( !strcmp("d_emergencystop",varname) ) {
        rm->Header.d_emergencystop = value;
      }
      else if( !strcmp("d_ref",varname) ) {
        rm->Header.d_ref = value;
      }
      else if( !strcmp("d_sr",varname) ) {
        rm->Header.d_sr = value;
      }
      else if( !strcmp("m_ack",varname) ) {
        rm->Header.m_ack = value;
      }
      else if( !strcmp("m_version",varname) ) {
        rm->Header.m_version = value;
      }
      else if( !strcmp("nid_em",varname) ) {
        rm->Header.nid_em = value;
      }
      else if( !strcmp("nid_lrbg",varname) ) {
        rm->Header.nid_lrbg = value;
      }
      else if( !strcmp("q_dir",varname) ) {
        rm->Header.q_dir = value;
      }
      else if( !strcmp("q_scale",varname) ) {
        rm->Header.q_scale = value;
      }
      else if( !strcmp("radioDevice",varname) ) {
        rm->Header.radioDevice = value;
      }
      else if( !strcmp("receivedSystemTime",varname) ) {
        rm->Header.receivedSystemTime = value;
      }
      else if( !strcmp("t_sh_rqst",varname) ) {
        rm->Header.t_sh_rqst = value;
      }
      else if( !strcmp("t_train",varname) ) {
        rm->Header.t_train = value;
      }
      else if( !strcmp("t_train_reference",varname) ) {
        rm->Header.t_train_reference = value;
      }
      else {
        snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid radio header variable: %s",varname);
        free(arg);
        return ES_TCL_ERROR;
      }
    }
    free(arg);
    return ES_OK;
  }

  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command '%s': expected 'header'",subcmd);
  return ES_TCL_ERROR;
}


es_Status es_tcl_track_radio_addpkt(char* arg1, char* arg2, void (*appendResult)(char*,es_ClientData), es_ClientData data) {
  MetadataElement_T_Common_Types_Pkg *hdr = NULL;

  if(arg2==NULL) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"missing argument: packet data");
    return ES_TCL_ERROR;
  }

  int i;
  int spos = 0;
  for(i=0; i<MAX_NUM_PACKETS; i++) {
    hdr = &(es_tcl_track_radio_buf.Messages.PacketHeaders[i]);
    if( ! hdr->valid )
      break;
    spos = hdr->endAddress + 1;
  }

  if(hdr->valid) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"cannot add radio packet: maximum number of packets reached");
    return ES_TCL_ERROR;
  }

  hdr->nid_packet = atoi(arg1);
  hdr->q_dir = (hdr->nid_packet / 100000) % 10;
  hdr->valid = true;
  hdr->startAddress = spos;
  size_t len = strlen(arg2) / 2;
  hdr->endAddress = spos + (len/4) - 1;
  if(len > 500 ) {
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"cannot add radio packet: packet too big (%lu bytes)",len);
    return ES_TCL_ERROR;
  }
  char buf[500];
  es_hex_to_bytes(len,arg2,buf);
  memcpy(&es_tcl_track_radio_buf.Messages.PacketData[spos],buf,len);

  return ES_OK;
}

es_Status es_tcl_track_radio(char* subcmd, char* arg1, char* arg2, void (*appendResult)(char*,es_ClientData), es_ClientData data) {
  if(!strcmp("load",subcmd)) {
    return es_tcl_track_radio_load_index(atoi(arg1));
  }
  if(!strcmp("raw",subcmd)) {
    return es_tcl_track_radio_load_raw(arg1);
  }
  if(!strcmp("get",subcmd)) {
    return es_tcl_track_radio_get(arg1,appendResult,data);
  }
  if(!strcmp("set",subcmd)) {
    return es_tcl_track_radio_set(arg1,arg2,appendResult,data);
  }
  if(!strcmp("clear",subcmd)) {
    memset(&es_tcl_track_radio_buf,0,es_tcl_track_rmsize);
    return ES_OK;
  }
  if(!strcmp("addpkt",subcmd)) {
    return es_tcl_track_radio_addpkt(arg1,arg2,appendResult,data);
  }
  if(!strcmp("header",subcmd)) {
    return ES_OK;
  }
  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command for 'track::radio': %s",subcmd);
  return ES_TCL_ERROR;
}


es_Status es_tcl_track_add(char* subcmd, double pos) {
  if(!strcmp("balise",subcmd)) {
    es_add_triggered_balise_message(&es_tracksim_track,pos,&es_tcl_track_balise_buf);
    return ES_OK;
  }
  if(!strcmp("radio",subcmd)) {
    es_add_triggered_radio_message(&es_tracksim_track,pos,&es_tcl_track_radio_buf);
    return ES_OK;
  }
  if(!strcmp("train",subcmd)) {
    es_add_triggered_train_message(&es_tracksim_track,pos,&es_tcl_track_train_buf);
    return ES_OK;
  }
  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid sub command for 'track::add': %s",subcmd);
  return ES_TCL_ERROR;
}


es_Status es_tcl_track_info(void (*appendResult)(char* res, es_ClientData data), es_ClientData data) {
  // balise messages
  es_ListEntry *next = es_tracksim_track.bmsgs;
  int i = 0;
  while(next!=NULL) {
    es_TriggeredBaliseMessage *bm = (es_TriggeredBaliseMessage*)next->data;
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"{b %d %d %d %.1f} ",i,bm->msg.Header.nid_bg,bm->msg.Header.n_pig,bm->triggerpos);
    appendResult(es_msg_buf,data);

    next = next->tail;
    i++;
  }
  // RBC radio messages
  next = es_tracksim_track.rmsgs;
  i = 0;
  while(next!=NULL) {
    es_TriggeredRadioMessage *rm = (es_TriggeredRadioMessage*)next->data;
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"{r %d %d %.1f} ",i,rm->msg.Header.nid_message,rm->triggerpos);
    appendResult(es_msg_buf,data);

    next = next->tail;
    i++;
  }
  // train radio messages
  next = es_tracksim_track.tmsgs;
  i = 0;
  while(next!=NULL) {
    es_TriggeredTrainMessage *tm = (es_TriggeredTrainMessage*)next->data;
    snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"{t %d %d %.1f} ",i,tm->msg.Message.nid_message,tm->triggerpos);
    appendResult(es_msg_buf,data);

    next = next->tail;
    i++;
  }

  return ES_OK;
}

es_Status es_tcl_track_title_set(char *title) {
  es_tracksim_track.title = title;
  return ES_OK;
}

es_Status es_tcl_track_title_get(void (*appendResult)(char* res, es_ClientData data), es_ClientData data) {
  if( es_tracksim_track.title != NULL ) {
    appendResult(es_tracksim_track.title,data);
  }
  return ES_OK;
}

es_Status es_tcl_track_clear() {
  es_track_clear(&es_tracksim_track);
  return ES_OK;
}
