//     Project: openETCS libenvsim
//      Module: tcl / envsimInt.c
// Description: Tcl extension for libenvsim
//
// History:
// - 23.09.15, J. Kastner: initial version
// - 29.10.15, J. Kastner: add track_title_cmd() and track_clear_cmd()
// - 24.11.15, J. Kastner: add track_train_cmd()

#ifdef WITH_TCL_EXTENSION

#include "envsimInt.h"
#include "track.h"
#include "pkts.h"

extern M_TrainTrack_Message_T_TM_radio_messages es_tcl_track_train_buf;
extern const size_t es_tcl_track_tmsize;
extern CompressedRadioMessage_TM es_tcl_track_radio_buf;
extern const size_t es_tcl_track_rmsize;
extern CompressedBaliseMessage_TM es_tcl_track_balise_buf;
extern const size_t es_tcl_track_bmsize;


void envsim_append_result(char* res, char* clientData) {
  Tcl_AppendResult((Tcl_Interp*)clientData, res, NULL);
}


//----------------------------- track commands ------------------------------
int envsim_track_balise_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc<2 || objc > 4) {
    Tcl_WrongNumArgs(interp,1,objv,"");
    return TCL_ERROR;
  }
  char *arg1 = Tcl_GetString(objv[1]);
  char *arg2 = NULL;
  if(objc>=3)
    arg2 = Tcl_GetString(objv[2]);
  char *arg3 = NULL;
  if(objc==4)
    arg3 = Tcl_GetString(objv[3]);

  if(! (strcmp("get",arg1) || strcmp("bytes",arg2)) ) {
    Tcl_Obj *p = Tcl_NewByteArrayObj((const unsigned char*)&es_tcl_track_balise_buf,es_tcl_track_bmsize);
    Tcl_SetObjResult(interp,p);
    return TCL_OK;
  }
  if(es_tcl_track_balise(arg1, arg2, arg3, envsim_append_result,(es_ClientData)interp)) {
    Tcl_AddErrorInfo(interp,es_msg_buf);
    return TCL_ERROR;
  };
  return TCL_OK;
}

int envsim_track_train_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc!=3) {
    Tcl_WrongNumArgs(interp,1,objv,"raw {arg} | get bytes");
    return TCL_ERROR;
  }
  char *arg1 = Tcl_GetString(objv[1]);
  char *arg2 = Tcl_GetString(objv[2]);
  if(! (strcmp("get",arg1) || strcmp("bytes",arg2)) ) {
    Tcl_Obj *p = Tcl_NewByteArrayObj((const unsigned char*)&es_tcl_track_train_buf,es_tcl_track_tmsize);
    Tcl_SetObjResult(interp,p);
    return TCL_OK;
  }
  if(es_tcl_track_train(Tcl_GetString(objv[1]), Tcl_GetString(objv[2]),envsim_append_result,(es_ClientData)interp)) {
    Tcl_AddErrorInfo(interp,es_msg_buf);
    return TCL_ERROR;
  };
  return TCL_OK;
}


int envsim_track_radio_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc == 2) {
    if(es_tcl_track_radio(Tcl_GetString(objv[1]), NULL, NULL, envsim_append_result,(es_ClientData)interp)) {
      Tcl_AddErrorInfo(interp,es_msg_buf);
      return TCL_ERROR;
    };
  }
  else if (objc == 3) {
    char *arg1 = Tcl_GetString(objv[1]);
    char *arg2 = Tcl_GetString(objv[2]);
    if(! (strcmp("get",arg1) || strcmp("bytes",arg2)) ) {
      Tcl_Obj *p = Tcl_NewByteArrayObj((const unsigned char*)&es_tcl_track_radio_buf,es_tcl_track_rmsize);
      Tcl_SetObjResult(interp,p);
      return TCL_OK;
    }
    if(es_tcl_track_radio(arg1, arg2, NULL, envsim_append_result,(es_ClientData)interp)) {
      Tcl_AddErrorInfo(interp,es_msg_buf);
      return TCL_ERROR;
    };
  }
  else if(objc == 4) {
    if(es_tcl_track_radio(Tcl_GetString(objv[1]), Tcl_GetString(objv[2]), Tcl_GetString(objv[3]), envsim_append_result,(es_ClientData)interp)) {
      Tcl_AddErrorInfo(interp,es_msg_buf);
      return TCL_ERROR;
    };
  }
  else {
    Tcl_WrongNumArgs(interp,1,objv,"");
    return TCL_ERROR;
  }
  return TCL_OK;
}


int envsim_track_add_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc!=3) {
    Tcl_WrongNumArgs(interp,1,objv,"balise|radio position");
    return TCL_ERROR;
  }
  double pos = 0.0;
  Tcl_GetDoubleFromObj(interp,objv[2],&pos);
  if(es_tcl_track_add(Tcl_GetString(objv[1]), pos)) {
    Tcl_AddErrorInfo(interp,es_msg_buf);
    return TCL_ERROR;
  }
  return TCL_OK;
}

int envsim_track_info_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc!=1) {
    Tcl_WrongNumArgs(interp,1,objv,"");
    return TCL_ERROR;
  }
  if(es_tcl_track_info(envsim_append_result,(es_ClientData)interp)) {
    Tcl_AddErrorInfo(interp,es_msg_buf);
    return TCL_ERROR;
  }
  return TCL_OK;
}

int envsim_track_title_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc==2) {
    char *title = Tcl_GetString(objv[1]);
    char *buf = malloc(strlen(title));
    strcpy(buf,title);
    if(es_tcl_track_title_set(buf)) {
      Tcl_AddErrorInfo(interp,es_msg_buf);
      return TCL_ERROR;
    }
  }
  else if(objc==1) {
    return es_tcl_track_title_get(envsim_append_result,(es_ClientData)interp);
  }
  else {
    Tcl_WrongNumArgs(interp,1,objv," {} | title");
    return TCL_ERROR;
  }
  return TCL_OK;
}

int envsim_track_clear_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  es_tcl_track_clear();
  return TCL_OK;
}

int envsim_pkts_target_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc!=2) {
    Tcl_WrongNumArgs(interp,1,objv,"balisebuf|radiobuf");
    return TCL_ERROR;
  }
  if(es_tcl_pkts_set_target(Tcl_GetString(objv[1]))) {
    Tcl_AddErrorInfo(interp,es_msg_buf);
    return TCL_ERROR;
  }
  return TCL_OK;
}

int envsim_pkts_get_cmd(ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
  if(objc<2) {
    Tcl_WrongNumArgs(interp,1,objv,"headers|data");
    return TCL_ERROR;
  }

  char *subcmd = Tcl_GetString(objv[1]);

  if(!strcmp("headers",subcmd)) {
    if(objc!=2) {
      Tcl_WrongNumArgs(interp,1,objv,"");
      return TCL_ERROR;
    }
    if(es_tcl_pkts_get_headers(envsim_append_result,(es_ClientData)interp)) {
      Tcl_AddErrorInfo(interp,es_msg_buf);
      return TCL_ERROR;
    }
    return TCL_OK;
  }

  if(!strcmp("data",subcmd)) {
    if(objc<3||objc>4) {
      Tcl_WrongNumArgs(interp,1,objv,"data index [npackets]");
      return TCL_ERROR;
    }
    int index = 0;
    int npackets = 1;
    if(Tcl_GetIntFromObj(interp,objv[2],&index)) {
      return TCL_ERROR;
    }
    if(objc==4 && Tcl_GetIntFromObj(interp,objv[3],&npackets)) {
      return TCL_ERROR;
    }
    if(es_tcl_pkts_get_data(index,npackets,envsim_append_result,(es_ClientData)interp)) {
      Tcl_AddErrorInfo(interp,es_msg_buf);
      return TCL_ERROR;
    }
    return TCL_OK;
  }

  snprintf(es_msg_buf,ES_MSG_BUF_SIZE,"invalid subcommand: %s",subcmd);
  Tcl_AddErrorInfo(interp,es_msg_buf);
  return TCL_ERROR;
}


//-------------------------- extension interface ----------------------------
int Envsim_Init(Tcl_Interp *interp) {
  if( !Tcl_InitStubs(interp, "8.4", 0) ) {
    return TCL_ERROR;
  }
  Tcl_CreateObjCommand(interp, "track::balise", envsim_track_balise_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "track::radio", envsim_track_radio_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "track::train", envsim_track_train_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "track::add", envsim_track_add_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "track::info", envsim_track_info_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "track::title", envsim_track_title_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "track::clear", envsim_track_clear_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "pkts::target", envsim_pkts_target_cmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "pkts::get", envsim_pkts_get_cmd, NULL, NULL);
  return TCL_OK;
}

int Envsim_Unload(Tcl_Interp *interp) {
  return TCL_OK;
}

int Envsim_SafeInit() {
  return TCL_OK;
}

int Envsim_SafeUnload() {
  return TCL_OK;
}


#endif //WITH_TCL_EXTENSION