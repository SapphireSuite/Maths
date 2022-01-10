// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Misc/Degree.hpp>

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
