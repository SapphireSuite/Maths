// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Space/Quaternion.hpp>

namespace Sa
{
	/* Must be declared in Sa:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Quat<T>& _q)
	{
		return _os << "W: " + std::to_string(_q.w) +
			"\tX: " + std::to_string(_q.x) +
			"\tY: " + std::to_string(_q.y) +
			"\tZ: " + std::to_string(_q.z);
	}
}

/// Google Test typedef helper.
#define QuatT Quat<TypeParam>

#define EXPECT_QUAT_NEAR(_q1, _q2, eps)\
{\
	auto q1V = (_q1);\
	auto q2V = (_q2);\
\
	EXPECT_NEAR(q1V.w, q2V.w, eps);\
	EXPECT_NEAR(q1V.x, q2V.x, eps);\
	EXPECT_NEAR(q1V.y, q2V.y, eps);\
	EXPECT_NEAR(q1V.z, q2V.z, eps);\
}
