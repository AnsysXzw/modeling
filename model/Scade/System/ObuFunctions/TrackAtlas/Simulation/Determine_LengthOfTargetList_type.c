
#include <stdlib.h>
#include "SmuTypes.h"
#include "kcg_types.h"
#include "Determine_LengthOfTargetList_type.h"
#include "Determine_LengthOfTargetList_mapping.h"

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
TypeUtils _SCSIM_struct__147_Utils = {struct__147_to_string,
	check_struct__147_string,
	string_to_struct__147,
	is_struct__147_allow_double_convertion,
	0,
	compare_struct__147_type,
	get_struct__147_signature,
	get_struct__147_filter_utils,
	struct__147_filter_size,
	struct__147_filter_values};
TypeUtils _SCSIM_array__153_Utils = {array__153_to_string,
	check_array__153_string,
	string_to_array__153,
	is_array__153_allow_double_convertion,
	0,
	compare_array__153_type,
	get_array__153_signature,
	get_array__153_filter_utils,
	array__153_filter_size,
	array__153_filter_values};
TypeUtils _SCSIM_SSP_t_indexed_matrix_element_Utils = {SSP_t_indexed_matrix_element_to_string,
	check_SSP_t_indexed_matrix_element_string,
	string_to_SSP_t_indexed_matrix_element,
	is_SSP_t_indexed_matrix_element_allow_double_convertion,
	SSP_t_indexed_matrix_element_to_double,
	compare_SSP_t_indexed_matrix_element_type,
	get_SSP_t_indexed_matrix_element_signature,
	get_SSP_t_indexed_matrix_element_filter_utils,
	SSP_t_indexed_matrix_element_filter_size,
	SSP_t_indexed_matrix_element_filter_values};
TypeUtils _SCSIM_SSP_target_t_Utils = {SSP_target_t_to_string,
	check_SSP_target_t_string,
	string_to_SSP_target_t,
	is_SSP_target_t_allow_double_convertion,
	SSP_target_t_to_double,
	compare_SSP_target_t_type,
	get_SSP_target_t_signature,
	get_SSP_target_t_filter_utils,
	SSP_target_t_filter_size,
	SSP_target_t_filter_values};
TypeUtils _SCSIM_SSP_t_list_t_Utils = {SSP_t_list_t_to_string,
	check_SSP_t_list_t_string,
	string_to_SSP_t_list_t,
	is_SSP_t_list_t_allow_double_convertion,
	SSP_t_list_t_to_double,
	compare_SSP_t_list_t_type,
	get_SSP_t_list_t_signature,
	get_SSP_t_list_t_filter_utils,
	SSP_t_list_t_filter_size,
	SSP_t_list_t_filter_values};

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
 ** struct__147
 ****************************************************************/
static void Fill_struct__147_StructSimValue(struct__147 * pStruct, StructSimValue * pValues) {
	/*Category_Index label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->Category_Index) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[0].m_pszName = "Category_Index";
	/*Pos_Index label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->Pos_Index) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[1].m_pszName = "Pos_Index";
	/*Loc label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->Loc) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_kcg_int_Utils;
	pValues[2].m_pszName = "Loc";
}

const char * struct__147_to_string(const void* pValue) {
	static StructSimValue values[3];
	Fill_struct__147_StructSimValue(((struct__147*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 3);
}

int string_to_struct__147(const char* strValue, void* pValue) {
	static struct__147 rTemp;
	int nResult = 0;
	static StructSimValue values[3];
	kcg_copy_struct__147(&(rTemp), &(*((struct__147*)pValue)));
	Fill_struct__147_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 3);
	if (nResult == 1)
		kcg_copy_struct__147(&(*((struct__147*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__147_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[3];
	Fill_struct__147_StructSimValue((struct__147*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 3);
}


int is_struct__147_allow_double_convertion() {
	return 0;
}


const char * get_struct__147_signature() {
	static StructSimValue values[3];
	Fill_struct__147_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 3);
}

FilterUtils get_struct__147_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[3];
	Fill_struct__147_StructSimValue((struct__147*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 3, strFilter);
}

const char * struct__147_filter_values[3] = {"Category_Index", "Pos_Index", "Loc"};
int check_struct__147_string(const char* strValue) {
	static struct__147 rTemp;
	return string_to_struct__147(strValue, &rTemp);
}


/****************************************************************
 ** array__153
 ****************************************************************/
void* array__153_projection(void** pValues, int nIndex) {
	return &((*(array__153*)pValues)[nIndex]);
}

const char * array__153_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnArrayToString((const void**)pValue, struct__147_to_string, 88, array__153_projection);
}

int compare_array__153_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_struct__147_type , 88, array__153_projection);
}

int is_array__153_allow_double_convertion() {
	return 0;
}

int string_to_array__153(const char* strValue, void* pValue) {
	static array__153 rTemp;
	int nResult = pSimulator->m_pfnArrayFromString(strValue, (void**)(void*)&rTemp, string_to_struct__147, 88, array__153_projection);
	if (nResult == 1)
		kcg_copy_array__153(&(*((array__153*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array__153_signature() {
	return pSimulator->m_pfnArraySignature(get_struct__147_signature, 88);
}

FilterUtils get_array__153_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_struct__147_Utils, strFilter, (void**)pValue, 88, array__153_projection);
}

int check_array__153_string(const char* strValue) {
	static array__153 rTemp;
	return string_to_array__153(strValue, &rTemp);
}


/****************************************************************
 ** SSP_t_indexed_matrix_element
 ****************************************************************/
struct SimTypeVTable* pSimSSP_t_indexed_matrix_elementVTable;
const char * SSP_t_indexed_matrix_element_to_string(const void* pValue) {
	if (pSimSSP_t_indexed_matrix_elementVTable != 0 && pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimSSP_t_indexed_matrix_elementVTable->m_pfnToType(SptString, pValue);
	return struct__147_to_string(pValue);
}

int string_to_SSP_t_indexed_matrix_element(const char* strValue, void* pValue) {
	if (pSimSSP_t_indexed_matrix_elementVTable != 0 && pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static SSP_t_indexed_matrix_element rTemp;
		int nResult = pSimSSP_t_indexed_matrix_elementVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__147(&(*((SSP_t_indexed_matrix_element*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__147(strValue, pValue);
}

int is_SSP_t_indexed_matrix_element_allow_double_convertion() {
	if (pSimSSP_t_indexed_matrix_elementVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__147_allow_double_convertion();
}

int SSP_t_indexed_matrix_element_to_double(double * nValue, const void* pValue) {
	if (pSimSSP_t_indexed_matrix_elementVTable != 0) {
		if (pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimSSP_t_indexed_matrix_elementVTable->m_pfnToType(SptLong, pValue));
		else if (pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimSSP_t_indexed_matrix_elementVTable->m_pfnToType(SptShort, pValue));
		else if (pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimSSP_t_indexed_matrix_elementVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimSSP_t_indexed_matrix_elementVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimSSP_t_indexed_matrix_elementVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__147_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__147_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_SSP_t_indexed_matrix_element_string(const char* strValue) {
	static SSP_t_indexed_matrix_element rTemp;
	return string_to_SSP_t_indexed_matrix_element(strValue, &rTemp);
}


/****************************************************************
 ** SSP_target_t
 ****************************************************************/
struct SimTypeVTable* pSimSSP_target_tVTable;
const char * SSP_target_t_to_string(const void* pValue) {
	if (pSimSSP_target_tVTable != 0 && pSimSSP_target_tVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimSSP_target_tVTable->m_pfnToType(SptString, pValue);
	return kcg_int_to_string(pValue);
}

int string_to_SSP_target_t(const char* strValue, void* pValue) {
	if (pSimSSP_target_tVTable != 0 && pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static SSP_target_t rTemp;
		int nResult = pSimSSP_target_tVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((SSP_target_t*)pValue) = rTemp;
		return nResult;
	}
	return string_to_kcg_int(strValue, pValue);
}

int is_SSP_target_t_allow_double_convertion() {
	if (pSimSSP_target_tVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_kcg_int_allow_double_convertion();
}

int SSP_target_t_to_double(double * nValue, const void* pValue) {
	if (pSimSSP_target_tVTable != 0) {
		if (pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimSSP_target_tVTable->m_pfnToType(SptLong, pValue));
		else if (pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimSSP_target_tVTable->m_pfnToType(SptShort, pValue));
		else if (pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimSSP_target_tVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimSSP_target_tVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimSSP_target_tVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_kcg_int_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_kcg_int_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_SSP_target_t_string(const char* strValue) {
	static SSP_target_t rTemp;
	return string_to_SSP_target_t(strValue, &rTemp);
}


/****************************************************************
 ** SSP_t_list_t
 ****************************************************************/
struct SimTypeVTable* pSimSSP_t_list_tVTable;
const char * SSP_t_list_t_to_string(const void* pValue) {
	if (pSimSSP_t_list_tVTable != 0 && pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimSSP_t_list_tVTable->m_pfnToType(SptString, pValue);
	return array__153_to_string(pValue);
}

int string_to_SSP_t_list_t(const char* strValue, void* pValue) {
	if (pSimSSP_t_list_tVTable != 0 && pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static SSP_t_list_t rTemp;
		int nResult = pSimSSP_t_list_tVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array__153(&(*((SSP_t_list_t*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array__153(strValue, pValue);
}

int is_SSP_t_list_t_allow_double_convertion() {
	if (pSimSSP_t_list_tVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array__153_allow_double_convertion();
}

int SSP_t_list_t_to_double(double * nValue, const void* pValue) {
	if (pSimSSP_t_list_tVTable != 0) {
		if (pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimSSP_t_list_tVTable->m_pfnToType(SptLong, pValue));
		else if (pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimSSP_t_list_tVTable->m_pfnToType(SptShort, pValue));
		else if (pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimSSP_t_list_tVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimSSP_t_list_tVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimSSP_t_list_tVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array__153_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array__153_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_SSP_t_list_t_string(const char* strValue) {
	static SSP_t_list_t rTemp;
	return string_to_SSP_t_list_t(strValue, &rTemp);
}


