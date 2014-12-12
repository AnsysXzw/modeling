/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/MLRI_Integration/KCG\kcg_s2c_config.txt
** Generation date: 2014-12-12T12:03:55
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "MLRI__op_3_6_5_1_4_b_ProvidePositionReport_Pkg.h"

void MLRI__op_3_6_5_1_4_b_reset_ProvidePositionReport_Pkg(
  MLRI__outC_op_3_6_5_1_4_b_ProvidePositionReport_Pkg *outC)
{
  outC->init = kcg_true;
}

/* ProvidePositionReport_Pkg::op_3_6_5_1_4_b */
void MLRI__op_3_6_5_1_4_b_ProvidePositionReport_Pkg(
  /* ProvidePositionReport_Pkg::op_3_6_5_1_4_b::train2trackStatus */MLRI__TrainToTrackStatus_T_BG_Types_Pkg *train2trackStatus,
  MLRI__outC_op_3_6_5_1_4_b_ProvidePositionReport_Pkg *outC)
{
  MLRI__M_MODE tmp;
  
  if (outC->init) {
    tmp = MLRI__cTrack2TrainStatus_ProvidePositionReport_Pkg.m_mode;
  }
  else {
    tmp = outC->rem_train2trackStatus.m_mode;
  }
  outC->b = (*train2trackStatus).m_mode != tmp;
  MLRI__kcg_copy_TrainToTrackStatus_T_BG_Types_Pkg(
    &outC->rem_train2trackStatus,
    train2trackStatus);
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** MLRI__op_3_6_5_1_4_b_ProvidePositionReport_Pkg.c
** Generation date: 2014-12-12T12:03:55
*************************************************************$ */

