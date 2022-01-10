// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Space/Vector2.hpp>

namespace Sa
{
	/* Must be declared in Sa:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Vec2<T>& _v)
	{
		return _os << "X: " + std::to_string(_v.x) + "\tY: " + std::to_string(_v.y);
	}
}

/// Google Test typedef helper.
#define Vec2T Vec2<TypeParam>

#define EXPECT_VEC2_NEAR(_v1, _v2, eps)\
{\
	auto v1V = (_v1);\
	auto v2V = (_v2);\
\
	EXPECT_NEAR(v1V.x, v2V.x, eps);\
	EXPECT_NEAR(v1V.y, v2V.y, eps);\
}
