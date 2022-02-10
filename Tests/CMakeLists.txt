# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.


### Add Max warning level for tests.
if(MSVC)

	if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") # ClangCl

		target_compile_options(SA_Maths PUBLIC -W4)

	else()

		target_compile_options(SA_Maths PUBLIC /W4)

	endif()

else()

	target_compile_options(SA_Maths PUBLIC -Wall -Wextra)

endif()



# Options
option(SA_MATHS_TEST_LOGGER_INTEGRATION "Should build tests logger integration" OFF)

if(SA_MATHS_TEST_LOGGER_INTEGRATION)

	# Fetch SA_Logger.
	if(NOT TARGET SA_Logger)

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



# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)

if(SA_MATHS_BUILD_BENCHMARK_OPT)

	add_subdirectory(Benchmark)

endif()
