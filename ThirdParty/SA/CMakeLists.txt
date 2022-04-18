# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Entrypoints

add_subdirectory(CMake_Utils)

if(SA_MATHS_USE_LOGGER_OPT)

	SA_FetchModule(Logger)

elseif(SA_MATHS_INTRINSICS_OPT)

	# Support required for intrinsics.
	SA_FetchModule(Support)

endif()
