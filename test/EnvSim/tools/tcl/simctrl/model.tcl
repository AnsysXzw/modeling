#     Project: openETCS / EnvSim
#      Module: simctrl / model.tcl
# Description: Data model for the simulation controller
# 
# History:
# - 23.10.15, J. Kastner: initial version

namespace eval ::model {
  # sim state (SIM -> UI)
  set connected      0
  set ebActive       0
  set sbActive       0
  set tcoActive      0
  # sim controls (UI -> SIM)
  set openDesk       0
  set traction       0.0
}

proc model::ctrlsChanged {args} {
  comm::sendCtrlMsg $model::openDesk $model::traction
}
