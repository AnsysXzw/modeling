#ifndef GENALL_ENVSIM_INTERNAL_INTERFACE
#define GENALL_ENVSIM_INTERNAL_INTERFACE


#include "NewSmuTypes.h"
#include "kcg_types.h"
#include "GenAll_EnvSim_Internal.h"

extern SimSimulator * pSimulator;

/*******************************
 * Simulation context
 *******************************/
extern outC_GenAll_EnvSim_Internal outputs_ctx;

/* separate_io: inputs declaration */

/* separate_io: outputs declaration */
/*******************************
 * Validity
 *******************************/
extern int valid(void*);
extern int notvalid(void*);

#ifdef EXTENDED_SIM
void BeforeSimInit();
void AfterSimInit();
void BeforeSimStep();
void AfterSimStep();
void ExtendedSimStop();
void ExtendedGatherDumpData(char * pData);
void ExtendedRestoreDumpData(const char * pData);
int ExtendedGetDumpSize();
void UpdateValues();
extern void UpdateSimulatorValues();
extern int GraphicalInputsConnected;
#endif /* EXTENDED_SIM */

#define SIM_INFO    1
#define SIM_WARNING 2
#define SIM_ERROR   3
extern void SsmOutputMessage(int level, const char* str);

#endif /*GENALL_ENVSIM_INTERNAL_INTERFACE */
