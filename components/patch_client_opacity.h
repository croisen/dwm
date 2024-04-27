#ifndef PATCH_CLIENT_OPACITY_H
#define PATCH_CLIENT_OPACITY_H

#include "main_un_structs.h"

void changefocusopacity(Arg *arg);
void changeunfocusopacity(Arg *arg);
void opacity(Client *c, double opacity);

#endif /*PATCH_CLIENT_OPACITY_H*/
