#ifndef DWM_WINDOW_RULES_H
#define DWM_WINDOW_RULES_H

#include "../components/main_un_structs.h"
#include "./appearance.h"

#include <stdlib.h>

const Rule rules[] = {
  /* xprop(1):
  *	WM_CLASS(STRING) = instance, class
  *	WM_NAME(STRING) = title
  */

  /* class  instance  title  tags  mask  isfloating  focusopacity
  unfocusedopacity  monitor */
    {"kitty",        NULL, NULL, 1 << 0, 0, activeopacity,   activeopacity,   -1},

    {"discord",      NULL, NULL, 1 << 1, 0, inactiveopacity, inactiveopacity, -1},

    {"feh",          NULL, NULL, 1 << 2, 0, inactiveopacity, inactiveopacity, -1},
    {"Eog",          NULL, NULL, 1 << 2, 0, inactiveopacity, inactiveopacity, -1},
    {"Thunar",       NULL, NULL, 1 << 2, 0, inactiveopacity, inactiveopacity, -1},

    {"libreoffice",  NULL, NULL, 1 << 3, 0, inactiveopacity, inactiveopacity,
     -1                                                                         },
    {"Gimp",         NULL, NULL, 1 << 3, 0, inactiveopacity, inactiveopacity, -1},

    {"obs",          NULL, NULL, 1 << 4, 0, inactiveopacity, inactiveopacity, -1},
    {"Virt-manager", NULL, NULL, 1 << 4, 0, inactiveopacity, inactiveopacity,
     -1                                                                         },

    {"qprompt",      NULL, NULL, 1 << 5, 0, inactiveopacity, inactiveopacity, -1},

    {"steam",        NULL, NULL, 1 << 6, 0, inactiveopacity, inactiveopacity, -1},

    {"Audacious",    NULL, NULL, 1 << 7, 0, activeopacity,   inactiveopacity, -1},
    {"Spotify",      NULL, NULL, 1 << 7, 0, activeopacity,   inactiveopacity, -1},

    {"firefox",      NULL, NULL, 1 << 8, 0, inactiveopacity, inactiveopacity, -1},
};

#endif // DWM_WINDOW_RULES_H
