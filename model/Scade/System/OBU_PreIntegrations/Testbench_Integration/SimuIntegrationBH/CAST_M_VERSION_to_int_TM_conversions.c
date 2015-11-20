/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CAST_M_VERSION_to_int_TM_conversions.h"

/* TM_conversions::CAST_M_VERSION_to_int */
kcg_int CAST_M_VERSION_to_int_TM_conversions(
  /* TM_conversions::CAST_M_VERSION_to_int::m_version */ M_VERSION m_version)
{
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error2;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _1_m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::then::_L5 */
  static kcg_bool _L5_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::then::_L4 */
  static kcg_int _L4_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else */
  static kcg_bool _16_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error10;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _9_m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else::then::_L4 */
  static kcg_bool _L418_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else::then::_L2 */
  static kcg_int _L2_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error8;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _7_m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else::else */
  static kcg_bool else_clock_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else::else::else::_L2 */
  static kcg_int _L221_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else::else::else::_L1 */
  static kcg_bool _L1_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _11_m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error12;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else::else::then::_L2 */
  static kcg_int _L220_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else::else::then::_L4 */
  static kcg_bool _L419_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _13_m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error14;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::else */
  static kcg_bool _15_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _3_m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error4;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::then::_L3 */
  static kcg_int _L3_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1::else::then::_L5 */
  static kcg_bool _L517_IfBlock1;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _5_m_version_int;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error6;
  static kcg_bool noname;
  /* TM_conversions::CAST_M_VERSION_to_int::IfBlock1 */
  static kcg_bool IfBlock1_clock;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_in */
  static M_VERSION m_version_in;
  /* TM_conversions::CAST_M_VERSION_to_int::error */
  static kcg_bool error22;
  /* TM_conversions::CAST_M_VERSION_to_int::_L4 */
  static M_VERSION _L4;
  /* TM_conversions::CAST_M_VERSION_to_int::_L5 */
  static kcg_bool _L5;
  /* TM_conversions::CAST_M_VERSION_to_int::m_version_int */
  static kcg_int _23_m_version_int;
  
  _L4 = m_version;
  m_version_in = _L4;
  IfBlock1_clock = m_version_in ==
    ENUM_M_VERSION_Previous_versions_TM_conversions;
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    _L4_IfBlock1 = INT_M_VERSION_previous_M_TM_conversions;
    _1_m_version_int = _L4_IfBlock1;
    _23_m_version_int = _1_m_version_int;
    _L5_IfBlock1 = kcg_false;
    error2 = _L5_IfBlock1;
    error22 = error2;
  }
  else {
    _16_else_clock_IfBlock1 = m_version_in ==
      ENUM_M_VERSION_Version_1_0_TM_conversions;
    /* ck_anon_activ */ if (_16_else_clock_IfBlock1) {
      _L3_IfBlock1 = INT_M_VERSION_1_0_TM_conversions;
      _5_m_version_int = _L3_IfBlock1;
      m_version_int = _5_m_version_int;
    }
    else {
      _15_else_clock_IfBlock1 = m_version_in ==
        ENUM_M_VERSION_Version_1_1_TM_conversions;
      /* ck_anon_activ */ if (_15_else_clock_IfBlock1) {
        _L2_IfBlock1 = INT_M_VERSION_1_1_TM_conversions;
        _9_m_version_int = _L2_IfBlock1;
        _3_m_version_int = _9_m_version_int;
      }
      else {
        else_clock_IfBlock1 = m_version_in ==
          ENUM_M_VERSION_Version_2_0_TM_conversions;
        /* ck_anon_activ */ if (else_clock_IfBlock1) {
          _L220_IfBlock1 = INT_M_VERSION_2_0_TM_conversions;
          _13_m_version_int = _L220_IfBlock1;
          _7_m_version_int = _13_m_version_int;
        }
        else {
          _L221_IfBlock1 = INT_M_VERSION_previous_M_TM_conversions;
          _11_m_version_int = _L221_IfBlock1;
          _7_m_version_int = _11_m_version_int;
        }
        _3_m_version_int = _7_m_version_int;
      }
      m_version_int = _3_m_version_int;
    }
    _23_m_version_int = m_version_int;
    /* ck_anon_activ */ if (_16_else_clock_IfBlock1) {
      _L517_IfBlock1 = kcg_false;
      error6 = _L517_IfBlock1;
      error = error6;
    }
    else {
      /* ck_anon_activ */ if (_15_else_clock_IfBlock1) {
        _L418_IfBlock1 = kcg_false;
        error10 = _L418_IfBlock1;
        error4 = error10;
      }
      else {
        /* ck_anon_activ */ if (else_clock_IfBlock1) {
          _L419_IfBlock1 = kcg_false;
          error14 = _L419_IfBlock1;
          error8 = error14;
        }
        else {
          _L1_IfBlock1 = kcg_true;
          error12 = _L1_IfBlock1;
          error8 = error12;
        }
        error4 = error8;
      }
      error = error4;
    }
    error22 = error;
  }
  _L5 = error22;
  noname = _L5;
  return _23_m_version_int;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** CAST_M_VERSION_to_int_TM_conversions.c
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

