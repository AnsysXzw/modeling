#ifndef FIND_FIRST_IN_SSP_CAT_INTERFACE
#define FIND_FIRST_IN_SSP_CAT_INTERFACE


#include "SmuTypes.h"
#include "kcg_types.h"
#include "Find_First_in_SSP_cat.h"

extern ScSimulator * pSimulator;

/*******************************
 * Simulation context
 *******************************/
extern inC_Find_First_in_SSP_cat inputs_ctx;
extern outC_Find_First_in_SSP_cat outputs_ctx;

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

#endif /*FIND_FIRST_IN_SSP_CAT_INTERFACE */
