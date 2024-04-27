#ifndef PATCH_AWESOME_BAR_H
#define PATCH_AWESOME_BAR_H

#include "main_un_structs.h"

void focusstackvis(Arg *arg);
void focusstackhid(Arg *arg);
void hide(Arg *arg);
void hidewin(Client *c);

void show(Arg *arg);
void showall(Arg *arg);
void showhide(Client *c);
void showwin(Client *c);

#endif /*PATCH_AWESOME_BAR_H*/
