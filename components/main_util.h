#ifndef DWM_UTIL_H
#define DWM_UTIL_H

#include <stdlib.h>

#define MAX(A, B)        ((A) > (B) ? (A) : (B))
#define MIN(A, B)        ((A) < (B) ? (A) : (B))
#define BETWEEN(X, A, B) ((A) <= (X) && (X) <= (B))

extern void die(const char* fmt, ...);
extern void* ecalloc(size_t nmemb, size_t size);

#endif /*DWM_UTIL_H*/

#ifdef DWM_UTIL_IMPL_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void die(const char* fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    if (fmt[0] && fmt[strlen(fmt) - 1] == ':')
    {
        fputc(' ', stderr);
        perror(NULL);
    }
    else
    {
        fputc('\n', stderr);
    }

    exit(1);
}

void* ecalloc(size_t nmemb, size_t size)
{
    void* p;

    if (!(p = calloc(nmemb, size)))
        die("calloc:");
    return p;
}

#endif /*DWM_UTIL_IMPL_H*/
