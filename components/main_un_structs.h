#ifndef DWM_UNION_N_STRUCTS_H
#define DWM_UNION_N_STRUCTS_H

#include <X11/X.h>

typedef union {
    int i;
    unsigned int ui;
    float f;
    const void *v;
} Arg;

typedef struct {
    unsigned int click;
    unsigned int mask;
    unsigned int button;
    void (*func)(Arg *arg);
    Arg arg;
} Button;

typedef struct Monitor Monitor;
typedef struct Client Client;

struct Client {
    char name[256];
    float mina, maxa;
    int x, y, w, h;
    int oldx, oldy, oldw, oldh;
    int basew, baseh, incw, inch, maxw, maxh, minw, minh, hintsvalid;
    int bw, oldbw;
    unsigned int tags;
    int ismax, wasfloating, isfixed, isfloating, isurgent, neverfocus, oldstate,
        isfullscreen;
    double opacity, unfocusopacity;
    Client *next;
    Client *snext;
    Monitor *mon;
    Window win;
};

typedef struct {
    unsigned int mod;
    KeySym keysym;
    void (*func)(Arg *);
    Arg arg;
} Key;

typedef struct {
    const char *symbol;
    void (*arrange)(Monitor *);
} Layout;

struct Monitor {
    char ltsymbol[16];
    float mfact;
    int nmaster;
    int num;
    int by;             /* bar geometry */
    int btw;            /* width of tasks portion of bar */
    int bt;             /* number of tasks */
    int mx, my, mw, mh; /* screen size */
    int wx, wy, ww, wh; /* window area  */
    unsigned int seltags;
    unsigned int sellt;
    unsigned int tagset[2];
    int showbar;
    int topbar;
    int hidsel;
    Client *clients;
    Client *sel;
    Client *stack;
    Monitor *next;
    Window barwin;
    const Layout *lt[2];
};

typedef struct {
    const char *class_name;
    const char *instance;
    const char *title;
    unsigned int tags;
    int isfloating;
    double opacity, unfocusopacity;
    int monitor;
} Rule;

typedef struct {
    Window win;
    Client *icons;
} Systray;

#endif /*DWM_UNION_N_STRUCTS_H*/
