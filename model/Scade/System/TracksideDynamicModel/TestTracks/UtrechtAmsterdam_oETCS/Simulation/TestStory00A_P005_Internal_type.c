
#include <stdlib.h>
#include "SmuTypes.h"
#include "kcg_types.h"
#include "TestStory00A_P005_Internal_type.h"
#include "TestStory00A_P005_Internal_mapping.h"

extern ScSimulator * pSimulator;

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
int _SCSIM_BoolEntity_is_active(void* pValue) {
	return *((kcg_bool*)pValue) == kcg_true ? 1 : 0;
}

/****************************************************************
 ** Type utils declarations
 ****************************************************************/
TypeUtils _SCSIM_kcg_real_Utils = {kcg_real_to_string,
	check_kcg_real_string,
	string_to_kcg_real,
	is_kcg_real_allow_double_convertion,
	kcg_real_to_double,
	compare_kcg_real_type,
	get_kcg_real_signature,
	get_kcg_real_filter_utils,
	kcg_real_filter_size,
	kcg_real_filter_values};
TypeUtils _SCSIM_kcg_bool_Utils = {kcg_bool_to_string,
	check_kcg_bool_string,
	string_to_kcg_bool,
	is_kcg_bool_allow_double_convertion,
	kcg_bool_to_double,
	compare_kcg_bool_type,
	get_kcg_bool_signature,
	get_kcg_bool_filter_utils,
	kcg_bool_filter_size,
	kcg_bool_filter_values};
TypeUtils _SCSIM_kcg_char_Utils = {kcg_char_to_string,
	check_kcg_char_string,
	string_to_kcg_char,
	is_kcg_char_allow_double_convertion,
	kcg_char_to_double,
	compare_kcg_char_type,
	get_kcg_char_signature,
	get_kcg_char_filter_utils,
	kcg_char_filter_size,
	kcg_char_filter_values};
TypeUtils _SCSIM_kcg_int_Utils = {kcg_int_to_string,
	check_kcg_int_string,
	string_to_kcg_int,
	is_kcg_int_allow_double_convertion,
	kcg_int_to_double,
	compare_kcg_int_type,
	get_kcg_int_signature,
	get_kcg_int_filter_utils,
	kcg_int_filter_size,
	kcg_int_filter_values};
TypeUtils _SCSIM_struct__5532_Utils = {struct__5532_to_string,
	check_struct__5532_string,
	string_to_struct__5532,
	is_struct__5532_allow_double_convertion,
	0,
	compare_struct__5532_type,
	get_struct__5532_signature,
	get_struct__5532_filter_utils,
	struct__5532_filter_size,
	struct__5532_filter_values};
TypeUtils _SCSIM_array__5546_Utils = {array__5546_to_string,
	check_array__5546_string,
	string_to_array__5546,
	is_array__5546_allow_double_convertion,
	0,
	compare_array__5546_type,
	get_array__5546_signature,
	get_array__5546_filter_utils,
	array__5546_filter_size,
	array__5546_filter_values};
TypeUtils _SCSIM_struct__5549_Utils = {struct__5549_to_string,
	check_struct__5549_string,
	string_to_struct__5549,
	is_struct__5549_allow_double_convertion,
	0,
	compare_struct__5549_type,
	get_struct__5549_signature,
	get_struct__5549_filter_utils,
	struct__5549_filter_size,
	struct__5549_filter_values};
TypeUtils _SCSIM_array_int_500_Utils = {array_int_500_to_string,
	check_array_int_500_string,
	string_to_array_int_500,
	is_array_int_500_allow_double_convertion,
	0,
	compare_array_int_500_type,
	get_array_int_500_signature,
	get_array_int_500_filter_utils,
	array_int_500_filter_size,
	array_int_500_filter_values};
TypeUtils _SCSIM_struct__5565_Utils = {struct__5565_to_string,
	check_struct__5565_string,
	string_to_struct__5565,
	is_struct__5565_allow_double_convertion,
	0,
	compare_struct__5565_type,
	get_struct__5565_signature,
	get_struct__5565_filter_utils,
	struct__5565_filter_size,
	struct__5565_filter_values};
TypeUtils _SCSIM_array__5573_Utils = {array__5573_to_string,
	check_array__5573_string,
	string_to_array__5573,
	is_array__5573_allow_double_convertion,
	0,
	compare_array__5573_type,
	get_array__5573_signature,
	get_array__5573_filter_utils,
	array__5573_filter_size,
	array__5573_filter_values};
TypeUtils _SCSIM_struct__5576_Utils = {struct__5576_to_string,
	check_struct__5576_string,
	string_to_struct__5576,
	is_struct__5576_allow_double_convertion,
	0,
	compare_struct__5576_type,
	get_struct__5576_signature,
	get_struct__5576_filter_utils,
	struct__5576_filter_size,
	struct__5576_filter_values};
TypeUtils _SCSIM_struct__5581_Utils = {struct__5581_to_string,
	check_struct__5581_string,
	string_to_struct__5581,
	is_struct__5581_allow_double_convertion,
	0,
	compare_struct__5581_type,
	get_struct__5581_signature,
	get_struct__5581_filter_utils,
	struct__5581_filter_size,
	struct__5581_filter_values};
TypeUtils _SCSIM_array__5592_Utils = {array__5592_to_string,
	check_array__5592_string,
	string_to_array__5592,
	is_array__5592_allow_double_convertion,
	0,
	compare_array__5592_type,
	get_array__5592_signature,
	get_array__5592_filter_utils,
	array__5592_filter_size,
	array__5592_filter_values};
TypeUtils _SCSIM_struct__5595_Utils = {struct__5595_to_string,
	check_struct__5595_string,
	string_to_struct__5595,
	is_struct__5595_allow_double_convertion,
	0,
	compare_struct__5595_type,
	get_struct__5595_signature,
	get_struct__5595_filter_utils,
	struct__5595_filter_size,
	struct__5595_filter_values};
TypeUtils _SCSIM_array_int_224_Utils = {array_int_224_to_string,
	check_array_int_224_string,
	string_to_array_int_224,
	is_array_int_224_allow_double_convertion,
	0,
	compare_array_int_224_type,
	get_array_int_224_signature,
	get_array_int_224_filter_utils,
	array_int_224_filter_size,
	array_int_224_filter_values};
TypeUtils _SCSIM_array_int_3_Utils = {array_int_3_to_string,
	check_array_int_3_string,
	string_to_array_int_3,
	is_array_int_3_allow_double_convertion,
	0,
	compare_array_int_3_type,
	get_array_int_3_signature,
	get_array_int_3_filter_utils,
	array_int_3_filter_size,
	array_int_3_filter_values};
TypeUtils _SCSIM_struct__5610_Utils = {struct__5610_to_string,
	check_struct__5610_string,
	string_to_struct__5610,
	is_struct__5610_allow_double_convertion,
	0,
	compare_struct__5610_type,
	get_struct__5610_signature,
	get_struct__5610_filter_utils,
	struct__5610_filter_size,
	struct__5610_filter_values};
TypeUtils _SCSIM_struct__5623_Utils = {struct__5623_to_string,
	check_struct__5623_string,
	string_to_struct__5623,
	is_struct__5623_allow_double_convertion,
	0,
	compare_struct__5623_type,
	get_struct__5623_signature,
	get_struct__5623_filter_utils,
	struct__5623_filter_size,
	struct__5623_filter_values};
TypeUtils _SCSIM_struct__5628_Utils = {struct__5628_to_string,
	check_struct__5628_string,
	string_to_struct__5628,
	is_struct__5628_allow_double_convertion,
	0,
	compare_struct__5628_type,
	get_struct__5628_signature,
	get_struct__5628_filter_utils,
	struct__5628_filter_size,
	struct__5628_filter_values};
TypeUtils _SCSIM_struct__5636_Utils = {struct__5636_to_string,
	check_struct__5636_string,
	string_to_struct__5636,
	is_struct__5636_allow_double_convertion,
	0,
	compare_struct__5636_type,
	get_struct__5636_signature,
	get_struct__5636_filter_utils,
	struct__5636_filter_size,
	struct__5636_filter_values};
TypeUtils _SCSIM_struct__5645_Utils = {struct__5645_to_string,
	check_struct__5645_string,
	string_to_struct__5645,
	is_struct__5645_allow_double_convertion,
	0,
	compare_struct__5645_type,
	get_struct__5645_signature,
	get_struct__5645_filter_utils,
	struct__5645_filter_size,
	struct__5645_filter_values};
TypeUtils _SCSIM_array__5655_Utils = {array__5655_to_string,
	check_array__5655_string,
	string_to_array__5655,
	is_array__5655_allow_double_convertion,
	0,
	compare_array__5655_type,
	get_array__5655_signature,
	get_array__5655_filter_utils,
	array__5655_filter_size,
	array__5655_filter_values};
TypeUtils _SCSIM_struct__5658_Utils = {struct__5658_to_string,
	check_struct__5658_string,
	string_to_struct__5658,
	is_struct__5658_allow_double_convertion,
	0,
	compare_struct__5658_type,
	get_struct__5658_signature,
	get_struct__5658_filter_utils,
	struct__5658_filter_size,
	struct__5658_filter_values};
TypeUtils _SCSIM_array_int_7_Utils = {array_int_7_to_string,
	check_array_int_7_string,
	string_to_array_int_7,
	is_array_int_7_allow_double_convertion,
	0,
	compare_array_int_7_type,
	get_array_int_7_signature,
	get_array_int_7_filter_utils,
	array_int_7_filter_size,
	array_int_7_filter_values};
TypeUtils _SCSIM_array_int_7_33_Utils = {array_int_7_33_to_string,
	check_array_int_7_33_string,
	string_to_array_int_7_33,
	is_array_int_7_33_allow_double_convertion,
	0,
	compare_array_int_7_33_type,
	get_array_int_7_33_signature,
	get_array_int_7_33_filter_utils,
	array_int_7_33_filter_size,
	array_int_7_33_filter_values};
TypeUtils _SCSIM_array__5681_Utils = {array__5681_to_string,
	check_array__5681_string,
	string_to_array__5681,
	is_array__5681_allow_double_convertion,
	0,
	compare_array__5681_type,
	get_array__5681_signature,
	get_array__5681_filter_utils,
	array__5681_filter_size,
	array__5681_filter_values};
TypeUtils _SCSIM_array_int_500_500_Utils = {array_int_500_500_to_string,
	check_array_int_500_500_string,
	string_to_array_int_500_500,
	is_array_int_500_500_allow_double_convertion,
	0,
	compare_array_int_500_500_type,
	get_array_int_500_500_signature,
	get_array_int_500_500_filter_utils,
	array_int_500_500_filter_size,
	array_int_500_500_filter_values};
TypeUtils _SCSIM_array_int_7_33_231_Utils = {array_int_7_33_231_to_string,
	check_array_int_7_33_231_string,
	string_to_array_int_7_33_231,
	is_array_int_7_33_231_allow_double_convertion,
	0,
	compare_array_int_7_33_231_type,
	get_array_int_7_33_231_signature,
	get_array_int_7_33_231_filter_utils,
	array_int_7_33_231_filter_size,
	array_int_7_33_231_filter_values};
TypeUtils _SCSIM_array_int_271_Utils = {array_int_271_to_string,
	check_array_int_271_string,
	string_to_array_int_271,
	is_array_int_271_allow_double_convertion,
	0,
	compare_array_int_271_type,
	get_array_int_271_signature,
	get_array_int_271_filter_utils,
	array_int_271_filter_size,
	array_int_271_filter_values};
TypeUtils _SCSIM_array_int_4_Utils = {array_int_4_to_string,
	check_array_int_4_string,
	string_to_array_int_4,
	is_array_int_4_allow_double_convertion,
	0,
	compare_array_int_4_type,
	get_array_int_4_signature,
	get_array_int_4_filter_utils,
	array_int_4_filter_size,
	array_int_4_filter_values};
TypeUtils _SCSIM_array_int_1_Utils = {array_int_1_to_string,
	check_array_int_1_string,
	string_to_array_int_1,
	is_array_int_1_allow_double_convertion,
	0,
	compare_array_int_1_type,
	get_array_int_1_signature,
	get_array_int_1_filter_utils,
	array_int_1_filter_size,
	array_int_1_filter_values};
TypeUtils _SCSIM_array_int_5_Utils = {array_int_5_to_string,
	check_array_int_5_string,
	string_to_array_int_5,
	is_array_int_5_allow_double_convertion,
	0,
	compare_array_int_5_type,
	get_array_int_5_signature,
	get_array_int_5_filter_utils,
	array_int_5_filter_size,
	array_int_5_filter_values};
TypeUtils _SCSIM_array_int_229_Utils = {array_int_229_to_string,
	check_array_int_229_string,
	string_to_array_int_229,
	is_array_int_229_allow_double_convertion,
	0,
	compare_array_int_229_type,
	get_array_int_229_signature,
	get_array_int_229_filter_utils,
	array_int_229_filter_size,
	array_int_229_filter_values};
TypeUtils _SCSIM_array__5705_Utils = {array__5705_to_string,
	check_array__5705_string,
	string_to_array__5705,
	is_array__5705_allow_double_convertion,
	0,
	compare_array__5705_type,
	get_array__5705_signature,
	get_array__5705_filter_utils,
	array__5705_filter_size,
	array__5705_filter_values};
TypeUtils _SCSIM_array_int_30_Utils = {array_int_30_to_string,
	check_array_int_30_string,
	string_to_array_int_30,
	is_array_int_30_allow_double_convertion,
	0,
	compare_array_int_30_type,
	get_array_int_30_signature,
	get_array_int_30_filter_utils,
	array_int_30_filter_size,
	array_int_30_filter_values};
TypeUtils _SCSIM_array_int_33_Utils = {array_int_33_to_string,
	check_array_int_33_string,
	string_to_array_int_33,
	is_array_int_33_allow_double_convertion,
	0,
	compare_array_int_33_type,
	get_array_int_33_signature,
	get_array_int_33_filter_utils,
	array_int_33_filter_size,
	array_int_33_filter_values};
TypeUtils _SCSIM_array_int_224_33_Utils = {array_int_224_33_to_string,
	check_array_int_224_33_string,
	string_to_array_int_224_33,
	is_array_int_224_33_allow_double_convertion,
	0,
	compare_array_int_224_33_type,
	get_array_int_224_33_signature,
	get_array_int_224_33_filter_utils,
	array_int_224_33_filter_size,
	array_int_224_33_filter_values};
TypeUtils _SCSIM_array__5717_Utils = {array__5717_to_string,
	check_array__5717_string,
	string_to_array__5717,
	is_array__5717_allow_double_convertion,
	0,
	compare_array__5717_type,
	get_array__5717_signature,
	get_array__5717_filter_utils,
	array__5717_filter_size,
	array__5717_filter_values};
TypeUtils _SCSIM_array__5720_Utils = {array__5720_to_string,
	check_array__5720_string,
	string_to_array__5720,
	is_array__5720_allow_double_convertion,
	0,
	compare_array__5720_type,
	get_array__5720_signature,
	get_array__5720_filter_utils,
	array__5720_filter_size,
	array__5720_filter_values};
TypeUtils _SCSIM_array__5723_Utils = {array__5723_to_string,
	check_array__5723_string,
	string_to_array__5723,
	is_array__5723_allow_double_convertion,
	0,
	compare_array__5723_type,
	get_array__5723_signature,
	get_array__5723_filter_utils,
	array__5723_filter_size,
	array__5723_filter_values};
TypeUtils _SCSIM_NID_PACKET_Utils = {NID_PACKET_to_string,
	check_NID_PACKET_string,
	string_to_NID_PACKET,
	is_NID_PACKET_allow_double_convertion,
	NID_PACKET_to_double,
	compare_NID_PACKET_type,
	get_NID_PACKET_signature,
	get_NID_PACKET_filter_utils,
	NID_PACKET_filter_size,
	NID_PACKET_filter_values};
TypeUtils _SCSIM_Q_DIR_Utils = {Q_DIR_to_string,
	check_Q_DIR_string,
	string_to_Q_DIR,
	is_Q_DIR_allow_double_convertion,
	Q_DIR_to_double,
	compare_Q_DIR_type,
	get_Q_DIR_signature,
	get_Q_DIR_filter_utils,
	Q_DIR_filter_size,
	Q_DIR_filter_values};
TypeUtils _SCSIM_Q_UPDOWN_Utils = {Q_UPDOWN_to_string,
	check_Q_UPDOWN_string,
	string_to_Q_UPDOWN,
	is_Q_UPDOWN_allow_double_convertion,
	Q_UPDOWN_to_double,
	compare_Q_UPDOWN_type,
	get_Q_UPDOWN_signature,
	get_Q_UPDOWN_filter_utils,
	Q_UPDOWN_filter_size,
	Q_UPDOWN_filter_values};
TypeUtils _SCSIM_M_VERSION_Utils = {M_VERSION_to_string,
	check_M_VERSION_string,
	string_to_M_VERSION,
	is_M_VERSION_allow_double_convertion,
	M_VERSION_to_double,
	compare_M_VERSION_type,
	get_M_VERSION_signature,
	get_M_VERSION_filter_utils,
	M_VERSION_filter_size,
	M_VERSION_filter_values};
TypeUtils _SCSIM_Q_MEDIA_Utils = {Q_MEDIA_to_string,
	check_Q_MEDIA_string,
	string_to_Q_MEDIA,
	is_Q_MEDIA_allow_double_convertion,
	Q_MEDIA_to_double,
	compare_Q_MEDIA_type,
	get_Q_MEDIA_signature,
	get_Q_MEDIA_filter_utils,
	Q_MEDIA_filter_size,
	Q_MEDIA_filter_values};
TypeUtils _SCSIM_N_PIG_Utils = {N_PIG_to_string,
	check_N_PIG_string,
	string_to_N_PIG,
	is_N_PIG_allow_double_convertion,
	N_PIG_to_double,
	compare_N_PIG_type,
	get_N_PIG_signature,
	get_N_PIG_filter_utils,
	N_PIG_filter_size,
	N_PIG_filter_values};
TypeUtils _SCSIM_N_TOTAL_Utils = {N_TOTAL_to_string,
	check_N_TOTAL_string,
	string_to_N_TOTAL,
	is_N_TOTAL_allow_double_convertion,
	N_TOTAL_to_double,
	compare_N_TOTAL_type,
	get_N_TOTAL_signature,
	get_N_TOTAL_filter_utils,
	N_TOTAL_filter_size,
	N_TOTAL_filter_values};
TypeUtils _SCSIM_M_DUP_Utils = {M_DUP_to_string,
	check_M_DUP_string,
	string_to_M_DUP,
	is_M_DUP_allow_double_convertion,
	M_DUP_to_double,
	compare_M_DUP_type,
	get_M_DUP_signature,
	get_M_DUP_filter_utils,
	M_DUP_filter_size,
	M_DUP_filter_values};
TypeUtils _SCSIM_M_MCOUNT_Utils = {M_MCOUNT_to_string,
	check_M_MCOUNT_string,
	string_to_M_MCOUNT,
	is_M_MCOUNT_allow_double_convertion,
	M_MCOUNT_to_double,
	compare_M_MCOUNT_type,
	get_M_MCOUNT_signature,
	get_M_MCOUNT_filter_utils,
	M_MCOUNT_filter_size,
	M_MCOUNT_filter_values};
TypeUtils _SCSIM_NID_C_Utils = {NID_C_to_string,
	check_NID_C_string,
	string_to_NID_C,
	is_NID_C_allow_double_convertion,
	NID_C_to_double,
	compare_NID_C_type,
	get_NID_C_signature,
	get_NID_C_filter_utils,
	NID_C_filter_size,
	NID_C_filter_values};
TypeUtils _SCSIM_NID_BG_Utils = {NID_BG_to_string,
	check_NID_BG_string,
	string_to_NID_BG,
	is_NID_BG_allow_double_convertion,
	NID_BG_to_double,
	compare_NID_BG_type,
	get_NID_BG_signature,
	get_NID_BG_filter_utils,
	NID_BG_filter_size,
	NID_BG_filter_values};
TypeUtils _SCSIM_Q_LINK_Utils = {Q_LINK_to_string,
	check_Q_LINK_string,
	string_to_Q_LINK,
	is_Q_LINK_allow_double_convertion,
	Q_LINK_to_double,
	compare_Q_LINK_type,
	get_Q_LINK_signature,
	get_Q_LINK_filter_utils,
	Q_LINK_filter_size,
	Q_LINK_filter_values};
TypeUtils _SCSIM_Q_SCALE_Utils = {Q_SCALE_to_string,
	check_Q_SCALE_string,
	string_to_Q_SCALE,
	is_Q_SCALE_allow_double_convertion,
	Q_SCALE_to_double,
	compare_Q_SCALE_type,
	get_Q_SCALE_signature,
	get_Q_SCALE_filter_utils,
	Q_SCALE_filter_size,
	Q_SCALE_filter_values};
TypeUtils _SCSIM_D_LINK_Utils = {D_LINK_to_string,
	check_D_LINK_string,
	string_to_D_LINK,
	is_D_LINK_allow_double_convertion,
	D_LINK_to_double,
	compare_D_LINK_type,
	get_D_LINK_signature,
	get_D_LINK_filter_utils,
	D_LINK_filter_size,
	D_LINK_filter_values};
TypeUtils _SCSIM_Q_NEWCOUNTRY_Utils = {Q_NEWCOUNTRY_to_string,
	check_Q_NEWCOUNTRY_string,
	string_to_Q_NEWCOUNTRY,
	is_Q_NEWCOUNTRY_allow_double_convertion,
	Q_NEWCOUNTRY_to_double,
	compare_Q_NEWCOUNTRY_type,
	get_Q_NEWCOUNTRY_signature,
	get_Q_NEWCOUNTRY_filter_utils,
	Q_NEWCOUNTRY_filter_size,
	Q_NEWCOUNTRY_filter_values};
TypeUtils _SCSIM_Q_LINKORIENTATION_Utils = {Q_LINKORIENTATION_to_string,
	check_Q_LINKORIENTATION_string,
	string_to_Q_LINKORIENTATION,
	is_Q_LINKORIENTATION_allow_double_convertion,
	Q_LINKORIENTATION_to_double,
	compare_Q_LINKORIENTATION_type,
	get_Q_LINKORIENTATION_signature,
	get_Q_LINKORIENTATION_filter_utils,
	Q_LINKORIENTATION_filter_size,
	Q_LINKORIENTATION_filter_values};
TypeUtils _SCSIM_Q_LINKREACTION_Utils = {Q_LINKREACTION_to_string,
	check_Q_LINKREACTION_string,
	string_to_Q_LINKREACTION,
	is_Q_LINKREACTION_allow_double_convertion,
	Q_LINKREACTION_to_double,
	compare_Q_LINKREACTION_type,
	get_Q_LINKREACTION_signature,
	get_Q_LINKREACTION_filter_utils,
	Q_LINKREACTION_filter_size,
	Q_LINKREACTION_filter_values};
TypeUtils _SCSIM_Q_LOCACC_Utils = {Q_LOCACC_to_string,
	check_Q_LOCACC_string,
	string_to_Q_LOCACC,
	is_Q_LOCACC_allow_double_convertion,
	Q_LOCACC_to_double,
	compare_Q_LOCACC_type,
	get_Q_LOCACC_signature,
	get_Q_LOCACC_filter_utils,
	Q_LOCACC_filter_size,
	Q_LOCACC_filter_values};
TypeUtils _SCSIM_N_ITER_Utils = {N_ITER_to_string,
	check_N_ITER_string,
	string_to_N_ITER,
	is_N_ITER_allow_double_convertion,
	N_ITER_to_double,
	compare_N_ITER_type,
	get_N_ITER_signature,
	get_N_ITER_filter_utils,
	N_ITER_filter_size,
	N_ITER_filter_values};
TypeUtils _SCSIM_L_PACKET_Utils = {L_PACKET_to_string,
	check_L_PACKET_string,
	string_to_L_PACKET,
	is_L_PACKET_allow_double_convertion,
	L_PACKET_to_double,
	compare_L_PACKET_type,
	get_L_PACKET_signature,
	get_L_PACKET_filter_utils,
	L_PACKET_filter_size,
	L_PACKET_filter_values};
TypeUtils _SCSIM_NID_LRBG_Utils = {NID_LRBG_to_string,
	check_NID_LRBG_string,
	string_to_NID_LRBG,
	is_NID_LRBG_allow_double_convertion,
	NID_LRBG_to_double,
	compare_NID_LRBG_type,
	get_NID_LRBG_signature,
	get_NID_LRBG_filter_utils,
	NID_LRBG_filter_size,
	NID_LRBG_filter_values};
TypeUtils _SCSIM_B_data_internal_FirstTest_InfraLibInt_Utils = {B_data_internal_FirstTest_InfraLibInt_to_string,
	check_B_data_internal_FirstTest_InfraLibInt_string,
	string_to_B_data_internal_FirstTest_InfraLibInt,
	is_B_data_internal_FirstTest_InfraLibInt_allow_double_convertion,
	B_data_internal_FirstTest_InfraLibInt_to_double,
	compare_B_data_internal_FirstTest_InfraLibInt_type,
	get_B_data_internal_FirstTest_InfraLibInt_signature,
	get_B_data_internal_FirstTest_InfraLibInt_filter_utils,
	B_data_internal_FirstTest_InfraLibInt_filter_size,
	B_data_internal_FirstTest_InfraLibInt_filter_values};
TypeUtils _SCSIM_CompressedBaliseMessage_TM_Utils = {CompressedBaliseMessage_TM_to_string,
	check_CompressedBaliseMessage_TM_string,
	string_to_CompressedBaliseMessage_TM,
	is_CompressedBaliseMessage_TM_allow_double_convertion,
	CompressedBaliseMessage_TM_to_double,
	compare_CompressedBaliseMessage_TM_type,
	get_CompressedBaliseMessage_TM_signature,
	get_CompressedBaliseMessage_TM_filter_utils,
	CompressedBaliseMessage_TM_filter_size,
	CompressedBaliseMessage_TM_filter_values};
TypeUtils _SCSIM_BaliseTelegramHeader_int_T_TM_Utils = {BaliseTelegramHeader_int_T_TM_to_string,
	check_BaliseTelegramHeader_int_T_TM_string,
	string_to_BaliseTelegramHeader_int_T_TM,
	is_BaliseTelegramHeader_int_T_TM_allow_double_convertion,
	BaliseTelegramHeader_int_T_TM_to_double,
	compare_BaliseTelegramHeader_int_T_TM_type,
	get_BaliseTelegramHeader_int_T_TM_signature,
	get_BaliseTelegramHeader_int_T_TM_filter_utils,
	BaliseTelegramHeader_int_T_TM_filter_size,
	BaliseTelegramHeader_int_T_TM_filter_values};
TypeUtils _SCSIM_OrBG_TM_Utils = {OrBG_TM_to_string,
	check_OrBG_TM_string,
	string_to_OrBG_TM,
	is_OrBG_TM_allow_double_convertion,
	OrBG_TM_to_double,
	compare_OrBG_TM_type,
	get_OrBG_TM_signature,
	get_OrBG_TM_filter_utils,
	OrBG_TM_filter_size,
	OrBG_TM_filter_values};
TypeUtils _SCSIM_OrLine_TM_Utils = {OrLine_TM_to_string,
	check_OrLine_TM_string,
	string_to_OrLine_TM,
	is_OrLine_TM_allow_double_convertion,
	OrLine_TM_to_double,
	compare_OrLine_TM_type,
	get_OrLine_TM_signature,
	get_OrLine_TM_filter_utils,
	OrLine_TM_filter_size,
	OrLine_TM_filter_values};
TypeUtils _SCSIM_P005_trackside_int_T_TM_Utils = {P005_trackside_int_T_TM_to_string,
	check_P005_trackside_int_T_TM_string,
	string_to_P005_trackside_int_T_TM,
	is_P005_trackside_int_T_TM_allow_double_convertion,
	P005_trackside_int_T_TM_to_double,
	compare_P005_trackside_int_T_TM_type,
	get_P005_trackside_int_T_TM_signature,
	get_P005_trackside_int_T_TM_filter_utils,
	P005_trackside_int_T_TM_filter_size,
	P005_trackside_int_T_TM_filter_values};
TypeUtils _SCSIM_P005_trackide_sectionlist_T_TM_Utils = {P005_trackide_sectionlist_T_TM_to_string,
	check_P005_trackide_sectionlist_T_TM_string,
	string_to_P005_trackide_sectionlist_T_TM,
	is_P005_trackide_sectionlist_T_TM_allow_double_convertion,
	P005_trackide_sectionlist_T_TM_to_double,
	compare_P005_trackide_sectionlist_T_TM_type,
	get_P005_trackide_sectionlist_T_TM_signature,
	get_P005_trackide_sectionlist_T_TM_filter_utils,
	P005_trackide_sectionlist_T_TM_filter_size,
	P005_trackide_sectionlist_T_TM_filter_values};
TypeUtils _SCSIM_P005_section_int_T_TM_Utils = {P005_section_int_T_TM_to_string,
	check_P005_section_int_T_TM_string,
	string_to_P005_section_int_T_TM,
	is_P005_section_int_T_TM_allow_double_convertion,
	P005_section_int_T_TM_to_double,
	compare_P005_section_int_T_TM_type,
	get_P005_section_int_T_TM_signature,
	get_P005_section_int_T_TM_filter_utils,
	P005_section_int_T_TM_filter_size,
	P005_section_int_T_TM_filter_values};
TypeUtils _SCSIM_P005_sections_array_flat_T_TM_Utils = {P005_sections_array_flat_T_TM_to_string,
	check_P005_sections_array_flat_T_TM_string,
	string_to_P005_sections_array_flat_T_TM,
	is_P005_sections_array_flat_T_TM_allow_double_convertion,
	P005_sections_array_flat_T_TM_to_double,
	compare_P005_sections_array_flat_T_TM_type,
	get_P005_sections_array_flat_T_TM_signature,
	get_P005_sections_array_flat_T_TM_filter_utils,
	P005_sections_array_flat_T_TM_filter_size,
	P005_sections_array_flat_T_TM_filter_values};
TypeUtils _SCSIM_P005_OBU_sectionlist_array_T_TM_Utils = {P005_OBU_sectionlist_array_T_TM_to_string,
	check_P005_OBU_sectionlist_array_T_TM_string,
	string_to_P005_OBU_sectionlist_array_T_TM,
	is_P005_OBU_sectionlist_array_T_TM_allow_double_convertion,
	P005_OBU_sectionlist_array_T_TM_to_double,
	compare_P005_OBU_sectionlist_array_T_TM_type,
	get_P005_OBU_sectionlist_array_T_TM_signature,
	get_P005_OBU_sectionlist_array_T_TM_filter_utils,
	P005_OBU_sectionlist_array_T_TM_filter_size,
	P005_OBU_sectionlist_array_T_TM_filter_values};
TypeUtils _SCSIM_P005_section_array_T_TM_Utils = {P005_section_array_T_TM_to_string,
	check_P005_section_array_T_TM_string,
	string_to_P005_section_array_T_TM,
	is_P005_section_array_T_TM_allow_double_convertion,
	P005_section_array_T_TM_to_double,
	compare_P005_section_array_T_TM_type,
	get_P005_section_array_T_TM_signature,
	get_P005_section_array_T_TM_filter_utils,
	P005_section_array_T_TM_filter_size,
	P005_section_array_T_TM_filter_values};
TypeUtils _SCSIM_P005_OBU_sectionlist_int_T_TM_Utils = {P005_OBU_sectionlist_int_T_TM_to_string,
	check_P005_OBU_sectionlist_int_T_TM_string,
	string_to_P005_OBU_sectionlist_int_T_TM,
	is_P005_OBU_sectionlist_int_T_TM_allow_double_convertion,
	P005_OBU_sectionlist_int_T_TM_to_double,
	compare_P005_OBU_sectionlist_int_T_TM_type,
	get_P005_OBU_sectionlist_int_T_TM_signature,
	get_P005_OBU_sectionlist_int_T_TM_filter_utils,
	P005_OBU_sectionlist_int_T_TM_filter_size,
	P005_OBU_sectionlist_int_T_TM_filter_values};
TypeUtils _SCSIM_BaliseGroupData_TM_Utils = {BaliseGroupData_TM_to_string,
	check_BaliseGroupData_TM_string,
	string_to_BaliseGroupData_TM,
	is_BaliseGroupData_TM_allow_double_convertion,
	BaliseGroupData_TM_to_double,
	compare_BaliseGroupData_TM_type,
	get_BaliseGroupData_TM_signature,
	get_BaliseGroupData_TM_filter_utils,
	BaliseGroupData_TM_filter_size,
	BaliseGroupData_TM_filter_values};
TypeUtils _SCSIM_P005_section_enum_T_TM_Utils = {P005_section_enum_T_TM_to_string,
	check_P005_section_enum_T_TM_string,
	string_to_P005_section_enum_T_TM,
	is_P005_section_enum_T_TM_allow_double_convertion,
	P005_section_enum_T_TM_to_double,
	compare_P005_section_enum_T_TM_type,
	get_P005_section_enum_T_TM_signature,
	get_P005_section_enum_T_TM_filter_utils,
	P005_section_enum_T_TM_filter_size,
	P005_section_enum_T_TM_filter_values};
TypeUtils _SCSIM_P005_OBU_sectionlist_enum_T_TM_Utils = {P005_OBU_sectionlist_enum_T_TM_to_string,
	check_P005_OBU_sectionlist_enum_T_TM_string,
	string_to_P005_OBU_sectionlist_enum_T_TM,
	is_P005_OBU_sectionlist_enum_T_TM_allow_double_convertion,
	P005_OBU_sectionlist_enum_T_TM_to_double,
	compare_P005_OBU_sectionlist_enum_T_TM_type,
	get_P005_OBU_sectionlist_enum_T_TM_signature,
	get_P005_OBU_sectionlist_enum_T_TM_filter_utils,
	P005_OBU_sectionlist_enum_T_TM_filter_size,
	P005_OBU_sectionlist_enum_T_TM_filter_values};
TypeUtils _SCSIM_P005_OBU_T_TM_Utils = {P005_OBU_T_TM_to_string,
	check_P005_OBU_T_TM_string,
	string_to_P005_OBU_T_TM,
	is_P005_OBU_T_TM_allow_double_convertion,
	P005_OBU_T_TM_to_double,
	compare_P005_OBU_T_TM_type,
	get_P005_OBU_T_TM_signature,
	get_P005_OBU_T_TM_filter_utils,
	P005_OBU_T_TM_filter_size,
	P005_OBU_T_TM_filter_values};
TypeUtils _SCSIM_Array03_TM_Utils = {Array03_TM_to_string,
	check_Array03_TM_string,
	string_to_Array03_TM,
	is_Array03_TM_allow_double_convertion,
	Array03_TM_to_double,
	compare_Array03_TM_type,
	get_Array03_TM_signature,
	get_Array03_TM_filter_utils,
	Array03_TM_filter_size,
	Array03_TM_filter_values};
TypeUtils _SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils = {CompressedPackets_T_Common_Types_Pkg_to_string,
	check_CompressedPackets_T_Common_Types_Pkg_string,
	string_to_CompressedPackets_T_Common_Types_Pkg,
	is_CompressedPackets_T_Common_Types_Pkg_allow_double_convertion,
	CompressedPackets_T_Common_Types_Pkg_to_double,
	compare_CompressedPackets_T_Common_Types_Pkg_type,
	get_CompressedPackets_T_Common_Types_Pkg_signature,
	get_CompressedPackets_T_Common_Types_Pkg_filter_utils,
	CompressedPackets_T_Common_Types_Pkg_filter_size,
	CompressedPackets_T_Common_Types_Pkg_filter_values};
TypeUtils _SCSIM_Metadata_T_Common_Types_Pkg_Utils = {Metadata_T_Common_Types_Pkg_to_string,
	check_Metadata_T_Common_Types_Pkg_string,
	string_to_Metadata_T_Common_Types_Pkg,
	is_Metadata_T_Common_Types_Pkg_allow_double_convertion,
	Metadata_T_Common_Types_Pkg_to_double,
	compare_Metadata_T_Common_Types_Pkg_type,
	get_Metadata_T_Common_Types_Pkg_signature,
	get_Metadata_T_Common_Types_Pkg_filter_utils,
	Metadata_T_Common_Types_Pkg_filter_size,
	Metadata_T_Common_Types_Pkg_filter_values};
TypeUtils _SCSIM_MetadataElement_T_Common_Types_Pkg_Utils = {MetadataElement_T_Common_Types_Pkg_to_string,
	check_MetadataElement_T_Common_Types_Pkg_string,
	string_to_MetadataElement_T_Common_Types_Pkg,
	is_MetadataElement_T_Common_Types_Pkg_allow_double_convertion,
	MetadataElement_T_Common_Types_Pkg_to_double,
	compare_MetadataElement_T_Common_Types_Pkg_type,
	get_MetadataElement_T_Common_Types_Pkg_signature,
	get_MetadataElement_T_Common_Types_Pkg_filter_utils,
	MetadataElement_T_Common_Types_Pkg_filter_size,
	MetadataElement_T_Common_Types_Pkg_filter_values};
TypeUtils _SCSIM_CompressedPacketData_T_Common_Types_Pkg_Utils = {CompressedPacketData_T_Common_Types_Pkg_to_string,
	check_CompressedPacketData_T_Common_Types_Pkg_string,
	string_to_CompressedPacketData_T_Common_Types_Pkg,
	is_CompressedPacketData_T_Common_Types_Pkg_allow_double_convertion,
	CompressedPacketData_T_Common_Types_Pkg_to_double,
	compare_CompressedPacketData_T_Common_Types_Pkg_type,
	get_CompressedPacketData_T_Common_Types_Pkg_signature,
	get_CompressedPacketData_T_Common_Types_Pkg_filter_utils,
	CompressedPacketData_T_Common_Types_Pkg_filter_size,
	CompressedPacketData_T_Common_Types_Pkg_filter_values};
TypeUtils _SCSIM_BaliseGroupData_Basics_Utils = {BaliseGroupData_Basics_to_string,
	check_BaliseGroupData_Basics_string,
	string_to_BaliseGroupData_Basics,
	is_BaliseGroupData_Basics_allow_double_convertion,
	BaliseGroupData_Basics_to_double,
	compare_BaliseGroupData_Basics_type,
	get_BaliseGroupData_Basics_signature,
	get_BaliseGroupData_Basics_filter_utils,
	BaliseGroupData_Basics_filter_size,
	BaliseGroupData_Basics_filter_values};
TypeUtils _SCSIM_B_data_internal_T_InfraLib_Utils = {B_data_internal_T_InfraLib_to_string,
	check_B_data_internal_T_InfraLib_string,
	string_to_B_data_internal_T_InfraLib,
	is_B_data_internal_T_InfraLib_allow_double_convertion,
	B_data_internal_T_InfraLib_to_double,
	compare_B_data_internal_T_InfraLib_type,
	get_B_data_internal_T_InfraLib_signature,
	get_B_data_internal_T_InfraLib_filter_utils,
	B_data_internal_T_InfraLib_filter_size,
	B_data_internal_T_InfraLib_filter_values};
TypeUtils _SCSIM_TelegramHeader_T_BG_Types_Pkg_Utils = {TelegramHeader_T_BG_Types_Pkg_to_string,
	check_TelegramHeader_T_BG_Types_Pkg_string,
	string_to_TelegramHeader_T_BG_Types_Pkg,
	is_TelegramHeader_T_BG_Types_Pkg_allow_double_convertion,
	TelegramHeader_T_BG_Types_Pkg_to_double,
	compare_TelegramHeader_T_BG_Types_Pkg_type,
	get_TelegramHeader_T_BG_Types_Pkg_signature,
	get_TelegramHeader_T_BG_Types_Pkg_filter_utils,
	TelegramHeader_T_BG_Types_Pkg_filter_size,
	TelegramHeader_T_BG_Types_Pkg_filter_values};
TypeUtils _SCSIM_LinkedBG_T_BG_Types_Pkg_Utils = {LinkedBG_T_BG_Types_Pkg_to_string,
	check_LinkedBG_T_BG_Types_Pkg_string,
	string_to_LinkedBG_T_BG_Types_Pkg,
	is_LinkedBG_T_BG_Types_Pkg_allow_double_convertion,
	LinkedBG_T_BG_Types_Pkg_to_double,
	compare_LinkedBG_T_BG_Types_Pkg_type,
	get_LinkedBG_T_BG_Types_Pkg_signature,
	get_LinkedBG_T_BG_Types_Pkg_filter_utils,
	LinkedBG_T_BG_Types_Pkg_filter_size,
	LinkedBG_T_BG_Types_Pkg_filter_values};
TypeUtils _SCSIM_LinkedBGs_T_BG_Types_Pkg_Utils = {LinkedBGs_T_BG_Types_Pkg_to_string,
	check_LinkedBGs_T_BG_Types_Pkg_string,
	string_to_LinkedBGs_T_BG_Types_Pkg,
	is_LinkedBGs_T_BG_Types_Pkg_allow_double_convertion,
	LinkedBGs_T_BG_Types_Pkg_to_double,
	compare_LinkedBGs_T_BG_Types_Pkg_type,
	get_LinkedBGs_T_BG_Types_Pkg_signature,
	get_LinkedBGs_T_BG_Types_Pkg_filter_utils,
	LinkedBGs_T_BG_Types_Pkg_filter_size,
	LinkedBGs_T_BG_Types_Pkg_filter_values};

/****************************************************************
 ** kcg_real
 ****************************************************************/
struct SimTypeVTable* pSimDoubleVTable;
const char * kcg_real_to_string(const void* pValue) {
	if (pSimDoubleVTable != 0 && pSimDoubleVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		double value = (double)(*(const kcg_real*)pValue);
		return *(char**)pSimDoubleVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnRealToString((double)(*(const kcg_real*)pValue));
}

int string_to_kcg_real(const char* strValue, void* pValue) {
	double nTemp = 0;
	static double rTemp;
	int nResult;
	if (pSimDoubleVTable != 0 && pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimDoubleVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*(kcg_real*)pValue = (kcg_real)rTemp;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToReal(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_real*)pValue = (kcg_real)nTemp;
	return nResult;
}

int compare_kcg_real_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_real rTemp;
	const kcg_real* pCurrent = (const kcg_real*)pValue;
	if (string_to_kcg_real(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_real_allow_double_convertion() {
	if (pSimDoubleVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_real_to_double(double * nValue, const void* pValue) {
	if (pSimDoubleVTable != 0) {
		double value = (double)(*(const kcg_real*)pValue);
		if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimDoubleVTable->m_pfnToType(SptDouble, &value));
		else if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimDoubleVTable->m_pfnToType(SptFloat, &value));
		else if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimDoubleVTable->m_pfnToType(SptLong, &value));
		else if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimDoubleVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = (double)*((const kcg_real*)pValue);
	return 1;
}

const char * get_kcg_real_signature() {
	return "R";
}

int check_kcg_real_string(const char* strValue) {
	static kcg_real rTemp;
	return string_to_kcg_real(strValue, &rTemp);
}


/****************************************************************
 ** kcg_bool
 ****************************************************************/
struct SimTypeVTable* pSimBoolVTable;
const char * kcg_bool_to_string(const void* pValue) {
	if (pSimBoolVTable != 0 && pSimBoolVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
		return *(char**)pSimBoolVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnBoolToString((*(const kcg_bool*)pValue) == kcg_true ? 1 : 0);
}

int string_to_kcg_bool(const char* strValue, void* pValue) {
	int nTemp = 0;
	static SimBool rTemp;
	int nResult;
	if (pSimBoolVTable != 0 && pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimBoolVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((kcg_bool*)pValue) = (rTemp == SbTrue)? kcg_true : kcg_false;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToBool(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_bool*)pValue = nTemp == 1 ? kcg_true : kcg_false;
	return nResult;
}

int compare_kcg_bool_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_bool rTemp;
	const kcg_bool* pCurrent = (const kcg_bool*)pValue;
	if (string_to_kcg_bool(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_bool_allow_double_convertion() {
	if (pSimBoolVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_bool_to_double(double * nValue, const void* pValue) {
	if (pSimBoolVTable != 0) {
		SimBool value = (*(const kcg_bool*)pValue == kcg_true)? SbTrue : SbFalse;
		if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimBoolVTable->m_pfnToType(SptDouble, &value));
		else if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimBoolVTable->m_pfnToType(SptFloat, &value));
		else if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimBoolVTable->m_pfnToType(SptLong, &value));
		else if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimBoolVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = *((const kcg_bool*)pValue) == kcg_true ? 1.0 : 0.0;
	return 1;
}

const char * get_kcg_bool_signature() {
	return "B";
}

int check_kcg_bool_string(const char* strValue) {
	static kcg_bool rTemp;
	return string_to_kcg_bool(strValue, &rTemp);
}


/****************************************************************
 ** kcg_char
 ****************************************************************/
struct SimTypeVTable* pSimCharVTable;
const char * kcg_char_to_string(const void* pValue) {
	if (pSimCharVTable != 0 && pSimCharVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		char value = (char)(*(const kcg_char*)pValue);
		return *(char**)pSimCharVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnCharToString((char)(*(const kcg_char*)pValue));
}

int string_to_kcg_char(const char* strValue, void* pValue) {
	char nTemp = 0;
	static char rTemp;
	int nResult;
	if (pSimCharVTable != 0 && pSimCharVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimCharVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*(kcg_char*)pValue = (kcg_char)rTemp;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToChar(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_char*)pValue = (kcg_char)nTemp;
	return nResult;
}

int compare_kcg_char_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_char rTemp;
	const kcg_char* pCurrent = (const kcg_char*)pValue;
	if (string_to_kcg_char(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_char_allow_double_convertion() {
	if (pSimCharVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_char_to_double(double * nValue, const void* pValue) {
	if (pSimCharVTable != 0) {
		char value = (char)(*(const kcg_char*)pValue);
		if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimCharVTable->m_pfnToType(SptDouble, &value));
		else if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimCharVTable->m_pfnToType(SptFloat, &value));
		else if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimCharVTable->m_pfnToType(SptLong, &value));
		else if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimCharVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = (double)*((const kcg_char*)pValue);
	return 1;
}

const char * get_kcg_char_signature() {
	return "C";
}

int check_kcg_char_string(const char* strValue) {
	static kcg_char rTemp;
	return string_to_kcg_char(strValue, &rTemp);
}


/****************************************************************
 ** kcg_int
 ****************************************************************/
struct SimTypeVTable* pSimLongVTable;
const char * kcg_int_to_string(const void* pValue) {
	if (pSimLongVTable != 0 && pSimLongVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		long value = (long)(*(const kcg_int*)pValue);
		return *(char**)pSimLongVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnIntToString(*(const int*)pValue);
}

int string_to_kcg_int(const char* strValue, void* pValue) {
	int nTemp = 0;
	static long rTemp;
	int nResult;
	if (pSimLongVTable != 0 && pSimLongVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimLongVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*(kcg_int*)pValue = (kcg_int)rTemp;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToInt(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_int*)pValue = (kcg_int)nTemp;
	return nResult;
}

int compare_kcg_int_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_int rTemp;
	const kcg_int* pCurrent = (const kcg_int*)pValue;
	if (string_to_kcg_int(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_int_allow_double_convertion() {
	if (pSimLongVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_int_to_double(double * nValue, const void* pValue) {
	if (pSimLongVTable != 0) {
		long value = (long)(*(const kcg_int*)pValue);
		if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimLongVTable->m_pfnToType(SptDouble, &value));
		else if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimLongVTable->m_pfnToType(SptFloat, &value));
		else if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimLongVTable->m_pfnToType(SptLong, &value));
		else if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimLongVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = (double)*((const kcg_int*)pValue);
	return 1;
}

const char * get_kcg_int_signature() {
	return "I";
}

int check_kcg_int_string(const char* strValue) {
	static kcg_int rTemp;
	return string_to_kcg_int(strValue, &rTemp);
}


/****************************************************************
 ** struct__5532
 ****************************************************************/
static void Fill_struct__5532_StructSimValue(struct__5532 * pStruct, StructSimValue * pValues) {
	/*valid label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->valid) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_bool_Utils;
	pValues[0].m_pszName = "valid";
	/*nid_LRBG label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->nid_LRBG) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[1].m_pszName = "nid_LRBG";
	/*q_dir label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->q_dir) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_Q_DIR_Utils;
	pValues[2].m_pszName = "q_dir";
	/*q_scale label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->q_scale) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_Q_SCALE_Utils;
	pValues[3].m_pszName = "q_scale";
	/*d_link label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->d_link) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "d_link";
	/*q_newcountry label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->q_newcountry) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_Q_NEWCOUNTRY_Utils;
	pValues[5].m_pszName = "q_newcountry";
	/*nid_c label.*/
	pValues[6].m_pPtr = pStruct != 0 ? &(pStruct->nid_c) : 0;
	pValues[6].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[6].m_pszName = "nid_c";
	/*nid_bg label.*/
	pValues[7].m_pPtr = pStruct != 0 ? &(pStruct->nid_bg) : 0;
	pValues[7].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[7].m_pszName = "nid_bg";
	/*q_linkorientation label.*/
	pValues[8].m_pPtr = pStruct != 0 ? &(pStruct->q_linkorientation) : 0;
	pValues[8].m_pTypeUtils = &_SCSIM_Q_LINKORIENTATION_Utils;
	pValues[8].m_pszName = "q_linkorientation";
	/*q_linkreaction label.*/
	pValues[9].m_pPtr = pStruct != 0 ? &(pStruct->q_linkreaction) : 0;
	pValues[9].m_pTypeUtils = &_SCSIM_Q_LINKREACTION_Utils;
	pValues[9].m_pszName = "q_linkreaction";
	/*q_locacc label.*/
	pValues[10].m_pPtr = pStruct != 0 ? &(pStruct->q_locacc) : 0;
	pValues[10].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[10].m_pszName = "q_locacc";
}

const char * struct__5532_to_string(const void* pValue) {
	static StructSimValue values[11];
	Fill_struct__5532_StructSimValue(((struct__5532*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 11);
}

int string_to_struct__5532(const char* strValue, void* pValue) {
	static struct__5532 rTemp;
	int nResult = 0;
	static StructSimValue values[11];
	kcg_copy_struct__5532(&(rTemp), &(*((struct__5532*)pValue)));
	Fill_struct__5532_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 11);
	if (nResult == 1)
		kcg_copy_struct__5532(&(*((struct__5532*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5532_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[11];
	Fill_struct__5532_StructSimValue((struct__5532*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 11);
}


int is_struct__5532_allow_double_convertion() {
	return 0;
}


const char * get_struct__5532_signature() {
	static StructSimValue values[11];
	Fill_struct__5532_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 11);
}

FilterUtils get_struct__5532_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[11];
	Fill_struct__5532_StructSimValue((struct__5532*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 11, strFilter);
}

const char * struct__5532_filter_values[11] = {"valid", "nid_LRBG", "q_dir", "q_scale", "d_link", "q_newcountry", "nid_c", "nid_bg", "q_linkorientation", "q_linkreaction", "q_locacc"};
int check_struct__5532_string(const char* strValue) {
	static struct__5532 rTemp;
	return string_to_struct__5532(strValue, &rTemp);
}


/****************************************************************
 ** array__5546
 ****************************************************************/
void* array__5546_projection(void** pValues, int nIndex) {
	return &((*(array__5546*)pValues)[nIndex]);
}

const char * array__5546_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__5532_to_string, 4, array__5546_projection);
}

int compare_array__5546_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__5532_type , 4, array__5546_projection);
}

int is_array__5546_allow_double_convertion() {
	return 0;
}

int string_to_array__5546(const char* strValue, void* pValue) {
	static array__5546 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__5532, 4, array__5546_projection);
	if (nResult == 1)
		kcg_copy_array__5546(&(*((array__5546*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5546_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__5532_signature, 4);
}

FilterUtils get_array__5546_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__5532_Utils, strFilter, (void**)pValue, 4, array__5546_projection);
}

int check_array__5546_string(const char* strValue) {
	static array__5546 rTemp;
	return string_to_array__5546(strValue, &rTemp);
}


/****************************************************************
 ** struct__5549
 ****************************************************************/
static void Fill_struct__5549_StructSimValue(struct__5549 * pStruct, StructSimValue * pValues) {
	/*q_updown label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->q_updown) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_Q_UPDOWN_Utils;
	pValues[0].m_pszName = "q_updown";
	/*m_version label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->m_version) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_M_VERSION_Utils;
	pValues[1].m_pszName = "m_version";
	/*q_media label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->q_media) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_Q_MEDIA_Utils;
	pValues[2].m_pszName = "q_media";
	/*n_pig label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->n_pig) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_N_PIG_Utils;
	pValues[3].m_pszName = "n_pig";
	/*n_total label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->n_total) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_N_TOTAL_Utils;
	pValues[4].m_pszName = "n_total";
	/*m_dup label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->m_dup) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_M_DUP_Utils;
	pValues[5].m_pszName = "m_dup";
	/*m_mcount label.*/
	pValues[6].m_pPtr = pStruct != 0 ? &(pStruct->m_mcount) : 0;
	pValues[6].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[6].m_pszName = "m_mcount";
	/*nid_c label.*/
	pValues[7].m_pPtr = pStruct != 0 ? &(pStruct->nid_c) : 0;
	pValues[7].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[7].m_pszName = "nid_c";
	/*nid_bg label.*/
	pValues[8].m_pPtr = pStruct != 0 ? &(pStruct->nid_bg) : 0;
	pValues[8].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[8].m_pszName = "nid_bg";
	/*q_link label.*/
	pValues[9].m_pPtr = pStruct != 0 ? &(pStruct->q_link) : 0;
	pValues[9].m_pTypeUtils = &_SCSIM_Q_LINK_Utils;
	pValues[9].m_pszName = "q_link";
}

const char * struct__5549_to_string(const void* pValue) {
	static StructSimValue values[10];
	Fill_struct__5549_StructSimValue(((struct__5549*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 10);
}

int string_to_struct__5549(const char* strValue, void* pValue) {
	static struct__5549 rTemp;
	int nResult = 0;
	static StructSimValue values[10];
	kcg_copy_struct__5549(&(rTemp), &(*((struct__5549*)pValue)));
	Fill_struct__5549_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 10);
	if (nResult == 1)
		kcg_copy_struct__5549(&(*((struct__5549*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5549_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[10];
	Fill_struct__5549_StructSimValue((struct__5549*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 10);
}


int is_struct__5549_allow_double_convertion() {
	return 0;
}


const char * get_struct__5549_signature() {
	static StructSimValue values[10];
	Fill_struct__5549_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 10);
}

FilterUtils get_struct__5549_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[10];
	Fill_struct__5549_StructSimValue((struct__5549*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 10, strFilter);
}

const char * struct__5549_filter_values[10] = {"q_updown", "m_version", "q_media", "n_pig", "n_total", "m_dup", "m_mcount", "nid_c", "nid_bg", "q_link"};
int check_struct__5549_string(const char* strValue) {
	static struct__5549 rTemp;
	return string_to_struct__5549(strValue, &rTemp);
}


/****************************************************************
 ** array_int_500
 ****************************************************************/
void* array_int_500_projection(void** pValues, int nIndex) {
	return &((*(array_int_500*)pValues)[nIndex]);
}

const char * array_int_500_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 500, array_int_500_projection);
}

int compare_array_int_500_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 500, array_int_500_projection);
}

int is_array_int_500_allow_double_convertion() {
	return 0;
}

int string_to_array_int_500(const char* strValue, void* pValue) {
	static array_int_500 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 500, array_int_500_projection);
	if (nResult == 1)
		kcg_copy_array_int_500(&(*((array_int_500*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_500_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 500);
}

FilterUtils get_array_int_500_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 500, array_int_500_projection);
}

int check_array_int_500_string(const char* strValue) {
	static array_int_500 rTemp;
	return string_to_array_int_500(strValue, &rTemp);
}


/****************************************************************
 ** struct__5565
 ****************************************************************/
static void Fill_struct__5565_StructSimValue(struct__5565 * pStruct, StructSimValue * pValues) {
	/*nid_packet label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->nid_packet) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[0].m_pszName = "nid_packet";
	/*q_dir label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->q_dir) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_Q_DIR_Utils;
	pValues[1].m_pszName = "q_dir";
	/*valid label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->valid) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_bool_Utils;
	pValues[2].m_pszName = "valid";
	/*startAddress label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->startAddress) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[3].m_pszName = "startAddress";
	/*endAddress label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->endAddress) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "endAddress";
}

const char * struct__5565_to_string(const void* pValue) {
	static StructSimValue values[5];
	Fill_struct__5565_StructSimValue(((struct__5565*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 5);
}

int string_to_struct__5565(const char* strValue, void* pValue) {
	static struct__5565 rTemp;
	int nResult = 0;
	static StructSimValue values[5];
	kcg_copy_struct__5565(&(rTemp), &(*((struct__5565*)pValue)));
	Fill_struct__5565_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 5);
	if (nResult == 1)
		kcg_copy_struct__5565(&(*((struct__5565*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5565_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[5];
	Fill_struct__5565_StructSimValue((struct__5565*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 5);
}


int is_struct__5565_allow_double_convertion() {
	return 0;
}


const char * get_struct__5565_signature() {
	static StructSimValue values[5];
	Fill_struct__5565_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 5);
}

FilterUtils get_struct__5565_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[5];
	Fill_struct__5565_StructSimValue((struct__5565*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 5, strFilter);
}

const char * struct__5565_filter_values[5] = {"nid_packet", "q_dir", "valid", "startAddress", "endAddress"};
int check_struct__5565_string(const char* strValue) {
	static struct__5565 rTemp;
	return string_to_struct__5565(strValue, &rTemp);
}


/****************************************************************
 ** array__5573
 ****************************************************************/
void* array__5573_projection(void** pValues, int nIndex) {
	return &((*(array__5573*)pValues)[nIndex]);
}

const char * array__5573_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__5565_to_string, 30, array__5573_projection);
}

int compare_array__5573_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__5565_type , 30, array__5573_projection);
}

int is_array__5573_allow_double_convertion() {
	return 0;
}

int string_to_array__5573(const char* strValue, void* pValue) {
	static array__5573 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__5565, 30, array__5573_projection);
	if (nResult == 1)
		kcg_copy_array__5573(&(*((array__5573*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5573_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__5565_signature, 30);
}

FilterUtils get_array__5573_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__5565_Utils, strFilter, (void**)pValue, 30, array__5573_projection);
}

int check_array__5573_string(const char* strValue) {
	static array__5573 rTemp;
	return string_to_array__5573(strValue, &rTemp);
}


/****************************************************************
 ** struct__5576
 ****************************************************************/
static void Fill_struct__5576_StructSimValue(struct__5576 * pStruct, StructSimValue * pValues) {
	/*PacketHeaders label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->PacketHeaders) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_array__5573_Utils;
	pValues[0].m_pszName = "PacketHeaders";
	/*PacketData label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->PacketData) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_array_int_500_Utils;
	pValues[1].m_pszName = "PacketData";
}

const char * struct__5576_to_string(const void* pValue) {
	static StructSimValue values[2];
	Fill_struct__5576_StructSimValue(((struct__5576*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 2);
}

int string_to_struct__5576(const char* strValue, void* pValue) {
	static struct__5576 rTemp;
	int nResult = 0;
	static StructSimValue values[2];
	kcg_copy_struct__5576(&(rTemp), &(*((struct__5576*)pValue)));
	Fill_struct__5576_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 2);
	if (nResult == 1)
		kcg_copy_struct__5576(&(*((struct__5576*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5576_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[2];
	Fill_struct__5576_StructSimValue((struct__5576*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 2);
}


int is_struct__5576_allow_double_convertion() {
	return 0;
}


const char * get_struct__5576_signature() {
	static StructSimValue values[2];
	Fill_struct__5576_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 2);
}

FilterUtils get_struct__5576_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[2];
	Fill_struct__5576_StructSimValue((struct__5576*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 2, strFilter);
}

const char * struct__5576_filter_values[2] = {"PacketHeaders", "PacketData"};
int check_struct__5576_string(const char* strValue) {
	static struct__5576 rTemp;
	return string_to_struct__5576(strValue, &rTemp);
}


/****************************************************************
 ** struct__5581
 ****************************************************************/
static void Fill_struct__5581_StructSimValue(struct__5581 * pStruct, StructSimValue * pValues) {
	/*valid label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->valid) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_bool_Utils;
	pValues[0].m_pszName = "valid";
	/*d_link label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->d_link) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[1].m_pszName = "d_link";
	/*q_newcountry label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->q_newcountry) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_Q_NEWCOUNTRY_Utils;
	pValues[2].m_pszName = "q_newcountry";
	/*nid_c label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->nid_c) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[3].m_pszName = "nid_c";
	/*nid_bg label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->nid_bg) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "nid_bg";
	/*q_linkorientation label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->q_linkorientation) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_Q_LINKORIENTATION_Utils;
	pValues[5].m_pszName = "q_linkorientation";
	/*q_linkreaction label.*/
	pValues[6].m_pPtr = pStruct != 0 ? &(pStruct->q_linkreaction) : 0;
	pValues[6].m_pTypeUtils = &_SCSIM_Q_LINKREACTION_Utils;
	pValues[6].m_pszName = "q_linkreaction";
	/*q_locacc label.*/
	pValues[7].m_pPtr = pStruct != 0 ? &(pStruct->q_locacc) : 0;
	pValues[7].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[7].m_pszName = "q_locacc";
}

const char * struct__5581_to_string(const void* pValue) {
	static StructSimValue values[8];
	Fill_struct__5581_StructSimValue(((struct__5581*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 8);
}

int string_to_struct__5581(const char* strValue, void* pValue) {
	static struct__5581 rTemp;
	int nResult = 0;
	static StructSimValue values[8];
	kcg_copy_struct__5581(&(rTemp), &(*((struct__5581*)pValue)));
	Fill_struct__5581_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 8);
	if (nResult == 1)
		kcg_copy_struct__5581(&(*((struct__5581*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5581_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[8];
	Fill_struct__5581_StructSimValue((struct__5581*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 8);
}


int is_struct__5581_allow_double_convertion() {
	return 0;
}


const char * get_struct__5581_signature() {
	static StructSimValue values[8];
	Fill_struct__5581_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 8);
}

FilterUtils get_struct__5581_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[8];
	Fill_struct__5581_StructSimValue((struct__5581*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 8, strFilter);
}

const char * struct__5581_filter_values[8] = {"valid", "d_link", "q_newcountry", "nid_c", "nid_bg", "q_linkorientation", "q_linkreaction", "q_locacc"};
int check_struct__5581_string(const char* strValue) {
	static struct__5581 rTemp;
	return string_to_struct__5581(strValue, &rTemp);
}


/****************************************************************
 ** array__5592
 ****************************************************************/
void* array__5592_projection(void** pValues, int nIndex) {
	return &((*(array__5592*)pValues)[nIndex]);
}

const char * array__5592_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__5581_to_string, 33, array__5592_projection);
}

int compare_array__5592_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__5581_type , 33, array__5592_projection);
}

int is_array__5592_allow_double_convertion() {
	return 0;
}

int string_to_array__5592(const char* strValue, void* pValue) {
	static array__5592 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__5581, 33, array__5592_projection);
	if (nResult == 1)
		kcg_copy_array__5592(&(*((array__5592*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5592_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__5581_signature, 33);
}

FilterUtils get_array__5592_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__5581_Utils, strFilter, (void**)pValue, 33, array__5592_projection);
}

int check_array__5592_string(const char* strValue) {
	static array__5592 rTemp;
	return string_to_array__5592(strValue, &rTemp);
}


/****************************************************************
 ** struct__5595
 ****************************************************************/
static void Fill_struct__5595_StructSimValue(struct__5595 * pStruct, StructSimValue * pValues) {
	/*valid label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->valid) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_bool_Utils;
	pValues[0].m_pszName = "valid";
	/*q_dir label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->q_dir) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_Q_DIR_Utils;
	pValues[1].m_pszName = "q_dir";
	/*l_packet label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->l_packet) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[2].m_pszName = "l_packet";
	/*q_scale label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->q_scale) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_Q_SCALE_Utils;
	pValues[3].m_pszName = "q_scale";
	/*n_iter label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->n_iter) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "n_iter";
	/*sections label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->sections) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_array__5592_Utils;
	pValues[5].m_pszName = "sections";
}

const char * struct__5595_to_string(const void* pValue) {
	static StructSimValue values[6];
	Fill_struct__5595_StructSimValue(((struct__5595*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 6);
}

int string_to_struct__5595(const char* strValue, void* pValue) {
	static struct__5595 rTemp;
	int nResult = 0;
	static StructSimValue values[6];
	kcg_copy_struct__5595(&(rTemp), &(*((struct__5595*)pValue)));
	Fill_struct__5595_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 6);
	if (nResult == 1)
		kcg_copy_struct__5595(&(*((struct__5595*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5595_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[6];
	Fill_struct__5595_StructSimValue((struct__5595*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 6);
}


int is_struct__5595_allow_double_convertion() {
	return 0;
}


const char * get_struct__5595_signature() {
	static StructSimValue values[6];
	Fill_struct__5595_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 6);
}

FilterUtils get_struct__5595_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[6];
	Fill_struct__5595_StructSimValue((struct__5595*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 6, strFilter);
}

const char * struct__5595_filter_values[6] = {"valid", "q_dir", "l_packet", "q_scale", "n_iter", "sections"};
int check_struct__5595_string(const char* strValue) {
	static struct__5595 rTemp;
	return string_to_struct__5595(strValue, &rTemp);
}


/****************************************************************
 ** array_int_224
 ****************************************************************/
void* array_int_224_projection(void** pValues, int nIndex) {
	return &((*(array_int_224*)pValues)[nIndex]);
}

const char * array_int_224_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 224, array_int_224_projection);
}

int compare_array_int_224_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 224, array_int_224_projection);
}

int is_array_int_224_allow_double_convertion() {
	return 0;
}

int string_to_array_int_224(const char* strValue, void* pValue) {
	static array_int_224 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 224, array_int_224_projection);
	if (nResult == 1)
		kcg_copy_array_int_224(&(*((array_int_224*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_224_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 224);
}

FilterUtils get_array_int_224_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 224, array_int_224_projection);
}

int check_array_int_224_string(const char* strValue) {
	static array_int_224 rTemp;
	return string_to_array_int_224(strValue, &rTemp);
}


/****************************************************************
 ** array_int_3
 ****************************************************************/
void* array_int_3_projection(void** pValues, int nIndex) {
	return &((*(array_int_3*)pValues)[nIndex]);
}

const char * array_int_3_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 3, array_int_3_projection);
}

int compare_array_int_3_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 3, array_int_3_projection);
}

int is_array_int_3_allow_double_convertion() {
	return 0;
}

int string_to_array_int_3(const char* strValue, void* pValue) {
	static array_int_3 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 3, array_int_3_projection);
	if (nResult == 1)
		kcg_copy_array_int_3(&(*((array_int_3*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_3_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 3);
}

FilterUtils get_array_int_3_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 3, array_int_3_projection);
}

int check_array_int_3_string(const char* strValue) {
	static array_int_3 rTemp;
	return string_to_array_int_3(strValue, &rTemp);
}


/****************************************************************
 ** struct__5610
 ****************************************************************/
static void Fill_struct__5610_StructSimValue(struct__5610 * pStruct, StructSimValue * pValues) {
	/*q_updown label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->q_updown) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[0].m_pszName = "q_updown";
	/*m_version label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->m_version) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[1].m_pszName = "m_version";
	/*q_media label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->q_media) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[2].m_pszName = "q_media";
	/*n_pig label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->n_pig) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[3].m_pszName = "n_pig";
	/*n_total label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->n_total) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "n_total";
	/*m_dup label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->m_dup) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[5].m_pszName = "m_dup";
	/*m_mcount label.*/
	pValues[6].m_pPtr = pStruct != 0 ? &(pStruct->m_mcount) : 0;
	pValues[6].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[6].m_pszName = "m_mcount";
	/*nid_c label.*/
	pValues[7].m_pPtr = pStruct != 0 ? &(pStruct->nid_c) : 0;
	pValues[7].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[7].m_pszName = "nid_c";
	/*nid_bg label.*/
	pValues[8].m_pPtr = pStruct != 0 ? &(pStruct->nid_bg) : 0;
	pValues[8].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[8].m_pszName = "nid_bg";
	/*q_link label.*/
	pValues[9].m_pPtr = pStruct != 0 ? &(pStruct->q_link) : 0;
	pValues[9].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[9].m_pszName = "q_link";
}

const char * struct__5610_to_string(const void* pValue) {
	static StructSimValue values[10];
	Fill_struct__5610_StructSimValue(((struct__5610*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 10);
}

int string_to_struct__5610(const char* strValue, void* pValue) {
	static struct__5610 rTemp;
	int nResult = 0;
	static StructSimValue values[10];
	kcg_copy_struct__5610(&(rTemp), &(*((struct__5610*)pValue)));
	Fill_struct__5610_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 10);
	if (nResult == 1)
		kcg_copy_struct__5610(&(*((struct__5610*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5610_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[10];
	Fill_struct__5610_StructSimValue((struct__5610*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 10);
}


int is_struct__5610_allow_double_convertion() {
	return 0;
}


const char * get_struct__5610_signature() {
	static StructSimValue values[10];
	Fill_struct__5610_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 10);
}

FilterUtils get_struct__5610_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[10];
	Fill_struct__5610_StructSimValue((struct__5610*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 10, strFilter);
}

const char * struct__5610_filter_values[10] = {"q_updown", "m_version", "q_media", "n_pig", "n_total", "m_dup", "m_mcount", "nid_c", "nid_bg", "q_link"};
int check_struct__5610_string(const char* strValue) {
	static struct__5610 rTemp;
	return string_to_struct__5610(strValue, &rTemp);
}


/****************************************************************
 ** struct__5623
 ****************************************************************/
static void Fill_struct__5623_StructSimValue(struct__5623 * pStruct, StructSimValue * pValues) {
	/*Header label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->Header) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_struct__5610_Utils;
	pValues[0].m_pszName = "Header";
	/*Messages label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->Messages) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_struct__5576_Utils;
	pValues[1].m_pszName = "Messages";
}

const char * struct__5623_to_string(const void* pValue) {
	static StructSimValue values[2];
	Fill_struct__5623_StructSimValue(((struct__5623*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 2);
}

int string_to_struct__5623(const char* strValue, void* pValue) {
	static struct__5623 rTemp;
	int nResult = 0;
	static StructSimValue values[2];
	kcg_copy_struct__5623(&(rTemp), &(*((struct__5623*)pValue)));
	Fill_struct__5623_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 2);
	if (nResult == 1)
		kcg_copy_struct__5623(&(*((struct__5623*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5623_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[2];
	Fill_struct__5623_StructSimValue((struct__5623*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 2);
}


int is_struct__5623_allow_double_convertion() {
	return 0;
}


const char * get_struct__5623_signature() {
	static StructSimValue values[2];
	Fill_struct__5623_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 2);
}

FilterUtils get_struct__5623_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[2];
	Fill_struct__5623_StructSimValue((struct__5623*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 2, strFilter);
}

const char * struct__5623_filter_values[2] = {"Header", "Messages"};
int check_struct__5623_string(const char* strValue) {
	static struct__5623 rTemp;
	return string_to_struct__5623(strValue, &rTemp);
}


/****************************************************************
 ** struct__5628
 ****************************************************************/
static void Fill_struct__5628_StructSimValue(struct__5628 * pStruct, StructSimValue * pValues) {
	/*NID_C label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->NID_C) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[0].m_pszName = "NID_C";
	/*NID_BG label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->NID_BG) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[1].m_pszName = "NID_BG";
	/*Pos label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->Pos) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[2].m_pszName = "Pos";
	/*Or_BG label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->Or_BG) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_OrBG_TM_Utils;
	pValues[3].m_pszName = "Or_BG";
	/*Or_Line label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->Or_Line) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_OrLine_TM_Utils;
	pValues[4].m_pszName = "Or_Line";
}

const char * struct__5628_to_string(const void* pValue) {
	static StructSimValue values[5];
	Fill_struct__5628_StructSimValue(((struct__5628*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 5);
}

int string_to_struct__5628(const char* strValue, void* pValue) {
	static struct__5628 rTemp;
	int nResult = 0;
	static StructSimValue values[5];
	kcg_copy_struct__5628(&(rTemp), &(*((struct__5628*)pValue)));
	Fill_struct__5628_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 5);
	if (nResult == 1)
		kcg_copy_struct__5628(&(*((struct__5628*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5628_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[5];
	Fill_struct__5628_StructSimValue((struct__5628*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 5);
}


int is_struct__5628_allow_double_convertion() {
	return 0;
}


const char * get_struct__5628_signature() {
	static StructSimValue values[5];
	Fill_struct__5628_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 5);
}

FilterUtils get_struct__5628_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[5];
	Fill_struct__5628_StructSimValue((struct__5628*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 5, strFilter);
}

const char * struct__5628_filter_values[5] = {"NID_C", "NID_BG", "Pos", "Or_BG", "Or_Line"};
int check_struct__5628_string(const char* strValue) {
	static struct__5628 rTemp;
	return string_to_struct__5628(strValue, &rTemp);
}


/****************************************************************
 ** struct__5636
 ****************************************************************/
static void Fill_struct__5636_StructSimValue(struct__5636 * pStruct, StructSimValue * pValues) {
	/*header label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->header) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_struct__5610_Utils;
	pValues[0].m_pszName = "header";
	/*packets label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->packets) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_struct__5576_Utils;
	pValues[1].m_pszName = "packets";
	/*engineering_BG_location label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->engineering_BG_location) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[2].m_pszName = "engineering_BG_location";
	/*TrainPos label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->TrainPos) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_kcg_real_Utils;
	pValues[3].m_pszName = "TrainPos";
	/*pig_nom_0 label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->pig_nom_0) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "pig_nom_0";
	/*balise_passed label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->balise_passed) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_kcg_bool_Utils;
	pValues[5].m_pszName = "balise_passed";
}

const char * struct__5636_to_string(const void* pValue) {
	static StructSimValue values[6];
	Fill_struct__5636_StructSimValue(((struct__5636*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 6);
}

int string_to_struct__5636(const char* strValue, void* pValue) {
	static struct__5636 rTemp;
	int nResult = 0;
	static StructSimValue values[6];
	kcg_copy_struct__5636(&(rTemp), &(*((struct__5636*)pValue)));
	Fill_struct__5636_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 6);
	if (nResult == 1)
		kcg_copy_struct__5636(&(*((struct__5636*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5636_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[6];
	Fill_struct__5636_StructSimValue((struct__5636*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 6);
}


int is_struct__5636_allow_double_convertion() {
	return 0;
}


const char * get_struct__5636_signature() {
	static StructSimValue values[6];
	Fill_struct__5636_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 6);
}

FilterUtils get_struct__5636_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[6];
	Fill_struct__5636_StructSimValue((struct__5636*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 6, strFilter);
}

const char * struct__5636_filter_values[6] = {"header", "packets", "engineering_BG_location", "TrainPos", "pig_nom_0", "balise_passed"};
int check_struct__5636_string(const char* strValue) {
	static struct__5636 rTemp;
	return string_to_struct__5636(strValue, &rTemp);
}


/****************************************************************
 ** struct__5645
 ****************************************************************/
static void Fill_struct__5645_StructSimValue(struct__5645 * pStruct, StructSimValue * pValues) {
	/*D_LINK label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->D_LINK) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[0].m_pszName = "D_LINK";
	/*Q_NEWCOUNTRY label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->Q_NEWCOUNTRY) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[1].m_pszName = "Q_NEWCOUNTRY";
	/*NID_C label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->NID_C) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[2].m_pszName = "NID_C";
	/*NID_BG label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->NID_BG) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[3].m_pszName = "NID_BG";
	/*Q_LINKORIENTATION label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->Q_LINKORIENTATION) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "Q_LINKORIENTATION";
	/*Q_LINKREACTION label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->Q_LINKREACTION) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[5].m_pszName = "Q_LINKREACTION";
	/*Q_LOCACC label.*/
	pValues[6].m_pPtr = pStruct != 0 ? &(pStruct->Q_LOCACC) : 0;
	pValues[6].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[6].m_pszName = "Q_LOCACC";
}

const char * struct__5645_to_string(const void* pValue) {
	static StructSimValue values[7];
	Fill_struct__5645_StructSimValue(((struct__5645*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 7);
}

int string_to_struct__5645(const char* strValue, void* pValue) {
	static struct__5645 rTemp;
	int nResult = 0;
	static StructSimValue values[7];
	kcg_copy_struct__5645(&(rTemp), &(*((struct__5645*)pValue)));
	Fill_struct__5645_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 7);
	if (nResult == 1)
		kcg_copy_struct__5645(&(*((struct__5645*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5645_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[7];
	Fill_struct__5645_StructSimValue((struct__5645*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 7);
}


int is_struct__5645_allow_double_convertion() {
	return 0;
}


const char * get_struct__5645_signature() {
	static StructSimValue values[7];
	Fill_struct__5645_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 7);
}

FilterUtils get_struct__5645_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[7];
	Fill_struct__5645_StructSimValue((struct__5645*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 7, strFilter);
}

const char * struct__5645_filter_values[7] = {"D_LINK", "Q_NEWCOUNTRY", "NID_C", "NID_BG", "Q_LINKORIENTATION", "Q_LINKREACTION", "Q_LOCACC"};
int check_struct__5645_string(const char* strValue) {
	static struct__5645 rTemp;
	return string_to_struct__5645(strValue, &rTemp);
}


/****************************************************************
 ** array__5655
 ****************************************************************/
void* array__5655_projection(void** pValues, int nIndex) {
	return &((*(array__5655*)pValues)[nIndex]);
}

const char * array__5655_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__5645_to_string, 32, array__5655_projection);
}

int compare_array__5655_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__5645_type , 32, array__5655_projection);
}

int is_array__5655_allow_double_convertion() {
	return 0;
}

int string_to_array__5655(const char* strValue, void* pValue) {
	static array__5655 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__5645, 32, array__5655_projection);
	if (nResult == 1)
		kcg_copy_array__5655(&(*((array__5655*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5655_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__5645_signature, 32);
}

FilterUtils get_array__5655_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__5645_Utils, strFilter, (void**)pValue, 32, array__5655_projection);
}

int check_array__5655_string(const char* strValue) {
	static array__5655 rTemp;
	return string_to_array__5655(strValue, &rTemp);
}


/****************************************************************
 ** struct__5658
 ****************************************************************/
static void Fill_struct__5658_StructSimValue(struct__5658 * pStruct, StructSimValue * pValues) {
	/*valid label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->valid) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_bool_Utils;
	pValues[0].m_pszName = "valid";
	/*NID_PACKET label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->NID_PACKET) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[1].m_pszName = "NID_PACKET";
	/*Q_DIR label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->Q_DIR) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[2].m_pszName = "Q_DIR";
	/*L_PACKET label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->L_PACKET) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[3].m_pszName = "L_PACKET";
	/*Q_SCALE label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->Q_SCALE) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[4].m_pszName = "Q_SCALE";
	/*D_LINK label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->D_LINK) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[5].m_pszName = "D_LINK";
	/*Q_NEWCOUNTRY label.*/
	pValues[6].m_pPtr = pStruct != 0 ? &(pStruct->Q_NEWCOUNTRY) : 0;
	pValues[6].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[6].m_pszName = "Q_NEWCOUNTRY";
	/*NID_C label.*/
	pValues[7].m_pPtr = pStruct != 0 ? &(pStruct->NID_C) : 0;
	pValues[7].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[7].m_pszName = "NID_C";
	/*NID_BG label.*/
	pValues[8].m_pPtr = pStruct != 0 ? &(pStruct->NID_BG) : 0;
	pValues[8].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[8].m_pszName = "NID_BG";
	/*Q_LINKORIENTATION label.*/
	pValues[9].m_pPtr = pStruct != 0 ? &(pStruct->Q_LINKORIENTATION) : 0;
	pValues[9].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[9].m_pszName = "Q_LINKORIENTATION";
	/*Q_LINKREACTION label.*/
	pValues[10].m_pPtr = pStruct != 0 ? &(pStruct->Q_LINKREACTION) : 0;
	pValues[10].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[10].m_pszName = "Q_LINKREACTION";
	/*Q_LOCACC label.*/
	pValues[11].m_pPtr = pStruct != 0 ? &(pStruct->Q_LOCACC) : 0;
	pValues[11].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[11].m_pszName = "Q_LOCACC";
	/*N_ITER label.*/
	pValues[12].m_pPtr = pStruct != 0 ? &(pStruct->N_ITER) : 0;
	pValues[12].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[12].m_pszName = "N_ITER";
	/*SECTIONS label.*/
	pValues[13].m_pPtr = pStruct != 0 ? &(pStruct->SECTIONS) : 0;
	pValues[13].m_pTypeUtils = &_SCSIM_array__5655_Utils;
	pValues[13].m_pszName = "SECTIONS";
}

const char * struct__5658_to_string(const void* pValue) {
	static StructSimValue values[14];
	Fill_struct__5658_StructSimValue(((struct__5658*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 14);
}

int string_to_struct__5658(const char* strValue, void* pValue) {
	static struct__5658 rTemp;
	int nResult = 0;
	static StructSimValue values[14];
	kcg_copy_struct__5658(&(rTemp), &(*((struct__5658*)pValue)));
	Fill_struct__5658_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 14);
	if (nResult == 1)
		kcg_copy_struct__5658(&(*((struct__5658*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__5658_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[14];
	Fill_struct__5658_StructSimValue((struct__5658*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 14);
}


int is_struct__5658_allow_double_convertion() {
	return 0;
}


const char * get_struct__5658_signature() {
	static StructSimValue values[14];
	Fill_struct__5658_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 14);
}

FilterUtils get_struct__5658_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[14];
	Fill_struct__5658_StructSimValue((struct__5658*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 14, strFilter);
}

const char * struct__5658_filter_values[14] = {"valid", "NID_PACKET", "Q_DIR", "L_PACKET", "Q_SCALE", "D_LINK", "Q_NEWCOUNTRY", "NID_C", "NID_BG", "Q_LINKORIENTATION", "Q_LINKREACTION", "Q_LOCACC", "N_ITER", "SECTIONS"};
int check_struct__5658_string(const char* strValue) {
	static struct__5658 rTemp;
	return string_to_struct__5658(strValue, &rTemp);
}


/****************************************************************
 ** array_int_7
 ****************************************************************/
void* array_int_7_projection(void** pValues, int nIndex) {
	return &((*(array_int_7*)pValues)[nIndex]);
}

const char * array_int_7_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 7, array_int_7_projection);
}

int compare_array_int_7_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 7, array_int_7_projection);
}

int is_array_int_7_allow_double_convertion() {
	return 0;
}

int string_to_array_int_7(const char* strValue, void* pValue) {
	static array_int_7 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 7, array_int_7_projection);
	if (nResult == 1)
		kcg_copy_array_int_7(&(*((array_int_7*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_7_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 7);
}

FilterUtils get_array_int_7_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 7, array_int_7_projection);
}

int check_array_int_7_string(const char* strValue) {
	static array_int_7 rTemp;
	return string_to_array_int_7(strValue, &rTemp);
}


/****************************************************************
 ** array_int_7_33
 ****************************************************************/
void* array_int_7_33_projection(void** pValues, int nIndex) {
	return &((*(array_int_7_33*)pValues)[nIndex]);
}

const char * array_int_7_33_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, array_int_7_to_string, 33, array_int_7_33_projection);
}

int compare_array_int_7_33_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_array_int_7_type , 33, array_int_7_33_projection);
}

int is_array_int_7_33_allow_double_convertion() {
	return 0;
}

int string_to_array_int_7_33(const char* strValue, void* pValue) {
	static array_int_7_33 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_array_int_7, 33, array_int_7_33_projection);
	if (nResult == 1)
		kcg_copy_array_int_7_33(&(*((array_int_7_33*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_7_33_signature() {
	return pSimulator->m_pfnArraySignature(get_array_int_7_signature, 33);
}

FilterUtils get_array_int_7_33_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_array_int_7_Utils, strFilter, (void**)pValue, 33, array_int_7_33_projection);
}

int check_array_int_7_33_string(const char* strValue) {
	static array_int_7_33 rTemp;
	return string_to_array_int_7_33(strValue, &rTemp);
}


/****************************************************************
 ** array__5681
 ****************************************************************/
void* array__5681_projection(void** pValues, int nIndex) {
	return &((*(array__5681*)pValues)[nIndex]);
}

const char * array__5681_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__5645_to_string, 33, array__5681_projection);
}

int compare_array__5681_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__5645_type , 33, array__5681_projection);
}

int is_array__5681_allow_double_convertion() {
	return 0;
}

int string_to_array__5681(const char* strValue, void* pValue) {
	static array__5681 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__5645, 33, array__5681_projection);
	if (nResult == 1)
		kcg_copy_array__5681(&(*((array__5681*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5681_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__5645_signature, 33);
}

FilterUtils get_array__5681_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__5645_Utils, strFilter, (void**)pValue, 33, array__5681_projection);
}

int check_array__5681_string(const char* strValue) {
	static array__5681 rTemp;
	return string_to_array__5681(strValue, &rTemp);
}


/****************************************************************
 ** array_int_500_500
 ****************************************************************/
void* array_int_500_500_projection(void** pValues, int nIndex) {
	return &((*(array_int_500_500*)pValues)[nIndex]);
}

const char * array_int_500_500_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, array_int_500_to_string, 500, array_int_500_500_projection);
}

int compare_array_int_500_500_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_array_int_500_type , 500, array_int_500_500_projection);
}

int is_array_int_500_500_allow_double_convertion() {
	return 0;
}

int string_to_array_int_500_500(const char* strValue, void* pValue) {
	static array_int_500_500 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_array_int_500, 500, array_int_500_500_projection);
	if (nResult == 1)
		kcg_copy_array_int_500_500(&(*((array_int_500_500*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_500_500_signature() {
	return pSimulator->m_pfnArraySignature(get_array_int_500_signature, 500);
}

FilterUtils get_array_int_500_500_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_array_int_500_Utils, strFilter, (void**)pValue, 500, array_int_500_500_projection);
}

int check_array_int_500_500_string(const char* strValue) {
	static array_int_500_500 rTemp;
	return string_to_array_int_500_500(strValue, &rTemp);
}


/****************************************************************
 ** array_int_7_33_231
 ****************************************************************/
void* array_int_7_33_231_projection(void** pValues, int nIndex) {
	return &((*(array_int_7_33_231*)pValues)[nIndex]);
}

const char * array_int_7_33_231_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, array_int_7_33_to_string, 231, array_int_7_33_231_projection);
}

int compare_array_int_7_33_231_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_array_int_7_33_type , 231, array_int_7_33_231_projection);
}

int is_array_int_7_33_231_allow_double_convertion() {
	return 0;
}

int string_to_array_int_7_33_231(const char* strValue, void* pValue) {
	static array_int_7_33_231 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_array_int_7_33, 231, array_int_7_33_231_projection);
	if (nResult == 1)
		kcg_copy_array_int_7_33_231(&(*((array_int_7_33_231*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_7_33_231_signature() {
	return pSimulator->m_pfnArraySignature(get_array_int_7_33_signature, 231);
}

FilterUtils get_array_int_7_33_231_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_array_int_7_33_Utils, strFilter, (void**)pValue, 231, array_int_7_33_231_projection);
}

int check_array_int_7_33_231_string(const char* strValue) {
	static array_int_7_33_231 rTemp;
	return string_to_array_int_7_33_231(strValue, &rTemp);
}


/****************************************************************
 ** array_int_271
 ****************************************************************/
void* array_int_271_projection(void** pValues, int nIndex) {
	return &((*(array_int_271*)pValues)[nIndex]);
}

const char * array_int_271_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 271, array_int_271_projection);
}

int compare_array_int_271_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 271, array_int_271_projection);
}

int is_array_int_271_allow_double_convertion() {
	return 0;
}

int string_to_array_int_271(const char* strValue, void* pValue) {
	static array_int_271 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 271, array_int_271_projection);
	if (nResult == 1)
		kcg_copy_array_int_271(&(*((array_int_271*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_271_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 271);
}

FilterUtils get_array_int_271_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 271, array_int_271_projection);
}

int check_array_int_271_string(const char* strValue) {
	static array_int_271 rTemp;
	return string_to_array_int_271(strValue, &rTemp);
}


/****************************************************************
 ** array_int_4
 ****************************************************************/
void* array_int_4_projection(void** pValues, int nIndex) {
	return &((*(array_int_4*)pValues)[nIndex]);
}

const char * array_int_4_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 4, array_int_4_projection);
}

int compare_array_int_4_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 4, array_int_4_projection);
}

int is_array_int_4_allow_double_convertion() {
	return 0;
}

int string_to_array_int_4(const char* strValue, void* pValue) {
	static array_int_4 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 4, array_int_4_projection);
	if (nResult == 1)
		kcg_copy_array_int_4(&(*((array_int_4*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_4_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 4);
}

FilterUtils get_array_int_4_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 4, array_int_4_projection);
}

int check_array_int_4_string(const char* strValue) {
	static array_int_4 rTemp;
	return string_to_array_int_4(strValue, &rTemp);
}


/****************************************************************
 ** array_int_1
 ****************************************************************/
void* array_int_1_projection(void** pValues, int nIndex) {
	return &((*(array_int_1*)pValues)[nIndex]);
}

const char * array_int_1_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 1, array_int_1_projection);
}

int compare_array_int_1_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 1, array_int_1_projection);
}

int is_array_int_1_allow_double_convertion() {
	return 0;
}

int string_to_array_int_1(const char* strValue, void* pValue) {
	static array_int_1 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 1, array_int_1_projection);
	if (nResult == 1)
		kcg_copy_array_int_1(&(*((array_int_1*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_1_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 1);
}

FilterUtils get_array_int_1_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 1, array_int_1_projection);
}

int check_array_int_1_string(const char* strValue) {
	static array_int_1 rTemp;
	return string_to_array_int_1(strValue, &rTemp);
}


/****************************************************************
 ** array_int_5
 ****************************************************************/
void* array_int_5_projection(void** pValues, int nIndex) {
	return &((*(array_int_5*)pValues)[nIndex]);
}

const char * array_int_5_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 5, array_int_5_projection);
}

int compare_array_int_5_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 5, array_int_5_projection);
}

int is_array_int_5_allow_double_convertion() {
	return 0;
}

int string_to_array_int_5(const char* strValue, void* pValue) {
	static array_int_5 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 5, array_int_5_projection);
	if (nResult == 1)
		kcg_copy_array_int_5(&(*((array_int_5*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_5_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 5);
}

FilterUtils get_array_int_5_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 5, array_int_5_projection);
}

int check_array_int_5_string(const char* strValue) {
	static array_int_5 rTemp;
	return string_to_array_int_5(strValue, &rTemp);
}


/****************************************************************
 ** array_int_229
 ****************************************************************/
void* array_int_229_projection(void** pValues, int nIndex) {
	return &((*(array_int_229*)pValues)[nIndex]);
}

const char * array_int_229_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 229, array_int_229_projection);
}

int compare_array_int_229_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 229, array_int_229_projection);
}

int is_array_int_229_allow_double_convertion() {
	return 0;
}

int string_to_array_int_229(const char* strValue, void* pValue) {
	static array_int_229 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 229, array_int_229_projection);
	if (nResult == 1)
		kcg_copy_array_int_229(&(*((array_int_229*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_229_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 229);
}

FilterUtils get_array_int_229_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 229, array_int_229_projection);
}

int check_array_int_229_string(const char* strValue) {
	static array_int_229 rTemp;
	return string_to_array_int_229(strValue, &rTemp);
}


/****************************************************************
 ** array__5705
 ****************************************************************/
void* array__5705_projection(void** pValues, int nIndex) {
	return &((*(array__5705*)pValues)[nIndex]);
}

const char * array__5705_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__5645_to_string, 1, array__5705_projection);
}

int compare_array__5705_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__5645_type , 1, array__5705_projection);
}

int is_array__5705_allow_double_convertion() {
	return 0;
}

int string_to_array__5705(const char* strValue, void* pValue) {
	static array__5705 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__5645, 1, array__5705_projection);
	if (nResult == 1)
		kcg_copy_array__5705(&(*((array__5705*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5705_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__5645_signature, 1);
}

FilterUtils get_array__5705_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__5645_Utils, strFilter, (void**)pValue, 1, array__5705_projection);
}

int check_array__5705_string(const char* strValue) {
	static array__5705 rTemp;
	return string_to_array__5705(strValue, &rTemp);
}


/****************************************************************
 ** array_int_30
 ****************************************************************/
void* array_int_30_projection(void** pValues, int nIndex) {
	return &((*(array_int_30*)pValues)[nIndex]);
}

const char * array_int_30_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 30, array_int_30_projection);
}

int compare_array_int_30_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 30, array_int_30_projection);
}

int is_array_int_30_allow_double_convertion() {
	return 0;
}

int string_to_array_int_30(const char* strValue, void* pValue) {
	static array_int_30 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 30, array_int_30_projection);
	if (nResult == 1)
		kcg_copy_array_int_30(&(*((array_int_30*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_30_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 30);
}

FilterUtils get_array_int_30_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 30, array_int_30_projection);
}

int check_array_int_30_string(const char* strValue) {
	static array_int_30 rTemp;
	return string_to_array_int_30(strValue, &rTemp);
}


/****************************************************************
 ** array_int_33
 ****************************************************************/
void* array_int_33_projection(void** pValues, int nIndex) {
	return &((*(array_int_33*)pValues)[nIndex]);
}

const char * array_int_33_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, kcg_int_to_string, 33, array_int_33_projection);
}

int compare_array_int_33_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_int_type , 33, array_int_33_projection);
}

int is_array_int_33_allow_double_convertion() {
	return 0;
}

int string_to_array_int_33(const char* strValue, void* pValue) {
	static array_int_33 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_int, 33, array_int_33_projection);
	if (nResult == 1)
		kcg_copy_array_int_33(&(*((array_int_33*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_33_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_int_signature, 33);
}

FilterUtils get_array_int_33_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_int_Utils, strFilter, (void**)pValue, 33, array_int_33_projection);
}

int check_array_int_33_string(const char* strValue) {
	static array_int_33 rTemp;
	return string_to_array_int_33(strValue, &rTemp);
}


/****************************************************************
 ** array_int_224_33
 ****************************************************************/
void* array_int_224_33_projection(void** pValues, int nIndex) {
	return &((*(array_int_224_33*)pValues)[nIndex]);
}

const char * array_int_224_33_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, array_int_224_to_string, 33, array_int_224_33_projection);
}

int compare_array_int_224_33_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_array_int_224_type , 33, array_int_224_33_projection);
}

int is_array_int_224_33_allow_double_convertion() {
	return 0;
}

int string_to_array_int_224_33(const char* strValue, void* pValue) {
	static array_int_224_33 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_array_int_224, 33, array_int_224_33_projection);
	if (nResult == 1)
		kcg_copy_array_int_224_33(&(*((array_int_224_33*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_int_224_33_signature() {
	return pSimulator->m_pfnArraySignature(get_array_int_224_signature, 33);
}

FilterUtils get_array_int_224_33_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_array_int_224_Utils, strFilter, (void**)pValue, 33, array_int_224_33_projection);
}

int check_array_int_224_33_string(const char* strValue) {
	static array_int_224_33 rTemp;
	return string_to_array_int_224_33(strValue, &rTemp);
}


/****************************************************************
 ** array__5717
 ****************************************************************/
void* array__5717_projection(void** pValues, int nIndex) {
	return &((*(array__5717*)pValues)[nIndex]);
}

const char * array__5717_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__5581_to_string, 4, array__5717_projection);
}

int compare_array__5717_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__5581_type , 4, array__5717_projection);
}

int is_array__5717_allow_double_convertion() {
	return 0;
}

int string_to_array__5717(const char* strValue, void* pValue) {
	static array__5717 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__5581, 4, array__5717_projection);
	if (nResult == 1)
		kcg_copy_array__5717(&(*((array__5717*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5717_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__5581_signature, 4);
}

FilterUtils get_array__5717_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__5581_Utils, strFilter, (void**)pValue, 4, array__5717_projection);
}

int check_array__5717_string(const char* strValue) {
	static array__5717 rTemp;
	return string_to_array__5717(strValue, &rTemp);
}


/****************************************************************
 ** array__5720
 ****************************************************************/
void* array__5720_projection(void** pValues, int nIndex) {
	return &((*(array__5720*)pValues)[nIndex]);
}

const char * array__5720_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, Q_DIR_to_string, 4, array__5720_projection);
}

int compare_array__5720_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_Q_DIR_type , 4, array__5720_projection);
}

int is_array__5720_allow_double_convertion() {
	return 0;
}

int string_to_array__5720(const char* strValue, void* pValue) {
	static array__5720 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_Q_DIR, 4, array__5720_projection);
	if (nResult == 1)
		kcg_copy_array__5720(&(*((array__5720*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5720_signature() {
	return pSimulator->m_pfnArraySignature(get_Q_DIR_signature, 4);
}

FilterUtils get_array__5720_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_Q_DIR_Utils, strFilter, (void**)pValue, 4, array__5720_projection);
}

int check_array__5720_string(const char* strValue) {
	static array__5720 rTemp;
	return string_to_array__5720(strValue, &rTemp);
}


/****************************************************************
 ** array__5723
 ****************************************************************/
void* array__5723_projection(void** pValues, int nIndex) {
	return &((*(array__5723*)pValues)[nIndex]);
}

const char * array__5723_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, Q_SCALE_to_string, 4, array__5723_projection);
}

int compare_array__5723_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_Q_SCALE_type , 4, array__5723_projection);
}

int is_array__5723_allow_double_convertion() {
	return 0;
}

int string_to_array__5723(const char* strValue, void* pValue) {
	static array__5723 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_Q_SCALE, 4, array__5723_projection);
	if (nResult == 1)
		kcg_copy_array__5723(&(*((array__5723*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__5723_signature() {
	return pSimulator->m_pfnArraySignature(get_Q_SCALE_signature, 4);
}

FilterUtils get_array__5723_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_Q_SCALE_Utils, strFilter, (void**)pValue, 4, array__5723_projection);
}

int check_array__5723_string(const char* strValue) {
	static array__5723 rTemp;
	return string_to_array__5723(strValue, &rTemp);
}


/****************************************************************
 ** NID_PACKET
 ****************************************************************/
struct SimTypeVTable* pSimNID_PACKETVTable;
const char * NID_PACKET_to_string(const void* pValue) {
	if (pSimNID_PACKETVTable != 0 && pSimNID_PACKETVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimNID_PACKETVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_NID_PACKET(const char* strValue, void* pValue) {
	if (pSimNID_PACKETVTable != 0 && pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static NID_PACKET rTemp;
		int nResult = pSimNID_PACKETVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((NID_PACKET*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_NID_PACKET_allow_double_convertion() {
	if (pSimNID_PACKETVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int NID_PACKET_to_double(double * nValue, const void* pValue) {
	if (pSimNID_PACKETVTable != 0) {
		if (pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimNID_PACKETVTable->m_pfnToType(SptLong, pValue));
		else if (pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimNID_PACKETVTable->m_pfnToType(SptShort, pValue));
		else if (pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimNID_PACKETVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimNID_PACKETVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimNID_PACKETVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_NID_PACKET_string(const char* strValue) {
	static NID_PACKET rTemp;
	return string_to_NID_PACKET(strValue, &rTemp);
}


/****************************************************************
 ** Q_DIR
 ****************************************************************/
struct SimTypeVTable* pSimQ_DIRVTable;
const char * Q_DIR_to_string(const void* pValue) {
	if (pSimQ_DIRVTable != 0 && pSimQ_DIRVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_DIRVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_DIR*)pValue)) {
	case Q_DIR_Reverse:
		return "Q_DIR_Reverse";
	case Q_DIR_Nominal:
		return "Q_DIR_Nominal";
	case Q_DIR_Both_directions:
		return "Q_DIR_Both_directions";
	default:
		return "?";
	}
}

int string_to_Q_DIR(const char* strValue, void* pValue) {
	if (pSimQ_DIRVTable != 0 && pSimQ_DIRVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_DIR rTemp;		int nResult = pSimQ_DIRVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_DIR*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_DIR_Reverse") == 0)
		*((Q_DIR*)pValue) = Q_DIR_Reverse;
	else if(strcmp(strValue, "Q_DIR_Nominal") == 0)
		*((Q_DIR*)pValue) = Q_DIR_Nominal;
	else if(strcmp(strValue, "Q_DIR_Both_directions") == 0)
		*((Q_DIR*)pValue) = Q_DIR_Both_directions;
	else 
		return 0;
	return 1;
}

int is_Q_DIR_allow_double_convertion() {
	return 1;
}


int Q_DIR_to_double(double * nValue, const void* pValue) {
	switch (*((Q_DIR*)pValue)) {
	case Q_DIR_Reverse:
		*nValue = 0.0;
		break;
	case Q_DIR_Nominal:
		*nValue = 1.0;
		break;
	case Q_DIR_Both_directions:
		*nValue = 2.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_DIR_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_DIR rTemp;
	const Q_DIR* pCurrent = (const Q_DIR*)pValue;
	if (string_to_Q_DIR(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_DIR_signature() {
	return "E"
		"|Q_DIR_Reverse"
		"|Q_DIR_Nominal"
		"|Q_DIR_Both_directions"
		;
}

int check_Q_DIR_string(const char* strValue) {
	static Q_DIR rTemp;
	return string_to_Q_DIR(strValue, &rTemp);
}


/****************************************************************
 ** Q_UPDOWN
 ****************************************************************/
struct SimTypeVTable* pSimQ_UPDOWNVTable;
const char * Q_UPDOWN_to_string(const void* pValue) {
	if (pSimQ_UPDOWNVTable != 0 && pSimQ_UPDOWNVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_UPDOWNVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_UPDOWN*)pValue)) {
	case Q_UPDOWN_Down_link_telegram:
		return "Q_UPDOWN_Down_link_telegram";
	case Q_UPDOWN_Up_link_telegram:
		return "Q_UPDOWN_Up_link_telegram";
	default:
		return "?";
	}
}

int string_to_Q_UPDOWN(const char* strValue, void* pValue) {
	if (pSimQ_UPDOWNVTable != 0 && pSimQ_UPDOWNVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_UPDOWN rTemp;		int nResult = pSimQ_UPDOWNVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_UPDOWN*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_UPDOWN_Down_link_telegram") == 0)
		*((Q_UPDOWN*)pValue) = Q_UPDOWN_Down_link_telegram;
	else if(strcmp(strValue, "Q_UPDOWN_Up_link_telegram") == 0)
		*((Q_UPDOWN*)pValue) = Q_UPDOWN_Up_link_telegram;
	else 
		return 0;
	return 1;
}

int is_Q_UPDOWN_allow_double_convertion() {
	return 1;
}


int Q_UPDOWN_to_double(double * nValue, const void* pValue) {
	switch (*((Q_UPDOWN*)pValue)) {
	case Q_UPDOWN_Down_link_telegram:
		*nValue = 0.0;
		break;
	case Q_UPDOWN_Up_link_telegram:
		*nValue = 1.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_UPDOWN_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_UPDOWN rTemp;
	const Q_UPDOWN* pCurrent = (const Q_UPDOWN*)pValue;
	if (string_to_Q_UPDOWN(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_UPDOWN_signature() {
	return "E"
		"|Q_UPDOWN_Down_link_telegram"
		"|Q_UPDOWN_Up_link_telegram"
		;
}

int check_Q_UPDOWN_string(const char* strValue) {
	static Q_UPDOWN rTemp;
	return string_to_Q_UPDOWN(strValue, &rTemp);
}


/****************************************************************
 ** M_VERSION
 ****************************************************************/
struct SimTypeVTable* pSimM_VERSIONVTable;
const char * M_VERSION_to_string(const void* pValue) {
	if (pSimM_VERSIONVTable != 0 && pSimM_VERSIONVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimM_VERSIONVTable->m_pfnToType(SptString, pValue);
	switch (*((M_VERSION*)pValue)) {
	case M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS:
		return "M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS";
	case M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0:
		return "M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0";
	case M_VERSION_Version_1_1_introduced_in_SRS_3_3_0:
		return "M_VERSION_Version_1_1_introduced_in_SRS_3_3_0";
	case M_VERSION_Version_2_0_introduced_in_SRS_3_3_0:
		return "M_VERSION_Version_2_0_introduced_in_SRS_3_3_0";
	default:
		return "?";
	}
}

int string_to_M_VERSION(const char* strValue, void* pValue) {
	if (pSimM_VERSIONVTable != 0 && pSimM_VERSIONVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		M_VERSION rTemp;		int nResult = pSimM_VERSIONVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((M_VERSION*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS") == 0)
		*((M_VERSION*)pValue) = M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS;
	else if(strcmp(strValue, "M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0") == 0)
		*((M_VERSION*)pValue) = M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0;
	else if(strcmp(strValue, "M_VERSION_Version_1_1_introduced_in_SRS_3_3_0") == 0)
		*((M_VERSION*)pValue) = M_VERSION_Version_1_1_introduced_in_SRS_3_3_0;
	else if(strcmp(strValue, "M_VERSION_Version_2_0_introduced_in_SRS_3_3_0") == 0)
		*((M_VERSION*)pValue) = M_VERSION_Version_2_0_introduced_in_SRS_3_3_0;
	else 
		return 0;
	return 1;
}

int is_M_VERSION_allow_double_convertion() {
	return 1;
}


int M_VERSION_to_double(double * nValue, const void* pValue) {
	switch (*((M_VERSION*)pValue)) {
	case M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS:
		*nValue = 0.0;
		break;
	case M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0:
		*nValue = 1.0;
		break;
	case M_VERSION_Version_1_1_introduced_in_SRS_3_3_0:
		*nValue = 2.0;
		break;
	case M_VERSION_Version_2_0_introduced_in_SRS_3_3_0:
		*nValue = 3.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_M_VERSION_type(int* pResult, const char* toCompare, const void* pValue) {
	static M_VERSION rTemp;
	const M_VERSION* pCurrent = (const M_VERSION*)pValue;
	if (string_to_M_VERSION(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_M_VERSION_signature() {
	return "E"
		"|M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS"
		"|M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0"
		"|M_VERSION_Version_1_1_introduced_in_SRS_3_3_0"
		"|M_VERSION_Version_2_0_introduced_in_SRS_3_3_0"
		;
}

int check_M_VERSION_string(const char* strValue) {
	static M_VERSION rTemp;
	return string_to_M_VERSION(strValue, &rTemp);
}


/****************************************************************
 ** Q_MEDIA
 ****************************************************************/
struct SimTypeVTable* pSimQ_MEDIAVTable;
const char * Q_MEDIA_to_string(const void* pValue) {
	if (pSimQ_MEDIAVTable != 0 && pSimQ_MEDIAVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_MEDIAVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_MEDIA*)pValue)) {
	case Q_MEDIA_Balise:
		return "Q_MEDIA_Balise";
	case Q_MEDIA_Loop:
		return "Q_MEDIA_Loop";
	default:
		return "?";
	}
}

int string_to_Q_MEDIA(const char* strValue, void* pValue) {
	if (pSimQ_MEDIAVTable != 0 && pSimQ_MEDIAVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_MEDIA rTemp;		int nResult = pSimQ_MEDIAVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_MEDIA*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_MEDIA_Balise") == 0)
		*((Q_MEDIA*)pValue) = Q_MEDIA_Balise;
	else if(strcmp(strValue, "Q_MEDIA_Loop") == 0)
		*((Q_MEDIA*)pValue) = Q_MEDIA_Loop;
	else 
		return 0;
	return 1;
}

int is_Q_MEDIA_allow_double_convertion() {
	return 1;
}


int Q_MEDIA_to_double(double * nValue, const void* pValue) {
	switch (*((Q_MEDIA*)pValue)) {
	case Q_MEDIA_Balise:
		*nValue = 0.0;
		break;
	case Q_MEDIA_Loop:
		*nValue = 1.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_MEDIA_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_MEDIA rTemp;
	const Q_MEDIA* pCurrent = (const Q_MEDIA*)pValue;
	if (string_to_Q_MEDIA(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_MEDIA_signature() {
	return "E"
		"|Q_MEDIA_Balise"
		"|Q_MEDIA_Loop"
		;
}

int check_Q_MEDIA_string(const char* strValue) {
	static Q_MEDIA rTemp;
	return string_to_Q_MEDIA(strValue, &rTemp);
}


/****************************************************************
 ** N_PIG
 ****************************************************************/
struct SimTypeVTable* pSimN_PIGVTable;
const char * N_PIG_to_string(const void* pValue) {
	if (pSimN_PIGVTable != 0 && pSimN_PIGVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimN_PIGVTable->m_pfnToType(SptString, pValue);
	switch (*((N_PIG*)pValue)) {
	case N_PIG_I_am_the_1st:
		return "N_PIG_I_am_the_1st";
	case N_PIG_I_am_the_2nd:
		return "N_PIG_I_am_the_2nd";
	case N_PIG_I_am_the_3rd:
		return "N_PIG_I_am_the_3rd";
	case N_PIG_I_am_the_4th:
		return "N_PIG_I_am_the_4th";
	case N_PIG_I_am_the_5th:
		return "N_PIG_I_am_the_5th";
	case N_PIG_I_am_the_6th:
		return "N_PIG_I_am_the_6th";
	case N_PIG_I_am_the_7th:
		return "N_PIG_I_am_the_7th";
	case N_PIG_I_am_the_8th:
		return "N_PIG_I_am_the_8th";
	default:
		return "?";
	}
}

int string_to_N_PIG(const char* strValue, void* pValue) {
	if (pSimN_PIGVTable != 0 && pSimN_PIGVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		N_PIG rTemp;		int nResult = pSimN_PIGVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((N_PIG*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "N_PIG_I_am_the_1st") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_1st;
	else if(strcmp(strValue, "N_PIG_I_am_the_2nd") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_2nd;
	else if(strcmp(strValue, "N_PIG_I_am_the_3rd") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_3rd;
	else if(strcmp(strValue, "N_PIG_I_am_the_4th") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_4th;
	else if(strcmp(strValue, "N_PIG_I_am_the_5th") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_5th;
	else if(strcmp(strValue, "N_PIG_I_am_the_6th") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_6th;
	else if(strcmp(strValue, "N_PIG_I_am_the_7th") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_7th;
	else if(strcmp(strValue, "N_PIG_I_am_the_8th") == 0)
		*((N_PIG*)pValue) = N_PIG_I_am_the_8th;
	else 
		return 0;
	return 1;
}

int is_N_PIG_allow_double_convertion() {
	return 1;
}


int N_PIG_to_double(double * nValue, const void* pValue) {
	switch (*((N_PIG*)pValue)) {
	case N_PIG_I_am_the_1st:
		*nValue = 0.0;
		break;
	case N_PIG_I_am_the_2nd:
		*nValue = 1.0;
		break;
	case N_PIG_I_am_the_3rd:
		*nValue = 2.0;
		break;
	case N_PIG_I_am_the_4th:
		*nValue = 3.0;
		break;
	case N_PIG_I_am_the_5th:
		*nValue = 4.0;
		break;
	case N_PIG_I_am_the_6th:
		*nValue = 5.0;
		break;
	case N_PIG_I_am_the_7th:
		*nValue = 6.0;
		break;
	case N_PIG_I_am_the_8th:
		*nValue = 7.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_N_PIG_type(int* pResult, const char* toCompare, const void* pValue) {
	static N_PIG rTemp;
	const N_PIG* pCurrent = (const N_PIG*)pValue;
	if (string_to_N_PIG(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_N_PIG_signature() {
	return "E"
		"|N_PIG_I_am_the_1st"
		"|N_PIG_I_am_the_2nd"
		"|N_PIG_I_am_the_3rd"
		"|N_PIG_I_am_the_4th"
		"|N_PIG_I_am_the_5th"
		"|N_PIG_I_am_the_6th"
		"|N_PIG_I_am_the_7th"
		"|N_PIG_I_am_the_8th"
		;
}

int check_N_PIG_string(const char* strValue) {
	static N_PIG rTemp;
	return string_to_N_PIG(strValue, &rTemp);
}


/****************************************************************
 ** N_TOTAL
 ****************************************************************/
struct SimTypeVTable* pSimN_TOTALVTable;
const char * N_TOTAL_to_string(const void* pValue) {
	if (pSimN_TOTALVTable != 0 && pSimN_TOTALVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimN_TOTALVTable->m_pfnToType(SptString, pValue);
	switch (*((N_TOTAL*)pValue)) {
	case N_TOTAL_1_balise_in_the_group:
		return "N_TOTAL_1_balise_in_the_group";
	case N_TOTAL_2_balises_in_the_group:
		return "N_TOTAL_2_balises_in_the_group";
	case N_TOTAL_3_balises_in_the_group:
		return "N_TOTAL_3_balises_in_the_group";
	case N_TOTAL_4_balises_in_the_group:
		return "N_TOTAL_4_balises_in_the_group";
	case N_TOTAL_5_balises_in_the_group:
		return "N_TOTAL_5_balises_in_the_group";
	case N_TOTAL_6_balises_in_the_group:
		return "N_TOTAL_6_balises_in_the_group";
	case N_TOTAL_7_balises_in_the_group:
		return "N_TOTAL_7_balises_in_the_group";
	case N_TOTAL_8_balises_in_the_group:
		return "N_TOTAL_8_balises_in_the_group";
	default:
		return "?";
	}
}

int string_to_N_TOTAL(const char* strValue, void* pValue) {
	if (pSimN_TOTALVTable != 0 && pSimN_TOTALVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		N_TOTAL rTemp;		int nResult = pSimN_TOTALVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((N_TOTAL*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "N_TOTAL_1_balise_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_1_balise_in_the_group;
	else if(strcmp(strValue, "N_TOTAL_2_balises_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_2_balises_in_the_group;
	else if(strcmp(strValue, "N_TOTAL_3_balises_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_3_balises_in_the_group;
	else if(strcmp(strValue, "N_TOTAL_4_balises_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_4_balises_in_the_group;
	else if(strcmp(strValue, "N_TOTAL_5_balises_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_5_balises_in_the_group;
	else if(strcmp(strValue, "N_TOTAL_6_balises_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_6_balises_in_the_group;
	else if(strcmp(strValue, "N_TOTAL_7_balises_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_7_balises_in_the_group;
	else if(strcmp(strValue, "N_TOTAL_8_balises_in_the_group") == 0)
		*((N_TOTAL*)pValue) = N_TOTAL_8_balises_in_the_group;
	else 
		return 0;
	return 1;
}

int is_N_TOTAL_allow_double_convertion() {
	return 1;
}


int N_TOTAL_to_double(double * nValue, const void* pValue) {
	switch (*((N_TOTAL*)pValue)) {
	case N_TOTAL_1_balise_in_the_group:
		*nValue = 0.0;
		break;
	case N_TOTAL_2_balises_in_the_group:
		*nValue = 1.0;
		break;
	case N_TOTAL_3_balises_in_the_group:
		*nValue = 2.0;
		break;
	case N_TOTAL_4_balises_in_the_group:
		*nValue = 3.0;
		break;
	case N_TOTAL_5_balises_in_the_group:
		*nValue = 4.0;
		break;
	case N_TOTAL_6_balises_in_the_group:
		*nValue = 5.0;
		break;
	case N_TOTAL_7_balises_in_the_group:
		*nValue = 6.0;
		break;
	case N_TOTAL_8_balises_in_the_group:
		*nValue = 7.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_N_TOTAL_type(int* pResult, const char* toCompare, const void* pValue) {
	static N_TOTAL rTemp;
	const N_TOTAL* pCurrent = (const N_TOTAL*)pValue;
	if (string_to_N_TOTAL(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_N_TOTAL_signature() {
	return "E"
		"|N_TOTAL_1_balise_in_the_group"
		"|N_TOTAL_2_balises_in_the_group"
		"|N_TOTAL_3_balises_in_the_group"
		"|N_TOTAL_4_balises_in_the_group"
		"|N_TOTAL_5_balises_in_the_group"
		"|N_TOTAL_6_balises_in_the_group"
		"|N_TOTAL_7_balises_in_the_group"
		"|N_TOTAL_8_balises_in_the_group"
		;
}

int check_N_TOTAL_string(const char* strValue) {
	static N_TOTAL rTemp;
	return string_to_N_TOTAL(strValue, &rTemp);
}


/****************************************************************
 ** M_DUP
 ****************************************************************/
struct SimTypeVTable* pSimM_DUPVTable;
const char * M_DUP_to_string(const void* pValue) {
	if (pSimM_DUPVTable != 0 && pSimM_DUPVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimM_DUPVTable->m_pfnToType(SptString, pValue);
	switch (*((M_DUP*)pValue)) {
	case M_DUP_No_duplicates:
		return "M_DUP_No_duplicates";
	case _2_M_DUP_This_balise_is_a_duplicate_of_the_next_balise:
		return "M_DUP_This_balise_is_a_duplicate_of_the_next_balise";
	case M_DUP_This_balise_is_a_duplicate_of_the_previous_balise:
		return "M_DUP_This_balise_is_a_duplicate_of_the_previous_balise";
	default:
		return "?";
	}
}

int string_to_M_DUP(const char* strValue, void* pValue) {
	if (pSimM_DUPVTable != 0 && pSimM_DUPVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		M_DUP rTemp;		int nResult = pSimM_DUPVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((M_DUP*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "M_DUP_No_duplicates") == 0)
		*((M_DUP*)pValue) = M_DUP_No_duplicates;
	else if(strcmp(strValue, "M_DUP_This_balise_is_a_duplicate_of_the_next_balise") == 0)
		*((M_DUP*)pValue) = _2_M_DUP_This_balise_is_a_duplicate_of_the_next_balise;
	else if(strcmp(strValue, "M_DUP_This_balise_is_a_duplicate_of_the_previous_balise") == 0)
		*((M_DUP*)pValue) = M_DUP_This_balise_is_a_duplicate_of_the_previous_balise;
	else 
		return 0;
	return 1;
}

int is_M_DUP_allow_double_convertion() {
	return 1;
}


int M_DUP_to_double(double * nValue, const void* pValue) {
	switch (*((M_DUP*)pValue)) {
	case M_DUP_No_duplicates:
		*nValue = 0.0;
		break;
	case _2_M_DUP_This_balise_is_a_duplicate_of_the_next_balise:
		*nValue = 1.0;
		break;
	case M_DUP_This_balise_is_a_duplicate_of_the_previous_balise:
		*nValue = 2.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_M_DUP_type(int* pResult, const char* toCompare, const void* pValue) {
	static M_DUP rTemp;
	const M_DUP* pCurrent = (const M_DUP*)pValue;
	if (string_to_M_DUP(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_M_DUP_signature() {
	return "E"
		"|M_DUP_No_duplicates"
		"|M_DUP_This_balise_is_a_duplicate_of_the_next_balise"
		"|M_DUP_This_balise_is_a_duplicate_of_the_previous_balise"
		;
}

int check_M_DUP_string(const char* strValue) {
	static M_DUP rTemp;
	return string_to_M_DUP(strValue, &rTemp);
}


/****************************************************************
 ** M_MCOUNT
 ****************************************************************/
struct SimTypeVTable* pSimM_MCOUNTVTable;
const char * M_MCOUNT_to_string(const void* pValue) {
	if (pSimM_MCOUNTVTable != 0 && pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimM_MCOUNTVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_M_MCOUNT(const char* strValue, void* pValue) {
	if (pSimM_MCOUNTVTable != 0 && pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static M_MCOUNT rTemp;
		int nResult = pSimM_MCOUNTVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((M_MCOUNT*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_M_MCOUNT_allow_double_convertion() {
	if (pSimM_MCOUNTVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int M_MCOUNT_to_double(double * nValue, const void* pValue) {
	if (pSimM_MCOUNTVTable != 0) {
		if (pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimM_MCOUNTVTable->m_pfnToType(SptLong, pValue));
		else if (pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimM_MCOUNTVTable->m_pfnToType(SptShort, pValue));
		else if (pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimM_MCOUNTVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimM_MCOUNTVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_M_MCOUNT_string(const char* strValue) {
	static M_MCOUNT rTemp;
	return string_to_M_MCOUNT(strValue, &rTemp);
}


/****************************************************************
 ** NID_C
 ****************************************************************/
struct SimTypeVTable* pSimNID_CVTable;
const char * NID_C_to_string(const void* pValue) {
	if (pSimNID_CVTable != 0 && pSimNID_CVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimNID_CVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_NID_C(const char* strValue, void* pValue) {
	if (pSimNID_CVTable != 0 && pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static NID_C rTemp;
		int nResult = pSimNID_CVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((NID_C*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_NID_C_allow_double_convertion() {
	if (pSimNID_CVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int NID_C_to_double(double * nValue, const void* pValue) {
	if (pSimNID_CVTable != 0) {
		if (pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimNID_CVTable->m_pfnToType(SptLong, pValue));
		else if (pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimNID_CVTable->m_pfnToType(SptShort, pValue));
		else if (pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimNID_CVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimNID_CVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimNID_CVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_NID_C_string(const char* strValue) {
	static NID_C rTemp;
	return string_to_NID_C(strValue, &rTemp);
}


/****************************************************************
 ** NID_BG
 ****************************************************************/
struct SimTypeVTable* pSimNID_BGVTable;
const char * NID_BG_to_string(const void* pValue) {
	if (pSimNID_BGVTable != 0 && pSimNID_BGVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimNID_BGVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_NID_BG(const char* strValue, void* pValue) {
	if (pSimNID_BGVTable != 0 && pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static NID_BG rTemp;
		int nResult = pSimNID_BGVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((NID_BG*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_NID_BG_allow_double_convertion() {
	if (pSimNID_BGVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int NID_BG_to_double(double * nValue, const void* pValue) {
	if (pSimNID_BGVTable != 0) {
		if (pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimNID_BGVTable->m_pfnToType(SptLong, pValue));
		else if (pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimNID_BGVTable->m_pfnToType(SptShort, pValue));
		else if (pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimNID_BGVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimNID_BGVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimNID_BGVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_NID_BG_string(const char* strValue) {
	static NID_BG rTemp;
	return string_to_NID_BG(strValue, &rTemp);
}


/****************************************************************
 ** Q_LINK
 ****************************************************************/
struct SimTypeVTable* pSimQ_LINKVTable;
const char * Q_LINK_to_string(const void* pValue) {
	if (pSimQ_LINKVTable != 0 && pSimQ_LINKVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_LINKVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_LINK*)pValue)) {
	case Q_LINK_Unlinked:
		return "Q_LINK_Unlinked";
	case Q_LINK_Linked:
		return "Q_LINK_Linked";
	default:
		return "?";
	}
}

int string_to_Q_LINK(const char* strValue, void* pValue) {
	if (pSimQ_LINKVTable != 0 && pSimQ_LINKVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_LINK rTemp;		int nResult = pSimQ_LINKVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_LINK*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_LINK_Unlinked") == 0)
		*((Q_LINK*)pValue) = Q_LINK_Unlinked;
	else if(strcmp(strValue, "Q_LINK_Linked") == 0)
		*((Q_LINK*)pValue) = Q_LINK_Linked;
	else 
		return 0;
	return 1;
}

int is_Q_LINK_allow_double_convertion() {
	return 1;
}


int Q_LINK_to_double(double * nValue, const void* pValue) {
	switch (*((Q_LINK*)pValue)) {
	case Q_LINK_Unlinked:
		*nValue = 0.0;
		break;
	case Q_LINK_Linked:
		*nValue = 1.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_LINK_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_LINK rTemp;
	const Q_LINK* pCurrent = (const Q_LINK*)pValue;
	if (string_to_Q_LINK(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_LINK_signature() {
	return "E"
		"|Q_LINK_Unlinked"
		"|Q_LINK_Linked"
		;
}

int check_Q_LINK_string(const char* strValue) {
	static Q_LINK rTemp;
	return string_to_Q_LINK(strValue, &rTemp);
}


/****************************************************************
 ** Q_SCALE
 ****************************************************************/
struct SimTypeVTable* pSimQ_SCALEVTable;
const char * Q_SCALE_to_string(const void* pValue) {
	if (pSimQ_SCALEVTable != 0 && pSimQ_SCALEVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_SCALEVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_SCALE*)pValue)) {
	case Q_SCALE_10_cm_scale:
		return "Q_SCALE_10_cm_scale";
	case Q_SCALE_1_m_scale:
		return "Q_SCALE_1_m_scale";
	case Q_SCALE_10_m_scale:
		return "Q_SCALE_10_m_scale";
	default:
		return "?";
	}
}

int string_to_Q_SCALE(const char* strValue, void* pValue) {
	if (pSimQ_SCALEVTable != 0 && pSimQ_SCALEVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_SCALE rTemp;		int nResult = pSimQ_SCALEVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_SCALE*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_SCALE_10_cm_scale") == 0)
		*((Q_SCALE*)pValue) = Q_SCALE_10_cm_scale;
	else if(strcmp(strValue, "Q_SCALE_1_m_scale") == 0)
		*((Q_SCALE*)pValue) = Q_SCALE_1_m_scale;
	else if(strcmp(strValue, "Q_SCALE_10_m_scale") == 0)
		*((Q_SCALE*)pValue) = Q_SCALE_10_m_scale;
	else 
		return 0;
	return 1;
}

int is_Q_SCALE_allow_double_convertion() {
	return 1;
}


int Q_SCALE_to_double(double * nValue, const void* pValue) {
	switch (*((Q_SCALE*)pValue)) {
	case Q_SCALE_10_cm_scale:
		*nValue = 0.0;
		break;
	case Q_SCALE_1_m_scale:
		*nValue = 1.0;
		break;
	case Q_SCALE_10_m_scale:
		*nValue = 2.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_SCALE_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_SCALE rTemp;
	const Q_SCALE* pCurrent = (const Q_SCALE*)pValue;
	if (string_to_Q_SCALE(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_SCALE_signature() {
	return "E"
		"|Q_SCALE_10_cm_scale"
		"|Q_SCALE_1_m_scale"
		"|Q_SCALE_10_m_scale"
		;
}

int check_Q_SCALE_string(const char* strValue) {
	static Q_SCALE rTemp;
	return string_to_Q_SCALE(strValue, &rTemp);
}


/****************************************************************
 ** D_LINK
 ****************************************************************/
struct SimTypeVTable* pSimD_LINKVTable;
const char * D_LINK_to_string(const void* pValue) {
	if (pSimD_LINKVTable != 0 && pSimD_LINKVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimD_LINKVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_D_LINK(const char* strValue, void* pValue) {
	if (pSimD_LINKVTable != 0 && pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static D_LINK rTemp;
		int nResult = pSimD_LINKVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((D_LINK*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_D_LINK_allow_double_convertion() {
	if (pSimD_LINKVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int D_LINK_to_double(double * nValue, const void* pValue) {
	if (pSimD_LINKVTable != 0) {
		if (pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimD_LINKVTable->m_pfnToType(SptLong, pValue));
		else if (pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimD_LINKVTable->m_pfnToType(SptShort, pValue));
		else if (pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimD_LINKVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimD_LINKVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimD_LINKVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_D_LINK_string(const char* strValue) {
	static D_LINK rTemp;
	return string_to_D_LINK(strValue, &rTemp);
}


/****************************************************************
 ** Q_NEWCOUNTRY
 ****************************************************************/
struct SimTypeVTable* pSimQ_NEWCOUNTRYVTable;
const char * Q_NEWCOUNTRY_to_string(const void* pValue) {
	if (pSimQ_NEWCOUNTRYVTable != 0 && pSimQ_NEWCOUNTRYVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_NEWCOUNTRYVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_NEWCOUNTRY*)pValue)) {
	case Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows:
		return "Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows";
	case Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows:
		return "Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows";
	default:
		return "?";
	}
}

int string_to_Q_NEWCOUNTRY(const char* strValue, void* pValue) {
	if (pSimQ_NEWCOUNTRYVTable != 0 && pSimQ_NEWCOUNTRYVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_NEWCOUNTRY rTemp;		int nResult = pSimQ_NEWCOUNTRYVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_NEWCOUNTRY*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows") == 0)
		*((Q_NEWCOUNTRY*)pValue) = Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows;
	else if(strcmp(strValue, "Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows") == 0)
		*((Q_NEWCOUNTRY*)pValue) = Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows;
	else 
		return 0;
	return 1;
}

int is_Q_NEWCOUNTRY_allow_double_convertion() {
	return 1;
}


int Q_NEWCOUNTRY_to_double(double * nValue, const void* pValue) {
	switch (*((Q_NEWCOUNTRY*)pValue)) {
	case Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows:
		*nValue = 0.0;
		break;
	case Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows:
		*nValue = 1.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_NEWCOUNTRY_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_NEWCOUNTRY rTemp;
	const Q_NEWCOUNTRY* pCurrent = (const Q_NEWCOUNTRY*)pValue;
	if (string_to_Q_NEWCOUNTRY(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_NEWCOUNTRY_signature() {
	return "E"
		"|Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows"
		"|Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows"
		;
}

int check_Q_NEWCOUNTRY_string(const char* strValue) {
	static Q_NEWCOUNTRY rTemp;
	return string_to_Q_NEWCOUNTRY(strValue, &rTemp);
}


/****************************************************************
 ** Q_LINKORIENTATION
 ****************************************************************/
struct SimTypeVTable* pSimQ_LINKORIENTATIONVTable;
const char * Q_LINKORIENTATION_to_string(const void* pValue) {
	if (pSimQ_LINKORIENTATIONVTable != 0 && pSimQ_LINKORIENTATIONVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_LINKORIENTATIONVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_LINKORIENTATION*)pValue)) {
	case _1_Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction:
		return "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction";
	case Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction:
		return "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction";
	default:
		return "?";
	}
}

int string_to_Q_LINKORIENTATION(const char* strValue, void* pValue) {
	if (pSimQ_LINKORIENTATIONVTable != 0 && pSimQ_LINKORIENTATIONVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_LINKORIENTATION rTemp;		int nResult = pSimQ_LINKORIENTATIONVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_LINKORIENTATION*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction") == 0)
		*((Q_LINKORIENTATION*)pValue) = _1_Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction;
	else if(strcmp(strValue, "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction") == 0)
		*((Q_LINKORIENTATION*)pValue) = Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction;
	else 
		return 0;
	return 1;
}

int is_Q_LINKORIENTATION_allow_double_convertion() {
	return 1;
}


int Q_LINKORIENTATION_to_double(double * nValue, const void* pValue) {
	switch (*((Q_LINKORIENTATION*)pValue)) {
	case _1_Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction:
		*nValue = 0.0;
		break;
	case Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction:
		*nValue = 1.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_LINKORIENTATION_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_LINKORIENTATION rTemp;
	const Q_LINKORIENTATION* pCurrent = (const Q_LINKORIENTATION*)pValue;
	if (string_to_Q_LINKORIENTATION(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_LINKORIENTATION_signature() {
	return "E"
		"|Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction"
		"|Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction"
		;
}

int check_Q_LINKORIENTATION_string(const char* strValue) {
	static Q_LINKORIENTATION rTemp;
	return string_to_Q_LINKORIENTATION(strValue, &rTemp);
}


/****************************************************************
 ** Q_LINKREACTION
 ****************************************************************/
struct SimTypeVTable* pSimQ_LINKREACTIONVTable;
const char * Q_LINKREACTION_to_string(const void* pValue) {
	if (pSimQ_LINKREACTIONVTable != 0 && pSimQ_LINKREACTIONVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_LINKREACTIONVTable->m_pfnToType(SptString, pValue);
	switch (*((Q_LINKREACTION*)pValue)) {
	case Q_LINKREACTION_Train_trip:
		return "Q_LINKREACTION_Train_trip";
	case Q_LINKREACTION_Apply_service_brake:
		return "Q_LINKREACTION_Apply_service_brake";
	case Q_LINKREACTION_No_Reaction:
		return "Q_LINKREACTION_No_Reaction";
	default:
		return "?";
	}
}

int string_to_Q_LINKREACTION(const char* strValue, void* pValue) {
	if (pSimQ_LINKREACTIONVTable != 0 && pSimQ_LINKREACTIONVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		Q_LINKREACTION rTemp;		int nResult = pSimQ_LINKREACTIONVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_LINKREACTION*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Q_LINKREACTION_Train_trip") == 0)
		*((Q_LINKREACTION*)pValue) = Q_LINKREACTION_Train_trip;
	else if(strcmp(strValue, "Q_LINKREACTION_Apply_service_brake") == 0)
		*((Q_LINKREACTION*)pValue) = Q_LINKREACTION_Apply_service_brake;
	else if(strcmp(strValue, "Q_LINKREACTION_No_Reaction") == 0)
		*((Q_LINKREACTION*)pValue) = Q_LINKREACTION_No_Reaction;
	else 
		return 0;
	return 1;
}

int is_Q_LINKREACTION_allow_double_convertion() {
	return 1;
}


int Q_LINKREACTION_to_double(double * nValue, const void* pValue) {
	switch (*((Q_LINKREACTION*)pValue)) {
	case Q_LINKREACTION_Train_trip:
		*nValue = 0.0;
		break;
	case Q_LINKREACTION_Apply_service_brake:
		*nValue = 1.0;
		break;
	case Q_LINKREACTION_No_Reaction:
		*nValue = 2.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_Q_LINKREACTION_type(int* pResult, const char* toCompare, const void* pValue) {
	static Q_LINKREACTION rTemp;
	const Q_LINKREACTION* pCurrent = (const Q_LINKREACTION*)pValue;
	if (string_to_Q_LINKREACTION(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_Q_LINKREACTION_signature() {
	return "E"
		"|Q_LINKREACTION_Train_trip"
		"|Q_LINKREACTION_Apply_service_brake"
		"|Q_LINKREACTION_No_Reaction"
		;
}

int check_Q_LINKREACTION_string(const char* strValue) {
	static Q_LINKREACTION rTemp;
	return string_to_Q_LINKREACTION(strValue, &rTemp);
}


/****************************************************************
 ** Q_LOCACC
 ****************************************************************/
struct SimTypeVTable* pSimQ_LOCACCVTable;
const char * Q_LOCACC_to_string(const void* pValue) {
	if (pSimQ_LOCACCVTable != 0 && pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimQ_LOCACCVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_Q_LOCACC(const char* strValue, void* pValue) {
	if (pSimQ_LOCACCVTable != 0 && pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static Q_LOCACC rTemp;
		int nResult = pSimQ_LOCACCVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((Q_LOCACC*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_Q_LOCACC_allow_double_convertion() {
	if (pSimQ_LOCACCVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int Q_LOCACC_to_double(double * nValue, const void* pValue) {
	if (pSimQ_LOCACCVTable != 0) {
		if (pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimQ_LOCACCVTable->m_pfnToType(SptLong, pValue));
		else if (pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimQ_LOCACCVTable->m_pfnToType(SptShort, pValue));
		else if (pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimQ_LOCACCVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimQ_LOCACCVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_Q_LOCACC_string(const char* strValue) {
	static Q_LOCACC rTemp;
	return string_to_Q_LOCACC(strValue, &rTemp);
}


/****************************************************************
 ** N_ITER
 ****************************************************************/
struct SimTypeVTable* pSimN_ITERVTable;
const char * N_ITER_to_string(const void* pValue) {
	if (pSimN_ITERVTable != 0 && pSimN_ITERVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimN_ITERVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_N_ITER(const char* strValue, void* pValue) {
	if (pSimN_ITERVTable != 0 && pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static N_ITER rTemp;
		int nResult = pSimN_ITERVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((N_ITER*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_N_ITER_allow_double_convertion() {
	if (pSimN_ITERVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int N_ITER_to_double(double * nValue, const void* pValue) {
	if (pSimN_ITERVTable != 0) {
		if (pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimN_ITERVTable->m_pfnToType(SptLong, pValue));
		else if (pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimN_ITERVTable->m_pfnToType(SptShort, pValue));
		else if (pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimN_ITERVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimN_ITERVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimN_ITERVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_N_ITER_string(const char* strValue) {
	static N_ITER rTemp;
	return string_to_N_ITER(strValue, &rTemp);
}


/****************************************************************
 ** L_PACKET
 ****************************************************************/
struct SimTypeVTable* pSimL_PACKETVTable;
const char * L_PACKET_to_string(const void* pValue) {
	if (pSimL_PACKETVTable != 0 && pSimL_PACKETVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimL_PACKETVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_L_PACKET(const char* strValue, void* pValue) {
	if (pSimL_PACKETVTable != 0 && pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static L_PACKET rTemp;
		int nResult = pSimL_PACKETVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((L_PACKET*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_L_PACKET_allow_double_convertion() {
	if (pSimL_PACKETVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int L_PACKET_to_double(double * nValue, const void* pValue) {
	if (pSimL_PACKETVTable != 0) {
		if (pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimL_PACKETVTable->m_pfnToType(SptLong, pValue));
		else if (pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimL_PACKETVTable->m_pfnToType(SptShort, pValue));
		else if (pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimL_PACKETVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimL_PACKETVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimL_PACKETVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_L_PACKET_string(const char* strValue) {
	static L_PACKET rTemp;
	return string_to_L_PACKET(strValue, &rTemp);
}


/****************************************************************
 ** NID_LRBG
 ****************************************************************/
struct SimTypeVTable* pSimNID_LRBGVTable;
const char * NID_LRBG_to_string(const void* pValue) {
	if (pSimNID_LRBGVTable != 0 && pSimNID_LRBGVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimNID_LRBGVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_NID_LRBG(const char* strValue, void* pValue) {
	if (pSimNID_LRBGVTable != 0 && pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static NID_LRBG rTemp;
		int nResult = pSimNID_LRBGVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((NID_LRBG*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_NID_LRBG_allow_double_convertion() {
	if (pSimNID_LRBGVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int NID_LRBG_to_double(double * nValue, const void* pValue) {
	if (pSimNID_LRBGVTable != 0) {
		if (pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimNID_LRBGVTable->m_pfnToType(SptLong, pValue));
		else if (pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimNID_LRBGVTable->m_pfnToType(SptShort, pValue));
		else if (pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimNID_LRBGVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimNID_LRBGVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimNID_LRBGVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_NID_LRBG_string(const char* strValue) {
	static NID_LRBG rTemp;
	return string_to_NID_LRBG(strValue, &rTemp);
}


/****************************************************************
 ** B_data_internal_FirstTest_InfraLibInt
 ****************************************************************/
struct SimTypeVTable* pSimB_data_internal_FirstTest_InfraLibIntVTable;
const char * B_data_internal_FirstTest_InfraLibInt_to_string(const void* pValue) {
	if (pSimB_data_internal_FirstTest_InfraLibIntVTable != 0 && pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnToType(SptString, pValue);
	return struct__5636_to_string(pValue);
}

int string_to_B_data_internal_FirstTest_InfraLibInt(const char* strValue, void* pValue) {
	if (pSimB_data_internal_FirstTest_InfraLibIntVTable != 0 && pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static B_data_internal_FirstTest_InfraLibInt rTemp;
		int nResult = pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5636(&(*((B_data_internal_FirstTest_InfraLibInt*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5636(strValue, pValue);
}

int is_B_data_internal_FirstTest_InfraLibInt_allow_double_convertion() {
	if (pSimB_data_internal_FirstTest_InfraLibIntVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5636_allow_double_convertion();
}

int B_data_internal_FirstTest_InfraLibInt_to_double(double * nValue, const void* pValue) {
	if (pSimB_data_internal_FirstTest_InfraLibIntVTable != 0) {
		if (pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnToType(SptLong, pValue));
		else if (pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnToType(SptShort, pValue));
		else if (pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5636_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5636_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_B_data_internal_FirstTest_InfraLibInt_string(const char* strValue) {
	static B_data_internal_FirstTest_InfraLibInt rTemp;
	return string_to_B_data_internal_FirstTest_InfraLibInt(strValue, &rTemp);
}


/****************************************************************
 ** CompressedBaliseMessage_TM
 ****************************************************************/
struct SimTypeVTable* pSimCompressedBaliseMessage_TMVTable;
const char * CompressedBaliseMessage_TM_to_string(const void* pValue) {
	if (pSimCompressedBaliseMessage_TMVTable != 0 && pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimCompressedBaliseMessage_TMVTable->m_pfnToType(SptString, pValue);
	return struct__5623_to_string(pValue);
}

int string_to_CompressedBaliseMessage_TM(const char* strValue, void* pValue) {
	if (pSimCompressedBaliseMessage_TMVTable != 0 && pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static CompressedBaliseMessage_TM rTemp;
		int nResult = pSimCompressedBaliseMessage_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5623(&(*((CompressedBaliseMessage_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5623(strValue, pValue);
}

int is_CompressedBaliseMessage_TM_allow_double_convertion() {
	if (pSimCompressedBaliseMessage_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5623_allow_double_convertion();
}

int CompressedBaliseMessage_TM_to_double(double * nValue, const void* pValue) {
	if (pSimCompressedBaliseMessage_TMVTable != 0) {
		if (pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimCompressedBaliseMessage_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimCompressedBaliseMessage_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimCompressedBaliseMessage_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimCompressedBaliseMessage_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5623_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5623_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_CompressedBaliseMessage_TM_string(const char* strValue) {
	static CompressedBaliseMessage_TM rTemp;
	return string_to_CompressedBaliseMessage_TM(strValue, &rTemp);
}


/****************************************************************
 ** BaliseTelegramHeader_int_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimBaliseTelegramHeader_int_T_TMVTable;
const char * BaliseTelegramHeader_int_T_TM_to_string(const void* pValue) {
	if (pSimBaliseTelegramHeader_int_T_TMVTable != 0 && pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnToType(SptString, pValue);
	return struct__5610_to_string(pValue);
}

int string_to_BaliseTelegramHeader_int_T_TM(const char* strValue, void* pValue) {
	if (pSimBaliseTelegramHeader_int_T_TMVTable != 0 && pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static BaliseTelegramHeader_int_T_TM rTemp;
		int nResult = pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5610(&(*((BaliseTelegramHeader_int_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5610(strValue, pValue);
}

int is_BaliseTelegramHeader_int_T_TM_allow_double_convertion() {
	if (pSimBaliseTelegramHeader_int_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5610_allow_double_convertion();
}

int BaliseTelegramHeader_int_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimBaliseTelegramHeader_int_T_TMVTable != 0) {
		if (pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5610_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5610_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_BaliseTelegramHeader_int_T_TM_string(const char* strValue) {
	static BaliseTelegramHeader_int_T_TM rTemp;
	return string_to_BaliseTelegramHeader_int_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** OrBG_TM
 ****************************************************************/
struct SimTypeVTable* pSimOrBG_TMVTable;
const char * OrBG_TM_to_string(const void* pValue) {
	if (pSimOrBG_TMVTable != 0 && pSimOrBG_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimOrBG_TMVTable->m_pfnToType(SptString, pValue);
	switch (*((OrBG_TM*)pValue)) {
	case Amsterdam_TM:
		return "TM::Amsterdam";
	case Utrecht_TM:
		return "TM::Utrecht";
	default:
		return "?";
	}
}

int string_to_OrBG_TM(const char* strValue, void* pValue) {
	if (pSimOrBG_TMVTable != 0 && pSimOrBG_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		OrBG_TM rTemp;		int nResult = pSimOrBG_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((OrBG_TM*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "Amsterdam") == 0 || strcmp(strValue, "TM::Amsterdam") == 0)
		*((OrBG_TM*)pValue) = Amsterdam_TM;
	else if(strcmp(strValue, "Utrecht") == 0 || strcmp(strValue, "TM::Utrecht") == 0)
		*((OrBG_TM*)pValue) = Utrecht_TM;
	else 
		return 0;
	return 1;
}

int is_OrBG_TM_allow_double_convertion() {
	return 1;
}


int OrBG_TM_to_double(double * nValue, const void* pValue) {
	switch (*((OrBG_TM*)pValue)) {
	case Amsterdam_TM:
		*nValue = 0.0;
		break;
	case Utrecht_TM:
		*nValue = 1.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_OrBG_TM_type(int* pResult, const char* toCompare, const void* pValue) {
	static OrBG_TM rTemp;
	const OrBG_TM* pCurrent = (const OrBG_TM*)pValue;
	if (string_to_OrBG_TM(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_OrBG_TM_signature() {
	return "E"
		"|TM::Amsterdam"
		"|TM::Utrecht"
		;
}

int check_OrBG_TM_string(const char* strValue) {
	static OrBG_TM rTemp;
	return string_to_OrBG_TM(strValue, &rTemp);
}


/****************************************************************
 ** OrLine_TM
 ****************************************************************/
struct SimTypeVTable* pSimOrLine_TMVTable;
const char * OrLine_TM_to_string(const void* pValue) {
	if (pSimOrLine_TMVTable != 0 && pSimOrLine_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimOrLine_TMVTable->m_pfnToType(SptString, pValue);
	switch (*((OrLine_TM*)pValue)) {
	case N_TM:
		return "TM::N";
	case Z_TM:
		return "TM::Z";
	default:
		return "?";
	}
}

int string_to_OrLine_TM(const char* strValue, void* pValue) {
	if (pSimOrLine_TMVTable != 0 && pSimOrLine_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		OrLine_TM rTemp;		int nResult = pSimOrLine_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((OrLine_TM*)pValue) = rTemp;
		return nResult;
	}
	if(strcmp(strValue, "N") == 0 || strcmp(strValue, "TM::N") == 0)
		*((OrLine_TM*)pValue) = N_TM;
	else if(strcmp(strValue, "Z") == 0 || strcmp(strValue, "TM::Z") == 0)
		*((OrLine_TM*)pValue) = Z_TM;
	else 
		return 0;
	return 1;
}

int is_OrLine_TM_allow_double_convertion() {
	return 1;
}


int OrLine_TM_to_double(double * nValue, const void* pValue) {
	switch (*((OrLine_TM*)pValue)) {
	case N_TM:
		*nValue = 0.0;
		break;
	case Z_TM:
		*nValue = 1.0;
		break;
	default:
		return 0;
	}
	return 1;
}


int compare_OrLine_TM_type(int* pResult, const char* toCompare, const void* pValue) {
	static OrLine_TM rTemp;
	const OrLine_TM* pCurrent = (const OrLine_TM*)pValue;
	if (string_to_OrLine_TM(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

const char * get_OrLine_TM_signature() {
	return "E"
		"|TM::N"
		"|TM::Z"
		;
}

int check_OrLine_TM_string(const char* strValue) {
	static OrLine_TM rTemp;
	return string_to_OrLine_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_trackside_int_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_trackside_int_T_TMVTable;
const char * P005_trackside_int_T_TM_to_string(const void* pValue) {
	if (pSimP005_trackside_int_T_TMVTable != 0 && pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_trackside_int_T_TMVTable->m_pfnToType(SptString, pValue);
	return struct__5658_to_string(pValue);
}

int string_to_P005_trackside_int_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_trackside_int_T_TMVTable != 0 && pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_trackside_int_T_TM rTemp;
		int nResult = pSimP005_trackside_int_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5658(&(*((P005_trackside_int_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5658(strValue, pValue);
}

int is_P005_trackside_int_T_TM_allow_double_convertion() {
	if (pSimP005_trackside_int_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5658_allow_double_convertion();
}

int P005_trackside_int_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_trackside_int_T_TMVTable != 0) {
		if (pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_trackside_int_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_trackside_int_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_trackside_int_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_trackside_int_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5658_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5658_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_trackside_int_T_TM_string(const char* strValue) {
	static P005_trackside_int_T_TM rTemp;
	return string_to_P005_trackside_int_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_trackide_sectionlist_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_trackide_sectionlist_T_TMVTable;
const char * P005_trackide_sectionlist_T_TM_to_string(const void* pValue) {
	if (pSimP005_trackide_sectionlist_T_TMVTable != 0 && pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_trackide_sectionlist_T_TMVTable->m_pfnToType(SptString, pValue);
	return array__5655_to_string(pValue);
}

int string_to_P005_trackide_sectionlist_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_trackide_sectionlist_T_TMVTable != 0 && pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_trackide_sectionlist_T_TM rTemp;
		int nResult = pSimP005_trackide_sectionlist_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array__5655(&(*((P005_trackide_sectionlist_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array__5655(strValue, pValue);
}

int is_P005_trackide_sectionlist_T_TM_allow_double_convertion() {
	if (pSimP005_trackide_sectionlist_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array__5655_allow_double_convertion();
}

int P005_trackide_sectionlist_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_trackide_sectionlist_T_TMVTable != 0) {
		if (pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_trackide_sectionlist_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_trackide_sectionlist_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_trackide_sectionlist_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_trackide_sectionlist_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array__5655_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array__5655_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_trackide_sectionlist_T_TM_string(const char* strValue) {
	static P005_trackide_sectionlist_T_TM rTemp;
	return string_to_P005_trackide_sectionlist_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_section_int_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_section_int_T_TMVTable;
const char * P005_section_int_T_TM_to_string(const void* pValue) {
	if (pSimP005_section_int_T_TMVTable != 0 && pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_section_int_T_TMVTable->m_pfnToType(SptString, pValue);
	return struct__5645_to_string(pValue);
}

int string_to_P005_section_int_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_section_int_T_TMVTable != 0 && pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_section_int_T_TM rTemp;
		int nResult = pSimP005_section_int_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5645(&(*((P005_section_int_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5645(strValue, pValue);
}

int is_P005_section_int_T_TM_allow_double_convertion() {
	if (pSimP005_section_int_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5645_allow_double_convertion();
}

int P005_section_int_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_section_int_T_TMVTable != 0) {
		if (pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_section_int_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_section_int_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_section_int_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_section_int_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5645_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5645_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_section_int_T_TM_string(const char* strValue) {
	static P005_section_int_T_TM rTemp;
	return string_to_P005_section_int_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_sections_array_flat_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_sections_array_flat_T_TMVTable;
const char * P005_sections_array_flat_T_TM_to_string(const void* pValue) {
	if (pSimP005_sections_array_flat_T_TMVTable != 0 && pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_sections_array_flat_T_TMVTable->m_pfnToType(SptString, pValue);
	return array_int_224_to_string(pValue);
}

int string_to_P005_sections_array_flat_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_sections_array_flat_T_TMVTable != 0 && pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_sections_array_flat_T_TM rTemp;
		int nResult = pSimP005_sections_array_flat_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_int_224(&(*((P005_sections_array_flat_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_int_224(strValue, pValue);
}

int is_P005_sections_array_flat_T_TM_allow_double_convertion() {
	if (pSimP005_sections_array_flat_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_int_224_allow_double_convertion();
}

int P005_sections_array_flat_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_sections_array_flat_T_TMVTable != 0) {
		if (pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_sections_array_flat_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_sections_array_flat_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_sections_array_flat_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_sections_array_flat_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_int_224_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_int_224_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_sections_array_flat_T_TM_string(const char* strValue) {
	static P005_sections_array_flat_T_TM rTemp;
	return string_to_P005_sections_array_flat_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_OBU_sectionlist_array_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_OBU_sectionlist_array_T_TMVTable;
const char * P005_OBU_sectionlist_array_T_TM_to_string(const void* pValue) {
	if (pSimP005_OBU_sectionlist_array_T_TMVTable != 0 && pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnToType(SptString, pValue);
	return array_int_7_33_to_string(pValue);
}

int string_to_P005_OBU_sectionlist_array_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_OBU_sectionlist_array_T_TMVTable != 0 && pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_OBU_sectionlist_array_T_TM rTemp;
		int nResult = pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_int_7_33(&(*((P005_OBU_sectionlist_array_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_int_7_33(strValue, pValue);
}

int is_P005_OBU_sectionlist_array_T_TM_allow_double_convertion() {
	if (pSimP005_OBU_sectionlist_array_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_int_7_33_allow_double_convertion();
}

int P005_OBU_sectionlist_array_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_OBU_sectionlist_array_T_TMVTable != 0) {
		if (pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_int_7_33_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_int_7_33_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_OBU_sectionlist_array_T_TM_string(const char* strValue) {
	static P005_OBU_sectionlist_array_T_TM rTemp;
	return string_to_P005_OBU_sectionlist_array_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_section_array_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_section_array_T_TMVTable;
const char * P005_section_array_T_TM_to_string(const void* pValue) {
	if (pSimP005_section_array_T_TMVTable != 0 && pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_section_array_T_TMVTable->m_pfnToType(SptString, pValue);
	return array_int_7_to_string(pValue);
}

int string_to_P005_section_array_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_section_array_T_TMVTable != 0 && pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_section_array_T_TM rTemp;
		int nResult = pSimP005_section_array_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_int_7(&(*((P005_section_array_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_int_7(strValue, pValue);
}

int is_P005_section_array_T_TM_allow_double_convertion() {
	if (pSimP005_section_array_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_int_7_allow_double_convertion();
}

int P005_section_array_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_section_array_T_TMVTable != 0) {
		if (pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_section_array_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_section_array_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_section_array_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_section_array_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_int_7_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_int_7_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_section_array_T_TM_string(const char* strValue) {
	static P005_section_array_T_TM rTemp;
	return string_to_P005_section_array_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_OBU_sectionlist_int_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_OBU_sectionlist_int_T_TMVTable;
const char * P005_OBU_sectionlist_int_T_TM_to_string(const void* pValue) {
	if (pSimP005_OBU_sectionlist_int_T_TMVTable != 0 && pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnToType(SptString, pValue);
	return array__5681_to_string(pValue);
}

int string_to_P005_OBU_sectionlist_int_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_OBU_sectionlist_int_T_TMVTable != 0 && pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_OBU_sectionlist_int_T_TM rTemp;
		int nResult = pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array__5681(&(*((P005_OBU_sectionlist_int_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array__5681(strValue, pValue);
}

int is_P005_OBU_sectionlist_int_T_TM_allow_double_convertion() {
	if (pSimP005_OBU_sectionlist_int_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array__5681_allow_double_convertion();
}

int P005_OBU_sectionlist_int_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_OBU_sectionlist_int_T_TMVTable != 0) {
		if (pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array__5681_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array__5681_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_OBU_sectionlist_int_T_TM_string(const char* strValue) {
	static P005_OBU_sectionlist_int_T_TM rTemp;
	return string_to_P005_OBU_sectionlist_int_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** BaliseGroupData_TM
 ****************************************************************/
struct SimTypeVTable* pSimBaliseGroupData_TMVTable;
const char * BaliseGroupData_TM_to_string(const void* pValue) {
	if (pSimBaliseGroupData_TMVTable != 0 && pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimBaliseGroupData_TMVTable->m_pfnToType(SptString, pValue);
	return struct__5628_to_string(pValue);
}

int string_to_BaliseGroupData_TM(const char* strValue, void* pValue) {
	if (pSimBaliseGroupData_TMVTable != 0 && pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static BaliseGroupData_TM rTemp;
		int nResult = pSimBaliseGroupData_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5628(&(*((BaliseGroupData_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5628(strValue, pValue);
}

int is_BaliseGroupData_TM_allow_double_convertion() {
	if (pSimBaliseGroupData_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5628_allow_double_convertion();
}

int BaliseGroupData_TM_to_double(double * nValue, const void* pValue) {
	if (pSimBaliseGroupData_TMVTable != 0) {
		if (pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimBaliseGroupData_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimBaliseGroupData_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimBaliseGroupData_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimBaliseGroupData_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5628_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5628_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_BaliseGroupData_TM_string(const char* strValue) {
	static BaliseGroupData_TM rTemp;
	return string_to_BaliseGroupData_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_section_enum_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_section_enum_T_TMVTable;
const char * P005_section_enum_T_TM_to_string(const void* pValue) {
	if (pSimP005_section_enum_T_TMVTable != 0 && pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_section_enum_T_TMVTable->m_pfnToType(SptString, pValue);
	return struct__5581_to_string(pValue);
}

int string_to_P005_section_enum_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_section_enum_T_TMVTable != 0 && pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_section_enum_T_TM rTemp;
		int nResult = pSimP005_section_enum_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5581(&(*((P005_section_enum_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5581(strValue, pValue);
}

int is_P005_section_enum_T_TM_allow_double_convertion() {
	if (pSimP005_section_enum_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5581_allow_double_convertion();
}

int P005_section_enum_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_section_enum_T_TMVTable != 0) {
		if (pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_section_enum_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_section_enum_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_section_enum_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_section_enum_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5581_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5581_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_section_enum_T_TM_string(const char* strValue) {
	static P005_section_enum_T_TM rTemp;
	return string_to_P005_section_enum_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_OBU_sectionlist_enum_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_OBU_sectionlist_enum_T_TMVTable;
const char * P005_OBU_sectionlist_enum_T_TM_to_string(const void* pValue) {
	if (pSimP005_OBU_sectionlist_enum_T_TMVTable != 0 && pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnToType(SptString, pValue);
	return array__5592_to_string(pValue);
}

int string_to_P005_OBU_sectionlist_enum_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_OBU_sectionlist_enum_T_TMVTable != 0 && pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_OBU_sectionlist_enum_T_TM rTemp;
		int nResult = pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array__5592(&(*((P005_OBU_sectionlist_enum_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array__5592(strValue, pValue);
}

int is_P005_OBU_sectionlist_enum_T_TM_allow_double_convertion() {
	if (pSimP005_OBU_sectionlist_enum_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array__5592_allow_double_convertion();
}

int P005_OBU_sectionlist_enum_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_OBU_sectionlist_enum_T_TMVTable != 0) {
		if (pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array__5592_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array__5592_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_OBU_sectionlist_enum_T_TM_string(const char* strValue) {
	static P005_OBU_sectionlist_enum_T_TM rTemp;
	return string_to_P005_OBU_sectionlist_enum_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** P005_OBU_T_TM
 ****************************************************************/
struct SimTypeVTable* pSimP005_OBU_T_TMVTable;
const char * P005_OBU_T_TM_to_string(const void* pValue) {
	if (pSimP005_OBU_T_TMVTable != 0 && pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimP005_OBU_T_TMVTable->m_pfnToType(SptString, pValue);
	return struct__5595_to_string(pValue);
}

int string_to_P005_OBU_T_TM(const char* strValue, void* pValue) {
	if (pSimP005_OBU_T_TMVTable != 0 && pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static P005_OBU_T_TM rTemp;
		int nResult = pSimP005_OBU_T_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5595(&(*((P005_OBU_T_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5595(strValue, pValue);
}

int is_P005_OBU_T_TM_allow_double_convertion() {
	if (pSimP005_OBU_T_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5595_allow_double_convertion();
}

int P005_OBU_T_TM_to_double(double * nValue, const void* pValue) {
	if (pSimP005_OBU_T_TMVTable != 0) {
		if (pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimP005_OBU_T_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimP005_OBU_T_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimP005_OBU_T_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimP005_OBU_T_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5595_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5595_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_P005_OBU_T_TM_string(const char* strValue) {
	static P005_OBU_T_TM rTemp;
	return string_to_P005_OBU_T_TM(strValue, &rTemp);
}


/****************************************************************
 ** Array03_TM
 ****************************************************************/
struct SimTypeVTable* pSimArray03_TMVTable;
const char * Array03_TM_to_string(const void* pValue) {
	if (pSimArray03_TMVTable != 0 && pSimArray03_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimArray03_TMVTable->m_pfnToType(SptString, pValue);
	return array_int_3_to_string(pValue);
}

int string_to_Array03_TM(const char* strValue, void* pValue) {
	if (pSimArray03_TMVTable != 0 && pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static Array03_TM rTemp;
		int nResult = pSimArray03_TMVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_int_3(&(*((Array03_TM*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_int_3(strValue, pValue);
}

int is_Array03_TM_allow_double_convertion() {
	if (pSimArray03_TMVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_int_3_allow_double_convertion();
}

int Array03_TM_to_double(double * nValue, const void* pValue) {
	if (pSimArray03_TMVTable != 0) {
		if (pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimArray03_TMVTable->m_pfnToType(SptLong, pValue));
		else if (pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimArray03_TMVTable->m_pfnToType(SptShort, pValue));
		else if (pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimArray03_TMVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimArray03_TMVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimArray03_TMVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_int_3_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_int_3_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_Array03_TM_string(const char* strValue) {
	static Array03_TM rTemp;
	return string_to_Array03_TM(strValue, &rTemp);
}


/****************************************************************
 ** CompressedPackets_T_Common_Types_Pkg
 ****************************************************************/
struct SimTypeVTable* pSimCompressedPackets_T_Common_Types_PkgVTable;
const char * CompressedPackets_T_Common_Types_Pkg_to_string(const void* pValue) {
	if (pSimCompressedPackets_T_Common_Types_PkgVTable != 0 && pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue);
	return struct__5576_to_string(pValue);
}

int string_to_CompressedPackets_T_Common_Types_Pkg(const char* strValue, void* pValue) {
	if (pSimCompressedPackets_T_Common_Types_PkgVTable != 0 && pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static CompressedPackets_T_Common_Types_Pkg rTemp;
		int nResult = pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5576(&(*((CompressedPackets_T_Common_Types_Pkg*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5576(strValue, pValue);
}

int is_CompressedPackets_T_Common_Types_Pkg_allow_double_convertion() {
	if (pSimCompressedPackets_T_Common_Types_PkgVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5576_allow_double_convertion();
}

int CompressedPackets_T_Common_Types_Pkg_to_double(double * nValue, const void* pValue) {
	if (pSimCompressedPackets_T_Common_Types_PkgVTable != 0) {
		if (pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnToType(SptLong, pValue));
		else if (pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnToType(SptShort, pValue));
		else if (pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5576_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5576_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_CompressedPackets_T_Common_Types_Pkg_string(const char* strValue) {
	static CompressedPackets_T_Common_Types_Pkg rTemp;
	return string_to_CompressedPackets_T_Common_Types_Pkg(strValue, &rTemp);
}


/****************************************************************
 ** Metadata_T_Common_Types_Pkg
 ****************************************************************/
struct SimTypeVTable* pSimMetadata_T_Common_Types_PkgVTable;
const char * Metadata_T_Common_Types_Pkg_to_string(const void* pValue) {
	if (pSimMetadata_T_Common_Types_PkgVTable != 0 && pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimMetadata_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue);
	return array__5573_to_string(pValue);
}

int string_to_Metadata_T_Common_Types_Pkg(const char* strValue, void* pValue) {
	if (pSimMetadata_T_Common_Types_PkgVTable != 0 && pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static Metadata_T_Common_Types_Pkg rTemp;
		int nResult = pSimMetadata_T_Common_Types_PkgVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array__5573(&(*((Metadata_T_Common_Types_Pkg*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array__5573(strValue, pValue);
}

int is_Metadata_T_Common_Types_Pkg_allow_double_convertion() {
	if (pSimMetadata_T_Common_Types_PkgVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array__5573_allow_double_convertion();
}

int Metadata_T_Common_Types_Pkg_to_double(double * nValue, const void* pValue) {
	if (pSimMetadata_T_Common_Types_PkgVTable != 0) {
		if (pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimMetadata_T_Common_Types_PkgVTable->m_pfnToType(SptLong, pValue));
		else if (pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimMetadata_T_Common_Types_PkgVTable->m_pfnToType(SptShort, pValue));
		else if (pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimMetadata_T_Common_Types_PkgVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimMetadata_T_Common_Types_PkgVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array__5573_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array__5573_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_Metadata_T_Common_Types_Pkg_string(const char* strValue) {
	static Metadata_T_Common_Types_Pkg rTemp;
	return string_to_Metadata_T_Common_Types_Pkg(strValue, &rTemp);
}


/****************************************************************
 ** MetadataElement_T_Common_Types_Pkg
 ****************************************************************/
struct SimTypeVTable* pSimMetadataElement_T_Common_Types_PkgVTable;
const char * MetadataElement_T_Common_Types_Pkg_to_string(const void* pValue) {
	if (pSimMetadataElement_T_Common_Types_PkgVTable != 0 && pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue);
	return struct__5565_to_string(pValue);
}

int string_to_MetadataElement_T_Common_Types_Pkg(const char* strValue, void* pValue) {
	if (pSimMetadataElement_T_Common_Types_PkgVTable != 0 && pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static MetadataElement_T_Common_Types_Pkg rTemp;
		int nResult = pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5565(&(*((MetadataElement_T_Common_Types_Pkg*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5565(strValue, pValue);
}

int is_MetadataElement_T_Common_Types_Pkg_allow_double_convertion() {
	if (pSimMetadataElement_T_Common_Types_PkgVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5565_allow_double_convertion();
}

int MetadataElement_T_Common_Types_Pkg_to_double(double * nValue, const void* pValue) {
	if (pSimMetadataElement_T_Common_Types_PkgVTable != 0) {
		if (pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnToType(SptLong, pValue));
		else if (pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnToType(SptShort, pValue));
		else if (pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5565_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5565_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_MetadataElement_T_Common_Types_Pkg_string(const char* strValue) {
	static MetadataElement_T_Common_Types_Pkg rTemp;
	return string_to_MetadataElement_T_Common_Types_Pkg(strValue, &rTemp);
}


/****************************************************************
 ** CompressedPacketData_T_Common_Types_Pkg
 ****************************************************************/
struct SimTypeVTable* pSimCompressedPacketData_T_Common_Types_PkgVTable;
const char * CompressedPacketData_T_Common_Types_Pkg_to_string(const void* pValue) {
	if (pSimCompressedPacketData_T_Common_Types_PkgVTable != 0 && pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue);
	return array_int_500_to_string(pValue);
}

int string_to_CompressedPacketData_T_Common_Types_Pkg(const char* strValue, void* pValue) {
	if (pSimCompressedPacketData_T_Common_Types_PkgVTable != 0 && pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static CompressedPacketData_T_Common_Types_Pkg rTemp;
		int nResult = pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_int_500(&(*((CompressedPacketData_T_Common_Types_Pkg*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_int_500(strValue, pValue);
}

int is_CompressedPacketData_T_Common_Types_Pkg_allow_double_convertion() {
	if (pSimCompressedPacketData_T_Common_Types_PkgVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_int_500_allow_double_convertion();
}

int CompressedPacketData_T_Common_Types_Pkg_to_double(double * nValue, const void* pValue) {
	if (pSimCompressedPacketData_T_Common_Types_PkgVTable != 0) {
		if (pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnToType(SptLong, pValue));
		else if (pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnToType(SptShort, pValue));
		else if (pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_int_500_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_int_500_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_CompressedPacketData_T_Common_Types_Pkg_string(const char* strValue) {
	static CompressedPacketData_T_Common_Types_Pkg rTemp;
	return string_to_CompressedPacketData_T_Common_Types_Pkg(strValue, &rTemp);
}


/****************************************************************
 ** BaliseGroupData_Basics
 ****************************************************************/
struct SimTypeVTable* pSimBaliseGroupData_BasicsVTable;
const char * BaliseGroupData_Basics_to_string(const void* pValue) {
	if (pSimBaliseGroupData_BasicsVTable != 0 && pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimBaliseGroupData_BasicsVTable->m_pfnToType(SptString, pValue);
	return struct__5628_to_string(pValue);
}

int string_to_BaliseGroupData_Basics(const char* strValue, void* pValue) {
	if (pSimBaliseGroupData_BasicsVTable != 0 && pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static BaliseGroupData_Basics rTemp;
		int nResult = pSimBaliseGroupData_BasicsVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5628(&(*((BaliseGroupData_Basics*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5628(strValue, pValue);
}

int is_BaliseGroupData_Basics_allow_double_convertion() {
	if (pSimBaliseGroupData_BasicsVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5628_allow_double_convertion();
}

int BaliseGroupData_Basics_to_double(double * nValue, const void* pValue) {
	if (pSimBaliseGroupData_BasicsVTable != 0) {
		if (pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimBaliseGroupData_BasicsVTable->m_pfnToType(SptLong, pValue));
		else if (pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimBaliseGroupData_BasicsVTable->m_pfnToType(SptShort, pValue));
		else if (pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimBaliseGroupData_BasicsVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimBaliseGroupData_BasicsVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5628_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5628_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_BaliseGroupData_Basics_string(const char* strValue) {
	static BaliseGroupData_Basics rTemp;
	return string_to_BaliseGroupData_Basics(strValue, &rTemp);
}


/****************************************************************
 ** B_data_internal_T_InfraLib
 ****************************************************************/
struct SimTypeVTable* pSimB_data_internal_T_InfraLibVTable;
const char * B_data_internal_T_InfraLib_to_string(const void* pValue) {
	if (pSimB_data_internal_T_InfraLibVTable != 0 && pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimB_data_internal_T_InfraLibVTable->m_pfnToType(SptString, pValue);
	return struct__5636_to_string(pValue);
}

int string_to_B_data_internal_T_InfraLib(const char* strValue, void* pValue) {
	if (pSimB_data_internal_T_InfraLibVTable != 0 && pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static B_data_internal_T_InfraLib rTemp;
		int nResult = pSimB_data_internal_T_InfraLibVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5636(&(*((B_data_internal_T_InfraLib*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5636(strValue, pValue);
}

int is_B_data_internal_T_InfraLib_allow_double_convertion() {
	if (pSimB_data_internal_T_InfraLibVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5636_allow_double_convertion();
}

int B_data_internal_T_InfraLib_to_double(double * nValue, const void* pValue) {
	if (pSimB_data_internal_T_InfraLibVTable != 0) {
		if (pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimB_data_internal_T_InfraLibVTable->m_pfnToType(SptLong, pValue));
		else if (pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimB_data_internal_T_InfraLibVTable->m_pfnToType(SptShort, pValue));
		else if (pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimB_data_internal_T_InfraLibVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimB_data_internal_T_InfraLibVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5636_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5636_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_B_data_internal_T_InfraLib_string(const char* strValue) {
	static B_data_internal_T_InfraLib rTemp;
	return string_to_B_data_internal_T_InfraLib(strValue, &rTemp);
}


/****************************************************************
 ** TelegramHeader_T_BG_Types_Pkg
 ****************************************************************/
struct SimTypeVTable* pSimTelegramHeader_T_BG_Types_PkgVTable;
const char * TelegramHeader_T_BG_Types_Pkg_to_string(const void* pValue) {
	if (pSimTelegramHeader_T_BG_Types_PkgVTable != 0 && pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnToType(SptString, pValue);
	return struct__5549_to_string(pValue);
}

int string_to_TelegramHeader_T_BG_Types_Pkg(const char* strValue, void* pValue) {
	if (pSimTelegramHeader_T_BG_Types_PkgVTable != 0 && pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static TelegramHeader_T_BG_Types_Pkg rTemp;
		int nResult = pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5549(&(*((TelegramHeader_T_BG_Types_Pkg*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5549(strValue, pValue);
}

int is_TelegramHeader_T_BG_Types_Pkg_allow_double_convertion() {
	if (pSimTelegramHeader_T_BG_Types_PkgVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5549_allow_double_convertion();
}

int TelegramHeader_T_BG_Types_Pkg_to_double(double * nValue, const void* pValue) {
	if (pSimTelegramHeader_T_BG_Types_PkgVTable != 0) {
		if (pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnToType(SptLong, pValue));
		else if (pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnToType(SptShort, pValue));
		else if (pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5549_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5549_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_TelegramHeader_T_BG_Types_Pkg_string(const char* strValue) {
	static TelegramHeader_T_BG_Types_Pkg rTemp;
	return string_to_TelegramHeader_T_BG_Types_Pkg(strValue, &rTemp);
}


/****************************************************************
 ** LinkedBG_T_BG_Types_Pkg
 ****************************************************************/
struct SimTypeVTable* pSimLinkedBG_T_BG_Types_PkgVTable;
const char * LinkedBG_T_BG_Types_Pkg_to_string(const void* pValue) {
	if (pSimLinkedBG_T_BG_Types_PkgVTable != 0 && pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnToType(SptString, pValue);
	return struct__5532_to_string(pValue);
}

int string_to_LinkedBG_T_BG_Types_Pkg(const char* strValue, void* pValue) {
	if (pSimLinkedBG_T_BG_Types_PkgVTable != 0 && pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static LinkedBG_T_BG_Types_Pkg rTemp;
		int nResult = pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__5532(&(*((LinkedBG_T_BG_Types_Pkg*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__5532(strValue, pValue);
}

int is_LinkedBG_T_BG_Types_Pkg_allow_double_convertion() {
	if (pSimLinkedBG_T_BG_Types_PkgVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__5532_allow_double_convertion();
}

int LinkedBG_T_BG_Types_Pkg_to_double(double * nValue, const void* pValue) {
	if (pSimLinkedBG_T_BG_Types_PkgVTable != 0) {
		if (pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnToType(SptLong, pValue));
		else if (pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnToType(SptShort, pValue));
		else if (pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__5532_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__5532_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_LinkedBG_T_BG_Types_Pkg_string(const char* strValue) {
	static LinkedBG_T_BG_Types_Pkg rTemp;
	return string_to_LinkedBG_T_BG_Types_Pkg(strValue, &rTemp);
}


/****************************************************************
 ** LinkedBGs_T_BG_Types_Pkg
 ****************************************************************/
struct SimTypeVTable* pSimLinkedBGs_T_BG_Types_PkgVTable;
const char * LinkedBGs_T_BG_Types_Pkg_to_string(const void* pValue) {
	if (pSimLinkedBGs_T_BG_Types_PkgVTable != 0 && pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnToType(SptString, pValue);
	return array__5546_to_string(pValue);
}

int string_to_LinkedBGs_T_BG_Types_Pkg(const char* strValue, void* pValue) {
	if (pSimLinkedBGs_T_BG_Types_PkgVTable != 0 && pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static LinkedBGs_T_BG_Types_Pkg rTemp;
		int nResult = pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array__5546(&(*((LinkedBGs_T_BG_Types_Pkg*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array__5546(strValue, pValue);
}

int is_LinkedBGs_T_BG_Types_Pkg_allow_double_convertion() {
	if (pSimLinkedBGs_T_BG_Types_PkgVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array__5546_allow_double_convertion();
}

int LinkedBGs_T_BG_Types_Pkg_to_double(double * nValue, const void* pValue) {
	if (pSimLinkedBGs_T_BG_Types_PkgVTable != 0) {
		if (pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnToType(SptLong, pValue));
		else if (pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnToType(SptShort, pValue));
		else if (pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array__5546_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array__5546_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_LinkedBGs_T_BG_Types_Pkg_string(const char* strValue) {
	static LinkedBGs_T_BG_Types_Pkg rTemp;
	return string_to_LinkedBGs_T_BG_Types_Pkg(strValue, &rTemp);
}


