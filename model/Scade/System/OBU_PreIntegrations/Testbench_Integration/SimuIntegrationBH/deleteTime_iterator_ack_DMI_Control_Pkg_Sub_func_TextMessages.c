/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "deleteTime_iterator_ack_DMI_Control_Pkg_Sub_func_TextMessages.h"

/* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack */
void deleteTime_iterator_ack_DMI_Control_Pkg_Sub_func_TextMessages(
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::index */ kcg_int index,
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::acc */ array_real_5 *acc,
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::Position */ kcg_int Position,
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::time_array */ array_real_5 *time_array,
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::time */ array_real_5 *time)
{
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L1 */
  static kcg_int _L1;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L2 */
  static kcg_int _L2;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L4 */
  static kcg_bool _L4;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L6 */
  static array_real_5 _L6;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L19 */
  static array_real_5 _L19;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L20 */
  static kcg_real _L20;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L21 */
  static array_real_5 _L21;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L22 */
  static array_real_5 _L22;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L23 */
  static kcg_int _L23;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L24 */
  static array_real_5 _L24;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L25 */
  static kcg_int _L25;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L26 */
  static kcg_real _L26;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L27 */
  static kcg_int _L27;
  /* DMI_Control_Pkg::Sub_func::TextMessages::deleteTime_iterator_ack::_L28 */
  static kcg_int _L28;
  
  _L1 = index;
  _L2 = Position;
  _L4 = _L1 < _L2;
  kcg_copy_array_real_5(&_L19, acc);
  kcg_copy_array_real_5(&_L22, acc);
  kcg_copy_array_real_5(&_L24, time_array);
  _L26 = - 1.0;
  _L25 = index;
  _L28 = 1;
  _L27 = _L25 + _L28;
  if ((0 <= _L27) & (_L27 < 5)) {
    _L20 = _L24[_L27];
  }
  else {
    _L20 = _L26;
  }
  _L23 = index;
  kcg_copy_array_real_5(&_L21, &_L22);
  if ((0 <= _L23) & (_L23 < 5)) {
    _L21[_L23] = _L20;
  }
  /* 1 */ if (_L4) {
    kcg_copy_array_real_5(&_L6, &_L19);
  }
  else {
    kcg_copy_array_real_5(&_L6, &_L21);
  }
  kcg_copy_array_real_5(time, &_L6);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** deleteTime_iterator_ack_DMI_Control_Pkg_Sub_func_TextMessages.c
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

