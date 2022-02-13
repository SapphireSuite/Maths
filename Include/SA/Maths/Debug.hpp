// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_DEBUG_GUARD
#define SAPPHIRE_MATHS_DEBUG_GUARD

#if SA_LOGGER_IMPL

	// Add Sapphire Logger if implementation linked
	#include <SA/Collections/Debug>

#else

	// Define empty logger macro.

	#define SA_LOG(...) {}

	#define SA_WARN(...) {}

	#define SA_ERROR(...) {}


	#define SA_ASSERT(...) {}

	#define SA_ASSERT_EXEC(_type, _chan, _exec, ...) { _exec; }

#endif

#endif // GUARD
