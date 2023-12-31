#ifndef ___DWM_6_4_ENUMS___
#define ___DWM_6_4_ENUMS___

enum { CurNormal, CurResize, CurMove, CurLast }; /* cursor */

enum { SchemeNorm, SchemeSel, SchemeHov, SchemeHid }; /* color schemes */

enum {
    NetSupported,
    NetWMName,
    NetWMState,
    NetWMCheck,
    NetWMFullscreen,
    NetActiveWindow,
    NetWMWindowType,
    NetWMWindowTypeDialog,
    NetClientList,
    NetLast
}; /* EWMH atoms */

enum {
    WMProtocols,
    WMDelete,
    WMState,
    WMTakeFocus,
    WMLast
}; /* default atoms */

enum {
    ClkTagBar,
    ClkLtSymbol,
    ClkStatusText,
    ClkWinTitle,
    ClkClientWin,
    ClkRootWin,
    ClkLast
}; /* clicks */

#endif
