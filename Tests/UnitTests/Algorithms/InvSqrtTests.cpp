// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Algorithms/InvSqrt.hpp>

namespace Sa::UT::InvSqrt
{
	TEST(InvSqrt, InvSqrtFloat)
	{
		EXPECT_FLOAT_EQ(Maths::InvSqrt(2.0f), 1.0f / std::sqrt(2.0f));
		EXPECT_NEAR(Maths::InvSqrt(25.0f), 1.0f / std::sqrt(25.0f), 0.00001f);
	}

	TEST(InvSqrt, InvSqrtDouble)
	{
		EXPECT_NEAR(Maths::InvSqrt(2.0), 1.0 / std::sqrt(2.0), 0.00001);
		EXPECT_NEAR(Maths::InvSqrt(25.0), 1.0 / std::sqrt(25.0), 0.00001);
	}
}
