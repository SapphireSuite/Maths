// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_VECTOR3_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_VECTOR3_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Space/Vector3.hpp>

namespace Sa
{
	/* Must be declared in Sa:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Vec3<T>& _v)
	{
		return _os << "X: " + std::to_string(_v.x) +
			"\tY: " + std::to_string(_v.y) +
			"\tZ: " + std::to_string(_v.z);
	}
}

/// Google Test typedef helper.
#define Vec3T Vec3<TypeParam>

#define EXPECT_VEC3_NEAR(_v1, _v2, eps)\
{\
	auto v1V = (_v1);\
	auto v2V = (_v2);\
\
	EXPECT_NEAR(v1V.x, v2V.x, eps);\
	EXPECT_NEAR(v1V.y, v2V.y, eps);\
	EXPECT_NEAR(v1V.z, v2V.z, eps);\
}

#endif // GUARD
