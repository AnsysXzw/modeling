#include "UtrechtAmsterdam_oETCS_newinterface.h"
const int  rt_version = Srtv62;

const char* _SCSIM_CheckSum = "92fc8ae53f6a378a8f7565d4e447e16c";
const char* _SCSIM_SmuTypesCheckSum = "f79c40cc4a28a84eb05b013596813063";

/*******************************
 * Validity
 *******************************/
int valid(void * pHandle) {
	return 1;
}
int notvalid(void * pHandle) {
	return 0;
}

/*******************************
 * Simulation context
 *******************************/
static kcg_bool _ctx_reset_restore;
kcg_bool _ctx_reset_buffer;
static CompressedBaliseMessage_TM _ctx_BG_data_restore;
static outC_DriveAllBGs_Internal_Tests _ctx_mem_restore;

static void _SCSIM_RestoreInterface(void) {
	_ctx_reset_buffer = _ctx_reset_restore;
	kcg_copy_struct__20894(&(BG_data), &(_ctx_BG_data_restore));
	Ctxt_DriveAllBGs_Internal_Tests = _ctx_mem_restore;
}

static void _SCSIM_ExecuteInterface(void) {
	pSimulator->m_pfnAcquireValueMutex(pSimulator);
	reset = _ctx_reset_buffer;
	pSimulator->m_pfnReleaseValueMutex(pSimulator);
}

/*******************************
 * Init/Reset function encapsulation
 *******************************/
int SimInit(void) {
	int nRet=0;
	_SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
	BeforeSimInit();
#endif /* EXTENDED_SIM */
	nRet=0;
#ifdef EXTENDED_SIM
	AfterSimInit();
#endif /* EXTENDED_SIM */
	return nRet;
}

int SimReset(void) {
	int nRet=0;
	_SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
	BeforeSimInit();
#endif /* EXTENDED_SIM */
#ifndef KCG_NO_EXTERN_CALL_TO_RESET
	DriveAllBGs_reset_Internal_Tests();
	nRet=1;
#else /* KCG_NO_EXTERN_CALL_TO_RESET */
	nRet=0;
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */
#ifdef EXTENDED_SIM
	AfterSimInit();
#endif /* EXTENDED_SIM */
	return nRet;
}

#ifdef EXTENDED_SIM
int GraphicalInputsConnected = 1;
#endif /* EXTENDED_SIM */
/*******************************
 * Cyclic function encapsulation
 *******************************/
int SimStep(void) {
#ifdef EXTENDED_SIM
	if (GraphicalInputsConnected)
		BeforeSimStep();
#endif /* EXTENDED_SIM */
	_SCSIM_ExecuteInterface();
	DriveAllBGs_Internal_Tests();
#ifdef EXTENDED_SIM
	AfterSimStep();
#endif /* EXTENDED_SIM */
	return 1;
}

int SimStop(void) {
#ifdef EXTENDED_SIM
	ExtendedSimStop();
#endif /* EXTENDED_SIM */
	return 1;
}

int SsmGetDumpSize(void) {
	int nSize = 0;
	nSize += sizeof(kcg_bool);
	nSize += sizeof(CompressedBaliseMessage_TM);
	nSize += sizeof(outC_DriveAllBGs_Internal_Tests);
#ifdef EXTENDED_SIM
	nSize += ExtendedGetDumpSize();
#endif /* EXTENDED_SIM */
	return nSize;
}

void SsmGatherDumpData(char * pData) {
	char* pCurrent = pData;
	memcpy(pCurrent, &reset, sizeof(kcg_bool));
	pCurrent += sizeof(kcg_bool);
	memcpy(pCurrent, &BG_data, sizeof(CompressedBaliseMessage_TM));
	pCurrent += sizeof(CompressedBaliseMessage_TM);
	memcpy(pCurrent, &Ctxt_DriveAllBGs_Internal_Tests, sizeof(outC_DriveAllBGs_Internal_Tests));
	pCurrent += sizeof(outC_DriveAllBGs_Internal_Tests);
#ifdef EXTENDED_SIM
	ExtendedGatherDumpData(pCurrent);
#endif /* EXTENDED_SIM */
}

void SsmRestoreDumpData(const char * pData) {
	const char* pCurrent = pData;
	memcpy(&reset, pCurrent, sizeof(kcg_bool));
	pCurrent += sizeof(kcg_bool);
	memcpy(&BG_data, pCurrent, sizeof(CompressedBaliseMessage_TM));
	pCurrent += sizeof(CompressedBaliseMessage_TM);
	memcpy(&Ctxt_DriveAllBGs_Internal_Tests, pCurrent, sizeof(outC_DriveAllBGs_Internal_Tests));
	pCurrent += sizeof(outC_DriveAllBGs_Internal_Tests);
#ifdef EXTENDED_SIM
	ExtendedRestoreDumpData(pCurrent);
#endif /* EXTENDED_SIM */
}

const char * SsmGetCheckSum() {
	return _SCSIM_CheckSum;
}

const char * SsmGetSmuTypesCheckSum() {
	return _SCSIM_SmuTypesCheckSum;
}

void SsmUpdateValues(void) {
#ifdef EXTENDED_SIM
	UpdateValues();
#endif /* EXTENDED_SIM */
}

void SsmConnectExternalInputs(int bConnect) {
#ifdef EXTENDED_SIM
	GraphicalInputsConnected = bConnect;
#endif /* EXTENDED_SIM */
}

