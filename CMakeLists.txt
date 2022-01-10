# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.17)


# Project

project(SA_Maths)

message("SA_Maths Main directory: ${CMAKE_SOURCE_DIR}")



# Outputs

### Setup output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)		# .exe
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Libs)	# .lib / .a
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Libs)	# .dll / .so



# Library

## Input.
file(GLOB_RECURSE SA_MATHS_SOURCES "Source/*")

## Static library.
add_library(SA_Maths STATIC ${SA_MATHS_SOURCES})

## Include directories

target_include_directories(SA_Maths PUBLIC Include)
target_include_directories(SA_Maths PRIVATE Include/SA)

## Compile features

### Standard
target_compile_features(SA_Maths PUBLIC c_std_11)
target_compile_features(SA_Maths PUBLIC cxx_std_20)

### SA_Maths module implementation preprocessor.
target_compile_definitions(SA_Maths PUBLIC SA_MATHS_IMPL)

## Link libraries

### Add SA Support.
target_link_libraries(SA_Maths PUBLIC SA_Support)



# Options

## Add SA_Maths's tests to build tree.
option(SA_MATHS_INTRINSICS_OPT "Should build using intrinsics" ON)

if(SA_MATHS_INTRINSICS_OPT)
	target_compile_definitions(SA_Maths PUBLIC SA_MATHS_INTRINSICS_OPT)
endif()

## Add SA_Maths's tests to build tree.
option(SA_MATHS_BUILD_TESTS_OPT "Should build SA_Maths tests" OFF)

## Add SA_Maths's tests to build tree.
option(SA_MATHS_BUILD_BENCHMARK_OPT "Should build SA_Maths benchmark" OFF)



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_MATHS_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()
