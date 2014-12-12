/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/MLRI_Integration/KCG\kcg_s2c_config.txt
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */
#ifndef _MLRI__indexOfBG_by_id_itr_CalculateTrainPosition_Pkg_BG_utilities_Pkg_H_
#define _MLRI__indexOfBG_by_id_itr_CalculateTrainPosition_Pkg_BG_utilities_Pkg_H_

#include "kcg_types.h"
#include "MLRI__positionedBGs_ids_equal_CalculateTrainPosition_Pkg_BG_utilities_Pkg.h"

/* =====================  no input structure  ====================== */


/** "Remark_1" {Description = "Iterated function for determing the index of BG in BGs - Copyright Siemens AG, 2014 - Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl ) - Gist URL: --- - Cryptography: No - Author(s): Uwe Steinke   The use of this software is limited to non-vital applications.  It has not been developed for vital operation purposes and must not be used for applications which may cause harm to people, physical accidents or financial loss.  THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.  "} */
/** "GdC_1" {Author = "Uwe Steinke", DateC = "Created : 2014-05-22", DateM = "Modified : 2014-05-22", Version = "Version : 00.02.00"} */
/* CalculateTrainPosition_Pkg::BG_utilities_Pkg::indexOfBG_by_id_itr */
extern void MLRI__indexOfBG_by_id_itr_CalculateTrainPosition_Pkg_BG_utilities_Pkg(
  /* CalculateTrainPosition_Pkg::BG_utilities_Pkg::indexOfBG_by_id_itr::iteratorIndex */kcg_int iteratorIndex,
  /* CalculateTrainPosition_Pkg::BG_utilities_Pkg::indexOfBG_by_id_itr::prevIndex */kcg_int prevIndex,
  /* CalculateTrainPosition_Pkg::BG_utilities_Pkg::indexOfBG_by_id_itr::BG */MLRI__positionedBG_T_TrainPosition_Types_Pck *BG,
  /* CalculateTrainPosition_Pkg::BG_utilities_Pkg::indexOfBG_by_id_itr::BG_asElementFromBGs */MLRI__positionedBG_T_TrainPosition_Types_Pck *BG_asElementFromBGs,
  /* CalculateTrainPosition_Pkg::BG_utilities_Pkg::indexOfBG_by_id_itr::cont */kcg_bool *cont,
  /* CalculateTrainPosition_Pkg::BG_utilities_Pkg::indexOfBG_by_id_itr::indexOfBG */kcg_int *indexOfBG);

#endif /* _MLRI__indexOfBG_by_id_itr_CalculateTrainPosition_Pkg_BG_utilities_Pkg_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** MLRI__indexOfBG_by_id_itr_CalculateTrainPosition_Pkg_BG_utilities_Pkg.h
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

