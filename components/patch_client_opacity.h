#ifndef PATCH_CLIENT_OPACITY_H
#define PATCH_CLIENT_OPACITY_H

#include "main_un_structs.h"

extern void changefocusopacity(Arg* arg);
extern void changeunfocusopacity(Arg* arg);
extern void opacity(Client* c, double opacity);

#endif /*PATCH_CLIENT_OPACITY_H*/

#ifdef PATCH_CLIENT_OPACITY_IMPL_H

void opacity(Client* c, double opacity)
{
    if (opacity > 0.0f && opacity < 1.0f)
    {
        unsigned long real_opacity[] = { opacity * 0xffffffff };
        XChangeProperty(dpy, c->win, netatom[NetWMWindowsOpacity], XA_CARDINAL,
                        32, PropModeReplace, (unsigned char*)real_opacity, 1);
    }
    else
    {
        XDeleteProperty(dpy, c->win, netatom[NetWMWindowsOpacity]);
    }
}

void changefocusopacity(Arg* arg)
{
    if (!selmon->sel)
        return;
    selmon->sel->opacity += arg->f;
    if (selmon->sel->opacity > 1.0)
        selmon->sel->opacity = 1.0;

    if (selmon->sel->opacity < 0.1)
        selmon->sel->opacity = 0.1;

    opacity(selmon->sel, selmon->sel->opacity);
}

void changeunfocusopacity(Arg* arg)
{
    if (!selmon->sel)
        return;
    selmon->sel->unfocusopacity += arg->f;
    if (selmon->sel->unfocusopacity > 1.0)
        selmon->sel->unfocusopacity = 1.0;

    if (selmon->sel->unfocusopacity < 0.1)
        selmon->sel->unfocusopacity = 0.1;

    opacity(selmon->sel, selmon->sel->unfocusopacity);
}

#endif /*PATCH_CLIENT_OPACITY_IMPL_H*/
