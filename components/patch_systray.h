#ifndef PATCH_SYSTRAY_H
#define PATCH_SYSTRAY_H

#include "main_un_structs.h"

#include <X11/Xlib.h>

unsigned int getsystraywidth();
void removesystrayicon(Client *i);
void resizebarwin(Monitor *m);
void resizerequest(XEvent *e);
Monitor *systraytomon(Monitor *m);
void updatesystray(void);
void updatesystrayicongeom(Client *i, int w, int h);
void updatesystrayiconstate(Client *i, XPropertyEvent *ev);
Client *wintosystrayicon(Window w);

#endif /*PATCH_SYSTRAY_H*/
