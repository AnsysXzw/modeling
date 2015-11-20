/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config D:/MD/model/Scade/System/OBU_PreIntegrations/Testbench_Integration/SimuIntegrationBH/config.txt
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Read_P005_TM.h"

/* TM::Read_P005 */
void Read_P005_TM(
  /* TM::Read_P005::Message_IN */ CompressedPackets_T_Common_Types_Pkg *Message_IN,
  /* TM::Read_P005::received */ kcg_bool *received,
  /* TM::Read_P005::P005_OBU_out */ P005_OBU_T_TM *P005_OBU_out)
{
  /* TM::Read_P005::_L5 */
  static CompressedPacketData_T_Common_Types_Pkg _L5;
  /* TM::Read_P005::_L6 */
  static CompressedPackets_T_Common_Types_Pkg _L6;
  /* TM::Read_P005::_L30 */
  static MetadataElement_T_Common_Types_Pkg _L30;
  /* TM::Read_P005::_L166 */
  static P005_OBU_T_TM _L166;
  /* TM::Read_P005::_L167 */
  static kcg_bool _L167;
  
  kcg_copy_CompressedPackets_T_Common_Types_Pkg(&_L6, Message_IN);
  /* 1 */
  RECV_ReadPackets_TM_lib_internal(
    &_L6,
    5032000,
    kcg_true,
    kcg_false,
    &_L5,
    &_L30,
    &_L167);
  /* 3 */ C_P005_compr_onboard_TM_conversions(&_L5, &_L30, &_L166);
  kcg_copy_P005_OBU_T_TM(P005_OBU_out, &_L166);
  *received = _L167;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Read_P005_TM.c
** Generation date: 2015-11-20T14:27:50
*************************************************************$ */

