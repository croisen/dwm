#ifndef DWM_LAYOUTS_H
#define DWM_LAYOUTS_H

#include "../components/main_un_structs.h"
#include "../dwm.h"

/* layout(s) */
const float mfact        = 0.50; /* factor of master area size [0.05..0.95] */
const int nmaster        = 1;    /* number of clients in master area */
const int resizehints    = 1; /* 1 means respect size hints in tiled resizals */
const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

const Layout layouts[]   = {
  /* symbol     arrange function */
    {"TILED", tile   }, /* first entry is default */
    {"FLOAT", NULL   }, /* no layout function means floating behavior */
    {"[M]",   monocle},
};

#endif // DWM_LAYOUTS_H
