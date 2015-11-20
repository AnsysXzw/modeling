/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "M003_to_Radio_Track_Train_H_TM_RBC_conversions_legacy.h"

/* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H */
void M003_to_Radio_Track_Train_H_TM_RBC_conversions_legacy(
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::M003_in */ M_003_T_TM_radio_messages *M003_in,
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::Radio_Track_Train_Hd_out */ Radio_TrackTrain_Header_T_Radio_Types_Pkg *Radio_Track_Train_Hd_out)
{
  static kcg_bool noname;
  static L_MESSAGE _1_noname;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L1 */
  static M_003_T_TM_radio_messages _L1;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L7 */
  static NID_LRBG _L7;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L6 */
  static M_ACK _L6;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L5 */
  static T_TRAIN _L5;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L4 */
  static L_MESSAGE _L4;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L3 */
  static NID_MESSAGE _L3;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L2 */
  static kcg_bool _L2;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L14 */
  static Radio_TrackTrain_Header_T_Radio_Types_Pkg _L14;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L15 */
  static T_TRAIN _L15;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L16 */
  static NID_EM _L16;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L17 */
  static Q_SCALE _L17;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L18 */
  static D_SR _L18;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L19 */
  static T_TRAIN _L19;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L20 */
  static D_REF _L20;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L21 */
  static Q_DIR _L21;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L22 */
  static D_EMERGENCYSTOP _L22;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L23 */
  static M_VERSION _L23;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L25 */
  static T_internal_Type_Obu_BasicTypes_Pkg _L25;
  /* TM_RBC_conversions_legacy::M003_to_Radio_Track_Train_H::_L24 */
  static kcg_int _L24;
  
  kcg_copy_M_003_T_TM_radio_messages(&_L1, M003_in);
  _L7 = _L1.nid_lrbg;
  _L6 = _L1.m_ack;
  _L5 = _L1.t_train;
  _L4 = _L1.l_message;
  _L3 = _L1.nid_message;
  _L2 = _L1.valid;
  _L24 = default_radioDevice_TM_RBC_conversions_legacy;
  _L25 = default_receivedSystemTime_TM_RBC_conversions_legacy;
  _L15 = default_t_train_reference_TM_RBC_conversions_legacy;
  _L16 = default_nid_em_TM_RBC_conversions_legacy;
  _L17 = default_q_scale_TM_RBC_conversions_legacy;
  _L18 = default_d_sr_TM_RBC_conversions_legacy;
  _L19 = default_t_sh_rqst_TM_RBC_conversions_legacy;
  _L20 = default_d_ref_TM_RBC_conversions_legacy;
  _L21 = default_q_dir_TM_RBC_conversions_legacy;
  _L22 = default_d_emergencystop_TM_RBC_conversions_legacy;
  _L23 = default_m_version_TM_RBC_conversions_legacy;
  _L14.radioDevice = _L24;
  _L14.receivedSystemTime = _L25;
  _L14.nid_message = _L3;
  _L14.t_train = _L5;
  _L14.m_ack = _L6;
  _L14.nid_lrbg = _L7;
  _L14.t_train_reference = _L15;
  _L14.nid_em = _L16;
  _L14.q_scale = _L17;
  _L14.d_sr = _L18;
  _L14.t_sh_rqst = _L19;
  _L14.d_ref = _L20;
  _L14.q_dir = _L21;
  _L14.d_emergencystop = _L22;
  _L14.m_version = _L23;
  kcg_copy_Radio_TrackTrain_Header_T_Radio_Types_Pkg(
    Radio_Track_Train_Hd_out,
    &_L14);
  noname = _L2;
  _1_noname = _L4;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** M003_to_Radio_Track_Train_H_TM_RBC_conversions_legacy.c
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

