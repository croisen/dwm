#ifndef DWM_APPEARANCE_H
#define DWM_APPEARANCE_H

#include "../components/main_enums.h"

/* appearance */
const unsigned int borderpx       = 5;  /* border pixel of windows */
const unsigned int gappx          = 10; /* window gaps */
const unsigned int snap           = 32; /* snap pixel */

/* Window opacity when it's focused (0 <= opacity <= 1) */
const double activeopacity        = 0.75f;
/* Window opacity when it's inactive (0 <= opacity <= 1) */
const double inactiveopacity      = 1.00f;

/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
const unsigned int systraypinning = 0;
/* 0: systray in the right corner, >0: systray on left of status text */
const unsigned int systrayonleft  = 1;
const unsigned int systrayspacing = 2; /* systray spacing */

/*
 * 1: if pinning fails, display systray on the first monitor, False: display
 * systray on the last monitor
 */
const int systraypinningfailfirst = 1;
const int showsystray             = 1; /* 0 means no systray */

const int showbar                 = 1; /* 0 means no bar */
const int topbar                  = 1; /* 0 means bottom bar */

// Default colors and fonts?
const char dmenufont[]            = "monospace:size=7";
const char *fonts[]               = {
    "monospace:size=7",
    "MesloLGS Nerd Font:size=7",
    "Fira Code:style=Medium,Regular:size=7",
};
const char col_gray1[]  = "#222222"; /* bg col */
const char col_gray2[]  = "#444444"; /* border col */
const char col_gray3[]  = "#bbbbbb"; /* font col */
const char col_gray4[]  = "#eeeeee"; /* tag & win title font col */
const char col_cyan[]   = "#005577"; /* tag & win title bg col */
const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel]  = {col_gray4, col_cyan,  col_cyan },
    [SchemeHid]  = {col_cyan,  col_gray1, col_cyan },
};

#endif // DWM_APPEARANCE_H
