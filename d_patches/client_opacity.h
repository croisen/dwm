#ifndef ___DWM_6_4_CLIENT_OPACITY___
#define ___DWM_6_4_CLIENT_OPACITY___

#include "../components/u_structs.h"

void changefocusopacity(const Arg *arg);
void changeunfocusopacity(const Arg *arg);
void opacity(Client *c, double opacity);

#endif
