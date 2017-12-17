cmake_minimum_required(VERSION 3.5.1)
project (strings)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(benchmark REQUIRED)

# set up include directories
include_directories(include)

file(GLOB_RECURSE ALL_STRINGS_CPP src/*_strings.cpp)

# create benchmarks
set(BENCHMARK_CPP src/benchmark.cpp)
set(UNITTEST_CPP test/unittest.cpp)
foreach(ONE_STRINGS_CPP ${ALL_STRINGS_CPP})
    get_filename_component(ONE_BENCH_EXEC ${ONE_STRINGS_CPP} NAME_WE)

    # Avoid name collision 
    set(BENCH_NAME Bench_${ONE_BENCH_EXEC})
    set(TEST_NAME Test_${ONE_BENCH_EXEC})
    set(LIB_NAME Lib_${ONE_BENCH_EXEC})

    # create library
    add_library(${LIB_NAME} STATIC ${ONE_STRINGS_CPP})

    # create benchmark
    add_executable(${BENCH_NAME} ${BENCHMARK_CPP})
    target_link_libraries(${BENCH_NAME} ${LIB_NAME} ${CMAKE_THREAD_LIBS_INIT} benchmark)

    # create test
    add_executable(${TEST_NAME} ${UNITTEST_CPP})
    target_link_libraries(${TEST_NAME} ${LIB_NAME} ${CMAKE_THREAD_LIBS_INIT} gtest gtest_main)
    add_test(${TEST_NAME} ${TEST_NAME})
endforeach()
