# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.17)


# Project

project(SA_Maths)

message("SA_Maths Main directory: ${CMAKE_SOURCE_DIR}")



# Inputs

file(GLOB_RECURSE SA_MATHS_SOURCES "Source/*")



# Library

## Add Static library
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



# Options

## Add SA_Maths's tests to build tree.
option(SA_MATHS_BUILD_TESTS "Should build SA_Maths tests" OFF)



# Tests

### Enable testing for this directory and below.
enable_testing()



# Entrypoints

if(SA_MATHS_BUILD_TESTS)
	add_subdirectory(Tests)
endif()
