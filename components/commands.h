#ifndef ___DWM_6_4_COMMANDS___
#define ___DWM_6_4_COMMANDS___

#include "macros.h"
#include "u_structs.h"
#include <stdlib.h>

static const Arg mute_vol = SHCMD(
    "wpctl set-mute @DEFAULT_SINK@ toggle && kill -USR1 $(pgrep slstatus)");
static const Arg raise_vol = SHCMD(
    "wpctl set-volume @DEFAULT_SINK@ 2%+ && kill -USR1 $(pgrep slstatus)");
static const Arg down_vol = SHCMD(
    "wpctl set-volume @DEFAULT_SINK@ 2%- && kill -USR1 $(pgrep slstatus)");
static const Arg dimmer  = SHCMD("xbacklight - 5%");
static const Arg bright  = SHCMD("xbacklight + 5%");

static const Arg termcmd = SHCMD("kitty");
static const Arg thunar  = SHCMD("thunar");
static const Arg spotify =
    SHCMD("LD_PRELOAD=/usr/lib/spotify-adblock.so spotify");
static const Arg firefox = SHCMD("firefox");

#endif
