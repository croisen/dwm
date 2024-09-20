#include "patch_actual_fullscreen.h"

#include "../dwm-funcs.h"
#include "main_un_structs.h"

void togglefullscr(Arg *arg)
{
    (void)arg;
    if (selmon->sel)
        setfullscreen(selmon->sel, !selmon->sel->isfullscreen);
}
