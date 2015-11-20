/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "C_P065_tracksim_compr_TM_conversions.h"

/* TM_conversions::C_P065_tracksim_compr */
void C_P065_tracksim_compr_TM_conversions(
  /* TM_conversions::C_P065_tracksim_compr::P065_from_track */ P065_trackside_int_T_TM *P065_from_track,
  /* TM_conversions::C_P065_tracksim_compr::Header */ MetadataElement_T_Common_Types_Pkg *Header,
  /* TM_conversions::C_P065_tracksim_compr::P065_compressed */ CompressedPacketData_T_Common_Types_Pkg *P065_compressed)
{
  static kcg_int i;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir */
  static Q_DIR _16_q_dir_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir_int */
  static kcg_int q_dir_int_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::_L12 */
  static kcg_int _L12_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::_L13 */
  static kcg_bool _L13_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir_in */
  static kcg_int q_dir_in_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::error */
  static kcg_bool error_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1 */
  static kcg_bool IfBlock1_clock_1;
  static kcg_bool noname_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::error */
  static kcg_bool _1_error_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir */
  static Q_DIR q_dir_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else::then::_L5 */
  static kcg_bool _L5_1_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else::then::_L3 */
  static Q_DIR _L3_1_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::error */
  static kcg_bool _2_error_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir */
  static Q_DIR _3_q_dir_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else::else */
  static kcg_bool else_clock_1_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else::else::else::_L2 */
  static Q_DIR _L2_1_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else::else::else::_L1 */
  static kcg_bool _L1_1_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir */
  static Q_DIR _4_q_dir_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::error */
  static kcg_bool _5_error_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else::else::then::_L2 */
  static Q_DIR _L2_16_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else::else::then::_L4 */
  static kcg_bool _L4_1_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir */
  static Q_DIR _7_q_dir_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::error */
  static kcg_bool _8_error_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::else */
  static kcg_bool _9_else_clock_1_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir */
  static Q_DIR _10_q_dir_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::error */
  static kcg_bool _11_error_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::then::_L4 */
  static Q_DIR _L4_112_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::IfBlock1::then::_L5 */
  static kcg_bool _L5_113_IfBlock1;
  /* TM_conversions::CAST_Int_to_Q_DIR::q_dir */
  static Q_DIR _14_q_dir_1;
  /* TM_conversions::CAST_Int_to_Q_DIR::error */
  static kcg_bool _15_error_1;
  /* TM_conversions::C_P065_tracksim_compr::_L1 */
  static P065_trackside_int_T_TM _L1;
  /* TM_conversions::C_P065_tracksim_compr::_L204 */
  static MetadataElement_T_Common_Types_Pkg _L204;
  /* TM_conversions::C_P065_tracksim_compr::_L206 */
  static kcg_int _L206;
  /* TM_conversions::C_P065_tracksim_compr::_L209 */
  static array_int_491 _L209;
  /* TM_conversions::C_P065_tracksim_compr::_L212 */
  static kcg_int _L212;
  /* TM_conversions::C_P065_tracksim_compr::_L213 */
  static kcg_int _L213;
  /* TM_conversions::C_P065_tracksim_compr::_L336 */
  static kcg_int _L336;
  /* TM_conversions::C_P065_tracksim_compr::_L214 */
  static kcg_bool _L214;
  /* TM_conversions::C_P065_tracksim_compr::_L356 */
  static Q_DIR _L356;
  /* TM_conversions::C_P065_tracksim_compr::_L373 */
  static array_int_9 _L373;
  /* TM_conversions::C_P065_tracksim_compr::_L383 */
  static CompressedPacketData_T_Common_Types_Pkg _L383;
  /* TM_conversions::C_P065_tracksim_compr::_L387 */
  static kcg_int _L387;
  /* TM_conversions::C_P065_tracksim_compr::_L388 */
  static kcg_int _L388;
  /* TM_conversions::C_P065_tracksim_compr::_L395 */
  static kcg_int _L395;
  /* TM_conversions::C_P065_tracksim_compr::_L394 */
  static kcg_int _L394;
  /* TM_conversions::C_P065_tracksim_compr::_L393 */
  static kcg_int _L393;
  /* TM_conversions::C_P065_tracksim_compr::_L399 */
  static kcg_int _L399;
  /* TM_conversions::C_P065_tracksim_compr::_L398 */
  static kcg_int _L398;
  /* TM_conversions::C_P065_tracksim_compr::_L397 */
  static kcg_int _L397;
  /* TM_conversions::C_P065_tracksim_compr::_L396 */
  static kcg_int _L396;
  /* TM_conversions::C_P065_tracksim_compr::_L400 */
  static kcg_int _L400;
  /* TM_conversions::C_P065_tracksim_compr::_L401 */
  static nid_packet_meta_TM _L401;
  
  kcg_copy_P065_trackside_int_T_TM(&_L1, P065_from_track);
  _L387 = _L1.NID_PACKET;
  _L395 = _L1.Q_DIR;
  _L394 = _L1.L_PACKET;
  _L400 = _L1.Q_SCALE;
  _L393 = _L1.NID_TSR;
  _L399 = _L1.D_TSR;
  _L398 = _L1.L_TSR;
  _L397 = _L1.Q_FRONT;
  _L396 = _L1.V_TSR;
  _L373[0] = _L387;
  _L373[1] = _L395;
  _L373[2] = _L394;
  _L373[3] = _L400;
  _L373[4] = _L393;
  _L373[5] = _L399;
  _L373[6] = _L398;
  _L373[7] = _L397;
  _L373[8] = _L396;
  _L336 = 0;
  /* pow */ for (i = 0; i < 491; i++) {
    _L209[i] = _L336;
  }
  kcg_copy_array_int_9(&_L383[0], &_L373);
  kcg_copy_array_int_491(&_L383[9], &_L209);
  kcg_copy_CompressedPacketData_T_Common_Types_Pkg(P065_compressed, &_L383);
  _L401 = /* 1 */
    T_Build_Metadata_Packet_ID_TM_lib_internal(
      _L387,
      _L395,
      _L393,
      65,
      INT_M_VERSION_2_0_TM);
  q_dir_int_1 = _L395;
  _L12_1 = q_dir_int_1;
  q_dir_in_1 = _L12_1;
  IfBlock1_clock_1 = q_dir_in_1 == INT_Q_DIR_nomiinal_TM_conversions;
  /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
    _L4_112_IfBlock1 = ENUM_Q_DIR_nominal_TM_conversions;
    _14_q_dir_1 = _L4_112_IfBlock1;
    _16_q_dir_1 = _14_q_dir_1;
  }
  else {
    _9_else_clock_1_IfBlock1 = q_dir_in_1 == INT_Q_DIR_reverse_TM_conversions;
    /* 1_ck_anon_activ */ if (_9_else_clock_1_IfBlock1) {
      _L3_1_IfBlock1 = ENUM_Q_DIR_reverse_TM_conversions;
      q_dir_1 = _L3_1_IfBlock1;
      _10_q_dir_1 = q_dir_1;
    }
    else {
      else_clock_1_IfBlock1 = q_dir_in_1 == INT_Q_DIR_both_TM_conversions;
      /* 1_ck_anon_activ */ if (else_clock_1_IfBlock1) {
        _L2_16_IfBlock1 = ENUM_Q_DIR_both_TM_conversions;
        _7_q_dir_1 = _L2_16_IfBlock1;
        _3_q_dir_1 = _7_q_dir_1;
      }
      else {
        _L2_1_IfBlock1 = ENUM_Q_DIR_both_TM_conversions;
        _4_q_dir_1 = _L2_1_IfBlock1;
        _3_q_dir_1 = _4_q_dir_1;
      }
      _10_q_dir_1 = _3_q_dir_1;
    }
    _16_q_dir_1 = _10_q_dir_1;
  }
  _L356 = _16_q_dir_1;
  _L214 = _L1.valid;
  _L206 = 0;
  _L388 = DIM_MaxElementsPacket065_TM;
  _L213 = 1;
  _L212 = _L388 - _L213;
  _L204.nid_packet = _L401;
  _L204.q_dir = _L356;
  _L204.valid = _L214;
  _L204.startAddress = _L206;
  _L204.endAddress = _L212;
  kcg_copy_MetadataElement_T_Common_Types_Pkg(Header, &_L204);
  /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
    _L5_113_IfBlock1 = kcg_false;
    _15_error_1 = _L5_113_IfBlock1;
    error_1 = _15_error_1;
  }
  else {
    /* 1_ck_anon_activ */ if (_9_else_clock_1_IfBlock1) {
      _L5_1_IfBlock1 = kcg_false;
      _1_error_1 = _L5_1_IfBlock1;
      _11_error_1 = _1_error_1;
    }
    else {
      /* 1_ck_anon_activ */ if (else_clock_1_IfBlock1) {
        _L4_1_IfBlock1 = kcg_false;
        _8_error_1 = _L4_1_IfBlock1;
        _2_error_1 = _8_error_1;
      }
      else {
        _L1_1_IfBlock1 = kcg_true;
        _5_error_1 = _L1_1_IfBlock1;
        _2_error_1 = _5_error_1;
      }
      _11_error_1 = _2_error_1;
    }
    error_1 = _11_error_1;
  }
  _L13_1 = error_1;
  noname_1 = _L13_1;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** C_P065_tracksim_compr_TM_conversions.c
** Generation date: 2015-11-20T14:27:51
*************************************************************$ */

