#ifndef SPLIT_AND_REVERSE_SSP_MATRIX_INTERFACE
#define SPLIT_AND_REVERSE_SSP_MATRIX_INTERFACE


#include "SmuTypes.h"
#include "kcg_types.h"
#include "Split_And_Reverse_SSP_matrix.h"

extern ScSimulator * pSimulator;

/*******************************
 * Simulation context
 *******************************/
extern inC_Split_And_Reverse_SSP_matrix inputs_ctx;
extern outC_Split_And_Reverse_SSP_matrix outputs_ctx;

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

#endif /*SPLIT_AND_REVERSE_SSP_MATRIX_INTERFACE */
