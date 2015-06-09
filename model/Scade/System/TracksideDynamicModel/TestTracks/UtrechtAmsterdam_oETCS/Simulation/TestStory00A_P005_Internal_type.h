#ifndef TESTSTORY00A_P005_INTERNAL_TYPES_CONVERTION
#define TESTSTORY00A_P005_INTERNAL_TYPES_CONVERTION

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
extern int _SCSIM_BoolEntity_is_active(void* pValue);

/****************************************************************
 ** Type utils declarations
 ****************************************************************/
extern TypeUtils _SCSIM_kcg_real_Utils;
extern TypeUtils _SCSIM_kcg_bool_Utils;
extern TypeUtils _SCSIM_kcg_char_Utils;
extern TypeUtils _SCSIM_kcg_int_Utils;
extern TypeUtils _SCSIM_struct__5278_Utils;
extern TypeUtils _SCSIM_array__5292_Utils;
extern TypeUtils _SCSIM_struct__5295_Utils;
extern TypeUtils _SCSIM_array_int_500_Utils;
extern TypeUtils _SCSIM_struct__5311_Utils;
extern TypeUtils _SCSIM_array__5319_Utils;
extern TypeUtils _SCSIM_struct__5322_Utils;
extern TypeUtils _SCSIM_struct__5327_Utils;
extern TypeUtils _SCSIM_array__5338_Utils;
extern TypeUtils _SCSIM_struct__5341_Utils;
extern TypeUtils _SCSIM_array_int_231_Utils;
extern TypeUtils _SCSIM_array_int_3_Utils;
extern TypeUtils _SCSIM_struct__5356_Utils;
extern TypeUtils _SCSIM_struct__5369_Utils;
extern TypeUtils _SCSIM_struct__5374_Utils;
extern TypeUtils _SCSIM_struct__5383_Utils;
extern TypeUtils _SCSIM_struct__5391_Utils;
extern TypeUtils _SCSIM_array__5401_Utils;
extern TypeUtils _SCSIM_struct__5404_Utils;
extern TypeUtils _SCSIM_array_int_7_Utils;
extern TypeUtils _SCSIM_array_int_7_33_Utils;
extern TypeUtils _SCSIM_array__5427_Utils;
extern TypeUtils _SCSIM_array_int_500_500_Utils;
extern TypeUtils _SCSIM_array_int_7_33_231_Utils;
extern TypeUtils _SCSIM_array_int_264_Utils;
extern TypeUtils _SCSIM_array_int_4_Utils;
extern TypeUtils _SCSIM_array_int_1_Utils;
extern TypeUtils _SCSIM_array_int_5_Utils;
extern TypeUtils _SCSIM_array_int_236_Utils;
extern TypeUtils _SCSIM_array__5451_Utils;
extern TypeUtils _SCSIM_array_int_30_Utils;
extern TypeUtils _SCSIM_array_int_33_Utils;
extern TypeUtils _SCSIM_array_int_231_33_Utils;
extern TypeUtils _SCSIM_array__5463_Utils;
extern TypeUtils _SCSIM_array__5466_Utils;
extern TypeUtils _SCSIM_array__5469_Utils;
extern TypeUtils _SCSIM_NID_PACKET_Utils;
extern TypeUtils _SCSIM_Q_DIR_Utils;
extern TypeUtils _SCSIM_Q_UPDOWN_Utils;
extern TypeUtils _SCSIM_M_VERSION_Utils;
extern TypeUtils _SCSIM_Q_MEDIA_Utils;
extern TypeUtils _SCSIM_N_PIG_Utils;
extern TypeUtils _SCSIM_N_TOTAL_Utils;
extern TypeUtils _SCSIM_M_DUP_Utils;
extern TypeUtils _SCSIM_M_MCOUNT_Utils;
extern TypeUtils _SCSIM_NID_C_Utils;
extern TypeUtils _SCSIM_NID_BG_Utils;
extern TypeUtils _SCSIM_Q_LINK_Utils;
extern TypeUtils _SCSIM_Q_SCALE_Utils;
extern TypeUtils _SCSIM_D_LINK_Utils;
extern TypeUtils _SCSIM_Q_NEWCOUNTRY_Utils;
extern TypeUtils _SCSIM_Q_LINKORIENTATION_Utils;
extern TypeUtils _SCSIM_Q_LINKREACTION_Utils;
extern TypeUtils _SCSIM_Q_LOCACC_Utils;
extern TypeUtils _SCSIM_N_ITER_Utils;
extern TypeUtils _SCSIM_L_PACKET_Utils;
extern TypeUtils _SCSIM_NID_LRBG_Utils;
extern TypeUtils _SCSIM_CompressedBaliseMessage_TM_Utils;
extern TypeUtils _SCSIM_BaliseTelegramHeader_int_T_TM_Utils;
extern TypeUtils _SCSIM_OrBG_TM_Utils;
extern TypeUtils _SCSIM_OrLine_TM_Utils;
extern TypeUtils _SCSIM_P005_trackside_int_T_TM_Utils;
extern TypeUtils _SCSIM_P005_trackide_sectionlist_T_TM_Utils;
extern TypeUtils _SCSIM_P005_section_int_T_TM_Utils;
extern TypeUtils _SCSIM_P005_sections_array_flat_T_TM_Utils;
extern TypeUtils _SCSIM_P005_OBU_sectionlist_array_T_TM_Utils;
extern TypeUtils _SCSIM_P005_section_array_T_TM_Utils;
extern TypeUtils _SCSIM_P005_OBU_sectionlist_int_T_TM_Utils;
extern TypeUtils _SCSIM_BaliseGroupData_TM_Utils;
extern TypeUtils _SCSIM_P005_section_enum_T_TM_Utils;
extern TypeUtils _SCSIM_P005_OBU_sectionlist_enum_T_TM_Utils;
extern TypeUtils _SCSIM_P005_OBU_T_TM_Utils;
extern TypeUtils _SCSIM_Array03_TM_Utils;
extern TypeUtils _SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils;
extern TypeUtils _SCSIM_Metadata_T_Common_Types_Pkg_Utils;
extern TypeUtils _SCSIM_MetadataElement_T_Common_Types_Pkg_Utils;
extern TypeUtils _SCSIM_CompressedPacketData_T_Common_Types_Pkg_Utils;
extern TypeUtils _SCSIM_BaliseGroupData_Basics_Utils;
extern TypeUtils _SCSIM_B_data_internal_T_InfraLib_Utils;
extern TypeUtils _SCSIM_TelegramHeader_T_BG_Types_Pkg_Utils;
extern TypeUtils _SCSIM_LinkedBG_T_BG_Types_Pkg_Utils;
extern TypeUtils _SCSIM_LinkedBGs_T_BG_Types_Pkg_Utils;

/****************************************************************
 ** kcg_real
 ****************************************************************/
extern const char * kcg_real_to_string(const void* pValue);
extern int check_kcg_real_string(const char* strValue);
extern int string_to_kcg_real(const char* strValue, void* pValue);
int is_kcg_real_allow_double_convertion();
extern int kcg_real_to_double(double * nValue, const void*);
extern const char * get_kcg_real_signature();
extern int compare_kcg_real_type(int*, const char*, const void*);
#define kcg_real_filter_size 0
#define get_kcg_real_filter_utils 0
#define kcg_real_filter_values 0
/****************************************************************
 ** kcg_bool
 ****************************************************************/
extern const char * kcg_bool_to_string(const void* pValue);
extern int check_kcg_bool_string(const char* strValue);
extern int string_to_kcg_bool(const char* strValue, void* pValue);
int is_kcg_bool_allow_double_convertion();
extern int kcg_bool_to_double(double * nValue, const void*);
extern const char * get_kcg_bool_signature();
extern int compare_kcg_bool_type(int*, const char*, const void*);
#define kcg_bool_filter_size 0
#define get_kcg_bool_filter_utils 0
#define kcg_bool_filter_values 0
/****************************************************************
 ** kcg_char
 ****************************************************************/
extern const char * kcg_char_to_string(const void* pValue);
extern int check_kcg_char_string(const char* strValue);
extern int string_to_kcg_char(const char* strValue, void* pValue);
int is_kcg_char_allow_double_convertion();
extern int kcg_char_to_double(double * nValue, const void*);
extern const char * get_kcg_char_signature();
extern int compare_kcg_char_type(int*, const char*, const void*);
#define kcg_char_filter_size 0
#define get_kcg_char_filter_utils 0
#define kcg_char_filter_values 0
/****************************************************************
 ** kcg_int
 ****************************************************************/
extern const char * kcg_int_to_string(const void* pValue);
extern int check_kcg_int_string(const char* strValue);
extern int string_to_kcg_int(const char* strValue, void* pValue);
int is_kcg_int_allow_double_convertion();
extern int kcg_int_to_double(double * nValue, const void*);
extern const char * get_kcg_int_signature();
extern int compare_kcg_int_type(int*, const char*, const void*);
#define kcg_int_filter_size 0
#define get_kcg_int_filter_utils 0
#define kcg_int_filter_values 0
/****************************************************************
 ** struct__5278
 ****************************************************************/
extern const char * struct__5278_to_string(const void* pValue);
extern int check_struct__5278_string(const char* strValue);
extern int string_to_struct__5278(const char* strValue, void* pValue);
int is_struct__5278_allow_double_convertion();
extern const char * get_struct__5278_signature();
extern int compare_struct__5278_type(int*, const char*, const void*);
#define struct__5278_filter_size 11
extern FilterUtils get_struct__5278_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5278_filter_values[11];
/****************************************************************
 ** array__5292
 ****************************************************************/
extern const char * array__5292_to_string(const void* pValue);
extern int check_array__5292_string(const char* strValue);
extern int string_to_array__5292(const char* strValue, void* pValue);
int is_array__5292_allow_double_convertion();
extern const char * get_array__5292_signature();
extern int compare_array__5292_type(int*, const char*, const void*);
#define array__5292_filter_size 4
extern FilterUtils get_array__5292_filter_utils(const char* strFilter, void* pValue);
#define array__5292_filter_values 0
/****************************************************************
 ** struct__5295
 ****************************************************************/
extern const char * struct__5295_to_string(const void* pValue);
extern int check_struct__5295_string(const char* strValue);
extern int string_to_struct__5295(const char* strValue, void* pValue);
int is_struct__5295_allow_double_convertion();
extern const char * get_struct__5295_signature();
extern int compare_struct__5295_type(int*, const char*, const void*);
#define struct__5295_filter_size 10
extern FilterUtils get_struct__5295_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5295_filter_values[10];
/****************************************************************
 ** array_int_500
 ****************************************************************/
extern const char * array_int_500_to_string(const void* pValue);
extern int check_array_int_500_string(const char* strValue);
extern int string_to_array_int_500(const char* strValue, void* pValue);
int is_array_int_500_allow_double_convertion();
extern const char * get_array_int_500_signature();
extern int compare_array_int_500_type(int*, const char*, const void*);
#define array_int_500_filter_size 500
extern FilterUtils get_array_int_500_filter_utils(const char* strFilter, void* pValue);
#define array_int_500_filter_values 0
/****************************************************************
 ** struct__5311
 ****************************************************************/
extern const char * struct__5311_to_string(const void* pValue);
extern int check_struct__5311_string(const char* strValue);
extern int string_to_struct__5311(const char* strValue, void* pValue);
int is_struct__5311_allow_double_convertion();
extern const char * get_struct__5311_signature();
extern int compare_struct__5311_type(int*, const char*, const void*);
#define struct__5311_filter_size 5
extern FilterUtils get_struct__5311_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5311_filter_values[5];
/****************************************************************
 ** array__5319
 ****************************************************************/
extern const char * array__5319_to_string(const void* pValue);
extern int check_array__5319_string(const char* strValue);
extern int string_to_array__5319(const char* strValue, void* pValue);
int is_array__5319_allow_double_convertion();
extern const char * get_array__5319_signature();
extern int compare_array__5319_type(int*, const char*, const void*);
#define array__5319_filter_size 30
extern FilterUtils get_array__5319_filter_utils(const char* strFilter, void* pValue);
#define array__5319_filter_values 0
/****************************************************************
 ** struct__5322
 ****************************************************************/
extern const char * struct__5322_to_string(const void* pValue);
extern int check_struct__5322_string(const char* strValue);
extern int string_to_struct__5322(const char* strValue, void* pValue);
int is_struct__5322_allow_double_convertion();
extern const char * get_struct__5322_signature();
extern int compare_struct__5322_type(int*, const char*, const void*);
#define struct__5322_filter_size 2
extern FilterUtils get_struct__5322_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5322_filter_values[2];
/****************************************************************
 ** struct__5327
 ****************************************************************/
extern const char * struct__5327_to_string(const void* pValue);
extern int check_struct__5327_string(const char* strValue);
extern int string_to_struct__5327(const char* strValue, void* pValue);
int is_struct__5327_allow_double_convertion();
extern const char * get_struct__5327_signature();
extern int compare_struct__5327_type(int*, const char*, const void*);
#define struct__5327_filter_size 8
extern FilterUtils get_struct__5327_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5327_filter_values[8];
/****************************************************************
 ** array__5338
 ****************************************************************/
extern const char * array__5338_to_string(const void* pValue);
extern int check_array__5338_string(const char* strValue);
extern int string_to_array__5338(const char* strValue, void* pValue);
int is_array__5338_allow_double_convertion();
extern const char * get_array__5338_signature();
extern int compare_array__5338_type(int*, const char*, const void*);
#define array__5338_filter_size 33
extern FilterUtils get_array__5338_filter_utils(const char* strFilter, void* pValue);
#define array__5338_filter_values 0
/****************************************************************
 ** struct__5341
 ****************************************************************/
extern const char * struct__5341_to_string(const void* pValue);
extern int check_struct__5341_string(const char* strValue);
extern int string_to_struct__5341(const char* strValue, void* pValue);
int is_struct__5341_allow_double_convertion();
extern const char * get_struct__5341_signature();
extern int compare_struct__5341_type(int*, const char*, const void*);
#define struct__5341_filter_size 6
extern FilterUtils get_struct__5341_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5341_filter_values[6];
/****************************************************************
 ** array_int_231
 ****************************************************************/
extern const char * array_int_231_to_string(const void* pValue);
extern int check_array_int_231_string(const char* strValue);
extern int string_to_array_int_231(const char* strValue, void* pValue);
int is_array_int_231_allow_double_convertion();
extern const char * get_array_int_231_signature();
extern int compare_array_int_231_type(int*, const char*, const void*);
#define array_int_231_filter_size 231
extern FilterUtils get_array_int_231_filter_utils(const char* strFilter, void* pValue);
#define array_int_231_filter_values 0
/****************************************************************
 ** array_int_3
 ****************************************************************/
extern const char * array_int_3_to_string(const void* pValue);
extern int check_array_int_3_string(const char* strValue);
extern int string_to_array_int_3(const char* strValue, void* pValue);
int is_array_int_3_allow_double_convertion();
extern const char * get_array_int_3_signature();
extern int compare_array_int_3_type(int*, const char*, const void*);
#define array_int_3_filter_size 3
extern FilterUtils get_array_int_3_filter_utils(const char* strFilter, void* pValue);
#define array_int_3_filter_values 0
/****************************************************************
 ** struct__5356
 ****************************************************************/
extern const char * struct__5356_to_string(const void* pValue);
extern int check_struct__5356_string(const char* strValue);
extern int string_to_struct__5356(const char* strValue, void* pValue);
int is_struct__5356_allow_double_convertion();
extern const char * get_struct__5356_signature();
extern int compare_struct__5356_type(int*, const char*, const void*);
#define struct__5356_filter_size 10
extern FilterUtils get_struct__5356_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5356_filter_values[10];
/****************************************************************
 ** struct__5369
 ****************************************************************/
extern const char * struct__5369_to_string(const void* pValue);
extern int check_struct__5369_string(const char* strValue);
extern int string_to_struct__5369(const char* strValue, void* pValue);
int is_struct__5369_allow_double_convertion();
extern const char * get_struct__5369_signature();
extern int compare_struct__5369_type(int*, const char*, const void*);
#define struct__5369_filter_size 2
extern FilterUtils get_struct__5369_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5369_filter_values[2];
/****************************************************************
 ** struct__5374
 ****************************************************************/
extern const char * struct__5374_to_string(const void* pValue);
extern int check_struct__5374_string(const char* strValue);
extern int string_to_struct__5374(const char* strValue, void* pValue);
int is_struct__5374_allow_double_convertion();
extern const char * get_struct__5374_signature();
extern int compare_struct__5374_type(int*, const char*, const void*);
#define struct__5374_filter_size 6
extern FilterUtils get_struct__5374_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5374_filter_values[6];
/****************************************************************
 ** struct__5383
 ****************************************************************/
extern const char * struct__5383_to_string(const void* pValue);
extern int check_struct__5383_string(const char* strValue);
extern int string_to_struct__5383(const char* strValue, void* pValue);
int is_struct__5383_allow_double_convertion();
extern const char * get_struct__5383_signature();
extern int compare_struct__5383_type(int*, const char*, const void*);
#define struct__5383_filter_size 5
extern FilterUtils get_struct__5383_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5383_filter_values[5];
/****************************************************************
 ** struct__5391
 ****************************************************************/
extern const char * struct__5391_to_string(const void* pValue);
extern int check_struct__5391_string(const char* strValue);
extern int string_to_struct__5391(const char* strValue, void* pValue);
int is_struct__5391_allow_double_convertion();
extern const char * get_struct__5391_signature();
extern int compare_struct__5391_type(int*, const char*, const void*);
#define struct__5391_filter_size 7
extern FilterUtils get_struct__5391_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5391_filter_values[7];
/****************************************************************
 ** array__5401
 ****************************************************************/
extern const char * array__5401_to_string(const void* pValue);
extern int check_array__5401_string(const char* strValue);
extern int string_to_array__5401(const char* strValue, void* pValue);
int is_array__5401_allow_double_convertion();
extern const char * get_array__5401_signature();
extern int compare_array__5401_type(int*, const char*, const void*);
#define array__5401_filter_size 32
extern FilterUtils get_array__5401_filter_utils(const char* strFilter, void* pValue);
#define array__5401_filter_values 0
/****************************************************************
 ** struct__5404
 ****************************************************************/
extern const char * struct__5404_to_string(const void* pValue);
extern int check_struct__5404_string(const char* strValue);
extern int string_to_struct__5404(const char* strValue, void* pValue);
int is_struct__5404_allow_double_convertion();
extern const char * get_struct__5404_signature();
extern int compare_struct__5404_type(int*, const char*, const void*);
#define struct__5404_filter_size 14
extern FilterUtils get_struct__5404_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__5404_filter_values[14];
/****************************************************************
 ** array_int_7
 ****************************************************************/
extern const char * array_int_7_to_string(const void* pValue);
extern int check_array_int_7_string(const char* strValue);
extern int string_to_array_int_7(const char* strValue, void* pValue);
int is_array_int_7_allow_double_convertion();
extern const char * get_array_int_7_signature();
extern int compare_array_int_7_type(int*, const char*, const void*);
#define array_int_7_filter_size 7
extern FilterUtils get_array_int_7_filter_utils(const char* strFilter, void* pValue);
#define array_int_7_filter_values 0
/****************************************************************
 ** array_int_7_33
 ****************************************************************/
extern const char * array_int_7_33_to_string(const void* pValue);
extern int check_array_int_7_33_string(const char* strValue);
extern int string_to_array_int_7_33(const char* strValue, void* pValue);
int is_array_int_7_33_allow_double_convertion();
extern const char * get_array_int_7_33_signature();
extern int compare_array_int_7_33_type(int*, const char*, const void*);
#define array_int_7_33_filter_size 33
extern FilterUtils get_array_int_7_33_filter_utils(const char* strFilter, void* pValue);
#define array_int_7_33_filter_values 0
/****************************************************************
 ** array__5427
 ****************************************************************/
extern const char * array__5427_to_string(const void* pValue);
extern int check_array__5427_string(const char* strValue);
extern int string_to_array__5427(const char* strValue, void* pValue);
int is_array__5427_allow_double_convertion();
extern const char * get_array__5427_signature();
extern int compare_array__5427_type(int*, const char*, const void*);
#define array__5427_filter_size 33
extern FilterUtils get_array__5427_filter_utils(const char* strFilter, void* pValue);
#define array__5427_filter_values 0
/****************************************************************
 ** array_int_500_500
 ****************************************************************/
extern const char * array_int_500_500_to_string(const void* pValue);
extern int check_array_int_500_500_string(const char* strValue);
extern int string_to_array_int_500_500(const char* strValue, void* pValue);
int is_array_int_500_500_allow_double_convertion();
extern const char * get_array_int_500_500_signature();
extern int compare_array_int_500_500_type(int*, const char*, const void*);
#define array_int_500_500_filter_size 500
extern FilterUtils get_array_int_500_500_filter_utils(const char* strFilter, void* pValue);
#define array_int_500_500_filter_values 0
/****************************************************************
 ** array_int_7_33_231
 ****************************************************************/
extern const char * array_int_7_33_231_to_string(const void* pValue);
extern int check_array_int_7_33_231_string(const char* strValue);
extern int string_to_array_int_7_33_231(const char* strValue, void* pValue);
int is_array_int_7_33_231_allow_double_convertion();
extern const char * get_array_int_7_33_231_signature();
extern int compare_array_int_7_33_231_type(int*, const char*, const void*);
#define array_int_7_33_231_filter_size 231
extern FilterUtils get_array_int_7_33_231_filter_utils(const char* strFilter, void* pValue);
#define array_int_7_33_231_filter_values 0
/****************************************************************
 ** array_int_264
 ****************************************************************/
extern const char * array_int_264_to_string(const void* pValue);
extern int check_array_int_264_string(const char* strValue);
extern int string_to_array_int_264(const char* strValue, void* pValue);
int is_array_int_264_allow_double_convertion();
extern const char * get_array_int_264_signature();
extern int compare_array_int_264_type(int*, const char*, const void*);
#define array_int_264_filter_size 264
extern FilterUtils get_array_int_264_filter_utils(const char* strFilter, void* pValue);
#define array_int_264_filter_values 0
/****************************************************************
 ** array_int_4
 ****************************************************************/
extern const char * array_int_4_to_string(const void* pValue);
extern int check_array_int_4_string(const char* strValue);
extern int string_to_array_int_4(const char* strValue, void* pValue);
int is_array_int_4_allow_double_convertion();
extern const char * get_array_int_4_signature();
extern int compare_array_int_4_type(int*, const char*, const void*);
#define array_int_4_filter_size 4
extern FilterUtils get_array_int_4_filter_utils(const char* strFilter, void* pValue);
#define array_int_4_filter_values 0
/****************************************************************
 ** array_int_1
 ****************************************************************/
extern const char * array_int_1_to_string(const void* pValue);
extern int check_array_int_1_string(const char* strValue);
extern int string_to_array_int_1(const char* strValue, void* pValue);
int is_array_int_1_allow_double_convertion();
extern const char * get_array_int_1_signature();
extern int compare_array_int_1_type(int*, const char*, const void*);
#define array_int_1_filter_size 1
extern FilterUtils get_array_int_1_filter_utils(const char* strFilter, void* pValue);
#define array_int_1_filter_values 0
/****************************************************************
 ** array_int_5
 ****************************************************************/
extern const char * array_int_5_to_string(const void* pValue);
extern int check_array_int_5_string(const char* strValue);
extern int string_to_array_int_5(const char* strValue, void* pValue);
int is_array_int_5_allow_double_convertion();
extern const char * get_array_int_5_signature();
extern int compare_array_int_5_type(int*, const char*, const void*);
#define array_int_5_filter_size 5
extern FilterUtils get_array_int_5_filter_utils(const char* strFilter, void* pValue);
#define array_int_5_filter_values 0
/****************************************************************
 ** array_int_236
 ****************************************************************/
extern const char * array_int_236_to_string(const void* pValue);
extern int check_array_int_236_string(const char* strValue);
extern int string_to_array_int_236(const char* strValue, void* pValue);
int is_array_int_236_allow_double_convertion();
extern const char * get_array_int_236_signature();
extern int compare_array_int_236_type(int*, const char*, const void*);
#define array_int_236_filter_size 236
extern FilterUtils get_array_int_236_filter_utils(const char* strFilter, void* pValue);
#define array_int_236_filter_values 0
/****************************************************************
 ** array__5451
 ****************************************************************/
extern const char * array__5451_to_string(const void* pValue);
extern int check_array__5451_string(const char* strValue);
extern int string_to_array__5451(const char* strValue, void* pValue);
int is_array__5451_allow_double_convertion();
extern const char * get_array__5451_signature();
extern int compare_array__5451_type(int*, const char*, const void*);
#define array__5451_filter_size 1
extern FilterUtils get_array__5451_filter_utils(const char* strFilter, void* pValue);
#define array__5451_filter_values 0
/****************************************************************
 ** array_int_30
 ****************************************************************/
extern const char * array_int_30_to_string(const void* pValue);
extern int check_array_int_30_string(const char* strValue);
extern int string_to_array_int_30(const char* strValue, void* pValue);
int is_array_int_30_allow_double_convertion();
extern const char * get_array_int_30_signature();
extern int compare_array_int_30_type(int*, const char*, const void*);
#define array_int_30_filter_size 30
extern FilterUtils get_array_int_30_filter_utils(const char* strFilter, void* pValue);
#define array_int_30_filter_values 0
/****************************************************************
 ** array_int_33
 ****************************************************************/
extern const char * array_int_33_to_string(const void* pValue);
extern int check_array_int_33_string(const char* strValue);
extern int string_to_array_int_33(const char* strValue, void* pValue);
int is_array_int_33_allow_double_convertion();
extern const char * get_array_int_33_signature();
extern int compare_array_int_33_type(int*, const char*, const void*);
#define array_int_33_filter_size 33
extern FilterUtils get_array_int_33_filter_utils(const char* strFilter, void* pValue);
#define array_int_33_filter_values 0
/****************************************************************
 ** array_int_231_33
 ****************************************************************/
extern const char * array_int_231_33_to_string(const void* pValue);
extern int check_array_int_231_33_string(const char* strValue);
extern int string_to_array_int_231_33(const char* strValue, void* pValue);
int is_array_int_231_33_allow_double_convertion();
extern const char * get_array_int_231_33_signature();
extern int compare_array_int_231_33_type(int*, const char*, const void*);
#define array_int_231_33_filter_size 33
extern FilterUtils get_array_int_231_33_filter_utils(const char* strFilter, void* pValue);
#define array_int_231_33_filter_values 0
/****************************************************************
 ** array__5463
 ****************************************************************/
extern const char * array__5463_to_string(const void* pValue);
extern int check_array__5463_string(const char* strValue);
extern int string_to_array__5463(const char* strValue, void* pValue);
int is_array__5463_allow_double_convertion();
extern const char * get_array__5463_signature();
extern int compare_array__5463_type(int*, const char*, const void*);
#define array__5463_filter_size 4
extern FilterUtils get_array__5463_filter_utils(const char* strFilter, void* pValue);
#define array__5463_filter_values 0
/****************************************************************
 ** array__5466
 ****************************************************************/
extern const char * array__5466_to_string(const void* pValue);
extern int check_array__5466_string(const char* strValue);
extern int string_to_array__5466(const char* strValue, void* pValue);
int is_array__5466_allow_double_convertion();
extern const char * get_array__5466_signature();
extern int compare_array__5466_type(int*, const char*, const void*);
#define array__5466_filter_size 4
extern FilterUtils get_array__5466_filter_utils(const char* strFilter, void* pValue);
#define array__5466_filter_values 0
/****************************************************************
 ** array__5469
 ****************************************************************/
extern const char * array__5469_to_string(const void* pValue);
extern int check_array__5469_string(const char* strValue);
extern int string_to_array__5469(const char* strValue, void* pValue);
int is_array__5469_allow_double_convertion();
extern const char * get_array__5469_signature();
extern int compare_array__5469_type(int*, const char*, const void*);
#define array__5469_filter_size 4
extern FilterUtils get_array__5469_filter_utils(const char* strFilter, void* pValue);
#define array__5469_filter_values 0
/****************************************************************
 ** NID_PACKET
 ****************************************************************/
extern const char * NID_PACKET_to_string(const void* pValue);
extern int check_NID_PACKET_string(const char* strValue);
extern int string_to_NID_PACKET(const char* strValue, void* pValue);
int is_NID_PACKET_allow_double_convertion();
extern int NID_PACKET_to_double(double * nValue, const void*);
#define get_NID_PACKET_signature get_kcg_int_signature
#define compare_NID_PACKET_type compare_kcg_int_type
#define NID_PACKET_filter_size kcg_int_filter_size
#define get_NID_PACKET_filter_utils get_kcg_int_filter_utils
#define NID_PACKET_filter_values kcg_int_filter_values
/****************************************************************
 ** Q_DIR
 ****************************************************************/
extern const char * Q_DIR_to_string(const void* pValue);
extern int check_Q_DIR_string(const char* strValue);
extern int string_to_Q_DIR(const char* strValue, void* pValue);
int is_Q_DIR_allow_double_convertion();
extern int Q_DIR_to_double(double * nValue, const void*);
extern const char * get_Q_DIR_signature();
extern int compare_Q_DIR_type(int*, const char*, const void*);
#define Q_DIR_filter_size 0
#define get_Q_DIR_filter_utils 0
#define Q_DIR_filter_values 0
/****************************************************************
 ** Q_UPDOWN
 ****************************************************************/
extern const char * Q_UPDOWN_to_string(const void* pValue);
extern int check_Q_UPDOWN_string(const char* strValue);
extern int string_to_Q_UPDOWN(const char* strValue, void* pValue);
int is_Q_UPDOWN_allow_double_convertion();
extern int Q_UPDOWN_to_double(double * nValue, const void*);
extern const char * get_Q_UPDOWN_signature();
extern int compare_Q_UPDOWN_type(int*, const char*, const void*);
#define Q_UPDOWN_filter_size 0
#define get_Q_UPDOWN_filter_utils 0
#define Q_UPDOWN_filter_values 0
/****************************************************************
 ** M_VERSION
 ****************************************************************/
extern const char * M_VERSION_to_string(const void* pValue);
extern int check_M_VERSION_string(const char* strValue);
extern int string_to_M_VERSION(const char* strValue, void* pValue);
int is_M_VERSION_allow_double_convertion();
extern int M_VERSION_to_double(double * nValue, const void*);
extern const char * get_M_VERSION_signature();
extern int compare_M_VERSION_type(int*, const char*, const void*);
#define M_VERSION_filter_size 0
#define get_M_VERSION_filter_utils 0
#define M_VERSION_filter_values 0
/****************************************************************
 ** Q_MEDIA
 ****************************************************************/
extern const char * Q_MEDIA_to_string(const void* pValue);
extern int check_Q_MEDIA_string(const char* strValue);
extern int string_to_Q_MEDIA(const char* strValue, void* pValue);
int is_Q_MEDIA_allow_double_convertion();
extern int Q_MEDIA_to_double(double * nValue, const void*);
extern const char * get_Q_MEDIA_signature();
extern int compare_Q_MEDIA_type(int*, const char*, const void*);
#define Q_MEDIA_filter_size 0
#define get_Q_MEDIA_filter_utils 0
#define Q_MEDIA_filter_values 0
/****************************************************************
 ** N_PIG
 ****************************************************************/
extern const char * N_PIG_to_string(const void* pValue);
extern int check_N_PIG_string(const char* strValue);
extern int string_to_N_PIG(const char* strValue, void* pValue);
int is_N_PIG_allow_double_convertion();
extern int N_PIG_to_double(double * nValue, const void*);
extern const char * get_N_PIG_signature();
extern int compare_N_PIG_type(int*, const char*, const void*);
#define N_PIG_filter_size 0
#define get_N_PIG_filter_utils 0
#define N_PIG_filter_values 0
/****************************************************************
 ** N_TOTAL
 ****************************************************************/
extern const char * N_TOTAL_to_string(const void* pValue);
extern int check_N_TOTAL_string(const char* strValue);
extern int string_to_N_TOTAL(const char* strValue, void* pValue);
int is_N_TOTAL_allow_double_convertion();
extern int N_TOTAL_to_double(double * nValue, const void*);
extern const char * get_N_TOTAL_signature();
extern int compare_N_TOTAL_type(int*, const char*, const void*);
#define N_TOTAL_filter_size 0
#define get_N_TOTAL_filter_utils 0
#define N_TOTAL_filter_values 0
/****************************************************************
 ** M_DUP
 ****************************************************************/
extern const char * M_DUP_to_string(const void* pValue);
extern int check_M_DUP_string(const char* strValue);
extern int string_to_M_DUP(const char* strValue, void* pValue);
int is_M_DUP_allow_double_convertion();
extern int M_DUP_to_double(double * nValue, const void*);
extern const char * get_M_DUP_signature();
extern int compare_M_DUP_type(int*, const char*, const void*);
#define M_DUP_filter_size 0
#define get_M_DUP_filter_utils 0
#define M_DUP_filter_values 0
/****************************************************************
 ** M_MCOUNT
 ****************************************************************/
extern const char * M_MCOUNT_to_string(const void* pValue);
extern int check_M_MCOUNT_string(const char* strValue);
extern int string_to_M_MCOUNT(const char* strValue, void* pValue);
int is_M_MCOUNT_allow_double_convertion();
extern int M_MCOUNT_to_double(double * nValue, const void*);
#define get_M_MCOUNT_signature get_kcg_int_signature
#define compare_M_MCOUNT_type compare_kcg_int_type
#define M_MCOUNT_filter_size kcg_int_filter_size
#define get_M_MCOUNT_filter_utils get_kcg_int_filter_utils
#define M_MCOUNT_filter_values kcg_int_filter_values
/****************************************************************
 ** NID_C
 ****************************************************************/
extern const char * NID_C_to_string(const void* pValue);
extern int check_NID_C_string(const char* strValue);
extern int string_to_NID_C(const char* strValue, void* pValue);
int is_NID_C_allow_double_convertion();
extern int NID_C_to_double(double * nValue, const void*);
#define get_NID_C_signature get_kcg_int_signature
#define compare_NID_C_type compare_kcg_int_type
#define NID_C_filter_size kcg_int_filter_size
#define get_NID_C_filter_utils get_kcg_int_filter_utils
#define NID_C_filter_values kcg_int_filter_values
/****************************************************************
 ** NID_BG
 ****************************************************************/
extern const char * NID_BG_to_string(const void* pValue);
extern int check_NID_BG_string(const char* strValue);
extern int string_to_NID_BG(const char* strValue, void* pValue);
int is_NID_BG_allow_double_convertion();
extern int NID_BG_to_double(double * nValue, const void*);
#define get_NID_BG_signature get_kcg_int_signature
#define compare_NID_BG_type compare_kcg_int_type
#define NID_BG_filter_size kcg_int_filter_size
#define get_NID_BG_filter_utils get_kcg_int_filter_utils
#define NID_BG_filter_values kcg_int_filter_values
/****************************************************************
 ** Q_LINK
 ****************************************************************/
extern const char * Q_LINK_to_string(const void* pValue);
extern int check_Q_LINK_string(const char* strValue);
extern int string_to_Q_LINK(const char* strValue, void* pValue);
int is_Q_LINK_allow_double_convertion();
extern int Q_LINK_to_double(double * nValue, const void*);
extern const char * get_Q_LINK_signature();
extern int compare_Q_LINK_type(int*, const char*, const void*);
#define Q_LINK_filter_size 0
#define get_Q_LINK_filter_utils 0
#define Q_LINK_filter_values 0
/****************************************************************
 ** Q_SCALE
 ****************************************************************/
extern const char * Q_SCALE_to_string(const void* pValue);
extern int check_Q_SCALE_string(const char* strValue);
extern int string_to_Q_SCALE(const char* strValue, void* pValue);
int is_Q_SCALE_allow_double_convertion();
extern int Q_SCALE_to_double(double * nValue, const void*);
extern const char * get_Q_SCALE_signature();
extern int compare_Q_SCALE_type(int*, const char*, const void*);
#define Q_SCALE_filter_size 0
#define get_Q_SCALE_filter_utils 0
#define Q_SCALE_filter_values 0
/****************************************************************
 ** D_LINK
 ****************************************************************/
extern const char * D_LINK_to_string(const void* pValue);
extern int check_D_LINK_string(const char* strValue);
extern int string_to_D_LINK(const char* strValue, void* pValue);
int is_D_LINK_allow_double_convertion();
extern int D_LINK_to_double(double * nValue, const void*);
#define get_D_LINK_signature get_kcg_int_signature
#define compare_D_LINK_type compare_kcg_int_type
#define D_LINK_filter_size kcg_int_filter_size
#define get_D_LINK_filter_utils get_kcg_int_filter_utils
#define D_LINK_filter_values kcg_int_filter_values
/****************************************************************
 ** Q_NEWCOUNTRY
 ****************************************************************/
extern const char * Q_NEWCOUNTRY_to_string(const void* pValue);
extern int check_Q_NEWCOUNTRY_string(const char* strValue);
extern int string_to_Q_NEWCOUNTRY(const char* strValue, void* pValue);
int is_Q_NEWCOUNTRY_allow_double_convertion();
extern int Q_NEWCOUNTRY_to_double(double * nValue, const void*);
extern const char * get_Q_NEWCOUNTRY_signature();
extern int compare_Q_NEWCOUNTRY_type(int*, const char*, const void*);
#define Q_NEWCOUNTRY_filter_size 0
#define get_Q_NEWCOUNTRY_filter_utils 0
#define Q_NEWCOUNTRY_filter_values 0
/****************************************************************
 ** Q_LINKORIENTATION
 ****************************************************************/
extern const char * Q_LINKORIENTATION_to_string(const void* pValue);
extern int check_Q_LINKORIENTATION_string(const char* strValue);
extern int string_to_Q_LINKORIENTATION(const char* strValue, void* pValue);
int is_Q_LINKORIENTATION_allow_double_convertion();
extern int Q_LINKORIENTATION_to_double(double * nValue, const void*);
extern const char * get_Q_LINKORIENTATION_signature();
extern int compare_Q_LINKORIENTATION_type(int*, const char*, const void*);
#define Q_LINKORIENTATION_filter_size 0
#define get_Q_LINKORIENTATION_filter_utils 0
#define Q_LINKORIENTATION_filter_values 0
/****************************************************************
 ** Q_LINKREACTION
 ****************************************************************/
extern const char * Q_LINKREACTION_to_string(const void* pValue);
extern int check_Q_LINKREACTION_string(const char* strValue);
extern int string_to_Q_LINKREACTION(const char* strValue, void* pValue);
int is_Q_LINKREACTION_allow_double_convertion();
extern int Q_LINKREACTION_to_double(double * nValue, const void*);
extern const char * get_Q_LINKREACTION_signature();
extern int compare_Q_LINKREACTION_type(int*, const char*, const void*);
#define Q_LINKREACTION_filter_size 0
#define get_Q_LINKREACTION_filter_utils 0
#define Q_LINKREACTION_filter_values 0
/****************************************************************
 ** Q_LOCACC
 ****************************************************************/
extern const char * Q_LOCACC_to_string(const void* pValue);
extern int check_Q_LOCACC_string(const char* strValue);
extern int string_to_Q_LOCACC(const char* strValue, void* pValue);
int is_Q_LOCACC_allow_double_convertion();
extern int Q_LOCACC_to_double(double * nValue, const void*);
#define get_Q_LOCACC_signature get_kcg_int_signature
#define compare_Q_LOCACC_type compare_kcg_int_type
#define Q_LOCACC_filter_size kcg_int_filter_size
#define get_Q_LOCACC_filter_utils get_kcg_int_filter_utils
#define Q_LOCACC_filter_values kcg_int_filter_values
/****************************************************************
 ** N_ITER
 ****************************************************************/
extern const char * N_ITER_to_string(const void* pValue);
extern int check_N_ITER_string(const char* strValue);
extern int string_to_N_ITER(const char* strValue, void* pValue);
int is_N_ITER_allow_double_convertion();
extern int N_ITER_to_double(double * nValue, const void*);
#define get_N_ITER_signature get_kcg_int_signature
#define compare_N_ITER_type compare_kcg_int_type
#define N_ITER_filter_size kcg_int_filter_size
#define get_N_ITER_filter_utils get_kcg_int_filter_utils
#define N_ITER_filter_values kcg_int_filter_values
/****************************************************************
 ** L_PACKET
 ****************************************************************/
extern const char * L_PACKET_to_string(const void* pValue);
extern int check_L_PACKET_string(const char* strValue);
extern int string_to_L_PACKET(const char* strValue, void* pValue);
int is_L_PACKET_allow_double_convertion();
extern int L_PACKET_to_double(double * nValue, const void*);
#define get_L_PACKET_signature get_kcg_int_signature
#define compare_L_PACKET_type compare_kcg_int_type
#define L_PACKET_filter_size kcg_int_filter_size
#define get_L_PACKET_filter_utils get_kcg_int_filter_utils
#define L_PACKET_filter_values kcg_int_filter_values
/****************************************************************
 ** NID_LRBG
 ****************************************************************/
extern const char * NID_LRBG_to_string(const void* pValue);
extern int check_NID_LRBG_string(const char* strValue);
extern int string_to_NID_LRBG(const char* strValue, void* pValue);
int is_NID_LRBG_allow_double_convertion();
extern int NID_LRBG_to_double(double * nValue, const void*);
#define get_NID_LRBG_signature get_kcg_int_signature
#define compare_NID_LRBG_type compare_kcg_int_type
#define NID_LRBG_filter_size kcg_int_filter_size
#define get_NID_LRBG_filter_utils get_kcg_int_filter_utils
#define NID_LRBG_filter_values kcg_int_filter_values
/****************************************************************
 ** CompressedBaliseMessage_TM
 ****************************************************************/
extern const char * CompressedBaliseMessage_TM_to_string(const void* pValue);
extern int check_CompressedBaliseMessage_TM_string(const char* strValue);
extern int string_to_CompressedBaliseMessage_TM(const char* strValue, void* pValue);
int is_CompressedBaliseMessage_TM_allow_double_convertion();
extern int CompressedBaliseMessage_TM_to_double(double * nValue, const void*);
#define get_CompressedBaliseMessage_TM_signature get_struct__5369_signature
#define compare_CompressedBaliseMessage_TM_type compare_struct__5369_type
#define CompressedBaliseMessage_TM_filter_size struct__5369_filter_size
#define get_CompressedBaliseMessage_TM_filter_utils get_struct__5369_filter_utils
#define CompressedBaliseMessage_TM_filter_values struct__5369_filter_values
/****************************************************************
 ** BaliseTelegramHeader_int_T_TM
 ****************************************************************/
extern const char * BaliseTelegramHeader_int_T_TM_to_string(const void* pValue);
extern int check_BaliseTelegramHeader_int_T_TM_string(const char* strValue);
extern int string_to_BaliseTelegramHeader_int_T_TM(const char* strValue, void* pValue);
int is_BaliseTelegramHeader_int_T_TM_allow_double_convertion();
extern int BaliseTelegramHeader_int_T_TM_to_double(double * nValue, const void*);
#define get_BaliseTelegramHeader_int_T_TM_signature get_struct__5356_signature
#define compare_BaliseTelegramHeader_int_T_TM_type compare_struct__5356_type
#define BaliseTelegramHeader_int_T_TM_filter_size struct__5356_filter_size
#define get_BaliseTelegramHeader_int_T_TM_filter_utils get_struct__5356_filter_utils
#define BaliseTelegramHeader_int_T_TM_filter_values struct__5356_filter_values
/****************************************************************
 ** OrBG_TM
 ****************************************************************/
extern const char * OrBG_TM_to_string(const void* pValue);
extern int check_OrBG_TM_string(const char* strValue);
extern int string_to_OrBG_TM(const char* strValue, void* pValue);
int is_OrBG_TM_allow_double_convertion();
extern int OrBG_TM_to_double(double * nValue, const void*);
extern const char * get_OrBG_TM_signature();
extern int compare_OrBG_TM_type(int*, const char*, const void*);
#define OrBG_TM_filter_size 0
#define get_OrBG_TM_filter_utils 0
#define OrBG_TM_filter_values 0
/****************************************************************
 ** OrLine_TM
 ****************************************************************/
extern const char * OrLine_TM_to_string(const void* pValue);
extern int check_OrLine_TM_string(const char* strValue);
extern int string_to_OrLine_TM(const char* strValue, void* pValue);
int is_OrLine_TM_allow_double_convertion();
extern int OrLine_TM_to_double(double * nValue, const void*);
extern const char * get_OrLine_TM_signature();
extern int compare_OrLine_TM_type(int*, const char*, const void*);
#define OrLine_TM_filter_size 0
#define get_OrLine_TM_filter_utils 0
#define OrLine_TM_filter_values 0
/****************************************************************
 ** P005_trackside_int_T_TM
 ****************************************************************/
extern const char * P005_trackside_int_T_TM_to_string(const void* pValue);
extern int check_P005_trackside_int_T_TM_string(const char* strValue);
extern int string_to_P005_trackside_int_T_TM(const char* strValue, void* pValue);
int is_P005_trackside_int_T_TM_allow_double_convertion();
extern int P005_trackside_int_T_TM_to_double(double * nValue, const void*);
#define get_P005_trackside_int_T_TM_signature get_struct__5404_signature
#define compare_P005_trackside_int_T_TM_type compare_struct__5404_type
#define P005_trackside_int_T_TM_filter_size struct__5404_filter_size
#define get_P005_trackside_int_T_TM_filter_utils get_struct__5404_filter_utils
#define P005_trackside_int_T_TM_filter_values struct__5404_filter_values
/****************************************************************
 ** P005_trackide_sectionlist_T_TM
 ****************************************************************/
extern const char * P005_trackide_sectionlist_T_TM_to_string(const void* pValue);
extern int check_P005_trackide_sectionlist_T_TM_string(const char* strValue);
extern int string_to_P005_trackide_sectionlist_T_TM(const char* strValue, void* pValue);
int is_P005_trackide_sectionlist_T_TM_allow_double_convertion();
extern int P005_trackide_sectionlist_T_TM_to_double(double * nValue, const void*);
#define get_P005_trackide_sectionlist_T_TM_signature get_array__5401_signature
#define compare_P005_trackide_sectionlist_T_TM_type compare_array__5401_type
#define P005_trackide_sectionlist_T_TM_filter_size array__5401_filter_size
#define get_P005_trackide_sectionlist_T_TM_filter_utils get_array__5401_filter_utils
#define P005_trackide_sectionlist_T_TM_filter_values array__5401_filter_values
/****************************************************************
 ** P005_section_int_T_TM
 ****************************************************************/
extern const char * P005_section_int_T_TM_to_string(const void* pValue);
extern int check_P005_section_int_T_TM_string(const char* strValue);
extern int string_to_P005_section_int_T_TM(const char* strValue, void* pValue);
int is_P005_section_int_T_TM_allow_double_convertion();
extern int P005_section_int_T_TM_to_double(double * nValue, const void*);
#define get_P005_section_int_T_TM_signature get_struct__5391_signature
#define compare_P005_section_int_T_TM_type compare_struct__5391_type
#define P005_section_int_T_TM_filter_size struct__5391_filter_size
#define get_P005_section_int_T_TM_filter_utils get_struct__5391_filter_utils
#define P005_section_int_T_TM_filter_values struct__5391_filter_values
/****************************************************************
 ** P005_sections_array_flat_T_TM
 ****************************************************************/
extern const char * P005_sections_array_flat_T_TM_to_string(const void* pValue);
extern int check_P005_sections_array_flat_T_TM_string(const char* strValue);
extern int string_to_P005_sections_array_flat_T_TM(const char* strValue, void* pValue);
int is_P005_sections_array_flat_T_TM_allow_double_convertion();
extern int P005_sections_array_flat_T_TM_to_double(double * nValue, const void*);
#define get_P005_sections_array_flat_T_TM_signature get_array_int_231_signature
#define compare_P005_sections_array_flat_T_TM_type compare_array_int_231_type
#define P005_sections_array_flat_T_TM_filter_size array_int_231_filter_size
#define get_P005_sections_array_flat_T_TM_filter_utils get_array_int_231_filter_utils
#define P005_sections_array_flat_T_TM_filter_values array_int_231_filter_values
/****************************************************************
 ** P005_OBU_sectionlist_array_T_TM
 ****************************************************************/
extern const char * P005_OBU_sectionlist_array_T_TM_to_string(const void* pValue);
extern int check_P005_OBU_sectionlist_array_T_TM_string(const char* strValue);
extern int string_to_P005_OBU_sectionlist_array_T_TM(const char* strValue, void* pValue);
int is_P005_OBU_sectionlist_array_T_TM_allow_double_convertion();
extern int P005_OBU_sectionlist_array_T_TM_to_double(double * nValue, const void*);
#define get_P005_OBU_sectionlist_array_T_TM_signature get_array_int_7_33_signature
#define compare_P005_OBU_sectionlist_array_T_TM_type compare_array_int_7_33_type
#define P005_OBU_sectionlist_array_T_TM_filter_size array_int_7_33_filter_size
#define get_P005_OBU_sectionlist_array_T_TM_filter_utils get_array_int_7_33_filter_utils
#define P005_OBU_sectionlist_array_T_TM_filter_values array_int_7_33_filter_values
/****************************************************************
 ** P005_section_array_T_TM
 ****************************************************************/
extern const char * P005_section_array_T_TM_to_string(const void* pValue);
extern int check_P005_section_array_T_TM_string(const char* strValue);
extern int string_to_P005_section_array_T_TM(const char* strValue, void* pValue);
int is_P005_section_array_T_TM_allow_double_convertion();
extern int P005_section_array_T_TM_to_double(double * nValue, const void*);
#define get_P005_section_array_T_TM_signature get_array_int_7_signature
#define compare_P005_section_array_T_TM_type compare_array_int_7_type
#define P005_section_array_T_TM_filter_size array_int_7_filter_size
#define get_P005_section_array_T_TM_filter_utils get_array_int_7_filter_utils
#define P005_section_array_T_TM_filter_values array_int_7_filter_values
/****************************************************************
 ** P005_OBU_sectionlist_int_T_TM
 ****************************************************************/
extern const char * P005_OBU_sectionlist_int_T_TM_to_string(const void* pValue);
extern int check_P005_OBU_sectionlist_int_T_TM_string(const char* strValue);
extern int string_to_P005_OBU_sectionlist_int_T_TM(const char* strValue, void* pValue);
int is_P005_OBU_sectionlist_int_T_TM_allow_double_convertion();
extern int P005_OBU_sectionlist_int_T_TM_to_double(double * nValue, const void*);
#define get_P005_OBU_sectionlist_int_T_TM_signature get_array__5427_signature
#define compare_P005_OBU_sectionlist_int_T_TM_type compare_array__5427_type
#define P005_OBU_sectionlist_int_T_TM_filter_size array__5427_filter_size
#define get_P005_OBU_sectionlist_int_T_TM_filter_utils get_array__5427_filter_utils
#define P005_OBU_sectionlist_int_T_TM_filter_values array__5427_filter_values
/****************************************************************
 ** BaliseGroupData_TM
 ****************************************************************/
extern const char * BaliseGroupData_TM_to_string(const void* pValue);
extern int check_BaliseGroupData_TM_string(const char* strValue);
extern int string_to_BaliseGroupData_TM(const char* strValue, void* pValue);
int is_BaliseGroupData_TM_allow_double_convertion();
extern int BaliseGroupData_TM_to_double(double * nValue, const void*);
#define get_BaliseGroupData_TM_signature get_struct__5383_signature
#define compare_BaliseGroupData_TM_type compare_struct__5383_type
#define BaliseGroupData_TM_filter_size struct__5383_filter_size
#define get_BaliseGroupData_TM_filter_utils get_struct__5383_filter_utils
#define BaliseGroupData_TM_filter_values struct__5383_filter_values
/****************************************************************
 ** P005_section_enum_T_TM
 ****************************************************************/
extern const char * P005_section_enum_T_TM_to_string(const void* pValue);
extern int check_P005_section_enum_T_TM_string(const char* strValue);
extern int string_to_P005_section_enum_T_TM(const char* strValue, void* pValue);
int is_P005_section_enum_T_TM_allow_double_convertion();
extern int P005_section_enum_T_TM_to_double(double * nValue, const void*);
#define get_P005_section_enum_T_TM_signature get_struct__5327_signature
#define compare_P005_section_enum_T_TM_type compare_struct__5327_type
#define P005_section_enum_T_TM_filter_size struct__5327_filter_size
#define get_P005_section_enum_T_TM_filter_utils get_struct__5327_filter_utils
#define P005_section_enum_T_TM_filter_values struct__5327_filter_values
/****************************************************************
 ** P005_OBU_sectionlist_enum_T_TM
 ****************************************************************/
extern const char * P005_OBU_sectionlist_enum_T_TM_to_string(const void* pValue);
extern int check_P005_OBU_sectionlist_enum_T_TM_string(const char* strValue);
extern int string_to_P005_OBU_sectionlist_enum_T_TM(const char* strValue, void* pValue);
int is_P005_OBU_sectionlist_enum_T_TM_allow_double_convertion();
extern int P005_OBU_sectionlist_enum_T_TM_to_double(double * nValue, const void*);
#define get_P005_OBU_sectionlist_enum_T_TM_signature get_array__5338_signature
#define compare_P005_OBU_sectionlist_enum_T_TM_type compare_array__5338_type
#define P005_OBU_sectionlist_enum_T_TM_filter_size array__5338_filter_size
#define get_P005_OBU_sectionlist_enum_T_TM_filter_utils get_array__5338_filter_utils
#define P005_OBU_sectionlist_enum_T_TM_filter_values array__5338_filter_values
/****************************************************************
 ** P005_OBU_T_TM
 ****************************************************************/
extern const char * P005_OBU_T_TM_to_string(const void* pValue);
extern int check_P005_OBU_T_TM_string(const char* strValue);
extern int string_to_P005_OBU_T_TM(const char* strValue, void* pValue);
int is_P005_OBU_T_TM_allow_double_convertion();
extern int P005_OBU_T_TM_to_double(double * nValue, const void*);
#define get_P005_OBU_T_TM_signature get_struct__5341_signature
#define compare_P005_OBU_T_TM_type compare_struct__5341_type
#define P005_OBU_T_TM_filter_size struct__5341_filter_size
#define get_P005_OBU_T_TM_filter_utils get_struct__5341_filter_utils
#define P005_OBU_T_TM_filter_values struct__5341_filter_values
/****************************************************************
 ** Array03_TM
 ****************************************************************/
extern const char * Array03_TM_to_string(const void* pValue);
extern int check_Array03_TM_string(const char* strValue);
extern int string_to_Array03_TM(const char* strValue, void* pValue);
int is_Array03_TM_allow_double_convertion();
extern int Array03_TM_to_double(double * nValue, const void*);
#define get_Array03_TM_signature get_array_int_3_signature
#define compare_Array03_TM_type compare_array_int_3_type
#define Array03_TM_filter_size array_int_3_filter_size
#define get_Array03_TM_filter_utils get_array_int_3_filter_utils
#define Array03_TM_filter_values array_int_3_filter_values
/****************************************************************
 ** CompressedPackets_T_Common_Types_Pkg
 ****************************************************************/
extern const char * CompressedPackets_T_Common_Types_Pkg_to_string(const void* pValue);
extern int check_CompressedPackets_T_Common_Types_Pkg_string(const char* strValue);
extern int string_to_CompressedPackets_T_Common_Types_Pkg(const char* strValue, void* pValue);
int is_CompressedPackets_T_Common_Types_Pkg_allow_double_convertion();
extern int CompressedPackets_T_Common_Types_Pkg_to_double(double * nValue, const void*);
#define get_CompressedPackets_T_Common_Types_Pkg_signature get_struct__5322_signature
#define compare_CompressedPackets_T_Common_Types_Pkg_type compare_struct__5322_type
#define CompressedPackets_T_Common_Types_Pkg_filter_size struct__5322_filter_size
#define get_CompressedPackets_T_Common_Types_Pkg_filter_utils get_struct__5322_filter_utils
#define CompressedPackets_T_Common_Types_Pkg_filter_values struct__5322_filter_values
/****************************************************************
 ** Metadata_T_Common_Types_Pkg
 ****************************************************************/
extern const char * Metadata_T_Common_Types_Pkg_to_string(const void* pValue);
extern int check_Metadata_T_Common_Types_Pkg_string(const char* strValue);
extern int string_to_Metadata_T_Common_Types_Pkg(const char* strValue, void* pValue);
int is_Metadata_T_Common_Types_Pkg_allow_double_convertion();
extern int Metadata_T_Common_Types_Pkg_to_double(double * nValue, const void*);
#define get_Metadata_T_Common_Types_Pkg_signature get_array__5319_signature
#define compare_Metadata_T_Common_Types_Pkg_type compare_array__5319_type
#define Metadata_T_Common_Types_Pkg_filter_size array__5319_filter_size
#define get_Metadata_T_Common_Types_Pkg_filter_utils get_array__5319_filter_utils
#define Metadata_T_Common_Types_Pkg_filter_values array__5319_filter_values
/****************************************************************
 ** MetadataElement_T_Common_Types_Pkg
 ****************************************************************/
extern const char * MetadataElement_T_Common_Types_Pkg_to_string(const void* pValue);
extern int check_MetadataElement_T_Common_Types_Pkg_string(const char* strValue);
extern int string_to_MetadataElement_T_Common_Types_Pkg(const char* strValue, void* pValue);
int is_MetadataElement_T_Common_Types_Pkg_allow_double_convertion();
extern int MetadataElement_T_Common_Types_Pkg_to_double(double * nValue, const void*);
#define get_MetadataElement_T_Common_Types_Pkg_signature get_struct__5311_signature
#define compare_MetadataElement_T_Common_Types_Pkg_type compare_struct__5311_type
#define MetadataElement_T_Common_Types_Pkg_filter_size struct__5311_filter_size
#define get_MetadataElement_T_Common_Types_Pkg_filter_utils get_struct__5311_filter_utils
#define MetadataElement_T_Common_Types_Pkg_filter_values struct__5311_filter_values
/****************************************************************
 ** CompressedPacketData_T_Common_Types_Pkg
 ****************************************************************/
extern const char * CompressedPacketData_T_Common_Types_Pkg_to_string(const void* pValue);
extern int check_CompressedPacketData_T_Common_Types_Pkg_string(const char* strValue);
extern int string_to_CompressedPacketData_T_Common_Types_Pkg(const char* strValue, void* pValue);
int is_CompressedPacketData_T_Common_Types_Pkg_allow_double_convertion();
extern int CompressedPacketData_T_Common_Types_Pkg_to_double(double * nValue, const void*);
#define get_CompressedPacketData_T_Common_Types_Pkg_signature get_array_int_500_signature
#define compare_CompressedPacketData_T_Common_Types_Pkg_type compare_array_int_500_type
#define CompressedPacketData_T_Common_Types_Pkg_filter_size array_int_500_filter_size
#define get_CompressedPacketData_T_Common_Types_Pkg_filter_utils get_array_int_500_filter_utils
#define CompressedPacketData_T_Common_Types_Pkg_filter_values array_int_500_filter_values
/****************************************************************
 ** BaliseGroupData_Basics
 ****************************************************************/
extern const char * BaliseGroupData_Basics_to_string(const void* pValue);
extern int check_BaliseGroupData_Basics_string(const char* strValue);
extern int string_to_BaliseGroupData_Basics(const char* strValue, void* pValue);
int is_BaliseGroupData_Basics_allow_double_convertion();
extern int BaliseGroupData_Basics_to_double(double * nValue, const void*);
#define get_BaliseGroupData_Basics_signature get_struct__5383_signature
#define compare_BaliseGroupData_Basics_type compare_struct__5383_type
#define BaliseGroupData_Basics_filter_size struct__5383_filter_size
#define get_BaliseGroupData_Basics_filter_utils get_struct__5383_filter_utils
#define BaliseGroupData_Basics_filter_values struct__5383_filter_values
/****************************************************************
 ** B_data_internal_T_InfraLib
 ****************************************************************/
extern const char * B_data_internal_T_InfraLib_to_string(const void* pValue);
extern int check_B_data_internal_T_InfraLib_string(const char* strValue);
extern int string_to_B_data_internal_T_InfraLib(const char* strValue, void* pValue);
int is_B_data_internal_T_InfraLib_allow_double_convertion();
extern int B_data_internal_T_InfraLib_to_double(double * nValue, const void*);
#define get_B_data_internal_T_InfraLib_signature get_struct__5374_signature
#define compare_B_data_internal_T_InfraLib_type compare_struct__5374_type
#define B_data_internal_T_InfraLib_filter_size struct__5374_filter_size
#define get_B_data_internal_T_InfraLib_filter_utils get_struct__5374_filter_utils
#define B_data_internal_T_InfraLib_filter_values struct__5374_filter_values
/****************************************************************
 ** TelegramHeader_T_BG_Types_Pkg
 ****************************************************************/
extern const char * TelegramHeader_T_BG_Types_Pkg_to_string(const void* pValue);
extern int check_TelegramHeader_T_BG_Types_Pkg_string(const char* strValue);
extern int string_to_TelegramHeader_T_BG_Types_Pkg(const char* strValue, void* pValue);
int is_TelegramHeader_T_BG_Types_Pkg_allow_double_convertion();
extern int TelegramHeader_T_BG_Types_Pkg_to_double(double * nValue, const void*);
#define get_TelegramHeader_T_BG_Types_Pkg_signature get_struct__5295_signature
#define compare_TelegramHeader_T_BG_Types_Pkg_type compare_struct__5295_type
#define TelegramHeader_T_BG_Types_Pkg_filter_size struct__5295_filter_size
#define get_TelegramHeader_T_BG_Types_Pkg_filter_utils get_struct__5295_filter_utils
#define TelegramHeader_T_BG_Types_Pkg_filter_values struct__5295_filter_values
/****************************************************************
 ** LinkedBG_T_BG_Types_Pkg
 ****************************************************************/
extern const char * LinkedBG_T_BG_Types_Pkg_to_string(const void* pValue);
extern int check_LinkedBG_T_BG_Types_Pkg_string(const char* strValue);
extern int string_to_LinkedBG_T_BG_Types_Pkg(const char* strValue, void* pValue);
int is_LinkedBG_T_BG_Types_Pkg_allow_double_convertion();
extern int LinkedBG_T_BG_Types_Pkg_to_double(double * nValue, const void*);
#define get_LinkedBG_T_BG_Types_Pkg_signature get_struct__5278_signature
#define compare_LinkedBG_T_BG_Types_Pkg_type compare_struct__5278_type
#define LinkedBG_T_BG_Types_Pkg_filter_size struct__5278_filter_size
#define get_LinkedBG_T_BG_Types_Pkg_filter_utils get_struct__5278_filter_utils
#define LinkedBG_T_BG_Types_Pkg_filter_values struct__5278_filter_values
/****************************************************************
 ** LinkedBGs_T_BG_Types_Pkg
 ****************************************************************/
extern const char * LinkedBGs_T_BG_Types_Pkg_to_string(const void* pValue);
extern int check_LinkedBGs_T_BG_Types_Pkg_string(const char* strValue);
extern int string_to_LinkedBGs_T_BG_Types_Pkg(const char* strValue, void* pValue);
int is_LinkedBGs_T_BG_Types_Pkg_allow_double_convertion();
extern int LinkedBGs_T_BG_Types_Pkg_to_double(double * nValue, const void*);
#define get_LinkedBGs_T_BG_Types_Pkg_signature get_array__5292_signature
#define compare_LinkedBGs_T_BG_Types_Pkg_type compare_array__5292_type
#define LinkedBGs_T_BG_Types_Pkg_filter_size array__5292_filter_size
#define get_LinkedBGs_T_BG_Types_Pkg_filter_utils get_array__5292_filter_utils
#define LinkedBGs_T_BG_Types_Pkg_filter_values array__5292_filter_values

#endif /*TESTSTORY00A_P005_INTERNAL_TYPES_CONVERTION */
