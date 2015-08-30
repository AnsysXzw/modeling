/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-08-30T07:02:45
*************************************************************$ */
#ifndef __9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg_H_
#define __9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg_H_

#include "kcg_types.h"
#include "_8_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  positionedBGs_T_TrainPosition_Types_Pck /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::BGs_out */ BGs_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC__8_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg /* 1 */ Context_1[8];
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  positionedBG_T_TrainPosition_Types_Pck /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L1 */ _L1;
  positionedBGs_T_TrainPosition_Types_Pck /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L2 */ _L2;
  refBGs_T_CalculateTrainPosition_Pkg_BG_relocation_Pkg /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L3 */ _L3;
  array__16894 /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L4 */ _L4;
  refBGs_T_CalculateTrainPosition_Pkg_BG_relocation_Pkg /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L7 */ _L7;
  refBGs_T_CalculateTrainPosition_Pkg_BG_relocation_Pkg /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L8 */ _L8;
  trainProperties_T_TrainPosition_Types_Pck /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L9 */ _L9;
  array__17549 /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::_L10 */ _L10;
} outC__9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg;

/* ===========  node initialization and cycle functions  =========== */
/* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead */
extern void _9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg(
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::referenceBG */positionedBG_T_TrainPosition_Types_Pck *referenceBG,
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::BGs_in */positionedBGs_T_TrainPosition_Types_Pck *BGs_in,
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_locations_ahead::trainProperties */trainProperties_T_TrainPosition_Types_Pck *trainProperties,
  outC__9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg *outC);

extern void _9_recalculate_BG_locations__reset_CalculateTrainPosition_Pkg_BG_relocation_Pkg(
  outC__9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg *outC);

#endif /* __9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** _9_recalculate_BG_locations__CalculateTrainPosition_Pkg_BG_relocation_Pkg.h
** Generation date: 2015-08-30T07:02:45
*************************************************************$ */

