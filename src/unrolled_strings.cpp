#include <cstdint>

#include "strings.hpp"

namespace strings 
{

size_t strlen(const char *s) {
    size_t len = 0;

    while (!((((*(uint64_t *)s) - 0x0101010101010101ULL) 
           & ~(*(uint64_t *)s) & 0x8080808080808080ULL)))
    {
        s += 8;
        len += 8;
    }

    while (*s++ && ++len)
       ;

    return len;
}

// from https://codereview.stackexchange.com/questions/30337/x86-strcpy-implementation
char * strcpy(char * dst, const char * src)
{
    char * origin = dst;

    while (!((((*(uint64_t *)src) - 0x0101010101010101ULL) 
           & ~(*(uint64_t *)src) & 0x8080808080808080ULL)))
    {
        *(uint64_t *)dst = *(uint64_t *)src;
        src += 8;
        dst += 8;
    }

    while (*dst++ = *src++)
       ;

    return origin;
}

}