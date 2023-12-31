#ifndef ___DWM_6_4_CONFIG_H___
#define ___DWM_6_4_CONFIG_H___

#include "components/enums.h"
#include "components/macros.h"
#include "components/patch_comps/awesome_bar.h"
#include "components/patch_comps/cycle_wallpaper.h"
#include "components/patch_comps/self_restart.h"
#include "components/u_structs.h"
#include "dwm.h"

#include <X11/X.h>
#include <X11/XF86keysym.h>

/* appearance */
const unsigned int borderpx = 5; /* border pixel of windows */
const unsigned int gappx = 10;   /* window gaps */
const unsigned int snap = 32;    /* snap pixel */

const int showbar = 1; /* 0 means no bar */
const int topbar = 1;  /* 0 means bottom bar */

const char dmenufont[] = "monospace:size=9";
const char *fonts[] = {"monospace:size=9", "'MesloLGS Nerd Font':size=9",
                       "'Fira Code':style=Medium,Regular:size=9"};

const char col_gray1[] = "#222222"; /* bg col */
const char col_gray2[] = "#444444"; /* border col */
const char col_gray3[] = "#bbbbbb"; /* font col */
const char col_gray4[] = "#eeeeee"; /* tag & win title font col */
const char col_cyan[] = "#005577";  /* tag & win title bg col */

const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_cyan},
    [SchemeHov] = {col_gray4, col_cyan, col_cyan},
    [SchemeHid] = {col_cyan, col_gray1, col_cyan},
};

/* tagging */
const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
const float mfact = 0.55;     /* factor of master area size [0.05..0.95] */
const int nmaster = 1;        /* number of clients in master area */
const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* commands */
char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};

const char *mute_vol[] = {"wpctl", "set-mute", "@DEFAULT_SINK@", "toggle",
                          NULL};
const char *raise_vol[] = {"wpctl", "set-volume", "@DEFAULT_SINK@", "2%+",
                           NULL};
const char *down_vol[] = {"wpctl", "set-volume", "@DEFAULT_SINK@", "2%-", NULL};

const char *termcmd[] = {"kitty", NULL};
const char *firefox[] = {"firefox", NULL};

const Key keys[] = {
    /* modifier                     key        function        argument */
    {0, XK_Print, spawn,
     SHCMD("scrot ~/Pictures/'Screenshot_%Y-%m-%d_%H_%M_%S.png'")},

    {MODKEY, XK_c | XK_w, cycle_wallpaper_forward, {0}},
    {MODKEY | ShiftMask, XK_c | XK_w, cycle_wallpaper_backward, {0}},

    {0, XF86XK_AudioMute, spawn, {.v = mute_vol}},
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = raise_vol}},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = down_vol}},

    {ALTKEY, XK_b, spawn, {.v = firefox}},

    {MODKEY, XK_r, spawn, {.v = dmenucmd}},
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstackvis, {.i = +1}},
    {MODKEY, XK_k, focusstackvis, {.i = -1}},
    {MODKEY | ShiftMask, XK_j, focusstackhid, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, focusstackhid, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY, XK_s, show, {0}},
    {MODKEY | ShiftMask, XK_s, showall, {0}},
    {MODKEY | ShiftMask, XK_h, hide, {0}},
    TAGKEYS(XK_1, 0),
    TAGKEYS(XK_2, 1),
    TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3),
    TAGKEYS(XK_5, 4),
    TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6),
    TAGKEYS(XK_8, 7),
    TAGKEYS(XK_9, 8),
    {MODKEY | ShiftMask, XK_r, self_restart, {0}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button1, togglewin, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};

#endif
