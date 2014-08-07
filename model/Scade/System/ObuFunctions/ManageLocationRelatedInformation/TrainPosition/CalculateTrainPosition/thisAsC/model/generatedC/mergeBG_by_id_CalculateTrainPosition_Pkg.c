/* $************* KCG Version 6.4 beta5 (build i13) *************
** Command: kcg64.exe -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/section/040_Model/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/TrainPosition/CalculateTrainPosition/KCG/config.txt
** Generation date: 2014-08-07T09:21:25
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "mergeBG_by_id_CalculateTrainPosition_Pkg.h"

/** "Remark_1" {Description = "Merges a BG into an array of BGs - Copyright Siemens AG, 2014 - Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl ) - Gist URL: --- - Cryptography: No - Author(s): Uwe Steinke   The use of this software is limited to non-vital applications.  It has not been developed for vital operation purposes and must not be used for applications which may cause harm to people, physical accidents or financial loss.  THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.  "} */
/** "GdC_1" {Author = "Uwe Steinke", DateC = "Created : 2014-05-22", DateM = "Modified : 2014-05-22", Version = "00.02.00"} */
/* CalculateTrainPosition_Pkg::mergeBG_by_id */
void mergeBG_by_id_CalculateTrainPosition_Pkg(
  /* CalculateTrainPosition_Pkg::mergeBG_by_id::BG */ positionedBG_T_TrainPosition_Types_Pck *BG,
  /* CalculateTrainPosition_Pkg::mergeBG_by_id::BGs_in */ positionedBGs_T_TrainPosition_Types_Pck *BGs_in,
  /* CalculateTrainPosition_Pkg::mergeBG_by_id::BGs_out */ positionedBGs_T_TrainPosition_Types_Pck *BGs_out,
  /* CalculateTrainPosition_Pkg::mergeBG_by_id::overrun */ kcg_bool *overrun)
{
  /* CalculateTrainPosition_Pkg::mergeBG_by_id::_L5 */ kcg_bool _L5;
  /* CalculateTrainPosition_Pkg::mergeBG_by_id::_L4 */ kcg_bool _L4;
  /* CalculateTrainPosition_Pkg::mergeBG_by_id::_L3 */ kcg_int _L3;
  
  /* 1 */
  indexOfBG_by_id_CalculateTrainPosition_Pkg(
    BG,
    BGs_in,
    (*BG).valid,
    &_L3,
    &_L4,
    &_L5);
  *overrun = !_L5 & (*BG).valid;
  kcg_copy_positionedBGs_T_TrainPosition_Types_Pck(BGs_out, BGs_in);
  if ((0 <= _L3) & (_L3 < 64)) {
    kcg_copy_positionedBG_T_TrainPosition_Types_Pck(&(*BGs_out)[_L3], BG);
  }
}

/* $************* KCG Version 6.4 beta5 (build i13) *************
** mergeBG_by_id_CalculateTrainPosition_Pkg.c
** Generation date: 2014-08-07T09:21:25
*************************************************************$ */

