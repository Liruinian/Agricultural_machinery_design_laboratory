/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _UXTHEME_H_
#define _UXTHEME_H_

#include <commctrl.h>

#ifndef THEMEAPI
#if !defined(_UXTHEME_)
#define THEMEAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define THEMEAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#else
#define THEMEAPI STDAPI
#define THEMEAPI_(type) STDAPI_(type)
#endif
#endif

typedef HANDLE HTHEME;

#if (NTDDI_VERSION >= NTDDI_WIN7)
WINBOOL WINAPI BeginPanningFeedback(HWND hwnd);
WINBOOL WINAPI UpdatePanningFeedback(HWND hwnd,LONG lTotalOverpanOffsetX,LONG lTotalOverpanOffsetY,WINBOOL fInInertia);
WINBOOL WINAPI EndPanningFeedback(HWND hwnd,WINBOOL fAnimateBack);
#endif

#if _WIN32_WINNT >= 0x0600

#define GBF_DIRECT 0x00000001
#define GBF_COPY 0x00000002
#define GBF_VALIDBITS (GBF_DIRECT | GBF_COPY)

THEMEAPI GetThemeBitmap(HTHEME hTheme,int iPartId,int iStateId,int iPropId,ULONG dwFlags,HBITMAP *phBitmap);
THEMEAPI GetThemeStream(HTHEME hTheme,int iPartId,int iStateId,int iPropId,VOID **ppvStream,DWORD *pcbStream,HINSTANCE hInst);
THEMEAPI GetThemeTransitionDuration(HTHEME hTheme,int iPartId,int iStateIdFrom,int iStateIdTo,int iPropId,DWORD *pdwDuration);

DECLARE_HANDLE(HPAINTBUFFER);

typedef enum _BP_BUFFERFORMAT {
    BPBF_COMPATIBLEBITMAP, BPBF_DIB, BPBF_TOPDOWNDIB, BPBF_TOPDOWNMONODIB
} BP_BUFFERFORMAT;

#define BPPF_ERASE     0x00000001
#define BPPF_NOCLIP    0x00000002
#define BPPF_NONCLIENT 0x00000004

typedef struct _BP_PAINTPARAMS {
    DWORD cbSize;
    DWORD dwFlags;
    const RECT *prcExclude;
    const BLENDFUNCTION *pBlendFunction;
} BP_PAINTPARAMS, *PBP_PAINTPARAMS;

THEMEAPI_(HPAINTBUFFER) BeginBufferedPaint(HDC hdcTarget,const RECT *prcTarget,BP_BUFFERFORMAT dwFormat,BP_PAINTPARAMS *pPaintParams,HDC *phdc);
THEMEAPI_(HRESULT) EndBufferedPaint(HPAINTBUFFER hBufferedPaint,WINBOOL fUpdateTarget);
THEMEAPI_(HRESULT) GetBufferedPaintTargetRect(HPAINTBUFFER hBufferedPaint,RECT *prc);
THEMEAPI_(HDC) GetBufferedPaintTargetDC(HPAINTBUFFER hBufferedPaint);
THEMEAPI_(HDC) GetBufferedPaintDC(HPAINTBUFFER hBufferedPaint);
THEMEAPI_(HRESULT) GetBufferedPaintBits(HPAINTBUFFER hBufferedPaint,RGBQUAD **ppbBuffer,int *pcxRow);
THEMEAPI_(HRESULT) BufferedPaintClear(HPAINTBUFFER hBufferedPaint,const RECT *prc);
THEMEAPI_(HRESULT) BufferedPaintSetAlpha(HPAINTBUFFER hBufferedPaint,const RECT *prc,BYTE alpha);
THEMEAPI_(HRESULT) BufferedPaintInit(VOID);
THEMEAPI_(HRESULT) BufferedPaintUnInit(VOID);

DECLARE_HANDLE(HANIMATIONBUFFER);

typedef enum _BP_ANIMATIONSTYLE {
    BPAS_NONE, BPAS_LINEAR, BPAS_CUBIC, BPAS_SINE
} BP_ANIMATIONSTYLE;

typedef struct _BP_ANIMATIONPARAMS {
    DWORD cbSize;
    DWORD  dwFlags;
    BP_ANIMATIONSTYLE style;
    DWORD dwDuration;
} BP_ANIMATIONPARAMS, *PBP_ANIMATIONPARAMS;

THEMEAPI_(HANIMATIONBUFFER) BeginBufferedAnimation(HWND hwnd,HDC hdcTarget,const RECT *rcTarget,BP_BUFFERFORMAT dwFormat,BP_PAINTPARAMS *pPaintParams,BP_ANIMATIONPARAMS *pAnimationParams,HDC *phdcFrom,HDC *phdcTo);
THEMEAPI EndBufferedAnimation(HANIMATIONBUFFER hbpAnimation,WINBOOL fUpdateTarget);
THEMEAPI_(WINBOOL) BufferedPaintRenderAnimation(HWND hwnd,HDC hdcTarget);
THEMEAPI BufferedPaintStopAllAnimations(HWND hwnd);
THEMEAPI_(WINBOOL) IsCompositionActive(void);

typedef enum WINDOWTHEMEATTRIBUTETYPE {
    WTA_NONCLIENT = 1 
} WINDOWTHEMEATTRIBUTETYPE;

typedef struct WTA_OPTIONS {
    DWORD dwFlags;
    DWORD dwMask;
} WTA_OPTIONS, *PWTA_OPTIONS;

#define WTNCA_NODRAWCAPTION 0x00000001
#define WTNCA_NODRAWICON 0x00000002
#define WTNCA_NOSYSMENU 0x00000004
#define WTNCA_NOMIRRORHELP 0x00000008
#define WTNCA_VALIDBITS (WTNCA_NODRAWCAPTION | WTNCA_NODRAWICON | WTNCA_NOSYSMENU | WTNCA_NOMIRRORHELP)

THEMEAPI SetWindowThemeAttribute(HWND hwnd,enum WINDOWTHEMEATTRIBUTETYPE eAttribute,PVOID pvAttribute,DWORD cbAttribute);

static __inline HRESULT SetWindowThemeNonClientAttributes(HWND hwnd,DWORD dwMask,DWORD dwAttributes)
{
    WTA_OPTIONS wta = { dwAttributes, dwMask };
    return SetWindowThemeAttribute(hwnd, WTA_NONCLIENT, &wta, sizeof(WTA_OPTIONS));
}

#endif

THEMEAPI_(HTHEME) OpenThemeData(HWND hwnd,LPCWSTR pszClassList);

#if (_WIN32_WINNT >= 0x0600)
#define OTD_FORCE_RECT_SIZING 0x00000001
#define OTD_NONCLIENT 0x00000002
#define OTD_VALIDBITS (OTD_FORCE_RECT_SIZING | OTD_NONCLIENT)
THEMEAPI_(HTHEME) OpenThemeDataEx(HWND hwnd,LPCWSTR pszClassList,DWORD dwFlags);
#endif

THEMEAPI CloseThemeData(HTHEME hTheme);
THEMEAPI DrawThemeBackground(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,const RECT *pClipRect);

#define DTT_GRAYED 0x1

THEMEAPI DrawThemeText(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,LPCWSTR pszText,int iCharCount,DWORD dwTextFlags,DWORD dwTextFlags2,const RECT *pRect);

#if (_WIN32_WINNT >= 0x0600)

#define DTT_TEXTCOLOR (__MSABI_LONG(1U) << 0)
#define DTT_BORDERCOLOR (__MSABI_LONG(1U) << 1)
#define DTT_SHADOWCOLOR (__MSABI_LONG(1U) << 2)
#define DTT_SHADOWTYPE (__MSABI_LONG(1U) << 3)
#define DTT_SHADOWOFFSET (__MSABI_LONG(1U) << 4)
#define DTT_BORDERSIZE (__MSABI_LONG(1U) << 5)
#define DTT_FONTPROP (__MSABI_LONG(1U) << 6)
#define DTT_COLORPROP (__MSABI_LONG(1U) << 7)
#define DTT_STATEID (__MSABI_LONG(1U) << 8)
#define DTT_CALCRECT (__MSABI_LONG(1U) << 9)
#define DTT_APPLYOVERLAY (__MSABI_LONG(1U) << 10)
#define DTT_GLOWSIZE (__MSABI_LONG(1U) << 11)
#define DTT_CALLBACK (__MSABI_LONG(1U) << 12)
#define DTT_COMPOSITED (__MSABI_LONG(1U) << 13)
#define DTT_VALIDBITS (DTT_TEXTCOLOR | DTT_BORDERCOLOR | DTT_SHADOWCOLOR | DTT_SHADOWTYPE | DTT_SHADOWOFFSET | DTT_BORDERSIZE | \
                       DTT_FONTPROP | DTT_COLORPROP | DTT_STATEID | DTT_CALCRECT | DTT_APPLYOVERLAY | DTT_GLOWSIZE | DTT_COMPOSITED)

typedef int (WINAPI *DTT_CALLBACK_PROC)(HDC hdc,LPWSTR pszText,int cchText,LPRECT prc,UINT dwFlags,LPARAM lParam);

typedef struct _DTTOPTS {
    DWORD dwSize;
    DWORD dwFlags;
    COLORREF crText;
    COLORREF crBorder;
    COLORREF crShadow;
    int iTextShadowType;
    POINT ptShadowOffset;
    int iBorderSize;
    int iFontPropId;
    int iColorPropId;
    int iStateId;
    WINBOOL fApplyOverlay;
    int iGlowSize;
    DTT_CALLBACK_PROC pfnDrawTextCallback;
    LPARAM lParam;
} DTTOPTS, *PDTTOPTS;

THEMEAPI DrawThemeTextEx(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,LPCWSTR pszText,int iCharCount,DWORD dwFlags,LPRECT pRect,const DTTOPTS *pOptions);
#endif

THEMEAPI GetThemeBackgroundContentRect(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pBoundingRect,RECT *pContentRect);
THEMEAPI GetThemeBackgroundExtent(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pContentRect,RECT *pExtentRect);

typedef enum THEMESIZE {
  TS_MIN,TS_TRUE,TS_DRAW
} THEMESIZE;

THEMEAPI GetThemePartSize(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,RECT *prc,enum THEMESIZE eSize,SIZE *psz);
THEMEAPI GetThemeTextExtent(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,LPCWSTR pszText,int iCharCount,DWORD dwTextFlags,const RECT *pBoundingRect,RECT *pExtentRect);
THEMEAPI GetThemeTextMetrics(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,TEXTMETRIC *ptm);
THEMEAPI GetThemeBackgroundRegion(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,HRGN *pRegion);

#define HTTB_BACKGROUNDSEG 0x0000
#define HTTB_FIXEDBORDER 0x0002
#define HTTB_CAPTION 0x0004
#define HTTB_RESIZINGBORDER_LEFT 0x0010
#define HTTB_RESIZINGBORDER_TOP 0x0020
#define HTTB_RESIZINGBORDER_RIGHT 0x0040
#define HTTB_RESIZINGBORDER_BOTTOM 0x0080

#define HTTB_RESIZINGBORDER (HTTB_RESIZINGBORDER_LEFT|HTTB_RESIZINGBORDER_TOP| HTTB_RESIZINGBORDER_RIGHT|HTTB_RESIZINGBORDER_BOTTOM)

#define HTTB_SIZINGTEMPLATE 0x0100
#define HTTB_SYSTEMSIZINGMARGINS 0x0200

THEMEAPI HitTestThemeBackground(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,DWORD dwOptions,const RECT *pRect,HRGN hrgn,POINT ptTest,WORD *pwHitTestCode);
THEMEAPI DrawThemeEdge(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pDestRect,UINT uEdge,UINT uFlags,RECT *pContentRect);
THEMEAPI DrawThemeIcon(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,HIMAGELIST himl,int iImageIndex);
THEMEAPI_(WINBOOL) IsThemePartDefined(HTHEME hTheme,int iPartId,int iStateId);
THEMEAPI_(WINBOOL) IsThemeBackgroundPartiallyTransparent(HTHEME hTheme,int iPartId,int iStateId);
THEMEAPI GetThemeColor(HTHEME hTheme,int iPartId,int iStateId,int iPropId,COLORREF *pColor);
THEMEAPI GetThemeMetric(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,int iPropId,int *piVal);
THEMEAPI GetThemeString(HTHEME hTheme,int iPartId,int iStateId,int iPropId,LPWSTR pszBuff,int cchMaxBuffChars);
THEMEAPI GetThemeBool(HTHEME hTheme,int iPartId,int iStateId,int iPropId,WINBOOL *pfVal);
THEMEAPI GetThemeInt(HTHEME hTheme,int iPartId,int iStateId,int iPropId,int *piVal);
THEMEAPI GetThemeEnumValue(HTHEME hTheme,int iPartId,int iStateId,int iPropId,int *piVal);
THEMEAPI GetThemePosition(HTHEME hTheme,int iPartId,int iStateId,int iPropId,POINT *pPoint);
THEMEAPI GetThemeFont(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,int iPropId,LOGFONT *pFont);
THEMEAPI GetThemeRect(HTHEME hTheme,int iPartId,int iStateId,int iPropId,RECT *pRect);

typedef struct _MARGINS {
  int cxLeftWidth;
  int cxRightWidth;
  int cyTopHeight;
  int cyBottomHeight;
} MARGINS,*PMARGINS;

THEMEAPI GetThemeMargins(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,int iPropId,RECT *prc,MARGINS *pMargins);

#if (_WIN32_WINNT >= 0x0600)
#define MAX_INTLIST_COUNT 402
#else
#define MAX_INTLIST_COUNT 10
#endif

typedef struct _INTLIST {
  int iValueCount;
  int iValues[MAX_INTLIST_COUNT];
} INTLIST,*PINTLIST;

THEMEAPI GetThemeIntList(HTHEME hTheme,int iPartId,int iStateId,int iPropId,INTLIST *pIntList);

typedef enum PROPERTYORIGIN {
  PO_STATE,PO_PART,PO_CLASS,PO_GLOBAL,PO_NOTFOUND
} PROPERTYORIGIN;

THEMEAPI GetThemePropertyOrigin(HTHEME hTheme,int iPartId,int iStateId,int iPropId,enum PROPERTYORIGIN *pOrigin);
THEMEAPI SetWindowTheme(HWND hwnd,LPCWSTR pszSubAppName,LPCWSTR pszSubIdList);
THEMEAPI GetThemeFilename(HTHEME hTheme,int iPartId,int iStateId,int iPropId,LPWSTR pszThemeFileName,int cchMaxBuffChars);
THEMEAPI_(COLORREF) GetThemeSysColor(HTHEME hTheme,int iColorId);
THEMEAPI_(HBRUSH) GetThemeSysColorBrush(HTHEME hTheme,int iColorId);
THEMEAPI_(WINBOOL) GetThemeSysBool(HTHEME hTheme,int iBoolId);
THEMEAPI_(int) GetThemeSysSize(HTHEME hTheme,int iSizeId);
THEMEAPI GetThemeSysFont(HTHEME hTheme,int iFontId,LOGFONT *plf);
THEMEAPI GetThemeSysString(HTHEME hTheme,int iStringId,LPWSTR pszStringBuff,int cchMaxStringChars);
THEMEAPI GetThemeSysInt(HTHEME hTheme,int iIntId,int *piValue);
THEMEAPI_(WINBOOL) IsThemeActive();
THEMEAPI_(WINBOOL) IsAppThemed();
THEMEAPI_(HTHEME) GetWindowTheme(HWND hwnd);

#define ETDT_DISABLE 0x00000001
#define ETDT_ENABLE 0x00000002
#define ETDT_USETABTEXTURE 0x00000004
#define ETDT_ENABLETAB (ETDT_ENABLE | ETDT_USETABTEXTURE)
#if (_WIN32_WINNT >= 0x0600)
#define ETDT_USEAEROWIZARDTABTEXTURE 0x00000008
#define ETDT_ENABLEAEROWIZARDTAB (ETDT_ENABLE | ETDT_USEAEROWIZARDTABTEXTURE)
#define ETDT_VALIDBITS (ETDT_DISABLE | ETDT_ENABLE | ETDT_USETABTEXTURE | ETDT_USEAEROWIZARDTABTEXTURE)
#endif

THEMEAPI EnableThemeDialogTexture(HWND hwnd,DWORD dwFlags);
THEMEAPI_(WINBOOL) IsThemeDialogTextureEnabled(HWND hwnd);

#define STAP_ALLOW_NONCLIENT (1 << 0)
#define STAP_ALLOW_CONTROLS (1 << 1)
#define STAP_ALLOW_WEBCONTENT (1 << 2)

THEMEAPI_(DWORD) GetThemeAppProperties();
THEMEAPI_(void) SetThemeAppProperties(DWORD dwFlags);
THEMEAPI GetCurrentThemeName(LPWSTR pszThemeFileName,int cchMaxNameChars,LPWSTR pszColorBuff,int cchMaxColorChars,LPWSTR pszSizeBuff,int cchMaxSizeChars);

#define SZ_THDOCPROP_DISPLAYNAME L"DisplayName"
#define SZ_THDOCPROP_CANONICALNAME L"ThemeName"
#define SZ_THDOCPROP_TOOLTIP L"ToolTip"
#define SZ_THDOCPROP_AUTHOR L"author"

THEMEAPI GetThemeDocumentationProperty(LPCWSTR pszThemeName,LPCWSTR pszPropertyName,LPWSTR pszValueBuff,int cchMaxValChars);
THEMEAPI DrawThemeParentBackground(HWND hwnd,HDC hdc,RECT *prc);

#if (_WIN32_WINNT >= 0x0600)
#define DTPB_WINDOWDC 0x00000001
#define DTPB_USECTLCOLORSTATIC 0x00000002
#define DTPB_USEERASEBKGND 0x00000004

THEMEAPI DrawThemeParentBackgroundEx(HWND hwnd,HDC hdc,DWORD dwFlags,const RECT *prc);
#endif

THEMEAPI EnableTheming(WINBOOL fEnable);

#define DTBG_CLIPRECT 0x00000001
#define DTBG_DRAWSOLID 0x00000002
#define DTBG_OMITBORDER 0x00000004
#define DTBG_OMITCONTENT 0x00000008
#define DTBG_COMPUTINGREGION 0x00000010
#define DTBG_MIRRORDC 0x00000020
#define DTBG_NOMIRROR 0x00000040
#define DTBG_VALIDBITS (DTBG_CLIPRECT | DTBG_DRAWSOLID | DTBG_OMITBORDER | DTBG_OMITCONTENT | DTBG_COMPUTINGREGION | DTBG_MIRRORDC | DTBG_NOMIRROR)

typedef struct _DTBGOPTS {
  DWORD dwSize;
  DWORD dwFlags;
  RECT rcClip;
} DTBGOPTS,*PDTBGOPTS;

THEMEAPI DrawThemeBackgroundEx(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,const DTBGOPTS *pOptions);
#endif
