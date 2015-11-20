/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/Simulation_EnvSim\kcg_s2c_config.txt
** Generation date: 2015-11-20T19:47:27
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Amsterdam_Utrecht_US_US_Integration_November.h"

/* US_Integration_November::Amsterdam_Utrecht_US */
void Amsterdam_Utrecht_US_US_Integration_November(
  /* US_Integration_November::Amsterdam_Utrecht_US::TrainPos */kcg_real TrainPos,
  /* US_Integration_November::Amsterdam_Utrecht_US::Trigger_in */kcg_int Trigger_in,
  /* US_Integration_November::Amsterdam_Utrecht_US::SelectTrack */TrackType_US_Integration_November SelectTrack,
  /* US_Integration_November::Amsterdam_Utrecht_US::Balise_Packets */CompressedPackets_T_Common_Types_Pkg *Balise_Packets,
  /* US_Integration_November::Amsterdam_Utrecht_US::Balise_Header */TelegramHeader_T_BG_Types_Pkg *Balise_Header,
  /* US_Integration_November::Amsterdam_Utrecht_US::CompressedBaliseMessage */CompressedBaliseMessage_TM *CompressedBaliseMessage,
  /* US_Integration_November::Amsterdam_Utrecht_US::RadioTrackTrainHeader_out */Radio_TrackTrain_Header_T_Radio_Types_Pkg *RadioTrackTrainHeader_out,
  /* US_Integration_November::Amsterdam_Utrecht_US::Compressed_Packets_out */CompressedPackets_T_Common_Types_Pkg *Compressed_Packets_out,
  /* US_Integration_November::Amsterdam_Utrecht_US::Compressed_Radio_Message_out */CompressedRadioMessage_TM *Compressed_Radio_Message_out)
{
  /* 1 */
  Amsterdam_Utrecht_Lijn1_balises_AmsterdamUtrechtL2_AmsterdamUtrechtTrack1(
    TrainPos,
    CompressedBaliseMessage);
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(
    Balise_Packets,
    &(*CompressedBaliseMessage).Messages);
  /* 1 */
  Amsterdam_Utrecht_RBC_Integration_US_Integration_November(
    Trigger_in,
    SelectTrack,
    RadioTrackTrainHeader_out,
    Compressed_Packets_out,
    Compressed_Radio_Message_out);
  /* 1 */
  CASTLIB_BaliseHeaders_TM_conversions(
    &(*CompressedBaliseMessage).Header,
    Balise_Header);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Amsterdam_Utrecht_US_US_Integration_November.c
** Generation date: 2015-11-20T19:47:27
*************************************************************$ */

