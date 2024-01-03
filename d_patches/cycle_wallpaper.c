#include "cycle_wallpaper.h"
#include "../components/macros.h"
#include "../dwm.h"
#include "../wallpapers.h"

#include <stdlib.h>
#include <string.h>

char main_cmd[]     = "feh --bg-scale --no-fehbg ";
int wallpaper_index = 0;

void set_wallpaper() {
    const char *wall = wallpapers[wallpaper_index];
    char *cmd = malloc((sizeof(main_cmd) + strlen(wall) + 1) * sizeof(char));

    strcpy(cmd, main_cmd);
    strcat(cmd, wall);

    Arg arg = SHCMD(cmd);
    spawn(&arg);
    free(cmd);
}

void cycle_wallpaper_forward(const Arg *arg) {
    (void)arg;
    long int size   = sizeof(wallpapers) / sizeof(wallpapers[0]);

    wallpaper_index = (wallpaper_index + 1) % size;
    set_wallpaper();
}

void cycle_wallpaper_backward(const Arg *arg) {
    (void)arg;
    long int size   = sizeof(wallpapers) / sizeof(wallpapers[0]);

    wallpaper_index = (wallpaper_index + size - 1) % size;
    set_wallpaper();
}
