/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-06-05T10:24:11
*************************************************************$ */
#ifndef _Send_364_P005_FirstTest_InfraLibInt_H_
#define _Send_364_P005_FirstTest_InfraLibInt_H_

#include "kcg_types.h"
#include "SEND_WritePacket005_IT_legacy_TM_trackside.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  CompressedPackets_T_Common_Types_Pkg /* FirstTest::InfraLibInt::Send_364_P005::B_data_out */ B_data_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_SEND_WritePacket005_IT_legacy_TM_trackside /* 1 */ Context_1;
  /* ------------------ clocks of observable data -------------------- */
  kcg_bool tmp;
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  CompressedPackets_T_Common_Types_Pkg /* FirstTest::InfraLibInt::Send_364_P005::_L3 */ _L3;
  P005old_TM /* FirstTest::InfraLibInt::Send_364_P005::_L4 */ _L4;
  kcg_bool /* FirstTest::InfraLibInt::Send_364_P005::_L8 */ _L8;
  kcg_bool /* FirstTest::InfraLibInt::Send_364_P005::_L6 */ _L6;
  CompressedPackets_T_Common_Types_Pkg /* FirstTest::InfraLibInt::Send_364_P005::_L7 */ _L7;
  kcg_bool /* FirstTest::InfraLibInt::Send_364_P005::_L5 */ _L5;
} outC_Send_364_P005_FirstTest_InfraLibInt;

/* ===========  node initialization and cycle functions  =========== */
/* FirstTest::InfraLibInt::Send_364_P005 */
extern void Send_364_P005_FirstTest_InfraLibInt(
  /* FirstTest::InfraLibInt::Send_364_P005::B_data_in */CompressedPackets_T_Common_Types_Pkg *B_data_in,
  /* FirstTest::InfraLibInt::Send_364_P005::P005 */P005old_TM *P005,
  outC_Send_364_P005_FirstTest_InfraLibInt *outC);

extern void Send_364_P005_reset_FirstTest_InfraLibInt(
  outC_Send_364_P005_FirstTest_InfraLibInt *outC);

#endif /* _Send_364_P005_FirstTest_InfraLibInt_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Send_364_P005_FirstTest_InfraLibInt.h
** Generation date: 2015-06-05T10:24:11
*************************************************************$ */

