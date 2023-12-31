#ifndef ___DWM_6_4_UTIL_H___
#define ___DWM_6_4_UTIL_H___

#include <stdlib.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define BETWEEN(X, A, B) ((A) <= (X) && (X) <= (B))

void die(const char *fmt, ...);
void *ecalloc(size_t nmemb, size_t size);

#endif
