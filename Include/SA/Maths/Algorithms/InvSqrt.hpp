// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_INV_SQRT_GUARD
#define SAPPHIRE_MATHS_INV_SQRT_GUARD

#include <cmath>

/**
*	\file InvSqrt.hpp
* 
*	\brief <b> Inverse Square Root</b> fast implementation.
* 
*	Sources: https://en.wikipedia.org/wiki/Fast_inverse_square_root
* 
*	\ingroup Maths_Algorithms
*	\{
*/


/// \cond Internal

/**
*	Iteration number for inverse sqrt implementation precision.
*/
# define __SA_INV_SQRT_IT_NUM 2

/// \endcond

namespace Sa
{
	namespace Maths
	{
		template <typename T>
		constexpr T InvSqrt(T _in) noexcept
		{
			return T(1) / std::sqrt(_in);
		}

		template <>
		float InvSqrt(float _in);

		template <>
		double InvSqrt(double _in);
	}
}

/** \} */

#endif // GUARD
