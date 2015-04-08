#ifndef FIND_FIRST_IN_EACH_SSP_CAT_TYPES_CONVERTION
#define FIND_FIRST_IN_EACH_SSP_CAT_TYPES_CONVERTION

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
extern TypeUtils _SCSIM_array_int_3_Utils;
extern TypeUtils _SCSIM_struct__159_Utils;
extern TypeUtils _SCSIM_array__164_Utils;
extern TypeUtils _SCSIM_array_int_3_11_Utils;
extern TypeUtils _SCSIM_SSP_target_t_Utils;
extern TypeUtils _SCSIM_SSP_section_t_Utils;
extern TypeUtils _SCSIM_SSP_indexed_trgt_t_Utils;
extern TypeUtils _SCSIM_SSP_cat_t_Utils;
extern TypeUtils _SCSIM_SSP_matrix_t_Utils;
extern TypeUtils _SCSIM_SSP_indexed_targets_list_t_Utils;

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
 ** struct__159
 ****************************************************************/
extern const char * struct__159_to_string(const void* pValue);
extern int check_struct__159_string(const char* strValue);
extern int string_to_struct__159(const char* strValue, void* pValue);
int is_struct__159_allow_double_convertion();
extern const char * get_struct__159_signature();
extern int compare_struct__159_type(int*, const char*, const void*);
#define struct__159_filter_size 2
extern FilterUtils get_struct__159_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__159_filter_values[2];
/****************************************************************
 ** array__164
 ****************************************************************/
extern const char * array__164_to_string(const void* pValue);
extern int check_array__164_string(const char* strValue);
extern int string_to_array__164(const char* strValue, void* pValue);
int is_array__164_allow_double_convertion();
extern const char * get_array__164_signature();
extern int compare_array__164_type(int*, const char*, const void*);
#define array__164_filter_size 11
extern FilterUtils get_array__164_filter_utils(const char* strFilter, void* pValue);
#define array__164_filter_values 0
/****************************************************************
 ** array_int_3_11
 ****************************************************************/
extern const char * array_int_3_11_to_string(const void* pValue);
extern int check_array_int_3_11_string(const char* strValue);
extern int string_to_array_int_3_11(const char* strValue, void* pValue);
int is_array_int_3_11_allow_double_convertion();
extern const char * get_array_int_3_11_signature();
extern int compare_array_int_3_11_type(int*, const char*, const void*);
#define array_int_3_11_filter_size 11
extern FilterUtils get_array_int_3_11_filter_utils(const char* strFilter, void* pValue);
#define array_int_3_11_filter_values 0
/****************************************************************
 ** SSP_target_t
 ****************************************************************/
extern const char * SSP_target_t_to_string(const void* pValue);
extern int check_SSP_target_t_string(const char* strValue);
extern int string_to_SSP_target_t(const char* strValue, void* pValue);
int is_SSP_target_t_allow_double_convertion();
extern int SSP_target_t_to_double(double * nValue, const void*);
#define get_SSP_target_t_signature get_kcg_int_signature
#define compare_SSP_target_t_type compare_kcg_int_type
#define SSP_target_t_filter_size kcg_int_filter_size
#define get_SSP_target_t_filter_utils get_kcg_int_filter_utils
#define SSP_target_t_filter_values kcg_int_filter_values
/****************************************************************
 ** SSP_section_t
 ****************************************************************/
extern const char * SSP_section_t_to_string(const void* pValue);
extern int check_SSP_section_t_string(const char* strValue);
extern int string_to_SSP_section_t(const char* strValue, void* pValue);
int is_SSP_section_t_allow_double_convertion();
extern int SSP_section_t_to_double(double * nValue, const void*);
#define get_SSP_section_t_signature get_kcg_int_signature
#define compare_SSP_section_t_type compare_kcg_int_type
#define SSP_section_t_filter_size kcg_int_filter_size
#define get_SSP_section_t_filter_utils get_kcg_int_filter_utils
#define SSP_section_t_filter_values kcg_int_filter_values
/****************************************************************
 ** SSP_indexed_trgt_t
 ****************************************************************/
extern const char * SSP_indexed_trgt_t_to_string(const void* pValue);
extern int check_SSP_indexed_trgt_t_string(const char* strValue);
extern int string_to_SSP_indexed_trgt_t(const char* strValue, void* pValue);
int is_SSP_indexed_trgt_t_allow_double_convertion();
extern int SSP_indexed_trgt_t_to_double(double * nValue, const void*);
#define get_SSP_indexed_trgt_t_signature get_struct__159_signature
#define compare_SSP_indexed_trgt_t_type compare_struct__159_type
#define SSP_indexed_trgt_t_filter_size struct__159_filter_size
#define get_SSP_indexed_trgt_t_filter_utils get_struct__159_filter_utils
#define SSP_indexed_trgt_t_filter_values struct__159_filter_values
/****************************************************************
 ** SSP_cat_t
 ****************************************************************/
extern const char * SSP_cat_t_to_string(const void* pValue);
extern int check_SSP_cat_t_string(const char* strValue);
extern int string_to_SSP_cat_t(const char* strValue, void* pValue);
int is_SSP_cat_t_allow_double_convertion();
extern int SSP_cat_t_to_double(double * nValue, const void*);
#define get_SSP_cat_t_signature get_array_int_3_signature
#define compare_SSP_cat_t_type compare_array_int_3_type
#define SSP_cat_t_filter_size array_int_3_filter_size
#define get_SSP_cat_t_filter_utils get_array_int_3_filter_utils
#define SSP_cat_t_filter_values array_int_3_filter_values
/****************************************************************
 ** SSP_matrix_t
 ****************************************************************/
extern const char * SSP_matrix_t_to_string(const void* pValue);
extern int check_SSP_matrix_t_string(const char* strValue);
extern int string_to_SSP_matrix_t(const char* strValue, void* pValue);
int is_SSP_matrix_t_allow_double_convertion();
extern int SSP_matrix_t_to_double(double * nValue, const void*);
#define get_SSP_matrix_t_signature get_array_int_3_11_signature
#define compare_SSP_matrix_t_type compare_array_int_3_11_type
#define SSP_matrix_t_filter_size array_int_3_11_filter_size
#define get_SSP_matrix_t_filter_utils get_array_int_3_11_filter_utils
#define SSP_matrix_t_filter_values array_int_3_11_filter_values
/****************************************************************
 ** SSP_indexed_targets_list_t
 ****************************************************************/
extern const char * SSP_indexed_targets_list_t_to_string(const void* pValue);
extern int check_SSP_indexed_targets_list_t_string(const char* strValue);
extern int string_to_SSP_indexed_targets_list_t(const char* strValue, void* pValue);
int is_SSP_indexed_targets_list_t_allow_double_convertion();
extern int SSP_indexed_targets_list_t_to_double(double * nValue, const void*);
#define get_SSP_indexed_targets_list_t_signature get_array__164_signature
#define compare_SSP_indexed_targets_list_t_type compare_array__164_type
#define SSP_indexed_targets_list_t_filter_size array__164_filter_size
#define get_SSP_indexed_targets_list_t_filter_utils get_array__164_filter_utils
#define SSP_indexed_targets_list_t_filter_values array__164_filter_values

#endif /*FIND_FIRST_IN_EACH_SSP_CAT_TYPES_CONVERTION */
