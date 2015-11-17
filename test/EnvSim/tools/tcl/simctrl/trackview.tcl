#     Project: openETCS / EnvSim
#      Module: simctrl / Trackview.tcl
# Description: Track view for simctrl.
#              This module provides procedures to visualize the train on track.
# 
# History:
# - 28.10.15, B. Kouengoue: initial version
# - 01.11.15, J. Kastner: integration into SimCtrl
# - 11.11.15, B. Kouengoue: Correction after integration into SimCtrl
source "$scriptpath/model.tcl"
package require Tk

namespace eval ::trackview {
  variable canvas
  variable unitForDistance "m"
  variable trackTotalDistance 33000
  variable train
  variable trainHeightPixel 20 
  variable ytrackPixel 
  variable trackTotalDistancePixel 
  variable xtrainCurrentPositionPixel
  variable xtrainCurrentPositionScaledPixel
  variable movingStepPixel 1
  variable canvaswidth
  variable zoomScale
  variable trainLength
  #variable BalisePos {}
  variable baliseGroup {}
}

proc trackview::readBalisePosition { pos } {
#variable BalisePos
  variable baliseGroup
  variable zoomScale
  variable trainLength
  trackview::zoom 100
  trackview::drawTrack
  trackview::drawDistancesOnTrack $zoomScale	
  trackview::drawTrain 0 $trainLength 
  set BalisePos {}

  set length [llength $pos]
  for {set i 0} {$i < $length } {incr i 2} {
    lappend BalisePos [lindex $pos  $i]
  }
  for {set i 1} {$i < $length } {incr i 2} {
    lappend baliseGroup [lindex $pos  $i]
  }

  set length1 [llength $BalisePos]
  for { set i 0} { $i < $length1} { incr i 1} {
    trackview::drawBaliseAt [lindex $BalisePos  $i]  
  }
  set length2 [llength $baliseGroup]
  for { set i 0} { $i < $length2} { incr i 1} {
    trackview::drawBaliseGroupAt [lindex $baliseGroup  $i]  
  }
  #trackview::moveTrain forward $model::currentPos	
  #trackview::moveTrain forward 3 
  #trackview::moveTrain backward 7 

  # set fp [open "output.txt" w]
  # foreach {x} $baliseGroup { puts $fp $x }   
  # close $fp	
}


proc trackview::ClearCanvas {} {
  variable canvas
  $canvas delete "all" 
} 


proc trackview::convertToPixel {distance} {
  variable trackTotalDistance
  variable trackTotalDistancePixel
  set distancePixel [expr { $trackTotalDistancePixel * $distance / $trackTotalDistance }]
  return $distancePixel
}


proc trackview::zoom { scale } {
  variable canvaswidth
  variable trackTotalDistancePixel
  variable zoomScale
  variable trainLength
  switch $scale {
    100 {
      set trackTotalDistancePixel [expr { $canvaswidth * 100}]
      set zoomScale 100
      set trainLength 10
    }
    1 {
      set trackTotalDistancePixel [expr { $canvaswidth * 10000}]
      set zoomScale 1
      set trainLength 0.1
    }
  }
}


proc trackview::init {path {height 60} {width 600}} {
  variable canvas
  variable canvaswidth $width 
  variable zoomScale
  variable trainLength
  variable train
  variable movingStepPixel
  variable ytrackPixel [expr { $height / 2 + 10 }]

  ttk::frame $path	
  grid [canvas $path.canvas -height $height -width $width -bg black -xscrollcommand "$path.x set"] -sticky news
  grid [scrollbar $path.x -command "$path.canvas xview" -orient horizontal] -sticky we  	
  set canvas $path.canvas	 	
  $path.canvas configure -scrollregion {-50 0 6000050 0} 

  #trackview::zoom 1
  #trackview::drawTrack
  #trackview::drawDistancesOnTrack 3
  #trackview::drawDistancesOnTrack $zoomScale

  #trackview::drawTrain 0 $trainLength  
  #trackview::drawTrain 0 10

  #trackview::drawBaliseAt 3
  # trackview::drawBaliseAt 9
  #trackview::drawBaliseAt 240.6
  #trackview::drawBaliseAt 243.6
  # trackview::drawBaliseAt 1179.5

  return $path
}


proc trackview::drawTrack {} {
  variable canvas
  variable ytrackPixel
  variable trackTotalDistancePixel
  $canvas create line 0 $ytrackPixel  $trackTotalDistancePixel   $ytrackPixel  -tags "axis" -width 3 -fill blue
}


proc trackview::drawDistancesOnTrack {interval} {	
  variable canvas
  variable trackTotalDistance
  variable unitForDistance
  variable ytrackPixel
  variable trackTotalDistancePixel 
  set bottomPadding 20	
  set intervalPixel [expr { $trackTotalDistancePixel * $interval / $trackTotalDistance }] 
  set distanceToDraw 0
  for {set i 0} {$i <= $trackTotalDistance } {incr i $interval} {
    if { $i == 0} {
      set iPixel [expr { $trackTotalDistancePixel * $i / $trackTotalDistance }]
      append var $distanceToDraw $unitForDistance
      $canvas create text [expr {$iPixel}] [expr { $ytrackPixel + $bottomPadding}] -text $var -anchor sw -fill white
      $canvas create rect $iPixel $ytrackPixel $iPixel $ytrackPixel  -outline white -fill white
      set var ""    		
    } else {
      set iPixel [expr { $trackTotalDistancePixel * $i / $trackTotalDistance }]
      incr distanceToDraw $interval
      append var $distanceToDraw $unitForDistance
      $canvas create text [expr {$iPixel}] [expr { $ytrackPixel + $bottomPadding}] -text $var -anchor sw -fill white
      $canvas create rect $iPixel $ytrackPixel $iPixel $ytrackPixel  -outline white -fill white
      set var ""    		
    }		
  }
}


proc trackview::drawTrain {trainInitialPosition trainLength} { 
  variable canvas
  variable trackTotalDistance
  variable train
  variable ytrackPixel
  variable trackTotalDistancePixel 
  variable trainHeightPixel 	
  variable xtrainCurrentPositionPixel
  variable xtrainCurrentPositionScaledPixel
  variable movingStepPixel 
  set trainLengthPixel [expr { $trackTotalDistancePixel * $trainLength / $trackTotalDistance }]
  set trainInitialPositionPixel [expr { $trackTotalDistancePixel * $trainInitialPosition / $trackTotalDistance }]	
  set train [$canvas create polygon  [expr {$trainInitialPositionPixel }] [expr { $ytrackPixel}] \
    [expr {$trainInitialPositionPixel + $trainLengthPixel / 2 }] [expr { $ytrackPixel - $trainHeightPixel}] \
    [expr {$trainInitialPositionPixel - $trainLengthPixel / 2 }] [expr { $ytrackPixel - $trainHeightPixel}] \
    [expr {$trainInitialPositionPixel} ] [expr { $ytrackPixel }] \
    -outline #696969 -fill #DC143C] 
  set xtrainCurrentPositionPixel $trainInitialPositionPixel 
  set xtrainCurrentPositionScaledPixel [expr { $xtrainCurrentPositionPixel / $movingStepPixel }]
}

#
#This procedure moves the train "forward/backward" by adding/subtracting "distance" 
#
proc trackview::moveTrain {direction distance} { 
  variable canvas
  variable train
  variable trackTotalDistance
  variable ytrackPixel
  variable trackTotalDistancePixel 
  variable xtrainCurrentPositionPixel
  variable xtrainCurrentPositionScaledPixel 
  variable movingStepPixel 
  set distancePixel [expr {$trackTotalDistancePixel * $distance / $trackTotalDistance }] 
  set distanceScaledPixel [expr { $distancePixel / $movingStepPixel }]
  set xtrainCurrentPositionScaledPixel [expr { $xtrainCurrentPositionScaledPixel + [expr { $xtrainCurrentPositionPixel / $movingStepPixel}] }]
  switch $direction {
    forward {
      for {set i 0} {$i <= $distanceScaledPixel && $xtrainCurrentPositionScaledPixel <= $trackTotalDistancePixel } { incr i} {
        update		
        $canvas move $train $movingStepPixel 0 	
        set xtrainCurrentPositionScaledPixel  [expr { $xtrainCurrentPositionScaledPixel + $movingStepPixel } ]
        update
      }
    }
    backward {
      for {set i 0} {$i <= $distanceScaledPixel && $xtrainCurrentPositionScaledPixel >= 0} { incr i} {
        update		
        $canvas move $train [ expr { - $movingStepPixel}] 0 	
        set xtrainCurrentPositionScaledPixel  [expr { $xtrainCurrentPositionScaledPixel - $movingStepPixel } ]				
        update
      }			
    }
  }	
}

proc trackview::drawBaliseAt {position} {
  variable canvas
  variable trackTotalDistance
  variable ytrackPixel
  variable trackTotalDistancePixel 
  set baliseLengthPixel 5
  set baliseHeightPixel 5
  set positionPixel [expr { $trackTotalDistancePixel * $position / $trackTotalDistance }]
  set Xa [ expr {$positionPixel}] 
  set Xb [ expr {$positionPixel + $baliseLengthPixel}] 
  set Ya [ expr {$ytrackPixel}]
  set Yb [ expr {$ytrackPixel + $baliseHeightPixel}]   
  #$canvas create rect $Xa $Ya $Xb $Yb  -outline #fb0 -fill #fb0
  $canvas create rect $Xa [ expr {$Ya}] $Xb [ expr {$Yb - 20}]  -outline #fb0 -fill #fb0
  $canvas create rect [ expr {$Xa - 5}] [ expr {$Ya - 20}] [ expr {$Xb + 5}] [ expr {$Yb - 20}]  -outline #fb0 -fill #fb0
}

proc trackview::drawBaliseGroupAt {position} {
#TODO 
}
