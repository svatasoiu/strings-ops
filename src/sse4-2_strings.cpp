#include "strings.hpp"

namespace strings 
{

size_t strlen(const char *s) {
    size_t len;
    __asm__ volatile("mov  $-16, %%rax;"
                     "mov  %1, %%rdx;"
                     "pxor %%xmm0, %%xmm0;"
                     "STRLEN_LOOP:;"
                        "add        $16, %%rax;"
                        "pcmpistri  $0b1000, (%%rdx, %%rax, 1), %%xmm0;"
                        "jnz        STRLEN_LOOP;"
                     "add %%rcx, %%rax;"
                     "mov %%rax, %0;"
                     :"=r"(len)         /* output */
                     :"r"(s)            /* input */
                     :"%rax", "%rdx", "%xmm0"  /* clobbered register */);
    return len;
}

char *strcpy(char *dest, const char *src)
{
    throw "Function not yet implemented";
}

}