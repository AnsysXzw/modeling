/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/Simulation_EnvSim\kcg_s2c_config.txt
** Generation date: 2015-11-20T19:47:26
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Send_M008_JRU_MessageLibBaseline2.h"

/* MessageLibBaseline2::Send_M008_JRU */
void Send_M008_JRU_MessageLibBaseline2(
  /* MessageLibBaseline2::Send_M008_JRU::M008 */M_008_int_T_TM_radio_messages *M008,
  /* MessageLibBaseline2::Send_M008_JRU::Message_Out */M_TrackTrain_Radio_T_TM_radio_messages *Message_Out)
{
  /* 1 */ C_M008_int_to_header_TM_RBC_conversions(M008, Message_Out);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Send_M008_JRU_MessageLibBaseline2.c
** Generation date: 2015-11-20T19:47:26
*************************************************************$ */

