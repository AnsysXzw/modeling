/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "C_M003_int__to_header_TM_RBC_conversions.h"

/* TM_RBC_conversions::C_M003_int__to_header */
void C_M003_int__to_header_TM_RBC_conversions(
  /* TM_RBC_conversions::C_M003_int__to_header::Message_Data_in */ M_003_int_T_TM_radio_messages *Message_Data_in,
  /* TM_RBC_conversions::C_M003_int__to_header::Message_Header_Out */ M_TrackTrain_Radio_T_TM_radio_messages *Message_Header_Out)
{
  /* TM_RBC_conversions::C_M003_int__to_header::_L1 */
  static M_003_int_T_TM_radio_messages _L1;
  /* TM_RBC_conversions::C_M003_int__to_header::_L2 */
  static M_TrackTrain_Radio_T_TM_radio_messages _L2;
  /* TM_RBC_conversions::C_M003_int__to_header::_L8 */
  static kcg_int _L8;
  /* TM_RBC_conversions::C_M003_int__to_header::_L7 */
  static kcg_int _L7;
  /* TM_RBC_conversions::C_M003_int__to_header::_L6 */
  static kcg_int _L6;
  /* TM_RBC_conversions::C_M003_int__to_header::_L5 */
  static kcg_int _L5;
  /* TM_RBC_conversions::C_M003_int__to_header::_L4 */
  static kcg_int _L4;
  /* TM_RBC_conversions::C_M003_int__to_header::_L3 */
  static kcg_bool _L3;
  /* TM_RBC_conversions::C_M003_int__to_header::_L19 */
  static kcg_int _L19;
  
  kcg_copy_M_003_int_T_TM_radio_messages(&_L1, Message_Data_in);
  _L3 = _L1.valid;
  _L4 = _L1.nid_message;
  _L5 = _L1.l_message;
  _L6 = _L1.t_train;
  _L7 = _L1.m_ack;
  _L8 = _L1.nid_lrbg;
  _L19 = 0;
  _L2.valid = _L3;
  _L2.nid_message = _L4;
  _L2.l_message = _L5;
  _L2.t_train = _L6;
  _L2.field1 = _L7;
  _L2.field2 = _L8;
  _L2.field3 = _L19;
  _L2.field4 = _L19;
  _L2.field5 = _L19;
  _L2.field6 = _L19;
  _L2.field7 = _L19;
  _L2.field8 = _L19;
  kcg_copy_M_TrackTrain_Radio_T_TM_radio_messages(Message_Header_Out, &_L2);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** C_M003_int__to_header_TM_RBC_conversions.c
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

