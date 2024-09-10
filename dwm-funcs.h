#ifndef DWM_H
#define DWM_H

#include <X11/Xatom.h>
#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <errno.h>
#include <locale.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#ifdef XINERAMA
#include <X11/extensions/Xinerama.h>
#endif

#include "components/main_drw.h"
#include "components/main_enums.h"
#include "components/main_macros.h"
#include "components/main_un_structs.h"

/* variables */
extern const char broken[];
extern char stext[256];
extern int screen;
extern int sw, sh; /* X display screen geometry width, height */
extern int bh;     /* bar height */
extern int lrpad;  /* sum of left and right padding for text */
extern int (*xerrorxlib)(Display *, XErrorEvent *);
extern unsigned int numlockmask;
extern Systray *systray;
extern Atom wmatom[WMLast], netatom[NetLast], xatom[XLast];
extern int restart;
extern int running;
extern Cur *cursor[CurLast];
extern Clr **scheme;
extern Display *dpy;
extern Drw *drw;
extern Monitor *mons, *selmon;
extern Window root, wmcheckwin;
extern void (*handler[LASTEvent])(XEvent *);

void applyrules(Client *c);
int applysizehints(Client *c, int *x, int *y, int *w, int *h, int interact);
void arrange(Monitor *m);
void arrangemon(Monitor *m);
void attach(Client *c);
void attachstack(Client *c);
void buttonpress(XEvent *e);
void checkotherwm(void);
void cleanup(void);
void cleanupmon(Monitor *mon);
void clientmessage(XEvent *e);
void configure(Client *c);
void configurenotify(XEvent *e);
void configurerequest(XEvent *e);
Monitor *createmon(void);
void destroynotify(XEvent *e);
void detach(Client *c);
void detachstack(Client *c);
Monitor *dirtomon(int dir);
void drawbar(Monitor *m);
void drawbars(void);
void enternotify(XEvent *e);
void expose(XEvent *e);
void focus(Client *c);
void focusin(XEvent *e);
void focusmon(Arg *arg);
void focusstack(int inc, int vis);
Atom getatomprop(Client *c, Atom prop);
int getrootptr(int *x, int *y);
long getstate(Window w);
int gettextprop(Window w, Atom atom, char *text, unsigned int size);
void grabbuttons(Client *c, int focused);
void grabkeys(void);
void incnmaster(Arg *arg);
void keypress(XEvent *e);
void killclient(Arg *arg);
void manage(Window w, XWindowAttributes *wa);
void mappingnotify(XEvent *e);
void maprequest(XEvent *e);
void monocle(Monitor *m);
void motionnotify(XEvent *e);
void movemouse(Arg *arg);
Client *nexttiled(Client *c);
void pop(Client *c);
void propertynotify(XEvent *e);
void quit(Arg *arg);
Monitor *recttomon(int x, int y, int w, int h);
void resize(Client *c, int x, int y, int w, int h, int interact);
void resizeclient(Client *c, int x, int y, int w, int h);
void resizemouse(Arg *arg);
void restack(Monitor *m);
void run(void);
void scan(void);
// int sendevent(Client *c, Atom proto);
int sendevent(Window w, Atom proto, int m, long d0, long d1, long d2, long d3,
              long d4);
void sendmon(Client *c, Monitor *m);
void setclientstate(Client *c, long state);
void setfocus(Client *c);
void setfullscreen(Client *c, int fullscreen);
void setlayout(Arg *arg);
void setmfact(Arg *arg);
void setup(void);
void seturgent(Client *c, int urg);
void spawn(Arg *arg);
void tag(Arg *arg);
void tagmon(Arg *arg);
void tile(Monitor *m);
void togglebar(Arg *arg);
void togglefloating(Arg *arg);
void toggletag(Arg *arg);
void toggleview(Arg *arg);
void togglewin(Arg *arg);
void unfocus(Client *c, int setfocus);
void unmanage(Client *c, int destroyed);
void unmapnotify(XEvent *e);
void updatebarpos(Monitor *m);
void updatebars(void);
void updateclientlist(void);
int updategeom(void);
void updatenumlockmask(void);
void updatesizehints(Client *c);
void updatestatus(void);
void updatetitle(Client *c);
void updatewindowtype(Client *c);
void updatewmhints(Client *c);
void view(Arg *arg);
Client *wintoclient(Window w);
Monitor *wintomon(Window w);
int xerror(Display *dpy, XErrorEvent *ee);
int xerrordummy(Display *dpy, XErrorEvent *ee);
int xerrorstart(Display *dpy, XErrorEvent *ee);
void zoom(Arg *arg);
#endif /*DWM_H*/
