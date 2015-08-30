#ifndef TESTTRACKATLAS_TYPES_CONVERSION
#define TESTTRACKATLAS_TYPES_CONVERSION

#include "NewSmuTypes.h"

/****************************************************************
 ** kcg_real 
 ****************************************************************/
extern int kcg_real_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_kcg_real_string(const char *str, char **endptr);
extern int string_to_kcg_real(const char *str, void *pValue, char **endptr);
extern int is_kcg_real_allow_double_conversion();
extern int kcg_real_to_double(const void *pValue, double *nValue);
extern int get_kcg_real_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_kcg_real(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_kcg_real_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_real_Utils;

/****************************************************************
 ** kcg_bool 
 ****************************************************************/
extern int kcg_bool_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_kcg_bool_string(const char *str, char **endptr);
extern int string_to_kcg_bool(const char *str, void *pValue, char **endptr);
extern int is_kcg_bool_allow_double_conversion();
extern int kcg_bool_to_double(const void *pValue, double *nValue);
extern int get_kcg_bool_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_kcg_bool(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_kcg_bool_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_bool_Utils;

/****************************************************************
 ** kcg_char 
 ****************************************************************/
extern int kcg_char_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_kcg_char_string(const char *str, char **endptr);
extern int string_to_kcg_char(const char *str, void *pValue, char **endptr);
extern int is_kcg_char_allow_double_conversion();
extern int kcg_char_to_double(const void *pValue, double *nValue);
extern int get_kcg_char_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_kcg_char(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_kcg_char_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_char_Utils;

/****************************************************************
 ** kcg_int 
 ****************************************************************/
extern int kcg_int_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_kcg_int_string(const char *str, char **endptr);
extern int string_to_kcg_int(const char *str, void *pValue, char **endptr);
extern int is_kcg_int_allow_double_conversion();
extern int kcg_int_to_double(const void *pValue, double *nValue);
extern int get_kcg_int_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_kcg_int(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_kcg_int_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_int_Utils;

/****************************************************************
 ** struct__2674 
 ****************************************************************/
extern int struct__2674_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2674_string(const char *str, char **endptr);
extern int string_to_struct__2674(const char *str, void *pValue, char **endptr);
extern int is_struct__2674_allow_double_conversion();
extern int struct__2674_to_double(const void *pValue, double *nValue);
extern int get_struct__2674_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2674(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2674_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2674_Utils;

/****************************************************************
 ** array__2679 
 ****************************************************************/
extern int array__2679_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2679_string(const char *str, char **endptr);
extern int string_to_array__2679(const char *str, void *pValue, char **endptr);
extern int is_array__2679_allow_double_conversion();
extern int array__2679_to_double(const void *pValue, double *nValue);
extern int get_array__2679_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2679(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2679_default_value(void *pValue);
extern SimTypeUtils _Type_array__2679_Utils;

/****************************************************************
 ** struct__2682 
 ****************************************************************/
extern int struct__2682_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2682_string(const char *str, char **endptr);
extern int string_to_struct__2682(const char *str, void *pValue, char **endptr);
extern int is_struct__2682_allow_double_conversion();
extern int struct__2682_to_double(const void *pValue, double *nValue);
extern int get_struct__2682_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2682(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2682_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2682_Utils;

/****************************************************************
 ** array__2688 
 ****************************************************************/
extern int array__2688_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2688_string(const char *str, char **endptr);
extern int string_to_array__2688(const char *str, void *pValue, char **endptr);
extern int is_array__2688_allow_double_conversion();
extern int array__2688_to_double(const void *pValue, double *nValue);
extern int get_array__2688_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2688(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2688_default_value(void *pValue);
extern SimTypeUtils _Type_array__2688_Utils;

/****************************************************************
 ** struct__2691 
 ****************************************************************/
extern int struct__2691_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2691_string(const char *str, char **endptr);
extern int string_to_struct__2691(const char *str, void *pValue, char **endptr);
extern int is_struct__2691_allow_double_conversion();
extern int struct__2691_to_double(const void *pValue, double *nValue);
extern int get_struct__2691_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2691(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2691_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2691_Utils;

/****************************************************************
 ** array__2700 
 ****************************************************************/
extern int array__2700_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2700_string(const char *str, char **endptr);
extern int string_to_array__2700(const char *str, void *pValue, char **endptr);
extern int is_array__2700_allow_double_conversion();
extern int array__2700_to_double(const void *pValue, double *nValue);
extern int get_array__2700_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2700(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2700_default_value(void *pValue);
extern SimTypeUtils _Type_array__2700_Utils;

/****************************************************************
 ** struct__2703 
 ****************************************************************/
extern int struct__2703_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2703_string(const char *str, char **endptr);
extern int string_to_struct__2703(const char *str, void *pValue, char **endptr);
extern int is_struct__2703_allow_double_conversion();
extern int struct__2703_to_double(const void *pValue, double *nValue);
extern int get_struct__2703_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2703(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2703_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2703_Utils;

/****************************************************************
 ** struct__2710 
 ****************************************************************/
extern int struct__2710_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2710_string(const char *str, char **endptr);
extern int string_to_struct__2710(const char *str, void *pValue, char **endptr);
extern int is_struct__2710_allow_double_conversion();
extern int struct__2710_to_double(const void *pValue, double *nValue);
extern int get_struct__2710_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2710(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2710_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2710_Utils;

/****************************************************************
 ** array__2715 
 ****************************************************************/
extern int array__2715_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2715_string(const char *str, char **endptr);
extern int string_to_array__2715(const char *str, void *pValue, char **endptr);
extern int is_array__2715_allow_double_conversion();
extern int array__2715_to_double(const void *pValue, double *nValue);
extern int get_array__2715_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2715(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2715_default_value(void *pValue);
extern SimTypeUtils _Type_array__2715_Utils;

/****************************************************************
 ** struct__2718 
 ****************************************************************/
extern int struct__2718_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2718_string(const char *str, char **endptr);
extern int string_to_struct__2718(const char *str, void *pValue, char **endptr);
extern int is_struct__2718_allow_double_conversion();
extern int struct__2718_to_double(const void *pValue, double *nValue);
extern int get_struct__2718_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2718(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2718_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2718_Utils;

/****************************************************************
 ** array__2726 
 ****************************************************************/
extern int array__2726_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2726_string(const char *str, char **endptr);
extern int string_to_array__2726(const char *str, void *pValue, char **endptr);
extern int is_array__2726_allow_double_conversion();
extern int array__2726_to_double(const void *pValue, double *nValue);
extern int get_array__2726_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2726(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2726_default_value(void *pValue);
extern SimTypeUtils _Type_array__2726_Utils;

/****************************************************************
 ** struct__2729 
 ****************************************************************/
extern int struct__2729_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2729_string(const char *str, char **endptr);
extern int string_to_struct__2729(const char *str, void *pValue, char **endptr);
extern int is_struct__2729_allow_double_conversion();
extern int struct__2729_to_double(const void *pValue, double *nValue);
extern int get_struct__2729_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2729(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2729_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2729_Utils;

/****************************************************************
 ** array_int_500 
 ****************************************************************/
extern int array_int_500_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_500_string(const char *str, char **endptr);
extern int string_to_array_int_500(const char *str, void *pValue, char **endptr);
extern int is_array_int_500_allow_double_conversion();
extern int array_int_500_to_double(const void *pValue, double *nValue);
extern int get_array_int_500_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_500(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_500_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_500_Utils;

/****************************************************************
 ** struct__2747 
 ****************************************************************/
extern int struct__2747_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2747_string(const char *str, char **endptr);
extern int string_to_struct__2747(const char *str, void *pValue, char **endptr);
extern int is_struct__2747_allow_double_conversion();
extern int struct__2747_to_double(const void *pValue, double *nValue);
extern int get_struct__2747_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2747(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2747_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2747_Utils;

/****************************************************************
 ** array_int_2 
 ****************************************************************/
extern int array_int_2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_2_string(const char *str, char **endptr);
extern int string_to_array_int_2(const char *str, void *pValue, char **endptr);
extern int is_array_int_2_allow_double_conversion();
extern int array_int_2_to_double(const void *pValue, double *nValue);
extern int get_array_int_2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_2_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_2_Utils;

/****************************************************************
 ** array_int_2_32 
 ****************************************************************/
extern int array_int_2_32_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_2_32_string(const char *str, char **endptr);
extern int string_to_array_int_2_32(const char *str, void *pValue, char **endptr);
extern int is_array_int_2_32_allow_double_conversion();
extern int array_int_2_32_to_double(const void *pValue, double *nValue);
extern int get_array_int_2_32_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_2_32(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_2_32_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_2_32_Utils;

/****************************************************************
 ** array_int_64 
 ****************************************************************/
extern int array_int_64_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_64_string(const char *str, char **endptr);
extern int string_to_array_int_64(const char *str, void *pValue, char **endptr);
extern int is_array_int_64_allow_double_conversion();
extern int array_int_64_to_double(const void *pValue, double *nValue);
extern int get_array_int_64_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_64(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_64_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_64_Utils;

/****************************************************************
 ** array__2764 
 ****************************************************************/
extern int array__2764_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2764_string(const char *str, char **endptr);
extern int string_to_array__2764(const char *str, void *pValue, char **endptr);
extern int is_array__2764_allow_double_conversion();
extern int array__2764_to_double(const void *pValue, double *nValue);
extern int get_array__2764_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2764(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2764_default_value(void *pValue);
extern SimTypeUtils _Type_array__2764_Utils;

/****************************************************************
 ** struct__2767 
 ****************************************************************/
extern int struct__2767_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2767_string(const char *str, char **endptr);
extern int string_to_struct__2767(const char *str, void *pValue, char **endptr);
extern int is_struct__2767_allow_double_conversion();
extern int struct__2767_to_double(const void *pValue, double *nValue);
extern int get_struct__2767_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2767(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2767_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2767_Utils;

/****************************************************************
 ** array__2772 
 ****************************************************************/
extern int array__2772_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2772_string(const char *str, char **endptr);
extern int string_to_array__2772(const char *str, void *pValue, char **endptr);
extern int is_array__2772_allow_double_conversion();
extern int array__2772_to_double(const void *pValue, double *nValue);
extern int get_array__2772_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2772(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2772_default_value(void *pValue);
extern SimTypeUtils _Type_array__2772_Utils;

/****************************************************************
 ** array_int_5 
 ****************************************************************/
extern int array_int_5_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_5_string(const char *str, char **endptr);
extern int string_to_array_int_5(const char *str, void *pValue, char **endptr);
extern int is_array_int_5_allow_double_conversion();
extern int array_int_5_to_double(const void *pValue, double *nValue);
extern int get_array_int_5_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_5(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_5_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_5_Utils;

/****************************************************************
 ** struct__2778 
 ****************************************************************/
extern int struct__2778_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_struct__2778_string(const char *str, char **endptr);
extern int string_to_struct__2778(const char *str, void *pValue, char **endptr);
extern int is_struct__2778_allow_double_conversion();
extern int struct__2778_to_double(const void *pValue, double *nValue);
extern int get_struct__2778_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_struct__2778(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_struct__2778_default_value(void *pValue);
extern SimTypeUtils _Type_struct__2778_Utils;

/****************************************************************
 ** array_int_3 
 ****************************************************************/
extern int array_int_3_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_3_string(const char *str, char **endptr);
extern int string_to_array_int_3(const char *str, void *pValue, char **endptr);
extern int is_array_int_3_allow_double_conversion();
extern int array_int_3_to_double(const void *pValue, double *nValue);
extern int get_array_int_3_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_3(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_3_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_3_Utils;

/****************************************************************
 ** array_int_30 
 ****************************************************************/
extern int array_int_30_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_30_string(const char *str, char **endptr);
extern int string_to_array_int_30(const char *str, void *pValue, char **endptr);
extern int is_array_int_30_allow_double_conversion();
extern int array_int_30_to_double(const void *pValue, double *nValue);
extern int get_array_int_30_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_30(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_30_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_30_Utils;

/****************************************************************
 ** array_bool_30 
 ****************************************************************/
extern int array_bool_30_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_bool_30_string(const char *str, char **endptr);
extern int string_to_array_bool_30(const char *str, void *pValue, char **endptr);
extern int is_array_bool_30_allow_double_conversion();
extern int array_bool_30_to_double(const void *pValue, double *nValue);
extern int get_array_bool_30_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_bool_30(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_bool_30_default_value(void *pValue);
extern SimTypeUtils _Type_array_bool_30_Utils;

/****************************************************************
 ** array_int_500_500 
 ****************************************************************/
extern int array_int_500_500_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_500_500_string(const char *str, char **endptr);
extern int string_to_array_int_500_500(const char *str, void *pValue, char **endptr);
extern int is_array_int_500_500_allow_double_conversion();
extern int array_int_500_500_to_double(const void *pValue, double *nValue);
extern int get_array_int_500_500_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_500_500(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_500_500_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_500_500_Utils;

/****************************************************************
 ** array_int_32 
 ****************************************************************/
extern int array_int_32_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_32_string(const char *str, char **endptr);
extern int string_to_array_int_32(const char *str, void *pValue, char **endptr);
extern int is_array_int_32_allow_double_conversion();
extern int array_int_32_to_double(const void *pValue, double *nValue);
extern int get_array_int_32_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_32(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_32_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_32_Utils;

/****************************************************************
 ** array_int_64_32 
 ****************************************************************/
extern int array_int_64_32_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_64_32_string(const char *str, char **endptr);
extern int string_to_array_int_64_32(const char *str, void *pValue, char **endptr);
extern int is_array_int_64_32_allow_double_conversion();
extern int array_int_64_32_to_double(const void *pValue, double *nValue);
extern int get_array_int_64_32_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_64_32(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_64_32_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_64_32_Utils;

/****************************************************************
 ** array_int_33 
 ****************************************************************/
extern int array_int_33_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_33_string(const char *str, char **endptr);
extern int string_to_array_int_33(const char *str, void *pValue, char **endptr);
extern int is_array_int_33_allow_double_conversion();
extern int array_int_33_to_double(const void *pValue, double *nValue);
extern int get_array_int_33_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_33(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_33_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_33_Utils;

/****************************************************************
 ** array__2805 
 ****************************************************************/
extern int array__2805_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2805_string(const char *str, char **endptr);
extern int string_to_array__2805(const char *str, void *pValue, char **endptr);
extern int is_array__2805_allow_double_conversion();
extern int array__2805_to_double(const void *pValue, double *nValue);
extern int get_array__2805_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2805(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2805_default_value(void *pValue);
extern SimTypeUtils _Type_array__2805_Utils;

/****************************************************************
 ** array_int_494 
 ****************************************************************/
extern int array_int_494_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_494_string(const char *str, char **endptr);
extern int string_to_array_int_494(const char *str, void *pValue, char **endptr);
extern int is_array_int_494_allow_double_conversion();
extern int array_int_494_to_double(const void *pValue, double *nValue);
extern int get_array_int_494_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_494(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_494_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_494_Utils;

/****************************************************************
 ** array_int_6 
 ****************************************************************/
extern int array_int_6_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_6_string(const char *str, char **endptr);
extern int string_to_array_int_6(const char *str, void *pValue, char **endptr);
extern int is_array_int_6_allow_double_conversion();
extern int array_int_6_to_double(const void *pValue, double *nValue);
extern int get_array_int_6_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_6(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_6_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_6_Utils;

/****************************************************************
 ** array__2814 
 ****************************************************************/
extern int array__2814_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2814_string(const char *str, char **endptr);
extern int string_to_array__2814(const char *str, void *pValue, char **endptr);
extern int is_array__2814_allow_double_conversion();
extern int array__2814_to_double(const void *pValue, double *nValue);
extern int get_array__2814_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2814(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2814_default_value(void *pValue);
extern SimTypeUtils _Type_array__2814_Utils;

/****************************************************************
 ** array_int_2_32_32 
 ****************************************************************/
extern int array_int_2_32_32_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_2_32_32_string(const char *str, char **endptr);
extern int string_to_array_int_2_32_32(const char *str, void *pValue, char **endptr);
extern int is_array_int_2_32_32_allow_double_conversion();
extern int array_int_2_32_32_to_double(const void *pValue, double *nValue);
extern int get_array_int_2_32_32_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_2_32_32(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_2_32_32_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_2_32_32_Utils;

/****************************************************************
 ** array_int_432 
 ****************************************************************/
extern int array_int_432_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_432_string(const char *str, char **endptr);
extern int string_to_array_int_432(const char *str, void *pValue, char **endptr);
extern int is_array_int_432_allow_double_conversion();
extern int array_int_432_to_double(const void *pValue, double *nValue);
extern int get_array_int_432_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_432(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_432_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_432_Utils;

/****************************************************************
 ** array_int_4 
 ****************************************************************/
extern int array_int_4_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_4_string(const char *str, char **endptr);
extern int string_to_array_int_4(const char *str, void *pValue, char **endptr);
extern int is_array_int_4_allow_double_conversion();
extern int array_int_4_to_double(const void *pValue, double *nValue);
extern int get_array_int_4_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_4(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_4_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_4_Utils;

/****************************************************************
 ** array_int_68 
 ****************************************************************/
extern int array_int_68_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array_int_68_string(const char *str, char **endptr);
extern int string_to_array_int_68(const char *str, void *pValue, char **endptr);
extern int is_array_int_68_allow_double_conversion();
extern int array_int_68_to_double(const void *pValue, double *nValue);
extern int get_array_int_68_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array_int_68(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array_int_68_default_value(void *pValue);
extern SimTypeUtils _Type_array_int_68_Utils;

/****************************************************************
 ** array__2829 
 ****************************************************************/
extern int array__2829_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2829_string(const char *str, char **endptr);
extern int string_to_array__2829(const char *str, void *pValue, char **endptr);
extern int is_array__2829_allow_double_conversion();
extern int array__2829_to_double(const void *pValue, double *nValue);
extern int get_array__2829_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2829(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2829_default_value(void *pValue);
extern SimTypeUtils _Type_array__2829_Utils;

/****************************************************************
 ** array__2832 
 ****************************************************************/
extern int array__2832_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2832_string(const char *str, char **endptr);
extern int string_to_array__2832(const char *str, void *pValue, char **endptr);
extern int is_array__2832_allow_double_conversion();
extern int array__2832_to_double(const void *pValue, double *nValue);
extern int get_array__2832_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2832(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2832_default_value(void *pValue);
extern SimTypeUtils _Type_array__2832_Utils;

/****************************************************************
 ** array__2835 
 ****************************************************************/
extern int array__2835_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2835_string(const char *str, char **endptr);
extern int string_to_array__2835(const char *str, void *pValue, char **endptr);
extern int is_array__2835_allow_double_conversion();
extern int array__2835_to_double(const void *pValue, double *nValue);
extern int get_array__2835_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2835(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2835_default_value(void *pValue);
extern SimTypeUtils _Type_array__2835_Utils;

/****************************************************************
 ** array__2838 
 ****************************************************************/
extern int array__2838_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_array__2838_string(const char *str, char **endptr);
extern int string_to_array__2838(const char *str, void *pValue, char **endptr);
extern int is_array__2838_allow_double_conversion();
extern int array__2838_to_double(const void *pValue, double *nValue);
extern int get_array__2838_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_array__2838(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_array__2838_default_value(void *pValue);
extern SimTypeUtils _Type_array__2838_Utils;

/****************************************************************
 ** NID_PACKET 
 ****************************************************************/
extern int NID_PACKET_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_NID_PACKET_string(const char *str, char **endptr);
extern int string_to_NID_PACKET(const char *str, void *pValue, char **endptr);
extern int is_NID_PACKET_allow_double_conversion();
extern int NID_PACKET_to_double(const void *pValue, double *nValue);
extern int get_NID_PACKET_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_NID_PACKET(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_NID_PACKET_default_value(void *pValue);
extern SimTypeUtils _Type_NID_PACKET_Utils;

/****************************************************************
 ** Q_DIR 
 ****************************************************************/
extern int Q_DIR_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_Q_DIR_string(const char *str, char **endptr);
extern int string_to_Q_DIR(const char *str, void *pValue, char **endptr);
extern int is_Q_DIR_allow_double_conversion();
extern int Q_DIR_to_double(const void *pValue, double *nValue);
extern int get_Q_DIR_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_Q_DIR(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_Q_DIR_default_value(void *pValue);
extern SimTypeUtils _Type_Q_DIR_Utils;

/****************************************************************
 ** Q_SCALE 
 ****************************************************************/
extern int Q_SCALE_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_Q_SCALE_string(const char *str, char **endptr);
extern int string_to_Q_SCALE(const char *str, void *pValue, char **endptr);
extern int is_Q_SCALE_allow_double_conversion();
extern int Q_SCALE_to_double(const void *pValue, double *nValue);
extern int get_Q_SCALE_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_Q_SCALE(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_Q_SCALE_default_value(void *pValue);
extern SimTypeUtils _Type_Q_SCALE_Utils;

/****************************************************************
 ** D_STATIC 
 ****************************************************************/
extern int D_STATIC_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_D_STATIC_string(const char *str, char **endptr);
extern int string_to_D_STATIC(const char *str, void *pValue, char **endptr);
extern int is_D_STATIC_allow_double_conversion();
extern int D_STATIC_to_double(const void *pValue, double *nValue);
extern int get_D_STATIC_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_D_STATIC(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_D_STATIC_default_value(void *pValue);
extern SimTypeUtils _Type_D_STATIC_Utils;

/****************************************************************
 ** V_STATIC 
 ****************************************************************/
extern int V_STATIC_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_V_STATIC_string(const char *str, char **endptr);
extern int string_to_V_STATIC(const char *str, void *pValue, char **endptr);
extern int is_V_STATIC_allow_double_conversion();
extern int V_STATIC_to_double(const void *pValue, double *nValue);
extern int get_V_STATIC_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_V_STATIC(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_V_STATIC_default_value(void *pValue);
extern SimTypeUtils _Type_V_STATIC_Utils;

/****************************************************************
 ** Q_FRONT 
 ****************************************************************/
extern int Q_FRONT_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_Q_FRONT_string(const char *str, char **endptr);
extern int string_to_Q_FRONT(const char *str, void *pValue, char **endptr);
extern int is_Q_FRONT_allow_double_conversion();
extern int Q_FRONT_to_double(const void *pValue, double *nValue);
extern int get_Q_FRONT_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_Q_FRONT(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_Q_FRONT_default_value(void *pValue);
extern SimTypeUtils _Type_Q_FRONT_Utils;

/****************************************************************
 ** N_ITER 
 ****************************************************************/
extern int N_ITER_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_N_ITER_string(const char *str, char **endptr);
extern int string_to_N_ITER(const char *str, void *pValue, char **endptr);
extern int is_N_ITER_allow_double_conversion();
extern int N_ITER_to_double(const void *pValue, double *nValue);
extern int get_N_ITER_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_N_ITER(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_N_ITER_default_value(void *pValue);
extern SimTypeUtils _Type_N_ITER_Utils;

/****************************************************************
 ** NC_DIFF 
 ****************************************************************/
extern int NC_DIFF_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_NC_DIFF_string(const char *str, char **endptr);
extern int string_to_NC_DIFF(const char *str, void *pValue, char **endptr);
extern int is_NC_DIFF_allow_double_conversion();
extern int NC_DIFF_to_double(const void *pValue, double *nValue);
extern int get_NC_DIFF_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_NC_DIFF(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_NC_DIFF_default_value(void *pValue);
extern SimTypeUtils _Type_NC_DIFF_Utils;

/****************************************************************
 ** V_DIFF 
 ****************************************************************/
extern int V_DIFF_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_V_DIFF_string(const char *str, char **endptr);
extern int string_to_V_DIFF(const char *str, void *pValue, char **endptr);
extern int is_V_DIFF_allow_double_conversion();
extern int V_DIFF_to_double(const void *pValue, double *nValue);
extern int get_V_DIFF_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_V_DIFF(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_V_DIFF_default_value(void *pValue);
extern SimTypeUtils _Type_V_DIFF_Utils;

/****************************************************************
 ** P027V1_OBU_body_enum_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_OBU_body_enum_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_OBU_body_enum_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_OBU_body_enum_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_OBU_body_enum_T_TM_baseline2_allow_double_conversion();
extern int P027V1_OBU_body_enum_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_OBU_body_enum_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_OBU_body_enum_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_OBU_body_enum_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_OBU_body_enum_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_section_enum_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_section_enum_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_section_enum_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_section_enum_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_section_enum_T_TM_baseline2_allow_double_conversion();
extern int P027V1_section_enum_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_section_enum_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_section_enum_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_section_enum_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_section_enum_T_TM_baseline2_Utils;

/****************************************************************
 ** _4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2 
 ****************************************************************/
extern int _4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check__4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to__4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is__4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2_allow_double_conversion();
extern int _4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get__4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare__4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set__4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type__4_P027V1_OBU_sectionlist_enum_qdiff_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_section_enum_qdiff_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_section_enum_qdiff_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_section_enum_qdiff_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_section_enum_qdiff_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_section_enum_qdiff_T_TM_baseline2_allow_double_conversion();
extern int P027V1_section_enum_qdiff_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_section_enum_qdiff_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_section_enum_qdiff_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_section_enum_qdiff_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_section_enum_qdiff_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_sections_array_flat_qdiff_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_sections_array_flat_qdiff_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_sections_array_flat_qdiff_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_sections_array_flat_qdiff_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_sections_array_flat_qdiff_T_TM_baseline2_allow_double_conversion();
extern int P027V1_sections_array_flat_qdiff_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_sections_array_flat_qdiff_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_sections_array_flat_qdiff_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_sections_array_flat_qdiff_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_sections_array_flat_qdiff_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_OBU_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_OBU_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_OBU_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_OBU_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_OBU_T_TM_baseline2_allow_double_conversion();
extern int P027V1_OBU_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_OBU_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_OBU_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_OBU_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_OBU_T_TM_baseline2_Utils;

/****************************************************************
 ** _3_P027V1_OBU_sectionlist_enum_T_TM_baseline2 
 ****************************************************************/
extern int _3_P027V1_OBU_sectionlist_enum_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check__3_P027V1_OBU_sectionlist_enum_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to__3_P027V1_OBU_sectionlist_enum_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is__3_P027V1_OBU_sectionlist_enum_T_TM_baseline2_allow_double_conversion();
extern int _3_P027V1_OBU_sectionlist_enum_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get__3_P027V1_OBU_sectionlist_enum_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare__3_P027V1_OBU_sectionlist_enum_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set__3_P027V1_OBU_sectionlist_enum_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type__3_P027V1_OBU_sectionlist_enum_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_trackside_int_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_trackside_int_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_trackside_int_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_trackside_int_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_trackside_int_T_TM_baseline2_allow_double_conversion();
extern int P027V1_trackside_int_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_trackside_int_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_trackside_int_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_trackside_int_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_trackside_int_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_trackside_qdifflist_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_trackside_qdifflist_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_trackside_qdifflist_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_trackside_qdifflist_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_trackside_qdifflist_T_TM_baseline2_allow_double_conversion();
extern int P027V1_trackside_qdifflist_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_trackside_qdifflist_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_trackside_qdifflist_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_trackside_qdifflist_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_trackside_qdifflist_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_section_int_qdiff_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_section_int_qdiff_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_section_int_qdiff_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_section_int_qdiff_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_section_int_qdiff_T_TM_baseline2_allow_double_conversion();
extern int P027V1_section_int_qdiff_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_section_int_qdiff_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_section_int_qdiff_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_section_int_qdiff_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_section_int_qdiff_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_trackside_sectionlist_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_trackside_sectionlist_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_trackside_sectionlist_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_trackside_sectionlist_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_trackside_sectionlist_T_TM_baseline2_allow_double_conversion();
extern int P027V1_trackside_sectionlist_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_trackside_sectionlist_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_trackside_sectionlist_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_trackside_sectionlist_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_trackside_sectionlist_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_section_int_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_section_int_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_section_int_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_section_int_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_section_int_T_TM_baseline2_allow_double_conversion();
extern int P027V1_section_int_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_section_int_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_section_int_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_section_int_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_section_int_T_TM_baseline2_Utils;

/****************************************************************
 ** _2_P027V1_OBU_sectionlist_int_T_TM_baseline2 
 ****************************************************************/
extern int _2_P027V1_OBU_sectionlist_int_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check__2_P027V1_OBU_sectionlist_int_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to__2_P027V1_OBU_sectionlist_int_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is__2_P027V1_OBU_sectionlist_int_T_TM_baseline2_allow_double_conversion();
extern int _2_P027V1_OBU_sectionlist_int_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get__2_P027V1_OBU_sectionlist_int_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare__2_P027V1_OBU_sectionlist_int_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set__2_P027V1_OBU_sectionlist_int_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type__2_P027V1_OBU_sectionlist_int_T_TM_baseline2_Utils;

/****************************************************************
 ** _1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2 
 ****************************************************************/
extern int _1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check__1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to__1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is__1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2_allow_double_conversion();
extern int _1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get__1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare__1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set__1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type__1_P027V1_OBU_sectionlist_array_qdiff_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_section_array_qdiff_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_section_array_qdiff_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_section_array_qdiff_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_section_array_qdiff_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_section_array_qdiff_T_TM_baseline2_allow_double_conversion();
extern int P027V1_section_array_qdiff_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_section_array_qdiff_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_section_array_qdiff_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_section_array_qdiff_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_section_array_qdiff_T_TM_baseline2_Utils;

/****************************************************************
 ** P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2 
 ****************************************************************/
extern int P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2_string(const char *str, char **endptr);
extern int string_to_P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2(const char *str, void *pValue, char **endptr);
extern int is_P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2_allow_double_conversion();
extern int P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2_to_double(const void *pValue, double *nValue);
extern int get_P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2_default_value(void *pValue);
extern SimTypeUtils _Type_P027V1_OBU_sectionlist_int_qdiff_T_TM_baseline2_Utils;

/****************************************************************
 ** Array05_TM 
 ****************************************************************/
extern int Array05_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_Array05_TM_string(const char *str, char **endptr);
extern int string_to_Array05_TM(const char *str, void *pValue, char **endptr);
extern int is_Array05_TM_allow_double_conversion();
extern int Array05_TM_to_double(const void *pValue, double *nValue);
extern int get_Array05_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_Array05_TM(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_Array05_TM_default_value(void *pValue);
extern SimTypeUtils _Type_Array05_TM_Utils;

/****************************************************************
 ** Array03_TM 
 ****************************************************************/
extern int Array03_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_Array03_TM_string(const char *str, char **endptr);
extern int string_to_Array03_TM(const char *str, void *pValue, char **endptr);
extern int is_Array03_TM_allow_double_conversion();
extern int Array03_TM_to_double(const void *pValue, double *nValue);
extern int get_Array03_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_Array03_TM(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_Array03_TM_default_value(void *pValue);
extern SimTypeUtils _Type_Array03_TM_Utils;

/****************************************************************
 ** nid_packet_meta_TM 
 ****************************************************************/
extern int nid_packet_meta_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_nid_packet_meta_TM_string(const char *str, char **endptr);
extern int string_to_nid_packet_meta_TM(const char *str, void *pValue, char **endptr);
extern int is_nid_packet_meta_TM_allow_double_conversion();
extern int nid_packet_meta_TM_to_double(const void *pValue, double *nValue);
extern int get_nid_packet_meta_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_nid_packet_meta_TM(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_nid_packet_meta_TM_default_value(void *pValue);
extern SimTypeUtils _Type_nid_packet_meta_TM_Utils;

/****************************************************************
 ** MetadataElement_T_Common_Types_Pkg 
 ****************************************************************/
extern int MetadataElement_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_MetadataElement_T_Common_Types_Pkg_string(const char *str, char **endptr);
extern int string_to_MetadataElement_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr);
extern int is_MetadataElement_T_Common_Types_Pkg_allow_double_conversion();
extern int MetadataElement_T_Common_Types_Pkg_to_double(const void *pValue, double *nValue);
extern int get_MetadataElement_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_MetadataElement_T_Common_Types_Pkg(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_MetadataElement_T_Common_Types_Pkg_default_value(void *pValue);
extern SimTypeUtils _Type_MetadataElement_T_Common_Types_Pkg_Utils;

/****************************************************************
 ** Metadata_T_Common_Types_Pkg 
 ****************************************************************/
extern int Metadata_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_Metadata_T_Common_Types_Pkg_string(const char *str, char **endptr);
extern int string_to_Metadata_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr);
extern int is_Metadata_T_Common_Types_Pkg_allow_double_conversion();
extern int Metadata_T_Common_Types_Pkg_to_double(const void *pValue, double *nValue);
extern int get_Metadata_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_Metadata_T_Common_Types_Pkg(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_Metadata_T_Common_Types_Pkg_default_value(void *pValue);
extern SimTypeUtils _Type_Metadata_T_Common_Types_Pkg_Utils;

/****************************************************************
 ** CompressedPacketData_T_Common_Types_Pkg 
 ****************************************************************/
extern int CompressedPacketData_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_CompressedPacketData_T_Common_Types_Pkg_string(const char *str, char **endptr);
extern int string_to_CompressedPacketData_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr);
extern int is_CompressedPacketData_T_Common_Types_Pkg_allow_double_conversion();
extern int CompressedPacketData_T_Common_Types_Pkg_to_double(const void *pValue, double *nValue);
extern int get_CompressedPacketData_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_CompressedPacketData_T_Common_Types_Pkg(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_CompressedPacketData_T_Common_Types_Pkg_default_value(void *pValue);
extern SimTypeUtils _Type_CompressedPacketData_T_Common_Types_Pkg_Utils;

/****************************************************************
 ** CompressedPackets_T_Common_Types_Pkg 
 ****************************************************************/
extern int CompressedPackets_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_CompressedPackets_T_Common_Types_Pkg_string(const char *str, char **endptr);
extern int string_to_CompressedPackets_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr);
extern int is_CompressedPackets_T_Common_Types_Pkg_allow_double_conversion();
extern int CompressedPackets_T_Common_Types_Pkg_to_double(const void *pValue, double *nValue);
extern int get_CompressedPackets_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_CompressedPackets_T_Common_Types_Pkg(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_CompressedPackets_T_Common_Types_Pkg_default_value(void *pValue);
extern SimTypeUtils _Type_CompressedPackets_T_Common_Types_Pkg_Utils;

/****************************************************************
 ** SSP_section_t_TA_MRSP 
 ****************************************************************/
extern int SSP_section_t_TA_MRSP_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_SSP_section_t_TA_MRSP_string(const char *str, char **endptr);
extern int string_to_SSP_section_t_TA_MRSP(const char *str, void *pValue, char **endptr);
extern int is_SSP_section_t_TA_MRSP_allow_double_conversion();
extern int SSP_section_t_TA_MRSP_to_double(const void *pValue, double *nValue);
extern int get_SSP_section_t_TA_MRSP_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_SSP_section_t_TA_MRSP(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_SSP_section_t_TA_MRSP_default_value(void *pValue);
extern SimTypeUtils _Type_SSP_section_t_TA_MRSP_Utils;

/****************************************************************
 ** SSP_t_section_t_TA_MRSP 
 ****************************************************************/
extern int SSP_t_section_t_TA_MRSP_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_SSP_t_section_t_TA_MRSP_string(const char *str, char **endptr);
extern int string_to_SSP_t_section_t_TA_MRSP(const char *str, void *pValue, char **endptr);
extern int is_SSP_t_section_t_TA_MRSP_allow_double_conversion();
extern int SSP_t_section_t_TA_MRSP_to_double(const void *pValue, double *nValue);
extern int get_SSP_t_section_t_TA_MRSP_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_SSP_t_section_t_TA_MRSP(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_SSP_t_section_t_TA_MRSP_default_value(void *pValue);
extern SimTypeUtils _Type_SSP_t_section_t_TA_MRSP_Utils;

/****************************************************************
 ** SSP_s_section_t_TA_MRSP 
 ****************************************************************/
extern int SSP_s_section_t_TA_MRSP_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_SSP_s_section_t_TA_MRSP_string(const char *str, char **endptr);
extern int string_to_SSP_s_section_t_TA_MRSP(const char *str, void *pValue, char **endptr);
extern int is_SSP_s_section_t_TA_MRSP_allow_double_conversion();
extern int SSP_s_section_t_TA_MRSP_to_double(const void *pValue, double *nValue);
extern int get_SSP_s_section_t_TA_MRSP_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_SSP_s_section_t_TA_MRSP(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_SSP_s_section_t_TA_MRSP_default_value(void *pValue);
extern SimTypeUtils _Type_SSP_s_section_t_TA_MRSP_Utils;

/****************************************************************
 ** SSP_cat_t_TA_MRSP 
 ****************************************************************/
extern int SSP_cat_t_TA_MRSP_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_SSP_cat_t_TA_MRSP_string(const char *str, char **endptr);
extern int string_to_SSP_cat_t_TA_MRSP(const char *str, void *pValue, char **endptr);
extern int is_SSP_cat_t_TA_MRSP_allow_double_conversion();
extern int SSP_cat_t_TA_MRSP_to_double(const void *pValue, double *nValue);
extern int get_SSP_cat_t_TA_MRSP_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_SSP_cat_t_TA_MRSP(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_SSP_cat_t_TA_MRSP_default_value(void *pValue);
extern SimTypeUtils _Type_SSP_cat_t_TA_MRSP_Utils;

/****************************************************************
 ** V_internal_Type_Obu_BasicTypes_Pkg 
 ****************************************************************/
extern int V_internal_Type_Obu_BasicTypes_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_V_internal_Type_Obu_BasicTypes_Pkg_string(const char *str, char **endptr);
extern int string_to_V_internal_Type_Obu_BasicTypes_Pkg(const char *str, void *pValue, char **endptr);
extern int is_V_internal_Type_Obu_BasicTypes_Pkg_allow_double_conversion();
extern int V_internal_Type_Obu_BasicTypes_Pkg_to_double(const void *pValue, double *nValue);
extern int get_V_internal_Type_Obu_BasicTypes_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_V_internal_Type_Obu_BasicTypes_Pkg(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_V_internal_Type_Obu_BasicTypes_Pkg_default_value(void *pValue);
extern SimTypeUtils _Type_V_internal_Type_Obu_BasicTypes_Pkg_Utils;

/****************************************************************
 ** L_internal_Type_Obu_BasicTypes_Pkg 
 ****************************************************************/
extern int L_internal_Type_Obu_BasicTypes_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData);
extern int check_L_internal_Type_Obu_BasicTypes_Pkg_string(const char *str, char **endptr);
extern int string_to_L_internal_Type_Obu_BasicTypes_Pkg(const char *str, void *pValue, char **endptr);
extern int is_L_internal_Type_Obu_BasicTypes_Pkg_allow_double_conversion();
extern int L_internal_Type_Obu_BasicTypes_Pkg_to_double(const void *pValue, double *nValue);
extern int get_L_internal_Type_Obu_BasicTypes_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern void compare_L_internal_Type_Obu_BasicTypes_Pkg(int *nStatus, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths);
extern int set_L_internal_Type_Obu_BasicTypes_Pkg_default_value(void *pValue);
extern SimTypeUtils _Type_L_internal_Type_Obu_BasicTypes_Pkg_Utils;


#endif /*TESTTRACKATLAS_TYPES_CONVERSION */
