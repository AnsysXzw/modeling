/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Send_RBC_LRBG_400_D_00106_0_M015_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_RBC.h"

/* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015 */
void Send_RBC_LRBG_400_D_00106_0_M015_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_RBC(
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::RadiaDataIn */ R_data_internal_T_InfraLib *RadiaDataIn,
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::TriggerValue */ kcg_int TriggerValue,
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::R_data_out */ R_data_internal_T_InfraLib *R_data_out)
{
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015 */
  static R_data_internal_T_InfraLib op_call;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015 */
  static kcg_bool ck_every;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::_L4 */
  static R_data_internal_T_InfraLib _L4;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::_L23 */
  static R_data_internal_T_InfraLib _L23;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::_L26 */
  static kcg_int _L26;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::_L27 */
  static kcg_int _L27;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::_L52 */
  static kcg_bool _L52;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_RBC::Send_RBC_LRBG_400_D_00106_0_M015::_L53 */
  static R_data_internal_T_InfraLib _L53;
  
  _L26 = TriggerValue;
  kcg_copy_R_data_internal_T_InfraLib(&_L23, RadiaDataIn);
  _L27 = _L23.trigger;
  _L52 = _L26 == _L27;
  ck_every = _L52;
  kcg_copy_R_data_internal_T_InfraLib(&_L53, RadiaDataIn);
  /* ck_Send_RBC_LRBG_400_D_00106_0_M015 */ if (ck_every) {
    /* 1 */
    Build_RBC_LRBG_400_D_00106_0_M015_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_RBC(
      &_L53,
      &op_call);
    kcg_copy_R_data_internal_T_InfraLib(&_L4, &op_call);
  }
  else {
    kcg_copy_R_data_internal_T_InfraLib(&_L4, &_L53);
  }
  kcg_copy_R_data_internal_T_InfraLib(R_data_out, &_L4);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Send_RBC_LRBG_400_D_00106_0_M015_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_RBC.c
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

