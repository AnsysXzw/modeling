/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-07-28T17:06:46
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Update_SP_per_LRBG_loop_TA_Lib_internal.h"

void Update_SP_per_LRBG_loop_reset_TA_Lib_internal(
  outC_Update_SP_per_LRBG_loop_TA_Lib_internal *outC)
{
}

/* TA_Lib_internal::Update_SP_per_LRBG_loop */
void Update_SP_per_LRBG_loop_TA_Lib_internal(
  /* TA_Lib_internal::Update_SP_per_LRBG_loop::i */kcg_int i,
  /* TA_Lib_internal::Update_SP_per_LRBG_loop::SP */SSP_cat_t_TA_MRSP *SP,
  /* TA_Lib_internal::Update_SP_per_LRBG_loop::First_Section_To_Replace */kcg_int First_Section_To_Replace,
  /* TA_Lib_internal::Update_SP_per_LRBG_loop::new_SSP_received */SSP_cat_t_TA_MRSP *new_SSP_received,
  outC_Update_SP_per_LRBG_loop_TA_Lib_internal *outC)
{
  kcg_copy_SSP_cat_t_TA_MRSP(&outC->_L20, SP);
  kcg_copy_SSP_cat_t_TA_MRSP(&outC->_L6, new_SSP_received);
  outC->_L11 = i;
  if ((0 <= outC->_L11) & (outC->_L11 < 33)) {
    kcg_copy_SSP_section_t_TA_MRSP(&outC->_L15, &outC->_L6[outC->_L11]);
  }
  else {
    kcg_copy_SSP_section_t_TA_MRSP(
      &outC->_L15,
      (SSP_section_t_TA_MRSP *) &DEFAULT_SSP_section_TA_MRSP);
  }
  outC->_L5 = i;
  outC->_L4 = First_Section_To_Replace;
  outC->_L7 = outC->_L5 + outC->_L4;
  kcg_copy_SSP_cat_t_TA_MRSP(&outC->_L19, &outC->_L20);
  if ((0 <= outC->_L7) & (outC->_L7 < 33)) {
    kcg_copy_SSP_section_t_TA_MRSP(&outC->_L19[outC->_L7], &outC->_L15);
  }
  kcg_copy_SSP_cat_t_TA_MRSP(&outC->SpeedProfile_out, &outC->_L19);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Update_SP_per_LRBG_loop_TA_Lib_internal.c
** Generation date: 2015-07-28T17:06:46
*************************************************************$ */

