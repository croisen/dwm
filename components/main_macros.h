#ifndef DWM_MACROS_H
#define DWM_MACROS_H

#define BUTTONMASK (ButtonPressMask | ButtonReleaseMask)
#define CLEANMASK(mask)                                                        \
  (mask & ~(numlockmask | LockMask) &                                          \
   (ShiftMask | ControlMask | Mod1Mask | Mod2Mask | Mod3Mask | Mod4Mask |      \
    Mod5Mask))
#define INTERSECT(x, y, w, h, m)                                               \
  (MAX(0, MIN((x) + (w), (m)->wx + (m)->ww) - MAX((x), (m)->wx)) *             \
   MAX(0, MIN((y) + (h), (m)->wy + (m)->wh) - MAX((y), (m)->wy)))
#define ISVISIBLE(C) ((C->tags & C->mon->tagset[C->mon->seltags]))
#define HIDDEN(C) ((getstate(C->win) == IconicState))
#define LENGTH(X) (sizeof X / sizeof X[0])
#define MOUSEMASK (BUTTONMASK | PointerMotionMask)
#define WIDTH(X) ((X)->w + 2 * (X)->bw)
#define HEIGHT(X) ((X)->h + 2 * (X)->bw)
#define TAGMASK ((1 << LENGTH(tags)) - 1)
#define TEXTW(X) (drw_fontset_getwidth(drw, (X)) + lrpad)

#define VERSION "6.4"
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}}, {                      \
    MODKEY | ControlMask | ShiftMask, KEY, toggletag, { .ui = 1 << TAG }       \
  }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

#define SYSTEM_TRAY_REQUEST_DOCK 0

/* XEMBED messages */
#define XEMBED_EMBEDDED_NOTIFY 0
#define XEMBED_WINDOW_ACTIVATE 1
#define XEMBED_FOCUS_IN 4
#define XEMBED_MODALITY_ON 10
#define XEMBED_MAPPED (1 << 0)
#define XEMBED_WINDOW_ACTIVATE 1
#define XEMBED_WINDOW_DEACTIVATE 2
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define XEMBED_EMBEDDED_VERSION (VERSION_MAJOR << 16) | VERSION_MINOR

#endif /*DWM_MACROS_H*/
