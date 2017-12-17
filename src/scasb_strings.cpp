#include <cstdint>

#include "strings.hpp"

namespace strings 
{

size_t strlen(const char *s) {
    size_t len;
    __asm__ volatile("xor %%al, %%al;"
                     "xor %%rcx, %%rcx;"
                     "not %%rcx;"
                     "mov %1, %%rdi;"
                     "cld;"
                     "repnz scasb;" 
                     "not %%rcx;"
                     "dec %%rcx;"
                     "mov %%rcx, %0;"
                     :"=r"(len)         /* output */
                     :"r"(s)            /* input */
                     :"%rdi", "%al", "%rcx"  /* clobbered register */);
    return len;
}

char * strcpy(char * dst, const char * src)
{
    throw "Function not yet implemented";
}

}