// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_LERP_GUARD
#define SAPPHIRE_MATHS_LERP_GUARD

#include <algorithm>

#include <SA/Maths/Debug.hpp>

#include <SA/Maths/Algorithms/Cos.hpp>
#include <SA/Maths/Algorithms/Sin.hpp>

/**
*	\file Lerp.hpp
* 
*	\brief \b Lerp algorithms implementation.
* 
*	\ingroup Maths_Algorithms
*	\{
*/


namespace SA
{
	namespace Maths
	{
		/**
		*	\brief <b> Unclamped Lerp </b> from _start to _end at _alpha.
		*
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\tparam T			Input type.
		* 
		*	\param[in] _start	Starting point of the lerp.
		*	\param[in] _end		Ending point of the lerp.
		*	\param[in] _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		template <typename T>
		T LerpUnclamped(const T& _start, const T& _end, float _alpha) noexcept
		{
			return (1.0f - _alpha) * _start + _alpha * _end;
		}

		/**
		*	\brief <b> Clamped Lerp </b> from _start to _end at _time.
		*
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\tparam T		Input type.
		* 
		*	\param[in] _start	Starting point of the lerp.
		*	\param[in] _end		Ending point of the lerp.
		*	\param[in] _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		template <typename T>
		T Lerp(const T& _start, const T& _end, float _alpha) noexcept
		{
			SA_WARN(_alpha >= 0.0f && _alpha <= 1.0f, SA.Maths, (L"Alpha[%1] clamped to range [0, 1]! Use LerpUnclamped if intended instead.", _alpha));

			return LerpUnclamped(_start, _end, std::clamp(_alpha, 0.0f, 1.0f));
		}


		/**
		*	\brief <b> Unclamped SLerp </b> from _start to _end at _alpha.
		*
		*	Reference: https://en.wikipedia.org/wiki/Slerp
		*
		*	\tparam T			Input type.
		* 
		*	\param[in] _start	Starting point of the lerp.
		*	\param[in] _end		Ending point of the lerp.
		*	\param[in] _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		template <typename T>
		T SLerpUnclamped(const T& _start, const T& _end, float _alpha) noexcept
		{
			/**
			*	Reference: https://en.wikipedia.org/wiki/Slerp
			*	Formula: (Sin((1.0f - _alpha) * angle) * _start) / sin + (sinStep * _end) / sin.
			*/

			using TScalar = typename T::Type;
			TScalar dot = T::Dot(_start, _end);
			TScalar endSign = 1.0f;

			// Ensure shortest path between _start and _end.
			if (dot < 0.0f)
			{
				endSign = -1.0f;
				dot = -dot;
			}

			// Dot too close to 1 cause angle of 0.
			if (Maths::Equals1(dot))
			{
				// Basic linear interpolation.
				return LerpUnclamped(_start, _end * endSign, _alpha);
			}

			// Current angle.
			Rad<TScalar> angle = ACos(dot);

			// Angle step to apply.
			Rad<TScalar> angleStep = angle * _alpha;

			// Current sin.
			TScalar sin = Sin(angle);

			// Sin Step ratio.
			TScalar sinRatio = Sin(angleStep) / sin;

			TScalar s0 = Cos(angleStep) - dot * sinRatio;

			return s0 * _start + sinRatio * _end * endSign;
		}

		/**
		*	\brief <b> Clamped SLerp </b> from _start to _end at _alpha.
		*
		*	Reference: https://en.wikipedia.org/wiki/Slerp
		*
		*	\tparam T		Input type.
		* 
		*	\param[in] _start	Starting point of the lerp.
		*	\param[in] _end		Ending point of the lerp.
		*	\param[in] _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		template <typename T>
		T SLerp(const T& _start, const T& _end, float _alpha) noexcept
		{
			SA_WARN(_alpha >= 0.0f && _alpha <= 1.0f, SA.Maths, (L"Alpha[%1] clamped to range [0, 1]! Use LerpUnclamped if intended instead.", _alpha));

			return SLerpUnclamped(_start, _end, std::clamp(_alpha, 0.0f, 1.0f));
		}
	}
}

/**
*	\example LerpTests.cpp
*	Examples and Unitary Tests for Lerp.
*/


/** \} */

#endif // GUARD
