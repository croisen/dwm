#ifndef DWM_ENUMS_H
#define DWM_ENUMS_H

enum
{
    CurNormal,
    CurResize,
    CurMove,
    CurLast
}; /* cursor */

enum
{
    SchemeNorm,
    SchemeSel,
    SchemeHov,
    SchemeHid
}; /* color schemes */

enum
{
    NetSupported,
    NetWMName,
    NetWMState,
    NetWMCheck,
    NetWMFullscreen,
    NetSystemTray,
    NetSystemTrayOP,
    NetSystemTrayOrientation,
    NetSystemTrayOrientationHorz,
    NetActiveWindow,
    NetWMWindowsOpacity,
    NetWMWindowType,
    NetWMWindowTypeDialog,
    NetClientList,
    NetLast
}; /* EWMH atoms */

enum
{
    WMProtocols,
    WMDelete,
    WMState,
    WMTakeFocus,
    WMLast
}; /* default atoms */

enum
{
    ClkTagBar,
    ClkLtSymbol,
    ClkStatusText,
    ClkWinTitle,
    ClkClientWin,
    ClkRootWin,
    ClkLast
}; /* clicks */

enum
{
    Manager,
    Xembed,
    XembedInfo,
    XLast
};

#endif /*DWM_ENUMS_H*/
