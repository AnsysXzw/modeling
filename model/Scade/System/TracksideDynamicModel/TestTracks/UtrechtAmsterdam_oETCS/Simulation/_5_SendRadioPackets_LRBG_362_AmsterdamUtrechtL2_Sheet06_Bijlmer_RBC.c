/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-07T00:28:47
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "_5_SendRadioPackets_LRBG_362_AmsterdamUtrechtL2_Sheet06_Bijlmer_RBC.h"

void _5_SendRadioPackets_LRBG_362_reset_AmsterdamUtrechtL2_Sheet06_Bijlmer_RBC(
  outC__5_SendRadioPackets_LRBG_362_AmsterdamUtrechtL2_Sheet06_Bijlmer_RBC *outC)
{
  /* 1 */ Send_P255_reset_MessageLibBaseline2(&outC->_5_Context_1);
  /* 1 */ Send_P065_reset_MessageLibBaseline2(&outC->_4_Context_1);
  /* 1 */ Send_P005_reset_MessageLibBaseline2(&outC->_3_Context_1);
  /* 1 */ Send_P027V1_reset_MessageLibBaseline2(&outC->_2_Context_1);
  /* 1 */ Send_P021_reset_MessageLibBaseline2(&outC->_1_Context_1);
  /* 1 */ Send_P015_reset_MessageLibBaseline2(&outC->Context_1);
}

/* AmsterdamUtrechtL2::Sheet06_Bijlmer_RBC::SendRadioPackets_LRBG_362_D_00230_7_M003 */
void _5_SendRadioPackets_LRBG_362_AmsterdamUtrechtL2_Sheet06_Bijlmer_RBC(
  /* AmsterdamUtrechtL2::Sheet06_Bijlmer_RBC::SendRadioPackets_LRBG_362_D_00230_7_M003::Radio_packets_in */CompressedPackets_T_Common_Types_Pkg *Radio_packets_in,
  outC__5_SendRadioPackets_LRBG_362_AmsterdamUtrechtL2_Sheet06_Bijlmer_RBC *outC)
{
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(&outC->_L32, Radio_packets_in);
  /* 1 */
  Send_P015_MessageLibBaseline2(
    &outC->_L32,
    (P015_trackside_int_T_TM *) &LRBG362_P015_1_Packets426,
    &outC->Context_1);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    &outC->_L11,
    &outC->Context_1.B_data_out);
  /* 1 */
  Send_P021_MessageLibBaseline2(
    &outC->_L11,
    (P021_trackside_int_T_TM *) &LRBG362_P021_1_Packets426,
    &outC->_1_Context_1);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    &outC->_L2,
    &outC->_1_Context_1.B_data_out);
  /* 1 */
  Send_P027V1_MessageLibBaseline2(
    &outC->_L2,
    (P027V1_trackside_int_T_TM_baseline2 *) &LRBG362_P027_1_Packets426,
    &outC->_2_Context_1);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    &outC->_L3,
    &outC->_2_Context_1.B_data_out);
  /* 1 */
  Send_P005_MessageLibBaseline2(
    &outC->_L3,
    (P005_trackside_int_T_TM *) &LRBG362_P005_1_Packets426,
    &outC->_3_Context_1);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    &outC->_L5,
    &outC->_3_Context_1.B_data_out);
  /* 1 */
  Send_P065_MessageLibBaseline2(
    &outC->_L5,
    (P065_trackside_int_T_TM *) &LRBG362_P065_1_Packets426,
    &outC->_4_Context_1);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    &outC->_L7,
    &outC->_4_Context_1.B_data_out);
  /* 1 */
  Send_P255_MessageLibBaseline2(
    &outC->_L7,
    (P255_trackside_int_T_TM *) &BGXXX_P255_Packets426,
    &outC->_5_Context_1);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    &outC->_L8,
    &outC->_5_Context_1.packet_data_out);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    &outC->Radio_packets_out,
    &outC->_L8);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** _5_SendRadioPackets_LRBG_362_AmsterdamUtrechtL2_Sheet06_Bijlmer_RBC.c
** Generation date: 2015-07-07T00:28:47
*************************************************************$ */

