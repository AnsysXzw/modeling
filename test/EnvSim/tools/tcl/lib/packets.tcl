#     Project: openETCS / EnvSim
#      Module: tcl / lib / packets.tcl
# Description: Common functions for handling of compressed packet data
# 
# History:
# - 29.09.15, J. Kastner: initial version
# - 01.12.15, J. Kastner: solve bug in enc/dec of P027
# - 02.12.15, J. Kastner: add enc/dec of P080

source "[file dirname [info script]]/enum.tcl"
source "[file dirname [info script]]/conv.tcl"

namespace eval ::pkts {}

# Returns the display name for the specified packet ID.
#
# @param nid_packet packet ID
# @param type of the message to which the packet belongs: R (RBC), B (balise), T (train)
proc pkts::packetName {nid_packet {type R}} {
  if {$type eq "T"} {
    switch $nid_packet {
      0 { return {Position Report} }
      1 { return {Position Report based on two balise groups} }
      3 { return {Onboard telephone numbers} }
      4 { return {Error Reporting} }
      5 { return {Train running number} }
      9 { return {Level 2/3 transition information} }
     11 { return {Validated train data} }
     44 { return {Application-specific data} }
     default { return "Unknown packet ID: $nid_packet" }
    }
  }
  switch $nid_packet {
    0   { return {Virtual Balise Cover Marker} }
    2   { return {System Version order} }
    3   { return {National Values} }
    5   { return {Linking} }
    6   { return {Virtual Balise Cover order} }
    12  { return {Level 1 Movement Authority} }
    13  { return {Staff Responsible distance Information from loop} }
    15  { return {Level 2/3 Movement Authority} }
    16  { return {Repositioning Information} }
    21  { return {Gradient Profile} }
    27  { return {International Static Speed Profile} }
    39  { return {Track Condition Change of traction system} }
    40  { return {Track Condition Change of allowed current consumption} }
    41  { return {Level Transition Order} }
    42  { return {Session Management} }
    44  { return {Data used by applications} }
    45  { return {Radio Network registration} }
    46  { return {Conditional Level Transition Order} }
    49  { return {List of balises for SH Area} }
    51  { return {Axle Load Speed Profile} }
    52  { return {Permitted Braking Distance Information} }
    57  { return {Movement Authority Request Parameters} }
    58  { return {Position Report Parameters} }
    63  { return {List of Balises in SR Authority} }
    64  { return {Inhibition of revocable TSRs from balises L2/3} }
    65  { return {Temporary Speed Restriction} }
    66  { return {Temporary Speed Restriction Revocation} }
    67  { return {Track Condition Big Metal Masses} }
    68  { return {Track Condition} }
    69  { return {Track Condition Station Platforms} }
    70  { return {Route Suitability Data} }
    71  { return {Adhesion factor} }
    72  { return {Packet for sending plain text messages} }
    76  { return {Packet for sending fixed text messages} }
    79  { return {Geographical Position Information} }
    80  { return {Mode profile} }
    88  { return {Level Crossing information} }
    90  { return {Track Ahead Free up to level 2/3 transition location} }
    131 { return {RBC transition order} }
    132 { return {Danger for Shunting} }
    133 { return {Radio infill area information} }
    134 { return {EOLM Packet} }
    135 { return {Stop Shunting on desk opening} }
    136 { return {Infill location reference} }
    137 { return {Stop if in Staff Repsonible} }
    138 { return {Reversing area information} }
    139 { return {Reversing supervision information} }
    140 { return {Train running number from RBC} }
    141 { return {Default Gradient for Temporary Speed Restriction} }
    143 { return {Session Management with neighbouring Radio Infill Unit} }
    145 { return {Inhibition of balise group message consistency reaction} }
    254 { return {Default balise, loop or RIU information} }
    255 { return {END OF INFORMATION} }
    default { return "Unknown packet ID: $nid_packet" }
  }

}


proc pkts::binToIntList {offset nint data} {
  binary scan "$data" x${offset}i${nint} lst
  return $lst
}

proc pkts::readBinPkt {nid offset nint data} {
  set lst [binToIntList $offset $nint "$data"]

  set subindex [expr $nid % 1000]
  switch -glob [expr $nid / 1000] {
     3?16 { return [readP003v1 "$lst"] }
     5?32 { return [readP005 "$lst"] }
    15?32 { return [readP015 "$lst"] }
    21?32 { return [readP021 "$lst"] }
    27?16 {
      if {$subindex > 0} {return {}}
      set niter [lindex "$lst" 4]
      set seclst [binToIntList [expr $offset + 4*$nint] [expr 4*($niter+1)] "$data"]
      set lst [concat "$lst" "$seclst"]
      return [readP027v1 "$lst"]
    }
    41?32 { return [readP041 "$lst"] }
    42?32 { return [readP042 "$lst"] }
    45?32 { return [readP045 "$lst"] }
    46?32 { return [readP046 "$lst"] }
    57?32 { return [readP057 "$lst"] }
    58?32 { return [readP058 "$lst"] }
    65?32 { return [readP065 "$lst"] }
    80?32 { return [readP080 "$lst"] }
   137?32 { return [readP137 "$lst"] }
   255??? { }
   default { error "unexpected nid: $nid" }
  }
}

proc pkts::readBinTrainPkts {offset data} {
  binary scan "$data" x${offset}i nid
  set pkts {}
  while {$nid > 0 && $nid < 999} {
    switch $nid {
      998 { 
        set lst [binToIntList $offset 17 "$data"]
        lappend pkts [readTrainP000 "$lst"]
        incr offset 68; # 17*4
      }
      1 {
        set lst [binToIntList $offset 17 "$data"]
        lappend pkts [readTrainP001 "$lst"]
        incr offset 68; # 17*4
      }
      3 {
        set lst [binToIntList $offset 8 "$data"]
        lappend pkts [readTrainP003 "$lst"]
        incr offset 32; # 8*4
      }
      4 { 
        set lst [binToIntList $offset 3 "$data"]
        lappend pkts [readTrainP004 "$lst"]
        incr offset 12; # 3*4
      }
      5 { incr offset 12; # 3*4 }
      11 { incr offset 100; # 25*4 }
      default {
        error "invalid nid: $nid (offset: $offset)"
      }
    }
    binary scan "$data" x${offset}i nid
  }

  return $pkts
}

proc pkts::readP003v1 {data} {
  set niter [lindex $data 5]

  set d [dict create\
    nid_packet     [lindex $data 0]\
    q_dir          [lindex $data 1]\
    q_scale        [lindex $data 3]\
    d_validnv      [lindex $data 4]\
    v_nvshunt      [lindex $data 6]\
    v_nvstff       [lindex $data 7]\
    v_nvonsight    [lindex $data 8]\
    v_nvunfit      [lindex $data 9]\
    v_nvrel        [lindex $data 10]\
    d_nvroll       [lindex $data 11]\
    q_nvsrbktrg    [lindex $data 12]\
    q_nvemrrls     [lindex $data 13]\
    v_nvallowovtrp [lindex $data 14]\
    v_nvsupovtrp   [lindex $data 15]\
    d_nvovtrp      [lindex $data 16]\
    t_nvovtrp      [lindex $data 17]\
    d_nvpotrp      [lindex $data 18]\
    m_nvcontact    [lindex $data 19]\
    t_nvcontact    [lindex $data 20]\
    m_nvderun      [lindex $data 21]\
    d_nvstff       [lindex $data 22]\
    q_nvdriver_adhes [lindex $data 23]\
    ]

  dict append d n_iter $niter
  if {$niter>0} {
    set npos 24
    for {set i 0} {$i<$niter} {incr i} {
      dict append d "nid_c($i)" [lindex $data $npos]
      incr npos
    }
  }

  return $d
}

proc pkts::readP005 {data} {
  set niter [lindex $data 4]

  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    n_iter     $niter]

  set npos 5
  for {set i 0} {$i<=$niter} {incr i} {
    dict append d "d_link($i)" [lindex $data $npos]
    incr npos
    set q_newc [lindex $data $npos]
    dict append d "q_newcountry($i)" $q_newc
    incr npos
    if {$q_newc==1} {
      dict append d "nid_c($i)" [lindex $data $npos]
    }
    incr npos
    dict append d "nid_bg($i)" [lindex $data $npos]
    incr npos
    dict append d "q_linkorientation($i)" [lindex $data $npos]
    incr npos
    dict append d "q_linkreaction($i)" [lindex $data $npos]
    incr npos
    dict append d "q_locacc($i)" [lindex $data $npos]
    incr npos
  }

  return $d
}

proc pkts::readP015 {data} {
  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    v_loa      [lindex $data 4]\
    t_loa      [lindex $data 5]\
    l_endsection [lindex $data 6]\
    q_sectiontimer [lindex $data 7]\
    t_sectiontimer [lindex $data 8]\
    d_sectiontimerstoploc [lindex $data 9]\
    ]

  return $d
}

proc pkts::readP021 {data} {
  set niter [lindex $data 4]

  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    n_iter     $niter\
    ]

  set npos 5
  for {set i 0} {$i<=$niter} {incr i} {
    dict append d "d_gradient($i)" [lindex $data $npos]
    incr npos
    dict append d "q_gdir($i)" [lindex $data $npos]
    incr npos
    dict append d "g_a($i)" [lindex $data $npos]
    incr npos
  }

  return $d
}

proc pkts::readP027v1 {data} {
  set niter_k [lindex $data 4]

  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    n_iter_k   $niter_k\
    ]

  set npos 6
  for {set i 0} {$i<=$niter_k} {incr i} {
    dict append d "d_static($i)" [lindex $data $npos]
    incr npos
    dict append d "v_static($i)" [lindex $data $npos]
    incr npos
    dict append d "q_front($i)" [lindex $data $npos]
    incr npos
    set n_iter_j [lindex $data $npos]
    dict append d "n_iter($i)" $n_iter_j
    incr npos
    for {set j 0} {$j<$n_iter_j} {incr j} {
      dict append d "nc_diff($i,$j)" [lindex $data $npos]
      incr npos
      dict append d "v_diff($i,$j)" [lindex $data $npos]
      incr npos
    }
  }

  return $d
}

proc pkts::readP041 {data} {
  set niter [lindex $data 5]
  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    d_leveltr  [lindex $data 4]\
    n_iter     $niter]

  set npos 6
  for {set i 0} {$i<=$niter} {incr i} {
    set m_leveltr [lindex $data $npos]
    dict append d "m_leveltr($i)" $m_leveltr
    incr npos
    if {$m_leveltr==1} {
      dict append d "nid_ntc($i)" [lindex $data $npos]
    }
    incr npos
    dict append d "l_ackleveltr($i)" [lindex $data $npos]
    incr npos
  }
  return $d
}

proc pkts::readP042 {data} {
  return [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_rbc      [lindex $data 3]\
    nid_c      [lindex $data 4]\
    nid_rbc    [lindex $data 5]\
    nid_radio  [lindex $data 6]\
    q_sleepsession [lindex $data 7]\
  ]  
}


proc pkts::readP045 {data} {
  return [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    nid_mn [lindex $data 3]]
}

proc pkts::readP046 {data} {
  set niter [lindex $data 3]
  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    n_iter     $niter]

  set npos 4
  for {set i 0} {$i<=$niter} {incr i} {
    set m_leveltr [lindex $data $npos]
    dict append d "m_leveltr($i)" $m_leveltr
    incr npos
    if {$m_leveltr==1} {
      dict append d "nid_ntc($i)" [lindex $data $npos]
      incr npos
    }
  }
  return $d
}

proc pkts::readP057 {data} {
  return [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    t_mar      [lindex $data 3]\
    t_timeoutrqst [lindex $data 4]\
    t_cycrqst  [lindex $data 5]\
    ]
}

proc pkts::readP058 {data} {
  set niter [lindex $data 7]
  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    t_cycloc   [lindex $data 4]\
    d_cycloc   [lindex $data 5]\
    m_loc      [lindex $data 6]\
    n_iter     $niter\
    ]

  set npos 8
  for {set i 0} {$i<$niter} {incr i} {
    dict append d "d_loc($i)" [lindex $data $npos]
    incr npos
    dict append d "q_lgtloc($i)" [lindex $data $npos]
    incr npos
  }

  return $d
}

proc pkts::readP065 {data} {
  return [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    nid_tsr    [lindex $data 4]\
    d_tsr      [lindex $data 5]\
    l_tsr      [lindex $data 6]\
    q_front    [lindex $data 7]\
    v_tsr      [lindex $data 8]\
    ]
}

proc pkts::readP080 {data} {
  set niter [lindex $data 4]
  set d [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_scale    [lindex $data 3]\
    n_iter     $niter\
    ]

  set npos 5
  for {set i 0} {$i<=$niter} {incr i} {
    dict append d "d_mamode($i)" [lindex $data $npos]
    incr npos
    dict append d "m_mamode($i)" [lindex $data $npos]
    incr npos
    dict append d "v_mamode($i)" [lindex $data $npos]
    incr npos
    dict append d "l_mamode($i)" [lindex $data $npos]
    incr npos
    dict append d "l_ackmamode($i)" [lindex $data $npos]
    incr npos
    dict append d "q_mamode($i)" [lindex $data $npos]
    incr npos
  }

  return $d
}
 

proc pkts::readP137 {data} {
  return [dict create\
    nid_packet [lindex $data 0]\
    q_dir      [lindex $data 1]\
    q_srstop   [lindex $data 3]\
  ]
}

proc pkts::readTrainP000 {data} {
  return [dict create\
    nid_packet 0\
    q_scale    [lindex $data 2]\
    nid_lrbg   [lindex $data 3]\
    d_lrbg     [lindex $data 4]\
    q_dirlrbg [lindex $data 5]\
    q_drllrbg [lindex $data 6]\
    l_doubtover [lindex $data 7]\
    l_doubtunder [lindex $data 8]\
    q_length   [lindex $data 9]\
    l_trainint [lindex $data 10]\
    v_train    [lindex $data 11]\
    q_dirtrain [lindex $data 12]\
    m_mode     [lindex $data 13]\
    m_level    [lindex $data 14]\
    nid_ntc    [lindex $data 15]\
    ]
}

proc pkts::readTrainP001 {data} {
  return [dict create\
    nid_packet 1\
    q_scale    [lindex $data 2]\
    nid_lrbg   [lindex $data 3]\
    nid_prvlrbg [lindex $data 4]\
    d_lrbg     [lindex $data 5]\
    q_dirlrbg  [lindex $data 6]\
    q_dlrbg    [lindex $data 7]\
    l_doubtover [lindex $data 8]\
    l_doubtunder [lindex $data 9]\
    q_length   [lindex $data 10]\
    l_trainint [lindex $data 11]\
    v_train    [lindex $data 12]\
    q_dirtrain [lindex $data 13]\
    m_mode     [lindex $data 14]\
    m_level    [lindex $data 15]\
    nid_ntc    [lindex $data 16]\
    ]
}

proc pkts::readTrainP003 {data} {
  set niter [lindex $data 2]
  set d [dict create\
    nid_packet 3\
    n_iter  $niter\
    ]
  for {set i 0; set os 3} {$i<=$niter} {incr i; incr os} {
    dict append d "nid_radio($i)" [lindex "$data" $os]
  }
  return $d
}

proc pkts::readTrainP004 {data} {
}

proc pkts::calcMetaNid {nid_packet q_dir version subindex} {
  return [expr 1000000*$nid_packet + 100000*$q_dir + 1000*$version + $subindex]
}

proc pkts::encodePacket {values} {
  set nid_packet [dict get $values nid_packet]
  set q_dir [dict get $values q_dir]
  set version 32
  set subindex 0
  switch $nid_packet {
     3 { set data [encodeP003v1 $values]; set version 16 }
     5 { set data [encodeP005 $values] }
    15 { set data [encodeP015 $values] }
    21 { set data [encodeP021 $values] }
    27 { 
      set data [encodeP027v1 $values]
      set version 16
      lappend lst [list $nid_packet $q_dir $version 0 "[lindex $data 0]"]
      set sub 100
      foreach p [lrange $data 1 end] {
        lappend lst [list $nid_packet $q_dir $version $sub "$p"]
        incr sub
      }
      return $lst
    }
    41 { set data [encodeP041 $values] }
    42 { set data [encodeP042 $values] }
    45 { set data [encodeP045 $values] }
    46 { set data [encodeP046 $values] }
    80 { set data [encodeP080 $values] }
    default { error "unsupported nid_packet=$nid_packet" }
  }
  return [list [list $nid_packet $q_dir $version $subindex "$data"]]
}

proc pkts::encodeP003v1 {values} {
  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  lappend pkt [dict get $values q_scale        ]
  set n_iter [dict get $values n_iter]
  lappend pkt $n_iter
  lappend pkt [dict get $values d_validnv      ]
  lappend pkt [dict get $values v_nvshunt      ]
  lappend pkt [dict get $values v_nvstff       ]
  lappend pkt [dict get $values v_nvonsight    ]
  lappend pkt [dict get $values v_nvunfit      ]
  lappend pkt [dict get $values v_nvrel        ]
  lappend pkt [dict get $values d_nvroll       ]
  lappend pkt [dict get $values q_nvsrbktrg    ]
  lappend pkt [dict get $values q_nvemrrls     ]
  lappend pkt [dict get $values v_nvallowovtrp ]
  lappend pkt [dict get $values v_nvsupovtrp   ]
  lappend pkt [dict get $values d_nvovtrp      ]
  lappend pkt [dict get $values t_nvovtrp      ]
  lappend pkt [dict get $values d_nvpotrp      ]
  lappend pkt [dict get $values m_nvcontact    ]
  lappend pkt [dict get $values t_nvcontact    ]
  lappend pkt [dict get $values m_nvderun      ]
  lappend pkt [dict get $values d_nvstff       ]
  lappend pkt [dict get $values q_nvdriver_adhes ]
  for {set i 0} {$i<$n_iter} {incr i} {
    lappend pkt [dict get $values nid_c($i)]
  }

  return "$pkt"
}

proc pkts::encodeP005 {values} {
  lappend pkt [dict get $values nid_packet] 
  lappend pkt [dict get $values q_dir     ] 
  lappend pkt 0
  lappend pkt [dict get $values q_scale   ] 
  set n_iter [dict get $values n_iter]
  lappend pkt $n_iter

  for {set i 0} {$i<=$n_iter} {incr i} {
    lappend pkt [dict get $values d_link($i)]
    set q_nc [dict get $values q_newcountry($i)]
    lappend pkt $q_nc
    if {$q_nc == 1} {
      lappend pkt [dict get $values nid_c($i)]
    } else {
      lappend pkt 0
    }
    lappend pkt [dict get $values nid_bg($i)]
    lappend pkt [dict get $values q_linkorientation($i)]
    lappend pkt [dict get $values q_linkreaction($i)]
    lappend pkt [dict get $values q_locacc($i)]
  }

  return "$pkt"
}

proc pkts::encodeP015 {values} {
    lappend pkt [dict get $values nid_packet] 
    lappend pkt [dict get $values q_dir     ] 
    lappend pkt 0
    lappend pkt [dict get $values q_scale   ] 
    lappend pkt [dict get $values v_loa     ] 
    lappend pkt [dict get $values t_loa     ] 
    lappend pkt [dict get $values l_endsection]
    lappend pkt [dict get $values q_sectiontimer]
    lappend pkt [dict get $values t_sectiontimer]
    lappend pkt [dict get $values d_sectiontimerstoploc]

    return "$pkt"
}

proc pkts::encodeP021 {values} {
  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  lappend pkt [dict get $values q_scale]
  set n_iter [dict get $values n_iter]
  lappend pkt $n_iter
  for {set i 0} {$i<=$n_iter} {incr i} {
    lappend pkt [dict get $values d_gradient($i)]
    lappend pkt [dict get $values q_gdir($i)]
    lappend pkt [dict get $values g_a($i)]
  }

  return "$pkt"
}

proc pkts::encodeP027v1 {values} {
  set n_iter_k [dict get $values n_iter_k]

  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  lappend pkt [dict get $values q_scale]
  lappend pkt $n_iter_k
  lappend pkt 27116100

  lappend pkts "$pkt"

  for {set k 0} {$k<=$n_iter_k} {incr k} {
    set pkt {}
    lappend pkt [dict get $values d_static($k)]
    lappend pkt [dict get $values v_static($k)]
    lappend pkt [dict get $values q_front($k)]
    set n_iter [dict get $values n_iter($k)]
    lappend pkt $n_iter

    lappend pkts "$pkt"
  }

  return $pkts
}


proc pkts::encodeP041 {values} {
  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  lappend pkt [dict get $values q_scale]
  lappend pkt [dict get $values d_leveltr]
  set n_iter [dict get $values n_iter]
  lappend pkt $n_iter
  for {set i 0} {$i<=$n_iter} {incr i} {
    set m_leveltr [dict get $values m_leveltr($i)]
    lappend pkt $m_leveltr
    if {$m_leveltr == 1} {
      lappend pkt [dict get $values nid_ntc($i)]
    } else {
      lappend pkt 0
    }
    lappend pkt [dict get $values l_ackleveltr($i)]
  }

  return "$pkt"
}

proc pkts::encodeP042 {values} {
  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  lappend pkt [dict get $values q_rbc]
  lappend pkt [dict get $values nid_c]
  lappend pkt [dict get $values nid_rbc]
  lappend pkt [dict get $values nid_radio]
  lappend pkt [dict get $values q_sleepsession]
  return "$pkt"
}

proc pkts::encodeP045 {values} {
  set pkt {}
  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  lappend pkt [dict get $values nid_nm]

  return "$pkt"
}

proc pkts::encodeP046 {values} {
  set pkt {}
  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  set n_iter [dict get $values n_iter]
  lappend pkt $n_iter
  for {set i 0} {$i <= $n_iter} {incr i} {
    set m_leveltr [dict get $values m_leveltr($i)]
    lappend pkt $m_leveltr
    if {$m_leveltr == 1} {
      lappend pkt [dict get $values nid_ntc($i)]
    }
  }

  return "$pkt"
}

proc pkts::encodeP080 {values} {
  lappend pkt [dict get $values nid_packet]
  lappend pkt [dict get $values q_dir]
  lappend pkt 0
  lappend pkt [dict get $values q_scale]

  set n_iter [dict get $values n_iter]
  lappend pkt $n_iter

  for {set i 0} {$i <= $n_iter} {incr i} {
    lappend pkt [dict get $values d_mamode($i)]
    lappend pkt [dict get $values m_mamode($i)]
    lappend pkt [dict get $values v_mamode($i)]
    lappend pkt [dict get $values l_mamode($i)]
    lappend pkt [dict get $values l_ackmamode($i)]
    lappend pkt [dict get $values q_mamode($i)]
  }

  return "$pkt"
}
