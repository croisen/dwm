#ifndef CROI_PATCH_CYCLE_WALLPAPER_H
#define CROI_PATCH_CYCLE_WALLPAPER_H

#include "wallpapers.h"

#include "main_un_structs.h"

extern void set_wallpaper();
extern void cycle_wallpaper_forward(Arg *arg);
extern void cycle_wallpaper_backward(Arg *arg);

#endif /*CROI_PATCH_CYCLE_WALLPAPER_H*/

#ifdef CROI_PATCH_CYCLE_WALLPAPER_IMPL_H

char main_cmd[]     = "feh --bg-scale --no-fehbg ";
int wallpaper_index = 0;

void set_wallpaper()
{
    const char *wall = wallpapers[wallpaper_index];
    char *cmd = malloc((sizeof(main_cmd) + strlen(wall) + 1) * sizeof(char));
    if (cmd == NULL)
    {
        // malloc didn't return a thing
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

#endif /*CROI_PATCH_CYCLE_WALLPAPER_IMPL_H*/
