// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_DEBUG_GUARD
#define SAPPHIRE_MATHS_DEBUG_GUARD

/**
 * @file Debug.hpp
 * 
 * @brief Maths module Debug compatibility definition.
 * 
 * Allows SA_Logger compatibility if cmake option SA_MATHS_USE_LOGGER_OPT=ON 
 * 
 * @ingroup Maths
 * @{
 */

/// @cond ignore

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

/// @endcond

/** @} */

#endif // GUARD
