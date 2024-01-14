#ifndef PATCH_RESTART_SIG_H
#define PATCH_RESTART_SIG_H

extern void some_sighup(int unused);
extern void some_sigterm(int unused);

#endif /*PATCH_RESTART_SIG_H*/

#ifdef PATCH_RESTART_SIG_IMPL_H

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

#endif /*PATCH_RESTART_SIG_IMPL_H*/
