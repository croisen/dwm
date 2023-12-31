#ifndef ___DWM_6_4_COMMANDS___
#define ___DWM_6_4_COMMANDS___

#include <stdlib.h>

static const char *mute_vol[]  = {"wpctl", "set-mute", "@DEFAULT_SINK@",
                                  "toggle", NULL};
static const char *raise_vol[] = {"wpctl", "set-volume", "@DEFAULT_SINK@",
                                  "2%+", NULL};
static const char *down_vol[] = {"wpctl", "set-volume", "@DEFAULT_SINK@", "2%-",
                                 NULL};
static const char *dimmer[]   = {"xbacklight", "-", "5%", NULL};
static const char *bright[]   = {"xbacklight", "+", "5%", NULL};

static const char *termcmd[]  = {"kitty", NULL};
static const char *thunar[]   = {"thunar", NULL};
static const char *spotify[]  = {"LD_PRELOAD=/usr/lib/spotify-adblock.so",
                                 "spotify", NULL};
static const char *firefox[]  = {"firefox", NULL};

#endif
