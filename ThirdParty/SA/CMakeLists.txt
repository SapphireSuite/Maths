# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Entrypoints

if(SA_MATHS_USE_LOGGER_OPT)

	SA_FetchModule(Logger)

elseif(SA_MATHS_INTRINSICS_OPT)

	# Support required for intrinsics.
	SA_FetchModule(Support)

endif()
