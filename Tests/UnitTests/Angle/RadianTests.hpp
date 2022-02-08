// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_RADIAN_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_RADIAN_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Angle/Radian.hpp>

namespace Sa
{
	/* Must be declared in Sa:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Rad<T>& _r)
	{
		return _os << std::to_string(_r.Handle()) + "_rad";
	}
}

/// Google Test typedef helper.
#define RadT Rad<TypeParam>

#endif // GUARD
