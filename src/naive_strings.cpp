#include "strings.hpp"

namespace strings 
{

size_t strlen(const char *s) 
{
    size_t len = 0;
    for (; *s != 0; ++len, ++s) ;
    return len;
}

char *strcpy(char *dest, const char *src)
{
    char *start = dest;
    for (; *src != 0; ++src, ++dest) 
        *dest = *src;
    *dest = 0;
    return start;
}

}