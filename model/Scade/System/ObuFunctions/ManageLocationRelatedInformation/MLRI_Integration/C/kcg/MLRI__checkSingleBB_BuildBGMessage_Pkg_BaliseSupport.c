/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/MLRI_Integration/KCG\kcg_s2c_config.txt
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "MLRI__checkSingleBB_BuildBGMessage_Pkg_BaliseSupport.h"

/* BuildBGMessage_Pkg::BaliseSupport::checkSingleBB */
void MLRI__checkSingleBB_BuildBGMessage_Pkg_BaliseSupport(
  /* BuildBGMessage_Pkg::BaliseSupport::checkSingleBB::inTelegram */MLRI__Telegram_T_BG_Types_Pkg *inTelegram,
  /* BuildBGMessage_Pkg::BaliseSupport::checkSingleBB::inCollector */MLRI__BGCollector_T_BuildBGMessage_Pkg *inCollector,
  /* BuildBGMessage_Pkg::BaliseSupport::checkSingleBB::outCollector */MLRI__BGCollector_T_BuildBGMessage_Pkg *outCollector)
{
  (*outCollector).badBaliseFlag = !(*inTelegram).valid &
    !(*inCollector).BGMessageSent & ((*inCollector).collectedTelegrams == 0);
  (*outCollector).BGMessageSent = (*inCollector).BGMessageSent;
  (*outCollector).C_ID = (*inCollector).C_ID;
  (*outCollector).BG_ID = (*inCollector).BG_ID;
  MLRI__kcg_copy_centerOfBalisePosition_T_BG_Types_Pkg(
    &(*outCollector).balisePosition,
    &(*inCollector).balisePosition);
  MLRI__kcg_copy_centerOfBalisePosition_T_BG_Types_Pkg(
    &(*outCollector).positionFirstContact,
    &(*inCollector).positionFirstContact);
  (*outCollector).collectedTelegrams = (*inCollector).collectedTelegrams;
  (*outCollector).totalTelegrams = (*inCollector).totalTelegrams;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** MLRI__checkSingleBB_BuildBGMessage_Pkg_BaliseSupport.c
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

