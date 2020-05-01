/*********************************************************
 **
 ** File  aol_closebutton.c
 **
 ** Specification File:  P:\modeling\model\Scade\System\DMI_Control\SCADE Display\Widgets\MainMenu\Button\closebutton.ogfx
 **
 ** Automatically generated by SCADE Display KCG
 ** Version 6.6.3 (build i10)
 **
 ** Date of generation: 2017-05-30T13:27:24
 ** Command line: ScadeDisplayKCG.exe -outdir P:\modeling\model\Scade\System\DMI_Control\SCADE Display\DMI_Code P:\modeling\model\Scade\System\DMI_Control\SCADE Display\DMI.sgfx
 *********************************************************/

#include "aol_closebutton.h"
#include "aol_imported_functions.h"
#include "sgl.h"


void aol_closebutton_init(aol_typ_closebutton *pContext)
{
  aol_closebutton_S_ModeSymbol(pContext, 25L);
  aol_closebutton_S_isPressed(pContext, SGL_FALSE);
  aol_closebutton_S_onButton(pContext, SGL_FALSE);

  pContext->_parentPriority = 0L;

}

void aol_closebutton_predraw(aol_typ_closebutton *pContext)
{

}

void aol_closebutton_draw(aol_typ_closebutton *pContext, SGLint32 pPriority)
{
  if (SGLint32_eq(pPriority, pContext->_parentPriority)) {

    /* Object: closeButton, Type: container, OID: 573f3ea7-0354-469b-b1bc-b928b22ebc87 */
    {
      sglPushMatrixAndTranslate(153.0F, 226.0F);

      /* Object: rectangle, Type: rectangle, OID: ad157235-1232-4d03-9282-d4c1b780bf26 */
      {
        /* filled object part */
        sglIndexColori(6L);
        sglDisable(SGL_MODULATE);
        sglDisable(SGL_POLYGON_SMOOTH);
        sglTransparency8(255L);
        sglDisable(SGL_TEXTURE_2D);
        sglDisable(SGL_TESSELLATION);
        sglBegin(SGL_POLYGON);
        sglVertex2f(-153.0F, -175.0F);
        sglVertex2f(-71.0F, -175.0F);
        sglVertex2f(-71.0F, -225.0F);
        sglVertex2f(-153.0F, -225.0F);
        sglEnd();
      }

      /* Object: TL_outerLine, Type: line, OID: 6798ede5-145c-44f4-ab4d-624d23d7b995 */
      {
        /* outlined object part */
        sglIndexColori(2L);
        sglIndexHaloColori(-1L);
        sglIndexLineWidthi(0L);
        sglIndexLineStipplei(0L);
        sglDisable(SGL_LINE_HALOING);
        sglSetLineCaps(SGL_STRAIGHT_CAPS);
        sglBegin(SGL_LINE_STRIP);
        sglVertex2f(-153.0F, -225.0F);
        sglVertex2f(-153.0F, -175.0F);
        sglVertex2f(-71.0F, -175.0F);
        sglEnd();
      }

      /* Object: TL_innerLine, Type: line, OID: 90ef4a15-0aca-4c79-8e73-ca473dc9f8e7 */
      {
        if (SGLbool_not(SGLbool_and(aol_closebutton_G_onButton(pContext), aol_closebutton_G_isPressed(pContext)))) {
          /* outlined object part */
          sglIndexColori(7L);
          sglBegin(SGL_LINE_STRIP);
          sglVertex2f(-152.0F, -224.0F);
          sglVertex2f(-152.0F, -176.0F);
          sglVertex2f(-72.0F, -176.0F);
          sglEnd();
        }
      }

      /* Object: BR_innerLine, Type: line, OID: 0111131c-35b8-4736-b8e4-9d662794876f */
      {
        if (SGLbool_not(SGLbool_and(aol_closebutton_G_onButton(pContext), aol_closebutton_G_isPressed(pContext)))) {
          /* outlined object part */
          sglIndexColori(2L);
          sglSetLineCaps(SGL_ROUNDED_CAPS);
          sglBegin(SGL_LINE_STRIP);
          sglVertex2f(-152.0F, -224.0F);
          sglVertex2f(-72.0F, -224.0F);
          sglVertex2f(-72.0F, -176.0F);
          sglEnd();
        }
      }

      /* Object: BR_outerLine, Type: line, OID: a823ceee-c33d-4389-bae7-d8f48e84fcc1 */
      {
        /* outlined object part */
        sglIndexColori(7L);
        sglSetLineCaps(SGL_ROUNDED_CAPS);
        sglBegin(SGL_LINE_STRIP);
        sglVertex2f(-153.0F, -225.0F);
        sglVertex2f(-71.0F, -225.0F);
        sglVertex2f(-71.0F, -175.0F);
        sglEnd();
      }

      /* Object: NavSymbol, Type: referenceContainer, OID: 7efee9cf-2bcc-4db7-b61e-3112448a2b03 */
      {
        sglPushMatrixAndTranslate(-112.5F, -200.0F);
        {
          aol_typ_NavigationSymbols _lSubContextVar;
          aol_typ_NavigationSymbols *_lSubContext = &_lSubContextVar;
          aol_NavigationSymbols_init(_lSubContext);
          aol_NavigationSymbols_S_ModeSymbol(_lSubContext, aol_closebutton_G_ModeSymbol(pContext));
          _lSubContext->_parentPriority = pContext->_parentPriority;
          aol_NavigationSymbols_draw(_lSubContext, pPriority);
        }
        sglPopMatrixAndTranslate();
      }

      /* Object: rectangle_area, Type: rectangleArea, OID: 0fb4c9df-e635-4c88-9927-6f97f7a07240 */
      {
        if (SGLint32_eq(aol_closebutton_G_ModeSymbol(pContext), 25L)) {
          {
            SGLfloat _lX = 0.0F;
            SGLfloat _lY = 0.0F;
            aol_locate(-1L, &_lX, &_lY);
            aol_closebutton_G_onButton(pContext) = sglRectangleActiveAreaGetStatus(_lX, _lY, -153.0F, -175.0F, -71.0F, -225.0F);
          }
        }
      }
      sglPopMatrixAndTranslate();
    }
  }
}


/*********************************************************
 ** End of file
 ** End of generation: 2017-05-30T13:27:24
 *********************************************************/
