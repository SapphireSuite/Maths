# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_MathsBenchmark)



# Fetch Google Benchmark
include(FetchContent)

message("Fetching Google Benchmark...")

FetchContent_Declare(
	googlebenchmark
	GIT_REPOSITORY https://github.com/google/benchmark.git
	GIT_TAG        v1.6.0
)

FetchContent_MakeAvailable(googlebenchmark)



# Executable

## Inputs

file(GLOB_RECURSE SA_MATHS_BENCHMARK_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_MathsBenchmark ${SA_MATHS_BENCHMARK_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_MathsBenchmark PRIVATE SA_Maths)

### Google test module dependency.
target_link_libraries(SA_MathsBenchmark PRIVATE benchmark::benchmark)
