// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Space/Vector4.hpp>

namespace Sa
{
	/* Must be declared in Sa:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Vec4<T>& _v)
	{
		return _os << "X: " + std::to_string(_v.x) +
			"\tY: " + std::to_string(_v.y) +
			"\tZ: " + std::to_string(_v.z) +
			"\tW: " + std::to_string(_v.w);
	}
}

/// Google Test typedef helper.
#define Vec4T Vec4<TypeParam>
