// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_FUNCTOR_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_FUNCTOR_GUARD

namespace Sa
{
	// Forward declaration for children.
	template <typename T, template <typename> typename... Args>
	struct Tr;

	/**
	 * @brief Define implementation for transform specific calculation.
	 * Must implement templated operator().
	 */
	class TrFunctor;
}

#endif // GUARD
