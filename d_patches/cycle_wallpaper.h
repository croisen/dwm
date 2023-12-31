#ifndef ___DWM_6_4_CYCLE_WALLS___
#define ___DWM_6_4_CYCLE_WALLS___

#include "../components/u_structs.h"

extern int wallpaper_index;

void set_wallpaper();
void cycle_wallpaper_forward(const Arg *arg);
void cycle_wallpaper_backward(const Arg *arg);

#endif
