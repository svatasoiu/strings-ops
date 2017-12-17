#include <cstdint>

#include "strings.hpp"

namespace strings 
{

size_t strlen(const char *s) {
    size_t len = 0;
    for(;;) {
        uint64_t x = *(uint64_t*)s;
        if((x & 0xFF) == 0) return len;
        if((x & 0xFF00) == 0) return len + 1;
        if((x & 0xFF0000) == 0) return len + 2;
        if((x & 0xFF000000) == 0) return len + 3;
        if((x & 0xFF00000000) == 0) return len + 4;
        if((x & 0xFF0000000000) == 0) return len + 5;
        if((x & 0xFF000000000000) == 0) return len + 6;
        if((x & 0xFF00000000000000) == 0) return len + 7;
        s += 8, len += 8;
    }
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