#include "patch_maximize.h"

#include "../dwm-funcs.h"

extern int borderpx;

static void maximize(int x, int y, int w, int h)
{
    XEvent ev;

    if (!selmon->sel || selmon->sel->isfixed)
        return;

    XRaiseWindow(dpy, selmon->sel->win);
    if (!selmon->sel->ismax) {
        if (!selmon->lt[selmon->sellt]->arrange || selmon->sel->isfloating)
            selmon->sel->wasfloating = True;
        else {
            togglefloating(NULL);
            selmon->sel->wasfloating = False;
        }
        selmon->sel->oldx = selmon->sel->x;
        selmon->sel->oldy = selmon->sel->y;
        selmon->sel->oldw = selmon->sel->w;
        selmon->sel->oldh = selmon->sel->h;
        resize(selmon->sel, x, y, w, h, True);
        selmon->sel->ismax = True;
    } else {
        resize(
            selmon->sel, selmon->sel->oldx, selmon->sel->oldy,
            selmon->sel->oldw, selmon->sel->oldh, True
        );
        if (!selmon->sel->wasfloating)
            togglefloating(NULL);
        selmon->sel->ismax = False;
    }
    drawbar(selmon);
    while (XCheckMaskEvent(dpy, EnterWindowMask, &ev))
        ;
}

void togglemaximize(Arg *arg)
{
    (void)arg;
    maximize(
        selmon->wx, selmon->wy, selmon->ww - 2 * borderpx,
        selmon->wh - 2 * borderpx
    );
}
