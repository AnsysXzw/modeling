/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-28T17:06:46
*************************************************************$ */
#ifndef _Update_LRBG_then_SSP_TA_SSP_H_
#define _Update_LRBG_then_SSP_TA_SSP_H_

#include "kcg_types.h"
#include "MoveSPSectionsToNewLRBGafter_TA_Lib_internal.h"
#include "Update_SP_per_LRBG_TA_Lib_internal.h"
#include "_17_Convert_P27_to_DistancePr_TA_SSP.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  SSP_cat_t_TA_MRSP /* TA_SSP::Update_LRBG_then_SSP::new_profile_out */ new_profile_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Update_SP_per_LRBG_TA_Lib_internal /* 1 */ _2_Context_1;
  outC_MoveSPSectionsToNewLRBGafter_TA_Lib_internal /* 1 */ _1_Context_1;
  outC__17_Convert_P27_to_DistancePr_TA_SSP /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  SSP_cat_t_TA_MRSP /* TA_SSP::Update_LRBG_then_SSP::_L1 */ _L1;
  P027V1_OBU_T_TM_baseline2 /* TA_SSP::Update_LRBG_then_SSP::_L2 */ _L2;
  L_internal_Type_Obu_BasicTypes_Pkg /* TA_SSP::Update_LRBG_then_SSP::_L3 */ _L3;
  trainPosition_T_TrainPosition_Types_Pck /* TA_SSP::Update_LRBG_then_SSP::_L4 */ _L4;
  SSP_cat_t_TA_MRSP /* TA_SSP::Update_LRBG_then_SSP::_L8 */ _L8;
  L_internal_Type_Obu_BasicTypes_Pkg /* TA_SSP::Update_LRBG_then_SSP::_L7 */ _L7;
  L_internal_Type_Obu_BasicTypes_Pkg /* TA_SSP::Update_LRBG_then_SSP::_L6 */ _L6;
  kcg_int /* TA_SSP::Update_LRBG_then_SSP::_L5 */ _L5;
  SSP_cat_t_TA_MRSP /* TA_SSP::Update_LRBG_then_SSP::_L13 */ _L13;
  SSP_cat_t_TA_MRSP /* TA_SSP::Update_LRBG_then_SSP::_L9 */ _L9;
  V_internal_Type_Obu_BasicTypes_Pkg /* TA_SSP::Update_LRBG_then_SSP::_L10 */ _L10;
  SSP_section_t_TA_MRSP /* TA_SSP::Update_LRBG_then_SSP::_L11 */ _L11;
  SSP_section_t_TA_MRSP /* TA_SSP::Update_LRBG_then_SSP::_L12 */ _L12;
} outC_Update_LRBG_then_SSP_TA_SSP;

/* ===========  node initialization and cycle functions  =========== */
/* TA_SSP::Update_LRBG_then_SSP */
extern void Update_LRBG_then_SSP_TA_SSP(
  /* TA_SSP::Update_LRBG_then_SSP::SP_in */SSP_cat_t_TA_MRSP *SP_in,
  /* TA_SSP::Update_LRBG_then_SSP::P27V1_in */P027V1_OBU_T_TM_baseline2 *P27V1_in,
  /* TA_SSP::Update_LRBG_then_SSP::train_length_in */L_internal_Type_Obu_BasicTypes_Pkg train_length_in,
  /* TA_SSP::Update_LRBG_then_SSP::TrainPosition_in */trainPosition_T_TrainPosition_Types_Pck *TrainPosition_in,
  outC_Update_LRBG_then_SSP_TA_SSP *outC);

extern void Update_LRBG_then_SSP_reset_TA_SSP(
  outC_Update_LRBG_then_SSP_TA_SSP *outC);

#endif /* _Update_LRBG_then_SSP_TA_SSP_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Update_LRBG_then_SSP_TA_SSP.h
** Generation date: 2015-07-28T17:06:46
*************************************************************$ */

