# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)


# Project

project(SA_Maths)

message("SA_Maths Main directory: ${CMAKE_CURRENT_SOURCE_DIR}")



# Outputs

### Setup output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)		# .exe
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .lib / .a
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .dll / .so



# Library

## Input.
file(GLOB_RECURSE SA_MATHS_SOURCES "Source/*")

## Static library.
add_library(SA_Maths STATIC ${SA_MATHS_SOURCES})


## Link dependencies.
### Add SA Logger if added to CMake build tree.
if(TARGET SA_Logger)
	target_link_libraries(SA_Maths PUBLIC SA_Logger)
endif()


## Include directories

target_include_directories(SA_Maths PUBLIC Include)
target_include_directories(SA_Maths PRIVATE Include/SA)


## Compile features

### Standard
target_compile_features(SA_Maths PUBLIC c_std_11)
target_compile_features(SA_Maths PUBLIC cxx_std_20)

### SA_Maths module implementation preprocessor.
target_compile_definitions(SA_Maths PUBLIC SA_MATHS_IMPL)

### Continuous integration preprocessor.
if(SA_CI)
	target_compile_definitions(SA_Maths PUBLIC SA_CI)
endif()



# Options

if(NOT TARGET SA_Logger)

	## Add local SA_Logger.
	option(SA_MATHS_LOCAL_LOGGER_OPT "Should clone local SA_Logger" OFF)

	if(SA_MATHS_LOCAL_LOGGER_OPT)

		# Fetch SA_Logger.
		message("Fetching SA_Logger...")

		include(FetchContent)

		FetchContent_Declare(
			SA_Logger
			GIT_REPOSITORY https://github.com/SapphireSuite/Logger.git
			GIT_TAG        main
		)

		FetchContent_MakeAvailable(SA_Logger)

		target_link_libraries(SA_Maths PUBLIC SA_Logger)

	endif()

endif()


## Add SA_Maths's intrinsics implementation.
option(SA_MATHS_INTRINSICS_OPT "Should build using intrinsics" OFF)

if(SA_MATHS_INTRINSICS_OPT)

	target_compile_definitions(SA_Maths PUBLIC SA_MATHS_INTRINSICS_OPT)

	# Fetch SA_Support.
	if(NOT TARGET SA_Support)

		message("Fetching SA_Support...")

		include(FetchContent)

		FetchContent_Declare(
			SA_Support
			GIT_REPOSITORY https://github.com/SapphireSuite/Support.git
			GIT_TAG        main
		)

		FetchContent_MakeAvailable(SA_Support)

	endif()

	SA_SetupIntrinsicsFlags(SA_Maths PUBLIC)

	### Add SA Support.
	target_link_libraries(SA_Maths PUBLIC SA_Support)

endif()


## Add SA_Maths's tests to build tree.
option(SA_MATHS_BUILD_TESTS_OPT "Should build SA_Maths tests" OFF)


## Add SA_Maths's benchmark to build tree.
option(SA_MATHS_BUILD_BENCHMARK_OPT "Should build SA_Maths benchmark" OFF)



# Entrypoints

if(SA_MATHS_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()
