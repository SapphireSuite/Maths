# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_MathsUT)



# Fetch Google Test.
include(FetchContent)

message("Fetching Google Test...")

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)



# Executable

## Inputs

file(GLOB_RECURSE SA_MATHS_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_MathsUT ${SA_MATHS_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_MathsUT PRIVATE SA_Maths_Test)

### Google test module dependency.
target_link_libraries(SA_MathsUT PRIVATE gtest)



# Tests

add_test(NAME CSA_MathsUT COMMAND SA_MathsUT)
