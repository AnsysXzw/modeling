/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-21T17:55:34
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Balises0010_Breukelen_Maa_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises.h"

void Balises0010_Breukelen_Maa_reset_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
  outC_Balises0010_Breukelen_Maa_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises *outC)
{
  /* 1 */
  Balise_Group_423_reset_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->_3_Context_1);
  /* 1 */
  Balise_Group_422_reset_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->_2_Context_1);
  /* 1 */
  Balise_Group_421_reset_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->_1_Context_1);
  /* 1 */
  Balise_Group_420_reset_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->Context_1);
}

/* AmsterdamUtrechtL2::Sheet13_Breukelen_Maarssen_Balises::Balises0010_Breukelen_Maarssen */
void Balises0010_Breukelen_Maa_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
  /* AmsterdamUtrechtL2::Sheet13_Breukelen_Maarssen_Balises::Balises0010_Breukelen_Maarssen::SectionData_in */TrackSectionData_T_InfraLib *SectionData_in,
  outC_Balises0010_Breukelen_Maa_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises *outC)
{
  kcg_copy_TrackSectionData_T_InfraLib(&outC->_L6, SectionData_in);
  kcg_copy_CompressedBaliseMessage_TM(&outC->_L3, &outC->_L6.BG_Message);
  outC->_L2 = outC->_L6.TrainPosRaw.TrainPosCalibrated;
  /* 1 */
  Balise_Group_420_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->_L3,
    outC->_L2,
    (BaliseGroupData_TM *) &BG420_Balises426,
    &outC->Context_1);
  kcg_copy_CompressedBaliseMessage_TM(
    &outC->_L1,
    &outC->Context_1.BG_message_out);
  /* 1 */
  Balise_Group_421_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->_L1,
    outC->_L2,
    (BaliseGroupData_TM *) &BG421_Balises426,
    &outC->_1_Context_1);
  kcg_copy_CompressedBaliseMessage_TM(
    &outC->_L7,
    &outC->_1_Context_1.BG_message_out);
  /* 1 */
  Balise_Group_422_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->_L7,
    outC->_L2,
    (BaliseGroupData_TM *) &BG422_Balises426,
    &outC->_2_Context_1);
  kcg_copy_CompressedBaliseMessage_TM(
    &outC->_L8,
    &outC->_2_Context_1.BG_message_out);
  /* 1 */
  Balise_Group_423_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises(
    &outC->_L8,
    outC->_L2,
    (BaliseGroupData_TM *) &BG423_Balises426,
    &outC->_3_Context_1);
  kcg_copy_CompressedBaliseMessage_TM(
    &outC->_L9,
    &outC->_3_Context_1.BG_message_out);
  kcg_copy_TrackSectionData_T_InfraLib(&outC->_L4, &outC->_L6);
  if (kcg_true) {
    kcg_copy_CompressedBaliseMessage_TM(&outC->_L4.BG_Message, &outC->_L9);
  }
  kcg_copy_TrackSectionData_T_InfraLib(&outC->SectionData_out, &outC->_L4);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Balises0010_Breukelen_Maa_AmsterdamUtrechtL2_Sheet13_Breukelen_Maarssen_Balises.c
** Generation date: 2015-07-21T17:55:34
*************************************************************$ */

