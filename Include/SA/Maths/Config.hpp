// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_CONFIG_GUARD
#define SAPPHIRE_MATHS_CONFIG_GUARD

/**
*	\file Maths/Config.hpp
*
*	\brief Maths specific config file.
*
*	\ingroup Maths
*	\{
*/


/**
*	\defgroup Maths Maths
*	Sapphire Suite's Maths Module.
*/

/**
*	\defgroup Maths_Algorithms Algorithms
*	Sapphire Suite's Maths Algorithms.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Space Space
*	Sapphire Suite's Maths Space.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Matrix Matrix
*	Sapphire Suite's Maths Matrix.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Misc Misc
*	Sapphire Suite's Maths Misc.
*	\ingroup Maths
*/


/**
*	Whether to use SIMD implementation for Quaternion.
*	Default is disabled. Benchmark has shown that compiler already optimize calcultation at its best.
*/
#define SA_MATHS_QUATERNION_SIMD 0 && SA_MATHS_INTRINSICS_OPT


/**
*	Whether to use SIMD implementation for Matrix4.
*	Default is disabled. Benchmark has shown that compiler already optimize calcultation at its best.
*/
#define SA_MATHS_MAT4_SIMD 0 && SA_MATHS_INTRINSICS_OPT

/** \} */

#endif // GUARD
