#include <cstring>

#include "strings.hpp"

namespace strings 
{

size_t strlen(const char *s) {
    return std::strlen(s);
}

char *strcpy(char *dest, const char *src) {
    return std::strcpy(dest, src);
}

}