// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Misc/Radian.hpp>

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
