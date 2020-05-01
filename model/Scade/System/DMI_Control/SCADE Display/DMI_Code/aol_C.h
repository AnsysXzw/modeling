/*********************************************************
 **
 ** File  aol_C.h
 **
 ** Specification File:  P:\modeling\model\Scade\System\DMI_Control\SCADE Display\Widgets\C\C.ogfx
 **
 ** Automatically generated by SCADE Display KCG
 ** Version 6.6.3 (build i10)
 **
 ** Date of generation: 2017-05-30T13:27:23
 ** Command line: ScadeDisplayKCG.exe -outdir P:\modeling\model\Scade\System\DMI_Control\SCADE Display\DMI_Code P:\modeling\model\Scade\System\DMI_Control\SCADE Display\DMI.sgfx
 *********************************************************/

#ifndef _AOL_C_H
#define _AOL_C_H

#include "sgl_types.h"

#include "aol_LevelSymbols.h"
#include "aol_StatusSymbols.h"
#include "aol_ModeSymbols.h"

/* Accessors */
#define aol_C_G_LevelSymbol(_C_) (_C_)->LevelSymbol
#define aol_C_S_LevelSymbol(_C_,_V_) (_C_)->LevelSymbol = (_V_)
#define aol_C_G_StatusSymbolBrake(_C_) (_C_)->StatusSymbolBrake
#define aol_C_S_StatusSymbolBrake(_C_,_V_) (_C_)->StatusSymbolBrake = (_V_)
#define aol_C_G_LevelSymbolAnncouncement(_C_) (_C_)->LevelSymbolAnncouncement
#define aol_C_S_LevelSymbolAnncouncement(_C_,_V_) (_C_)->LevelSymbolAnncouncement = (_V_)
#define aol_C_G_LevelSymbolVisibility(_C_) (_C_)->LevelSymbolVisibility
#define aol_C_S_LevelSymbolVisibility(_C_,_V_) (_C_)->LevelSymbolVisibility = (_V_)
#define aol_C_G_ModeSymbolAnncouncement(_C_) (_C_)->ModeSymbolAnncouncement
#define aol_C_S_ModeSymbolAnncouncement(_C_,_V_) (_C_)->ModeSymbolAnncouncement = (_V_)
#define aol_C_G_iconGroupIndex(_C_) (_C_)->iconGroupIndex
#define aol_C_S_iconGroupIndex(_C_,_V_) (_C_)->iconGroupIndex = (_V_)
#define aol_C_G_yellowBorderBrakeSymbol(_C_) (_C_)->yellowBorderBrakeSymbol
#define aol_C_S_yellowBorderBrakeSymbol(_C_,_V_) (_C_)->yellowBorderBrakeSymbol = (_V_)
#define aol_C_G_yellowBorderC1Area(_C_) (_C_)->yellowBorderC1Area
#define aol_C_S_yellowBorderC1Area(_C_,_V_) (_C_)->yellowBorderC1Area = (_V_)
#define aol_C_G_C1_area_visibility(_C_) (_C_)->C1_area_visibility
#define aol_C_S_C1_area_visibility(_C_,_V_) (_C_)->C1_area_visibility = (_V_)
#define aol_C_G_OverC2(_C_) (_C_)->OverC2
#define aol_C_S_OverC2(_C_,_V_) (_C_)->OverC2 = (_V_)
#define aol_C_G_OverC3(_C_) (_C_)->OverC3
#define aol_C_S_OverC3(_C_,_V_) (_C_)->OverC3 = (_V_)
#define aol_C_G_OverC4(_C_) (_C_)->OverC4
#define aol_C_S_OverC4(_C_,_V_) (_C_)->OverC4 = (_V_)
#define aol_C_G_BrakeStatusSymbolAck(_C_) (_C_)->BrakeStatusSymbolAck
#define aol_C_S_BrakeStatusSymbolAck(_C_,_V_) (_C_)->BrakeStatusSymbolAck = (_V_)
#define aol_C_G_C1AreaAck(_C_) (_C_)->C1AreaAck
#define aol_C_S_C1AreaAck(_C_,_V_) (_C_)->C1AreaAck = (_V_)
#define aol_C_HOOK(_C_,_F_,_D_) 

/* Context type */
typedef struct aol_typ_C_ {
  /* ------------------------- inputs --------------------------- */
  SGLint32 LevelSymbol;
  SGLbool StatusSymbolBrake;
  SGLint32 LevelSymbolAnncouncement;
  SGLbool LevelSymbolVisibility;
  SGLint32 ModeSymbolAnncouncement;
  SGLint32 iconGroupIndex;
  SGLbool yellowBorderBrakeSymbol;
  SGLbool yellowBorderC1Area;
  SGLbool C1_area_visibility;
  /* ------------------------- outputs -------------------------- */
  SGLbool OverC2;
  SGLbool OverC3;
  SGLbool OverC4;
  SGLbool BrakeStatusSymbolAck;
  SGLbool C1AreaAck;
  /* ------------------------- parent priority ------------------ */
  SGLint32 _parentPriority;
} aol_typ_C;

/* Associated functions */
extern void aol_C_init(aol_typ_C *pContext);
extern void aol_C_predraw(aol_typ_C *pContext);
extern void aol_C_draw(aol_typ_C *pContext, SGLint32 pPriority);

#endif /* _AOL_C_H */

/*********************************************************
 ** End of file
 ** End of generation: 2017-05-30T13:27:23
 *********************************************************/
