#include <benchmark/benchmark.h>
#include <cstring>

#include "strings.hpp"

static void BM_Strlen(benchmark::State& state) {
    auto str = new char[state.range(0) + 1];
    std::memset(str, 'a', state.range(0));
    str[state.range(0)] = 0;

    for (auto _ : state) {
        benchmark::DoNotOptimize(strings::strlen(str));
    }

    delete[] str;
}
BENCHMARK(BM_Strlen)->RangeMultiplier(8)->Range(1, 1<<20);

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
