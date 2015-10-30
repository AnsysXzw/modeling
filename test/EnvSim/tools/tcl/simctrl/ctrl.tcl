#     Project: openETCS / EnvSim
#      Module: simctrl / ctrl.tcl
# Description: Main UI controller for simctrl
# 
# History:
# - 28.10.15, J. Kastner: initial version

namespace eval ::ctrl {
}

proc ctrl::error {msg} {
}

proc ctrl::displayRemoteConfig {data} {
  foreach {k v} $data {
    switch $k {
      track {
        if {$v eq ""} {
          set model::loadedTrack "No track loaded"
        } else {
          set model::loadedTrack $v
        }
      }
      sendevts {  }
    }
  }
}

proc ctrl::log {id msg {type info}} {
  .c.n.log.area configure -state normal
  .c.n.log.area insert end "\[$id\] $msg\n" $type
  .c.n.log.area configure -state disabled
  .c.n.log.area see end
}

proc ctrl::clearLog {} {
  .c.n.log.area configure -state normal
  .c.n.log.area delete 1.0 end
  .c.n.log.area configure -state disabled
}
