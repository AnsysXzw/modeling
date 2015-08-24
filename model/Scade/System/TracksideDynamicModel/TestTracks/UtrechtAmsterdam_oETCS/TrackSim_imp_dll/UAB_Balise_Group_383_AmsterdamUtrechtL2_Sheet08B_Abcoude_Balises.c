/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/TrackSim_imp_dll\kcg_s2c_config.txt
** Generation date: 2015-08-20T20:42:33
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "UAB_Balise_Group_383_AmsterdamUtrechtL2_Sheet08B_Abcoude_Balises.h"

/* AmsterdamUtrechtL2::Sheet08B_Abcoude_Balises::Balise_Group_383 */
void UAB_Balise_Group_383_AmsterdamUtrechtL2_Sheet08B_Abcoude_Balises(
  /* AmsterdamUtrechtL2::Sheet08B_Abcoude_Balises::Balise_Group_383::BG_message_in */UAB_CompressedBaliseMessage_TM *BG_message_in,
  /* AmsterdamUtrechtL2::Sheet08B_Abcoude_Balises::Balise_Group_383::TrainPos */kcg_real TrainPos,
  /* AmsterdamUtrechtL2::Sheet08B_Abcoude_Balises::Balise_Group_383::Engineering_Data */UAB_BaliseGroupData_TM *Engineering_Data,
  /* AmsterdamUtrechtL2::Sheet08B_Abcoude_Balises::Balise_Group_383::BG_message_out */UAB_CompressedBaliseMessage_TM *BG_message_out)
{
  static UAB_B_data_internal_T_InfraLib tmp1;
  static UAB_B_data_internal_T_InfraLib tmp;
  /* AmsterdamUtrechtL2::Sheet08B_Abcoude_Balises::Balise_Group_383::_L14 */
  static kcg_bool _L14;
  
  /* 1 */ UAB_Balise_Group_Init_InfraLib(TrainPos, Engineering_Data, &tmp1);
  /* 1 */
  UAB_Balise_383_1_AmsterdamUtrechtL2_Sheet08B_Abcoude_Balises(
    &tmp1,
    (UAB_BaliseTelegramHeader_int_T_TM *) &UAB_BG383_header_B1_Balises426,
    0,
    &tmp);
  /* 1 */
  UAB_Balise_383_0_AmsterdamUtrechtL2_Sheet08B_Abcoude_Balises(
    &tmp,
    (UAB_BaliseTelegramHeader_int_T_TM *) &UAB_BG383_header_B0_Balises426,
    1,
    &tmp1);
  /* 1 */
  UAB_Balise_Group_Close_InfraLib(&tmp1, BG_message_in, &_L14, BG_message_out);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UAB_Balise_Group_383_AmsterdamUtrechtL2_Sheet08B_Abcoude_Balises.c
** Generation date: 2015-08-20T20:42:33
*************************************************************$ */

