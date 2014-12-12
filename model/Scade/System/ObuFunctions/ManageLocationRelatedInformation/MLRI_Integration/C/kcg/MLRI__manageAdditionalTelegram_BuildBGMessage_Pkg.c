/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/MLRI_Integration/KCG\kcg_s2c_config.txt
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "MLRI__manageAdditionalTelegram_BuildBGMessage_Pkg.h"

/* BuildBGMessage_Pkg::manageAdditionalTelegram */
void MLRI__manageAdditionalTelegram_BuildBGMessage_Pkg(
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::inDecodedTelegram */MLRI__Telegram_T_BG_Types_Pkg *inDecodedTelegram,
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::incenterOfBalisePosition */MLRI__centerOfBalisePosition_T_BG_Types_Pkg *incenterOfBalisePosition,
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::inTelegramStore */MLRI__TelegramStore_T_BuildBGMessage_Pkg *inTelegramStore,
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::inputTelegramPresent */kcg_bool inputTelegramPresent,
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::outputPresent */kcg_bool *outputPresent,
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::outDecodedTelegram */MLRI__Telegram_T_BG_Types_Pkg *outDecodedTelegram,
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::outcenterOfBalisePosition */MLRI__centerOfBalisePosition_T_BG_Types_Pkg *outcenterOfBalisePosition,
  /* BuildBGMessage_Pkg::manageAdditionalTelegram::outNeedStore */kcg_bool *outNeedStore)
{
  *outputPresent = inputTelegramPresent | (*inTelegramStore).valid;
  if ((*inTelegramStore).valid) {
    MLRI__kcg_copy_Telegram_T_BG_Types_Pkg(
      outDecodedTelegram,
      &(*inTelegramStore).telegram);
    MLRI__kcg_copy_centerOfBalisePosition_T_BG_Types_Pkg(
      outcenterOfBalisePosition,
      &(*inTelegramStore).position);
  }
  else {
    MLRI__kcg_copy_Telegram_T_BG_Types_Pkg(
      outDecodedTelegram,
      inDecodedTelegram);
    MLRI__kcg_copy_centerOfBalisePosition_T_BG_Types_Pkg(
      outcenterOfBalisePosition,
      incenterOfBalisePosition);
  }
  *outNeedStore = (*inTelegramStore).valid & inputTelegramPresent;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** MLRI__manageAdditionalTelegram_BuildBGMessage_Pkg.c
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

