/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Build_RBC_Message_LRBG_100_D_00100_0_M008_AmsterdamUtrechtL2_Sheet14_Maarssen_Standalone.h"

/* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008 */
void Build_RBC_Message_LRBG_100_D_00100_0_M008_AmsterdamUtrechtL2_Sheet14_Maarssen_Standalone(
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::RadiaDataIn */ R_data_internal_T_InfraLib *RadiaDataIn,
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::R_data_out */ R_data_internal_T_InfraLib *R_data_out)
{
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L1 */
  static R_data_internal_T_InfraLib _L1;
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L3 */
  static CompressedPackets_T_Common_Types_Pkg _L3;
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L38 */
  static CompressedPackets_T_Common_Types_Pkg _L38;
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L39 */
  static R_data_internal_T_InfraLib _L39;
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L40 */
  static R_data_internal_T_InfraLib _L40;
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L42 */
  static M_TrackTrain_Radio_T_TM_radio_messages _L42;
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L43 */
  static R_data_internal_T_InfraLib _L43;
  /* AmsterdamUtrechtL2::Sheet14_Maarssen_Standalone::Build_RBC_Message_LRBG_100_D_00100_0_M008::_L44 */
  static kcg_bool _L44;
  
  kcg_copy_R_data_internal_T_InfraLib(&_L1, RadiaDataIn);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(&_L38, &_L1.packets);
  /* 1 */ No_Radio_Packets_RadioLib(&_L38, &_L3);
  kcg_copy_R_data_internal_T_InfraLib(&_L39, &_L1);
  if (kcg_true) {
    kcg_copy_CompressedPackets_T_Common_Types_Pkg(&_L39.packets, &_L3);
  }
  /* 1 */
  Send_M008_JRU_MessageLibBaseline2(
    (M_008_int_T_TM_radio_messages *) &LRBG_100_D_00100_0_M008_Messages_Sim,
    &_L42);
  kcg_copy_R_data_internal_T_InfraLib(&_L40, &_L39);
  if (kcg_true) {
    kcg_copy_M_TrackTrain_Radio_T_TM_radio_messages(&_L40.message, &_L42);
  }
  _L44 = kcg_true;
  kcg_copy_R_data_internal_T_InfraLib(&_L43, &_L40);
  if (kcg_true) {
    _L43.message_sent = _L44;
  }
  kcg_copy_R_data_internal_T_InfraLib(R_data_out, &_L43);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Build_RBC_Message_LRBG_100_D_00100_0_M008_AmsterdamUtrechtL2_Sheet14_Maarssen_Standalone.c
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

