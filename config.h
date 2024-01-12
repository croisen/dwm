#ifndef ___DWM_6_4_CONFIG_H___
#define ___DWM_6_4_CONFIG_H___

#include "components/commands.h"
#include "components/enums.h"
#include "components/macros.h"
#include "components/u_structs.h"
#include "d_patches/awesome_bar.h"
#include "d_patches/client_opacity.h"
#include "d_patches/cycle_wallpaper.h"
#include "d_patches/maximize.h"
#include "d_patches/rotate_stack.h"
#include "dwm.h"

#include <X11/X.h>
#include <X11/XF86keysym.h>

/* appearance */
const unsigned int borderpx       = 5;  /* border pixel of windows */
const unsigned int gappx          = 10; /* window gaps */
const unsigned int snap           = 32; /* snap pixel */

/* Window opacity when it's focused (0 <= opacity <= 1) */
const double activeopacity        = 0.69f;
/* Window opacity when it's inactive (0 <= opacity <= 1) */
const double inactiveopacity      = 1.00f;

/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
const unsigned int systraypinning = 0;
/* 0: systray in the right corner, >0: systray on left of status text */
const unsigned int systrayonleft  = 1;

const unsigned int systrayspacing = 2; /* systray spacing */

/* 1: if pinning fails, display systray on the first monitor, False: display
 * systray on the last monitor*/
const int systraypinningfailfirst = 1;
const int showsystray             = 1; /* 0 means no systray */

const int showbar                 = 1; /* 0 means no bar */
const int topbar                  = 1; /* 0 means bottom bar */

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

// Win 3.11 Scheme {{
// const char col_gray1[]            = "#d3d7cf";
// const char col_gray2[]            = "#d3d7cf";
// const char col_gray3[]            = "#000000";
// const char col_gray4[]            = "#ffffff";
// const char col_cyan[]             = "#0000aa";

// const char *fonts[]               = {
//"Fixedsys Excelsior:size=13:antialias=true:autohint=false",
//};
// const char dmenufont[] =
//"Fixedsys Excelsior:size=13:antialias=true:autohint=false";
// }}

const char *colors[][3] = {
  /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel]  = {col_gray4, col_cyan,  col_cyan },
 //[SchemeNorm] = {col_gray3, col_gray1, col_cyan },
  //[SchemeSel]  = {col_gray4, col_cyan,  col_gray2},
    [SchemeHov]  = {col_gray4, col_cyan,  col_cyan },
    [SchemeHid]  = {col_cyan,  col_gray1, col_cyan },
};

/* tagging */
const char *tags[] = {"", "󰙯", "", "󰖴", "5",
                      "", "",  "", ""};

const Rule rules[] = {
  /* xprop(1):
  *	WM_CLASS(STRING) = instance, class
  *	WM_NAME(STRING) = title
  */

  /* class  instance  title  tags  mask  isfloating  focusopacity
  unfocusedopacity  monitor */
    {"kitty",   NULL, NULL, 1 << 0, 0, activeopacity,   activeopacity,   -1},
    {"discord", NULL, NULL, 1 << 1, 0, inactiveopacity, inactiveopacity, -1},
    {"feh",     NULL, NULL, 1 << 2, 0, inactiveopacity, inactiveopacity, -1},
    {"Eog",     NULL, NULL, 1 << 2, 0, inactiveopacity, inactiveopacity, -1},
    {"Thunar",  NULL, NULL, 1 << 2, 0, inactiveopacity, inactiveopacity, -1},
    {"qprompt", NULL, NULL, 1 << 5, 0, inactiveopacity, inactiveopacity, -1},
    {"steam",   NULL, NULL, 1 << 6, 0, inactiveopacity, inactiveopacity, -1},
    {"Spotify", NULL, NULL, 1 << 7, 0, activeopacity,   inactiveopacity, -1},
    {"firefox", NULL, NULL, 1 << 8, 0, inactiveopacity, inactiveopacity, -1},
};

/* layout(s) */
const float mfact        = 0.50; /* factor of master area size [0.05..0.95] */
const int nmaster        = 1;    /* number of clients in master area */
const int resizehints    = 1; /* 1 means respect size hints in tiled resizals */
const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

const Layout layouts[]   = {
  /* symbol     arrange function */
    {"TILED", tile   }, /* first entry is default */
    {"FLOAT", NULL   }, /* no layout function means floating behavior */
    {"[M]",   monocle},
};

/* commands */
char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};

const Key keys[] = {
  /* modifier                     key        function        argument */
    {ALTKEY,               XK_b,                     spawn,                    firefox           },
    {ALTKEY,               XK_e,                     spawn,                    thunar            },
    {ALTKEY,               XK_m,                     spawn,                    spotify           },
    {ALTKEY,               XK_w,                     cycle_wallpaper_forward,  {0}               },
    {ALTKEY | ShiftMask,   XK_w,                     cycle_wallpaper_backward, {0}               },

    {0,                    XK_Print,                 spawn,                    scrot             },

    {0,                    XF86XK_AudioMute,         spawn,                    mute_vol          },
    {0,                    XF86XK_AudioRaiseVolume,  spawn,                    raise_vol         },
    {ShiftMask,            XF86XK_AudioRaiseVolume,  spawn,                    max_vol           },
    {0,                    XF86XK_AudioLowerVolume,  spawn,                    down_vol          },
    {ShiftMask,            XF86XK_AudioLowerVolume,  spawn,                    zero_vol          },

    {0,                    XF86XK_MonBrightnessUp,   spawn,                    bright            },
    {0,                    XF86XK_MonBrightnessDown, spawn,                    dimmer            },

    {MODKEY | ControlMask, XK_h | XK_m,              togglehorizontalmax,      {0}               },
    {MODKEY | ControlMask, XK_v | XK_m,              toggleverticalmax,        {0}               },
    {MODKEY | ControlMask, XK_m,                     togglemaximize,           {0}               },

    {MODKEY | ControlMask, XK_o,                     changefocusopacity,       {.f = +0.025}     },
    {MODKEY | ShiftMask,   XK_o,                     changefocusopacity,       {.f = -0.025}     },
    {MODKEY | ControlMask, XK_u | XK_o,              changeunfocusopacity,     {.f = +0.025}     },
    {MODKEY | ShiftMask,   XK_u | XK_o,              changeunfocusopacity,     {.f = -0.025}     },

    {MODKEY,               XK_r,                     spawn,                    {.v = dmenucmd}   },
    {MODKEY | ShiftMask,   XK_Return,                spawn,                    termcmd           },
    {MODKEY,               XK_b,                     togglebar,                {0}               },

 /* People might get confused by this decision */
    {MODKEY,               XK_j,                     focusstackhid,            {.i = -1}         },
    {MODKEY,               XK_k,                     focusstackhid,            {.i = +1}         },
    {MODKEY | ShiftMask,   XK_j,                     rotatestack,              {.i = -1}         },
    {MODKEY | ShiftMask,   XK_k,                     rotatestack,              {.i = +1}         },

    {MODKEY,               XK_i,                     incnmaster,               {.i = +1}         },
    {MODKEY,               XK_d,                     incnmaster,               {.i = -1}         },
    {MODKEY,               XK_h,                     setmfact,                 {.f = -0.05}      },
    {MODKEY,               XK_l,                     setmfact,                 {.f = +0.05}      },
    {MODKEY,               XK_Return,                zoom,                     {0}               },
    {MODKEY,               XK_Tab,                   view,                     {0}               },
    {MODKEY | ShiftMask,   XK_c,                     killclient,               {0}               },
    {MODKEY,               XK_t,                     setlayout,                {.v = &layouts[0]}},
    {MODKEY,               XK_f,                     setlayout,                {.v = &layouts[1]}},
    {MODKEY,               XK_m,                     setlayout,                {.v = &layouts[2]}},
    {MODKEY,               XK_space,                 setlayout,                {0}               },
    {MODKEY | ShiftMask,   XK_space,                 togglefloating,           {0}               },
    {MODKEY,               XK_0,                     view,                     {.ui = ~0}        },
    {MODKEY | ShiftMask,   XK_0,                     tag,                      {.ui = ~0}        },
    {MODKEY,               XK_comma,                 focusmon,                 {.i = -1}         },
    {MODKEY,               XK_period,                focusmon,                 {.i = +1}         },
    {MODKEY | ShiftMask,   XK_comma,                 tagmon,                   {.i = -1}         },
    {MODKEY | ShiftMask,   XK_period,                tagmon,                   {.i = +1}         },
    {MODKEY,               XK_s,                     show,                     {0}               },
    {MODKEY | ShiftMask,   XK_s,                     showall,                  {0}               },
    {MODKEY | ShiftMask,   XK_h,                     hide,                     {0}               },
    TAGKEYS(XK_1, 0),
    TAGKEYS(XK_2, 1),
    TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3),
    TAGKEYS(XK_5, 4),
    TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6),
    TAGKEYS(XK_8, 7),
    TAGKEYS(XK_9, 8),
    {MODKEY | ShiftMask,   XK_q,                     quit,                     {0}               },
    {MODKEY | ShiftMask,   XK_r,                     quit,                     {1}               },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
const Button buttons[] = {
  /* click       event mask  button  function            argument */
    {ClkLtSymbol,   0,      Button1, setlayout,      {0}               },
    {ClkLtSymbol,   0,      Button3, setlayout,      {.v = &layouts[2]}},
    {ClkTagBar,     MODKEY, Button1, tag,            {0}               },
    {ClkTagBar,     MODKEY, Button3, toggletag,      {0}               },
    {ClkWinTitle,   0,      Button1, togglewin,      {0}               },
    {ClkWinTitle,   0,      Button2, zoom,           {0}               },
    {ClkStatusText, 0,      Button2, spawn,          termcmd           },
    {ClkClientWin,  MODKEY, Button1, movemouse,      {0}               },
    {ClkClientWin,  MODKEY, Button2, togglefloating, {0}               },
    {ClkClientWin,  MODKEY, Button3, resizemouse,    {0}               },
    {ClkTagBar,     0,      Button1, view,           {0}               },
    {ClkTagBar,     0,      Button3, toggleview,     {0}               },
    {ClkTagBar,     MODKEY, Button1, tag,            {0}               },
    {ClkTagBar,     MODKEY, Button3, toggletag,      {0}               },
};

#endif
