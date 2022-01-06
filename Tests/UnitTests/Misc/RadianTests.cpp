// Copyright 2022 Sapphire development team.All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Misc/Radian.hpp>
#include <SA/Maths/Misc/Degree.hpp>

namespace Sa::UT::Radian
{
	template <typename T>
	class RadianTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(RadianTest, TestTypes);

	TYPED_TEST(RadianTest, Constructors)
	{
		const Rad<TypeParam> r1;
		EXPECT_EQ(r1.Handle(), 0);

		const TypeParam r2_val = TypeParam{ 2.56 };
		const Rad<TypeParam> r2 = r2_val;
		EXPECT_EQ(r2.Handle(), r2_val);

		const Deg<TypeParam> d4 = TypeParam{ 180.0 };
		const Rad<TypeParam> r4 = d4;
		EXPECT_EQ(r4.Handle(), TypeParam{ Maths::Pi });
	}

	TEST(Radian, CastConstructor)
	{
		const Radd rd1 = 4.23;
		const Radf r1 = rd1;
		EXPECT_EQ(r1.Handle(), 4.23f);

		const Radf rf2 = 6.235f;
		const Radd r2 = rf2;
		EXPECT_EQ(r2.Handle(), double{ 6.235f });
	}

	TYPED_TEST(RadianTest, Equals)
	{
		const Rad<TypeParam> r1 = TypeParam{ 1.3 };
		const Rad<TypeParam> r2 = TypeParam{ 4.0 };
		const Rad<TypeParam> r3 = TypeParam{ 1.3 } + std::numeric_limits<TypeParam>::epsilon();

		EXPECT_FALSE(r1.Equals(r2));
		EXPECT_TRUE(r1.Equals(r1));
		EXPECT_TRUE(r1.Equals(r3));

		EXPECT_FALSE(r1 == r2);
		EXPECT_TRUE(r1 == r1);
		EXPECT_TRUE(r1 == r3);

		EXPECT_TRUE(r1 != r2);
		EXPECT_FALSE(r1 != r1);
		EXPECT_FALSE(r1 != r3);
	}

	TYPED_TEST(RadianTest, Clamp)
	{
		const TypeParam piT = TypeParam{ Maths::Pi };
		const TypeParam baseVal = TypeParam{ 1.26 };
		const TypeParam clampedVal = TypeParam{ 1.8815926535897933 };

		Rad<TypeParam> r1 = baseVal;
		r1.Clamp();
		EXPECT_EQ(r1, baseVal);

		Rad<TypeParam> r2 = piT + baseVal;
		r2.Clamp();
		EXPECT_EQ(r2, -clampedVal);

		Rad<TypeParam> r3 = 3 * piT + baseVal;
		r3.Clamp();
		EXPECT_EQ(r3, -clampedVal);

		Rad<TypeParam> r4 = -piT - baseVal;
		r4.Clamp();
		EXPECT_EQ(r4, clampedVal);

		Rad<TypeParam> r5 = -3 * piT - baseVal;
		r5.Clamp();
		EXPECT_EQ(r5, clampedVal);
	}

	TYPED_TEST(RadianTest, OperatorSelfMinus)
	{
		const Rad<TypeParam> r1 = TypeParam{ Maths::Pi };

		EXPECT_EQ(-r1, TypeParam{ -Maths::Pi });

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = -r1;
		EXPECT_EQ(d1, TypeParam{ -180.0 });
	}

	TYPED_TEST(RadianTest, OperatorPlus)
	{
		const Rad<TypeParam> r1 = TypeParam{ Maths::PiOv2 };
		const Rad<TypeParam> r2 = TypeParam{ Maths::PiOv4 };

		EXPECT_EQ(r1 + r2, TypeParam{ Maths::PiOv2 + Maths::PiOv4 });

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 + r2;
		EXPECT_EQ(d1, TypeParam{ (Maths::PiOv2 + Maths::PiOv4) * Maths::RadToDeg });

		Rad<TypeParam> r3 = r1;
		r3 += r2;
		EXPECT_EQ(r3, r1 + r2);
	}

	TYPED_TEST(RadianTest, OperatorMinus)
	{
		const Rad<TypeParam> r1 = TypeParam{ Maths::PiOv2 };
		const Rad<TypeParam> r2 = TypeParam{ Maths::PiOv4 };

		EXPECT_EQ(r1 - r2, TypeParam{ Maths::PiOv2 - Maths::PiOv4 });

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 - r2;
		EXPECT_EQ(d1, TypeParam{ (Maths::PiOv2 - Maths::PiOv4) * Maths::RadToDeg });

		Rad<TypeParam> r3 = r1;
		r3 -= r2;
		EXPECT_EQ(r3, r1 - r2);
	}

	TYPED_TEST(RadianTest, OperatorScale)
	{
		const Rad<TypeParam> r1 = TypeParam{ Maths::PiOv2};

		EXPECT_EQ(r1 * 2, TypeParam{ Maths::Pi });

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 * 2;
		EXPECT_EQ(d1, TypeParam{ 180.0 });

		Rad<TypeParam> r3 = r1;
		r3 *= 2;
		EXPECT_EQ(r3, r1 * 2);
	}

	TYPED_TEST(RadianTest, OperatorUnScale)
	{
		const Rad<TypeParam> r1 = TypeParam{ Maths::Pi };

		EXPECT_EQ(r1 / 2, TypeParam{ Maths::PiOv2 });

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 / 2;
		EXPECT_EQ(d1, TypeParam{ 90.0 });

		Rad<TypeParam> r3 = r1;
		r3 /= 2;
		EXPECT_EQ(r3, r1 / 2);
	}


	TEST(Radian, Literals)
	{
		const Radf r1 = 4_rad;
		EXPECT_EQ(r1.Handle(), 4.0f);

		const Radd r2 = 1.3_rad;
		EXPECT_EQ(r2.Handle(), 1.3);
	}
}
