# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.


### Add Max warning level for tests.
SA_SetupMaxWarningLevel(SA_Maths)



# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)

if(SA_MATHS_BUILD_BENCHMARK_OPT)

	add_subdirectory(Benchmark)

endif()
