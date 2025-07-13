#ifndef DWM_KEYS_H
#define DWM_KEYS_H

#include <X11/X.h>
#include <X11/XF86keysym.h>

#include "../components/main_enums.h"
#include "../components/main_macros.h"
#include "../components/main_un_structs.h"
#include "../components/patch_actual_fullscreen.h"
#include "../components/patch_awesome_bar.h"
#include "../components/patch_client_opacity.h"
#include "../components/patch_cycle_wallpaper.h"
#include "../components/patch_maximize.h"
#include "../components/patch_rotate_stack.h"

#include "../dwm-funcs.h"
#include "commands.h"
#include "layouts.h"

Key keys[] = {
    /* modifier                     key        function        argument */
    {ALTKEY,               XK_b,                     spawn,                    firefox      },
    {ALTKEY,               XK_e,                     spawn,                    thunar       },
    {ALTKEY,               XK_m,                     spawn,                    spotify      },
    {ALTKEY,               XK_w,                     cycle_wallpaper_forward,  {0}          },
    {ALTKEY | ShiftMask,   XK_w,                     cycle_wallpaper_backward, {0}          },

    {0,                    XK_Print,                 spawn,                    scrot        },

    {0,                    XF86XK_AudioMute,         spawn,                    mute_vol     },
    {0,                    XF86XK_AudioRaiseVolume,  spawn,                    raise_vol    },
    {ShiftMask,            XF86XK_AudioRaiseVolume,  spawn,                    max_vol      },
    {0,                    XF86XK_AudioLowerVolume,  spawn,                    down_vol     },
    {ShiftMask,            XF86XK_AudioLowerVolume,  spawn,                    zero_vol     },
    {0,                    XF86XK_AudioPlay,         spawn,                    s_play       },
    {0,                    XF86XK_AudioStop,         spawn,                    s_stop       },
    {0,                    XF86XK_AudioPrev,         spawn,                    s_prev       },
    {0,                    XF86XK_AudioNext,         spawn,                    s_next       },

    {0,                    XF86XK_MonBrightnessUp,   spawn,                    bright       },
    {0,                    XF86XK_MonBrightnessDown, spawn,                    dimmer       },

    {MODKEY | ControlMask, XK_o,                     changefocusopacity,       {.f = +0.025}},
    {MODKEY | ShiftMask,   XK_o,                     changefocusopacity,       {.f = -0.025}},
    {MODKEY | ControlMask, XK_u,                     changeunfocusopacity,     {.f = +0.025}},
    {MODKEY | ShiftMask,   XK_u,                     changeunfocusopacity,     {.f = -0.025}},

    {MODKEY,               XK_r,                     spawn,                    rofi_drun    },
    {MODKEY | ShiftMask,   XK_r,                     spawn,                    rofi_run     },
    {MODKEY | ShiftMask,   XK_Return,                spawn,                    termcmd      },
    {MODKEY,               XK_b,                     togglebar,                {0}          },

    /* People might get confused by this decision */
    {MODKEY,               XK_j,                     focusstackhid,            {.i = -1}    },
    {MODKEY,               XK_k,                     focusstackhid,            {.i = +1}    },
    {MODKEY | ShiftMask,   XK_j,                     rotatestack,              {.i = -1}    },
    {MODKEY | ShiftMask,   XK_k,                     rotatestack,              {.i = +1}    },

    {MODKEY,               XK_i,                     incnmaster,               {.i = +1}    },
    {MODKEY,               XK_d,                     incnmaster,               {.i = -1}    },
    {MODKEY,               XK_h,                     setmfact,                 {.f = -0.05} },
    {MODKEY,               XK_l,                     setmfact,                 {.f = +0.05} },
    {MODKEY,               XK_Return,                zoom,                     {0}          },
    {MODKEY,               XK_Tab,                   view,                     {0}          },
    {MODKEY | ShiftMask,   XK_c,                     killclient,               {0}          },

    //     {MODKEY,               XK_m,                     setlayout, {.v =
    //     &layouts[0]}}, {MODKEY,               XK_t, setlayout, {.v =
    //     &layouts[1]}}, {MODKEY,               XK_f, setlayout, {.v =
    //     &layouts[2]}},
    {MODKEY,               XK_f,                     togglefullscr,            {0}          },
    {MODKEY,               XK_m,                     togglemaximize,           {0}          },
    {MODKEY,               XK_space,                 setlayout,                {0}          },

    {MODKEY | ShiftMask,   XK_space,                 togglefloating,           {0}          },
    {MODKEY,               XK_0,                     view,                     {.ui = ~0}   },
    {MODKEY | ShiftMask,   XK_0,                     tag,                      {.ui = ~0}   },
    {MODKEY,               XK_comma,                 focusmon,                 {.i = -1}    },
    {MODKEY,               XK_period,                focusmon,                 {.i = +1}    },
    {MODKEY | ShiftMask,   XK_comma,                 tagmon,                   {.i = -1}    },
    {MODKEY | ShiftMask,   XK_period,                tagmon,                   {.i = +1}    },
    {MODKEY,               XK_s,                     show,                     {0}          },
    {MODKEY | ShiftMask,   XK_s,                     showall,                  {0}          },
    {MODKEY | ShiftMask,   XK_h,                     hide,                     {0}          },
    TAGKEYS(XK_1, 0),
    TAGKEYS(XK_2, 1),
    TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3),
    TAGKEYS(XK_5, 4),
    TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6),
    TAGKEYS(XK_8, 7),
    TAGKEYS(XK_9, 8),
    {MODKEY | ShiftMask,   XK_q,                     quit,                     {0}          },
    {MODKEY | ControlMask, XK_r,                     quit,                     {1}          },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
Button buttons[] = {
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

#endif // DWM_KEYS_H
