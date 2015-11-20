/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "C_int_to_DMI_Train_Data_Ack1_DATA_Packets_DMI_to_EVC.h"

/* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1 */
void C_int_to_DMI_Train_Data_Ack1_DATA_Packets_DMI_to_EVC(
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::dmi_train_data_ack_int */ DMI_Train_Data_Ack_int_array_T_DATA *dmi_train_data_ack_int,
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::dmi_train_data_ack_ct */ DMI_Train_Data_Ack_T_DMI_Messages_DMI_to_EVC_Pkg *dmi_train_data_ack_ct)
{
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::_L2 */
  static DMI_Train_Data_Ack_T_DMI_Messages_DMI_to_EVC_Pkg _L2;
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::_L5 */
  static kcg_int _L5;
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::_L4 */
  static kcg_int _L4;
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::_L3 */
  static kcg_int _L3;
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::_L8 */
  static DMI_Train_Data_Ack_int_array_T_DATA _L8;
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::_L9 */
  static kcg_bool _L9;
  /* DATA::Packets::DMI_to_EVC::C_int_to_DMI_Train_Data_Ack1::_L11 */
  static kcg_bool _L11;
  
  kcg_copy_DMI_Train_Data_Ack_int_array_T_DATA(&_L8, dmi_train_data_ack_int);
  _L5 = _L8[0];
  _L9 = /* 1 */ Int_to_Bool_Utilities(_L5);
  _L4 = _L8[1];
  _L3 = _L8[2];
  _L11 = /* 2 */ Int_to_Bool_Utilities(_L3);
  _L2.valid = _L9;
  _L2.systemTime = _L4;
  _L2.acknowledged = _L11;
  kcg_copy_DMI_Train_Data_Ack_T_DMI_Messages_DMI_to_EVC_Pkg(
    dmi_train_data_ack_ct,
    &_L2);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** C_int_to_DMI_Train_Data_Ack1_DATA_Packets_DMI_to_EVC.c
** Generation date: 2015-11-20T14:27:49
*************************************************************$ */

