#include "patch_restart_sig.h"
#include "../dwm-funcs.h"
#include "main_un_structs.h"

void some_sighup(int unused)
{
    (void)unused;
    Arg arg = {
        .i = 1,
    };

    quit(&arg);
}

void some_sigterm(int unused)
{
    (void)unused;
    Arg arg = {
        .i = 1,
    };

    quit(&arg);
}
