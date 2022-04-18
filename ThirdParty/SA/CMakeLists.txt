# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Entrypoints

include(CMake_FetchModule/SA_FetchModule.cmake)

if(SA_MATHS_USE_LOGGER_OPT)

	SA_FetchModule(Logger)

endif()


if(NOT TARGET SA_Support AND NOT TARGET SA_Logger)

	SA_FetchModule(Support)

endif()
