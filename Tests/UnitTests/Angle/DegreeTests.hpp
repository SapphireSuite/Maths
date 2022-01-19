// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_DEGREE_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_DEGREE_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Angle/Degree.hpp>

namespace Sa
{
	/* Must be declared in Sa:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Deg<T>& _d)
	{
		return _os << std::to_string(_d.Handle()) + "_deg";
	}
}

/// Google Test typedef helper.
#define DegT Deg<TypeParam>

#endif // GUARD
