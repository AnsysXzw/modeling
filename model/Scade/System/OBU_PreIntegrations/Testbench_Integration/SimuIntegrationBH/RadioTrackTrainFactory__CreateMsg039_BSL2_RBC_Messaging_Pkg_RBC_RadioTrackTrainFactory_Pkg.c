/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "RadioTrackTrainFactory__CreateMsg039_BSL2_RBC_Messaging_Pkg_RBC_RadioTrackTrainFactory_Pkg.h"

/* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2 */
void RadioTrackTrainFactory__CreateMsg039_BSL2_RBC_Messaging_Pkg_RBC_RadioTrackTrainFactory_Pkg(
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::in_T_TRAIN */ T_TRAIN in_T_TRAIN,
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::in_NID_LRBG */ NID_LRBG in_NID_LRBG,
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::outRadioTrackTrainMessage */ CompressedRadioMessage_TM *outRadioTrackTrainMessage)
{
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L27 */
  static Radio_TrackTrain_Header_T_TM _L27;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L30 */
  static T_TRAIN _L30;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L31 */
  static NID_EM _L31;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L32 */
  static Q_SCALE _L32;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L33 */
  static T_TRAIN _L33;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L34 */
  static D_REF _L34;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L35 */
  static Q_DIR _L35;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L36 */
  static D_EMERGENCYSTOP _L36;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L96 */
  static P015_trackside_int_T_TM _L96;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L95 */
  static P042_trackside_int_T_TM _L95;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L94 */
  static P005_trackside_int_T_TM _L94;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L93 */
  static P003V1_trackside_int_T_TM_baseline2 _L93;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L92 */
  static P021_trackside_int_T_TM _L92;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L91 */
  static P058_trackside_int_T_TM _L91;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L90 */
  static P027V1_trackside_int_T_TM_baseline2 _L90;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L88 */
  static P057_trackside_int_T_TM _L88;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L98 */
  static T_TRAIN _L98;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L100 */
  static NID_LRBG _L100;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L101 */
  static NID_MESSAGE _L101;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L102 */
  static M_ACK _L102;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L103 */
  static M_VERSION _L103;
  /* RBC_Messaging_Pkg::RBC_RadioTrackTrainFactory_Pkg::RadioTrackTrainFactory__CreateMsg039_BSL2::_L105 */
  static CompressedRadioMessage_TM _L105;
  
  _L101 = 39;
  _L98 = in_T_TRAIN;
  _L102 = M_ACK_No_acknowledgement_required;
  _L100 = in_NID_LRBG;
  _L30 = T_TRAIN_DEFAULT;
  _L31 = NID_EM_DEFAULT;
  _L32 = Q_SCALE_DEFAULT;
  _L33 = T_TRAIN_DEFAULT;
  _L34 = D_REF_DEFAULT;
  _L35 = Q_DIR_DEFAULT;
  _L36 = D_EMERGENCYSTOP_DEFAULT;
  _L103 = M_VERSION_DEFAULT;
  /* 1 */
  RadioTrackTrainHeader__Create_RBC_Messaging_Pkg_RBC_RadioTrackTrain_Pkg(
    _L101,
    _L98,
    _L102,
    _L100,
    _L30,
    _L31,
    _L32,
    _L33,
    _L34,
    _L35,
    _L36,
    _L103,
    &_L27);
  kcg_copy_P003V1_trackside_int_T_TM_baseline2(
    &_L93,
    (P003V1_trackside_int_T_TM_baseline2 *) &P003_DEFAULT);
  kcg_copy_P005_trackside_int_T_TM(
    &_L94,
    (P005_trackside_int_T_TM *) &P005_DEFAULT);
  kcg_copy_P015_trackside_int_T_TM(
    &_L96,
    (P015_trackside_int_T_TM *) &P015_DEFAULT);
  kcg_copy_P021_trackside_int_T_TM(
    &_L92,
    (P021_trackside_int_T_TM *) &P021_DEFAULT);
  kcg_copy_P027V1_trackside_int_T_TM_baseline2(
    &_L90,
    (P027V1_trackside_int_T_TM_baseline2 *) &P027_DEFAULT);
  kcg_copy_P042_trackside_int_T_TM(
    &_L95,
    (P042_trackside_int_T_TM *) &P042_DEFAULT);
  kcg_copy_P057_trackside_int_T_TM(
    &_L88,
    (P057_trackside_int_T_TM *) &P057_DEFAULT);
  kcg_copy_P058_trackside_int_T_TM(
    &_L91,
    (P058_trackside_int_T_TM *) &P058_DEFAULT);
  /* 2 */
  SEND_MergeRadioPackets_RBC_SendMergeRadio_Pkg(
    &_L27,
    &_L93,
    &_L94,
    &_L96,
    &_L92,
    &_L90,
    &_L95,
    &_L88,
    &_L91,
    &_L105);
  kcg_copy_CompressedRadioMessage_TM(outRadioTrackTrainMessage, &_L105);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** RadioTrackTrainFactory__CreateMsg039_BSL2_RBC_Messaging_Pkg_RBC_RadioTrackTrainFactory_Pkg.c
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

