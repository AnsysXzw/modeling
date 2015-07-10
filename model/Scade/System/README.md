# Directory structure

Directory | Description | Status
----------|-------------|-------
[APITypes](https://github.com/openETCS/modeling/tree/master/model/Scade/System/APITypes) | Datatypes used at the API interface. Data delivered to the openETCS-API is provided using the datatypes in this SCADE model. | in verification
[DMI_Control](https://github.com/openETCS/modeling/tree/master/model/Scade/System/DMI_Control) | DMI Controller project. The project is not part of the EVC kernel but needed to connect the DMI implemented in SCADE Display to the EVC interface. | under development
[ETCS_Language](https://github.com/openETCS/modeling/tree/master/model/Scade/System/ETCS_Language) | Contains the variable definitions, packet definitions and message definitions complying to Subset 026 chapter 7 and 8. Currently only the variable definitions of chapter 7 are used in the project. The packet and message definitions are deprecated and not used in the project anymore. | in verification
[OBU_Integration](https://github.com/openETCS/modeling/tree/master/model/Scade/System/OBU_Integration) | This model will be the EVC model representing the architecture of the system. Currently the integration model is under construction and not compileable. | only system structure
[OBU_PreIntegrations](https://github.com/openETCS/modeling/tree/master/model/Scade/System/OBU_PreIntegrations) | Contains the current integration model used for testing purposes, the EVC model used for testing purposes and the Toolbox, which contains environment components to simulate the train. | see status of submodels
[OBU_for_ITEA_Review](https://github.com/openETCS/modeling/tree/master/model/Scade/System/OBU_for_ITEA-Review) | Contains the integration model used for demonstration purposes at the ITEA Review March 2015. The model is at the moment still kept in a running state but there are no new functions/modules added anymore. | frozen
[ObuFunctions](https://github.com/openETCS/modeling/tree/master/model/Scade/System/ObuFunctions) | Contains the submodules of the EVC kernel, which are integrated in the OBU integration model. | see status of submodels
[RBC-System](https://github.com/openETCS/modeling/tree/master/model/Scade/System/RBC-System) | Contains the model of the RBC simulation (external of EVC kernel, trackside) | under development
[TracksideDynamicModel](https://github.com/openETCS/modeling/tree/master/model/Scade/System/TracksideDynamicModel) | Contains the library to build test tracks and the test track "Utrecht-Amsterdam"  | in verification
