# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.17)


# Project

project(SA_Maths)

message("SA_Maths Main directory: ${CMAKE_SOURCE_DIR}")



# Setup target

function(SA_Setup_Maths_Target mathsTarget)

	## Include directories

	target_include_directories(${mathsTarget} PUBLIC Include)
	target_include_directories(${mathsTarget} PRIVATE Include/SA)


	## Compile features

	### Standard
	target_compile_features(${mathsTarget} PUBLIC c_std_11)
	target_compile_features(${mathsTarget} PUBLIC cxx_std_20)

	### SA_Maths module implementation preprocessor.
	target_compile_definitions(${mathsTarget} PUBLIC SA_MATHS_IMPL)


endfunction()



# Library

## Input.
file(GLOB_RECURSE SA_MATHS_SOURCES "Source/*")

## Static library.
add_library(SA_Maths STATIC ${SA_MATHS_SOURCES})
SA_Setup_Maths_Target(SA_Maths)



# Options

## Add SA_Maths's tests to build tree.
option(SA_MATHS_BUILD_TESTS_OPT "Should build SA_Maths tests" OFF)



# Entrypoints

if(SA_MATHS_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()
