/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/Simulation_EnvSim\kcg_s2c_config.txt
** Generation date: 2015-11-20T19:47:26
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Send_P057_MessageLibBaseline2.h"

/* MessageLibBaseline2::Send_P057 */
void Send_P057_MessageLibBaseline2(
  /* MessageLibBaseline2::Send_P057::B_data_in */CompressedPackets_T_Common_Types_Pkg *B_data_in,
  /* MessageLibBaseline2::Send_P057::P057 */P057_trackside_int_T_TM *P057,
  /* MessageLibBaseline2::Send_P057::B_data_out */CompressedPackets_T_Common_Types_Pkg *B_data_out)
{
  static kcg_bool tmp;
  
  if ((*P057).valid) {
    /* 1 */ Write_P057_TM_trackside(P057, B_data_in, &tmp, B_data_out);
  }
  else {
    kcg_copy_CompressedPackets_T_Common_Types_Pkg(B_data_out, B_data_in);
  }
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Send_P057_MessageLibBaseline2.c
** Generation date: 2015-11-20T19:47:26
*************************************************************$ */

