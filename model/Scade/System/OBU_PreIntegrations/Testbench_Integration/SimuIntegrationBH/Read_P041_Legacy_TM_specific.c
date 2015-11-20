/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Read_P041_Legacy_TM_specific.h"

/* TM_specific::Read_P041_Legacy */
void Read_P041_Legacy_TM_specific(
  /* TM_specific::Read_P041_Legacy::Message_IN */ CompressedPackets_T_Common_Types_Pkg *Message_IN,
  /* TM_specific::Read_P041_Legacy::P041_legacy_out */ P41_LevelTransistionOrders_T_Packet_Types_Pkg *P041_legacy_out)
{
  /* TM_specific::Read_P041_Legacy */
  static P41_LevelTransistionOrders_T_Packet_Types_Pkg op_call;
  /* TM_specific::Read_P041_Legacy */
  static kcg_bool ck_every;
  /* TM_specific::Read_P041_Legacy::_L2 */
  static P041_OBU_T_TM _L2;
  /* TM_specific::Read_P041_Legacy::_L1 */
  static kcg_bool _L1;
  /* TM_specific::Read_P041_Legacy::_L3 */
  static CompressedPackets_T_Common_Types_Pkg _L3;
  /* TM_specific::Read_P041_Legacy::_L4 */
  static P41_LevelTransistionOrders_T_Packet_Types_Pkg _L4;
  
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(&_L3, Message_IN);
  /* 1 */ Read_P041_TM(&_L3, &_L1, &_L2);
  ck_every = _L1;
  /* ck_Read_P041_Legacy */ if (ck_every) {
    /* 1 */ C_P041_to_legacy_t_TM_conversions(&_L2, &op_call);
    kcg_copy_P41_LevelTransistionOrders_T_Packet_Types_Pkg(&_L4, &op_call);
  }
  else {
    kcg_copy_P41_LevelTransistionOrders_T_Packet_Types_Pkg(
      &_L4,
      (P41_LevelTransistionOrders_T_Packet_Types_Pkg *)
        &DEFAULT_P041_legacy_TM_specific);
  }
  kcg_copy_P41_LevelTransistionOrders_T_Packet_Types_Pkg(P041_legacy_out, &_L4);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Read_P041_Legacy_TM_specific.c
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

