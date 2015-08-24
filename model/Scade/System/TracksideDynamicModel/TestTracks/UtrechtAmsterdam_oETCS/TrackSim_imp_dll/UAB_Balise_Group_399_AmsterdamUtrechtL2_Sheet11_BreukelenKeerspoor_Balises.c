/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/TrackSim_imp_dll\kcg_s2c_config.txt
** Generation date: 2015-08-20T20:42:33
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "UAB_Balise_Group_399_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_Balises.h"

/* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_Balises::Balise_Group_399 */
void UAB_Balise_Group_399_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_Balises(
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_Balises::Balise_Group_399::BG_message_in */UAB_CompressedBaliseMessage_TM *BG_message_in,
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_Balises::Balise_Group_399::TrainPos */kcg_real TrainPos,
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_Balises::Balise_Group_399::Engineering_Data */UAB_BaliseGroupData_TM *Engineering_Data,
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_Balises::Balise_Group_399::BG_message_out */UAB_CompressedBaliseMessage_TM *BG_message_out)
{
  static UAB_B_data_internal_T_InfraLib tmp1;
  static UAB_B_data_internal_T_InfraLib tmp;
  /* AmsterdamUtrechtL2::Sheet11_BreukelenKeerspoor_Balises::Balise_Group_399::_L14 */
  static kcg_bool _L14;
  
  /* 1 */ UAB_Balise_Group_Init_InfraLib(TrainPos, Engineering_Data, &tmp1);
  /* 1 */
  UAB_Balise_399_1_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_Balises(
    &tmp1,
    (UAB_BaliseTelegramHeader_int_T_TM *) &UAB_BG399_header_B1_Balises426,
    0,
    &tmp);
  /* 1 */
  UAB_Balise_399_0_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_Balises(
    &tmp,
    (UAB_BaliseTelegramHeader_int_T_TM *) &UAB_BG399_header_B0_Balises426,
    1,
    &tmp1);
  /* 1 */
  UAB_Balise_Group_Close_InfraLib(&tmp1, BG_message_in, &_L14, BG_message_out);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UAB_Balise_Group_399_AmsterdamUtrechtL2_Sheet11_BreukelenKeerspoor_Balises.c
** Generation date: 2015-08-20T20:42:33
*************************************************************$ */

