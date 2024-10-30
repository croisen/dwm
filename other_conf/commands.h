#ifndef DWM_COMMANDS_H
#define DWM_COMMANDS_H

#include "../components/main_macros.h"
#include "../components/main_un_structs.h"
#include "./appearance.h"

#include <stdlib.h>

/* commands */
char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
const char *dmenucmd[] = {"dmenu_run", "-m",  dmenumon,  "-fn",
                          dmenufont,   "-nb", col_gray1, "-nf",
                          col_gray3,   "-sb", col_cyan,  "-sf",
                          col_gray4,   NULL};

const Arg rofi_run     = SHCMD("rofi -show run");
const Arg rofi_drun    = SHCMD("rofi -show drun");

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

const Arg dimmer = SHCMD("xbacklight - 5%");
const Arg bright = SHCMD("xbacklight + 5%");

const Arg scrot  = SHCMD("scrot ~/Pictures/'Screenshot_%Y-%m-%d_%H_%M_%S.png'");

const Arg termcmd = SHCMD("kitty");
const Arg thunar  = SHCMD("thunar");
const Arg spotify = SHCMD("LD_PRELOAD=/usr/lib/spotify-adblock.so spotify");
const Arg firefox = SHCMD("firefox");

#endif // DWM_COMMANDS_H
