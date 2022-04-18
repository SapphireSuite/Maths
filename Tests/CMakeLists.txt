# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.


SA_SetMaxWarningLevel(TARGET SA_Maths)



# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)

if(SA_MATHS_BUILD_BENCHMARK_OPT)

	add_subdirectory(Benchmark)

endif()
