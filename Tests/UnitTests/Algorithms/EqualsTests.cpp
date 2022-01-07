// Copyright 2022 Sapphire development team.All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Algorithms/Equals.hpp>
using namespace Sa;

namespace Sa::UT::Equals
{
	template <typename T>
	class EqualsTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double, int32_t, uint32_t>;
	TYPED_TEST_SUITE(EqualsTest, TestTypes);

	TYPED_TEST(EqualsTest, Equals)
	{
		const TypeParam defaultVal = static_cast<TypeParam>(1.26);
		const TypeParam epsilon = std::numeric_limits<TypeParam>::epsilon();

		EXPECT_EQ(Maths::Equals(defaultVal, defaultVal), true);
		EXPECT_EQ(Maths::Equals(defaultVal, defaultVal + epsilon), true);

		// float / double test only.
		if constexpr (std::is_floating_point_v<TypeParam>)
			EXPECT_EQ(Maths::Equals(defaultVal, defaultVal + 2 * epsilon), false);
		
		EXPECT_EQ(Maths::Equals(defaultVal, defaultVal + 1, 1), true);
		EXPECT_EQ(Maths::Equals(defaultVal, defaultVal + 1, epsilon), false);
	}
}
