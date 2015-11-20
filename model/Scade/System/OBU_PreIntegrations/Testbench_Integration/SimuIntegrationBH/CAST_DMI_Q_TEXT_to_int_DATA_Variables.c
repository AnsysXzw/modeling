/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CAST_DMI_Q_TEXT_to_int_DATA_Variables.h"

/* DATA::Variables::CAST_DMI_Q_TEXT_to_int */
kcg_int CAST_DMI_Q_TEXT_to_int_DATA_Variables(
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_ct */ DMI_Q_TEXT_DMI_Types_Pkg q_text_ct)
{
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error2;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _1_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::then::_L3 */
  static kcg_bool _L3_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::then::_L1 */
  static kcg_int _L1_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else */
  static kcg_bool _131_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error10;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _9_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::then::_L2 */
  static kcg_bool _L2133_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::then::_L1 */
  static kcg_int _L1134_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error8;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _7_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else */
  static kcg_bool _129_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error18;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _17_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::then::_L2 */
  static kcg_bool _L2137_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::then::_L1 */
  static kcg_int _L1138_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error16;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _15_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else */
  static kcg_bool _127_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error26;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _25_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2141_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1142_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error24;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _23_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else */
  static kcg_bool _125_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error34;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _33_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2145_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1146_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error32;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _31_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else */
  static kcg_bool _123_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error42;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _41_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2149_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1150_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error40;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _39_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _121_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error50;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _49_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2153_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1154_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error48;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _47_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _119_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error58;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _57_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L3 */
  static kcg_bool _L3157_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1158_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error56;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _55_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _117_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error66;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _65_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2161_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1162_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error64;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _63_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _115_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error74;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _73_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2165_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1166_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error72;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _71_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _113_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error82;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _81_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2169_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1170_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error80;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _79_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _111_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error90;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _89_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2173_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1174_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error88;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _87_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _109_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error98;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _97_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2177_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1178_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error96;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _95_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _107_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error106;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _105_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2181_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1182_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error104;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _103_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::_L2 */
  static kcg_bool _L2183_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::_L1 */
  static kcg_int _L1184_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _99_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error100;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1180_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2179_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _101_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error102;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _108_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _91_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error92;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1176_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2175_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _93_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error94;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _110_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _83_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error84;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1172_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2171_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _85_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error86;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _112_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _75_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error76;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1168_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2167_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _77_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error78;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _114_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _67_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error68;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1164_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2163_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _69_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error70;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _116_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _59_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error60;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1160_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2159_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _61_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error62;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _118_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _51_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error52;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1156_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2155_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _53_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error54;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _120_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _43_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error44;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1152_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else::else::then::_L3 */
  static kcg_bool _L3151_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _45_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error46;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::else */
  static kcg_bool _122_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _35_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error36;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1148_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2147_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _37_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error38;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::else */
  static kcg_bool _124_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _27_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error28;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L1144_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2143_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _29_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error30;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::else */
  static kcg_bool _126_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _19_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error20;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::then::_L1 */
  static kcg_int _L1140_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else::else::then::_L2 */
  static kcg_bool _L2139_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _21_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error22;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::else */
  static kcg_bool _128_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _11_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error12;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::then::_L1 */
  static kcg_int _L1136_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else::else::then::_L2 */
  static kcg_bool _L2135_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _13_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error14;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::else */
  static kcg_bool _130_else_clock_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _3_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error4;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::then::_L1 */
  static kcg_int _L1132_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1::else::then::_L2 */
  static kcg_bool _L2_IfBlock1;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _5_q_text_int;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error6;
  static kcg_bool noname;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::IfBlock1 */
  static kcg_bool IfBlock1_clock;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::error */
  static kcg_bool error185;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::_L60 */
  static kcg_bool _L60;
  /* DATA::Variables::CAST_DMI_Q_TEXT_to_int::q_text_int */
  static kcg_int _186_q_text_int;
  
  IfBlock1_clock = q_text_ct == ENUM_DMI_Q_TEXT_acknowledgment;
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    _L1_IfBlock1 = INT_DMI_Q_TEXT_acknowledgment;
    _1_q_text_int = _L1_IfBlock1;
    _186_q_text_int = _1_q_text_int;
    _L3_IfBlock1 = kcg_false;
    error2 = _L3_IfBlock1;
    error185 = error2;
  }
  else {
    _131_else_clock_IfBlock1 = q_text_ct == ENUM_DMI_Q_TEXT_balise_read_error;
    /* ck_anon_activ */ if (_131_else_clock_IfBlock1) {
      _L1132_IfBlock1 = INT_DMI_Q_TEXT_balise_read_error;
      _5_q_text_int = _L1132_IfBlock1;
      q_text_int = _5_q_text_int;
    }
    else {
      _130_else_clock_IfBlock1 = q_text_ct ==
        ENUM_DMI_Q_TEXT_communication_error;
      /* ck_anon_activ */ if (_130_else_clock_IfBlock1) {
        _L1134_IfBlock1 = INT_DMI_Q_TEXT_communication_error;
        _9_q_text_int = _L1134_IfBlock1;
        _3_q_text_int = _9_q_text_int;
      }
      else {
        _129_else_clock_IfBlock1 = q_text_ct == ENUM_DMI_Q_TEXT_emergency_stop;
        /* ck_anon_activ */ if (_129_else_clock_IfBlock1) {
          _L1136_IfBlock1 = INT_DMI_Q_TEXT_emergency_stop;
          _13_q_text_int = _L1136_IfBlock1;
          _7_q_text_int = _13_q_text_int;
        }
        else {
          _128_else_clock_IfBlock1 = q_text_ct == ENUM_DMI_Q_TEXT_entering_FS;
          /* ck_anon_activ */ if (_128_else_clock_IfBlock1) {
            _L1138_IfBlock1 = INT_DMI_Q_TEXT_entering_FS;
            _17_q_text_int = _L1138_IfBlock1;
            _11_q_text_int = _17_q_text_int;
          }
          else {
            _127_else_clock_IfBlock1 = q_text_ct == ENUM_DMI_Q_TEXT_entering_OS;
            /* ck_anon_activ */ if (_127_else_clock_IfBlock1) {
              _L1140_IfBlock1 = INT_DMI_Q_TEXT_entering_OS;
              _21_q_text_int = _L1140_IfBlock1;
              _15_q_text_int = _21_q_text_int;
            }
            else {
              _126_else_clock_IfBlock1 = q_text_ct ==
                ENUM_DMI_Q_TEXT_level_crossing_not_protected;
              /* ck_anon_activ */ if (_126_else_clock_IfBlock1) {
                _L1142_IfBlock1 = INT_DMI_Q_TEXT_level_crossing_not_protected;
                _25_q_text_int = _L1142_IfBlock1;
                _19_q_text_int = _25_q_text_int;
              }
              else {
                _125_else_clock_IfBlock1 = q_text_ct ==
                  ENUM_DMI_Q_TEXT_no_MA_received_at_level_transition;
                /* ck_anon_activ */ if (_125_else_clock_IfBlock1) {
                  _L1144_IfBlock1 =
                    INT_DMI_Q_TEXT_no_MA_received_at_level_transition;
                  _29_q_text_int = _L1144_IfBlock1;
                  _23_q_text_int = _29_q_text_int;
                }
                else {
                  _124_else_clock_IfBlock1 = q_text_ct ==
                    ENUM_DMI_Q_TEXT_no_track_condition_will_be_received;
                  /* ck_anon_activ */ if (_124_else_clock_IfBlock1) {
                    _L1146_IfBlock1 =
                      INT_DMI_Q_TEXT_no_track_condition_will_be_received;
                    _33_q_text_int = _L1146_IfBlock1;
                    _27_q_text_int = _33_q_text_int;
                  }
                  else {
                    _123_else_clock_IfBlock1 = q_text_ct ==
                      ENUM_DMI_Q_TEXT_no_track_description;
                    /* ck_anon_activ */ if (_123_else_clock_IfBlock1) {
                      _L1148_IfBlock1 = INT_DMI_Q_TEXT_no_track_description;
                      _37_q_text_int = _L1148_IfBlock1;
                      _31_q_text_int = _37_q_text_int;
                    }
                    else {
                      _122_else_clock_IfBlock1 = q_text_ct ==
                        ENUM_DMI_Q_TEXT_radio_network_registration_failed;
                      /* ck_anon_activ */ if (_122_else_clock_IfBlock1) {
                        _L1150_IfBlock1 =
                          INT_DMI_Q_TEXT_radio_network_registration_failed;
                        _41_q_text_int = _L1150_IfBlock1;
                        _35_q_text_int = _41_q_text_int;
                      }
                      else {
                        _121_else_clock_IfBlock1 = q_text_ct ==
                          ENUM_DMI_Q_TEXT_route_unsuitable_axle_load_category;
                        /* ck_anon_activ */ if (_121_else_clock_IfBlock1) {
                          _L1152_IfBlock1 =
                            INT_DMI_Q_TEXT_route_unsuitable_axle_load_category;
                          _45_q_text_int = _L1152_IfBlock1;
                          _39_q_text_int = _45_q_text_int;
                        }
                        else {
                          _120_else_clock_IfBlock1 = q_text_ct ==
                            ENUM_DMI_Q_TEXT_route_unsuitable_loading_gauge;
                          /* ck_anon_activ */ if (_120_else_clock_IfBlock1) {
                            _L1154_IfBlock1 =
                              INT_DMI_Q_TEXT_route_unsuitable_loading_gauge;
                            _49_q_text_int = _L1154_IfBlock1;
                            _43_q_text_int = _49_q_text_int;
                          }
                          else {
                            _119_else_clock_IfBlock1 = q_text_ct ==
                              ENUM_DMI_Q_TEXT_route_unsuitable_traction_system;
                            /* ck_anon_activ */ if (_119_else_clock_IfBlock1) {
                              _L1156_IfBlock1 =
                                INT_DMI_Q_TEXT_route_unsuitable_traction_system;
                              _53_q_text_int = _L1156_IfBlock1;
                              _47_q_text_int = _53_q_text_int;
                            }
                            else {
                              _118_else_clock_IfBlock1 = q_text_ct ==
                                ENUM_DMI_Q_TEXT_runaway_movement;
                              /* ck_anon_activ */ if (_118_else_clock_IfBlock1) {
                                _L1158_IfBlock1 =
                                  INT_DMI_Q_TEXT_runaway_movement;
                                _57_q_text_int = _L1158_IfBlock1;
                                _51_q_text_int = _57_q_text_int;
                              }
                              else {
                                _117_else_clock_IfBlock1 = q_text_ct ==
                                  ENUM_DMI_Q_TEXT_RV_distance_esceeded;
                                /* ck_anon_activ */ if (_117_else_clock_IfBlock1) {
                                  _L1160_IfBlock1 =
                                    INT_DMI_Q_TEXT_RV_distance_esceeded;
                                  _61_q_text_int = _L1160_IfBlock1;
                                  _55_q_text_int = _61_q_text_int;
                                }
                                else {
                                  _116_else_clock_IfBlock1 = q_text_ct ==
                                    ENUM_DMI_Q_TEXT_SH_refused;
                                  /* ck_anon_activ */ if (_116_else_clock_IfBlock1) {
                                    _L1162_IfBlock1 = INT_DMI_Q_TEXT_SH_refused;
                                    _65_q_text_int = _L1162_IfBlock1;
                                    _59_q_text_int = _65_q_text_int;
                                  }
                                  else {
                                    _115_else_clock_IfBlock1 = q_text_ct ==
                                      ENUM_DMI_Q_TEXT_SH_request_failed;
                                    /* ck_anon_activ */ if (_115_else_clock_IfBlock1) {
                                      _L1164_IfBlock1 =
                                        INT_DMI_Q_TEXT_SH_request_failed;
                                      _69_q_text_int = _L1164_IfBlock1;
                                      _63_q_text_int = _69_q_text_int;
                                    }
                                    else {
                                      _114_else_clock_IfBlock1 = q_text_ct ==
                                        ENUM_DMI_Q_TEXT_SH_stop_order;
                                      /* ck_anon_activ */ if (_114_else_clock_IfBlock1) {
                                        _L1166_IfBlock1 =
                                          INT_DMI_Q_TEXT_SH_stop_order;
                                        _73_q_text_int = _L1166_IfBlock1;
                                        _67_q_text_int = _73_q_text_int;
                                      }
                                      else {
                                        _113_else_clock_IfBlock1 = q_text_ct ==
                                          ENUM_DMI_Q_TEXT_SR_distance_exceeded;
                                        /* ck_anon_activ */ if (_113_else_clock_IfBlock1) {
                                          _L1168_IfBlock1 =
                                            INT_DMI_Q_TEXT_SR_distance_exceeded;
                                          _77_q_text_int = _L1168_IfBlock1;
                                          _71_q_text_int = _77_q_text_int;
                                        }
                                        else {
                                          _112_else_clock_IfBlock1 =
                                            q_text_ct ==
                                            ENUM_DMI_Q_TEXT_SR_stop_order;
                                          /* ck_anon_activ */ if (_112_else_clock_IfBlock1) {
                                            _L1170_IfBlock1 =
                                              INT_DMI_Q_TEXT_SR_stop_order;
                                            _81_q_text_int = _L1170_IfBlock1;
                                            _75_q_text_int = _81_q_text_int;
                                          }
                                          else {
                                            _111_else_clock_IfBlock1 =
                                              q_text_ct ==
                                              ENUM_DMI_Q_TEXT_STM_brake_Deman;
                                            /* ck_anon_activ */ if (_111_else_clock_IfBlock1) {
                                              _L1172_IfBlock1 =
                                                INT_DMI_Q_TEXT_STM_brake_Deman;
                                              _85_q_text_int = _L1172_IfBlock1;
                                              _79_q_text_int = _85_q_text_int;
                                            }
                                            else {
                                              _110_else_clock_IfBlock1 =
                                                q_text_ct ==
                                                ENUM_DMI_Q_TEXT_trackside_malfunction;
                                              /* ck_anon_activ */ if (_110_else_clock_IfBlock1) {
                                                _L1174_IfBlock1 =
                                                  INT_DMI_Q_TEXT_trackside_malfunction;
                                                _89_q_text_int =
                                                  _L1174_IfBlock1;
                                                _83_q_text_int = _89_q_text_int;
                                              }
                                              else {
                                                _109_else_clock_IfBlock1 =
                                                  q_text_ct ==
                                                  ENUM_DMI_Q_TEXT_trackside_not_compatible;
                                                /* ck_anon_activ */ if (_109_else_clock_IfBlock1) {
                                                  _L1176_IfBlock1 =
                                                    INT_DMI_Q_TEXT_trackside_not_compatible;
                                                  _93_q_text_int =
                                                    _L1176_IfBlock1;
                                                  _87_q_text_int =
                                                    _93_q_text_int;
                                                }
                                                else {
                                                  _108_else_clock_IfBlock1 =
                                                    q_text_ct ==
                                                    ENUM_DMI_Q_TEXT_train_data_changed;
                                                  /* ck_anon_activ */ if (_108_else_clock_IfBlock1) {
                                                    _L1178_IfBlock1 =
                                                      INT_DMI_Q_TEXT_train_data_changed;
                                                    _97_q_text_int =
                                                      _L1178_IfBlock1;
                                                    _91_q_text_int =
                                                      _97_q_text_int;
                                                  }
                                                  else {
                                                    _107_else_clock_IfBlock1 =
                                                      q_text_ct ==
                                                      ENUM_DMI_Q_TEXT_train_is_rejected;
                                                    /* ck_anon_activ */ if (_107_else_clock_IfBlock1) {
                                                      _L1180_IfBlock1 =
                                                        INT_DMI_Q_TEXT_train_is_rejected;
                                                      _101_q_text_int =
                                                        _L1180_IfBlock1;
                                                      _95_q_text_int =
                                                        _101_q_text_int;
                                                    }
                                                    else {
                                                      else_clock_IfBlock1 =
                                                        q_text_ct ==
                                                        ENUM_DMI_Q_TEXT_unauthorized_passing_of_EOA_LOA;
                                                      /* ck_anon_activ */ if (else_clock_IfBlock1) {
                                                        _L1182_IfBlock1 =
                                                          INT_DMI_Q_TEXT_unauthorized_passing_of_EOA_LOA;
                                                        _105_q_text_int =
                                                          _L1182_IfBlock1;
                                                        _99_q_text_int =
                                                          _105_q_text_int;
                                                      }
                                                      else {
                                                        _L1184_IfBlock1 =
                                                          INT_DMI_Q_TEXT_unauthorized_passing_of_EOA_LOA;
                                                        _103_q_text_int =
                                                          _L1184_IfBlock1;
                                                        _99_q_text_int =
                                                          _103_q_text_int;
                                                      }
                                                      _95_q_text_int =
                                                        _99_q_text_int;
                                                    }
                                                    _91_q_text_int =
                                                      _95_q_text_int;
                                                  }
                                                  _87_q_text_int =
                                                    _91_q_text_int;
                                                }
                                                _83_q_text_int = _87_q_text_int;
                                              }
                                              _79_q_text_int = _83_q_text_int;
                                            }
                                            _75_q_text_int = _79_q_text_int;
                                          }
                                          _71_q_text_int = _75_q_text_int;
                                        }
                                        _67_q_text_int = _71_q_text_int;
                                      }
                                      _63_q_text_int = _67_q_text_int;
                                    }
                                    _59_q_text_int = _63_q_text_int;
                                  }
                                  _55_q_text_int = _59_q_text_int;
                                }
                                _51_q_text_int = _55_q_text_int;
                              }
                              _47_q_text_int = _51_q_text_int;
                            }
                            _43_q_text_int = _47_q_text_int;
                          }
                          _39_q_text_int = _43_q_text_int;
                        }
                        _35_q_text_int = _39_q_text_int;
                      }
                      _31_q_text_int = _35_q_text_int;
                    }
                    _27_q_text_int = _31_q_text_int;
                  }
                  _23_q_text_int = _27_q_text_int;
                }
                _19_q_text_int = _23_q_text_int;
              }
              _15_q_text_int = _19_q_text_int;
            }
            _11_q_text_int = _15_q_text_int;
          }
          _7_q_text_int = _11_q_text_int;
        }
        _3_q_text_int = _7_q_text_int;
      }
      q_text_int = _3_q_text_int;
    }
    _186_q_text_int = q_text_int;
    /* ck_anon_activ */ if (_131_else_clock_IfBlock1) {
      _L2_IfBlock1 = kcg_false;
      error6 = _L2_IfBlock1;
      error = error6;
    }
    else {
      /* ck_anon_activ */ if (_130_else_clock_IfBlock1) {
        _L2133_IfBlock1 = kcg_false;
        error10 = _L2133_IfBlock1;
        error4 = error10;
      }
      else {
        /* ck_anon_activ */ if (_129_else_clock_IfBlock1) {
          _L2135_IfBlock1 = kcg_false;
          error14 = _L2135_IfBlock1;
          error8 = error14;
        }
        else {
          /* ck_anon_activ */ if (_128_else_clock_IfBlock1) {
            _L2137_IfBlock1 = kcg_false;
            error18 = _L2137_IfBlock1;
            error12 = error18;
          }
          else {
            /* ck_anon_activ */ if (_127_else_clock_IfBlock1) {
              _L2139_IfBlock1 = kcg_false;
              error22 = _L2139_IfBlock1;
              error16 = error22;
            }
            else {
              /* ck_anon_activ */ if (_126_else_clock_IfBlock1) {
                _L2141_IfBlock1 = kcg_false;
                error26 = _L2141_IfBlock1;
                error20 = error26;
              }
              else {
                /* ck_anon_activ */ if (_125_else_clock_IfBlock1) {
                  _L2143_IfBlock1 = kcg_false;
                  error30 = _L2143_IfBlock1;
                  error24 = error30;
                }
                else {
                  /* ck_anon_activ */ if (_124_else_clock_IfBlock1) {
                    _L2145_IfBlock1 = kcg_false;
                    error34 = _L2145_IfBlock1;
                    error28 = error34;
                  }
                  else {
                    /* ck_anon_activ */ if (_123_else_clock_IfBlock1) {
                      _L2147_IfBlock1 = kcg_false;
                      error38 = _L2147_IfBlock1;
                      error32 = error38;
                    }
                    else {
                      /* ck_anon_activ */ if (_122_else_clock_IfBlock1) {
                        _L2149_IfBlock1 = kcg_false;
                        error42 = _L2149_IfBlock1;
                        error36 = error42;
                      }
                      else {
                        /* ck_anon_activ */ if (_121_else_clock_IfBlock1) {
                          _L3151_IfBlock1 = kcg_false;
                          error46 = _L3151_IfBlock1;
                          error40 = error46;
                        }
                        else {
                          /* ck_anon_activ */ if (_120_else_clock_IfBlock1) {
                            _L2153_IfBlock1 = kcg_false;
                            error50 = _L2153_IfBlock1;
                            error44 = error50;
                          }
                          else {
                            /* ck_anon_activ */ if (_119_else_clock_IfBlock1) {
                              _L2155_IfBlock1 = kcg_false;
                              error54 = _L2155_IfBlock1;
                              error48 = error54;
                            }
                            else {
                              /* ck_anon_activ */ if (_118_else_clock_IfBlock1) {
                                _L3157_IfBlock1 = kcg_false;
                                error58 = _L3157_IfBlock1;
                                error52 = error58;
                              }
                              else {
                                /* ck_anon_activ */ if (_117_else_clock_IfBlock1) {
                                  _L2159_IfBlock1 = kcg_false;
                                  error62 = _L2159_IfBlock1;
                                  error56 = error62;
                                }
                                else {
                                  /* ck_anon_activ */ if (_116_else_clock_IfBlock1) {
                                    _L2161_IfBlock1 = kcg_false;
                                    error66 = _L2161_IfBlock1;
                                    error60 = error66;
                                  }
                                  else {
                                    /* ck_anon_activ */ if (_115_else_clock_IfBlock1) {
                                      _L2163_IfBlock1 = kcg_false;
                                      error70 = _L2163_IfBlock1;
                                      error64 = error70;
                                    }
                                    else {
                                      /* ck_anon_activ */ if (_114_else_clock_IfBlock1) {
                                        _L2165_IfBlock1 = kcg_false;
                                        error74 = _L2165_IfBlock1;
                                        error68 = error74;
                                      }
                                      else {
                                        /* ck_anon_activ */ if (_113_else_clock_IfBlock1) {
                                          _L2167_IfBlock1 = kcg_false;
                                          error78 = _L2167_IfBlock1;
                                          error72 = error78;
                                        }
                                        else {
                                          /* ck_anon_activ */ if (_112_else_clock_IfBlock1) {
                                            _L2169_IfBlock1 = kcg_false;
                                            error82 = _L2169_IfBlock1;
                                            error76 = error82;
                                          }
                                          else {
                                            /* ck_anon_activ */ if (_111_else_clock_IfBlock1) {
                                              _L2171_IfBlock1 = kcg_false;
                                              error86 = _L2171_IfBlock1;
                                              error80 = error86;
                                            }
                                            else {
                                              /* ck_anon_activ */ if (_110_else_clock_IfBlock1) {
                                                _L2173_IfBlock1 = kcg_false;
                                                error90 = _L2173_IfBlock1;
                                                error84 = error90;
                                              }
                                              else {
                                                /* ck_anon_activ */ if (_109_else_clock_IfBlock1) {
                                                  _L2175_IfBlock1 = kcg_false;
                                                  error94 = _L2175_IfBlock1;
                                                  error88 = error94;
                                                }
                                                else {
                                                  /* ck_anon_activ */ if (_108_else_clock_IfBlock1) {
                                                    _L2177_IfBlock1 = kcg_false;
                                                    error98 = _L2177_IfBlock1;
                                                    error92 = error98;
                                                  }
                                                  else {
                                                    /* ck_anon_activ */ if (_107_else_clock_IfBlock1) {
                                                      _L2179_IfBlock1 =
                                                        kcg_false;
                                                      error102 =
                                                        _L2179_IfBlock1;
                                                      error96 = error102;
                                                    }
                                                    else {
                                                      /* ck_anon_activ */ if (else_clock_IfBlock1) {
                                                        _L2181_IfBlock1 =
                                                          kcg_false;
                                                        error106 =
                                                          _L2181_IfBlock1;
                                                        error100 = error106;
                                                      }
                                                      else {
                                                        _L2183_IfBlock1 =
                                                          kcg_true;
                                                        error104 =
                                                          _L2183_IfBlock1;
                                                        error100 = error104;
                                                      }
                                                      error96 = error100;
                                                    }
                                                    error92 = error96;
                                                  }
                                                  error88 = error92;
                                                }
                                                error84 = error88;
                                              }
                                              error80 = error84;
                                            }
                                            error76 = error80;
                                          }
                                          error72 = error76;
                                        }
                                        error68 = error72;
                                      }
                                      error64 = error68;
                                    }
                                    error60 = error64;
                                  }
                                  error56 = error60;
                                }
                                error52 = error56;
                              }
                              error48 = error52;
                            }
                            error44 = error48;
                          }
                          error40 = error44;
                        }
                        error36 = error40;
                      }
                      error32 = error36;
                    }
                    error28 = error32;
                  }
                  error24 = error28;
                }
                error20 = error24;
              }
              error16 = error20;
            }
            error12 = error16;
          }
          error8 = error12;
        }
        error4 = error8;
      }
      error = error4;
    }
    error185 = error;
  }
  _L60 = error185;
  noname = _L60;
  return _186_q_text_int;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** CAST_DMI_Q_TEXT_to_int_DATA_Variables.c
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

