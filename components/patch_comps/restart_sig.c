#include "restart_sig.h"
#include "../../dwm.h"

void some_sighup(int unused) {
    (void)unused;
    Arg arg = {
        .i = 1,
    };

    quit(&arg);
}

void some_sigterm(int unused) {
    (void)unused;
    Arg arg = {
        .i = 1,
    };

    quit(&arg);
}
