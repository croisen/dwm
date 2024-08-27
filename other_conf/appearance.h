#ifndef DWM_APPEARANCE_H
#define DWM_APPEARANCE_H

#include "../components/main_enums.h"

/* appearance */
static const unsigned int borderpx       = 5;  /* border pixel of windows */
static const unsigned int gappx          = 10; /* window gaps */
static const unsigned int snap           = 32; /* snap pixel */

/* Window opacity when it's focused (0 <= opacity <= 1) */
static const double activeopacity        = 0.75f;
/* Window opacity when it's inactive (0 <= opacity <= 1) */
static const double inactiveopacity      = 1.00f;

/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systraypinning = 0;
/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayonleft  = 1;

static const unsigned int systrayspacing = 2; /* systray spacing */

/*
 * 1: if pinning fails, display systray on the first monitor, False: display
 * systray on the last monitor
 */
static const int systraypinningfailfirst = 1;
static const int showsystray             = 1; /* 0 means no systray */

static const int showbar                 = 1; /* 0 means no bar */
static const int topbar                  = 1; /* 0 means bottom bar */

// Default colors and fonts?
static const char dmenufont[]            = "monospace:size=7";
static const char *fonts[]               = {
    "monospace:size=7",
    "MesloLGS Nerd Font:size=7",
    "Fira Code:style=Medium,Regular:size=7",
};
static const char col_gray1[]  = "#222222"; /* bg col */
static const char col_gray2[]  = "#444444"; /* border col */
static const char col_gray3[]  = "#bbbbbb"; /* font col */
static const char col_gray4[]  = "#eeeeee"; /* tag & win title font col */
static const char col_cyan[]   = "#005577"; /* tag & win title bg col */
static const char *colors[][3] = {
  /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel]  = {col_gray4, col_cyan,  col_cyan },
    [SchemeHid]  = {col_cyan,  col_gray1, col_cyan },
};

// Windows 3.11 theme patch
// static const char *fonts[]               = {
//"Fixedsys Excelsior:size=13:antialias=true:autohint=false"};
// static const char dmenufont[] =
//"Fixedsys Excelsior:size=13:antialias=true:autohint=false";
// static const char col_gray1[]  = "#d3d7cf";
// static const char col_gray2[]  = "#d3d7cf";
// static const char col_gray3[]  = "#000000";
// static const char col_gray4[]  = "#ffffff";
// static const char col_cyan[]   = "#0000aa";
// static const char *colors[][3] = {
//[>               fg         bg         border   <]
//[SchemeNorm] = {col_gray3, col_gray1, col_cyan },
//[SchemeSel]  = {col_gray4, col_cyan,  col_gray2},
//[SchemeHid]  = {col_cyan,  col_gray1, col_cyan },
//};
// This ain't a part of the patch tho the schemehid I mean

#endif // DWM_APPEARANCE_H
