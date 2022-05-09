// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_ORDER_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_ORDER_GUARD

namespace Sa
{
	// Forward declaration for children.
	template <typename T, template <typename> typename... Args>
	struct Tr;

	/**
	 * @brief Define Transformation order application.
	 * Implement this struct to define transformation application order to compute matrix.
	 * 
	 * Order should be applied from right to left.
	 * Ex: TRS matrix is T * R * S
	 * 
	 * Order class must implement the function:
	 * template <typename T, template <typename> typename... TrArgs>
	 * Mat4<T> ComputeMatrix(const Tr<T, TrArgs...>& _tr)
	 * 
	 * @tparam OrderArgs Ordered Transform components.
	 */
	template <template <typename> typename... OrderArgs>
	class TrOrder;
}

#endif // GUARD
