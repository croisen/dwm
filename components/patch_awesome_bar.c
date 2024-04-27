#include "patch_awesome_bar.h"
#include "../dwm-funcs.h"

void focusstackvis(Arg *arg)
{
    focusstack(arg->i, 0);
}

void focusstackhid(Arg *arg)
{
    focusstack(arg->i, 1);
}

void show(Arg *arg)
{
    if (selmon->hidsel)
        selmon->hidsel = 0;
    showwin(selmon->sel);
}

void showall(Arg *arg)
{
    Client *c      = NULL;
    selmon->hidsel = 0;
    for (c = selmon->clients; c; c = c->next)
    {
        if (ISVISIBLE(c))
            showwin(c);
    }
    if (!selmon->sel)
    {
        for (c = selmon->clients; c && !ISVISIBLE(c); c = c->next)
            ;
        if (c)
            focus(c);
    }
    restack(selmon);
}

void showwin(Client *c)
{
    if (!c || !HIDDEN(c))
        return;

    XMapWindow(dpy, c->win);
    setclientstate(c, NormalState);
    arrange(c->mon);
}

void showhide(Client *c)
{
    if (!c)
        return;
    if (ISVISIBLE(c))
    {
        /* show clients top down */
        XMoveWindow(dpy, c->win, c->x, c->y);
        if ((!c->mon->lt[c->mon->sellt]->arrange || c->isfloating) &&
            !c->isfullscreen)
            resize(c, c->x, c->y, c->w, c->h, 0);
        showhide(c->snext);
    }
    else
    {
        /* hide clients bottom up */
        showhide(c->snext);
        XMoveWindow(dpy, c->win, WIDTH(c) * -2, c->y);
    }
}
