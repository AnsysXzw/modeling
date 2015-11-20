/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CAST_M_ERROR_to_int_TM_conversions.h"

/* TM_conversions::CAST_M_ERROR_to_int */
kcg_int CAST_M_ERROR_to_int_TM_conversions(
  /* TM_conversions::CAST_M_ERROR_to_int::m_error */ M_ERROR m_error)
{
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error2;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _1_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::then::_L8 */
  static kcg_int _L8_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::then::_L7 */
  static kcg_bool _L7_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else */
  static kcg_bool _41_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error10;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _9_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::then::_L1 */
  static kcg_int _L1_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::then::_L2 */
  static kcg_bool _L2_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error8;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _7_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else */
  static kcg_bool _39_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error18;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _17_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::then::_L1 */
  static kcg_int _L145_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::then::_L2 */
  static kcg_bool _L246_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error16;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _15_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else */
  static kcg_bool _37_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error26;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _25_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L149_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L250_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error24;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _23_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else */
  static kcg_bool _35_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error34;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _33_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L153_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L254_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error32;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _31_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::_L1 */
  static kcg_int _L155_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else::else::else::_L2 */
  static kcg_bool _L256_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else::else */
  static kcg_bool else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _27_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error28;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else::then::_L2 */
  static kcg_bool _L252_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else::else::then::_L1 */
  static kcg_int _L151_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _29_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error30;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::else */
  static kcg_bool _36_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _19_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error20;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::then::_L1 */
  static kcg_bool _L148_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else::else::then::_L2 */
  static kcg_int _L247_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _21_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error22;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::else */
  static kcg_bool _38_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _11_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error12;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::then::_L2 */
  static kcg_int _L244_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else::else::then::_L1 */
  static kcg_bool _L143_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _13_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error14;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::else */
  static kcg_bool _40_else_clock_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _3_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error4;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::then::_L6 */
  static kcg_bool _L6_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1::else::then::_L7 */
  static kcg_int _L742_IfBlock1;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _5_m_error_int;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error6;
  static kcg_bool noname;
  /* TM_conversions::CAST_M_ERROR_to_int::IfBlock1 */
  static kcg_bool IfBlock1_clock;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_in */
  static M_ERROR m_error_in;
  /* TM_conversions::CAST_M_ERROR_to_int::error */
  static kcg_bool error57;
  /* TM_conversions::CAST_M_ERROR_to_int::_L4 */
  static M_ERROR _L4;
  /* TM_conversions::CAST_M_ERROR_to_int::_L7 */
  static kcg_bool _L7;
  /* TM_conversions::CAST_M_ERROR_to_int::m_error_int */
  static kcg_int _58_m_error_int;
  
  _L4 = m_error;
  m_error_in = _L4;
  IfBlock1_clock = m_error_in ==
    ENUM_M_ERROR_balise_group_linking_conistency_TM_conversions;
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    _L7_IfBlock1 = kcg_false;
    error2 = _L7_IfBlock1;
    error57 = error2;
  }
  else {
    _41_else_clock_IfBlock1 = m_error_in ==
      ENUM_M_ERROR_Double_linking_error_TM_conversions;
    /* ck_anon_activ */ if (_41_else_clock_IfBlock1) {
      _L6_IfBlock1 = kcg_false;
      error6 = _L6_IfBlock1;
      error = error6;
    }
    else {
      _40_else_clock_IfBlock1 = m_error_in ==
        ENUM_M_ERROR_Double_repositioning_error_TM_conversions;
      /* ck_anon_activ */ if (_40_else_clock_IfBlock1) {
        _L2_IfBlock1 = kcg_false;
        error10 = _L2_IfBlock1;
        error4 = error10;
      }
      else {
        _39_else_clock_IfBlock1 = m_error_in ==
          ENUM_M_ERROR_Linked_balise_group_message_consistency_erro_TM_conversions;
        /* ck_anon_activ */ if (_39_else_clock_IfBlock1) {
          _L143_IfBlock1 = kcg_false;
          error14 = _L143_IfBlock1;
          error8 = error14;
        }
        else {
          _38_else_clock_IfBlock1 = m_error_in ==
            ENUM_M_ERROR_Radio_message_consistency_error_TM_conversions;
          /* ck_anon_activ */ if (_38_else_clock_IfBlock1) {
            _L246_IfBlock1 = kcg_false;
            error18 = _L246_IfBlock1;
            error12 = error18;
          }
          else {
            _37_else_clock_IfBlock1 = m_error_in ==
              ENUM_M_ERROR_Radio_safe_radio_connection_error_TM_conversions;
            /* ck_anon_activ */ if (_37_else_clock_IfBlock1) {
              _L148_IfBlock1 = kcg_false;
              error22 = _L148_IfBlock1;
              error16 = error22;
            }
            else {
              _36_else_clock_IfBlock1 = m_error_in ==
                ENUM_M_ERROR_Radio_sequence_error_TM_conversions;
              /* ck_anon_activ */ if (_36_else_clock_IfBlock1) {
                _L250_IfBlock1 = kcg_false;
                error26 = _L250_IfBlock1;
                error20 = error26;
              }
              else {
                _35_else_clock_IfBlock1 = m_error_in ==
                  ENUM_M_ERROR_Safety_critical_failure_TM_conversions;
                /* ck_anon_activ */ if (_35_else_clock_IfBlock1) {
                  _L252_IfBlock1 = kcg_false;
                  error30 = _L252_IfBlock1;
                  error24 = error30;
                }
                else {
                  else_clock_IfBlock1 = m_error_in ==
                    ENUM_M_ERROR_Unlinked_balise_group_message_consistency_error_TM_conversions;
                  /* ck_anon_activ */ if (else_clock_IfBlock1) {
                    _L254_IfBlock1 = kcg_false;
                    error34 = _L254_IfBlock1;
                    error28 = error34;
                  }
                  else {
                    _L256_IfBlock1 = kcg_true;
                    error32 = _L256_IfBlock1;
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
    error57 = error;
  }
  _L7 = error57;
  noname = _L7;
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    _L8_IfBlock1 = INT_M_ERROR_balise_group_linking_conistency_TM_conversions;
    _1_m_error_int = _L8_IfBlock1;
    _58_m_error_int = _1_m_error_int;
  }
  else {
    /* ck_anon_activ */ if (_41_else_clock_IfBlock1) {
      _L742_IfBlock1 = INT_M_ERROR_Double_linking_error_TM_conversions;
      _5_m_error_int = _L742_IfBlock1;
      m_error_int = _5_m_error_int;
    }
    else {
      /* ck_anon_activ */ if (_40_else_clock_IfBlock1) {
        _L1_IfBlock1 = INT_M_ERROR_Double_repositioning_error_TM_conversions;
        _9_m_error_int = _L1_IfBlock1;
        _3_m_error_int = _9_m_error_int;
      }
      else {
        /* ck_anon_activ */ if (_39_else_clock_IfBlock1) {
          _L244_IfBlock1 =
            INT_M_ERROR_Linked_balise_group_message_consistency_error_TM_conversions;
          _13_m_error_int = _L244_IfBlock1;
          _7_m_error_int = _13_m_error_int;
        }
        else {
          /* ck_anon_activ */ if (_38_else_clock_IfBlock1) {
            _L145_IfBlock1 =
              INT_M_ERROR_Radio_message_consistency_error_TM_conversions;
            _17_m_error_int = _L145_IfBlock1;
            _11_m_error_int = _17_m_error_int;
          }
          else {
            /* ck_anon_activ */ if (_37_else_clock_IfBlock1) {
              _L247_IfBlock1 =
                INT_M_ERROR_Radio_safe_radio_connection_error_TM_conversions;
              _21_m_error_int = _L247_IfBlock1;
              _15_m_error_int = _21_m_error_int;
            }
            else {
              /* ck_anon_activ */ if (_36_else_clock_IfBlock1) {
                _L149_IfBlock1 =
                  INT_M_ERROR_Radio_sequence_error_TM_conversions;
                _25_m_error_int = _L149_IfBlock1;
                _19_m_error_int = _25_m_error_int;
              }
              else {
                /* ck_anon_activ */ if (_35_else_clock_IfBlock1) {
                  _L151_IfBlock1 =
                    INT_M_ERROR_Safety_critical_failure_TM_conversions;
                  _29_m_error_int = _L151_IfBlock1;
                  _23_m_error_int = _29_m_error_int;
                }
                else {
                  /* ck_anon_activ */ if (else_clock_IfBlock1) {
                    _L153_IfBlock1 =
                      INT_M_ERROR_Unlinked_balise_group_message_consistency_error_TM_conversions;
                    _33_m_error_int = _L153_IfBlock1;
                    _27_m_error_int = _33_m_error_int;
                  }
                  else {
                    _L155_IfBlock1 =
                      INT_M_ERROR_Safety_critical_failure_TM_conversions;
                    _31_m_error_int = _L155_IfBlock1;
                    _27_m_error_int = _31_m_error_int;
                  }
                  _23_m_error_int = _27_m_error_int;
                }
                _19_m_error_int = _23_m_error_int;
              }
              _15_m_error_int = _19_m_error_int;
            }
            _11_m_error_int = _15_m_error_int;
          }
          _7_m_error_int = _11_m_error_int;
        }
        _3_m_error_int = _7_m_error_int;
      }
      m_error_int = _3_m_error_int;
    }
    _58_m_error_int = m_error_int;
  }
  return _58_m_error_int;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** CAST_M_ERROR_to_int_TM_conversions.c
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

