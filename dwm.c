/* See LICENSE file for copyright and license details.
 *
 * dynamic window manager is designed like any other X client as well. It is
 * driven through handling X events. In contrast to other X clients, a window
 * manager selects for SubstructureRedirectMask on the root window, to receive
 * events about window (dis-)appearance. Only one X connection at a time is
 * allowed to select for this event mask.
 *
 * The event handlers of dwm are organized in an array which is accessed
 * whenever a new event has been fetched. This allows event dispatching
 * in O(1) time.
 *
 * Each child of the root window is called a client, except windows which have
 * set the override_redirect flag. Clients are organized in a linked client
 * list on each monitor, the focus history is remembered through a stack list
 * on each monitor. Each client contains a bit array to indicate the tags of a
 * client.
 *
 * Keys and tagging rules are organized as arrays and defined in config.h.
 *
 * To understand everything else, start reading main().
 */

#include "config.h"

#define DWM_IMPL_H
#include "dwm.h"

#define DWM_DRW_IMPL_H
#define DWM_UTIL_IMPL_H

#define PATCH_AUTOSTART_IMPL_H
#define PATCH_AWESOME_BAR_IMPL_H
#define PATCH_CLIENT_OPACITY_IMPL_H
#define PATCH_RESTART_SIG_IMPL_H
#define PATCH_ROTATE_STACK_IMPL_H
#define PATCH_SYSTRAY_IMPL_H

#define CROI_PATCH_CYCLE_WALLPAPER_IMPL_H

#include "components/main_drw.h"
#include "components/main_macros.h"
#include "components/main_util.h"

#include "components/patch_autostart.h"
#include "components/patch_awesome_bar.h"
#include "components/patch_client_opacity.h"
#include "components/patch_cycle_wallpaper.h"
#include "components/patch_restart_sig.h"
#include "components/patch_rotate_stack.h"
#include "components/patch_systray.h"

#include <X11/Xatom.h>
#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <locale.h>
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

/* compile-time check if all tags fit into an unsigned int bit array. */
struct NumTags
{
    char limitexceeded[LENGTH(tags) > 31 ? -1 : 1];
};

int main(int argc, char *argv[])
{
    if (argc == 2 && !strcmp("-v", argv[1]))
        die("dwm-" VERSION);
    else if (argc != 1)
        die("usage: dwm [-v]");
    if (!setlocale(LC_CTYPE, "") || !XSupportsLocale())
        fputs("warning: no locale support\n", stderr);
    if (!(dpy = XOpenDisplay(NULL)))
        die("dwm: cannot open display");
    checkotherwm();
    setup();
#ifdef __OpenBSD__
    if (pledge("stdio rpath proc exec", NULL) == -1)
        die("pledge");
#endif /* __OpenBSD__ */
    scan();
    runautostart();
    set_wallpaper();
    run();

    if (restart)
    {
        execvp(argv[0], argv);
    }

    cleanup();
    XCloseDisplay(dpy);
    return EXIT_SUCCESS;
}
