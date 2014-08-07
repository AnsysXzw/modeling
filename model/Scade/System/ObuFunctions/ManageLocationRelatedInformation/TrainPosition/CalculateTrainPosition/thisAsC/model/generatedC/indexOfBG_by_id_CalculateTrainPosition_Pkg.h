/* $************* KCG Version 6.4 beta5 (build i13) *************
** Command: kcg64.exe -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/section/040_Model/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/TrainPosition/CalculateTrainPosition/KCG/config.txt
** Generation date: 2014-08-07T09:21:25
*************************************************************$ */
#ifndef _indexOfBG_by_id_CalculateTrainPosition_Pkg_H_
#define _indexOfBG_by_id_CalculateTrainPosition_Pkg_H_

#include "kcg_types.h"
#include "indexOfBG_by_id_itr_CalculateTrainPosition_Pkg.h"

/* =====================  no input structure  ====================== */


/** "Remark_1" {Description = "Determines the index of BG in BGs - Copyright Siemens AG, 2014 - Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl ) - Gist URL: --- - Cryptography: No - Author(s): Uwe Steinke   The use of this software is limited to non-vital applications.  It has not been developed for vital operation purposes and must not be used for applications which may cause harm to people, physical accidents or financial loss.  THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.  "} */
/** "GdC_1" {Author = "Uwe Steinke", DateC = "Created : 2014-05-22", DateM = "Modified : 2014-05-22", Version = "Version : 00.02.00"} */
/* CalculateTrainPosition_Pkg::indexOfBG_by_id */
extern void indexOfBG_by_id_CalculateTrainPosition_Pkg(
  /* CalculateTrainPosition_Pkg::indexOfBG_by_id::BG */ positionedBG_T_TrainPosition_Types_Pck *BG,
  /* CalculateTrainPosition_Pkg::indexOfBG_by_id::BGs */ positionedBGs_T_TrainPosition_Types_Pck *BGs,
  /* CalculateTrainPosition_Pkg::indexOfBG_by_id::enable */ kcg_bool enable,
  /* CalculateTrainPosition_Pkg::indexOfBG_by_id::indexOfBG */ kcg_int *indexOfBG,
  /* CalculateTrainPosition_Pkg::indexOfBG_by_id::BG_found */ kcg_bool *BG_found,
  /* CalculateTrainPosition_Pkg::indexOfBG_by_id::indexValid */ kcg_bool *indexValid);

#endif /* _indexOfBG_by_id_CalculateTrainPosition_Pkg_H_ */
/* $************* KCG Version 6.4 beta5 (build i13) *************
** indexOfBG_by_id_CalculateTrainPosition_Pkg.h
** Generation date: 2014-08-07T09:21:25
*************************************************************$ */

