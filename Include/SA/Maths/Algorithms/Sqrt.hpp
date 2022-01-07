// Copyright 2022 Sapphire development team.All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_SQRT_GUARD
#define SAPPHIRE_MATHS_SQRT_GUARD

#include <cmath>

/**
*	\file Sqrt.hpp
* 
*	\brief <b>Square Root</b> algorithm implementation.
* 
*	\ingroup Maths_Algorithms
*	\{
*/


namespace Sa
{
	namespace Maths
	{
		/**
		*	\brief \e Compute the <b> square root </b> of the input as float.
		*
		*	\tparam T		Input Type.
		* 
		*	\param[in] _in	Input to compute square root.
		*
		*	\return Square Root of the input.
		*/
		template <typename T>
		T Sqrt(T _in)
		{
			// TODO: Debug.
			//SA_WARN(_in >= T(0), Maths, L"Compute square root of a negative number!");

			return std::sqrt(_in);
		}
	}
}


/** \} */

#endif // GUARD
