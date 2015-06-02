/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/Simulation\kcg_s2c_config.txt
** Generation date: 2015-06-02T15:02:42
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SEND_ConvertP005forWrite_IT_TM_conversions.h"

void SEND_ConvertP005forWrite_IT_reset_TM_conversions(
  outC_SEND_ConvertP005forWrite_IT_TM_conversions *outC)
{
  /* 1 */ CAST_Int_to_Q_DIR_reset_TM_conversions(&outC->_2_Context_1);
  /* 1 */ SEND_ConvertP005forWriteS_reset_TM_conversions(&outC->_1_Context_1);
  /* 2 */ SEND_ConvertP005forWriteS_reset_TM_conversions(&outC->Context_2);
  /* 3 */ SEND_ConvertP005forWriteS_reset_TM_conversions(&outC->Context_3);
  /* 4 */ SEND_ConvertP005forWriteS_reset_TM_conversions(&outC->Context_4);
  /* 5 */ SEND_ConvertP005forWriteS_reset_TM_conversions(&outC->Context_5);
  /* 1 */ TOOLS_calculate_L_PACKET_reset_TM_conversions(&outC->Context_1);
}

/* TM_conversions::SEND_ConvertP005forWrite_IT */
void SEND_ConvertP005forWrite_IT_TM_conversions(
  /* TM_conversions::SEND_ConvertP005forWrite_IT::RM05 */P005_TM *RM05,
  outC_SEND_ConvertP005forWrite_IT_TM_conversions *outC)
{
  kcg_int i;
  kcg_int noname;
  
  kcg_copy_P005_TM(&outC->_L1, RM05);
  kcg_copy_P005Es_T_TM(&outC->_L219, &outC->_L1.SECTIONS);
  outC->_L218 = outC->_L1.N_ITER;
  outC->_L217 = outC->_L1.Q_SCALE;
  outC->_L216 = outC->_L1.L_PACKET;
  outC->_L215 = outC->_L1.Q_DIR;
  kcg_copy_P005E_T_TM(&outC->_L226, &outC->_L219[4]);
  kcg_copy_P005E_T_TM(&outC->_L227, &outC->_L219[3]);
  kcg_copy_P005E_T_TM(&outC->_L228, &outC->_L219[2]);
  kcg_copy_P005E_T_TM(&outC->_L229, &outC->_L219[1]);
  noname = outC->_L216;
  /* 1 */
  TOOLS_calculate_L_PACKET_TM_conversions(outC->_L218, 4, 7, &outC->Context_1);
  outC->_L363 = outC->Context_1.L_PACKET;
  outC->_L364 = outC->Context_1.N_ITER_out;
  /* 5 */
  SEND_ConvertP005forWriteS_TM_conversions(&outC->_L226, &outC->Context_5);
  kcg_copy_P005E_array_T_TM(&outC->_L361, &outC->Context_5.SectionArray);
  /* 4 */
  SEND_ConvertP005forWriteS_TM_conversions(&outC->_L227, &outC->Context_4);
  kcg_copy_P005E_array_T_TM(&outC->_L360, &outC->Context_4.SectionArray);
  /* 3 */
  SEND_ConvertP005forWriteS_TM_conversions(&outC->_L228, &outC->Context_3);
  kcg_copy_P005E_array_T_TM(&outC->_L359, &outC->Context_3.SectionArray);
  /* 2 */
  SEND_ConvertP005forWriteS_TM_conversions(&outC->_L229, &outC->Context_2);
  kcg_copy_P005E_array_T_TM(&outC->_L358, &outC->Context_2.SectionArray);
  kcg_copy_P005E_T_TM(&outC->_L230, &outC->_L219[0]);
  /* 1 */
  SEND_ConvertP005forWriteS_TM_conversions(&outC->_L230, &outC->_1_Context_1);
  kcg_copy_P005E_array_T_TM(&outC->_L357, &outC->_1_Context_1.SectionArray);
  /* 1 */ CAST_Int_to_Q_DIR_TM_conversions(outC->_L215, &outC->_2_Context_1);
  outC->_L356 = outC->_2_Context_1.q_dir;
  outC->_L355[0] = outC->_L215;
  outC->_L355[1] = outC->_L363;
  outC->_L355[2] = outC->_L217;
  outC->_L355[3] = outC->_L364;
  outC->_L336 = 0;
  kcg_copy_array_int_4(&outC->_L325[0], &outC->_L355);
  kcg_copy_P005E_array_T_TM(&outC->_L325[4], &outC->_L357);
  kcg_copy_array_int_11(&outC->_L327[0], &outC->_L325);
  kcg_copy_P005E_array_T_TM(&outC->_L327[11], &outC->_L358);
  kcg_copy_array_int_18(&outC->_L328[0], &outC->_L327);
  kcg_copy_P005E_array_T_TM(&outC->_L328[18], &outC->_L359);
  kcg_copy_array_int_25(&outC->_L329[0], &outC->_L328);
  kcg_copy_P005E_array_T_TM(&outC->_L329[25], &outC->_L360);
  kcg_copy_array_int_32(&outC->_L330[0], &outC->_L329);
  kcg_copy_P005E_array_T_TM(&outC->_L330[32], &outC->_L361);
  outC->_L214 = outC->_L1.valid;
  outC->_L213 = 1;
  outC->_L212 = outC->_L363 - outC->_L213;
  for (i = 0; i < 461; i++) {
    outC->_L209[i] = outC->_L336;
  }
  kcg_copy_array_int_39(&outC->_L211[0], &outC->_L330);
  kcg_copy_array_int_461(&outC->_L211[39], &outC->_L209);
  outC->_L206 = 0;
  outC->_L205 = 5;
  outC->_L204.nid_packet = outC->_L205;
  outC->_L204.q_dir = outC->_L356;
  outC->_L204.valid = outC->_L214;
  outC->_L204.startAddress = outC->_L206;
  outC->_L204.endAddress = outC->_L212;
  kcg_copy_MetadataElement_T_Common_Types_Pkg(&outC->Header, &outC->_L204);
  kcg_copy_CompressedPacketData_T_Common_Types_Pkg(
    &outC->RM05_out,
    &outC->_L211);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** SEND_ConvertP005forWrite_IT_TM_conversions.c
** Generation date: 2015-06-02T15:02:42
*************************************************************$ */

