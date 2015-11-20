/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CAST_DMI_Display_Control_to_int_DATA_Packets_EVC_to_DMI.h"

/* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int */
void CAST_DMI_Display_Control_to_int_DATA_Packets_EVC_to_DMI(
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::dmi_display_control_ct */ DMI_Display_Control_T_DMI_Messages_EVC_to_DMI_Pkg *dmi_display_control_ct,
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::dmi_display_control_int */ DMI_Display_Control_int_array_T_DATA *dmi_display_control_int)
{
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::_L1 */
  static DMI_Display_Control_T_DMI_Messages_EVC_to_DMI_Pkg _L1;
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::_L2 */
  static array_int_3 _L2;
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::_L5 */
  static kcg_bool _L5;
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::_L4 */
  static kcg_bool _L4;
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::_L3 */
  static T_internal_Type_Obu_BasicTypes_Pkg _L3;
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::_L6 */
  static kcg_int _L6;
  /* DATA::Packets::EVC_to_DMI::CAST_DMI_Display_Control_to_int::_L7 */
  static kcg_int _L7;
  
  kcg_copy_DMI_Display_Control_T_DMI_Messages_EVC_to_DMI_Pkg(
    &_L1,
    dmi_display_control_ct);
  _L5 = _L1.valid;
  _L6 = /* 1 */ Bool_to_Int_Utilities(_L5);
  _L4 = _L1.cab_is_active;
  _L7 = /* 2 */ Bool_to_Int_Utilities(_L4);
  _L3 = _L1.system_clock;
  _L2[0] = _L6;
  _L2[1] = _L7;
  _L2[2] = _L3;
  kcg_copy_DMI_Display_Control_int_array_T_DATA(dmi_display_control_int, &_L2);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** CAST_DMI_Display_Control_to_int_DATA_Packets_EVC_to_DMI.c
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

