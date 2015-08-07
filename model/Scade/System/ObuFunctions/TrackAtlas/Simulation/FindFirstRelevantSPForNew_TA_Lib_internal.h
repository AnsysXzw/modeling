/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-08-07T17:15:59
*************************************************************$ */
#ifndef _FindFirstRelevantSPForNew_TA_Lib_internal_H_
#define _FindFirstRelevantSPForNew_TA_Lib_internal_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::cont */ cont;
  kcg_int /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::relevant_section */ relevant_section;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L168 */ _L168;
  kcg_int /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L169 */ _L169;
  SSP_cat_t_TA_MRSP /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L170 */ _L170;
  kcg_int /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L171 */ _L171;
  SSP_section_t_TA_MRSP /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L172 */ _L172;
  SSP_t_section_t_TA_MRSP /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L173 */ _L173;
  kcg_bool /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L174 */ _L174;
  kcg_int /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L175 */ _L175;
  kcg_bool /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L181 */ _L181;
  kcg_bool /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L180 */ _L180;
  kcg_bool /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L179 */ _L179;
  kcg_bool /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L178 */ _L178;
  kcg_bool /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L177 */ _L177;
  kcg_int /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L176 */ _L176;
  kcg_int /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::_L182 */ _L182;
} outC_FindFirstRelevantSPForNew_TA_Lib_internal;

/* ===========  node initialization and cycle functions  =========== */
/* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop */
extern void FindFirstRelevantSPForNew_TA_Lib_internal(
  /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::i */kcg_int i,
  /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::Acc */kcg_int Acc,
  /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::Profile_in */SSP_cat_t_TA_MRSP *Profile_in,
  /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG_Loop::Distance_2LRBGs */kcg_int Distance_2LRBGs,
  outC_FindFirstRelevantSPForNew_TA_Lib_internal *outC);

extern void FindFirstRelevantSPForNew_reset_TA_Lib_internal(
  outC_FindFirstRelevantSPForNew_TA_Lib_internal *outC);

#endif /* _FindFirstRelevantSPForNew_TA_Lib_internal_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** FindFirstRelevantSPForNew_TA_Lib_internal.h
** Generation date: 2015-08-07T17:15:59
*************************************************************$ */

