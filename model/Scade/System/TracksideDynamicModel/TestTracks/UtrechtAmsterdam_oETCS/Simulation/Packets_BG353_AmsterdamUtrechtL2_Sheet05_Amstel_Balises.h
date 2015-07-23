/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-21T17:55:34
*************************************************************$ */
#ifndef _Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises_H_
#define _Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises_H_

#include "kcg_types.h"
#include "Send_P255_MessageLibBaseline2.h"
#include "Send_P042_MessageLibBaseline2.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  B_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::Balise_data_out */ Balise_data_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Send_P255_MessageLibBaseline2 /* 1 */ _1_Context_1;
  outC_Send_P042_MessageLibBaseline2 /* 2 */ Context_2;
  outC_Send_P042_MessageLibBaseline2 /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::B_data_in */ B_data_in;
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::B_data_out */ B_data_out;
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L2 */ _L2;
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L11 */ _L11;
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L22 */ _L22;
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L25 */ _L25;
  B_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L26 */ _L26;
  BaliseTelegramHeader_int_T_TM /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L28 */ _L28;
  B_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L29 */ _L29;
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L30 */ _L30;
  B_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L31 */ _L31;
  B_data_internal_T_InfraLib /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L32 */ _L32;
  kcg_bool /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L33 */ _L33;
  CompressedPackets_T_Common_Types_Pkg /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::_L34 */ _L34;
} outC_Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises;

/* ===========  node initialization and cycle functions  =========== */
/* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353 */
extern void Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises(
  /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::Header */BaliseTelegramHeader_int_T_TM *Header,
  /* AmsterdamUtrechtL2::Sheet05_Amstel_Balises::Packets_BG353::Balise_data_in */B_data_internal_T_InfraLib *Balise_data_in,
  outC_Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises *outC);

extern void Packets_BG353_reset_AmsterdamUtrechtL2_Sheet05_Amstel_Balises(
  outC_Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises *outC);

#endif /* _Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Packets_BG353_AmsterdamUtrechtL2_Sheet05_Amstel_Balises.h
** Generation date: 2015-07-21T17:55:34
*************************************************************$ */

