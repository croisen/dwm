/* See LICENSE file for copyright and license details. */

/* autostart */
const char autostartblocksh[]      = "autostart_blocking.sh";
const char autostartsh[]           = "autostart.sh";
const char dwmdir[]                = "dwm";
const char config_dir[]            = ".config";

/* appearance */
static const unsigned int borderpx = 2;  /* border pixel of windows */
static const unsigned int snap     = 32; /* snap pixel */
static const int showbar           = 1;  /* 0 means no bar */
static const int topbar            = 1;  /* 0 means bottom bar */

static const char *fonts[]         = {
    "monospace:size=7.5",
    "MesloLGS Nerd Font:size=7.5",
    "Fira Code:style=Medium,Regular:size=7.5",
};

static const char col_gray1[]  = "#222222";
static const char col_gray2[]  = "#444444";
static const char col_gray3[]  = "#bbbbbb";
static const char col_gray4[]  = "#eeeeee";
static const char col_cyan[]   = "#005577";
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel]  = {col_gray4, col_cyan,  col_cyan },
};

/* tagging */
const char *tags[]        = {"", "󰙯", "", "󰖴", "💻",
                             "", "",  "", ""};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"kitty",             NULL, NULL, 1 << 0, 0, -1},

    {"discord",           NULL, NULL, 1 << 1, 0, -1},
    {"vesktop",           NULL, NULL, 1 << 1, 0, -1},

    {"feh",               NULL, NULL, 1 << 2, 0, -1},
    {"Eog",               NULL, NULL, 1 << 2, 0, -1},
    {"Thunar",            NULL, NULL, 1 << 2, 0, -1},

    {"Gimp",              NULL, NULL, 1 << 3, 1, -1},
    {"libreoffice",       NULL, NULL, 1 << 3, 0, -1},
    {"soffice",           NULL, NULL, 1 << 3, 0, -1},

    {"obs",               NULL, NULL, 1 << 4, 0, -1},
    {"qprompt",           NULL, NULL, 1 << 4, 0, -1},
    {"thunderbird",       NULL, NULL, 1 << 4, 0, -1},
    {"Virt-manager",      NULL, NULL, 1 << 4, 0, -1},

    {"pavucontrol",       NULL, NULL, 1 << 5, 0, -1},

    {"steam",             NULL, NULL, 1 << 6, 0, -1},
    // EXCALIBURIAN !!
    {"steam_app_1739530", NULL, NULL, 1 << 6, 0, -1},
    // Toram Online
    {"steam_app_1827180", NULL, NULL, 1 << 6, 0, -1},

    {"Audacious",         NULL, NULL, 1 << 7, 0, -1},
    {"Spotify",           NULL, NULL, 1 << 7, 0, -1},

    {"Firefox",           NULL, NULL, 1 << 8, 0, -1},
    {"librewolf",         NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile   }, /* first entry is default */
    {"><>", NULL   }, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod1Mask
#define ALTKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
    {MODKEY, KEY, view, {.ui = 1 << TAG}},                                     \
        {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},             \
        {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                      \
    {                                                                          \
        MODKEY | ControlMask | ShiftMask, KEY, toggletag,                      \
        {                                                                      \
            .ui = 1 << TAG                                                     \
        }                                                                      \
    }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
    {                                                                          \
        .v = (const char *[])                                                  \
        {                                                                      \
            "/bin/sh", "-c", cmd, NULL                                         \
        }                                                                      \
    }

/* commands */
const char *rofi_run[]  = {"rofi", "-show", "run", NULL};
const char *rofi_drun[] = {"rofi", "-show", "drun", NULL};

const Arg down_vol =
    SHCMD("wpctl set-volume @DEFAULT_SINK@ 2%- && pkill -RTMIN+7 slstatus");
const Arg raise_vol =
    SHCMD("wpctl set-volume @DEFAULT_SINK@ 2%+ && pkill -RTMIN+7 slstatus");
const Arg mute_vol =
    SHCMD("wpctl set-mute @DEFAULT_SINK@ toggle && pkill -RTMIN+7 slstatus");
const Arg max_vol =
    SHCMD("wpctl set-volume @DEFAULT_SINK@ 100% && pkill -RTMIN+7 slstatus");
const Arg zero_vol =
    SHCMD("wpctl set-volume @DEFAULT_SINK@ 0% && pkill -RTMIN+7 slstatus");
const char *s_play[] = {"playerctl", "--all-players", "play-pause", NULL};
const char *s_stop[] = {"playerctl", "--all-players", "stop", NULL};
const char *s_prev[] = {"playerctl", "--all-players", "previous", NULL};
const char *s_next[] = {"playerctl", "--all-players", "next", NULL};

const char *dimmer[] = {"brightnessctl", "set", "5%-", NULL};
const char *bright[] = {"brightnessctl", "set", "+5%", NULL};

const Arg scrot = SHCMD("scrot ~/Pictures/'Screenshot_%Y-%m-%d_%H_%M_%S.png'");

const char *termcmd[] = {"kitty", NULL};
const char *thunar[]  = {"thunar", NULL};
const Arg spotify     = SHCMD("LD_PRELOAD=/usr/lib/spotify-adblock.so spotify");
const char *firefox[] = {"firefox", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {ALTKEY,               XK_b,                     spawn,          {.v = firefox}    },
    {ALTKEY,               XK_e,                     spawn,          {.v = thunar}     },
    {ALTKEY,               XK_m,                     spawn,          spotify           },

    {0,                    XK_Print,                 spawn,          scrot             },

    {0,                    XF86XK_AudioMute,         spawn,          mute_vol          },
    {0,                    XF86XK_AudioRaiseVolume,  spawn,          raise_vol         },
    {ShiftMask,            XF86XK_AudioRaiseVolume,  spawn,          max_vol           },
    {0,                    XF86XK_AudioLowerVolume,  spawn,          down_vol          },
    {ShiftMask,            XF86XK_AudioLowerVolume,  spawn,          zero_vol          },
    {0,                    XF86XK_AudioPlay,         spawn,          {.v = s_play}     },
    {0,                    XF86XK_AudioStop,         spawn,          {.v = s_stop}     },
    {0,                    XF86XK_AudioPrev,         spawn,          {.v = s_prev}     },
    {0,                    XF86XK_AudioNext,         spawn,          {.v = s_next}     },

    {0,                    XF86XK_MonBrightnessUp,   spawn,          {.v = bright}     },
    {0,                    XF86XK_MonBrightnessDown, spawn,          {.v = dimmer}     },

    {MODKEY,               XK_r,                     spawn,          {.v = rofi_drun}  },
    {MODKEY | ShiftMask,   XK_r,                     spawn,          {.v = rofi_run}   },
    {MODKEY | ShiftMask,   XK_Return,                spawn,          {.v = termcmd}    },
    {MODKEY,               XK_b,                     togglebar,      {0}               },

    {MODKEY,               XK_j,                     focusstack,     {.i = -1}         },
    {MODKEY,               XK_k,                     focusstack,     {.i = +1}         },
    {MODKEY,               XK_i,                     incnmaster,     {.i = +1}         },
    {MODKEY,               XK_d,                     incnmaster,     {.i = -1}         },
    {MODKEY,               XK_h,                     setmfact,       {.f = -0.05}      },
    {MODKEY,               XK_l,                     setmfact,       {.f = +0.05}      },
    {MODKEY,               XK_Return,                zoom,           {0}               },
    {MODKEY,               XK_Tab,                   view,           {0}               },
    {MODKEY | ShiftMask,   XK_c,                     killclient,     {0}               },

    {MODKEY,               XK_t,                     setlayout,      {.v = &layouts[0]}},
    {MODKEY,               XK_f,                     setlayout,      {.v = &layouts[1]}},
    {MODKEY,               XK_m,                     setlayout,      {.v = &layouts[2]}},

    {MODKEY,               XK_space,                 setlayout,      {0}               },
    {MODKEY | ShiftMask,   XK_space,                 togglefloating, {0}               },
    {MODKEY,               XK_0,                     view,           {.ui = ~0}        },
    {MODKEY | ShiftMask,   XK_0,                     tag,            {.ui = ~0}        },
    {MODKEY,               XK_comma,                 focusmon,       {.i = -1}         },
    {MODKEY,               XK_period,                focusmon,       {.i = +1}         },
    {MODKEY | ShiftMask,   XK_comma,                 tagmon,         {.i = -1}         },
    {MODKEY | ShiftMask,   XK_period,                tagmon,         {.i = +1}         },

    TAGKEYS(XK_1, 0),
    TAGKEYS(XK_2, 1),
    TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3),
    TAGKEYS(XK_5, 4),
    TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6),
    TAGKEYS(XK_8, 7),
    TAGKEYS(XK_9, 8),

    {MODKEY | ShiftMask,   XK_q,                     quit,           {0}               },
    {MODKEY | ControlMask, XK_r,                     quit,           {1}               },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol,   0,      Button1, setlayout,      {0}               },
    {ClkLtSymbol,   0,      Button3, setlayout,      {.v = &layouts[2]}},
    {ClkWinTitle,   0,      Button2, zoom,           {0}               },
    {ClkStatusText, 0,      Button2, spawn,          {.v = termcmd}    },
    {ClkClientWin,  MODKEY, Button1, movemouse,      {0}               },
    {ClkClientWin,  MODKEY, Button2, togglefloating, {0}               },
    {ClkClientWin,  MODKEY, Button3, resizemouse,    {0}               },
    {ClkTagBar,     0,      Button1, view,           {0}               },
    {ClkTagBar,     0,      Button3, toggleview,     {0}               },
    {ClkTagBar,     MODKEY, Button1, tag,            {0}               },
    {ClkTagBar,     MODKEY, Button3, toggletag,      {0}               },
};
