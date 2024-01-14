#ifndef CROI_DWM_CMDS_H
#define CROI_DWM_CMDS_H

#include "main_un_structs.h"

extern const Arg down_vol;
extern const Arg raise_vol;
extern const Arg mute_vol;
extern const Arg max_vol;
extern const Arg zero_vol;
extern const Arg dimmer;
extern const Arg bright;
extern const Arg scrot;
extern const Arg termcmd;
extern const Arg thunar;
extern const Arg spotify;
extern const Arg firefox;

#endif /*CROI_DWM_CMDS_H*/

#ifdef CROI_DWM_CMDS_IMPL_H

const Arg down_vol = SHCMD(
    "wpctl set-volume @DEFAULT_SINK@ 2%- && kill -USR1 $(pgrep slstatus)");
const Arg raise_vol = SHCMD(
    "wpctl set-volume @DEFAULT_SINK@ 2%+ && kill -USR1 $(pgrep slstatus)");
const Arg mute_vol = SHCMD(
    "wpctl set-mute @DEFAULT_SINK@ toggle && kill -USR1 $(pgrep slstatus)");
const Arg max_vol = SHCMD(
    "wpctl set-volume @DEFAULT_SINK@ 100% && kill -USR1 $(pgrep slstatus)");
const Arg zero_vol = SHCMD(
    "wpctl set-volume @DEFAULT_SINK@ 0% && kill -USR1 $(pgrep slstatus)");

const Arg dimmer = SHCMD("xbacklight - 5%");
const Arg bright = SHCMD("xbacklight + 5%");

const Arg scrot  = SHCMD("scrot ~/Pictures/'Screenshot_%Y-%m-%d_%H_%M_%S.png'");

const Arg termcmd = SHCMD("kitty");
const Arg thunar  = SHCMD("thunar");
const Arg spotify = SHCMD("LD_PRELOAD=/usr/lib/spotify-adblock.so spotify");
const Arg firefox = SHCMD("firefox");

#endif /*CROI_DWM_CMDS_IMPL_H*/
