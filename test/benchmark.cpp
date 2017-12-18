#include <benchmark/benchmark.h>
#include <cstdint>
#include <cstring>
#include <type_traits>

#include "strings.hpp"

static const int ALIGN = 0x10;

template <typename T>
constexpr bool is_power_of_2(const T x) { 
    static_assert(std::is_arithmetic<T>::value, "T must be numeric");
    return ~(x & (x - 1)); 
}

static void BM_Strlen(benchmark::State& state) {
    static_assert(is_power_of_2(ALIGN), "alignment must be power of 2");

    const size_t size = state.range(0);
    const int offset = state.range(1);

    auto align_up = [](const char *ptr) { return (char *) (((uint64_t)ptr + ALIGN) & ~(ALIGN - 1)); };

    auto str = new char[size + 2 * ALIGN + 1];
    std::memset(str, 'a', size + 2 * ALIGN);
    auto offset_str = align_up(str) + offset;
    offset_str[size] = 0;

    for (auto _ : state) {
        benchmark::DoNotOptimize(strings::strlen(offset_str));
    }

    delete[] str;
}
BENCHMARK(BM_Strlen)->Ranges({{1, 1<<20}, {0, 15}});

static void BM_Strcpy(benchmark::State& state) {
    auto src = new char[state.range(0) + 1];
    auto dst = new char[state.range(0) + 1];
    std::memset(src, 'a', state.range(0));
    src[state.range(0)] = 0;

    for (auto _ : state) {
        benchmark::DoNotOptimize(strings::strcpy(dst, src));
    }

    delete[] src;
    delete[] dst;
}
BENCHMARK(BM_Strcpy)->RangeMultiplier(8)->Range(1, 1<<20);

BENCHMARK_MAIN();
