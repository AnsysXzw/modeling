#     Project: openETCS / EnvSim
#      Module: tcl / lib / msgs.tcl
# Description: Common functions for handling of compressed message data (balise, radio)
# 
# History:
# - 29.10.15, J. Kastner: initial version
source "[file dirname [info script]]/packets.tcl"

namespace eval ::msgs {
}

proc msgs::parseBinPktHeaders {data} {
  set hdrs {}
  for {set i 0; set offset 40;} {$i < 30} {incr i; incr offset 20} {
    binary scan "$data" x${offset}ix8ii nid_packet start end
    if {$nid_packet > 0} {lappend hdrs $nid_packet $start $end}
  }
  return $hdrs
}

proc msgs::parseBinBaliseMsg {data} {
  binary scan $data x32i nid_bg
  dict set msg id "BG $nid_bg"
  foreach {id start end} [parseBinPktHeaders $data] {
    #puts "$id: $start - $end"
  }
  return $msg
}
