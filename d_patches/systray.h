#ifndef ___DWM_6_4_SYSTRAY___
#define ___DWM_6_4_SYSTRAY___

#include "../components/u_structs.h"

#include <X11/Xlib.h>

unsigned int getsystraywidth();

void removesystrayicon(Client *i);
void resizebarwin(Monitor *m);
void resizerequest(XEvent *e);

int sendevent(Window w, Atom proto, int m, long d0, long d1, long d2, long d3,
              long d4);

Monitor *systraytomon(Monitor *m);

void updatesystray(void);
void updatesystrayicongeom(Client *i, int w, int h);
void updatesystrayiconstate(Client *i, XPropertyEvent *ev);

Client *wintosystrayicon(Window w);

#endif
