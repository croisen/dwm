#include "awesome_bar.h"
#include "../../dwm.h"

void focusstackvis(const Arg *arg) { focusstack(arg->i, 0); }
void focusstackhid(const Arg *arg) { focusstack(arg->i, 1); }
