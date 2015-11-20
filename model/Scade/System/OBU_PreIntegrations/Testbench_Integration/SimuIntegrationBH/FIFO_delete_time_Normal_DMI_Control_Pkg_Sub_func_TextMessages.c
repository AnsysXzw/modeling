/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "FIFO_delete_time_Normal_DMI_Control_Pkg_Sub_func_TextMessages.h"

#ifndef KCG_USER_DEFINED_INIT
void FIFO_delete_time_Normal_init_DMI_Control_Pkg_Sub_func_TextMessages(
  outC_FIFO_delete_time_Normal_DMI_Control_Pkg_Sub_func_TextMessages *outC)
{
  static kcg_int i1;
  static kcg_int i;
  
  outC->init = kcg_true;
  for (i = 0; i < 10; i++) {
    outC->new_hh_array[i] = 0.0;
  }
  for (i1 = 0; i1 < 10; i1++) {
    outC->new_mm_array[i1] = 0.0;
  }
}
#endif /* KCG_USER_DEFINED_INIT */


void FIFO_delete_time_Normal_reset_DMI_Control_Pkg_Sub_func_TextMessages(
  outC_FIFO_delete_time_Normal_DMI_Control_Pkg_Sub_func_TextMessages *outC)
{
  outC->init = kcg_true;
}

/* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal */
void FIFO_delete_time_Normal_DMI_Control_Pkg_Sub_func_TextMessages(
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::hh_array */ array_real_10 *hh_array,
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::mm_array */ array_real_10 *mm_array,
  outC_FIFO_delete_time_Normal_DMI_Control_Pkg_Sub_func_TextMessages *outC)
{
  static kcg_int i6;
  static kcg_int i5;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal */
  static array_real_10 acc4;
  static kcg_int i3;
  static kcg_int i2;
  static kcg_int i1;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal */
  static array_real_10 acc;
  static kcg_int i;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::new_hh_array */
  static array_real_10 last_new_hh_array;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::new_mm_array */
  static array_real_10 last_new_mm_array;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L10 */
  static array_real_10 _L10;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L4 */
  static array_int_10 _L4;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L1 */
  static array_real_10 _L1;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L13 */
  static kcg_int _L13;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L15 */
  static array_real_10 _L15;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L17 */
  static array_real_10 _L17;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L22 */
  static kcg_int _L22;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L21 */
  static array_real_10 _L21;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L20 */
  static array_real_10 _L20;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L19 */
  static array_int_10 _L19;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L24 */
  static array_real_10_10 _L24;
  /* DMI_Control_Pkg::Sub_func::TextMessages::FIFO_delete_time_Normal::_L28 */
  static array_real_10_10 _L28;
  
  kcg_copy_array_real_10(&_L1, hh_array);
  _L13 = 0;
  /* pow */ for (i6 = 0; i6 < 10; i6++) {
    _L4[i6] = _L13;
  }
  kcg_copy_array_real_10(
    &_L17,
    (array_real_10 *) &cArray_hh_leer_DMI_Control_Pkg);
  /* pow */ for (i5 = 0; i5 < 10; i5++) {
    kcg_copy_array_real_10(&_L24[i5], &_L1);
  }
  kcg_copy_array_real_10(&_L15, &_L17);
  /* 1 */ for (i3 = 0; i3 < 10; i3++) {
    kcg_copy_array_real_10(&acc4, &_L15);
    /* 1 */
    deleteTime_iterator_normal_DMI_Control_Pkg_Sub_func_TextMessages(
      i3,
      &acc4,
      _L4[i3],
      &_L24[i3],
      &_L15);
  }
  kcg_copy_array_real_10(&_L10, mm_array);
  /* last_init_ck_new_mm_array */ if (outC->init) {
    kcg_copy_array_real_10(
      &last_new_mm_array,
      (array_real_10 *) &cArray_mm_leer_DMI_Control_Pkg);
  }
  else {
    kcg_copy_array_real_10(&last_new_mm_array, &outC->new_mm_array);
  }
  kcg_copy_array_real_10(
    &_L21,
    (array_real_10 *) &cArray_hh_leer_DMI_Control_Pkg);
  _L22 = 0;
  /* pow */ for (i2 = 0; i2 < 10; i2++) {
    _L19[i2] = _L22;
  }
  /* pow */ for (i1 = 0; i1 < 10; i1++) {
    kcg_copy_array_real_10(&_L28[i1], &_L10);
  }
  kcg_copy_array_real_10(&_L20, &_L21);
  /* 2 */ for (i = 0; i < 10; i++) {
    kcg_copy_array_real_10(&acc, &_L20);
    /* 2 */
    deleteTime_iterator_normal_DMI_Control_Pkg_Sub_func_TextMessages(
      i,
      &acc,
      _L19[i],
      &_L28[i],
      &_L20);
  }
  kcg_copy_array_real_10(&outC->new_mm_array, &_L20);
  /* last_init_ck_new_hh_array */ if (outC->init) {
    kcg_copy_array_real_10(
      &last_new_hh_array,
      (array_real_10 *) &cArray_hh_leer_DMI_Control_Pkg);
  }
  else {
    kcg_copy_array_real_10(&last_new_hh_array, &outC->new_hh_array);
  }
  kcg_copy_array_real_10(&outC->new_hh_array, &_L15);
  outC->init = kcg_false;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** FIFO_delete_time_Normal_DMI_Control_Pkg_Sub_func_TextMessages.c
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

