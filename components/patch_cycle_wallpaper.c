#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wordexp.h>

#include "patch_cycle_wallpaper.h"

#include "../other_conf/wallpapers.h"
#include "main_util.h"

volatile int wallpaper_index = 0;

void set_wallpaper(void)
{
    const char *wall = wallpapers[wallpaper_index];
    wordexp_t w      = {0};
    wordexp(wall, &w, WRDE_NOCMD);

    pid_t p = fork();
    if (p < 0)
        die("fork(): failed to create process to change wallpaper\n");

    if (p == 0) {
        char *const a[5] = {
            "feh", "--no-fehbg", "--bg-scale", w.we_wordv[0], NULL
        };
        execvp(*a, a);
        exit(errno);
    }

    wordfree(&w);
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
