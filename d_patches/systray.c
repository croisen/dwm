#include "systray.h"
#include "../components/drw.h"
#include "../components/enums.h"
#include "../components/macros.h"
#include "../components/u_structs.h"
#include "../components/util.h"
#include "../dwm.h"

#include <stdlib.h>

extern int bh, lrpad;
extern char stext[];

extern const unsigned int systraypinning;
extern const unsigned int systrayonleft;
extern const unsigned int systrayspacing;
extern const int systraypinningfailfirst;
extern const int showsystray;

extern Atom netatom[NetLast], xatom[XLast];
extern Display *dpy;
extern Monitor *mons, *selmon;
extern Systray *systray;
extern Window root;

extern Clr **scheme;
extern Drw *drw;

unsigned int getsystraywidth() {
    unsigned int w = 0;
    Client *i;
    if (showsystray)
        for (i = systray->icons; i; i = i->next) {
            w += i->w + systrayspacing;
        }

    return w ? w + systrayspacing : 1;
}

void removesystrayicon(Client *i) {
    Client **ii;

    if (!showsystray || !i)
        return;
    for (ii = &systray->icons; *ii && *ii != i; ii = &(*ii)->next)
        ;
    if (ii)
        *ii = i->next;
    free(i);
}

void resizebarwin(Monitor *m) {
    unsigned int w = m->ww;
    if (showsystray && m == systraytomon(m) && !systrayonleft)
        w -= getsystraywidth();
    XMoveResizeWindow(dpy, m->barwin, m->wx, m->by, w, bh);
}

void resizerequest(XEvent *e) {
    XResizeRequestEvent *ev = &e->xresizerequest;
    Client *i;

    if ((i = wintosystrayicon(ev->window))) {
        updatesystrayicongeom(i, ev->width, ev->height);
        resizebarwin(selmon);
        updatesystray();
    }
}

void updatesystrayicongeom(Client *i, int w, int h) {
    if (i) {
        i->h = bh;
        if (w == h)
            i->w = bh;
        else if (h == bh)
            i->w = w;
        else
            i->w = (int)((float)bh * ((float)w / (float)h));
        applysizehints(i, &(i->x), &(i->y), &(i->w), &(i->h), False);
        /* force icons into the systray dimensions if they don't want to */
        if (i->h > bh) {
            if (i->w == i->h)
                i->w = bh;
            else
                i->w = (int)((float)bh * ((float)i->w / (float)i->h));
            i->h = bh;
        }
    }
}

void updatesystrayiconstate(Client *i, XPropertyEvent *ev) {
    long flags;
    int code = 0;

    if (!showsystray || !i || ev->atom != xatom[XembedInfo] ||
        !(flags = getatomprop(i, xatom[XembedInfo])))
        return;

    if (flags & XEMBED_MAPPED && !i->tags) {
        i->tags = 1;
        code    = XEMBED_WINDOW_ACTIVATE;
        XMapRaised(dpy, i->win);
        setclientstate(i, NormalState);
    } else if (!(flags & XEMBED_MAPPED) && i->tags) {
        i->tags = 0;
        code    = XEMBED_WINDOW_DEACTIVATE;
        XUnmapWindow(dpy, i->win);
        setclientstate(i, WithdrawnState);
    } else
        return;
    sendevent(i->win, xatom[Xembed], StructureNotifyMask, CurrentTime, code, 0,
              systray->win, XEMBED_EMBEDDED_VERSION);
}

void updatesystray(void) {
    XSetWindowAttributes wa;
    XWindowChanges wc;
    Client *i;
    Monitor *m      = systraytomon(NULL);
    unsigned int x  = m->mx + m->mw;
    unsigned int sw = TEXTW(stext) - lrpad + systrayspacing;
    unsigned int w  = 1;

    if (!showsystray)
        return;
    if (systrayonleft)
        x -= sw + lrpad / 2;
    if (!systray) {
        /* init systray */
        if (!(systray = (Systray *)calloc(1, sizeof(Systray))))
            die("fatal: could not malloc() %u bytes\n", sizeof(Systray));
        systray->win  = XCreateSimpleWindow(dpy, root, x, m->by, w, bh, 0, 0,
                                            scheme[SchemeSel][ColBg].pixel);
        wa.event_mask = ButtonPressMask | ExposureMask;
        wa.override_redirect = True;
        wa.background_pixel  = scheme[SchemeNorm][ColBg].pixel;
        XSelectInput(dpy, systray->win, SubstructureNotifyMask);
        XChangeProperty(dpy, systray->win, netatom[NetSystemTrayOrientation],
                        XA_CARDINAL, 32, PropModeReplace,
                        (unsigned char *)&netatom[NetSystemTrayOrientationHorz],
                        1);
        XChangeWindowAttributes(dpy, systray->win,
                                CWEventMask | CWOverrideRedirect | CWBackPixel,
                                &wa);
        XMapRaised(dpy, systray->win);
        XSetSelectionOwner(dpy, netatom[NetSystemTray], systray->win,
                           CurrentTime);
        if (XGetSelectionOwner(dpy, netatom[NetSystemTray]) == systray->win) {
            sendevent(root, xatom[Manager], StructureNotifyMask, CurrentTime,
                      netatom[NetSystemTray], systray->win, 0, 0);
            XSync(dpy, False);
        } else {
            fprintf(stderr, "dwm: unable to obtain system tray.\n");
            free(systray);
            systray = NULL;
            return;
        }
    }
    for (w = 0, i = systray->icons; i; i = i->next) {
        /* make sure the background color stays the same */
        wa.background_pixel = scheme[SchemeNorm][ColBg].pixel;
        XChangeWindowAttributes(dpy, i->win, CWBackPixel, &wa);
        XMapRaised(dpy, i->win);
        w    += systrayspacing;
        i->x  = w;
        XMoveResizeWindow(dpy, i->win, i->x, 0, i->w, i->h);
        w += i->w;
        if (i->mon != m)
            i->mon = m;
    }
    w  = w ? w + systrayspacing : 1;
    x -= w;
    XMoveResizeWindow(dpy, systray->win, x, m->by, w, bh);
    wc.x          = x;
    wc.y          = m->by;
    wc.width      = w;
    wc.height     = bh;
    wc.stack_mode = Above;
    wc.sibling    = m->barwin;
    XConfigureWindow(dpy, systray->win,
                     CWX | CWY | CWWidth | CWHeight | CWSibling | CWStackMode,
                     &wc);
    XMapWindow(dpy, systray->win);
    XMapSubwindows(dpy, systray->win);
    /* redraw background */
    XSetForeground(dpy, drw->gc, scheme[SchemeNorm][ColBg].pixel);
    XFillRectangle(dpy, systray->win, drw->gc, 0, 0, w, bh);
    XSync(dpy, False);
}

Client *wintosystrayicon(Window w) {
    Client *i = NULL;

    if (!showsystray || !w)
        return i;
    for (i = systray->icons; i && i->win != w; i = i->next)
        ;
    return i;
}

Monitor *systraytomon(Monitor *m) {
    Monitor *t;
    int i, n;
    if (!systraypinning) {
        if (!m)
            return selmon;
        return m == selmon ? m : NULL;
    }
    for (n = 1, t = mons; t && t->next; n++, t = t->next)
        ;
    for (i = 1, t = mons; t && t->next && i < systraypinning; i++, t = t->next)
        ;
    if (systraypinningfailfirst && n < systraypinning)
        return mons;
    return t;
}
