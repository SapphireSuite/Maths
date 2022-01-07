// Copyright 2022 Sapphire development team.All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Algorithms/Equals.hpp>

namespace Sa::UT::Lerp
{
	template <typename T>
	class LerpTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(LerpTest, TestTypes);

	TYPED_TEST(LerpTest, Lerp)
	{
		EXPECT_EQ(Maths::Lerp(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 0.0f), TestTypes{ 1.0 });
		EXPECT_EQ(Maths::Lerp(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 1.0f), TestTypes{ 5.0 });
		EXPECT_EQ(Maths::Lerp(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 0.5f), TestTypes{ 3.0 });

		EXPECT_EQ(Maths::Lerp(TestTypes{ 1.0 }, TestTypes{ 5.0 }, -1.0f), TestTypes{ 1.0 });
		EXPECT_EQ(Maths::Lerp(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 2.0f), TestTypes{ 5.0 });
	}

	TYPED_TEST(LerpTest, LerpUnclamped)
	{
		EXPECT_EQ(Maths::LerpUnclamped(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 0.0f), TestTypes{ 1.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 1.0f), TestTypes{ 5.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 0.5f), TestTypes{ 3.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TestTypes{ 1.0 }, TestTypes{ 5.0 }, -1.0f), TestTypes{ -3.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TestTypes{ 1.0 }, TestTypes{ 5.0 }, 2.0f), TestTypes{ 9.0 });

	}

	TYPED_TEST(LerpTest, SLerp)
	{
		// TODO: Implement.
	}

	TYPED_TEST(LerpTest, SLerpUnclamped)
	{
		// TODO: Implement.
	}
}
