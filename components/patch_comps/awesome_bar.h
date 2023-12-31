#ifndef ___DWM_6_4_AWESOME_BAR___
#define ___DWM_6_4_AWESOME_BAR___

#include "../u_structs.h"

void focusstackvis(const Arg *arg);
void focusstackhid(const Arg *arg);
void hide(const Arg *arg);
void hidewin(Client *c);

void show(const Arg *arg);
void showall(const Arg *arg);
void showwin(Client *c);

#endif
