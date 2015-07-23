/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-21T17:55:34
*************************************************************$ */
#ifndef _Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC_H_
#define _Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC_H_

#include "kcg_types.h"
#include "_7_Build_RBC_Message_LRBG_35_AmsterdamUtrechtL2_Sheet05_Amstel_RBC.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  R_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::R_data_out */ R_data_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC__7_Build_RBC_Message_LRBG_35_AmsterdamUtrechtL2_Sheet05_Amstel_RBC /* 1 */ Context_1;
  /* ------------------ clocks of observable data -------------------- */
  kcg_bool tmp;
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  R_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::_L4 */ _L4;
  R_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::_L23 */ _L23;
  kcg_int /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::_L26 */ _L26;
  kcg_int /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::_L27 */ _L27;
  kcg_bool /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::_L52 */ _L52;
  R_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::_L53 */ _L53;
} outC_Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC;

/* ===========  node initialization and cycle functions  =========== */
/* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008 */
extern void Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC(
  /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::RadiaDataIn */R_data_internal_T_InfraLib *RadiaDataIn,
  /* AmsterdamUtrechtL2::Sheet05_Amstel_RBC::Send_RBC_LRBG_353_D_00421_9_M008::TriggerValue */kcg_int TriggerValue,
  outC_Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC *outC);

extern void Send_RBC_LRBG_353_D_00421_reset_AmsterdamUtrechtL2_Sheet05_Amstel_RBC(
  outC_Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC *outC);

#endif /* _Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Send_RBC_LRBG_353_D_00421_AmsterdamUtrechtL2_Sheet05_Amstel_RBC.h
** Generation date: 2015-07-21T17:55:34
*************************************************************$ */

