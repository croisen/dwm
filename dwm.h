#ifndef DWM_H
#define DWM_H

#include "components/main_un_structs.h"

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

extern void applyrules(Client* c);
extern int applysizehints(Client* c, int* x, int* y, int* w, int* h,
                          int interact);
extern void arrange(Monitor* m);
extern void arrangemon(Monitor* m);
extern void attach(Client* c);
extern void attachstack(Client* c);
extern void buttonpress(XEvent* e);
extern void checkotherwm(void);
extern void cleanup(void);
extern void cleanupmon(Monitor* mon);
extern void clientmessage(XEvent* e);
extern void configure(Client* c);
extern void configurenotify(XEvent* e);
extern void configurerequest(XEvent* e);
extern Monitor* createmon(void);
extern void destroynotify(XEvent* e);
extern void detach(Client* c);
extern void detachstack(Client* c);
extern Monitor* dirtomon(int dir);
extern void drawbar(Monitor* m);
extern void drawbars(void);
extern void enternotify(XEvent* e);
extern void expose(XEvent* e);
extern void focus(Client* c);
extern void focusin(XEvent* e);
extern void focusmon(Arg* arg);
extern void focusstack(int inc, int vis);
extern Atom getatomprop(Client* c, Atom prop);
extern int getrootptr(int* x, int* y);
extern long getstate(Window w);
extern int gettextprop(Window w, Atom atom, char* text, unsigned int size);
extern void grabbuttons(Client* c, int focused);
extern void grabkeys(void);
extern void incnmaster(Arg* arg);
extern void keypress(XEvent* e);
extern void killclient(Arg* arg);
extern void manage(Window w, XWindowAttributes* wa);
extern void mappingnotify(XEvent* e);
extern void maprequest(XEvent* e);
extern void monocle(Monitor* m);
extern void motionnotify(XEvent* e);
extern void movemouse(Arg* arg);
extern Client* nexttiled(Client* c);
extern void pop(Client* c);
extern void propertynotify(XEvent* e);
extern void quit(Arg* arg);
extern Monitor* recttomon(int x, int y, int w, int h);
extern void resize(Client* c, int x, int y, int w, int h, int interact);
extern void resizeclient(Client* c, int x, int y, int w, int h);
extern void resizemouse(Arg* arg);
extern void restack(Monitor* m);
extern void run(void);
extern void runautostart(void);
extern void scan(void);
// extern int sendevent(Client *c, Atom proto);
extern void sendmon(Client* c, Monitor* m);
extern void setclientstate(Client* c, long state);
extern void setfocus(Client* c);
extern void setfullscreen(Client* c, int fullscreen);
extern void setlayout(Arg* arg);
extern void setmfact(Arg* arg);
extern void setup(void);
extern void seturgent(Client* c, int urg);
extern void spawn(Arg* arg);
extern void tag(Arg* arg);
extern void tagmon(Arg* arg);
extern void tile(Monitor* m);
extern void togglebar(Arg* arg);
extern void togglefloating(Arg* arg);
extern void toggletag(Arg* arg);
extern void toggleview(Arg* arg);
extern void togglewin(Arg* arg);
extern void unfocus(Client* c, int setfocus);
extern void unmanage(Client* c, int destroyed);
extern void unmapnotify(XEvent* e);
extern void updatebarpos(Monitor* m);
extern void updatebars(void);
extern void updateclientlist(void);
extern int updategeom(void);
extern void updatenumlockmask(void);
extern void updatesizehints(Client* c);
extern void updatestatus(void);
extern void updatetitle(Client* c);
extern void updatewindowtype(Client* c);
extern void updatewmhints(Client* c);
extern void view(Arg* arg);
extern Client* wintoclient(Window w);
extern Monitor* wintomon(Window w);
extern int xerror(Display* dpy, XErrorEvent* ee);
extern int xerrordummy(Display* dpy, XErrorEvent* ee);
extern int xerrorstart(Display* dpy, XErrorEvent* ee);
extern void zoom(Arg* arg);

#endif /*DWM_H*/
