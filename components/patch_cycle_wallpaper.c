#include <stdlib.h>
#include <string.h>

#include "patch_cycle_wallpaper.h"

#include "../dwm-funcs.h"
#include "../other_conf/wallpapers.h"
#include "main_macros.h"
#include "main_util.h"

char main_cmd[]     = "feh --bg-scale --no-fehbg ";
int wallpaper_index = 0;

void set_wallpaper(void)
{
    const char *wall = wallpapers[wallpaper_index];
    char *cmd = ecalloc(sizeof(main_cmd) + strlen(wall) + 1, sizeof(char));
    if (cmd == NULL) {
        return;
    }

    strcpy(cmd, main_cmd);
    strcat(cmd, wall);

    Arg arg = SHCMD(cmd);
    spawn(&arg);
    free(cmd);
}

void cycle_wallpaper_forward(Arg *arg)
{
    (void)arg;
    long int size   = sizeof(wallpapers) / sizeof(wallpapers[0]);

    wallpaper_index = (wallpaper_index + 1) % size;
    set_wallpaper();
}

void cycle_wallpaper_backward(Arg *arg)
{
    (void)arg;
    long int size   = sizeof(wallpapers) / sizeof(wallpapers[0]);

    wallpaper_index = (wallpaper_index + size - 1) % size;
    set_wallpaper();
}
