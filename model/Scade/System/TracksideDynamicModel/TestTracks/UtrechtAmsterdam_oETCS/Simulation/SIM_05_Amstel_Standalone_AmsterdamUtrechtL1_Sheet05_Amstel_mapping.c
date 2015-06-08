#include "SIM_05_Amstel_Standalone_AmsterdamUtrechtL1_Sheet05_Amstel_mapping.h"
#include "SIM_05_Amstel_Standalone_AmsterdamUtrechtL1_Sheet05_Amstel_interface.h"
#include "kcg_sensors.h"

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
static ControlUtils _SCSIM_BoolEntity_Control_Utils = {_SCSIM_BoolEntity_is_active};
/****************************************************************
 ** Mapping creation function
 ****************************************************************/
void _SCSIM_Mapping_Create() {
	_SCSIM_Mapping_SIM_05_Amstel_Standalone_AmsterdamUtrechtL1_Sheet05_Amstel();
	pSimulator->m_pfnFinalizeMapping(pSimulator);
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::SIM_05_Amstel_Standalone/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_SIM_05_Amstel_Standalone_AmsterdamUtrechtL1_Sheet05_Amstel() {
	pSimulator->m_pfnSetRoot(pSimulator, "AmsterdamUtrechtL1::Sheet05_Amstel::SIM_05_Amstel_Standalone/", &outputs_ctx, _SCSIM_Get_SIM_05_Amstel_Standalone_AmsterdamUtrechtL1_Sheet05_Amstel_Handle);
	_SCSIM_Mapping_Sheet05_Amstel_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Sheet05_Amstel", "1", 1, 0, 0);
	_SCSIM_Mapping_TrackInit_InfraLib("InfraLib::TrackInit", "1", 2, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 3, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 4, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_real_Utils, 5, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_CompressedBaliseMessage_TM_Utils, 6, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BaliseMessageOut", &_SCSIM_CompressedBaliseMessage_TM_Utils, 7, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "TrainPosIn", &_SCSIM_kcg_real_Utils, 8, valid, 0, 0);
}

void* _SCSIM_Get_SIM_05_Amstel_Standalone_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	switch (nHandleIdent) {
		case 1:
			return &(outputs_ctx._1_Context_1);
		case 2:
			return &(outputs_ctx.Context_1);
		case 3:
			return &(outputs_ctx._L1);
		case 4:
			return &(outputs_ctx._L2);
		case 5:
			return &(outputs_ctx._L3);
		case 6:
			return &(outputs_ctx._L4);
		case 7:
			return &(outputs_ctx.BaliseMessageOut);
		case 8:
			return &(inputs_ctx.TrainPosIn);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Sheet05_Amstel/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Sheet05_Amstel_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Sheet05_Amstel_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_TrackDiscontinuity_InfraLib("InfraLib::TrackDiscontinuity", "1", 9, 0, 0);
	_SCSIM_Mapping_Balises0001_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balises0001_Amstel_UB_Signal_611_to_613", "1", 10, 0, 0);
	_SCSIM_Mapping_Balises0002_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balises0002_Amstel_UB_Signal_613_to_617", "1", 11, 0, 0);
	_SCSIM_Mapping_TrackDiscontinuity_InfraLib("InfraLib::TrackDiscontinuity", "2", 12, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 13, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 14, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 15, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 16, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 17, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "SectionData_out", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 18, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Sheet05_Amstel_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Sheet05_Amstel_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Sheet05_Amstel_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 9:
			return &((*pContext).Context_1);
		case 10:
			return &((*pContext)._1_Context_1);
		case 11:
			return &((*pContext)._2_Context_1);
		case 12:
			return &((*pContext).Context_2);
		case 13:
			return &((*pContext)._L1);
		case 14:
			return &((*pContext)._L4);
		case 15:
			return &((*pContext)._L5);
		case 16:
			return &((*pContext)._L6);
		case 17:
			return &((*pContext)._L7);
		case 18:
			return &((*pContext).SectionData_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::TrackInit/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_TrackInit_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_TrackInit_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_real_Utils, 19, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_CompressedBaliseMessage_TM_Utils, 20, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 21, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_TrainPosRaw_T_InfraLib_Utils, 22, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_real_Utils, 23, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 24, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "SectionData_out", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 25, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_TrackInit_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_TrackInit_InfraLib* pContext = (outC_TrackInit_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 19:
			return &((*pContext)._L1);
		case 20:
			return &((*pContext)._L4);
		case 21:
			return &((*pContext)._L8);
		case 22:
			return &((*pContext)._L10);
		case 23:
			return &((*pContext)._L11);
		case 24:
			return &((*pContext)._L12);
		case 25:
			return &((*pContext).SectionData_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::TrackDiscontinuity/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_TrackDiscontinuity_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_TrackDiscontinuity_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	/*<< Inlined math::Abs*/
	pSimulator->m_pfnPushInstance(pSimulator, "math::Abs", "3", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "A_Output", &_SCSIM_kcg_int_Utils, 26, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "A_Input", &_SCSIM_kcg_int_Utils, 27, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 28, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 29, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_int_Utils, 30, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_int_Utils, 31, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 32, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	_SCSIM_Mapping_TrackDiscontinuity_CalcTr_InfraLib("InfraLib::TrackDiscontinuity_CalcTrainPos", "2", 33, 34, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "NewOffset", &_SCSIM_kcg_int_Utils, 35, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 36, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_int_Utils, 37, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 38, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L49", &_SCSIM_kcg_int_Utils, 39, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L50", &_SCSIM_kcg_int_Utils, 40, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L57", &_SCSIM_kcg_int_Utils, 41, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L59", &_SCSIM_kcg_real_Utils, 42, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L60", &_SCSIM_kcg_real_Utils, 43, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L61", &_SCSIM_kcg_bool_Utils, 44, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L62", &_SCSIM_kcg_bool_Utils, 45, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L63", &_SCSIM_kcg_bool_Utils, 46, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L79", &_SCSIM_kcg_real_Utils, 47, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L80", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 48, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L81", &_SCSIM_TrainPosRaw_T_InfraLib_Utils, 49, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L82", &_SCSIM_kcg_real_Utils, 50, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L83", &_SCSIM_kcg_int_Utils, 51, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L88", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 52, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L89", &_SCSIM_TrainPosRaw_T_InfraLib_Utils, 53, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L90", &_SCSIM_TrainPosRaw_T_InfraLib_Utils, 54, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L91", &_SCSIM_kcg_int_Utils, 55, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L_kcg_clock", &_SCSIM_kcg_bool_Utils, 34, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "SectionData_out", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 56, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_TrackDiscontinuity_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_TrackDiscontinuity_InfraLib* pContext = (outC_TrackDiscontinuity_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 26:
			return &((*pContext).A_Output_3);
		case 27:
			return &((*pContext).A_Input_3);
		case 28:
			return &((*pContext)._L1_3);
		case 29:
			return &((*pContext)._L2_3);
		case 30:
			return &((*pContext)._L3_3);
		case 31:
			return &((*pContext)._L5_3);
		case 32:
			return &((*pContext)._L8_3);
		case 33:
			return &((*pContext).Context_2);
		case 35:
			return &((*pContext).NewOffset);
		case 36:
			return &((*pContext)._L2);
		case 37:
			return &((*pContext)._L3);
		case 38:
			return &((*pContext)._L16);
		case 39:
			return &((*pContext)._L49);
		case 40:
			return &((*pContext)._L50);
		case 41:
			return &((*pContext)._L57);
		case 42:
			return &((*pContext)._L59);
		case 43:
			return &((*pContext)._L60);
		case 44:
			return &((*pContext)._L61);
		case 45:
			return &((*pContext)._L62);
		case 46:
			return &((*pContext)._L63);
		case 47:
			return &((*pContext)._L79);
		case 48:
			return &((*pContext)._L80);
		case 49:
			return &((*pContext)._L81);
		case 50:
			return &((*pContext)._L82);
		case 51:
			return &((*pContext)._L83);
		case 52:
			return &((*pContext)._L88);
		case 53:
			return &((*pContext)._L89);
		case 54:
			return &((*pContext)._L90);
		case 55:
			return &((*pContext)._L91);
		case 34:
			return &((*pContext).tmp);
		case 56:
			return &((*pContext).SectionData_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balises0001_Amstel_UB_Signal_611_to_613/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balises0001_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balises0001_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_Group_352_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balise_Group_352", "1", 57, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedBaliseMessage_TM_Utils, 58, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 59, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_CompressedBaliseMessage_TM_Utils, 60, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_real_Utils, 61, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 62, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "SectionData_out", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 63, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balises0001_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balises0001_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balises0001_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 57:
			return &((*pContext).Context_1);
		case 58:
			return &((*pContext)._L1);
		case 59:
			return &((*pContext)._L3);
		case 60:
			return &((*pContext)._L13);
		case 61:
			return &((*pContext)._L14);
		case 62:
			return &((*pContext)._L15);
		case 63:
			return &((*pContext).SectionData_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balises0002_Amstel_UB_Signal_613_to_617/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balises0002_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balises0002_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_Group_353_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balise_Group_353", "2", 64, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 65, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_CompressedBaliseMessage_TM_Utils, 66, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_real_Utils, 67, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedBaliseMessage_TM_Utils, 68, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 69, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "SectionData_out", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 70, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balises0002_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balises0002_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balises0002_Amstel_UB_Sig_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 64:
			return &((*pContext).Context_2);
		case 65:
			return &((*pContext)._L4);
		case 66:
			return &((*pContext)._L3);
		case 67:
			return &((*pContext)._L2);
		case 68:
			return &((*pContext)._L1);
		case 69:
			return &((*pContext)._L6);
		case 70:
			return &((*pContext).SectionData_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::TrackDiscontinuity_CalcTrainPos/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_TrackDiscontinuity_CalcTr_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_TrackDiscontinuity_CalcTr_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 71, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L18", &_SCSIM_kcg_bool_Utils, 72, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_kcg_int_Utils, 73, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L22", &_SCSIM_kcg_int_Utils, 74, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 75, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 76, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L26", &_SCSIM_kcg_real_Utils, 77, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L25", &_SCSIM_kcg_real_Utils, 78, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L24", &_SCSIM_kcg_real_Utils, 79, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_kcg_real_Utils, 80, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L28", &_SCSIM_kcg_int_Utils, 81, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L27", &_SCSIM_TrackSectionData_T_InfraLib_Utils, 82, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L29", &_SCSIM_TrainPosRaw_T_InfraLib_Utils, 83, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L30", &_SCSIM_kcg_int_Utils, 84, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L31", &_SCSIM_kcg_real_Utils, 85, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L33", &_SCSIM_kcg_real_Utils, 86, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L32", &_SCSIM_kcg_real_Utils, 87, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "TrainPosCalibrated", &_SCSIM_kcg_real_Utils, 88, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_TrackDiscontinuity_CalcTr_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_TrackDiscontinuity_CalcTr_InfraLib* pContext = (outC_TrackDiscontinuity_CalcTr_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 71:
			return &((*pContext)._L15);
		case 72:
			return &((*pContext)._L18);
		case 73:
			return &((*pContext)._L19);
		case 74:
			return &((*pContext)._L22);
		case 75:
			return &((*pContext)._L21);
		case 76:
			return &((*pContext)._L20);
		case 77:
			return &((*pContext)._L26);
		case 78:
			return &((*pContext)._L25);
		case 79:
			return &((*pContext)._L24);
		case 80:
			return &((*pContext)._L23);
		case 81:
			return &((*pContext)._L28);
		case 82:
			return &((*pContext)._L27);
		case 83:
			return &((*pContext)._L29);
		case 84:
			return &((*pContext)._L30);
		case 85:
			return &((*pContext)._L31);
		case 86:
			return &((*pContext)._L33);
		case 87:
			return &((*pContext)._L32);
		case 88:
			return &((*pContext).TrainPosCalibrated);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balise_Group_352/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_Group_352_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_Group_352_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_352_1_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balise_352_1", "1", 89, 0, 0);
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 90, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 91, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 92, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 93, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 94, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 95, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 96, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 97, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 98, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 99, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 100, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 101, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 102, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 103, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "3", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 104, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 105, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 106, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 107, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 108, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 109, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 110, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "4", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 111, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 112, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 113, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 114, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 115, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 116, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 117, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "5", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 118, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 119, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 120, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 121, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 122, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 123, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 124, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "6", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 125, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 126, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 127, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 128, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 129, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 130, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 131, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	_SCSIM_Mapping_Balise_Group_Init_InfraLib("InfraLib::Balise_Group_Init", "1", 132, 0, 0);
	_SCSIM_Mapping_Balise_Group_Close_InfraLib("InfraLib::Balise_Group_Close", "1", 133, 0, 0);
	_SCSIM_Mapping_Balise_352_0_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balise_352_0", "1", 134, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "BaliseDataIn", &_SCSIM_B_data_internal_T_InfraLib_Utils, 135, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "BaliseDataOut", &_SCSIM_B_data_internal_T_InfraLib_Utils, 136, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 137, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_B_data_internal_T_InfraLib_Utils, 138, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_B_data_internal_T_InfraLib_Utils, 139, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_B_data_internal_T_InfraLib_Utils, 140, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_B_data_internal_T_InfraLib_Utils, 141, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_B_data_internal_T_InfraLib_Utils, 142, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_B_data_internal_T_InfraLib_Utils, 143, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_B_data_internal_T_InfraLib_Utils, 144, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_B_data_internal_T_InfraLib_Utils, 145, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_CompressedBaliseMessage_TM_Utils, 146, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_bool_Utils, 147, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_B_data_internal_T_InfraLib_Utils, 148, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_BaliseGroupData_TM_Utils, 149, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 150, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 151, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L22", &_SCSIM_kcg_int_Utils, 152, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_kcg_int_Utils, 153, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L24", &_SCSIM_kcg_int_Utils, 154, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L25", &_SCSIM_kcg_int_Utils, 155, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L26", &_SCSIM_kcg_int_Utils, 156, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L27", &_SCSIM_kcg_int_Utils, 157, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_B_data_internal_T_InfraLib_Utils, 158, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L28", &_SCSIM_kcg_real_Utils, 159, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L29", &_SCSIM_CompressedBaliseMessage_TM_Utils, 160, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BG_message_out", &_SCSIM_CompressedBaliseMessage_TM_Utils, 161, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_Group_352_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_Group_352_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balise_Group_352_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 89:
			return &((*pContext)._2_Context_1);
		case 90:
			return &((*pContext).B_data_out_1);
		case 91:
			return &((*pContext).B_data_in_1);
		case 92:
			return &((*pContext).Header_1);
		case 93:
			return &((*pContext).PIG_nom_1);
		case 94:
			return &((*pContext)._L1_1);
		case 95:
			return &((*pContext)._L2_1);
		case 96:
			return &((*pContext)._L3_1);
		case 97:
			return &((*pContext).B_data_out_2);
		case 98:
			return &((*pContext).B_data_in_2);
		case 99:
			return &((*pContext).Header_2);
		case 100:
			return &((*pContext).PIG_nom_2);
		case 101:
			return &((*pContext)._L1_2);
		case 102:
			return &((*pContext)._L2_2);
		case 103:
			return &((*pContext)._L3_2);
		case 104:
			return &((*pContext).B_data_out_3);
		case 105:
			return &((*pContext).B_data_in_3);
		case 106:
			return &((*pContext).Header_3);
		case 107:
			return &((*pContext).PIG_nom_3);
		case 108:
			return &((*pContext)._L1_3);
		case 109:
			return &((*pContext)._L2_3);
		case 110:
			return &((*pContext)._L3_3);
		case 111:
			return &((*pContext).B_data_out_4);
		case 112:
			return &((*pContext).B_data_in_4);
		case 113:
			return &((*pContext).Header_4);
		case 114:
			return &((*pContext).PIG_nom_4);
		case 115:
			return &((*pContext)._L1_4);
		case 116:
			return &((*pContext)._L2_4);
		case 117:
			return &((*pContext)._L3_4);
		case 118:
			return &((*pContext).B_data_out_5);
		case 119:
			return &((*pContext).B_data_in_5);
		case 120:
			return &((*pContext).Header_5);
		case 121:
			return &((*pContext).PIG_nom_5);
		case 122:
			return &((*pContext)._L1_5);
		case 123:
			return &((*pContext)._L2_5);
		case 124:
			return &((*pContext)._L3_5);
		case 125:
			return &((*pContext).B_data_out_6);
		case 126:
			return &((*pContext).B_data_in_6);
		case 127:
			return &((*pContext).Header_6);
		case 128:
			return &((*pContext).PIG_nom_6);
		case 129:
			return &((*pContext)._L1_6);
		case 130:
			return &((*pContext)._L2_6);
		case 131:
			return &((*pContext)._L3_6);
		case 132:
			return &((*pContext).Context_1);
		case 133:
			return &((*pContext)._3_Context_1);
		case 134:
			return &((*pContext)._1_Context_1);
		case 135:
			return &((*pContext).BaliseDataIn);
		case 136:
			return &((*pContext).BaliseDataOut);
		case 137:
			return &((*pContext)._L1);
		case 138:
			return &((*pContext)._L2);
		case 139:
			return &((*pContext)._L3);
		case 140:
			return &((*pContext)._L4);
		case 141:
			return &((*pContext)._L5);
		case 142:
			return &((*pContext)._L6);
		case 143:
			return &((*pContext)._L7);
		case 144:
			return &((*pContext)._L9);
		case 145:
			return &((*pContext)._L11);
		case 146:
			return &((*pContext)._L13);
		case 147:
			return &((*pContext)._L14);
		case 148:
			return &((*pContext)._L16);
		case 149:
			return &((*pContext)._L19);
		case 150:
			return &((*pContext)._L20);
		case 151:
			return &((*pContext)._L21);
		case 152:
			return &((*pContext)._L22);
		case 153:
			return &((*pContext)._L23);
		case 154:
			return &((*pContext)._L24);
		case 155:
			return &((*pContext)._L25);
		case 156:
			return &((*pContext)._L26);
		case 157:
			return &((*pContext)._L27);
		case 158:
			return &((*pContext)._L8);
		case 159:
			return &((*pContext)._L28);
		case 160:
			return &((*pContext)._L29);
		case 161:
			return &((*pContext).BG_message_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balise_Group_353/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_Group_353_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_Group_353_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_353_1_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balise_353_1", "1", 162, 0, 0);
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 163, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 164, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 165, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 166, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 167, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 168, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 169, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 170, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 171, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 172, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 173, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 174, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 175, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 176, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "3", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 177, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 178, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 179, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 180, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 181, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 182, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 183, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "4", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 184, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 185, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 186, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 187, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 188, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 189, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 190, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "5", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 191, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 192, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 193, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 194, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 195, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 196, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 197, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Balise*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Balise", "6", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 198, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_B_data_internal_T_InfraLib_Utils, 199, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Header", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 200, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "PIG_nom", &_SCSIM_kcg_int_Utils, 201, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 202, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 203, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 204, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	_SCSIM_Mapping_Balise_Group_Init_InfraLib("InfraLib::Balise_Group_Init", "1", 205, 0, 0);
	_SCSIM_Mapping_Balise_Group_Close_InfraLib("InfraLib::Balise_Group_Close", "1", 206, 0, 0);
	_SCSIM_Mapping_Balise_353_0_AmsterdamUtrechtL1_Sheet05_Amstel("AmsterdamUtrechtL1::Sheet05_Amstel::Balise_353_0", "1", 207, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "BaliseDataIn", &_SCSIM_B_data_internal_T_InfraLib_Utils, 208, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "BaliseDataOut", &_SCSIM_B_data_internal_T_InfraLib_Utils, 209, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_B_data_internal_T_InfraLib_Utils, 210, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_B_data_internal_T_InfraLib_Utils, 211, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_B_data_internal_T_InfraLib_Utils, 212, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_B_data_internal_T_InfraLib_Utils, 213, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_B_data_internal_T_InfraLib_Utils, 214, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_B_data_internal_T_InfraLib_Utils, 215, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_B_data_internal_T_InfraLib_Utils, 216, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_B_data_internal_T_InfraLib_Utils, 217, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_B_data_internal_T_InfraLib_Utils, 218, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_CompressedBaliseMessage_TM_Utils, 219, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_bool_Utils, 220, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_B_data_internal_T_InfraLib_Utils, 221, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_BaliseGroupData_TM_Utils, 222, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 223, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 224, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L22", &_SCSIM_kcg_int_Utils, 225, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_kcg_int_Utils, 226, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L24", &_SCSIM_kcg_int_Utils, 227, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L25", &_SCSIM_kcg_int_Utils, 228, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L26", &_SCSIM_kcg_int_Utils, 229, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L27", &_SCSIM_kcg_int_Utils, 230, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_B_data_internal_T_InfraLib_Utils, 231, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L28", &_SCSIM_kcg_real_Utils, 232, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L29", &_SCSIM_CompressedBaliseMessage_TM_Utils, 233, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BG_message_out", &_SCSIM_CompressedBaliseMessage_TM_Utils, 234, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_Group_353_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_Group_353_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balise_Group_353_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 162:
			return &((*pContext)._2_Context_1);
		case 163:
			return &((*pContext).B_data_out_1);
		case 164:
			return &((*pContext).B_data_in_1);
		case 165:
			return &((*pContext).Header_1);
		case 166:
			return &((*pContext).PIG_nom_1);
		case 167:
			return &((*pContext)._L1_1);
		case 168:
			return &((*pContext)._L2_1);
		case 169:
			return &((*pContext)._L3_1);
		case 170:
			return &((*pContext).B_data_out_2);
		case 171:
			return &((*pContext).B_data_in_2);
		case 172:
			return &((*pContext).Header_2);
		case 173:
			return &((*pContext).PIG_nom_2);
		case 174:
			return &((*pContext)._L1_2);
		case 175:
			return &((*pContext)._L2_2);
		case 176:
			return &((*pContext)._L3_2);
		case 177:
			return &((*pContext).B_data_out_3);
		case 178:
			return &((*pContext).B_data_in_3);
		case 179:
			return &((*pContext).Header_3);
		case 180:
			return &((*pContext).PIG_nom_3);
		case 181:
			return &((*pContext)._L1_3);
		case 182:
			return &((*pContext)._L2_3);
		case 183:
			return &((*pContext)._L3_3);
		case 184:
			return &((*pContext).B_data_out_4);
		case 185:
			return &((*pContext).B_data_in_4);
		case 186:
			return &((*pContext).Header_4);
		case 187:
			return &((*pContext).PIG_nom_4);
		case 188:
			return &((*pContext)._L1_4);
		case 189:
			return &((*pContext)._L2_4);
		case 190:
			return &((*pContext)._L3_4);
		case 191:
			return &((*pContext).B_data_out_5);
		case 192:
			return &((*pContext).B_data_in_5);
		case 193:
			return &((*pContext).Header_5);
		case 194:
			return &((*pContext).PIG_nom_5);
		case 195:
			return &((*pContext)._L1_5);
		case 196:
			return &((*pContext)._L2_5);
		case 197:
			return &((*pContext)._L3_5);
		case 198:
			return &((*pContext).B_data_out_6);
		case 199:
			return &((*pContext).B_data_in_6);
		case 200:
			return &((*pContext).Header_6);
		case 201:
			return &((*pContext).PIG_nom_6);
		case 202:
			return &((*pContext)._L1_6);
		case 203:
			return &((*pContext)._L2_6);
		case 204:
			return &((*pContext)._L3_6);
		case 205:
			return &((*pContext).Context_1);
		case 206:
			return &((*pContext)._3_Context_1);
		case 207:
			return &((*pContext)._1_Context_1);
		case 208:
			return &((*pContext).BaliseDataIn);
		case 209:
			return &((*pContext).BaliseDataOut);
		case 210:
			return &((*pContext)._L1);
		case 211:
			return &((*pContext)._L2);
		case 212:
			return &((*pContext)._L3);
		case 213:
			return &((*pContext)._L4);
		case 214:
			return &((*pContext)._L5);
		case 215:
			return &((*pContext)._L6);
		case 216:
			return &((*pContext)._L7);
		case 217:
			return &((*pContext)._L9);
		case 218:
			return &((*pContext)._L11);
		case 219:
			return &((*pContext)._L13);
		case 220:
			return &((*pContext)._L14);
		case 221:
			return &((*pContext)._L16);
		case 222:
			return &((*pContext)._L19);
		case 223:
			return &((*pContext)._L20);
		case 224:
			return &((*pContext)._L21);
		case 225:
			return &((*pContext)._L22);
		case 226:
			return &((*pContext)._L23);
		case 227:
			return &((*pContext)._L24);
		case 228:
			return &((*pContext)._L25);
		case 229:
			return &((*pContext)._L26);
		case 230:
			return &((*pContext)._L27);
		case 231:
			return &((*pContext)._L8);
		case 232:
			return &((*pContext)._L28);
		case 233:
			return &((*pContext)._L29);
		case 234:
			return &((*pContext).BG_message_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balise_352_1/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_352_1_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_352_1_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_Localisation_InfraLib("InfraLib::Balise_Localisation", "1", 235, 0, 0);
	_SCSIM_Mapping_No_Balise_Packets_InfraLib("InfraLib::No_Balise_Packets", "1", 236, 237, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 238, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_B_data_internal_T_InfraLib_Utils, 239, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_B_data_internal_T_InfraLib_Utils, 240, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_B_data_internal_T_InfraLib_Utils, 241, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_B_data_internal_T_InfraLib_Utils, 242, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 243, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 244, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 245, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 246, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L_kcg_clock", &_SCSIM_kcg_bool_Utils, 237, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 247, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_352_1_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_352_1_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balise_352_1_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 235:
			return &((*pContext).Context_1);
		case 236:
			return &((*pContext)._1_Context_1);
		case 238:
			return &((*pContext)._L2);
		case 239:
			return &((*pContext)._L4);
		case 240:
			return &((*pContext)._L5);
		case 241:
			return &((*pContext)._L15);
		case 242:
			return &((*pContext)._L17);
		case 243:
			return &((*pContext)._L19);
		case 244:
			return &((*pContext)._L20);
		case 245:
			return &((*pContext)._L21);
		case 246:
			return &((*pContext)._L23);
		case 237:
			return &((*pContext).tmp);
		case 247:
			return &((*pContext).B_data_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::Balise_Group_Init/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_Group_Init_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_Group_Init_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_BaliseGroupData_TM_Utils, 248, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 249, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L26", &_SCSIM_B_data_internal_T_InfraLib_Utils, 250, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L27", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 251, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L28", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 252, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L29", &_SCSIM_kcg_int_Utils, 253, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L30", &_SCSIM_kcg_real_Utils, 254, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L31", &_SCSIM_kcg_bool_Utils, 255, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BG_internal_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 256, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_Group_Init_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_Group_Init_InfraLib* pContext = (outC_Balise_Group_Init_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 248:
			return &((*pContext)._L2);
		case 249:
			return &((*pContext)._L14);
		case 250:
			return &((*pContext)._L26);
		case 251:
			return &((*pContext)._L27);
		case 252:
			return &((*pContext)._L28);
		case 253:
			return &((*pContext)._L29);
		case 254:
			return &((*pContext)._L30);
		case 255:
			return &((*pContext)._L31);
		case 256:
			return &((*pContext).BG_internal_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::Balise_Group_Close/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_Group_Close_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_Group_Close_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_CompressedBaliseMessage_TM_Utils, 257, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_CompressedBaliseMessage_TM_Utils, 258, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_B_data_internal_T_InfraLib_Utils, 259, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L22", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 260, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 261, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L24", &_SCSIM_CompressedBaliseMessage_TM_Utils, 262, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L25", &_SCSIM_kcg_bool_Utils, 263, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L26", &_SCSIM_kcg_bool_Utils, 264, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Error_out", &_SCSIM_kcg_bool_Utils, 265, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BG_message_out", &_SCSIM_CompressedBaliseMessage_TM_Utils, 266, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_Group_Close_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_Group_Close_InfraLib* pContext = (outC_Balise_Group_Close_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 257:
			return &((*pContext)._L2);
		case 258:
			return &((*pContext)._L20);
		case 259:
			return &((*pContext)._L21);
		case 260:
			return &((*pContext)._L22);
		case 261:
			return &((*pContext)._L23);
		case 262:
			return &((*pContext)._L24);
		case 263:
			return &((*pContext)._L25);
		case 264:
			return &((*pContext)._L26);
		case 265:
			return &((*pContext).Error_out);
		case 266:
			return &((*pContext).BG_message_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balise_352_0/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_352_0_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_352_0_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_Localisation_InfraLib("InfraLib::Balise_Localisation", "1", 267, 0, 0);
	_SCSIM_Mapping_No_Balise_Packets_InfraLib("InfraLib::No_Balise_Packets", "1", 268, 269, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 270, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_B_data_internal_T_InfraLib_Utils, 271, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_B_data_internal_T_InfraLib_Utils, 272, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_B_data_internal_T_InfraLib_Utils, 273, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_B_data_internal_T_InfraLib_Utils, 274, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 275, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 276, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 277, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 278, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L_kcg_clock", &_SCSIM_kcg_bool_Utils, 269, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 279, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_352_0_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_352_0_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balise_352_0_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 267:
			return &((*pContext).Context_1);
		case 268:
			return &((*pContext)._1_Context_1);
		case 270:
			return &((*pContext)._L2);
		case 271:
			return &((*pContext)._L4);
		case 272:
			return &((*pContext)._L5);
		case 273:
			return &((*pContext)._L15);
		case 274:
			return &((*pContext)._L17);
		case 275:
			return &((*pContext)._L19);
		case 276:
			return &((*pContext)._L20);
		case 277:
			return &((*pContext)._L21);
		case 278:
			return &((*pContext)._L23);
		case 269:
			return &((*pContext).tmp);
		case 279:
			return &((*pContext).B_data_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balise_353_1/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_353_1_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_353_1_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_Localisation_InfraLib("InfraLib::Balise_Localisation", "1", 280, 0, 0);
	_SCSIM_Mapping_No_Balise_Packets_InfraLib("InfraLib::No_Balise_Packets", "1", 281, 282, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 283, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_B_data_internal_T_InfraLib_Utils, 284, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_B_data_internal_T_InfraLib_Utils, 285, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_B_data_internal_T_InfraLib_Utils, 286, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_B_data_internal_T_InfraLib_Utils, 287, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 288, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 289, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 290, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 291, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L_kcg_clock", &_SCSIM_kcg_bool_Utils, 282, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 292, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_353_1_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_353_1_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balise_353_1_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 280:
			return &((*pContext).Context_1);
		case 281:
			return &((*pContext)._1_Context_1);
		case 283:
			return &((*pContext)._L2);
		case 284:
			return &((*pContext)._L4);
		case 285:
			return &((*pContext)._L5);
		case 286:
			return &((*pContext)._L15);
		case 287:
			return &((*pContext)._L17);
		case 288:
			return &((*pContext)._L19);
		case 289:
			return &((*pContext)._L20);
		case 290:
			return &((*pContext)._L21);
		case 291:
			return &((*pContext)._L23);
		case 282:
			return &((*pContext).tmp);
		case 292:
			return &((*pContext).B_data_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** AmsterdamUtrechtL1::Sheet05_Amstel::Balise_353_0/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_353_0_AmsterdamUtrechtL1_Sheet05_Amstel(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_353_0_AmsterdamUtrechtL1_Sheet05_Amstel_Handle, nClockHandleIdent, pfnClockActive);
	_SCSIM_Mapping_Balise_Localisation_InfraLib("InfraLib::Balise_Localisation", "1", 293, 0, 0);
	_SCSIM_Mapping_No_Balise_Packets_InfraLib("InfraLib::No_Balise_Packets", "1", 294, 295, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 296, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_B_data_internal_T_InfraLib_Utils, 297, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_B_data_internal_T_InfraLib_Utils, 298, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_B_data_internal_T_InfraLib_Utils, 299, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_B_data_internal_T_InfraLib_Utils, 300, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 301, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 302, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 303, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 304, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L_kcg_clock", &_SCSIM_kcg_bool_Utils, 295, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 305, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_353_0_AmsterdamUtrechtL1_Sheet05_Amstel_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_353_0_AmsterdamUtrechtL1_Sheet05_Amstel* pContext = (outC_Balise_353_0_AmsterdamUtrechtL1_Sheet05_Amstel*)pInstance;
	switch (nHandleIdent) {
		case 293:
			return &((*pContext).Context_1);
		case 294:
			return &((*pContext)._1_Context_1);
		case 296:
			return &((*pContext)._L2);
		case 297:
			return &((*pContext)._L4);
		case 298:
			return &((*pContext)._L5);
		case 299:
			return &((*pContext)._L15);
		case 300:
			return &((*pContext)._L17);
		case 301:
			return &((*pContext)._L19);
		case 302:
			return &((*pContext)._L20);
		case 303:
			return &((*pContext)._L21);
		case 304:
			return &((*pContext)._L23);
		case 295:
			return &((*pContext).tmp);
		case 305:
			return &((*pContext).B_data_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::Balise_Localisation/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_Localisation_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_Localisation_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	pSimulator->m_pfnAddLocal(pSimulator, "_L73", &_SCSIM_kcg_real_Utils, 306, valid, 0, 0);
	_SCSIM_Mapping_Balise_Interdistance_InfraLib("InfraLib::Balise_Interdistance", "1", 307, 0, 0);
	_SCSIM_Mapping_TOOLS_convert_engineering_TM_conversions("TM_conversions::TOOLS_convert_engineering_location", "1", 308, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 309, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 310, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L47", &_SCSIM_kcg_int_Utils, 311, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L48", &_SCSIM_kcg_int_Utils, 312, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L50", &_SCSIM_kcg_bool_Utils, 313, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L51", &_SCSIM_kcg_int_Utils, 314, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L52", &_SCSIM_kcg_int_Utils, 315, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L65", &_SCSIM_B_data_internal_T_InfraLib_Utils, 316, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L66", &_SCSIM_kcg_int_Utils, 317, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L72", &_SCSIM_kcg_bool_Utils, 318, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L71", &_SCSIM_B_data_internal_T_InfraLib_Utils, 319, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L70", &_SCSIM_kcg_real_Utils, 320, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L69", &_SCSIM_kcg_bool_Utils, 321, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L68", &_SCSIM_kcg_int_Utils, 322, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L67", &_SCSIM_kcg_bool_Utils, 323, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L75", &_SCSIM_kcg_real_Utils, 324, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L76", &_SCSIM_kcg_real_Utils, 325, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L77", &_SCSIM_kcg_real_Utils, 326, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L80", &_SCSIM_kcg_bool_Utils, 327, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L79", &_SCSIM_kcg_bool_Utils, 328, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L78", &_SCSIM_kcg_bool_Utils, 329, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L81", &_SCSIM_kcg_bool_Utils, 330, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "PIG_0_out", &_SCSIM_kcg_int_Utils, 331, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "TrainPass", &_SCSIM_kcg_bool_Utils, 332, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_Localisation_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_Localisation_InfraLib* pContext = (outC_Balise_Localisation_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 306:
			return &((*pContext)._L73);
		case 307:
			return &((*pContext).Context_1);
		case 308:
			return &((*pContext)._1_Context_1);
		case 309:
			return &((*pContext)._L15);
		case 310:
			return &((*pContext)._L16);
		case 311:
			return &((*pContext)._L47);
		case 312:
			return &((*pContext)._L48);
		case 313:
			return &((*pContext)._L50);
		case 314:
			return &((*pContext)._L51);
		case 315:
			return &((*pContext)._L52);
		case 316:
			return &((*pContext)._L65);
		case 317:
			return &((*pContext)._L66);
		case 318:
			return &((*pContext)._L72);
		case 319:
			return &((*pContext)._L71);
		case 320:
			return &((*pContext)._L70);
		case 321:
			return &((*pContext)._L69);
		case 322:
			return &((*pContext)._L68);
		case 323:
			return &((*pContext)._L67);
		case 324:
			return &((*pContext)._L75);
		case 325:
			return &((*pContext)._L76);
		case 326:
			return &((*pContext)._L77);
		case 327:
			return &((*pContext)._L80);
		case 328:
			return &((*pContext)._L79);
		case 329:
			return &((*pContext)._L78);
		case 330:
			return &((*pContext)._L81);
		case 331:
			return &((*pContext).PIG_0_out);
		case 332:
			return &((*pContext).TrainPass);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::No_Balise_Packets/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_No_Balise_Packets_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_No_Balise_Packets_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 333, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 334, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 335, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 336, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 337, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 338, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "3", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 339, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 340, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 341, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "4", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 342, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 343, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 344, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "5", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 345, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 346, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 347, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "6", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 348, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 349, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 350, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "7", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 351, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 352, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 353, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "8", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 354, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 355, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 356, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "9", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 357, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 358, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 359, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "0", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 360, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 361, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 362, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "20", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 363, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 364, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 365, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "19", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 366, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 367, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 368, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "18", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 369, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 370, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 371, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "17", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 372, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 373, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 374, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "16", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 375, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 376, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 377, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "15", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 378, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 379, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 380, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "14", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 381, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 382, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 383, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "13", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 384, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 385, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 386, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "12", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 387, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 388, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 389, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined InfraLib::No_Packet*/
	pSimulator->m_pfnPushInstance(pSimulator, "InfraLib::No_Packet", "11", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 390, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 391, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 392, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "B_data_in", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 393, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "B_data_out", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 394, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "B_data_link", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 395, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 396, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 397, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 398, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 399, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 400, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 401, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 402, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 403, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 404, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 405, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 406, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 407, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 408, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L18", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 409, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 410, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 411, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 412, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 413, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 414, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 415, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L22", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 416, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L24", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 417, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L25", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 418, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L26", &_SCSIM_B_data_internal_T_InfraLib_Utils, 419, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L28", &_SCSIM_BaliseTelegramHeader_int_T_TM_Utils, 420, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L29", &_SCSIM_B_data_internal_T_InfraLib_Utils, 421, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L30", &_SCSIM_CompressedPackets_T_Common_Types_Pkg_Utils, 422, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L31", &_SCSIM_B_data_internal_T_InfraLib_Utils, 423, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Balise_data_out", &_SCSIM_B_data_internal_T_InfraLib_Utils, 424, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_No_Balise_Packets_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_No_Balise_Packets_InfraLib* pContext = (outC_No_Balise_Packets_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 333:
			return &((*pContext).B_data_out_1);
		case 334:
			return &((*pContext).B_data_in_1);
		case 335:
			return &((*pContext)._L1_1);
		case 336:
			return &((*pContext).B_data_out_2);
		case 337:
			return &((*pContext).B_data_in_2);
		case 338:
			return &((*pContext)._L1_2);
		case 339:
			return &((*pContext).B_data_out_3);
		case 340:
			return &((*pContext).B_data_in_3);
		case 341:
			return &((*pContext)._L1_3);
		case 342:
			return &((*pContext).B_data_out_4);
		case 343:
			return &((*pContext).B_data_in_4);
		case 344:
			return &((*pContext)._L1_4);
		case 345:
			return &((*pContext).B_data_out_5);
		case 346:
			return &((*pContext).B_data_in_5);
		case 347:
			return &((*pContext)._L1_5);
		case 348:
			return &((*pContext).B_data_out_6);
		case 349:
			return &((*pContext).B_data_in_6);
		case 350:
			return &((*pContext)._L1_6);
		case 351:
			return &((*pContext).B_data_out_7);
		case 352:
			return &((*pContext).B_data_in_7);
		case 353:
			return &((*pContext)._L1_7);
		case 354:
			return &((*pContext).B_data_out_8);
		case 355:
			return &((*pContext).B_data_in_8);
		case 356:
			return &((*pContext)._L1_8);
		case 357:
			return &((*pContext).B_data_out_9);
		case 358:
			return &((*pContext).B_data_in_9);
		case 359:
			return &((*pContext)._L1_9);
		case 360:
			return &((*pContext).B_data_out_0);
		case 361:
			return &((*pContext).B_data_in_0);
		case 362:
			return &((*pContext)._L1_0);
		case 363:
			return &((*pContext).B_data_out_20);
		case 364:
			return &((*pContext).B_data_in_20);
		case 365:
			return &((*pContext)._L1_20);
		case 366:
			return &((*pContext).B_data_out_19);
		case 367:
			return &((*pContext).B_data_in_19);
		case 368:
			return &((*pContext)._L1_19);
		case 369:
			return &((*pContext).B_data_out_18);
		case 370:
			return &((*pContext).B_data_in_18);
		case 371:
			return &((*pContext)._L1_18);
		case 372:
			return &((*pContext).B_data_out_17);
		case 373:
			return &((*pContext).B_data_in_17);
		case 374:
			return &((*pContext)._L1_17);
		case 375:
			return &((*pContext).B_data_out_16);
		case 376:
			return &((*pContext).B_data_in_16);
		case 377:
			return &((*pContext)._L1_16);
		case 378:
			return &((*pContext).B_data_out_15);
		case 379:
			return &((*pContext).B_data_in_15);
		case 380:
			return &((*pContext)._L1_15);
		case 381:
			return &((*pContext).B_data_out_14);
		case 382:
			return &((*pContext).B_data_in_14);
		case 383:
			return &((*pContext)._L1_14);
		case 384:
			return &((*pContext).B_data_out_13);
		case 385:
			return &((*pContext).B_data_in_13);
		case 386:
			return &((*pContext)._L1_13);
		case 387:
			return &((*pContext).B_data_out_12);
		case 388:
			return &((*pContext).B_data_in_12);
		case 389:
			return &((*pContext)._L1_12);
		case 390:
			return &((*pContext).B_data_out_11);
		case 391:
			return &((*pContext).B_data_in_11);
		case 392:
			return &((*pContext)._L1_11);
		case 393:
			return &((*pContext).B_data_in);
		case 394:
			return &((*pContext).B_data_out);
		case 395:
			return &((*pContext).B_data_link);
		case 396:
			return &((*pContext)._L2);
		case 397:
			return &((*pContext)._L3);
		case 398:
			return &((*pContext)._L4);
		case 399:
			return &((*pContext)._L5);
		case 400:
			return &((*pContext)._L6);
		case 401:
			return &((*pContext)._L7);
		case 402:
			return &((*pContext)._L8);
		case 403:
			return &((*pContext)._L9);
		case 404:
			return &((*pContext)._L10);
		case 405:
			return &((*pContext)._L11);
		case 406:
			return &((*pContext)._L21);
		case 407:
			return &((*pContext)._L20);
		case 408:
			return &((*pContext)._L19);
		case 409:
			return &((*pContext)._L18);
		case 410:
			return &((*pContext)._L17);
		case 411:
			return &((*pContext)._L16);
		case 412:
			return &((*pContext)._L15);
		case 413:
			return &((*pContext)._L14);
		case 414:
			return &((*pContext)._L13);
		case 415:
			return &((*pContext)._L12);
		case 416:
			return &((*pContext)._L22);
		case 417:
			return &((*pContext)._L24);
		case 418:
			return &((*pContext)._L25);
		case 419:
			return &((*pContext)._L26);
		case 420:
			return &((*pContext)._L28);
		case 421:
			return &((*pContext)._L29);
		case 422:
			return &((*pContext)._L30);
		case 423:
			return &((*pContext)._L31);
		case 424:
			return &((*pContext).Balise_data_out);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** InfraLib::Balise_Interdistance/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Balise_Interdistance_InfraLib(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_Balise_Interdistance_InfraLib_Handle, nClockHandleIdent, pfnClockActive);
	/*<< Inlined math::Abs*/
	pSimulator->m_pfnPushInstance(pSimulator, "math::Abs", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "A_Output", &_SCSIM_kcg_int_Utils, 425, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "A_Input", &_SCSIM_kcg_int_Utils, 426, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 427, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 428, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_int_Utils, 429, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_int_Utils, 430, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 431, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_real_Utils, 432, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_real_Utils, 433, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_real_Utils, 434, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_real_Utils, 435, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_real_Utils, 436, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 437, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_bool_Utils, 438, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 439, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 440, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 441, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_real_Utils, 442, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 443, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_real_Utils, 444, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "distance_BB", &_SCSIM_kcg_real_Utils, 445, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_Balise_Interdistance_InfraLib_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_Balise_Interdistance_InfraLib* pContext = (outC_Balise_Interdistance_InfraLib*)pInstance;
	switch (nHandleIdent) {
		case 425:
			return &((*pContext).A_Output_1);
		case 426:
			return &((*pContext).A_Input_1);
		case 427:
			return &((*pContext)._L1_1);
		case 428:
			return &((*pContext)._L2_1);
		case 429:
			return &((*pContext)._L3_1);
		case 430:
			return &((*pContext)._L5_1);
		case 431:
			return &((*pContext)._L8_1);
		case 432:
			return &((*pContext)._L1);
		case 433:
			return &((*pContext)._L2);
		case 434:
			return &((*pContext)._L3);
		case 435:
			return &((*pContext)._L4);
		case 436:
			return &((*pContext)._L5);
		case 437:
			return &((*pContext)._L6);
		case 438:
			return &((*pContext)._L8);
		case 439:
			return &((*pContext)._L9);
		case 440:
			return &((*pContext)._L10);
		case 441:
			return &((*pContext)._L11);
		case 442:
			return &((*pContext)._L12);
		case 443:
			return &((*pContext)._L13);
		case 444:
			return &((*pContext)._L14);
		case 445:
			return &((*pContext).distance_BB);
		default:
			break;
	}
	return 0;
}

/****************************************************************
 ** TM_conversions::TOOLS_convert_engineering_location/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_TOOLS_convert_engineering_TM_conversions(const char* pszPath, const char* pszInstanceName, int nHandleIdent, int nClockHandleIdent, int (*pfnClockActive)(void*)) {
	pSimulator->m_pfnPushInstance(pSimulator, pszPath, pszInstanceName, nHandleIdent, _SCSIM_Get_TOOLS_convert_engineering_TM_conversions_Handle, nClockHandleIdent, pfnClockActive);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_int_Utils, 446, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_real_Utils, 447, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_real_Utils, 448, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_real_Utils, 449, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Loc_real", &_SCSIM_kcg_real_Utils, 450, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
}

void* _SCSIM_Get_TOOLS_convert_engineering_TM_conversions_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	outC_TOOLS_convert_engineering_TM_conversions* pContext = (outC_TOOLS_convert_engineering_TM_conversions*)pInstance;
	switch (nHandleIdent) {
		case 446:
			return &((*pContext)._L1);
		case 447:
			return &((*pContext)._L2);
		case 448:
			return &((*pContext)._L3);
		case 449:
			return &((*pContext)._L4);
		case 450:
			return &((*pContext).Loc_real);
		default:
			break;
	}
	return 0;
}

static int _SCSIM_ClockActive_kcg_true(void* clock) {
return *(kcg_bool*)clock == kcg_true ? 1 : 0;
}
