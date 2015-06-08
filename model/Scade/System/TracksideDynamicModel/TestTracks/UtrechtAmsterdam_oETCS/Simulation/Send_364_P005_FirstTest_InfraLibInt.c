/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-06-05T10:24:11
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Send_364_P005_FirstTest_InfraLibInt.h"

void Send_364_P005_reset_FirstTest_InfraLibInt(
  outC_Send_364_P005_FirstTest_InfraLibInt *outC)
{
  /* 1 */ SEND_WritePacket005_IT_legacy_reset_TM_trackside(&outC->Context_1);
}

/* FirstTest::InfraLibInt::Send_364_P005 */
void Send_364_P005_FirstTest_InfraLibInt(
  /* FirstTest::InfraLibInt::Send_364_P005::B_data_in */CompressedPackets_T_Common_Types_Pkg *B_data_in,
  /* FirstTest::InfraLibInt::Send_364_P005::P005 */P005old_TM *P005,
  outC_Send_364_P005_FirstTest_InfraLibInt *outC)
{
  CompressedPackets_T_Common_Types_Pkg tmp;
  kcg_bool tmp1;
  kcg_bool noname;
  
  kcg_copy_P005old_TM(&outC->_L4, P005);
  outC->_L5 = outC->_L4.valid;
  outC->tmp = outC->_L5;
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(&outC->_L3, B_data_in);
  if (outC->tmp) {
    /* 1 */
    SEND_WritePacket005_IT_legacy_TM_trackside(
      &outC->_L4,
      &outC->_L3,
      &outC->Context_1);
    tmp1 = outC->Context_1.Error;
    kcg_copy_CompressedPackets_T_Common_Types_Pkg(
      &tmp,
      &outC->Context_1.RadioPacketsOut);
    kcg_copy_CompressedPackets_T_Common_Types_Pkg(&outC->_L7, &tmp);
  }
  else {
    kcg_copy_CompressedPackets_T_Common_Types_Pkg(&outC->_L7, &outC->_L3);
  }
  outC->_L8 = kcg_false;
  if (outC->tmp) {
    outC->_L6 = tmp1;
  }
  else {
    outC->_L6 = outC->_L8;
  }
  noname = outC->_L6;
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(&outC->B_data_out, &outC->_L7);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Send_364_P005_FirstTest_InfraLibInt.c
** Generation date: 2015-06-05T10:24:11
*************************************************************$ */

