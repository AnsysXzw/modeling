/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-07T00:28:47
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "C_header_to_M032_TM_radio_messages.h"

void C_header_to_M032_reset_TM_radio_messages(
  outC_C_header_to_M032_TM_radio_messages *outC)
{
  /* 1 */ CAST_Int_to_M_ACK_reset_TM_conversions(&outC->_2_Context_1);
  /* 1 */ CAST_Int_to_NID_LRBG_reset_TM_conversions(&outC->_1_Context_1);
  /* 1 */ CAST_Int_to_M_VERSION_reset_TM_conversions(&outC->Context_1);
}

/* TM_radio_messages::C_header_to_M032 */
void C_header_to_M032_TM_radio_messages(
  /* TM_radio_messages::C_header_to_M032::header_in */M_TrackTrain_Radio_T_TM_radio_messages *header_in,
  outC_C_header_to_M032_TM_radio_messages *outC)
{
  kcg_int noname;
  kcg_int _1_noname;
  kcg_int _2_noname;
  kcg_int _3_noname;
  kcg_int _4_noname;
  
  kcg_copy_M_TrackTrain_Radio_T_TM_radio_messages(&outC->_L1, header_in);
  outC->_L13 = outC->_L1.field8;
  outC->_L12 = outC->_L1.field7;
  outC->_L11 = outC->_L1.field6;
  outC->_L10 = outC->_L1.field5;
  outC->_L9 = outC->_L1.field4;
  outC->_L8 = outC->_L1.field3;
  outC->_L7 = outC->_L1.field2;
  outC->_L6 = outC->_L1.field1;
  outC->_L5 = outC->_L1.t_train;
  outC->_L4 = outC->_L1.l_message;
  outC->_L3 = outC->_L1.nid_message;
  /* 1 */ CAST_Int_to_M_VERSION_TM_conversions(outC->_L8, &outC->Context_1);
  outC->_L29 = outC->Context_1.m_version;
  _4_noname = outC->_L12;
  _3_noname = outC->_L11;
  _2_noname = outC->_L10;
  _1_noname = outC->_L9;
  noname = outC->_L13;
  /* 1 */ CAST_Int_to_NID_LRBG_TM_conversions(outC->_L7, &outC->_1_Context_1);
  outC->_L28 = outC->_1_Context_1.NID_LRBG_out;
  /* 1 */ CAST_Int_to_M_ACK_TM_conversions(outC->_L6, &outC->_2_Context_1);
  outC->_L27 = outC->_2_Context_1.m_ack;
  outC->_L2 = outC->_L1.valid;
  outC->_L26.valid = outC->_L2;
  outC->_L26.nid_message = outC->_L3;
  outC->_L26.l_message = outC->_L4;
  outC->_L26.t_train = outC->_L5;
  outC->_L26.m_ack = outC->_L27;
  outC->_L26.nid_lrbg = outC->_L28;
  outC->_L26.m_version = outC->_L29;
  kcg_copy_M_032_T_TM_radio_messages(&outC->message_out, &outC->_L26);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** C_header_to_M032_TM_radio_messages.c
** Generation date: 2015-07-07T00:28:47
*************************************************************$ */

