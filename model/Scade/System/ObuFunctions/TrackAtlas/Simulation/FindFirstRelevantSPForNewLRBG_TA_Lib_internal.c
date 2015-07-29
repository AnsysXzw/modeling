/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-28T17:06:46
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "FindFirstRelevantSPForNewLRBG_TA_Lib_internal.h"

void FindFirstRelevantSPForNewLRBG_reset_TA_Lib_internal(
  outC_FindFirstRelevantSPForNewLRBG_TA_Lib_internal *outC)
{
  kcg_int i;
  
  for (i = 0; i < 33; i++) {
    /* 3 */
    FindFirstRelevantSPForNew_reset_TA_Lib_internal(&outC->Context_3[i]);
  }
}

/* TA_Lib_internal::FindFirstRelevantSPForNewLRBG */
void FindFirstRelevantSPForNewLRBG_TA_Lib_internal(
  /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG::Profile_in */SSP_cat_t_TA_MRSP *Profile_in,
  /* TA_Lib_internal::FindFirstRelevantSPForNewLRBG::Distance_2LRBGs */kcg_int Distance_2LRBGs,
  outC_FindFirstRelevantSPForNewLRBG_TA_Lib_internal *outC)
{
  kcg_int i2;
  kcg_int i1;
  kcg_int tmp;
  kcg_int i;
  kcg_int noname;
  
  outC->_L1 = Distance_2LRBGs;
  for (i2 = 0; i2 < 33; i2++) {
    outC->_L170[i2] = outC->_L1;
  }
  kcg_copy_SSP_cat_t_TA_MRSP(&outC->_L93, Profile_in);
  for (i1 = 0; i1 < 33; i1++) {
    kcg_copy_SSP_cat_t_TA_MRSP(&outC->_L169[i1], &outC->_L93);
  }
  outC->_L100 = 0;
  outC->_L96 = kcg_true;
  outC->_L168 = outC->_L100;
  if (outC->_L96) {
    for (i = 0; i < 33; i++) {
      tmp = outC->_L168;
      /* 3 */
      FindFirstRelevantSPForNew_TA_Lib_internal(
        i,
        tmp,
        &outC->_L169[i],
        outC->_L170[i],
        &outC->Context_3[i]);
      outC->_L168 = outC->Context_3[i].relevant_section;
      outC->_L94 = i + 1;
      if (!outC->Context_3[i].cont) {
        break;
      }
    }
  }
  else {
    outC->_L94 = 0;
  }
  noname = outC->_L94;
  outC->relevant_section = outC->_L168;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** FindFirstRelevantSPForNewLRBG_TA_Lib_internal.c
** Generation date: 2015-07-28T17:06:46
*************************************************************$ */

