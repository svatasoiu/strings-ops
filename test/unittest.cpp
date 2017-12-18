#include <cstring>
#include <memory>

#include "gtest/gtest.h"
#include "strings.hpp"

namespace {

// Tests strlen()
void test_strlen(const char *str) {
    EXPECT_EQ(std::strlen(str), strings::strlen(str));
}

TEST(StrlenTest, Correctness) {
    test_strlen("");
    test_strlen("abcd");
    test_strlen("123456789");

    const size_t big_size = 1 << 20;
    auto str = new char[big_size + 1];
    std::memset(str, 'a', big_size);
    str[big_size] = 0;
    test_strlen(str);
}

void test_strcpy(const char *str) {
    size_t len = std::strlen(str);
    auto dst_std = new char[len + 1];
    auto dst_test = new char[len + 1];

    std::strcpy(dst_std, str);
    strings::strcpy(dst_test, str);

    EXPECT_STREQ(dst_std, dst_test);
}

// Tests strlen()
TEST(StrcpyTest, Correctness) {
    test_strcpy("");
    test_strcpy("abcd");
    test_strcpy("123456789");

    const size_t big_size = 1 << 20;
    auto str = new char[big_size + 1];
    std::memset(str, 'a', big_size);
    str[big_size] = 0;
    test_strcpy(str);
}

}