# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.


# Library

## Static library for test. Use this lib for any testing.
add_library(SA_Maths_Test STATIC ${SA_MATHS_SOURCES})
SA_Setup_Maths_Target(SA_Maths_Test)


## Compile features

### Max warning level for tests.
if(MSVC)
	if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") # ClangCl
		target_compile_options(SA_Maths_Test PUBLIC -W4)
	else()
		target_compile_options(SA_Maths_Test PUBLIC /W4)
	endif()
elseif()
	target_compile_options(SA_Maths_Test PUBLIC -Wall -Wextra)
endif()



# Entrypoints

add_subdirectory(Prototype)
#add_subdirectory(UnitTests)
