#ifndef PATCH_ROTATE_STACK_H
#define PATCH_ROTATE_STACK_H

#include "main_un_structs.h"

extern void enqueue(Client* c);
extern void enqueuestack(Client* c);
extern void rotatestack(Arg* arg);

#endif /*PATCH_ROTATE_STACK_H*/

#ifdef PATCH_ROTATE_STACK_IMPL_H

void enqueue(Client* c)
{
    Client* l;
    for (l = c->mon->clients; l && l->next; l = l->next)
        ;
    if (l)
    {
        l->next = c;
        c->next = NULL;
    }
}

void enqueuestack(Client* c)
{
    Client* l;
    for (l = c->mon->stack; l && l->snext; l = l->snext)
        ;
    if (l)
    {
        l->snext = c;
        c->snext = NULL;
    }
}

void rotatestack(Arg* arg)
{
    Client *c = NULL, *f;

    if (!selmon->sel)
        return;
    f = selmon->sel;
    if (arg->i > 0)
    {
        for (c = nexttiled(selmon->clients); c && nexttiled(c->next);
             c = nexttiled(c->next))
            ;
        if (c)
        {
            detach(c);
            attach(c);
            detachstack(c);
            attachstack(c);
        }
    }
    else
    {
        if ((c = nexttiled(selmon->clients)))
        {
            detach(c);
            enqueue(c);
            detachstack(c);
            enqueuestack(c);
        }
    }
    if (c)
    {
        arrange(selmon);
        // unfocus(f, 1);
        focus(f);
        restack(selmon);
    }
}

#endif /*PATCH_ROTATE_STACK_IMPL_H*/
