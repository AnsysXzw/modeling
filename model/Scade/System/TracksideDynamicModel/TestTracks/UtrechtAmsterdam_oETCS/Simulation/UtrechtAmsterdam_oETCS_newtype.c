#include <stdlib.h>
#include <stddef.h>
#include "NewSmuTypes.h"
#include "kcg_types.h"
#include "UtrechtAmsterdam_oETCS_newtype.h"
#include "kcg_conv.h"

char* strDefaultRealFormat="%.5g"; /*(from .etp)*/

#define skip_whitespace(str) while(*str == ' ' || *str == '\t') str++

/****************************************************************
 ** utility functions 
 ****************************************************************/

static int string_to_VTable(const char *str, const struct SimTypeVTable *pVTable, void *pValue, char **endptr)
{
    int nRet;
    if (pVTable != NULL && pVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        nRet = pVTable->m_pfnFromType(SptString, (const void*)&str, pValue);
        if (nRet != 0) {
            *endptr = (char*)str+strlen(str);
        }
        return nRet;
    };
    return 0;
}

static int is_VTable_double_convertion_allowed(const struct SimTypeVTable *pVTable)
{
    if (pVTable != NULL) {
        int nConvertionAllowed = 0;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
        return nConvertionAllowed;
    }
    return 1;
}

int VTable_to_double(const void *pValue, const struct SimTypeVTable *pVTable, double *nRetValue)
{
    if (pVTable != NULL) {
        if (pVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
            *nRetValue = (*(double*)pVTable->m_pfnToType(SptDouble, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
            *nRetValue = (double)(*(float*)pVTable->m_pfnToType(SptFloat, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
            *nRetValue = (double)(*(long*)pVTable->m_pfnToType(SptLong, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
            *nRetValue = (double)(*(int*)pVTable->m_pfnToType(SptShort, pValue));
        else
            return 0;
    }
    return 1;
}

static int get_enum_signature(const SimEnumValUtils *pEnumVals, int nSize, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    int i;
    pfnStrAppend("E", pData);
    for(i=0; i<nSize; i++) {
        pfnStrAppend("|", pData);
        pfnStrAppend(pEnumVals[i].m_name, pData);
    }
    return 1;
}

static int get_structure_signature(const SimFieldUtils *pFields, int nSize, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for(i=0; i<nSize; i++) {
        if (i > 0)
            pfnStrAppend(",", pData);
        pFields[i].m_pTypeUtils->m_pfnGetSignature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

/****************************************************************
 ** kcg_real 
 ****************************************************************/

struct SimTypeVTable *pSimDoubleVTable;

int kcg_real_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimDoubleVTable != NULL
        && pSimDoubleVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimDoubleVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return pfnStrAppend(*(char**)pSimDoubleVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_real_to_string(*((kcg_real*)pValue), pConverter->m_RealFormat, pfnStrAppend, pData);
}

int string_to_kcg_real(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static double rTemp;
    skip_whitespace(str);
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /*R15 and higher: VTable funtion must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimDoubleVTable, pValue, endptr);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimDoubleVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_real*)pValue = (kcg_real)rTemp;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_real(str, (kcg_real*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_real_double_convertion_allowed()
{
    if (pSimDoubleVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimDoubleVTable);
    }
    return 1;
}

void compare_kcg_real(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    if (pSimDoubleVTable != NULL && pData!=NULL && pSimDoubleVTable->m_version >= Scv65 && pSimDoubleVTable->m_pfnCompareWithTol != NULL ) {
        /*Customized comparison with tolerance (R15 and higher): */
        unitResult = pSimDoubleVTable->m_pfnCompareWithTol(pResult, pValue1, pValue2, pData);
    } else if (pSimDoubleVTable != NULL && pData==NULL && pSimDoubleVTable->m_version >= Scv612 && pSimDoubleVTable->m_pfnCompare != NULL) {
        /*Customized comparison without tolerance: */
        if (pSimDoubleVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            unitResult = pSimDoubleVTable->m_pfnCompare(pResult, pValue1, pValue2);
         } else {
             /*Before R15: VTable funtion returns a standard C typed *variable: */
             double value1 = (double)(*(const kcg_real*)pValue1);
             double value2 = (double)(*(const kcg_real*)pValue2);
             pSimDoubleVTable->m_pfnCompare(&unitResult, &value1, &value2);
             updateCompareResult(unitResult, pResult);
         }
    } else {
        /*Predefined comparison (with/without tolerance): */
        unitResult = predef_compare_kcg_real(pResult, *((kcg_real*)pValue1), *((kcg_real*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_real_to_double(const void *pValue, double *nRetValue)
{
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            return VTable_to_double(pValue, pSimDoubleVTable, nRetValue);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return VTable_to_double(&value, pSimDoubleVTable, nRetValue);
        }
    }
    *nRetValue = (double)*((kcg_real*)pValue);
    return 1;
}

int get_kcg_real_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("R", pData);
}

int set_kcg_real_default_value(void *pValue)
{
    *(kcg_real*)pValue = 0.0;
    return 1;
}

int check_kcg_real_string(const char *str, char **endptr)
{
    static kcg_real rTemp;
    return string_to_kcg_real(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_real_Utils = {
    kcg_real_to_string,
    check_kcg_real_string,
    string_to_kcg_real,
    is_kcg_real_double_convertion_allowed,
    kcg_real_to_double,
    compare_kcg_real,
    get_kcg_real_signature,
    set_kcg_real_default_value,
    sizeof(kcg_real)
};

/****************************************************************
 ** kcg_bool 
 ****************************************************************/

struct SimTypeVTable *pSimBoolVTable;

int kcg_bool_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_bool_to_string(*((kcg_bool*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_bool(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static SimBool rTemp;
    skip_whitespace(str);
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /*R15 and higher: VTable funtion must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimBoolVTable, pValue, endptr);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimBoolVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_bool*)pValue = (rTemp == SbTrue)? kcg_true : kcg_false;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_bool(str, (kcg_bool*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_bool_double_convertion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimBoolVTable);
    }
    return 1;
}

void compare_kcg_bool(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_version >= Scv612
        && pSimBoolVTable->m_pfnCompare != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            unitResult = pSimBoolVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            SimBool value1 = (*((const kcg_bool*)pValue1) == kcg_true)? SbTrue : SbFalse;
            SimBool value2 = (*((const kcg_bool*)pValue2) == kcg_true)? SbTrue : SbFalse;
            pSimBoolVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_bool(pResult, *((kcg_bool*)pValue1), *((kcg_bool*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_bool_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            return VTable_to_double(pValue, pSimBoolVTable, nRetValue);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return VTable_to_double(&value, pSimBoolVTable, nRetValue);
        }
    }
    *nRetValue = *((kcg_bool*)pValue) == kcg_true ? 1.0 : 0.0;
    return 1;
}

int get_kcg_bool_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("B", pData);
}

int set_kcg_bool_default_value(void *pValue)
{
    *(kcg_bool*)pValue = kcg_false;
    return 1;
}

int check_kcg_bool_string(const char *str, char **endptr)
{
    static kcg_bool rTemp;
    return string_to_kcg_bool(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_bool_Utils = {
    kcg_bool_to_string,
    check_kcg_bool_string,
    string_to_kcg_bool,
    is_kcg_bool_double_convertion_allowed,
    kcg_bool_to_double,
    compare_kcg_bool,
    get_kcg_bool_signature,
    set_kcg_bool_default_value,
    sizeof(kcg_bool)
};

/****************************************************************
 ** kcg_char 
 ****************************************************************/

struct SimTypeVTable *pSimCharVTable;

int kcg_char_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimCharVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_char_to_string(*((kcg_char*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_char(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static char rTemp;
    skip_whitespace(str);
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /*R15 and higher: VTable funtion must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimCharVTable, pValue, endptr);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimCharVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_char*)pValue = (kcg_char)rTemp;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_char(str, (kcg_char*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_char_double_convertion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimCharVTable);
    }
    return 1;
}

void compare_kcg_char(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_version >= Scv612
        && pSimCharVTable->m_pfnCompare != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            unitResult = pSimCharVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            char value1 = (char)(*(const kcg_char*)pValue1);
            char value2 = (char)(*(const kcg_char*)pValue2);
            pSimCharVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_char(pResult, *((kcg_char*)pValue1), *((kcg_char*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_char_to_double(const void *pValue, double *nRetValue)
{
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            return VTable_to_double(pValue, pSimCharVTable, nRetValue);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return VTable_to_double(&value, pSimCharVTable, nRetValue);
        }
    }
    *nRetValue = (double)*((kcg_char*)pValue);
    return 1;
}

int get_kcg_char_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("C", pData);
}

int set_kcg_char_default_value(void *pValue)
{
    *(kcg_char*)pValue = 0;
    return 1;
}

int check_kcg_char_string(const char *str, char **endptr)
{
    static kcg_char rTemp;
    return string_to_kcg_char(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_char_Utils = {
    kcg_char_to_string,
    check_kcg_char_string,
    string_to_kcg_char,
    is_kcg_char_double_convertion_allowed,
    kcg_char_to_double,
    compare_kcg_char,
    get_kcg_char_signature,
    set_kcg_char_default_value,
    sizeof(kcg_char)
};

/****************************************************************
 ** kcg_int 
 ****************************************************************/

struct SimTypeVTable *pSimLongVTable;

int kcg_int_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimLongVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimLongVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return pfnStrAppend(*(char**)pSimLongVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_int_to_string(*((kcg_int*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_int(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static long rTemp;
    skip_whitespace(str);
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /*R15 and higher: VTable funtion must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimLongVTable, pValue, endptr);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimLongVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_int*)pValue = (kcg_int)rTemp;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_int(str, (kcg_int*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_int_double_convertion_allowed()
{
    if (pSimLongVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimLongVTable);
    }
    return 1;
}

void compare_kcg_int(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_version >= Scv612
        && pSimLongVTable->m_pfnCompare != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            unitResult = pSimLongVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            long value1 = (long)(*(const kcg_int*)pValue1);
            long value2 = (long)(*(const kcg_int*)pValue2);
            pSimLongVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_int(pResult, *((kcg_int*)pValue1), *((kcg_int*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_int_to_double(const void *pValue, double *nRetValue)
{
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /*R15 and higher: pass kcg_<type> * to VTable funtion: */
            return VTable_to_double(pValue, pSimLongVTable, nRetValue);
        } else {
            /*Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return VTable_to_double(&value, pSimLongVTable, nRetValue);
        }
    }
    *nRetValue = (double)*((kcg_int*)pValue);
    return 1;
}

int get_kcg_int_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("I", pData);
}

int set_kcg_int_default_value(void *pValue)
{
    *(kcg_int*)pValue = 0;
    return 1;
}

int check_kcg_int_string(const char *str, char **endptr)
{
    static kcg_int rTemp;
    return string_to_kcg_int(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_int_Utils = {
    kcg_int_to_string,
    check_kcg_int_string,
    string_to_kcg_int,
    is_kcg_int_double_convertion_allowed,
    kcg_int_to_double,
    compare_kcg_int,
    get_kcg_int_signature,
    set_kcg_int_default_value,
    sizeof(kcg_int)
};

/****************************************************************
 ** struct__5532 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5532VTable;

static SimFieldUtils struct__5532_fields[] = {
    {"valid", offsetof(struct__5532,valid), &_Type_kcg_bool_Utils},
    {"nid_LRBG", offsetof(struct__5532,nid_LRBG), &_Type_kcg_int_Utils},
    {"q_dir", offsetof(struct__5532,q_dir), &_Type_Q_DIR_Utils},
    {"q_scale", offsetof(struct__5532,q_scale), &_Type_Q_SCALE_Utils},
    {"d_link", offsetof(struct__5532,d_link), &_Type_kcg_int_Utils},
    {"q_newcountry", offsetof(struct__5532,q_newcountry), &_Type_Q_NEWCOUNTRY_Utils},
    {"nid_c", offsetof(struct__5532,nid_c), &_Type_kcg_int_Utils},
    {"nid_bg", offsetof(struct__5532,nid_bg), &_Type_kcg_int_Utils},
    {"q_linkorientation", offsetof(struct__5532,q_linkorientation), &_Type_Q_LINKORIENTATION_Utils},
    {"q_linkreaction", offsetof(struct__5532,q_linkreaction), &_Type_Q_LINKREACTION_Utils},
    {"q_locacc", offsetof(struct__5532,q_locacc), &_Type_kcg_int_Utils},
};

int struct__5532_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5532VTable != NULL
        && pSimstruct__5532VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5532VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5532_fields, 11, pfnStrAppend, pData);
}

int string_to_struct__5532(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5532VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5532VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5532_fields, 11, endptr);
    }
    return nRet;
}

int is_struct__5532_double_convertion_allowed()
{
    if (pSimstruct__5532VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5532VTable);
    }
    return 0;
}

void compare_struct__5532(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5532VTable != NULL
        && pSimstruct__5532VTable->m_version >= Scv612
        && pSimstruct__5532VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5532VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5532VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5532VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5532_fields, 11, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5532_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5532VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5532VTable, nRetValue);
    }
    return 0;
}

int get_struct__5532_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5532_fields, 11, pfnStrAppend, pData);
}

int set_struct__5532_default_value(void *pValue)
{
    set_kcg_bool_default_value(&(((struct__5532*)pValue)->valid));
    set_kcg_int_default_value(&(((struct__5532*)pValue)->nid_LRBG));
    set_Q_DIR_default_value(&(((struct__5532*)pValue)->q_dir));
    set_Q_SCALE_default_value(&(((struct__5532*)pValue)->q_scale));
    set_kcg_int_default_value(&(((struct__5532*)pValue)->d_link));
    set_Q_NEWCOUNTRY_default_value(&(((struct__5532*)pValue)->q_newcountry));
    set_kcg_int_default_value(&(((struct__5532*)pValue)->nid_c));
    set_kcg_int_default_value(&(((struct__5532*)pValue)->nid_bg));
    set_Q_LINKORIENTATION_default_value(&(((struct__5532*)pValue)->q_linkorientation));
    set_Q_LINKREACTION_default_value(&(((struct__5532*)pValue)->q_linkreaction));
    set_kcg_int_default_value(&(((struct__5532*)pValue)->q_locacc));
    return 1;
}

int check_struct__5532_string(const char *str, char **endptr)
{
    static struct__5532 rTemp;
    return string_to_struct__5532(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5532_Utils = {
    struct__5532_to_string,
    check_struct__5532_string,
    string_to_struct__5532,
    is_struct__5532_double_convertion_allowed,
    struct__5532_to_double,
    compare_struct__5532,
    get_struct__5532_signature,
    set_struct__5532_default_value,
    sizeof(struct__5532)
};

/****************************************************************
 ** array__5546 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5546VTable;

int array__5546_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5546VTable != NULL
        && pSimarray__5546VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5546VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, struct__5532_to_string, 4, sizeof(struct__5532), pfnStrAppend, pData);
}

int string_to_array__5546(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5546VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5546VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_struct__5532_Utils, 4, sizeof(struct__5532), endptr);
    }
    return nRet;
}

int is_array__5546_double_convertion_allowed()
{
    if (pSimarray__5546VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5546VTable);
    }
    return 0;
}

void compare_array__5546(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5546VTable != NULL
        && pSimarray__5546VTable->m_version >= Scv612
        && pSimarray__5546VTable->m_pfnCompare != NULL) {
        if (pSimarray__5546VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5546VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5546VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_struct__5532, 4, sizeof(struct__5532), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5546_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5546VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5546VTable, nRetValue);
    }
    return 0;
}

int get_array__5546_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 4; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_struct__5532_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5546_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 4; i++)
        set_struct__5532_default_value(&((struct__5532*)pValue)[i]);
    return 1;
}

int check_array__5546_string(const char *str, char **endptr)
{
    static array__5546 rTemp;
    return string_to_array__5546(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5546_Utils = {
    array__5546_to_string,
    check_array__5546_string,
    string_to_array__5546,
    is_array__5546_double_convertion_allowed,
    array__5546_to_double,
    compare_array__5546,
    get_array__5546_signature,
    set_array__5546_default_value,
    sizeof(array__5546)
};

/****************************************************************
 ** struct__5549 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5549VTable;

static SimFieldUtils struct__5549_fields[] = {
    {"q_updown", offsetof(struct__5549,q_updown), &_Type_Q_UPDOWN_Utils},
    {"m_version", offsetof(struct__5549,m_version), &_Type_M_VERSION_Utils},
    {"q_media", offsetof(struct__5549,q_media), &_Type_Q_MEDIA_Utils},
    {"n_pig", offsetof(struct__5549,n_pig), &_Type_N_PIG_Utils},
    {"n_total", offsetof(struct__5549,n_total), &_Type_N_TOTAL_Utils},
    {"m_dup", offsetof(struct__5549,m_dup), &_Type_M_DUP_Utils},
    {"m_mcount", offsetof(struct__5549,m_mcount), &_Type_kcg_int_Utils},
    {"nid_c", offsetof(struct__5549,nid_c), &_Type_kcg_int_Utils},
    {"nid_bg", offsetof(struct__5549,nid_bg), &_Type_kcg_int_Utils},
    {"q_link", offsetof(struct__5549,q_link), &_Type_Q_LINK_Utils},
};

int struct__5549_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5549VTable != NULL
        && pSimstruct__5549VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5549VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5549_fields, 10, pfnStrAppend, pData);
}

int string_to_struct__5549(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5549VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5549VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5549_fields, 10, endptr);
    }
    return nRet;
}

int is_struct__5549_double_convertion_allowed()
{
    if (pSimstruct__5549VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5549VTable);
    }
    return 0;
}

void compare_struct__5549(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5549VTable != NULL
        && pSimstruct__5549VTable->m_version >= Scv612
        && pSimstruct__5549VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5549VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5549VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5549VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5549_fields, 10, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5549_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5549VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5549VTable, nRetValue);
    }
    return 0;
}

int get_struct__5549_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5549_fields, 10, pfnStrAppend, pData);
}

int set_struct__5549_default_value(void *pValue)
{
    set_Q_UPDOWN_default_value(&(((struct__5549*)pValue)->q_updown));
    set_M_VERSION_default_value(&(((struct__5549*)pValue)->m_version));
    set_Q_MEDIA_default_value(&(((struct__5549*)pValue)->q_media));
    set_N_PIG_default_value(&(((struct__5549*)pValue)->n_pig));
    set_N_TOTAL_default_value(&(((struct__5549*)pValue)->n_total));
    set_M_DUP_default_value(&(((struct__5549*)pValue)->m_dup));
    set_kcg_int_default_value(&(((struct__5549*)pValue)->m_mcount));
    set_kcg_int_default_value(&(((struct__5549*)pValue)->nid_c));
    set_kcg_int_default_value(&(((struct__5549*)pValue)->nid_bg));
    set_Q_LINK_default_value(&(((struct__5549*)pValue)->q_link));
    return 1;
}

int check_struct__5549_string(const char *str, char **endptr)
{
    static struct__5549 rTemp;
    return string_to_struct__5549(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5549_Utils = {
    struct__5549_to_string,
    check_struct__5549_string,
    string_to_struct__5549,
    is_struct__5549_double_convertion_allowed,
    struct__5549_to_double,
    compare_struct__5549,
    get_struct__5549_signature,
    set_struct__5549_default_value,
    sizeof(struct__5549)
};

/****************************************************************
 ** array_int_500 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_500VTable;

int array_int_500_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_500VTable != NULL
        && pSimarray_int_500VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_500VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 500, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_500(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_500VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_500VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 500, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_500_double_convertion_allowed()
{
    if (pSimarray_int_500VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_500VTable);
    }
    return 0;
}

void compare_array_int_500(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_500VTable != NULL
        && pSimarray_int_500VTable->m_version >= Scv612
        && pSimarray_int_500VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_500VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_500VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_500VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 500, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_500_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_500VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_500VTable, nRetValue);
    }
    return 0;
}

int get_array_int_500_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 500; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_500_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 500; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_500_string(const char *str, char **endptr)
{
    static array_int_500 rTemp;
    return string_to_array_int_500(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_500_Utils = {
    array_int_500_to_string,
    check_array_int_500_string,
    string_to_array_int_500,
    is_array_int_500_double_convertion_allowed,
    array_int_500_to_double,
    compare_array_int_500,
    get_array_int_500_signature,
    set_array_int_500_default_value,
    sizeof(array_int_500)
};

/****************************************************************
 ** struct__5565 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5565VTable;

static SimFieldUtils struct__5565_fields[] = {
    {"nid_packet", offsetof(struct__5565,nid_packet), &_Type_kcg_int_Utils},
    {"q_dir", offsetof(struct__5565,q_dir), &_Type_Q_DIR_Utils},
    {"valid", offsetof(struct__5565,valid), &_Type_kcg_bool_Utils},
    {"startAddress", offsetof(struct__5565,startAddress), &_Type_kcg_int_Utils},
    {"endAddress", offsetof(struct__5565,endAddress), &_Type_kcg_int_Utils},
};

int struct__5565_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5565VTable != NULL
        && pSimstruct__5565VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5565VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5565_fields, 5, pfnStrAppend, pData);
}

int string_to_struct__5565(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5565VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5565VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5565_fields, 5, endptr);
    }
    return nRet;
}

int is_struct__5565_double_convertion_allowed()
{
    if (pSimstruct__5565VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5565VTable);
    }
    return 0;
}

void compare_struct__5565(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5565VTable != NULL
        && pSimstruct__5565VTable->m_version >= Scv612
        && pSimstruct__5565VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5565VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5565VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5565VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5565_fields, 5, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5565_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5565VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5565VTable, nRetValue);
    }
    return 0;
}

int get_struct__5565_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5565_fields, 5, pfnStrAppend, pData);
}

int set_struct__5565_default_value(void *pValue)
{
    set_kcg_int_default_value(&(((struct__5565*)pValue)->nid_packet));
    set_Q_DIR_default_value(&(((struct__5565*)pValue)->q_dir));
    set_kcg_bool_default_value(&(((struct__5565*)pValue)->valid));
    set_kcg_int_default_value(&(((struct__5565*)pValue)->startAddress));
    set_kcg_int_default_value(&(((struct__5565*)pValue)->endAddress));
    return 1;
}

int check_struct__5565_string(const char *str, char **endptr)
{
    static struct__5565 rTemp;
    return string_to_struct__5565(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5565_Utils = {
    struct__5565_to_string,
    check_struct__5565_string,
    string_to_struct__5565,
    is_struct__5565_double_convertion_allowed,
    struct__5565_to_double,
    compare_struct__5565,
    get_struct__5565_signature,
    set_struct__5565_default_value,
    sizeof(struct__5565)
};

/****************************************************************
 ** array__5573 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5573VTable;

int array__5573_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5573VTable != NULL
        && pSimarray__5573VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5573VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, struct__5565_to_string, 30, sizeof(struct__5565), pfnStrAppend, pData);
}

int string_to_array__5573(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5573VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5573VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_struct__5565_Utils, 30, sizeof(struct__5565), endptr);
    }
    return nRet;
}

int is_array__5573_double_convertion_allowed()
{
    if (pSimarray__5573VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5573VTable);
    }
    return 0;
}

void compare_array__5573(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5573VTable != NULL
        && pSimarray__5573VTable->m_version >= Scv612
        && pSimarray__5573VTable->m_pfnCompare != NULL) {
        if (pSimarray__5573VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5573VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5573VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_struct__5565, 30, sizeof(struct__5565), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5573_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5573VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5573VTable, nRetValue);
    }
    return 0;
}

int get_array__5573_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 30; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_struct__5565_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5573_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 30; i++)
        set_struct__5565_default_value(&((struct__5565*)pValue)[i]);
    return 1;
}

int check_array__5573_string(const char *str, char **endptr)
{
    static array__5573 rTemp;
    return string_to_array__5573(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5573_Utils = {
    array__5573_to_string,
    check_array__5573_string,
    string_to_array__5573,
    is_array__5573_double_convertion_allowed,
    array__5573_to_double,
    compare_array__5573,
    get_array__5573_signature,
    set_array__5573_default_value,
    sizeof(array__5573)
};

/****************************************************************
 ** struct__5576 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5576VTable;

static SimFieldUtils struct__5576_fields[] = {
    {"PacketHeaders", offsetof(struct__5576,PacketHeaders), &_Type_array__5573_Utils},
    {"PacketData", offsetof(struct__5576,PacketData), &_Type_array_int_500_Utils},
};

int struct__5576_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5576VTable != NULL
        && pSimstruct__5576VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5576VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5576_fields, 2, pfnStrAppend, pData);
}

int string_to_struct__5576(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5576VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5576VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5576_fields, 2, endptr);
    }
    return nRet;
}

int is_struct__5576_double_convertion_allowed()
{
    if (pSimstruct__5576VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5576VTable);
    }
    return 0;
}

void compare_struct__5576(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5576VTable != NULL
        && pSimstruct__5576VTable->m_version >= Scv612
        && pSimstruct__5576VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5576VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5576VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5576VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5576_fields, 2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5576_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5576VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5576VTable, nRetValue);
    }
    return 0;
}

int get_struct__5576_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5576_fields, 2, pfnStrAppend, pData);
}

int set_struct__5576_default_value(void *pValue)
{
    set_array__5573_default_value(&(((struct__5576*)pValue)->PacketHeaders));
    set_array_int_500_default_value(&(((struct__5576*)pValue)->PacketData));
    return 1;
}

int check_struct__5576_string(const char *str, char **endptr)
{
    static struct__5576 rTemp;
    return string_to_struct__5576(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5576_Utils = {
    struct__5576_to_string,
    check_struct__5576_string,
    string_to_struct__5576,
    is_struct__5576_double_convertion_allowed,
    struct__5576_to_double,
    compare_struct__5576,
    get_struct__5576_signature,
    set_struct__5576_default_value,
    sizeof(struct__5576)
};

/****************************************************************
 ** struct__5581 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5581VTable;

static SimFieldUtils struct__5581_fields[] = {
    {"valid", offsetof(struct__5581,valid), &_Type_kcg_bool_Utils},
    {"d_link", offsetof(struct__5581,d_link), &_Type_kcg_int_Utils},
    {"q_newcountry", offsetof(struct__5581,q_newcountry), &_Type_Q_NEWCOUNTRY_Utils},
    {"nid_c", offsetof(struct__5581,nid_c), &_Type_kcg_int_Utils},
    {"nid_bg", offsetof(struct__5581,nid_bg), &_Type_kcg_int_Utils},
    {"q_linkorientation", offsetof(struct__5581,q_linkorientation), &_Type_Q_LINKORIENTATION_Utils},
    {"q_linkreaction", offsetof(struct__5581,q_linkreaction), &_Type_Q_LINKREACTION_Utils},
    {"q_locacc", offsetof(struct__5581,q_locacc), &_Type_kcg_int_Utils},
};

int struct__5581_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5581VTable != NULL
        && pSimstruct__5581VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5581VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5581_fields, 8, pfnStrAppend, pData);
}

int string_to_struct__5581(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5581VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5581VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5581_fields, 8, endptr);
    }
    return nRet;
}

int is_struct__5581_double_convertion_allowed()
{
    if (pSimstruct__5581VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5581VTable);
    }
    return 0;
}

void compare_struct__5581(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5581VTable != NULL
        && pSimstruct__5581VTable->m_version >= Scv612
        && pSimstruct__5581VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5581VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5581VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5581VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5581_fields, 8, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5581_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5581VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5581VTable, nRetValue);
    }
    return 0;
}

int get_struct__5581_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5581_fields, 8, pfnStrAppend, pData);
}

int set_struct__5581_default_value(void *pValue)
{
    set_kcg_bool_default_value(&(((struct__5581*)pValue)->valid));
    set_kcg_int_default_value(&(((struct__5581*)pValue)->d_link));
    set_Q_NEWCOUNTRY_default_value(&(((struct__5581*)pValue)->q_newcountry));
    set_kcg_int_default_value(&(((struct__5581*)pValue)->nid_c));
    set_kcg_int_default_value(&(((struct__5581*)pValue)->nid_bg));
    set_Q_LINKORIENTATION_default_value(&(((struct__5581*)pValue)->q_linkorientation));
    set_Q_LINKREACTION_default_value(&(((struct__5581*)pValue)->q_linkreaction));
    set_kcg_int_default_value(&(((struct__5581*)pValue)->q_locacc));
    return 1;
}

int check_struct__5581_string(const char *str, char **endptr)
{
    static struct__5581 rTemp;
    return string_to_struct__5581(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5581_Utils = {
    struct__5581_to_string,
    check_struct__5581_string,
    string_to_struct__5581,
    is_struct__5581_double_convertion_allowed,
    struct__5581_to_double,
    compare_struct__5581,
    get_struct__5581_signature,
    set_struct__5581_default_value,
    sizeof(struct__5581)
};

/****************************************************************
 ** array__5592 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5592VTable;

int array__5592_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5592VTable != NULL
        && pSimarray__5592VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5592VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, struct__5581_to_string, 33, sizeof(struct__5581), pfnStrAppend, pData);
}

int string_to_array__5592(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5592VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5592VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_struct__5581_Utils, 33, sizeof(struct__5581), endptr);
    }
    return nRet;
}

int is_array__5592_double_convertion_allowed()
{
    if (pSimarray__5592VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5592VTable);
    }
    return 0;
}

void compare_array__5592(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5592VTable != NULL
        && pSimarray__5592VTable->m_version >= Scv612
        && pSimarray__5592VTable->m_pfnCompare != NULL) {
        if (pSimarray__5592VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5592VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5592VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_struct__5581, 33, sizeof(struct__5581), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5592_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5592VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5592VTable, nRetValue);
    }
    return 0;
}

int get_array__5592_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 33; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_struct__5581_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5592_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 33; i++)
        set_struct__5581_default_value(&((struct__5581*)pValue)[i]);
    return 1;
}

int check_array__5592_string(const char *str, char **endptr)
{
    static array__5592 rTemp;
    return string_to_array__5592(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5592_Utils = {
    array__5592_to_string,
    check_array__5592_string,
    string_to_array__5592,
    is_array__5592_double_convertion_allowed,
    array__5592_to_double,
    compare_array__5592,
    get_array__5592_signature,
    set_array__5592_default_value,
    sizeof(array__5592)
};

/****************************************************************
 ** struct__5595 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5595VTable;

static SimFieldUtils struct__5595_fields[] = {
    {"valid", offsetof(struct__5595,valid), &_Type_kcg_bool_Utils},
    {"q_dir", offsetof(struct__5595,q_dir), &_Type_Q_DIR_Utils},
    {"l_packet", offsetof(struct__5595,l_packet), &_Type_kcg_int_Utils},
    {"q_scale", offsetof(struct__5595,q_scale), &_Type_Q_SCALE_Utils},
    {"n_iter", offsetof(struct__5595,n_iter), &_Type_kcg_int_Utils},
    {"sections", offsetof(struct__5595,sections), &_Type_array__5592_Utils},
};

int struct__5595_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5595VTable != NULL
        && pSimstruct__5595VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5595VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5595_fields, 6, pfnStrAppend, pData);
}

int string_to_struct__5595(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5595VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5595VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5595_fields, 6, endptr);
    }
    return nRet;
}

int is_struct__5595_double_convertion_allowed()
{
    if (pSimstruct__5595VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5595VTable);
    }
    return 0;
}

void compare_struct__5595(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5595VTable != NULL
        && pSimstruct__5595VTable->m_version >= Scv612
        && pSimstruct__5595VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5595VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5595VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5595VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5595_fields, 6, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5595_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5595VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5595VTable, nRetValue);
    }
    return 0;
}

int get_struct__5595_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5595_fields, 6, pfnStrAppend, pData);
}

int set_struct__5595_default_value(void *pValue)
{
    set_kcg_bool_default_value(&(((struct__5595*)pValue)->valid));
    set_Q_DIR_default_value(&(((struct__5595*)pValue)->q_dir));
    set_kcg_int_default_value(&(((struct__5595*)pValue)->l_packet));
    set_Q_SCALE_default_value(&(((struct__5595*)pValue)->q_scale));
    set_kcg_int_default_value(&(((struct__5595*)pValue)->n_iter));
    set_array__5592_default_value(&(((struct__5595*)pValue)->sections));
    return 1;
}

int check_struct__5595_string(const char *str, char **endptr)
{
    static struct__5595 rTemp;
    return string_to_struct__5595(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5595_Utils = {
    struct__5595_to_string,
    check_struct__5595_string,
    string_to_struct__5595,
    is_struct__5595_double_convertion_allowed,
    struct__5595_to_double,
    compare_struct__5595,
    get_struct__5595_signature,
    set_struct__5595_default_value,
    sizeof(struct__5595)
};

/****************************************************************
 ** array_int_224 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_224VTable;

int array_int_224_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_224VTable != NULL
        && pSimarray_int_224VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_224VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 224, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_224(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_224VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_224VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 224, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_224_double_convertion_allowed()
{
    if (pSimarray_int_224VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_224VTable);
    }
    return 0;
}

void compare_array_int_224(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_224VTable != NULL
        && pSimarray_int_224VTable->m_version >= Scv612
        && pSimarray_int_224VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_224VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_224VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_224VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 224, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_224_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_224VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_224VTable, nRetValue);
    }
    return 0;
}

int get_array_int_224_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 224; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_224_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 224; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_224_string(const char *str, char **endptr)
{
    static array_int_224 rTemp;
    return string_to_array_int_224(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_224_Utils = {
    array_int_224_to_string,
    check_array_int_224_string,
    string_to_array_int_224,
    is_array_int_224_double_convertion_allowed,
    array_int_224_to_double,
    compare_array_int_224,
    get_array_int_224_signature,
    set_array_int_224_default_value,
    sizeof(array_int_224)
};

/****************************************************************
 ** array_int_3 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_3VTable;

int array_int_3_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_3VTable != NULL
        && pSimarray_int_3VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_3VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 3, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_3(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_3VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_3VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 3, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_3_double_convertion_allowed()
{
    if (pSimarray_int_3VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_3VTable);
    }
    return 0;
}

void compare_array_int_3(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_3VTable != NULL
        && pSimarray_int_3VTable->m_version >= Scv612
        && pSimarray_int_3VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_3VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_3VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_3VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 3, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_3_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_3VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_3VTable, nRetValue);
    }
    return 0;
}

int get_array_int_3_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 3; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_3_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 3; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_3_string(const char *str, char **endptr)
{
    static array_int_3 rTemp;
    return string_to_array_int_3(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_3_Utils = {
    array_int_3_to_string,
    check_array_int_3_string,
    string_to_array_int_3,
    is_array_int_3_double_convertion_allowed,
    array_int_3_to_double,
    compare_array_int_3,
    get_array_int_3_signature,
    set_array_int_3_default_value,
    sizeof(array_int_3)
};

/****************************************************************
 ** struct__5610 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5610VTable;

static SimFieldUtils struct__5610_fields[] = {
    {"q_updown", offsetof(struct__5610,q_updown), &_Type_kcg_int_Utils},
    {"m_version", offsetof(struct__5610,m_version), &_Type_kcg_int_Utils},
    {"q_media", offsetof(struct__5610,q_media), &_Type_kcg_int_Utils},
    {"n_pig", offsetof(struct__5610,n_pig), &_Type_kcg_int_Utils},
    {"n_total", offsetof(struct__5610,n_total), &_Type_kcg_int_Utils},
    {"m_dup", offsetof(struct__5610,m_dup), &_Type_kcg_int_Utils},
    {"m_mcount", offsetof(struct__5610,m_mcount), &_Type_kcg_int_Utils},
    {"nid_c", offsetof(struct__5610,nid_c), &_Type_kcg_int_Utils},
    {"nid_bg", offsetof(struct__5610,nid_bg), &_Type_kcg_int_Utils},
    {"q_link", offsetof(struct__5610,q_link), &_Type_kcg_int_Utils},
};

int struct__5610_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5610VTable != NULL
        && pSimstruct__5610VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5610VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5610_fields, 10, pfnStrAppend, pData);
}

int string_to_struct__5610(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5610VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5610VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5610_fields, 10, endptr);
    }
    return nRet;
}

int is_struct__5610_double_convertion_allowed()
{
    if (pSimstruct__5610VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5610VTable);
    }
    return 0;
}

void compare_struct__5610(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5610VTable != NULL
        && pSimstruct__5610VTable->m_version >= Scv612
        && pSimstruct__5610VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5610VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5610VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5610VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5610_fields, 10, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5610_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5610VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5610VTable, nRetValue);
    }
    return 0;
}

int get_struct__5610_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5610_fields, 10, pfnStrAppend, pData);
}

int set_struct__5610_default_value(void *pValue)
{
    set_kcg_int_default_value(&(((struct__5610*)pValue)->q_updown));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->m_version));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->q_media));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->n_pig));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->n_total));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->m_dup));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->m_mcount));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->nid_c));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->nid_bg));
    set_kcg_int_default_value(&(((struct__5610*)pValue)->q_link));
    return 1;
}

int check_struct__5610_string(const char *str, char **endptr)
{
    static struct__5610 rTemp;
    return string_to_struct__5610(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5610_Utils = {
    struct__5610_to_string,
    check_struct__5610_string,
    string_to_struct__5610,
    is_struct__5610_double_convertion_allowed,
    struct__5610_to_double,
    compare_struct__5610,
    get_struct__5610_signature,
    set_struct__5610_default_value,
    sizeof(struct__5610)
};

/****************************************************************
 ** struct__5623 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5623VTable;

static SimFieldUtils struct__5623_fields[] = {
    {"Header", offsetof(struct__5623,Header), &_Type_struct__5610_Utils},
    {"Messages", offsetof(struct__5623,Messages), &_Type_struct__5576_Utils},
};

int struct__5623_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5623VTable != NULL
        && pSimstruct__5623VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5623VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5623_fields, 2, pfnStrAppend, pData);
}

int string_to_struct__5623(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5623VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5623VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5623_fields, 2, endptr);
    }
    return nRet;
}

int is_struct__5623_double_convertion_allowed()
{
    if (pSimstruct__5623VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5623VTable);
    }
    return 0;
}

void compare_struct__5623(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5623VTable != NULL
        && pSimstruct__5623VTable->m_version >= Scv612
        && pSimstruct__5623VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5623VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5623VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5623VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5623_fields, 2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5623_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5623VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5623VTable, nRetValue);
    }
    return 0;
}

int get_struct__5623_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5623_fields, 2, pfnStrAppend, pData);
}

int set_struct__5623_default_value(void *pValue)
{
    set_struct__5610_default_value(&(((struct__5623*)pValue)->Header));
    set_struct__5576_default_value(&(((struct__5623*)pValue)->Messages));
    return 1;
}

int check_struct__5623_string(const char *str, char **endptr)
{
    static struct__5623 rTemp;
    return string_to_struct__5623(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5623_Utils = {
    struct__5623_to_string,
    check_struct__5623_string,
    string_to_struct__5623,
    is_struct__5623_double_convertion_allowed,
    struct__5623_to_double,
    compare_struct__5623,
    get_struct__5623_signature,
    set_struct__5623_default_value,
    sizeof(struct__5623)
};

/****************************************************************
 ** struct__5628 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5628VTable;

static SimFieldUtils struct__5628_fields[] = {
    {"NID_C", offsetof(struct__5628,NID_C), &_Type_kcg_int_Utils},
    {"NID_BG", offsetof(struct__5628,NID_BG), &_Type_kcg_int_Utils},
    {"Pos", offsetof(struct__5628,Pos), &_Type_kcg_int_Utils},
    {"Or_BG", offsetof(struct__5628,Or_BG), &_Type_OrBG_TM_Utils},
    {"Or_Line", offsetof(struct__5628,Or_Line), &_Type_OrLine_TM_Utils},
};

int struct__5628_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5628VTable != NULL
        && pSimstruct__5628VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5628VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5628_fields, 5, pfnStrAppend, pData);
}

int string_to_struct__5628(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5628VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5628VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5628_fields, 5, endptr);
    }
    return nRet;
}

int is_struct__5628_double_convertion_allowed()
{
    if (pSimstruct__5628VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5628VTable);
    }
    return 0;
}

void compare_struct__5628(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5628VTable != NULL
        && pSimstruct__5628VTable->m_version >= Scv612
        && pSimstruct__5628VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5628VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5628VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5628VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5628_fields, 5, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5628_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5628VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5628VTable, nRetValue);
    }
    return 0;
}

int get_struct__5628_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5628_fields, 5, pfnStrAppend, pData);
}

int set_struct__5628_default_value(void *pValue)
{
    set_kcg_int_default_value(&(((struct__5628*)pValue)->NID_C));
    set_kcg_int_default_value(&(((struct__5628*)pValue)->NID_BG));
    set_kcg_int_default_value(&(((struct__5628*)pValue)->Pos));
    set_OrBG_TM_default_value(&(((struct__5628*)pValue)->Or_BG));
    set_OrLine_TM_default_value(&(((struct__5628*)pValue)->Or_Line));
    return 1;
}

int check_struct__5628_string(const char *str, char **endptr)
{
    static struct__5628 rTemp;
    return string_to_struct__5628(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5628_Utils = {
    struct__5628_to_string,
    check_struct__5628_string,
    string_to_struct__5628,
    is_struct__5628_double_convertion_allowed,
    struct__5628_to_double,
    compare_struct__5628,
    get_struct__5628_signature,
    set_struct__5628_default_value,
    sizeof(struct__5628)
};

/****************************************************************
 ** struct__5636 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5636VTable;

static SimFieldUtils struct__5636_fields[] = {
    {"header", offsetof(struct__5636,header), &_Type_struct__5610_Utils},
    {"packets", offsetof(struct__5636,packets), &_Type_struct__5576_Utils},
    {"engineering_BG_location", offsetof(struct__5636,engineering_BG_location), &_Type_kcg_int_Utils},
    {"TrainPos", offsetof(struct__5636,TrainPos), &_Type_kcg_real_Utils},
    {"pig_nom_0", offsetof(struct__5636,pig_nom_0), &_Type_kcg_int_Utils},
    {"balise_passed", offsetof(struct__5636,balise_passed), &_Type_kcg_bool_Utils},
};

int struct__5636_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5636VTable != NULL
        && pSimstruct__5636VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5636VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5636_fields, 6, pfnStrAppend, pData);
}

int string_to_struct__5636(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5636VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5636VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5636_fields, 6, endptr);
    }
    return nRet;
}

int is_struct__5636_double_convertion_allowed()
{
    if (pSimstruct__5636VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5636VTable);
    }
    return 0;
}

void compare_struct__5636(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5636VTable != NULL
        && pSimstruct__5636VTable->m_version >= Scv612
        && pSimstruct__5636VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5636VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5636VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5636VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5636_fields, 6, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5636_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5636VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5636VTable, nRetValue);
    }
    return 0;
}

int get_struct__5636_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5636_fields, 6, pfnStrAppend, pData);
}

int set_struct__5636_default_value(void *pValue)
{
    set_struct__5610_default_value(&(((struct__5636*)pValue)->header));
    set_struct__5576_default_value(&(((struct__5636*)pValue)->packets));
    set_kcg_int_default_value(&(((struct__5636*)pValue)->engineering_BG_location));
    set_kcg_real_default_value(&(((struct__5636*)pValue)->TrainPos));
    set_kcg_int_default_value(&(((struct__5636*)pValue)->pig_nom_0));
    set_kcg_bool_default_value(&(((struct__5636*)pValue)->balise_passed));
    return 1;
}

int check_struct__5636_string(const char *str, char **endptr)
{
    static struct__5636 rTemp;
    return string_to_struct__5636(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5636_Utils = {
    struct__5636_to_string,
    check_struct__5636_string,
    string_to_struct__5636,
    is_struct__5636_double_convertion_allowed,
    struct__5636_to_double,
    compare_struct__5636,
    get_struct__5636_signature,
    set_struct__5636_default_value,
    sizeof(struct__5636)
};

/****************************************************************
 ** struct__5645 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5645VTable;

static SimFieldUtils struct__5645_fields[] = {
    {"D_LINK", offsetof(struct__5645,D_LINK), &_Type_kcg_int_Utils},
    {"Q_NEWCOUNTRY", offsetof(struct__5645,Q_NEWCOUNTRY), &_Type_kcg_int_Utils},
    {"NID_C", offsetof(struct__5645,NID_C), &_Type_kcg_int_Utils},
    {"NID_BG", offsetof(struct__5645,NID_BG), &_Type_kcg_int_Utils},
    {"Q_LINKORIENTATION", offsetof(struct__5645,Q_LINKORIENTATION), &_Type_kcg_int_Utils},
    {"Q_LINKREACTION", offsetof(struct__5645,Q_LINKREACTION), &_Type_kcg_int_Utils},
    {"Q_LOCACC", offsetof(struct__5645,Q_LOCACC), &_Type_kcg_int_Utils},
};

int struct__5645_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5645VTable != NULL
        && pSimstruct__5645VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5645VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5645_fields, 7, pfnStrAppend, pData);
}

int string_to_struct__5645(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5645VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5645VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5645_fields, 7, endptr);
    }
    return nRet;
}

int is_struct__5645_double_convertion_allowed()
{
    if (pSimstruct__5645VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5645VTable);
    }
    return 0;
}

void compare_struct__5645(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5645VTable != NULL
        && pSimstruct__5645VTable->m_version >= Scv612
        && pSimstruct__5645VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5645VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5645VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5645VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5645_fields, 7, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5645_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5645VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5645VTable, nRetValue);
    }
    return 0;
}

int get_struct__5645_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5645_fields, 7, pfnStrAppend, pData);
}

int set_struct__5645_default_value(void *pValue)
{
    set_kcg_int_default_value(&(((struct__5645*)pValue)->D_LINK));
    set_kcg_int_default_value(&(((struct__5645*)pValue)->Q_NEWCOUNTRY));
    set_kcg_int_default_value(&(((struct__5645*)pValue)->NID_C));
    set_kcg_int_default_value(&(((struct__5645*)pValue)->NID_BG));
    set_kcg_int_default_value(&(((struct__5645*)pValue)->Q_LINKORIENTATION));
    set_kcg_int_default_value(&(((struct__5645*)pValue)->Q_LINKREACTION));
    set_kcg_int_default_value(&(((struct__5645*)pValue)->Q_LOCACC));
    return 1;
}

int check_struct__5645_string(const char *str, char **endptr)
{
    static struct__5645 rTemp;
    return string_to_struct__5645(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5645_Utils = {
    struct__5645_to_string,
    check_struct__5645_string,
    string_to_struct__5645,
    is_struct__5645_double_convertion_allowed,
    struct__5645_to_double,
    compare_struct__5645,
    get_struct__5645_signature,
    set_struct__5645_default_value,
    sizeof(struct__5645)
};

/****************************************************************
 ** array__5655 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5655VTable;

int array__5655_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5655VTable != NULL
        && pSimarray__5655VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5655VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, struct__5645_to_string, 32, sizeof(struct__5645), pfnStrAppend, pData);
}

int string_to_array__5655(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5655VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5655VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_struct__5645_Utils, 32, sizeof(struct__5645), endptr);
    }
    return nRet;
}

int is_array__5655_double_convertion_allowed()
{
    if (pSimarray__5655VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5655VTable);
    }
    return 0;
}

void compare_array__5655(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5655VTable != NULL
        && pSimarray__5655VTable->m_version >= Scv612
        && pSimarray__5655VTable->m_pfnCompare != NULL) {
        if (pSimarray__5655VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5655VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5655VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_struct__5645, 32, sizeof(struct__5645), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5655_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5655VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5655VTable, nRetValue);
    }
    return 0;
}

int get_array__5655_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 32; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_struct__5645_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5655_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 32; i++)
        set_struct__5645_default_value(&((struct__5645*)pValue)[i]);
    return 1;
}

int check_array__5655_string(const char *str, char **endptr)
{
    static array__5655 rTemp;
    return string_to_array__5655(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5655_Utils = {
    array__5655_to_string,
    check_array__5655_string,
    string_to_array__5655,
    is_array__5655_double_convertion_allowed,
    array__5655_to_double,
    compare_array__5655,
    get_array__5655_signature,
    set_array__5655_default_value,
    sizeof(array__5655)
};

/****************************************************************
 ** struct__5658 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__5658VTable;

static SimFieldUtils struct__5658_fields[] = {
    {"valid", offsetof(struct__5658,valid), &_Type_kcg_bool_Utils},
    {"NID_PACKET", offsetof(struct__5658,NID_PACKET), &_Type_kcg_int_Utils},
    {"Q_DIR", offsetof(struct__5658,Q_DIR), &_Type_kcg_int_Utils},
    {"L_PACKET", offsetof(struct__5658,L_PACKET), &_Type_kcg_int_Utils},
    {"Q_SCALE", offsetof(struct__5658,Q_SCALE), &_Type_kcg_int_Utils},
    {"D_LINK", offsetof(struct__5658,D_LINK), &_Type_kcg_int_Utils},
    {"Q_NEWCOUNTRY", offsetof(struct__5658,Q_NEWCOUNTRY), &_Type_kcg_int_Utils},
    {"NID_C", offsetof(struct__5658,NID_C), &_Type_kcg_int_Utils},
    {"NID_BG", offsetof(struct__5658,NID_BG), &_Type_kcg_int_Utils},
    {"Q_LINKORIENTATION", offsetof(struct__5658,Q_LINKORIENTATION), &_Type_kcg_int_Utils},
    {"Q_LINKREACTION", offsetof(struct__5658,Q_LINKREACTION), &_Type_kcg_int_Utils},
    {"Q_LOCACC", offsetof(struct__5658,Q_LOCACC), &_Type_kcg_int_Utils},
    {"N_ITER", offsetof(struct__5658,N_ITER), &_Type_kcg_int_Utils},
    {"SECTIONS", offsetof(struct__5658,SECTIONS), &_Type_array__5655_Utils},
};

int struct__5658_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__5658VTable != NULL
        && pSimstruct__5658VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__5658VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__5658_fields, 14, pfnStrAppend, pData);
}

int string_to_struct__5658(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__5658VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__5658VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__5658_fields, 14, endptr);
    }
    return nRet;
}

int is_struct__5658_double_convertion_allowed()
{
    if (pSimstruct__5658VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__5658VTable);
    }
    return 0;
}

void compare_struct__5658(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__5658VTable != NULL
        && pSimstruct__5658VTable->m_version >= Scv612
        && pSimstruct__5658VTable->m_pfnCompare != NULL) {
        if (pSimstruct__5658VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__5658VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__5658VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__5658_fields, 14, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__5658_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__5658VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__5658VTable, nRetValue);
    }
    return 0;
}

int get_struct__5658_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__5658_fields, 14, pfnStrAppend, pData);
}

int set_struct__5658_default_value(void *pValue)
{
    set_kcg_bool_default_value(&(((struct__5658*)pValue)->valid));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->NID_PACKET));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->Q_DIR));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->L_PACKET));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->Q_SCALE));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->D_LINK));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->Q_NEWCOUNTRY));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->NID_C));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->NID_BG));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->Q_LINKORIENTATION));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->Q_LINKREACTION));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->Q_LOCACC));
    set_kcg_int_default_value(&(((struct__5658*)pValue)->N_ITER));
    set_array__5655_default_value(&(((struct__5658*)pValue)->SECTIONS));
    return 1;
}

int check_struct__5658_string(const char *str, char **endptr)
{
    static struct__5658 rTemp;
    return string_to_struct__5658(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__5658_Utils = {
    struct__5658_to_string,
    check_struct__5658_string,
    string_to_struct__5658,
    is_struct__5658_double_convertion_allowed,
    struct__5658_to_double,
    compare_struct__5658,
    get_struct__5658_signature,
    set_struct__5658_default_value,
    sizeof(struct__5658)
};

/****************************************************************
 ** array_int_7 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_7VTable;

int array_int_7_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_7VTable != NULL
        && pSimarray_int_7VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_7VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 7, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_7(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_7VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_7VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 7, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_7_double_convertion_allowed()
{
    if (pSimarray_int_7VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_7VTable);
    }
    return 0;
}

void compare_array_int_7(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_7VTable != NULL
        && pSimarray_int_7VTable->m_version >= Scv612
        && pSimarray_int_7VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_7VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_7VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_7VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 7, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_7_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_7VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_7VTable, nRetValue);
    }
    return 0;
}

int get_array_int_7_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 7; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_7_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 7; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_7_string(const char *str, char **endptr)
{
    static array_int_7 rTemp;
    return string_to_array_int_7(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_7_Utils = {
    array_int_7_to_string,
    check_array_int_7_string,
    string_to_array_int_7,
    is_array_int_7_double_convertion_allowed,
    array_int_7_to_double,
    compare_array_int_7,
    get_array_int_7_signature,
    set_array_int_7_default_value,
    sizeof(array_int_7)
};

/****************************************************************
 ** array_int_7_33 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_7_33VTable;

int array_int_7_33_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_7_33VTable != NULL
        && pSimarray_int_7_33VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_7_33VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, array_int_7_to_string, 33, sizeof(array_int_7), pfnStrAppend, pData);
}

int string_to_array_int_7_33(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_7_33VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_7_33VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_array_int_7_Utils, 33, sizeof(array_int_7), endptr);
    }
    return nRet;
}

int is_array_int_7_33_double_convertion_allowed()
{
    if (pSimarray_int_7_33VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_7_33VTable);
    }
    return 0;
}

void compare_array_int_7_33(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_7_33VTable != NULL
        && pSimarray_int_7_33VTable->m_version >= Scv612
        && pSimarray_int_7_33VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_7_33VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_7_33VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_7_33VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_array_int_7, 33, sizeof(array_int_7), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_7_33_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_7_33VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_7_33VTable, nRetValue);
    }
    return 0;
}

int get_array_int_7_33_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 33; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_array_int_7_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_7_33_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 33; i++)
        set_array_int_7_default_value(&((array_int_7*)pValue)[i]);
    return 1;
}

int check_array_int_7_33_string(const char *str, char **endptr)
{
    static array_int_7_33 rTemp;
    return string_to_array_int_7_33(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_7_33_Utils = {
    array_int_7_33_to_string,
    check_array_int_7_33_string,
    string_to_array_int_7_33,
    is_array_int_7_33_double_convertion_allowed,
    array_int_7_33_to_double,
    compare_array_int_7_33,
    get_array_int_7_33_signature,
    set_array_int_7_33_default_value,
    sizeof(array_int_7_33)
};

/****************************************************************
 ** array__5681 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5681VTable;

int array__5681_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5681VTable != NULL
        && pSimarray__5681VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5681VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, struct__5645_to_string, 33, sizeof(struct__5645), pfnStrAppend, pData);
}

int string_to_array__5681(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5681VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5681VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_struct__5645_Utils, 33, sizeof(struct__5645), endptr);
    }
    return nRet;
}

int is_array__5681_double_convertion_allowed()
{
    if (pSimarray__5681VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5681VTable);
    }
    return 0;
}

void compare_array__5681(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5681VTable != NULL
        && pSimarray__5681VTable->m_version >= Scv612
        && pSimarray__5681VTable->m_pfnCompare != NULL) {
        if (pSimarray__5681VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5681VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5681VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_struct__5645, 33, sizeof(struct__5645), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5681_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5681VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5681VTable, nRetValue);
    }
    return 0;
}

int get_array__5681_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 33; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_struct__5645_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5681_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 33; i++)
        set_struct__5645_default_value(&((struct__5645*)pValue)[i]);
    return 1;
}

int check_array__5681_string(const char *str, char **endptr)
{
    static array__5681 rTemp;
    return string_to_array__5681(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5681_Utils = {
    array__5681_to_string,
    check_array__5681_string,
    string_to_array__5681,
    is_array__5681_double_convertion_allowed,
    array__5681_to_double,
    compare_array__5681,
    get_array__5681_signature,
    set_array__5681_default_value,
    sizeof(array__5681)
};

/****************************************************************
 ** array_int_500_500 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_500_500VTable;

int array_int_500_500_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_500_500VTable != NULL
        && pSimarray_int_500_500VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_500_500VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, array_int_500_to_string, 500, sizeof(array_int_500), pfnStrAppend, pData);
}

int string_to_array_int_500_500(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_500_500VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_500_500VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_array_int_500_Utils, 500, sizeof(array_int_500), endptr);
    }
    return nRet;
}

int is_array_int_500_500_double_convertion_allowed()
{
    if (pSimarray_int_500_500VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_500_500VTable);
    }
    return 0;
}

void compare_array_int_500_500(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_500_500VTable != NULL
        && pSimarray_int_500_500VTable->m_version >= Scv612
        && pSimarray_int_500_500VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_500_500VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_500_500VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_500_500VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_array_int_500, 500, sizeof(array_int_500), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_500_500_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_500_500VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_500_500VTable, nRetValue);
    }
    return 0;
}

int get_array_int_500_500_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 500; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_array_int_500_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_500_500_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 500; i++)
        set_array_int_500_default_value(&((array_int_500*)pValue)[i]);
    return 1;
}

int check_array_int_500_500_string(const char *str, char **endptr)
{
    static array_int_500_500 rTemp;
    return string_to_array_int_500_500(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_500_500_Utils = {
    array_int_500_500_to_string,
    check_array_int_500_500_string,
    string_to_array_int_500_500,
    is_array_int_500_500_double_convertion_allowed,
    array_int_500_500_to_double,
    compare_array_int_500_500,
    get_array_int_500_500_signature,
    set_array_int_500_500_default_value,
    sizeof(array_int_500_500)
};

/****************************************************************
 ** array_int_7_33_231 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_7_33_231VTable;

int array_int_7_33_231_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_7_33_231VTable != NULL
        && pSimarray_int_7_33_231VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_7_33_231VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, array_int_7_33_to_string, 231, sizeof(array_int_7_33), pfnStrAppend, pData);
}

int string_to_array_int_7_33_231(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_7_33_231VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_7_33_231VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_array_int_7_33_Utils, 231, sizeof(array_int_7_33), endptr);
    }
    return nRet;
}

int is_array_int_7_33_231_double_convertion_allowed()
{
    if (pSimarray_int_7_33_231VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_7_33_231VTable);
    }
    return 0;
}

void compare_array_int_7_33_231(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_7_33_231VTable != NULL
        && pSimarray_int_7_33_231VTable->m_version >= Scv612
        && pSimarray_int_7_33_231VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_7_33_231VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_7_33_231VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_7_33_231VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_array_int_7_33, 231, sizeof(array_int_7_33), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_7_33_231_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_7_33_231VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_7_33_231VTable, nRetValue);
    }
    return 0;
}

int get_array_int_7_33_231_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 231; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_array_int_7_33_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_7_33_231_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 231; i++)
        set_array_int_7_33_default_value(&((array_int_7_33*)pValue)[i]);
    return 1;
}

int check_array_int_7_33_231_string(const char *str, char **endptr)
{
    static array_int_7_33_231 rTemp;
    return string_to_array_int_7_33_231(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_7_33_231_Utils = {
    array_int_7_33_231_to_string,
    check_array_int_7_33_231_string,
    string_to_array_int_7_33_231,
    is_array_int_7_33_231_double_convertion_allowed,
    array_int_7_33_231_to_double,
    compare_array_int_7_33_231,
    get_array_int_7_33_231_signature,
    set_array_int_7_33_231_default_value,
    sizeof(array_int_7_33_231)
};

/****************************************************************
 ** array_int_271 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_271VTable;

int array_int_271_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_271VTable != NULL
        && pSimarray_int_271VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_271VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 271, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_271(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_271VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_271VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 271, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_271_double_convertion_allowed()
{
    if (pSimarray_int_271VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_271VTable);
    }
    return 0;
}

void compare_array_int_271(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_271VTable != NULL
        && pSimarray_int_271VTable->m_version >= Scv612
        && pSimarray_int_271VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_271VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_271VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_271VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 271, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_271_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_271VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_271VTable, nRetValue);
    }
    return 0;
}

int get_array_int_271_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 271; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_271_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 271; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_271_string(const char *str, char **endptr)
{
    static array_int_271 rTemp;
    return string_to_array_int_271(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_271_Utils = {
    array_int_271_to_string,
    check_array_int_271_string,
    string_to_array_int_271,
    is_array_int_271_double_convertion_allowed,
    array_int_271_to_double,
    compare_array_int_271,
    get_array_int_271_signature,
    set_array_int_271_default_value,
    sizeof(array_int_271)
};

/****************************************************************
 ** array_int_4 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_4VTable;

int array_int_4_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_4VTable != NULL
        && pSimarray_int_4VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_4VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 4, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_4(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_4VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_4VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 4, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_4_double_convertion_allowed()
{
    if (pSimarray_int_4VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_4VTable);
    }
    return 0;
}

void compare_array_int_4(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_4VTable != NULL
        && pSimarray_int_4VTable->m_version >= Scv612
        && pSimarray_int_4VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_4VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_4VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_4VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 4, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_4_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_4VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_4VTable, nRetValue);
    }
    return 0;
}

int get_array_int_4_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 4; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_4_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 4; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_4_string(const char *str, char **endptr)
{
    static array_int_4 rTemp;
    return string_to_array_int_4(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_4_Utils = {
    array_int_4_to_string,
    check_array_int_4_string,
    string_to_array_int_4,
    is_array_int_4_double_convertion_allowed,
    array_int_4_to_double,
    compare_array_int_4,
    get_array_int_4_signature,
    set_array_int_4_default_value,
    sizeof(array_int_4)
};

/****************************************************************
 ** array_int_1 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_1VTable;

int array_int_1_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_1VTable != NULL
        && pSimarray_int_1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_1VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 1, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_1(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_1VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_1VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 1, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_1_double_convertion_allowed()
{
    if (pSimarray_int_1VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_1VTable);
    }
    return 0;
}

void compare_array_int_1(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_1VTable != NULL
        && pSimarray_int_1VTable->m_version >= Scv612
        && pSimarray_int_1VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_1VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_1VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_1VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 1, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_1_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_1VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_1VTable, nRetValue);
    }
    return 0;
}

int get_array_int_1_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 1; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_1_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 1; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_1_string(const char *str, char **endptr)
{
    static array_int_1 rTemp;
    return string_to_array_int_1(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_1_Utils = {
    array_int_1_to_string,
    check_array_int_1_string,
    string_to_array_int_1,
    is_array_int_1_double_convertion_allowed,
    array_int_1_to_double,
    compare_array_int_1,
    get_array_int_1_signature,
    set_array_int_1_default_value,
    sizeof(array_int_1)
};

/****************************************************************
 ** array_int_5 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_5VTable;

int array_int_5_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_5VTable != NULL
        && pSimarray_int_5VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_5VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 5, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_5(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_5VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_5VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 5, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_5_double_convertion_allowed()
{
    if (pSimarray_int_5VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_5VTable);
    }
    return 0;
}

void compare_array_int_5(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_5VTable != NULL
        && pSimarray_int_5VTable->m_version >= Scv612
        && pSimarray_int_5VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_5VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_5VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_5VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 5, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_5_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_5VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_5VTable, nRetValue);
    }
    return 0;
}

int get_array_int_5_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 5; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_5_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 5; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_5_string(const char *str, char **endptr)
{
    static array_int_5 rTemp;
    return string_to_array_int_5(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_5_Utils = {
    array_int_5_to_string,
    check_array_int_5_string,
    string_to_array_int_5,
    is_array_int_5_double_convertion_allowed,
    array_int_5_to_double,
    compare_array_int_5,
    get_array_int_5_signature,
    set_array_int_5_default_value,
    sizeof(array_int_5)
};

/****************************************************************
 ** array_int_229 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_229VTable;

int array_int_229_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_229VTable != NULL
        && pSimarray_int_229VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_229VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 229, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_229(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_229VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_229VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 229, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_229_double_convertion_allowed()
{
    if (pSimarray_int_229VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_229VTable);
    }
    return 0;
}

void compare_array_int_229(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_229VTable != NULL
        && pSimarray_int_229VTable->m_version >= Scv612
        && pSimarray_int_229VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_229VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_229VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_229VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 229, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_229_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_229VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_229VTable, nRetValue);
    }
    return 0;
}

int get_array_int_229_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 229; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_229_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 229; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_229_string(const char *str, char **endptr)
{
    static array_int_229 rTemp;
    return string_to_array_int_229(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_229_Utils = {
    array_int_229_to_string,
    check_array_int_229_string,
    string_to_array_int_229,
    is_array_int_229_double_convertion_allowed,
    array_int_229_to_double,
    compare_array_int_229,
    get_array_int_229_signature,
    set_array_int_229_default_value,
    sizeof(array_int_229)
};

/****************************************************************
 ** array__5705 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5705VTable;

int array__5705_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5705VTable != NULL
        && pSimarray__5705VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5705VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, struct__5645_to_string, 1, sizeof(struct__5645), pfnStrAppend, pData);
}

int string_to_array__5705(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5705VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5705VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_struct__5645_Utils, 1, sizeof(struct__5645), endptr);
    }
    return nRet;
}

int is_array__5705_double_convertion_allowed()
{
    if (pSimarray__5705VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5705VTable);
    }
    return 0;
}

void compare_array__5705(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5705VTable != NULL
        && pSimarray__5705VTable->m_version >= Scv612
        && pSimarray__5705VTable->m_pfnCompare != NULL) {
        if (pSimarray__5705VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5705VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5705VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_struct__5645, 1, sizeof(struct__5645), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5705_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5705VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5705VTable, nRetValue);
    }
    return 0;
}

int get_array__5705_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 1; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_struct__5645_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5705_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 1; i++)
        set_struct__5645_default_value(&((struct__5645*)pValue)[i]);
    return 1;
}

int check_array__5705_string(const char *str, char **endptr)
{
    static array__5705 rTemp;
    return string_to_array__5705(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5705_Utils = {
    array__5705_to_string,
    check_array__5705_string,
    string_to_array__5705,
    is_array__5705_double_convertion_allowed,
    array__5705_to_double,
    compare_array__5705,
    get_array__5705_signature,
    set_array__5705_default_value,
    sizeof(array__5705)
};

/****************************************************************
 ** array_int_30 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_30VTable;

int array_int_30_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_30VTable != NULL
        && pSimarray_int_30VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_30VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 30, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_30(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_30VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_30VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 30, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_30_double_convertion_allowed()
{
    if (pSimarray_int_30VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_30VTable);
    }
    return 0;
}

void compare_array_int_30(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_30VTable != NULL
        && pSimarray_int_30VTable->m_version >= Scv612
        && pSimarray_int_30VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_30VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_30VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_30VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 30, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_30_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_30VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_30VTable, nRetValue);
    }
    return 0;
}

int get_array_int_30_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 30; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_30_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 30; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_30_string(const char *str, char **endptr)
{
    static array_int_30 rTemp;
    return string_to_array_int_30(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_30_Utils = {
    array_int_30_to_string,
    check_array_int_30_string,
    string_to_array_int_30,
    is_array_int_30_double_convertion_allowed,
    array_int_30_to_double,
    compare_array_int_30,
    get_array_int_30_signature,
    set_array_int_30_default_value,
    sizeof(array_int_30)
};

/****************************************************************
 ** array_int_33 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_33VTable;

int array_int_33_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_33VTable != NULL
        && pSimarray_int_33VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_33VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_int_to_string, 33, sizeof(kcg_int), pfnStrAppend, pData);
}

int string_to_array_int_33(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_33VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_33VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_int_Utils, 33, sizeof(kcg_int), endptr);
    }
    return nRet;
}

int is_array_int_33_double_convertion_allowed()
{
    if (pSimarray_int_33VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_33VTable);
    }
    return 0;
}

void compare_array_int_33(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_33VTable != NULL
        && pSimarray_int_33VTable->m_version >= Scv612
        && pSimarray_int_33VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_33VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_33VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_33VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_int, 33, sizeof(kcg_int), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_33_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_33VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_33VTable, nRetValue);
    }
    return 0;
}

int get_array_int_33_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 33; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_int_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_33_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 33; i++)
        set_kcg_int_default_value(&((kcg_int*)pValue)[i]);
    return 1;
}

int check_array_int_33_string(const char *str, char **endptr)
{
    static array_int_33 rTemp;
    return string_to_array_int_33(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_33_Utils = {
    array_int_33_to_string,
    check_array_int_33_string,
    string_to_array_int_33,
    is_array_int_33_double_convertion_allowed,
    array_int_33_to_double,
    compare_array_int_33,
    get_array_int_33_signature,
    set_array_int_33_default_value,
    sizeof(array_int_33)
};

/****************************************************************
 ** array_int_224_33 
 ****************************************************************/

struct SimTypeVTable *pSimarray_int_224_33VTable;

int array_int_224_33_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray_int_224_33VTable != NULL
        && pSimarray_int_224_33VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_int_224_33VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, array_int_224_to_string, 33, sizeof(array_int_224), pfnStrAppend, pData);
}

int string_to_array_int_224_33(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray_int_224_33VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray_int_224_33VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_array_int_224_Utils, 33, sizeof(array_int_224), endptr);
    }
    return nRet;
}

int is_array_int_224_33_double_convertion_allowed()
{
    if (pSimarray_int_224_33VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_int_224_33VTable);
    }
    return 0;
}

void compare_array_int_224_33(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray_int_224_33VTable != NULL
        && pSimarray_int_224_33VTable->m_version >= Scv612
        && pSimarray_int_224_33VTable->m_pfnCompare != NULL) {
        if (pSimarray_int_224_33VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray_int_224_33VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray_int_224_33VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_array_int_224, 33, sizeof(array_int_224), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array_int_224_33_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_int_224_33VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_int_224_33VTable, nRetValue);
    }
    return 0;
}

int get_array_int_224_33_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 33; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_array_int_224_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array_int_224_33_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 33; i++)
        set_array_int_224_default_value(&((array_int_224*)pValue)[i]);
    return 1;
}

int check_array_int_224_33_string(const char *str, char **endptr)
{
    static array_int_224_33 rTemp;
    return string_to_array_int_224_33(str, &rTemp, endptr);
}

SimTypeUtils _Type_array_int_224_33_Utils = {
    array_int_224_33_to_string,
    check_array_int_224_33_string,
    string_to_array_int_224_33,
    is_array_int_224_33_double_convertion_allowed,
    array_int_224_33_to_double,
    compare_array_int_224_33,
    get_array_int_224_33_signature,
    set_array_int_224_33_default_value,
    sizeof(array_int_224_33)
};

/****************************************************************
 ** array__5717 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5717VTable;

int array__5717_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5717VTable != NULL
        && pSimarray__5717VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5717VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, struct__5581_to_string, 4, sizeof(struct__5581), pfnStrAppend, pData);
}

int string_to_array__5717(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5717VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5717VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_struct__5581_Utils, 4, sizeof(struct__5581), endptr);
    }
    return nRet;
}

int is_array__5717_double_convertion_allowed()
{
    if (pSimarray__5717VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5717VTable);
    }
    return 0;
}

void compare_array__5717(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5717VTable != NULL
        && pSimarray__5717VTable->m_version >= Scv612
        && pSimarray__5717VTable->m_pfnCompare != NULL) {
        if (pSimarray__5717VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5717VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5717VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_struct__5581, 4, sizeof(struct__5581), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5717_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5717VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5717VTable, nRetValue);
    }
    return 0;
}

int get_array__5717_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 4; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_struct__5581_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5717_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 4; i++)
        set_struct__5581_default_value(&((struct__5581*)pValue)[i]);
    return 1;
}

int check_array__5717_string(const char *str, char **endptr)
{
    static array__5717 rTemp;
    return string_to_array__5717(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5717_Utils = {
    array__5717_to_string,
    check_array__5717_string,
    string_to_array__5717,
    is_array__5717_double_convertion_allowed,
    array__5717_to_double,
    compare_array__5717,
    get_array__5717_signature,
    set_array__5717_default_value,
    sizeof(array__5717)
};

/****************************************************************
 ** array__5720 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5720VTable;

int array__5720_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5720VTable != NULL
        && pSimarray__5720VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5720VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, Q_DIR_to_string, 4, sizeof(Q_DIR), pfnStrAppend, pData);
}

int string_to_array__5720(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5720VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5720VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_Q_DIR_Utils, 4, sizeof(Q_DIR), endptr);
    }
    return nRet;
}

int is_array__5720_double_convertion_allowed()
{
    if (pSimarray__5720VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5720VTable);
    }
    return 0;
}

void compare_array__5720(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5720VTable != NULL
        && pSimarray__5720VTable->m_version >= Scv612
        && pSimarray__5720VTable->m_pfnCompare != NULL) {
        if (pSimarray__5720VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5720VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5720VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_Q_DIR, 4, sizeof(Q_DIR), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5720_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5720VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5720VTable, nRetValue);
    }
    return 0;
}

int get_array__5720_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 4; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_Q_DIR_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5720_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 4; i++)
        set_Q_DIR_default_value(&((Q_DIR*)pValue)[i]);
    return 1;
}

int check_array__5720_string(const char *str, char **endptr)
{
    static array__5720 rTemp;
    return string_to_array__5720(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5720_Utils = {
    array__5720_to_string,
    check_array__5720_string,
    string_to_array__5720,
    is_array__5720_double_convertion_allowed,
    array__5720_to_double,
    compare_array__5720,
    get_array__5720_signature,
    set_array__5720_default_value,
    sizeof(array__5720)
};

/****************************************************************
 ** array__5723 
 ****************************************************************/

struct SimTypeVTable *pSimarray__5723VTable;

int array__5723_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimarray__5723VTable != NULL
        && pSimarray__5723VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray__5723VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, Q_SCALE_to_string, 4, sizeof(Q_SCALE), pfnStrAppend, pData);
}

int string_to_array__5723(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimarray__5723VTable != NULL) {
        nRet=string_to_VTable(str, pSimarray__5723VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_Q_SCALE_Utils, 4, sizeof(Q_SCALE), endptr);
    }
    return nRet;
}

int is_array__5723_double_convertion_allowed()
{
    if (pSimarray__5723VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray__5723VTable);
    }
    return 0;
}

void compare_array__5723(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimarray__5723VTable != NULL
        && pSimarray__5723VTable->m_version >= Scv612
        && pSimarray__5723VTable->m_pfnCompare != NULL) {
        if (pSimarray__5723VTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimarray__5723VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimarray__5723VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_Q_SCALE, 4, sizeof(Q_SCALE), pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int array__5723_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray__5723VTable != NULL) {
        return VTable_to_double(pValue, pSimarray__5723VTable, nRetValue);
    }
    return 0;
}

int get_array__5723_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 4; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_Q_SCALE_signature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

int set_array__5723_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 4; i++)
        set_Q_SCALE_default_value(&((Q_SCALE*)pValue)[i]);
    return 1;
}

int check_array__5723_string(const char *str, char **endptr)
{
    static array__5723 rTemp;
    return string_to_array__5723(str, &rTemp, endptr);
}

SimTypeUtils _Type_array__5723_Utils = {
    array__5723_to_string,
    check_array__5723_string,
    string_to_array__5723,
    is_array__5723_double_convertion_allowed,
    array__5723_to_double,
    compare_array__5723,
    get_array__5723_signature,
    set_array__5723_default_value,
    sizeof(array__5723)
};

/****************************************************************
 ** NID_PACKET 
 ****************************************************************/

struct SimTypeVTable *pSimNID_PACKETVTable;

int NID_PACKET_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimNID_PACKETVTable != NULL
        && pSimNID_PACKETVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimNID_PACKETVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_NID_PACKET(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimNID_PACKETVTable != NULL) {
        nRet=string_to_VTable(str, pSimNID_PACKETVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_NID_PACKET_double_convertion_allowed()
{
    if (pSimNID_PACKETVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimNID_PACKETVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_NID_PACKET(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimNID_PACKETVTable != NULL
        && pSimNID_PACKETVTable->m_version >= Scv612
        && pSimNID_PACKETVTable->m_pfnCompare != NULL) {
        if (pSimNID_PACKETVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimNID_PACKETVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimNID_PACKETVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int NID_PACKET_to_double(const void *pValue, double *nRetValue)
{
    if (pSimNID_PACKETVTable != NULL) {
        return VTable_to_double(pValue, pSimNID_PACKETVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_NID_PACKET_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_NID_PACKET_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_NID_PACKET_string(const char *str, char **endptr)
{
    static NID_PACKET rTemp;
    return string_to_NID_PACKET(str, &rTemp, endptr);
}

SimTypeUtils _Type_NID_PACKET_Utils = {
    NID_PACKET_to_string,
    check_NID_PACKET_string,
    string_to_NID_PACKET,
    is_NID_PACKET_double_convertion_allowed,
    NID_PACKET_to_double,
    compare_NID_PACKET,
    get_NID_PACKET_signature,
    set_NID_PACKET_default_value,
    sizeof(NID_PACKET)
};

/****************************************************************
 ** Q_DIR 
 ****************************************************************/

struct SimTypeVTable *pSimQ_DIRVTable;

static SimEnumValUtils Q_DIR_values[] = {
    { "Q_DIR_Reverse", Q_DIR_Reverse},
    { "Q_DIR_Reverse", Q_DIR_Reverse},
    { "Q_DIR_Nominal", Q_DIR_Nominal},
    { "Q_DIR_Nominal", Q_DIR_Nominal},
    { "Q_DIR_Both_directions", Q_DIR_Both_directions},
    { "Q_DIR_Both_directions", Q_DIR_Both_directions},
};

int Q_DIR_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_DIRVTable != NULL
        && pSimQ_DIRVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_DIRVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_DIR*)pValue, Q_DIR_values, 6, pfnStrAppend, pData);
}

int string_to_Q_DIR(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_DIRVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_DIRVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_DIR_values, 6, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_DIR*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_DIR_double_convertion_allowed()
{
    if (pSimQ_DIRVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_DIRVTable);
    }
    return 1;
}

void compare_Q_DIR(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_DIRVTable != NULL
        && pSimQ_DIRVTable->m_version >= Scv612
        && pSimQ_DIRVTable->m_pfnCompare != NULL) {
        if (pSimQ_DIRVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_DIRVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_DIRVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_DIR*)pValue1), (int)(*(Q_DIR*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_DIR_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_DIRVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_DIRVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_DIR*)pValue);
    return 1;
}

int get_Q_DIR_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_DIR_values, 6, pfnStrAppend, pData);
}

int set_Q_DIR_default_value(void *pValue)
{
    *(Q_DIR*)pValue = Q_DIR_Reverse;
    return 1;
}

int check_Q_DIR_string(const char *str, char **endptr)
{
    static Q_DIR rTemp;
    return string_to_Q_DIR(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_DIR_Utils = {
    Q_DIR_to_string,
    check_Q_DIR_string,
    string_to_Q_DIR,
    is_Q_DIR_double_convertion_allowed,
    Q_DIR_to_double,
    compare_Q_DIR,
    get_Q_DIR_signature,
    set_Q_DIR_default_value,
    sizeof(Q_DIR)
};

/****************************************************************
 ** Q_UPDOWN 
 ****************************************************************/

struct SimTypeVTable *pSimQ_UPDOWNVTable;

static SimEnumValUtils Q_UPDOWN_values[] = {
    { "Q_UPDOWN_Down_link_telegram", Q_UPDOWN_Down_link_telegram},
    { "Q_UPDOWN_Down_link_telegram", Q_UPDOWN_Down_link_telegram},
    { "Q_UPDOWN_Up_link_telegram", Q_UPDOWN_Up_link_telegram},
    { "Q_UPDOWN_Up_link_telegram", Q_UPDOWN_Up_link_telegram},
};

int Q_UPDOWN_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_UPDOWNVTable != NULL
        && pSimQ_UPDOWNVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_UPDOWNVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_UPDOWN*)pValue, Q_UPDOWN_values, 4, pfnStrAppend, pData);
}

int string_to_Q_UPDOWN(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_UPDOWNVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_UPDOWNVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_UPDOWN_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_UPDOWN*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_UPDOWN_double_convertion_allowed()
{
    if (pSimQ_UPDOWNVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_UPDOWNVTable);
    }
    return 1;
}

void compare_Q_UPDOWN(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_UPDOWNVTable != NULL
        && pSimQ_UPDOWNVTable->m_version >= Scv612
        && pSimQ_UPDOWNVTable->m_pfnCompare != NULL) {
        if (pSimQ_UPDOWNVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_UPDOWNVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_UPDOWNVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_UPDOWN*)pValue1), (int)(*(Q_UPDOWN*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_UPDOWN_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_UPDOWNVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_UPDOWNVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_UPDOWN*)pValue);
    return 1;
}

int get_Q_UPDOWN_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_UPDOWN_values, 4, pfnStrAppend, pData);
}

int set_Q_UPDOWN_default_value(void *pValue)
{
    *(Q_UPDOWN*)pValue = Q_UPDOWN_Down_link_telegram;
    return 1;
}

int check_Q_UPDOWN_string(const char *str, char **endptr)
{
    static Q_UPDOWN rTemp;
    return string_to_Q_UPDOWN(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_UPDOWN_Utils = {
    Q_UPDOWN_to_string,
    check_Q_UPDOWN_string,
    string_to_Q_UPDOWN,
    is_Q_UPDOWN_double_convertion_allowed,
    Q_UPDOWN_to_double,
    compare_Q_UPDOWN,
    get_Q_UPDOWN_signature,
    set_Q_UPDOWN_default_value,
    sizeof(Q_UPDOWN)
};

/****************************************************************
 ** M_VERSION 
 ****************************************************************/

struct SimTypeVTable *pSimM_VERSIONVTable;

static SimEnumValUtils M_VERSION_values[] = {
    { "M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS", M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS},
    { "M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS", M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS},
    { "M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0", M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0},
    { "M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0", M_VERSION_Version_1_0_introduced_in_SRS_1_2_0_and_reused_in_SRSs_2_0_0_and_2_2_2_and_2_3_0},
    { "M_VERSION_Version_1_1_introduced_in_SRS_3_3_0", M_VERSION_Version_1_1_introduced_in_SRS_3_3_0},
    { "M_VERSION_Version_1_1_introduced_in_SRS_3_3_0", M_VERSION_Version_1_1_introduced_in_SRS_3_3_0},
    { "M_VERSION_Version_2_0_introduced_in_SRS_3_3_0", M_VERSION_Version_2_0_introduced_in_SRS_3_3_0},
    { "M_VERSION_Version_2_0_introduced_in_SRS_3_3_0", M_VERSION_Version_2_0_introduced_in_SRS_3_3_0},
};

int M_VERSION_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimM_VERSIONVTable != NULL
        && pSimM_VERSIONVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimM_VERSIONVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(M_VERSION*)pValue, M_VERSION_values, 8, pfnStrAppend, pData);
}

int string_to_M_VERSION(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimM_VERSIONVTable != NULL) {
        nRet=string_to_VTable(str, pSimM_VERSIONVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, M_VERSION_values, 8, endptr);
        if (pValue != NULL && nRet != 0)
            *(M_VERSION*)pValue = nTemp;
    }
    return nRet;
}

int is_M_VERSION_double_convertion_allowed()
{
    if (pSimM_VERSIONVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimM_VERSIONVTable);
    }
    return 1;
}

void compare_M_VERSION(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimM_VERSIONVTable != NULL
        && pSimM_VERSIONVTable->m_version >= Scv612
        && pSimM_VERSIONVTable->m_pfnCompare != NULL) {
        if (pSimM_VERSIONVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimM_VERSIONVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimM_VERSIONVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(M_VERSION*)pValue1), (int)(*(M_VERSION*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int M_VERSION_to_double(const void *pValue, double *nRetValue)
{
    if (pSimM_VERSIONVTable != NULL) {
        return VTable_to_double(pValue, pSimM_VERSIONVTable, nRetValue);
    }
    *nRetValue = (double)*((M_VERSION*)pValue);
    return 1;
}

int get_M_VERSION_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(M_VERSION_values, 8, pfnStrAppend, pData);
}

int set_M_VERSION_default_value(void *pValue)
{
    *(M_VERSION*)pValue = M_VERSION_Previous_versions_according_to_e_g_EEIG_SRS_and_UIC_A200_SRS;
    return 1;
}

int check_M_VERSION_string(const char *str, char **endptr)
{
    static M_VERSION rTemp;
    return string_to_M_VERSION(str, &rTemp, endptr);
}

SimTypeUtils _Type_M_VERSION_Utils = {
    M_VERSION_to_string,
    check_M_VERSION_string,
    string_to_M_VERSION,
    is_M_VERSION_double_convertion_allowed,
    M_VERSION_to_double,
    compare_M_VERSION,
    get_M_VERSION_signature,
    set_M_VERSION_default_value,
    sizeof(M_VERSION)
};

/****************************************************************
 ** Q_MEDIA 
 ****************************************************************/

struct SimTypeVTable *pSimQ_MEDIAVTable;

static SimEnumValUtils Q_MEDIA_values[] = {
    { "Q_MEDIA_Balise", Q_MEDIA_Balise},
    { "Q_MEDIA_Balise", Q_MEDIA_Balise},
    { "Q_MEDIA_Loop", Q_MEDIA_Loop},
    { "Q_MEDIA_Loop", Q_MEDIA_Loop},
};

int Q_MEDIA_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_MEDIAVTable != NULL
        && pSimQ_MEDIAVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_MEDIAVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_MEDIA*)pValue, Q_MEDIA_values, 4, pfnStrAppend, pData);
}

int string_to_Q_MEDIA(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_MEDIAVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_MEDIAVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_MEDIA_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_MEDIA*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_MEDIA_double_convertion_allowed()
{
    if (pSimQ_MEDIAVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_MEDIAVTable);
    }
    return 1;
}

void compare_Q_MEDIA(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_MEDIAVTable != NULL
        && pSimQ_MEDIAVTable->m_version >= Scv612
        && pSimQ_MEDIAVTable->m_pfnCompare != NULL) {
        if (pSimQ_MEDIAVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_MEDIAVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_MEDIAVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_MEDIA*)pValue1), (int)(*(Q_MEDIA*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_MEDIA_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_MEDIAVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_MEDIAVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_MEDIA*)pValue);
    return 1;
}

int get_Q_MEDIA_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_MEDIA_values, 4, pfnStrAppend, pData);
}

int set_Q_MEDIA_default_value(void *pValue)
{
    *(Q_MEDIA*)pValue = Q_MEDIA_Balise;
    return 1;
}

int check_Q_MEDIA_string(const char *str, char **endptr)
{
    static Q_MEDIA rTemp;
    return string_to_Q_MEDIA(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_MEDIA_Utils = {
    Q_MEDIA_to_string,
    check_Q_MEDIA_string,
    string_to_Q_MEDIA,
    is_Q_MEDIA_double_convertion_allowed,
    Q_MEDIA_to_double,
    compare_Q_MEDIA,
    get_Q_MEDIA_signature,
    set_Q_MEDIA_default_value,
    sizeof(Q_MEDIA)
};

/****************************************************************
 ** N_PIG 
 ****************************************************************/

struct SimTypeVTable *pSimN_PIGVTable;

static SimEnumValUtils N_PIG_values[] = {
    { "N_PIG_I_am_the_1st", N_PIG_I_am_the_1st},
    { "N_PIG_I_am_the_1st", N_PIG_I_am_the_1st},
    { "N_PIG_I_am_the_2nd", N_PIG_I_am_the_2nd},
    { "N_PIG_I_am_the_2nd", N_PIG_I_am_the_2nd},
    { "N_PIG_I_am_the_3rd", N_PIG_I_am_the_3rd},
    { "N_PIG_I_am_the_3rd", N_PIG_I_am_the_3rd},
    { "N_PIG_I_am_the_4th", N_PIG_I_am_the_4th},
    { "N_PIG_I_am_the_4th", N_PIG_I_am_the_4th},
    { "N_PIG_I_am_the_5th", N_PIG_I_am_the_5th},
    { "N_PIG_I_am_the_5th", N_PIG_I_am_the_5th},
    { "N_PIG_I_am_the_6th", N_PIG_I_am_the_6th},
    { "N_PIG_I_am_the_6th", N_PIG_I_am_the_6th},
    { "N_PIG_I_am_the_7th", N_PIG_I_am_the_7th},
    { "N_PIG_I_am_the_7th", N_PIG_I_am_the_7th},
    { "N_PIG_I_am_the_8th", N_PIG_I_am_the_8th},
    { "N_PIG_I_am_the_8th", N_PIG_I_am_the_8th},
};

int N_PIG_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimN_PIGVTable != NULL
        && pSimN_PIGVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimN_PIGVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(N_PIG*)pValue, N_PIG_values, 16, pfnStrAppend, pData);
}

int string_to_N_PIG(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimN_PIGVTable != NULL) {
        nRet=string_to_VTable(str, pSimN_PIGVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, N_PIG_values, 16, endptr);
        if (pValue != NULL && nRet != 0)
            *(N_PIG*)pValue = nTemp;
    }
    return nRet;
}

int is_N_PIG_double_convertion_allowed()
{
    if (pSimN_PIGVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimN_PIGVTable);
    }
    return 1;
}

void compare_N_PIG(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimN_PIGVTable != NULL
        && pSimN_PIGVTable->m_version >= Scv612
        && pSimN_PIGVTable->m_pfnCompare != NULL) {
        if (pSimN_PIGVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimN_PIGVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimN_PIGVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(N_PIG*)pValue1), (int)(*(N_PIG*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int N_PIG_to_double(const void *pValue, double *nRetValue)
{
    if (pSimN_PIGVTable != NULL) {
        return VTable_to_double(pValue, pSimN_PIGVTable, nRetValue);
    }
    *nRetValue = (double)*((N_PIG*)pValue);
    return 1;
}

int get_N_PIG_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(N_PIG_values, 16, pfnStrAppend, pData);
}

int set_N_PIG_default_value(void *pValue)
{
    *(N_PIG*)pValue = N_PIG_I_am_the_1st;
    return 1;
}

int check_N_PIG_string(const char *str, char **endptr)
{
    static N_PIG rTemp;
    return string_to_N_PIG(str, &rTemp, endptr);
}

SimTypeUtils _Type_N_PIG_Utils = {
    N_PIG_to_string,
    check_N_PIG_string,
    string_to_N_PIG,
    is_N_PIG_double_convertion_allowed,
    N_PIG_to_double,
    compare_N_PIG,
    get_N_PIG_signature,
    set_N_PIG_default_value,
    sizeof(N_PIG)
};

/****************************************************************
 ** N_TOTAL 
 ****************************************************************/

struct SimTypeVTable *pSimN_TOTALVTable;

static SimEnumValUtils N_TOTAL_values[] = {
    { "N_TOTAL_1_balise_in_the_group", N_TOTAL_1_balise_in_the_group},
    { "N_TOTAL_1_balise_in_the_group", N_TOTAL_1_balise_in_the_group},
    { "N_TOTAL_2_balises_in_the_group", N_TOTAL_2_balises_in_the_group},
    { "N_TOTAL_2_balises_in_the_group", N_TOTAL_2_balises_in_the_group},
    { "N_TOTAL_3_balises_in_the_group", N_TOTAL_3_balises_in_the_group},
    { "N_TOTAL_3_balises_in_the_group", N_TOTAL_3_balises_in_the_group},
    { "N_TOTAL_4_balises_in_the_group", N_TOTAL_4_balises_in_the_group},
    { "N_TOTAL_4_balises_in_the_group", N_TOTAL_4_balises_in_the_group},
    { "N_TOTAL_5_balises_in_the_group", N_TOTAL_5_balises_in_the_group},
    { "N_TOTAL_5_balises_in_the_group", N_TOTAL_5_balises_in_the_group},
    { "N_TOTAL_6_balises_in_the_group", N_TOTAL_6_balises_in_the_group},
    { "N_TOTAL_6_balises_in_the_group", N_TOTAL_6_balises_in_the_group},
    { "N_TOTAL_7_balises_in_the_group", N_TOTAL_7_balises_in_the_group},
    { "N_TOTAL_7_balises_in_the_group", N_TOTAL_7_balises_in_the_group},
    { "N_TOTAL_8_balises_in_the_group", N_TOTAL_8_balises_in_the_group},
    { "N_TOTAL_8_balises_in_the_group", N_TOTAL_8_balises_in_the_group},
};

int N_TOTAL_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimN_TOTALVTable != NULL
        && pSimN_TOTALVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimN_TOTALVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(N_TOTAL*)pValue, N_TOTAL_values, 16, pfnStrAppend, pData);
}

int string_to_N_TOTAL(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimN_TOTALVTable != NULL) {
        nRet=string_to_VTable(str, pSimN_TOTALVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, N_TOTAL_values, 16, endptr);
        if (pValue != NULL && nRet != 0)
            *(N_TOTAL*)pValue = nTemp;
    }
    return nRet;
}

int is_N_TOTAL_double_convertion_allowed()
{
    if (pSimN_TOTALVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimN_TOTALVTable);
    }
    return 1;
}

void compare_N_TOTAL(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimN_TOTALVTable != NULL
        && pSimN_TOTALVTable->m_version >= Scv612
        && pSimN_TOTALVTable->m_pfnCompare != NULL) {
        if (pSimN_TOTALVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimN_TOTALVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimN_TOTALVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(N_TOTAL*)pValue1), (int)(*(N_TOTAL*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int N_TOTAL_to_double(const void *pValue, double *nRetValue)
{
    if (pSimN_TOTALVTable != NULL) {
        return VTable_to_double(pValue, pSimN_TOTALVTable, nRetValue);
    }
    *nRetValue = (double)*((N_TOTAL*)pValue);
    return 1;
}

int get_N_TOTAL_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(N_TOTAL_values, 16, pfnStrAppend, pData);
}

int set_N_TOTAL_default_value(void *pValue)
{
    *(N_TOTAL*)pValue = N_TOTAL_1_balise_in_the_group;
    return 1;
}

int check_N_TOTAL_string(const char *str, char **endptr)
{
    static N_TOTAL rTemp;
    return string_to_N_TOTAL(str, &rTemp, endptr);
}

SimTypeUtils _Type_N_TOTAL_Utils = {
    N_TOTAL_to_string,
    check_N_TOTAL_string,
    string_to_N_TOTAL,
    is_N_TOTAL_double_convertion_allowed,
    N_TOTAL_to_double,
    compare_N_TOTAL,
    get_N_TOTAL_signature,
    set_N_TOTAL_default_value,
    sizeof(N_TOTAL)
};

/****************************************************************
 ** M_DUP 
 ****************************************************************/

struct SimTypeVTable *pSimM_DUPVTable;

static SimEnumValUtils M_DUP_values[] = {
    { "M_DUP_No_duplicates", M_DUP_No_duplicates},
    { "M_DUP_No_duplicates", M_DUP_No_duplicates},
    { "M_DUP_This_balise_is_a_duplicate_of_the_next_balise", _2_M_DUP_This_balise_is_a_duplicate_of_the_next_balise},
    { "M_DUP_This_balise_is_a_duplicate_of_the_next_balise", _2_M_DUP_This_balise_is_a_duplicate_of_the_next_balise},
    { "M_DUP_This_balise_is_a_duplicate_of_the_previous_balise", M_DUP_This_balise_is_a_duplicate_of_the_previous_balise},
    { "M_DUP_This_balise_is_a_duplicate_of_the_previous_balise", M_DUP_This_balise_is_a_duplicate_of_the_previous_balise},
};

int M_DUP_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimM_DUPVTable != NULL
        && pSimM_DUPVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimM_DUPVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(M_DUP*)pValue, M_DUP_values, 6, pfnStrAppend, pData);
}

int string_to_M_DUP(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimM_DUPVTable != NULL) {
        nRet=string_to_VTable(str, pSimM_DUPVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, M_DUP_values, 6, endptr);
        if (pValue != NULL && nRet != 0)
            *(M_DUP*)pValue = nTemp;
    }
    return nRet;
}

int is_M_DUP_double_convertion_allowed()
{
    if (pSimM_DUPVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimM_DUPVTable);
    }
    return 1;
}

void compare_M_DUP(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimM_DUPVTable != NULL
        && pSimM_DUPVTable->m_version >= Scv612
        && pSimM_DUPVTable->m_pfnCompare != NULL) {
        if (pSimM_DUPVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimM_DUPVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimM_DUPVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(M_DUP*)pValue1), (int)(*(M_DUP*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int M_DUP_to_double(const void *pValue, double *nRetValue)
{
    if (pSimM_DUPVTable != NULL) {
        return VTable_to_double(pValue, pSimM_DUPVTable, nRetValue);
    }
    *nRetValue = (double)*((M_DUP*)pValue);
    return 1;
}

int get_M_DUP_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(M_DUP_values, 6, pfnStrAppend, pData);
}

int set_M_DUP_default_value(void *pValue)
{
    *(M_DUP*)pValue = M_DUP_No_duplicates;
    return 1;
}

int check_M_DUP_string(const char *str, char **endptr)
{
    static M_DUP rTemp;
    return string_to_M_DUP(str, &rTemp, endptr);
}

SimTypeUtils _Type_M_DUP_Utils = {
    M_DUP_to_string,
    check_M_DUP_string,
    string_to_M_DUP,
    is_M_DUP_double_convertion_allowed,
    M_DUP_to_double,
    compare_M_DUP,
    get_M_DUP_signature,
    set_M_DUP_default_value,
    sizeof(M_DUP)
};

/****************************************************************
 ** M_MCOUNT 
 ****************************************************************/

struct SimTypeVTable *pSimM_MCOUNTVTable;

int M_MCOUNT_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimM_MCOUNTVTable != NULL
        && pSimM_MCOUNTVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimM_MCOUNTVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_M_MCOUNT(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimM_MCOUNTVTable != NULL) {
        nRet=string_to_VTable(str, pSimM_MCOUNTVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_M_MCOUNT_double_convertion_allowed()
{
    if (pSimM_MCOUNTVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimM_MCOUNTVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_M_MCOUNT(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimM_MCOUNTVTable != NULL
        && pSimM_MCOUNTVTable->m_version >= Scv612
        && pSimM_MCOUNTVTable->m_pfnCompare != NULL) {
        if (pSimM_MCOUNTVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimM_MCOUNTVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimM_MCOUNTVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int M_MCOUNT_to_double(const void *pValue, double *nRetValue)
{
    if (pSimM_MCOUNTVTable != NULL) {
        return VTable_to_double(pValue, pSimM_MCOUNTVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_M_MCOUNT_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_M_MCOUNT_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_M_MCOUNT_string(const char *str, char **endptr)
{
    static M_MCOUNT rTemp;
    return string_to_M_MCOUNT(str, &rTemp, endptr);
}

SimTypeUtils _Type_M_MCOUNT_Utils = {
    M_MCOUNT_to_string,
    check_M_MCOUNT_string,
    string_to_M_MCOUNT,
    is_M_MCOUNT_double_convertion_allowed,
    M_MCOUNT_to_double,
    compare_M_MCOUNT,
    get_M_MCOUNT_signature,
    set_M_MCOUNT_default_value,
    sizeof(M_MCOUNT)
};

/****************************************************************
 ** NID_C 
 ****************************************************************/

struct SimTypeVTable *pSimNID_CVTable;

int NID_C_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimNID_CVTable != NULL
        && pSimNID_CVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimNID_CVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_NID_C(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimNID_CVTable != NULL) {
        nRet=string_to_VTable(str, pSimNID_CVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_NID_C_double_convertion_allowed()
{
    if (pSimNID_CVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimNID_CVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_NID_C(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimNID_CVTable != NULL
        && pSimNID_CVTable->m_version >= Scv612
        && pSimNID_CVTable->m_pfnCompare != NULL) {
        if (pSimNID_CVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimNID_CVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimNID_CVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int NID_C_to_double(const void *pValue, double *nRetValue)
{
    if (pSimNID_CVTable != NULL) {
        return VTable_to_double(pValue, pSimNID_CVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_NID_C_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_NID_C_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_NID_C_string(const char *str, char **endptr)
{
    static NID_C rTemp;
    return string_to_NID_C(str, &rTemp, endptr);
}

SimTypeUtils _Type_NID_C_Utils = {
    NID_C_to_string,
    check_NID_C_string,
    string_to_NID_C,
    is_NID_C_double_convertion_allowed,
    NID_C_to_double,
    compare_NID_C,
    get_NID_C_signature,
    set_NID_C_default_value,
    sizeof(NID_C)
};

/****************************************************************
 ** NID_BG 
 ****************************************************************/

struct SimTypeVTable *pSimNID_BGVTable;

int NID_BG_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimNID_BGVTable != NULL
        && pSimNID_BGVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimNID_BGVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_NID_BG(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimNID_BGVTable != NULL) {
        nRet=string_to_VTable(str, pSimNID_BGVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_NID_BG_double_convertion_allowed()
{
    if (pSimNID_BGVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimNID_BGVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_NID_BG(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimNID_BGVTable != NULL
        && pSimNID_BGVTable->m_version >= Scv612
        && pSimNID_BGVTable->m_pfnCompare != NULL) {
        if (pSimNID_BGVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimNID_BGVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimNID_BGVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int NID_BG_to_double(const void *pValue, double *nRetValue)
{
    if (pSimNID_BGVTable != NULL) {
        return VTable_to_double(pValue, pSimNID_BGVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_NID_BG_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_NID_BG_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_NID_BG_string(const char *str, char **endptr)
{
    static NID_BG rTemp;
    return string_to_NID_BG(str, &rTemp, endptr);
}

SimTypeUtils _Type_NID_BG_Utils = {
    NID_BG_to_string,
    check_NID_BG_string,
    string_to_NID_BG,
    is_NID_BG_double_convertion_allowed,
    NID_BG_to_double,
    compare_NID_BG,
    get_NID_BG_signature,
    set_NID_BG_default_value,
    sizeof(NID_BG)
};

/****************************************************************
 ** Q_LINK 
 ****************************************************************/

struct SimTypeVTable *pSimQ_LINKVTable;

static SimEnumValUtils Q_LINK_values[] = {
    { "Q_LINK_Unlinked", Q_LINK_Unlinked},
    { "Q_LINK_Unlinked", Q_LINK_Unlinked},
    { "Q_LINK_Linked", Q_LINK_Linked},
    { "Q_LINK_Linked", Q_LINK_Linked},
};

int Q_LINK_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_LINKVTable != NULL
        && pSimQ_LINKVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_LINKVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_LINK*)pValue, Q_LINK_values, 4, pfnStrAppend, pData);
}

int string_to_Q_LINK(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_LINKVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_LINKVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_LINK_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_LINK*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_LINK_double_convertion_allowed()
{
    if (pSimQ_LINKVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_LINKVTable);
    }
    return 1;
}

void compare_Q_LINK(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_LINKVTable != NULL
        && pSimQ_LINKVTable->m_version >= Scv612
        && pSimQ_LINKVTable->m_pfnCompare != NULL) {
        if (pSimQ_LINKVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_LINKVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_LINKVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_LINK*)pValue1), (int)(*(Q_LINK*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_LINK_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_LINKVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_LINKVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_LINK*)pValue);
    return 1;
}

int get_Q_LINK_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_LINK_values, 4, pfnStrAppend, pData);
}

int set_Q_LINK_default_value(void *pValue)
{
    *(Q_LINK*)pValue = Q_LINK_Unlinked;
    return 1;
}

int check_Q_LINK_string(const char *str, char **endptr)
{
    static Q_LINK rTemp;
    return string_to_Q_LINK(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_LINK_Utils = {
    Q_LINK_to_string,
    check_Q_LINK_string,
    string_to_Q_LINK,
    is_Q_LINK_double_convertion_allowed,
    Q_LINK_to_double,
    compare_Q_LINK,
    get_Q_LINK_signature,
    set_Q_LINK_default_value,
    sizeof(Q_LINK)
};

/****************************************************************
 ** Q_SCALE 
 ****************************************************************/

struct SimTypeVTable *pSimQ_SCALEVTable;

static SimEnumValUtils Q_SCALE_values[] = {
    { "Q_SCALE_10_cm_scale", Q_SCALE_10_cm_scale},
    { "Q_SCALE_10_cm_scale", Q_SCALE_10_cm_scale},
    { "Q_SCALE_1_m_scale", Q_SCALE_1_m_scale},
    { "Q_SCALE_1_m_scale", Q_SCALE_1_m_scale},
    { "Q_SCALE_10_m_scale", Q_SCALE_10_m_scale},
    { "Q_SCALE_10_m_scale", Q_SCALE_10_m_scale},
};

int Q_SCALE_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_SCALEVTable != NULL
        && pSimQ_SCALEVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_SCALEVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_SCALE*)pValue, Q_SCALE_values, 6, pfnStrAppend, pData);
}

int string_to_Q_SCALE(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_SCALEVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_SCALEVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_SCALE_values, 6, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_SCALE*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_SCALE_double_convertion_allowed()
{
    if (pSimQ_SCALEVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_SCALEVTable);
    }
    return 1;
}

void compare_Q_SCALE(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_SCALEVTable != NULL
        && pSimQ_SCALEVTable->m_version >= Scv612
        && pSimQ_SCALEVTable->m_pfnCompare != NULL) {
        if (pSimQ_SCALEVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_SCALEVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_SCALEVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_SCALE*)pValue1), (int)(*(Q_SCALE*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_SCALE_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_SCALEVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_SCALEVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_SCALE*)pValue);
    return 1;
}

int get_Q_SCALE_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_SCALE_values, 6, pfnStrAppend, pData);
}

int set_Q_SCALE_default_value(void *pValue)
{
    *(Q_SCALE*)pValue = Q_SCALE_10_cm_scale;
    return 1;
}

int check_Q_SCALE_string(const char *str, char **endptr)
{
    static Q_SCALE rTemp;
    return string_to_Q_SCALE(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_SCALE_Utils = {
    Q_SCALE_to_string,
    check_Q_SCALE_string,
    string_to_Q_SCALE,
    is_Q_SCALE_double_convertion_allowed,
    Q_SCALE_to_double,
    compare_Q_SCALE,
    get_Q_SCALE_signature,
    set_Q_SCALE_default_value,
    sizeof(Q_SCALE)
};

/****************************************************************
 ** D_LINK 
 ****************************************************************/

struct SimTypeVTable *pSimD_LINKVTable;

int D_LINK_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimD_LINKVTable != NULL
        && pSimD_LINKVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimD_LINKVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_D_LINK(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimD_LINKVTable != NULL) {
        nRet=string_to_VTable(str, pSimD_LINKVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_D_LINK_double_convertion_allowed()
{
    if (pSimD_LINKVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimD_LINKVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_D_LINK(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimD_LINKVTable != NULL
        && pSimD_LINKVTable->m_version >= Scv612
        && pSimD_LINKVTable->m_pfnCompare != NULL) {
        if (pSimD_LINKVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimD_LINKVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimD_LINKVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int D_LINK_to_double(const void *pValue, double *nRetValue)
{
    if (pSimD_LINKVTable != NULL) {
        return VTable_to_double(pValue, pSimD_LINKVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_D_LINK_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_D_LINK_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_D_LINK_string(const char *str, char **endptr)
{
    static D_LINK rTemp;
    return string_to_D_LINK(str, &rTemp, endptr);
}

SimTypeUtils _Type_D_LINK_Utils = {
    D_LINK_to_string,
    check_D_LINK_string,
    string_to_D_LINK,
    is_D_LINK_double_convertion_allowed,
    D_LINK_to_double,
    compare_D_LINK,
    get_D_LINK_signature,
    set_D_LINK_default_value,
    sizeof(D_LINK)
};

/****************************************************************
 ** Q_NEWCOUNTRY 
 ****************************************************************/

struct SimTypeVTable *pSimQ_NEWCOUNTRYVTable;

static SimEnumValUtils Q_NEWCOUNTRY_values[] = {
    { "Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows", Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows},
    { "Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows", Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows},
    { "Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows", Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows},
    { "Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows", Q_NEWCOUNTRY_Not_the_same_country__or__railway_administration_NID_C_follows},
};

int Q_NEWCOUNTRY_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_NEWCOUNTRYVTable != NULL
        && pSimQ_NEWCOUNTRYVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_NEWCOUNTRYVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_NEWCOUNTRY*)pValue, Q_NEWCOUNTRY_values, 4, pfnStrAppend, pData);
}

int string_to_Q_NEWCOUNTRY(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_NEWCOUNTRYVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_NEWCOUNTRYVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_NEWCOUNTRY_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_NEWCOUNTRY*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_NEWCOUNTRY_double_convertion_allowed()
{
    if (pSimQ_NEWCOUNTRYVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_NEWCOUNTRYVTable);
    }
    return 1;
}

void compare_Q_NEWCOUNTRY(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_NEWCOUNTRYVTable != NULL
        && pSimQ_NEWCOUNTRYVTable->m_version >= Scv612
        && pSimQ_NEWCOUNTRYVTable->m_pfnCompare != NULL) {
        if (pSimQ_NEWCOUNTRYVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_NEWCOUNTRYVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_NEWCOUNTRYVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_NEWCOUNTRY*)pValue1), (int)(*(Q_NEWCOUNTRY*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_NEWCOUNTRY_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_NEWCOUNTRYVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_NEWCOUNTRYVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_NEWCOUNTRY*)pValue);
    return 1;
}

int get_Q_NEWCOUNTRY_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_NEWCOUNTRY_values, 4, pfnStrAppend, pData);
}

int set_Q_NEWCOUNTRY_default_value(void *pValue)
{
    *(Q_NEWCOUNTRY*)pValue = Q_NEWCOUNTRY_Same_country__or__railway_administration_no_NID_C_follows;
    return 1;
}

int check_Q_NEWCOUNTRY_string(const char *str, char **endptr)
{
    static Q_NEWCOUNTRY rTemp;
    return string_to_Q_NEWCOUNTRY(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_NEWCOUNTRY_Utils = {
    Q_NEWCOUNTRY_to_string,
    check_Q_NEWCOUNTRY_string,
    string_to_Q_NEWCOUNTRY,
    is_Q_NEWCOUNTRY_double_convertion_allowed,
    Q_NEWCOUNTRY_to_double,
    compare_Q_NEWCOUNTRY,
    get_Q_NEWCOUNTRY_signature,
    set_Q_NEWCOUNTRY_default_value,
    sizeof(Q_NEWCOUNTRY)
};

/****************************************************************
 ** Q_LINKORIENTATION 
 ****************************************************************/

struct SimTypeVTable *pSimQ_LINKORIENTATIONVTable;

static SimEnumValUtils Q_LINKORIENTATION_values[] = {
    { "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction", _1_Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction},
    { "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction", _1_Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction},
    { "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction", Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction},
    { "Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction", Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_nominal_direction},
};

int Q_LINKORIENTATION_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_LINKORIENTATIONVTable != NULL
        && pSimQ_LINKORIENTATIONVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_LINKORIENTATIONVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_LINKORIENTATION*)pValue, Q_LINKORIENTATION_values, 4, pfnStrAppend, pData);
}

int string_to_Q_LINKORIENTATION(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_LINKORIENTATIONVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_LINKORIENTATIONVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_LINKORIENTATION_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_LINKORIENTATION*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_LINKORIENTATION_double_convertion_allowed()
{
    if (pSimQ_LINKORIENTATIONVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_LINKORIENTATIONVTable);
    }
    return 1;
}

void compare_Q_LINKORIENTATION(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_LINKORIENTATIONVTable != NULL
        && pSimQ_LINKORIENTATIONVTable->m_version >= Scv612
        && pSimQ_LINKORIENTATIONVTable->m_pfnCompare != NULL) {
        if (pSimQ_LINKORIENTATIONVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_LINKORIENTATIONVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_LINKORIENTATIONVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_LINKORIENTATION*)pValue1), (int)(*(Q_LINKORIENTATION*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_LINKORIENTATION_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_LINKORIENTATIONVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_LINKORIENTATIONVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_LINKORIENTATION*)pValue);
    return 1;
}

int get_Q_LINKORIENTATION_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_LINKORIENTATION_values, 4, pfnStrAppend, pData);
}

int set_Q_LINKORIENTATION_default_value(void *pValue)
{
    *(Q_LINKORIENTATION*)pValue = _1_Q_LINKORIENTATION_The_balise_group_is_seen_by_the_train_in_reverse_direction;
    return 1;
}

int check_Q_LINKORIENTATION_string(const char *str, char **endptr)
{
    static Q_LINKORIENTATION rTemp;
    return string_to_Q_LINKORIENTATION(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_LINKORIENTATION_Utils = {
    Q_LINKORIENTATION_to_string,
    check_Q_LINKORIENTATION_string,
    string_to_Q_LINKORIENTATION,
    is_Q_LINKORIENTATION_double_convertion_allowed,
    Q_LINKORIENTATION_to_double,
    compare_Q_LINKORIENTATION,
    get_Q_LINKORIENTATION_signature,
    set_Q_LINKORIENTATION_default_value,
    sizeof(Q_LINKORIENTATION)
};

/****************************************************************
 ** Q_LINKREACTION 
 ****************************************************************/

struct SimTypeVTable *pSimQ_LINKREACTIONVTable;

static SimEnumValUtils Q_LINKREACTION_values[] = {
    { "Q_LINKREACTION_Train_trip", Q_LINKREACTION_Train_trip},
    { "Q_LINKREACTION_Train_trip", Q_LINKREACTION_Train_trip},
    { "Q_LINKREACTION_Apply_service_brake", Q_LINKREACTION_Apply_service_brake},
    { "Q_LINKREACTION_Apply_service_brake", Q_LINKREACTION_Apply_service_brake},
    { "Q_LINKREACTION_No_Reaction", Q_LINKREACTION_No_Reaction},
    { "Q_LINKREACTION_No_Reaction", Q_LINKREACTION_No_Reaction},
};

int Q_LINKREACTION_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_LINKREACTIONVTable != NULL
        && pSimQ_LINKREACTIONVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_LINKREACTIONVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(Q_LINKREACTION*)pValue, Q_LINKREACTION_values, 6, pfnStrAppend, pData);
}

int string_to_Q_LINKREACTION(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_LINKREACTIONVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_LINKREACTIONVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, Q_LINKREACTION_values, 6, endptr);
        if (pValue != NULL && nRet != 0)
            *(Q_LINKREACTION*)pValue = nTemp;
    }
    return nRet;
}

int is_Q_LINKREACTION_double_convertion_allowed()
{
    if (pSimQ_LINKREACTIONVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_LINKREACTIONVTable);
    }
    return 1;
}

void compare_Q_LINKREACTION(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_LINKREACTIONVTable != NULL
        && pSimQ_LINKREACTIONVTable->m_version >= Scv612
        && pSimQ_LINKREACTIONVTable->m_pfnCompare != NULL) {
        if (pSimQ_LINKREACTIONVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_LINKREACTIONVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_LINKREACTIONVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(Q_LINKREACTION*)pValue1), (int)(*(Q_LINKREACTION*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_LINKREACTION_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_LINKREACTIONVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_LINKREACTIONVTable, nRetValue);
    }
    *nRetValue = (double)*((Q_LINKREACTION*)pValue);
    return 1;
}

int get_Q_LINKREACTION_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(Q_LINKREACTION_values, 6, pfnStrAppend, pData);
}

int set_Q_LINKREACTION_default_value(void *pValue)
{
    *(Q_LINKREACTION*)pValue = Q_LINKREACTION_Train_trip;
    return 1;
}

int check_Q_LINKREACTION_string(const char *str, char **endptr)
{
    static Q_LINKREACTION rTemp;
    return string_to_Q_LINKREACTION(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_LINKREACTION_Utils = {
    Q_LINKREACTION_to_string,
    check_Q_LINKREACTION_string,
    string_to_Q_LINKREACTION,
    is_Q_LINKREACTION_double_convertion_allowed,
    Q_LINKREACTION_to_double,
    compare_Q_LINKREACTION,
    get_Q_LINKREACTION_signature,
    set_Q_LINKREACTION_default_value,
    sizeof(Q_LINKREACTION)
};

/****************************************************************
 ** Q_LOCACC 
 ****************************************************************/

struct SimTypeVTable *pSimQ_LOCACCVTable;

int Q_LOCACC_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimQ_LOCACCVTable != NULL
        && pSimQ_LOCACCVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimQ_LOCACCVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_Q_LOCACC(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimQ_LOCACCVTable != NULL) {
        nRet=string_to_VTable(str, pSimQ_LOCACCVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_Q_LOCACC_double_convertion_allowed()
{
    if (pSimQ_LOCACCVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimQ_LOCACCVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_Q_LOCACC(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimQ_LOCACCVTable != NULL
        && pSimQ_LOCACCVTable->m_version >= Scv612
        && pSimQ_LOCACCVTable->m_pfnCompare != NULL) {
        if (pSimQ_LOCACCVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimQ_LOCACCVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimQ_LOCACCVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Q_LOCACC_to_double(const void *pValue, double *nRetValue)
{
    if (pSimQ_LOCACCVTable != NULL) {
        return VTable_to_double(pValue, pSimQ_LOCACCVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_Q_LOCACC_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_Q_LOCACC_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_Q_LOCACC_string(const char *str, char **endptr)
{
    static Q_LOCACC rTemp;
    return string_to_Q_LOCACC(str, &rTemp, endptr);
}

SimTypeUtils _Type_Q_LOCACC_Utils = {
    Q_LOCACC_to_string,
    check_Q_LOCACC_string,
    string_to_Q_LOCACC,
    is_Q_LOCACC_double_convertion_allowed,
    Q_LOCACC_to_double,
    compare_Q_LOCACC,
    get_Q_LOCACC_signature,
    set_Q_LOCACC_default_value,
    sizeof(Q_LOCACC)
};

/****************************************************************
 ** N_ITER 
 ****************************************************************/

struct SimTypeVTable *pSimN_ITERVTable;

int N_ITER_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimN_ITERVTable != NULL
        && pSimN_ITERVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimN_ITERVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_N_ITER(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimN_ITERVTable != NULL) {
        nRet=string_to_VTable(str, pSimN_ITERVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_N_ITER_double_convertion_allowed()
{
    if (pSimN_ITERVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimN_ITERVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_N_ITER(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimN_ITERVTable != NULL
        && pSimN_ITERVTable->m_version >= Scv612
        && pSimN_ITERVTable->m_pfnCompare != NULL) {
        if (pSimN_ITERVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimN_ITERVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimN_ITERVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int N_ITER_to_double(const void *pValue, double *nRetValue)
{
    if (pSimN_ITERVTable != NULL) {
        return VTable_to_double(pValue, pSimN_ITERVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_N_ITER_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_N_ITER_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_N_ITER_string(const char *str, char **endptr)
{
    static N_ITER rTemp;
    return string_to_N_ITER(str, &rTemp, endptr);
}

SimTypeUtils _Type_N_ITER_Utils = {
    N_ITER_to_string,
    check_N_ITER_string,
    string_to_N_ITER,
    is_N_ITER_double_convertion_allowed,
    N_ITER_to_double,
    compare_N_ITER,
    get_N_ITER_signature,
    set_N_ITER_default_value,
    sizeof(N_ITER)
};

/****************************************************************
 ** L_PACKET 
 ****************************************************************/

struct SimTypeVTable *pSimL_PACKETVTable;

int L_PACKET_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimL_PACKETVTable != NULL
        && pSimL_PACKETVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimL_PACKETVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_L_PACKET(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimL_PACKETVTable != NULL) {
        nRet=string_to_VTable(str, pSimL_PACKETVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_L_PACKET_double_convertion_allowed()
{
    if (pSimL_PACKETVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimL_PACKETVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_L_PACKET(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimL_PACKETVTable != NULL
        && pSimL_PACKETVTable->m_version >= Scv612
        && pSimL_PACKETVTable->m_pfnCompare != NULL) {
        if (pSimL_PACKETVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimL_PACKETVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimL_PACKETVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int L_PACKET_to_double(const void *pValue, double *nRetValue)
{
    if (pSimL_PACKETVTable != NULL) {
        return VTable_to_double(pValue, pSimL_PACKETVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_L_PACKET_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_L_PACKET_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_L_PACKET_string(const char *str, char **endptr)
{
    static L_PACKET rTemp;
    return string_to_L_PACKET(str, &rTemp, endptr);
}

SimTypeUtils _Type_L_PACKET_Utils = {
    L_PACKET_to_string,
    check_L_PACKET_string,
    string_to_L_PACKET,
    is_L_PACKET_double_convertion_allowed,
    L_PACKET_to_double,
    compare_L_PACKET,
    get_L_PACKET_signature,
    set_L_PACKET_default_value,
    sizeof(L_PACKET)
};

/****************************************************************
 ** NID_LRBG 
 ****************************************************************/

struct SimTypeVTable *pSimNID_LRBGVTable;

int NID_LRBG_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimNID_LRBGVTable != NULL
        && pSimNID_LRBGVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimNID_LRBGVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_NID_LRBG(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimNID_LRBGVTable != NULL) {
        nRet=string_to_VTable(str, pSimNID_LRBGVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_NID_LRBG_double_convertion_allowed()
{
    if (pSimNID_LRBGVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimNID_LRBGVTable);
    }
    return is_kcg_int_double_convertion_allowed();
}

void compare_NID_LRBG(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimNID_LRBGVTable != NULL
        && pSimNID_LRBGVTable->m_version >= Scv612
        && pSimNID_LRBGVTable->m_pfnCompare != NULL) {
        if (pSimNID_LRBGVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimNID_LRBGVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimNID_LRBGVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int NID_LRBG_to_double(const void *pValue, double *nRetValue)
{
    if (pSimNID_LRBGVTable != NULL) {
        return VTable_to_double(pValue, pSimNID_LRBGVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int get_NID_LRBG_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_NID_LRBG_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_NID_LRBG_string(const char *str, char **endptr)
{
    static NID_LRBG rTemp;
    return string_to_NID_LRBG(str, &rTemp, endptr);
}

SimTypeUtils _Type_NID_LRBG_Utils = {
    NID_LRBG_to_string,
    check_NID_LRBG_string,
    string_to_NID_LRBG,
    is_NID_LRBG_double_convertion_allowed,
    NID_LRBG_to_double,
    compare_NID_LRBG,
    get_NID_LRBG_signature,
    set_NID_LRBG_default_value,
    sizeof(NID_LRBG)
};

/****************************************************************
 ** B_data_internal_FirstTest_InfraLibInt 
 ****************************************************************/

struct SimTypeVTable *pSimB_data_internal_FirstTest_InfraLibIntVTable;

int B_data_internal_FirstTest_InfraLibInt_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimB_data_internal_FirstTest_InfraLibIntVTable != NULL
        && pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5636_to_string(pValue, pfnStrAppend, pData);
}

int string_to_B_data_internal_FirstTest_InfraLibInt(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimB_data_internal_FirstTest_InfraLibIntVTable != NULL) {
        nRet=string_to_VTable(str, pSimB_data_internal_FirstTest_InfraLibIntVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5636(str, pValue, endptr);
    }
    return nRet;
}

int is_B_data_internal_FirstTest_InfraLibInt_double_convertion_allowed()
{
    if (pSimB_data_internal_FirstTest_InfraLibIntVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimB_data_internal_FirstTest_InfraLibIntVTable);
    }
    return is_struct__5636_double_convertion_allowed();
}

void compare_B_data_internal_FirstTest_InfraLibInt(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimB_data_internal_FirstTest_InfraLibIntVTable != NULL
        && pSimB_data_internal_FirstTest_InfraLibIntVTable->m_version >= Scv612
        && pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnCompare != NULL) {
        if (pSimB_data_internal_FirstTest_InfraLibIntVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimB_data_internal_FirstTest_InfraLibIntVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5636(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int B_data_internal_FirstTest_InfraLibInt_to_double(const void *pValue, double *nRetValue)
{
    if (pSimB_data_internal_FirstTest_InfraLibIntVTable != NULL) {
        return VTable_to_double(pValue, pSimB_data_internal_FirstTest_InfraLibIntVTable, nRetValue);
    }
    return struct__5636_to_double(pValue, nRetValue);
}

int get_B_data_internal_FirstTest_InfraLibInt_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5636_signature(pfnStrAppend, pData);
}

int set_B_data_internal_FirstTest_InfraLibInt_default_value(void *pValue)
{
    return set_struct__5636_default_value(pValue);
}

int check_B_data_internal_FirstTest_InfraLibInt_string(const char *str, char **endptr)
{
    static B_data_internal_FirstTest_InfraLibInt rTemp;
    return string_to_B_data_internal_FirstTest_InfraLibInt(str, &rTemp, endptr);
}

SimTypeUtils _Type_B_data_internal_FirstTest_InfraLibInt_Utils = {
    B_data_internal_FirstTest_InfraLibInt_to_string,
    check_B_data_internal_FirstTest_InfraLibInt_string,
    string_to_B_data_internal_FirstTest_InfraLibInt,
    is_B_data_internal_FirstTest_InfraLibInt_double_convertion_allowed,
    B_data_internal_FirstTest_InfraLibInt_to_double,
    compare_B_data_internal_FirstTest_InfraLibInt,
    get_B_data_internal_FirstTest_InfraLibInt_signature,
    set_B_data_internal_FirstTest_InfraLibInt_default_value,
    sizeof(B_data_internal_FirstTest_InfraLibInt)
};

/****************************************************************
 ** CompressedBaliseMessage_TM 
 ****************************************************************/

struct SimTypeVTable *pSimCompressedBaliseMessage_TMVTable;

int CompressedBaliseMessage_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimCompressedBaliseMessage_TMVTable != NULL
        && pSimCompressedBaliseMessage_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimCompressedBaliseMessage_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5623_to_string(pValue, pfnStrAppend, pData);
}

int string_to_CompressedBaliseMessage_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimCompressedBaliseMessage_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimCompressedBaliseMessage_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5623(str, pValue, endptr);
    }
    return nRet;
}

int is_CompressedBaliseMessage_TM_double_convertion_allowed()
{
    if (pSimCompressedBaliseMessage_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimCompressedBaliseMessage_TMVTable);
    }
    return is_struct__5623_double_convertion_allowed();
}

void compare_CompressedBaliseMessage_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimCompressedBaliseMessage_TMVTable != NULL
        && pSimCompressedBaliseMessage_TMVTable->m_version >= Scv612
        && pSimCompressedBaliseMessage_TMVTable->m_pfnCompare != NULL) {
        if (pSimCompressedBaliseMessage_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimCompressedBaliseMessage_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimCompressedBaliseMessage_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5623(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int CompressedBaliseMessage_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimCompressedBaliseMessage_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimCompressedBaliseMessage_TMVTable, nRetValue);
    }
    return struct__5623_to_double(pValue, nRetValue);
}

int get_CompressedBaliseMessage_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5623_signature(pfnStrAppend, pData);
}

int set_CompressedBaliseMessage_TM_default_value(void *pValue)
{
    return set_struct__5623_default_value(pValue);
}

int check_CompressedBaliseMessage_TM_string(const char *str, char **endptr)
{
    static CompressedBaliseMessage_TM rTemp;
    return string_to_CompressedBaliseMessage_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_CompressedBaliseMessage_TM_Utils = {
    CompressedBaliseMessage_TM_to_string,
    check_CompressedBaliseMessage_TM_string,
    string_to_CompressedBaliseMessage_TM,
    is_CompressedBaliseMessage_TM_double_convertion_allowed,
    CompressedBaliseMessage_TM_to_double,
    compare_CompressedBaliseMessage_TM,
    get_CompressedBaliseMessage_TM_signature,
    set_CompressedBaliseMessage_TM_default_value,
    sizeof(CompressedBaliseMessage_TM)
};

/****************************************************************
 ** BaliseTelegramHeader_int_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimBaliseTelegramHeader_int_T_TMVTable;

int BaliseTelegramHeader_int_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimBaliseTelegramHeader_int_T_TMVTable != NULL
        && pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5610_to_string(pValue, pfnStrAppend, pData);
}

int string_to_BaliseTelegramHeader_int_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimBaliseTelegramHeader_int_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimBaliseTelegramHeader_int_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5610(str, pValue, endptr);
    }
    return nRet;
}

int is_BaliseTelegramHeader_int_T_TM_double_convertion_allowed()
{
    if (pSimBaliseTelegramHeader_int_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimBaliseTelegramHeader_int_T_TMVTable);
    }
    return is_struct__5610_double_convertion_allowed();
}

void compare_BaliseTelegramHeader_int_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimBaliseTelegramHeader_int_T_TMVTable != NULL
        && pSimBaliseTelegramHeader_int_T_TMVTable->m_version >= Scv612
        && pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimBaliseTelegramHeader_int_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimBaliseTelegramHeader_int_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5610(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int BaliseTelegramHeader_int_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBaliseTelegramHeader_int_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimBaliseTelegramHeader_int_T_TMVTable, nRetValue);
    }
    return struct__5610_to_double(pValue, nRetValue);
}

int get_BaliseTelegramHeader_int_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5610_signature(pfnStrAppend, pData);
}

int set_BaliseTelegramHeader_int_T_TM_default_value(void *pValue)
{
    return set_struct__5610_default_value(pValue);
}

int check_BaliseTelegramHeader_int_T_TM_string(const char *str, char **endptr)
{
    static BaliseTelegramHeader_int_T_TM rTemp;
    return string_to_BaliseTelegramHeader_int_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_BaliseTelegramHeader_int_T_TM_Utils = {
    BaliseTelegramHeader_int_T_TM_to_string,
    check_BaliseTelegramHeader_int_T_TM_string,
    string_to_BaliseTelegramHeader_int_T_TM,
    is_BaliseTelegramHeader_int_T_TM_double_convertion_allowed,
    BaliseTelegramHeader_int_T_TM_to_double,
    compare_BaliseTelegramHeader_int_T_TM,
    get_BaliseTelegramHeader_int_T_TM_signature,
    set_BaliseTelegramHeader_int_T_TM_default_value,
    sizeof(BaliseTelegramHeader_int_T_TM)
};

/****************************************************************
 ** OrBG_TM 
 ****************************************************************/

struct SimTypeVTable *pSimOrBG_TMVTable;

static SimEnumValUtils OrBG_TM_values[] = {
    { "TM::Amsterdam", Amsterdam_TM},
    { "Amsterdam", Amsterdam_TM},
    { "TM::Utrecht", Utrecht_TM},
    { "Utrecht", Utrecht_TM},
};

int OrBG_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimOrBG_TMVTable != NULL
        && pSimOrBG_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimOrBG_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(OrBG_TM*)pValue, OrBG_TM_values, 4, pfnStrAppend, pData);
}

int string_to_OrBG_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimOrBG_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimOrBG_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, OrBG_TM_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(OrBG_TM*)pValue = nTemp;
    }
    return nRet;
}

int is_OrBG_TM_double_convertion_allowed()
{
    if (pSimOrBG_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimOrBG_TMVTable);
    }
    return 1;
}

void compare_OrBG_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimOrBG_TMVTable != NULL
        && pSimOrBG_TMVTable->m_version >= Scv612
        && pSimOrBG_TMVTable->m_pfnCompare != NULL) {
        if (pSimOrBG_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimOrBG_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimOrBG_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(OrBG_TM*)pValue1), (int)(*(OrBG_TM*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int OrBG_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimOrBG_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimOrBG_TMVTable, nRetValue);
    }
    *nRetValue = (double)*((OrBG_TM*)pValue);
    return 1;
}

int get_OrBG_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(OrBG_TM_values, 4, pfnStrAppend, pData);
}

int set_OrBG_TM_default_value(void *pValue)
{
    *(OrBG_TM*)pValue = Amsterdam_TM;
    return 1;
}

int check_OrBG_TM_string(const char *str, char **endptr)
{
    static OrBG_TM rTemp;
    return string_to_OrBG_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_OrBG_TM_Utils = {
    OrBG_TM_to_string,
    check_OrBG_TM_string,
    string_to_OrBG_TM,
    is_OrBG_TM_double_convertion_allowed,
    OrBG_TM_to_double,
    compare_OrBG_TM,
    get_OrBG_TM_signature,
    set_OrBG_TM_default_value,
    sizeof(OrBG_TM)
};

/****************************************************************
 ** OrLine_TM 
 ****************************************************************/

struct SimTypeVTable *pSimOrLine_TMVTable;

static SimEnumValUtils OrLine_TM_values[] = {
    { "TM::N", N_TM},
    { "N", N_TM},
    { "TM::Z", Z_TM},
    { "Z", Z_TM},
};

int OrLine_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimOrLine_TMVTable != NULL
        && pSimOrLine_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimOrLine_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(OrLine_TM*)pValue, OrLine_TM_values, 4, pfnStrAppend, pData);
}

int string_to_OrLine_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimOrLine_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimOrLine_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        int nTemp = 0;
        nRet = pConverter->m_pfnStringToEnum(str, &nTemp, OrLine_TM_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(OrLine_TM*)pValue = nTemp;
    }
    return nRet;
}

int is_OrLine_TM_double_convertion_allowed()
{
    if (pSimOrLine_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimOrLine_TMVTable);
    }
    return 1;
}

void compare_OrLine_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimOrLine_TMVTable != NULL
        && pSimOrLine_TMVTable->m_version >= Scv612
        && pSimOrLine_TMVTable->m_pfnCompare != NULL) {
        if (pSimOrLine_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimOrLine_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimOrLine_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_enum(pResult, (int)(*(OrLine_TM*)pValue1), (int)(*(OrLine_TM*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int OrLine_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimOrLine_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimOrLine_TMVTable, nRetValue);
    }
    *nRetValue = (double)*((OrLine_TM*)pValue);
    return 1;
}

int get_OrLine_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_enum_signature(OrLine_TM_values, 4, pfnStrAppend, pData);
}

int set_OrLine_TM_default_value(void *pValue)
{
    *(OrLine_TM*)pValue = N_TM;
    return 1;
}

int check_OrLine_TM_string(const char *str, char **endptr)
{
    static OrLine_TM rTemp;
    return string_to_OrLine_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_OrLine_TM_Utils = {
    OrLine_TM_to_string,
    check_OrLine_TM_string,
    string_to_OrLine_TM,
    is_OrLine_TM_double_convertion_allowed,
    OrLine_TM_to_double,
    compare_OrLine_TM,
    get_OrLine_TM_signature,
    set_OrLine_TM_default_value,
    sizeof(OrLine_TM)
};

/****************************************************************
 ** P005_trackside_int_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_trackside_int_T_TMVTable;

int P005_trackside_int_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_trackside_int_T_TMVTable != NULL
        && pSimP005_trackside_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_trackside_int_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5658_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_trackside_int_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_trackside_int_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_trackside_int_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5658(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_trackside_int_T_TM_double_convertion_allowed()
{
    if (pSimP005_trackside_int_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_trackside_int_T_TMVTable);
    }
    return is_struct__5658_double_convertion_allowed();
}

void compare_P005_trackside_int_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_trackside_int_T_TMVTable != NULL
        && pSimP005_trackside_int_T_TMVTable->m_version >= Scv612
        && pSimP005_trackside_int_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_trackside_int_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_trackside_int_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_trackside_int_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5658(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_trackside_int_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_trackside_int_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_trackside_int_T_TMVTable, nRetValue);
    }
    return struct__5658_to_double(pValue, nRetValue);
}

int get_P005_trackside_int_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5658_signature(pfnStrAppend, pData);
}

int set_P005_trackside_int_T_TM_default_value(void *pValue)
{
    return set_struct__5658_default_value(pValue);
}

int check_P005_trackside_int_T_TM_string(const char *str, char **endptr)
{
    static P005_trackside_int_T_TM rTemp;
    return string_to_P005_trackside_int_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_trackside_int_T_TM_Utils = {
    P005_trackside_int_T_TM_to_string,
    check_P005_trackside_int_T_TM_string,
    string_to_P005_trackside_int_T_TM,
    is_P005_trackside_int_T_TM_double_convertion_allowed,
    P005_trackside_int_T_TM_to_double,
    compare_P005_trackside_int_T_TM,
    get_P005_trackside_int_T_TM_signature,
    set_P005_trackside_int_T_TM_default_value,
    sizeof(P005_trackside_int_T_TM)
};

/****************************************************************
 ** P005_trackide_sectionlist_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_trackide_sectionlist_T_TMVTable;

int P005_trackide_sectionlist_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_trackide_sectionlist_T_TMVTable != NULL
        && pSimP005_trackide_sectionlist_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_trackide_sectionlist_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array__5655_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_trackide_sectionlist_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_trackide_sectionlist_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_trackide_sectionlist_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array__5655(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_trackide_sectionlist_T_TM_double_convertion_allowed()
{
    if (pSimP005_trackide_sectionlist_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_trackide_sectionlist_T_TMVTable);
    }
    return is_array__5655_double_convertion_allowed();
}

void compare_P005_trackide_sectionlist_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_trackide_sectionlist_T_TMVTable != NULL
        && pSimP005_trackide_sectionlist_T_TMVTable->m_version >= Scv612
        && pSimP005_trackide_sectionlist_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_trackide_sectionlist_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_trackide_sectionlist_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_trackide_sectionlist_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array__5655(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_trackide_sectionlist_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_trackide_sectionlist_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_trackide_sectionlist_T_TMVTable, nRetValue);
    }
    return array__5655_to_double(pValue, nRetValue);
}

int get_P005_trackide_sectionlist_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array__5655_signature(pfnStrAppend, pData);
}

int set_P005_trackide_sectionlist_T_TM_default_value(void *pValue)
{
    return set_array__5655_default_value(pValue);
}

int check_P005_trackide_sectionlist_T_TM_string(const char *str, char **endptr)
{
    static P005_trackide_sectionlist_T_TM rTemp;
    return string_to_P005_trackide_sectionlist_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_trackide_sectionlist_T_TM_Utils = {
    P005_trackide_sectionlist_T_TM_to_string,
    check_P005_trackide_sectionlist_T_TM_string,
    string_to_P005_trackide_sectionlist_T_TM,
    is_P005_trackide_sectionlist_T_TM_double_convertion_allowed,
    P005_trackide_sectionlist_T_TM_to_double,
    compare_P005_trackide_sectionlist_T_TM,
    get_P005_trackide_sectionlist_T_TM_signature,
    set_P005_trackide_sectionlist_T_TM_default_value,
    sizeof(P005_trackide_sectionlist_T_TM)
};

/****************************************************************
 ** P005_section_int_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_section_int_T_TMVTable;

int P005_section_int_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_section_int_T_TMVTable != NULL
        && pSimP005_section_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_section_int_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5645_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_section_int_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_section_int_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_section_int_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5645(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_section_int_T_TM_double_convertion_allowed()
{
    if (pSimP005_section_int_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_section_int_T_TMVTable);
    }
    return is_struct__5645_double_convertion_allowed();
}

void compare_P005_section_int_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_section_int_T_TMVTable != NULL
        && pSimP005_section_int_T_TMVTable->m_version >= Scv612
        && pSimP005_section_int_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_section_int_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_section_int_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_section_int_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5645(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_section_int_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_section_int_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_section_int_T_TMVTable, nRetValue);
    }
    return struct__5645_to_double(pValue, nRetValue);
}

int get_P005_section_int_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5645_signature(pfnStrAppend, pData);
}

int set_P005_section_int_T_TM_default_value(void *pValue)
{
    return set_struct__5645_default_value(pValue);
}

int check_P005_section_int_T_TM_string(const char *str, char **endptr)
{
    static P005_section_int_T_TM rTemp;
    return string_to_P005_section_int_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_section_int_T_TM_Utils = {
    P005_section_int_T_TM_to_string,
    check_P005_section_int_T_TM_string,
    string_to_P005_section_int_T_TM,
    is_P005_section_int_T_TM_double_convertion_allowed,
    P005_section_int_T_TM_to_double,
    compare_P005_section_int_T_TM,
    get_P005_section_int_T_TM_signature,
    set_P005_section_int_T_TM_default_value,
    sizeof(P005_section_int_T_TM)
};

/****************************************************************
 ** P005_sections_array_flat_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_sections_array_flat_T_TMVTable;

int P005_sections_array_flat_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_sections_array_flat_T_TMVTable != NULL
        && pSimP005_sections_array_flat_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_sections_array_flat_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_int_224_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_sections_array_flat_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_sections_array_flat_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_sections_array_flat_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array_int_224(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_sections_array_flat_T_TM_double_convertion_allowed()
{
    if (pSimP005_sections_array_flat_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_sections_array_flat_T_TMVTable);
    }
    return is_array_int_224_double_convertion_allowed();
}

void compare_P005_sections_array_flat_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_sections_array_flat_T_TMVTable != NULL
        && pSimP005_sections_array_flat_T_TMVTable->m_version >= Scv612
        && pSimP005_sections_array_flat_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_sections_array_flat_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_sections_array_flat_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_sections_array_flat_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array_int_224(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_sections_array_flat_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_sections_array_flat_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_sections_array_flat_T_TMVTable, nRetValue);
    }
    return array_int_224_to_double(pValue, nRetValue);
}

int get_P005_sections_array_flat_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array_int_224_signature(pfnStrAppend, pData);
}

int set_P005_sections_array_flat_T_TM_default_value(void *pValue)
{
    return set_array_int_224_default_value(pValue);
}

int check_P005_sections_array_flat_T_TM_string(const char *str, char **endptr)
{
    static P005_sections_array_flat_T_TM rTemp;
    return string_to_P005_sections_array_flat_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_sections_array_flat_T_TM_Utils = {
    P005_sections_array_flat_T_TM_to_string,
    check_P005_sections_array_flat_T_TM_string,
    string_to_P005_sections_array_flat_T_TM,
    is_P005_sections_array_flat_T_TM_double_convertion_allowed,
    P005_sections_array_flat_T_TM_to_double,
    compare_P005_sections_array_flat_T_TM,
    get_P005_sections_array_flat_T_TM_signature,
    set_P005_sections_array_flat_T_TM_default_value,
    sizeof(P005_sections_array_flat_T_TM)
};

/****************************************************************
 ** P005_OBU_sectionlist_array_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_OBU_sectionlist_array_T_TMVTable;

int P005_OBU_sectionlist_array_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_OBU_sectionlist_array_T_TMVTable != NULL
        && pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_int_7_33_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_OBU_sectionlist_array_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_OBU_sectionlist_array_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_OBU_sectionlist_array_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array_int_7_33(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_OBU_sectionlist_array_T_TM_double_convertion_allowed()
{
    if (pSimP005_OBU_sectionlist_array_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_OBU_sectionlist_array_T_TMVTable);
    }
    return is_array_int_7_33_double_convertion_allowed();
}

void compare_P005_OBU_sectionlist_array_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_OBU_sectionlist_array_T_TMVTable != NULL
        && pSimP005_OBU_sectionlist_array_T_TMVTable->m_version >= Scv612
        && pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_OBU_sectionlist_array_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_OBU_sectionlist_array_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array_int_7_33(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_OBU_sectionlist_array_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_OBU_sectionlist_array_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_OBU_sectionlist_array_T_TMVTable, nRetValue);
    }
    return array_int_7_33_to_double(pValue, nRetValue);
}

int get_P005_OBU_sectionlist_array_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array_int_7_33_signature(pfnStrAppend, pData);
}

int set_P005_OBU_sectionlist_array_T_TM_default_value(void *pValue)
{
    return set_array_int_7_33_default_value(pValue);
}

int check_P005_OBU_sectionlist_array_T_TM_string(const char *str, char **endptr)
{
    static P005_OBU_sectionlist_array_T_TM rTemp;
    return string_to_P005_OBU_sectionlist_array_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_OBU_sectionlist_array_T_TM_Utils = {
    P005_OBU_sectionlist_array_T_TM_to_string,
    check_P005_OBU_sectionlist_array_T_TM_string,
    string_to_P005_OBU_sectionlist_array_T_TM,
    is_P005_OBU_sectionlist_array_T_TM_double_convertion_allowed,
    P005_OBU_sectionlist_array_T_TM_to_double,
    compare_P005_OBU_sectionlist_array_T_TM,
    get_P005_OBU_sectionlist_array_T_TM_signature,
    set_P005_OBU_sectionlist_array_T_TM_default_value,
    sizeof(P005_OBU_sectionlist_array_T_TM)
};

/****************************************************************
 ** P005_section_array_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_section_array_T_TMVTable;

int P005_section_array_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_section_array_T_TMVTable != NULL
        && pSimP005_section_array_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_section_array_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_int_7_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_section_array_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_section_array_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_section_array_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array_int_7(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_section_array_T_TM_double_convertion_allowed()
{
    if (pSimP005_section_array_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_section_array_T_TMVTable);
    }
    return is_array_int_7_double_convertion_allowed();
}

void compare_P005_section_array_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_section_array_T_TMVTable != NULL
        && pSimP005_section_array_T_TMVTable->m_version >= Scv612
        && pSimP005_section_array_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_section_array_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_section_array_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_section_array_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array_int_7(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_section_array_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_section_array_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_section_array_T_TMVTable, nRetValue);
    }
    return array_int_7_to_double(pValue, nRetValue);
}

int get_P005_section_array_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array_int_7_signature(pfnStrAppend, pData);
}

int set_P005_section_array_T_TM_default_value(void *pValue)
{
    return set_array_int_7_default_value(pValue);
}

int check_P005_section_array_T_TM_string(const char *str, char **endptr)
{
    static P005_section_array_T_TM rTemp;
    return string_to_P005_section_array_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_section_array_T_TM_Utils = {
    P005_section_array_T_TM_to_string,
    check_P005_section_array_T_TM_string,
    string_to_P005_section_array_T_TM,
    is_P005_section_array_T_TM_double_convertion_allowed,
    P005_section_array_T_TM_to_double,
    compare_P005_section_array_T_TM,
    get_P005_section_array_T_TM_signature,
    set_P005_section_array_T_TM_default_value,
    sizeof(P005_section_array_T_TM)
};

/****************************************************************
 ** P005_OBU_sectionlist_int_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_OBU_sectionlist_int_T_TMVTable;

int P005_OBU_sectionlist_int_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_OBU_sectionlist_int_T_TMVTable != NULL
        && pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array__5681_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_OBU_sectionlist_int_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_OBU_sectionlist_int_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_OBU_sectionlist_int_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array__5681(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_OBU_sectionlist_int_T_TM_double_convertion_allowed()
{
    if (pSimP005_OBU_sectionlist_int_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_OBU_sectionlist_int_T_TMVTable);
    }
    return is_array__5681_double_convertion_allowed();
}

void compare_P005_OBU_sectionlist_int_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_OBU_sectionlist_int_T_TMVTable != NULL
        && pSimP005_OBU_sectionlist_int_T_TMVTable->m_version >= Scv612
        && pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_OBU_sectionlist_int_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_OBU_sectionlist_int_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array__5681(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_OBU_sectionlist_int_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_OBU_sectionlist_int_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_OBU_sectionlist_int_T_TMVTable, nRetValue);
    }
    return array__5681_to_double(pValue, nRetValue);
}

int get_P005_OBU_sectionlist_int_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array__5681_signature(pfnStrAppend, pData);
}

int set_P005_OBU_sectionlist_int_T_TM_default_value(void *pValue)
{
    return set_array__5681_default_value(pValue);
}

int check_P005_OBU_sectionlist_int_T_TM_string(const char *str, char **endptr)
{
    static P005_OBU_sectionlist_int_T_TM rTemp;
    return string_to_P005_OBU_sectionlist_int_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_OBU_sectionlist_int_T_TM_Utils = {
    P005_OBU_sectionlist_int_T_TM_to_string,
    check_P005_OBU_sectionlist_int_T_TM_string,
    string_to_P005_OBU_sectionlist_int_T_TM,
    is_P005_OBU_sectionlist_int_T_TM_double_convertion_allowed,
    P005_OBU_sectionlist_int_T_TM_to_double,
    compare_P005_OBU_sectionlist_int_T_TM,
    get_P005_OBU_sectionlist_int_T_TM_signature,
    set_P005_OBU_sectionlist_int_T_TM_default_value,
    sizeof(P005_OBU_sectionlist_int_T_TM)
};

/****************************************************************
 ** BaliseGroupData_TM 
 ****************************************************************/

struct SimTypeVTable *pSimBaliseGroupData_TMVTable;

int BaliseGroupData_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimBaliseGroupData_TMVTable != NULL
        && pSimBaliseGroupData_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimBaliseGroupData_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5628_to_string(pValue, pfnStrAppend, pData);
}

int string_to_BaliseGroupData_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimBaliseGroupData_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimBaliseGroupData_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5628(str, pValue, endptr);
    }
    return nRet;
}

int is_BaliseGroupData_TM_double_convertion_allowed()
{
    if (pSimBaliseGroupData_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimBaliseGroupData_TMVTable);
    }
    return is_struct__5628_double_convertion_allowed();
}

void compare_BaliseGroupData_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimBaliseGroupData_TMVTable != NULL
        && pSimBaliseGroupData_TMVTable->m_version >= Scv612
        && pSimBaliseGroupData_TMVTable->m_pfnCompare != NULL) {
        if (pSimBaliseGroupData_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimBaliseGroupData_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimBaliseGroupData_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5628(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int BaliseGroupData_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBaliseGroupData_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimBaliseGroupData_TMVTable, nRetValue);
    }
    return struct__5628_to_double(pValue, nRetValue);
}

int get_BaliseGroupData_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5628_signature(pfnStrAppend, pData);
}

int set_BaliseGroupData_TM_default_value(void *pValue)
{
    return set_struct__5628_default_value(pValue);
}

int check_BaliseGroupData_TM_string(const char *str, char **endptr)
{
    static BaliseGroupData_TM rTemp;
    return string_to_BaliseGroupData_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_BaliseGroupData_TM_Utils = {
    BaliseGroupData_TM_to_string,
    check_BaliseGroupData_TM_string,
    string_to_BaliseGroupData_TM,
    is_BaliseGroupData_TM_double_convertion_allowed,
    BaliseGroupData_TM_to_double,
    compare_BaliseGroupData_TM,
    get_BaliseGroupData_TM_signature,
    set_BaliseGroupData_TM_default_value,
    sizeof(BaliseGroupData_TM)
};

/****************************************************************
 ** P005_section_enum_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_section_enum_T_TMVTable;

int P005_section_enum_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_section_enum_T_TMVTable != NULL
        && pSimP005_section_enum_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_section_enum_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5581_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_section_enum_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_section_enum_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_section_enum_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5581(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_section_enum_T_TM_double_convertion_allowed()
{
    if (pSimP005_section_enum_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_section_enum_T_TMVTable);
    }
    return is_struct__5581_double_convertion_allowed();
}

void compare_P005_section_enum_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_section_enum_T_TMVTable != NULL
        && pSimP005_section_enum_T_TMVTable->m_version >= Scv612
        && pSimP005_section_enum_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_section_enum_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_section_enum_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_section_enum_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5581(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_section_enum_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_section_enum_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_section_enum_T_TMVTable, nRetValue);
    }
    return struct__5581_to_double(pValue, nRetValue);
}

int get_P005_section_enum_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5581_signature(pfnStrAppend, pData);
}

int set_P005_section_enum_T_TM_default_value(void *pValue)
{
    return set_struct__5581_default_value(pValue);
}

int check_P005_section_enum_T_TM_string(const char *str, char **endptr)
{
    static P005_section_enum_T_TM rTemp;
    return string_to_P005_section_enum_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_section_enum_T_TM_Utils = {
    P005_section_enum_T_TM_to_string,
    check_P005_section_enum_T_TM_string,
    string_to_P005_section_enum_T_TM,
    is_P005_section_enum_T_TM_double_convertion_allowed,
    P005_section_enum_T_TM_to_double,
    compare_P005_section_enum_T_TM,
    get_P005_section_enum_T_TM_signature,
    set_P005_section_enum_T_TM_default_value,
    sizeof(P005_section_enum_T_TM)
};

/****************************************************************
 ** P005_OBU_sectionlist_enum_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_OBU_sectionlist_enum_T_TMVTable;

int P005_OBU_sectionlist_enum_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_OBU_sectionlist_enum_T_TMVTable != NULL
        && pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array__5592_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_OBU_sectionlist_enum_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_OBU_sectionlist_enum_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_OBU_sectionlist_enum_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array__5592(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_OBU_sectionlist_enum_T_TM_double_convertion_allowed()
{
    if (pSimP005_OBU_sectionlist_enum_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_OBU_sectionlist_enum_T_TMVTable);
    }
    return is_array__5592_double_convertion_allowed();
}

void compare_P005_OBU_sectionlist_enum_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_OBU_sectionlist_enum_T_TMVTable != NULL
        && pSimP005_OBU_sectionlist_enum_T_TMVTable->m_version >= Scv612
        && pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_OBU_sectionlist_enum_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_OBU_sectionlist_enum_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array__5592(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_OBU_sectionlist_enum_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_OBU_sectionlist_enum_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_OBU_sectionlist_enum_T_TMVTable, nRetValue);
    }
    return array__5592_to_double(pValue, nRetValue);
}

int get_P005_OBU_sectionlist_enum_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array__5592_signature(pfnStrAppend, pData);
}

int set_P005_OBU_sectionlist_enum_T_TM_default_value(void *pValue)
{
    return set_array__5592_default_value(pValue);
}

int check_P005_OBU_sectionlist_enum_T_TM_string(const char *str, char **endptr)
{
    static P005_OBU_sectionlist_enum_T_TM rTemp;
    return string_to_P005_OBU_sectionlist_enum_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_OBU_sectionlist_enum_T_TM_Utils = {
    P005_OBU_sectionlist_enum_T_TM_to_string,
    check_P005_OBU_sectionlist_enum_T_TM_string,
    string_to_P005_OBU_sectionlist_enum_T_TM,
    is_P005_OBU_sectionlist_enum_T_TM_double_convertion_allowed,
    P005_OBU_sectionlist_enum_T_TM_to_double,
    compare_P005_OBU_sectionlist_enum_T_TM,
    get_P005_OBU_sectionlist_enum_T_TM_signature,
    set_P005_OBU_sectionlist_enum_T_TM_default_value,
    sizeof(P005_OBU_sectionlist_enum_T_TM)
};

/****************************************************************
 ** P005_OBU_T_TM 
 ****************************************************************/

struct SimTypeVTable *pSimP005_OBU_T_TMVTable;

int P005_OBU_T_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimP005_OBU_T_TMVTable != NULL
        && pSimP005_OBU_T_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimP005_OBU_T_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5595_to_string(pValue, pfnStrAppend, pData);
}

int string_to_P005_OBU_T_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimP005_OBU_T_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimP005_OBU_T_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5595(str, pValue, endptr);
    }
    return nRet;
}

int is_P005_OBU_T_TM_double_convertion_allowed()
{
    if (pSimP005_OBU_T_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimP005_OBU_T_TMVTable);
    }
    return is_struct__5595_double_convertion_allowed();
}

void compare_P005_OBU_T_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimP005_OBU_T_TMVTable != NULL
        && pSimP005_OBU_T_TMVTable->m_version >= Scv612
        && pSimP005_OBU_T_TMVTable->m_pfnCompare != NULL) {
        if (pSimP005_OBU_T_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimP005_OBU_T_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimP005_OBU_T_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5595(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int P005_OBU_T_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimP005_OBU_T_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimP005_OBU_T_TMVTable, nRetValue);
    }
    return struct__5595_to_double(pValue, nRetValue);
}

int get_P005_OBU_T_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5595_signature(pfnStrAppend, pData);
}

int set_P005_OBU_T_TM_default_value(void *pValue)
{
    return set_struct__5595_default_value(pValue);
}

int check_P005_OBU_T_TM_string(const char *str, char **endptr)
{
    static P005_OBU_T_TM rTemp;
    return string_to_P005_OBU_T_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_P005_OBU_T_TM_Utils = {
    P005_OBU_T_TM_to_string,
    check_P005_OBU_T_TM_string,
    string_to_P005_OBU_T_TM,
    is_P005_OBU_T_TM_double_convertion_allowed,
    P005_OBU_T_TM_to_double,
    compare_P005_OBU_T_TM,
    get_P005_OBU_T_TM_signature,
    set_P005_OBU_T_TM_default_value,
    sizeof(P005_OBU_T_TM)
};

/****************************************************************
 ** Array03_TM 
 ****************************************************************/

struct SimTypeVTable *pSimArray03_TMVTable;

int Array03_TM_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimArray03_TMVTable != NULL
        && pSimArray03_TMVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimArray03_TMVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_int_3_to_string(pValue, pfnStrAppend, pData);
}

int string_to_Array03_TM(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimArray03_TMVTable != NULL) {
        nRet=string_to_VTable(str, pSimArray03_TMVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array_int_3(str, pValue, endptr);
    }
    return nRet;
}

int is_Array03_TM_double_convertion_allowed()
{
    if (pSimArray03_TMVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimArray03_TMVTable);
    }
    return is_array_int_3_double_convertion_allowed();
}

void compare_Array03_TM(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimArray03_TMVTable != NULL
        && pSimArray03_TMVTable->m_version >= Scv612
        && pSimArray03_TMVTable->m_pfnCompare != NULL) {
        if (pSimArray03_TMVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimArray03_TMVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimArray03_TMVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array_int_3(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Array03_TM_to_double(const void *pValue, double *nRetValue)
{
    if (pSimArray03_TMVTable != NULL) {
        return VTable_to_double(pValue, pSimArray03_TMVTable, nRetValue);
    }
    return array_int_3_to_double(pValue, nRetValue);
}

int get_Array03_TM_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array_int_3_signature(pfnStrAppend, pData);
}

int set_Array03_TM_default_value(void *pValue)
{
    return set_array_int_3_default_value(pValue);
}

int check_Array03_TM_string(const char *str, char **endptr)
{
    static Array03_TM rTemp;
    return string_to_Array03_TM(str, &rTemp, endptr);
}

SimTypeUtils _Type_Array03_TM_Utils = {
    Array03_TM_to_string,
    check_Array03_TM_string,
    string_to_Array03_TM,
    is_Array03_TM_double_convertion_allowed,
    Array03_TM_to_double,
    compare_Array03_TM,
    get_Array03_TM_signature,
    set_Array03_TM_default_value,
    sizeof(Array03_TM)
};

/****************************************************************
 ** CompressedPackets_T_Common_Types_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimCompressedPackets_T_Common_Types_PkgVTable;

int CompressedPackets_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimCompressedPackets_T_Common_Types_PkgVTable != NULL
        && pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5576_to_string(pValue, pfnStrAppend, pData);
}

int string_to_CompressedPackets_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimCompressedPackets_T_Common_Types_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimCompressedPackets_T_Common_Types_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5576(str, pValue, endptr);
    }
    return nRet;
}

int is_CompressedPackets_T_Common_Types_Pkg_double_convertion_allowed()
{
    if (pSimCompressedPackets_T_Common_Types_PkgVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimCompressedPackets_T_Common_Types_PkgVTable);
    }
    return is_struct__5576_double_convertion_allowed();
}

void compare_CompressedPackets_T_Common_Types_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimCompressedPackets_T_Common_Types_PkgVTable != NULL
        && pSimCompressedPackets_T_Common_Types_PkgVTable->m_version >= Scv612
        && pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnCompare != NULL) {
        if (pSimCompressedPackets_T_Common_Types_PkgVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimCompressedPackets_T_Common_Types_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5576(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int CompressedPackets_T_Common_Types_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimCompressedPackets_T_Common_Types_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimCompressedPackets_T_Common_Types_PkgVTable, nRetValue);
    }
    return struct__5576_to_double(pValue, nRetValue);
}

int get_CompressedPackets_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5576_signature(pfnStrAppend, pData);
}

int set_CompressedPackets_T_Common_Types_Pkg_default_value(void *pValue)
{
    return set_struct__5576_default_value(pValue);
}

int check_CompressedPackets_T_Common_Types_Pkg_string(const char *str, char **endptr)
{
    static CompressedPackets_T_Common_Types_Pkg rTemp;
    return string_to_CompressedPackets_T_Common_Types_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_CompressedPackets_T_Common_Types_Pkg_Utils = {
    CompressedPackets_T_Common_Types_Pkg_to_string,
    check_CompressedPackets_T_Common_Types_Pkg_string,
    string_to_CompressedPackets_T_Common_Types_Pkg,
    is_CompressedPackets_T_Common_Types_Pkg_double_convertion_allowed,
    CompressedPackets_T_Common_Types_Pkg_to_double,
    compare_CompressedPackets_T_Common_Types_Pkg,
    get_CompressedPackets_T_Common_Types_Pkg_signature,
    set_CompressedPackets_T_Common_Types_Pkg_default_value,
    sizeof(CompressedPackets_T_Common_Types_Pkg)
};

/****************************************************************
 ** Metadata_T_Common_Types_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimMetadata_T_Common_Types_PkgVTable;

int Metadata_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimMetadata_T_Common_Types_PkgVTable != NULL
        && pSimMetadata_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimMetadata_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array__5573_to_string(pValue, pfnStrAppend, pData);
}

int string_to_Metadata_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimMetadata_T_Common_Types_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimMetadata_T_Common_Types_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array__5573(str, pValue, endptr);
    }
    return nRet;
}

int is_Metadata_T_Common_Types_Pkg_double_convertion_allowed()
{
    if (pSimMetadata_T_Common_Types_PkgVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimMetadata_T_Common_Types_PkgVTable);
    }
    return is_array__5573_double_convertion_allowed();
}

void compare_Metadata_T_Common_Types_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimMetadata_T_Common_Types_PkgVTable != NULL
        && pSimMetadata_T_Common_Types_PkgVTable->m_version >= Scv612
        && pSimMetadata_T_Common_Types_PkgVTable->m_pfnCompare != NULL) {
        if (pSimMetadata_T_Common_Types_PkgVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimMetadata_T_Common_Types_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimMetadata_T_Common_Types_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array__5573(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int Metadata_T_Common_Types_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimMetadata_T_Common_Types_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimMetadata_T_Common_Types_PkgVTable, nRetValue);
    }
    return array__5573_to_double(pValue, nRetValue);
}

int get_Metadata_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array__5573_signature(pfnStrAppend, pData);
}

int set_Metadata_T_Common_Types_Pkg_default_value(void *pValue)
{
    return set_array__5573_default_value(pValue);
}

int check_Metadata_T_Common_Types_Pkg_string(const char *str, char **endptr)
{
    static Metadata_T_Common_Types_Pkg rTemp;
    return string_to_Metadata_T_Common_Types_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_Metadata_T_Common_Types_Pkg_Utils = {
    Metadata_T_Common_Types_Pkg_to_string,
    check_Metadata_T_Common_Types_Pkg_string,
    string_to_Metadata_T_Common_Types_Pkg,
    is_Metadata_T_Common_Types_Pkg_double_convertion_allowed,
    Metadata_T_Common_Types_Pkg_to_double,
    compare_Metadata_T_Common_Types_Pkg,
    get_Metadata_T_Common_Types_Pkg_signature,
    set_Metadata_T_Common_Types_Pkg_default_value,
    sizeof(Metadata_T_Common_Types_Pkg)
};

/****************************************************************
 ** MetadataElement_T_Common_Types_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimMetadataElement_T_Common_Types_PkgVTable;

int MetadataElement_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimMetadataElement_T_Common_Types_PkgVTable != NULL
        && pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5565_to_string(pValue, pfnStrAppend, pData);
}

int string_to_MetadataElement_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimMetadataElement_T_Common_Types_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimMetadataElement_T_Common_Types_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5565(str, pValue, endptr);
    }
    return nRet;
}

int is_MetadataElement_T_Common_Types_Pkg_double_convertion_allowed()
{
    if (pSimMetadataElement_T_Common_Types_PkgVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimMetadataElement_T_Common_Types_PkgVTable);
    }
    return is_struct__5565_double_convertion_allowed();
}

void compare_MetadataElement_T_Common_Types_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimMetadataElement_T_Common_Types_PkgVTable != NULL
        && pSimMetadataElement_T_Common_Types_PkgVTable->m_version >= Scv612
        && pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnCompare != NULL) {
        if (pSimMetadataElement_T_Common_Types_PkgVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimMetadataElement_T_Common_Types_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5565(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int MetadataElement_T_Common_Types_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimMetadataElement_T_Common_Types_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimMetadataElement_T_Common_Types_PkgVTable, nRetValue);
    }
    return struct__5565_to_double(pValue, nRetValue);
}

int get_MetadataElement_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5565_signature(pfnStrAppend, pData);
}

int set_MetadataElement_T_Common_Types_Pkg_default_value(void *pValue)
{
    return set_struct__5565_default_value(pValue);
}

int check_MetadataElement_T_Common_Types_Pkg_string(const char *str, char **endptr)
{
    static MetadataElement_T_Common_Types_Pkg rTemp;
    return string_to_MetadataElement_T_Common_Types_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_MetadataElement_T_Common_Types_Pkg_Utils = {
    MetadataElement_T_Common_Types_Pkg_to_string,
    check_MetadataElement_T_Common_Types_Pkg_string,
    string_to_MetadataElement_T_Common_Types_Pkg,
    is_MetadataElement_T_Common_Types_Pkg_double_convertion_allowed,
    MetadataElement_T_Common_Types_Pkg_to_double,
    compare_MetadataElement_T_Common_Types_Pkg,
    get_MetadataElement_T_Common_Types_Pkg_signature,
    set_MetadataElement_T_Common_Types_Pkg_default_value,
    sizeof(MetadataElement_T_Common_Types_Pkg)
};

/****************************************************************
 ** CompressedPacketData_T_Common_Types_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimCompressedPacketData_T_Common_Types_PkgVTable;

int CompressedPacketData_T_Common_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimCompressedPacketData_T_Common_Types_PkgVTable != NULL
        && pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_int_500_to_string(pValue, pfnStrAppend, pData);
}

int string_to_CompressedPacketData_T_Common_Types_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimCompressedPacketData_T_Common_Types_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimCompressedPacketData_T_Common_Types_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array_int_500(str, pValue, endptr);
    }
    return nRet;
}

int is_CompressedPacketData_T_Common_Types_Pkg_double_convertion_allowed()
{
    if (pSimCompressedPacketData_T_Common_Types_PkgVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimCompressedPacketData_T_Common_Types_PkgVTable);
    }
    return is_array_int_500_double_convertion_allowed();
}

void compare_CompressedPacketData_T_Common_Types_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimCompressedPacketData_T_Common_Types_PkgVTable != NULL
        && pSimCompressedPacketData_T_Common_Types_PkgVTable->m_version >= Scv612
        && pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnCompare != NULL) {
        if (pSimCompressedPacketData_T_Common_Types_PkgVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimCompressedPacketData_T_Common_Types_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array_int_500(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int CompressedPacketData_T_Common_Types_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimCompressedPacketData_T_Common_Types_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimCompressedPacketData_T_Common_Types_PkgVTable, nRetValue);
    }
    return array_int_500_to_double(pValue, nRetValue);
}

int get_CompressedPacketData_T_Common_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array_int_500_signature(pfnStrAppend, pData);
}

int set_CompressedPacketData_T_Common_Types_Pkg_default_value(void *pValue)
{
    return set_array_int_500_default_value(pValue);
}

int check_CompressedPacketData_T_Common_Types_Pkg_string(const char *str, char **endptr)
{
    static CompressedPacketData_T_Common_Types_Pkg rTemp;
    return string_to_CompressedPacketData_T_Common_Types_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_CompressedPacketData_T_Common_Types_Pkg_Utils = {
    CompressedPacketData_T_Common_Types_Pkg_to_string,
    check_CompressedPacketData_T_Common_Types_Pkg_string,
    string_to_CompressedPacketData_T_Common_Types_Pkg,
    is_CompressedPacketData_T_Common_Types_Pkg_double_convertion_allowed,
    CompressedPacketData_T_Common_Types_Pkg_to_double,
    compare_CompressedPacketData_T_Common_Types_Pkg,
    get_CompressedPacketData_T_Common_Types_Pkg_signature,
    set_CompressedPacketData_T_Common_Types_Pkg_default_value,
    sizeof(CompressedPacketData_T_Common_Types_Pkg)
};

/****************************************************************
 ** BaliseGroupData_Basics 
 ****************************************************************/

struct SimTypeVTable *pSimBaliseGroupData_BasicsVTable;

int BaliseGroupData_Basics_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimBaliseGroupData_BasicsVTable != NULL
        && pSimBaliseGroupData_BasicsVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimBaliseGroupData_BasicsVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5628_to_string(pValue, pfnStrAppend, pData);
}

int string_to_BaliseGroupData_Basics(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimBaliseGroupData_BasicsVTable != NULL) {
        nRet=string_to_VTable(str, pSimBaliseGroupData_BasicsVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5628(str, pValue, endptr);
    }
    return nRet;
}

int is_BaliseGroupData_Basics_double_convertion_allowed()
{
    if (pSimBaliseGroupData_BasicsVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimBaliseGroupData_BasicsVTable);
    }
    return is_struct__5628_double_convertion_allowed();
}

void compare_BaliseGroupData_Basics(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimBaliseGroupData_BasicsVTable != NULL
        && pSimBaliseGroupData_BasicsVTable->m_version >= Scv612
        && pSimBaliseGroupData_BasicsVTable->m_pfnCompare != NULL) {
        if (pSimBaliseGroupData_BasicsVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimBaliseGroupData_BasicsVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimBaliseGroupData_BasicsVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5628(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int BaliseGroupData_Basics_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBaliseGroupData_BasicsVTable != NULL) {
        return VTable_to_double(pValue, pSimBaliseGroupData_BasicsVTable, nRetValue);
    }
    return struct__5628_to_double(pValue, nRetValue);
}

int get_BaliseGroupData_Basics_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5628_signature(pfnStrAppend, pData);
}

int set_BaliseGroupData_Basics_default_value(void *pValue)
{
    return set_struct__5628_default_value(pValue);
}

int check_BaliseGroupData_Basics_string(const char *str, char **endptr)
{
    static BaliseGroupData_Basics rTemp;
    return string_to_BaliseGroupData_Basics(str, &rTemp, endptr);
}

SimTypeUtils _Type_BaliseGroupData_Basics_Utils = {
    BaliseGroupData_Basics_to_string,
    check_BaliseGroupData_Basics_string,
    string_to_BaliseGroupData_Basics,
    is_BaliseGroupData_Basics_double_convertion_allowed,
    BaliseGroupData_Basics_to_double,
    compare_BaliseGroupData_Basics,
    get_BaliseGroupData_Basics_signature,
    set_BaliseGroupData_Basics_default_value,
    sizeof(BaliseGroupData_Basics)
};

/****************************************************************
 ** B_data_internal_T_InfraLib 
 ****************************************************************/

struct SimTypeVTable *pSimB_data_internal_T_InfraLibVTable;

int B_data_internal_T_InfraLib_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimB_data_internal_T_InfraLibVTable != NULL
        && pSimB_data_internal_T_InfraLibVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimB_data_internal_T_InfraLibVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5636_to_string(pValue, pfnStrAppend, pData);
}

int string_to_B_data_internal_T_InfraLib(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimB_data_internal_T_InfraLibVTable != NULL) {
        nRet=string_to_VTable(str, pSimB_data_internal_T_InfraLibVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5636(str, pValue, endptr);
    }
    return nRet;
}

int is_B_data_internal_T_InfraLib_double_convertion_allowed()
{
    if (pSimB_data_internal_T_InfraLibVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimB_data_internal_T_InfraLibVTable);
    }
    return is_struct__5636_double_convertion_allowed();
}

void compare_B_data_internal_T_InfraLib(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimB_data_internal_T_InfraLibVTable != NULL
        && pSimB_data_internal_T_InfraLibVTable->m_version >= Scv612
        && pSimB_data_internal_T_InfraLibVTable->m_pfnCompare != NULL) {
        if (pSimB_data_internal_T_InfraLibVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimB_data_internal_T_InfraLibVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimB_data_internal_T_InfraLibVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5636(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int B_data_internal_T_InfraLib_to_double(const void *pValue, double *nRetValue)
{
    if (pSimB_data_internal_T_InfraLibVTable != NULL) {
        return VTable_to_double(pValue, pSimB_data_internal_T_InfraLibVTable, nRetValue);
    }
    return struct__5636_to_double(pValue, nRetValue);
}

int get_B_data_internal_T_InfraLib_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5636_signature(pfnStrAppend, pData);
}

int set_B_data_internal_T_InfraLib_default_value(void *pValue)
{
    return set_struct__5636_default_value(pValue);
}

int check_B_data_internal_T_InfraLib_string(const char *str, char **endptr)
{
    static B_data_internal_T_InfraLib rTemp;
    return string_to_B_data_internal_T_InfraLib(str, &rTemp, endptr);
}

SimTypeUtils _Type_B_data_internal_T_InfraLib_Utils = {
    B_data_internal_T_InfraLib_to_string,
    check_B_data_internal_T_InfraLib_string,
    string_to_B_data_internal_T_InfraLib,
    is_B_data_internal_T_InfraLib_double_convertion_allowed,
    B_data_internal_T_InfraLib_to_double,
    compare_B_data_internal_T_InfraLib,
    get_B_data_internal_T_InfraLib_signature,
    set_B_data_internal_T_InfraLib_default_value,
    sizeof(B_data_internal_T_InfraLib)
};

/****************************************************************
 ** TelegramHeader_T_BG_Types_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimTelegramHeader_T_BG_Types_PkgVTable;

int TelegramHeader_T_BG_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimTelegramHeader_T_BG_Types_PkgVTable != NULL
        && pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5549_to_string(pValue, pfnStrAppend, pData);
}

int string_to_TelegramHeader_T_BG_Types_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimTelegramHeader_T_BG_Types_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimTelegramHeader_T_BG_Types_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5549(str, pValue, endptr);
    }
    return nRet;
}

int is_TelegramHeader_T_BG_Types_Pkg_double_convertion_allowed()
{
    if (pSimTelegramHeader_T_BG_Types_PkgVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimTelegramHeader_T_BG_Types_PkgVTable);
    }
    return is_struct__5549_double_convertion_allowed();
}

void compare_TelegramHeader_T_BG_Types_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimTelegramHeader_T_BG_Types_PkgVTable != NULL
        && pSimTelegramHeader_T_BG_Types_PkgVTable->m_version >= Scv612
        && pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnCompare != NULL) {
        if (pSimTelegramHeader_T_BG_Types_PkgVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimTelegramHeader_T_BG_Types_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5549(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int TelegramHeader_T_BG_Types_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimTelegramHeader_T_BG_Types_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimTelegramHeader_T_BG_Types_PkgVTable, nRetValue);
    }
    return struct__5549_to_double(pValue, nRetValue);
}

int get_TelegramHeader_T_BG_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5549_signature(pfnStrAppend, pData);
}

int set_TelegramHeader_T_BG_Types_Pkg_default_value(void *pValue)
{
    return set_struct__5549_default_value(pValue);
}

int check_TelegramHeader_T_BG_Types_Pkg_string(const char *str, char **endptr)
{
    static TelegramHeader_T_BG_Types_Pkg rTemp;
    return string_to_TelegramHeader_T_BG_Types_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_TelegramHeader_T_BG_Types_Pkg_Utils = {
    TelegramHeader_T_BG_Types_Pkg_to_string,
    check_TelegramHeader_T_BG_Types_Pkg_string,
    string_to_TelegramHeader_T_BG_Types_Pkg,
    is_TelegramHeader_T_BG_Types_Pkg_double_convertion_allowed,
    TelegramHeader_T_BG_Types_Pkg_to_double,
    compare_TelegramHeader_T_BG_Types_Pkg,
    get_TelegramHeader_T_BG_Types_Pkg_signature,
    set_TelegramHeader_T_BG_Types_Pkg_default_value,
    sizeof(TelegramHeader_T_BG_Types_Pkg)
};

/****************************************************************
 ** LinkedBG_T_BG_Types_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimLinkedBG_T_BG_Types_PkgVTable;

int LinkedBG_T_BG_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimLinkedBG_T_BG_Types_PkgVTable != NULL
        && pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__5532_to_string(pValue, pfnStrAppend, pData);
}

int string_to_LinkedBG_T_BG_Types_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimLinkedBG_T_BG_Types_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimLinkedBG_T_BG_Types_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__5532(str, pValue, endptr);
    }
    return nRet;
}

int is_LinkedBG_T_BG_Types_Pkg_double_convertion_allowed()
{
    if (pSimLinkedBG_T_BG_Types_PkgVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimLinkedBG_T_BG_Types_PkgVTable);
    }
    return is_struct__5532_double_convertion_allowed();
}

void compare_LinkedBG_T_BG_Types_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimLinkedBG_T_BG_Types_PkgVTable != NULL
        && pSimLinkedBG_T_BG_Types_PkgVTable->m_version >= Scv612
        && pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnCompare != NULL) {
        if (pSimLinkedBG_T_BG_Types_PkgVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimLinkedBG_T_BG_Types_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__5532(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int LinkedBG_T_BG_Types_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimLinkedBG_T_BG_Types_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimLinkedBG_T_BG_Types_PkgVTable, nRetValue);
    }
    return struct__5532_to_double(pValue, nRetValue);
}

int get_LinkedBG_T_BG_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__5532_signature(pfnStrAppend, pData);
}

int set_LinkedBG_T_BG_Types_Pkg_default_value(void *pValue)
{
    return set_struct__5532_default_value(pValue);
}

int check_LinkedBG_T_BG_Types_Pkg_string(const char *str, char **endptr)
{
    static LinkedBG_T_BG_Types_Pkg rTemp;
    return string_to_LinkedBG_T_BG_Types_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_LinkedBG_T_BG_Types_Pkg_Utils = {
    LinkedBG_T_BG_Types_Pkg_to_string,
    check_LinkedBG_T_BG_Types_Pkg_string,
    string_to_LinkedBG_T_BG_Types_Pkg,
    is_LinkedBG_T_BG_Types_Pkg_double_convertion_allowed,
    LinkedBG_T_BG_Types_Pkg_to_double,
    compare_LinkedBG_T_BG_Types_Pkg,
    get_LinkedBG_T_BG_Types_Pkg_signature,
    set_LinkedBG_T_BG_Types_Pkg_default_value,
    sizeof(LinkedBG_T_BG_Types_Pkg)
};

/****************************************************************
 ** LinkedBGs_T_BG_Types_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimLinkedBGs_T_BG_Types_PkgVTable;

int LinkedBGs_T_BG_Types_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimLinkedBGs_T_BG_Types_PkgVTable != NULL
        && pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array__5546_to_string(pValue, pfnStrAppend, pData);
}

int string_to_LinkedBGs_T_BG_Types_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimLinkedBGs_T_BG_Types_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimLinkedBGs_T_BG_Types_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_array__5546(str, pValue, endptr);
    }
    return nRet;
}

int is_LinkedBGs_T_BG_Types_Pkg_double_convertion_allowed()
{
    if (pSimLinkedBGs_T_BG_Types_PkgVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimLinkedBGs_T_BG_Types_PkgVTable);
    }
    return is_array__5546_double_convertion_allowed();
}

void compare_LinkedBGs_T_BG_Types_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimLinkedBGs_T_BG_Types_PkgVTable != NULL
        && pSimLinkedBGs_T_BG_Types_PkgVTable->m_version >= Scv612
        && pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnCompare != NULL) {
        if (pSimLinkedBGs_T_BG_Types_PkgVTable->m_version >= Scv65) {
            /*R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /*Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimLinkedBGs_T_BG_Types_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_array__5546(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int LinkedBGs_T_BG_Types_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimLinkedBGs_T_BG_Types_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimLinkedBGs_T_BG_Types_PkgVTable, nRetValue);
    }
    return array__5546_to_double(pValue, nRetValue);
}

int get_LinkedBGs_T_BG_Types_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_array__5546_signature(pfnStrAppend, pData);
}

int set_LinkedBGs_T_BG_Types_Pkg_default_value(void *pValue)
{
    return set_array__5546_default_value(pValue);
}

int check_LinkedBGs_T_BG_Types_Pkg_string(const char *str, char **endptr)
{
    static LinkedBGs_T_BG_Types_Pkg rTemp;
    return string_to_LinkedBGs_T_BG_Types_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_LinkedBGs_T_BG_Types_Pkg_Utils = {
    LinkedBGs_T_BG_Types_Pkg_to_string,
    check_LinkedBGs_T_BG_Types_Pkg_string,
    string_to_LinkedBGs_T_BG_Types_Pkg,
    is_LinkedBGs_T_BG_Types_Pkg_double_convertion_allowed,
    LinkedBGs_T_BG_Types_Pkg_to_double,
    compare_LinkedBGs_T_BG_Types_Pkg,
    get_LinkedBGs_T_BG_Types_Pkg_signature,
    set_LinkedBGs_T_BG_Types_Pkg_default_value,
    sizeof(LinkedBGs_T_BG_Types_Pkg)
};

#include "C:/Program Files/Esterel Technologies/SCADE R15.2/SCADE/lib/kcg_conv.c"
