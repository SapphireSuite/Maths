// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Misc/Degree.hpp>
#include <SA/Maths/Misc/Radian.hpp>

namespace Sa::UT::Degree
{
	template <typename T>
	class DegreeTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(DegreeTest, TestTypes);

	TYPED_TEST(DegreeTest, Constructors)
	{
		const Deg<TypeParam> d1;
		EXPECT_EQ(d1.Handle(), 0);

		const TypeParam d2_val = TypeParam{ 2.56 };
		const Deg<TypeParam> d2 = d2_val;
		EXPECT_EQ(d2.Handle(), d2_val);

		const Rad<TypeParam> r4 = Maths::Pi<TypeParam>;
		const Deg<TypeParam> d4 = r4;
		EXPECT_EQ(d4.Handle(), 180);
	}

	TEST(Degree, CastConstructor)
	{
		const Degd dd1 = 4.23;
		const Degf d1 = dd1;
		EXPECT_EQ(d1.Handle(), 4.23f);

		const Degf df2 = 6.235f;
		const Degd d2 = df2;
		EXPECT_EQ(d2.Handle(), double{ 6.235f });
	}

	TYPED_TEST(DegreeTest, Equals)
	{
		const Deg<TypeParam> d1 = TypeParam{ 1.3 };
		const Deg<TypeParam> d2 = TypeParam{ 4.0 };
		const Deg<TypeParam> d3 = TypeParam{ 1.3 } + std::numeric_limits<TypeParam>::epsilon();

		EXPECT_FALSE(d1.Equals(d2));
		EXPECT_TRUE(d1.Equals(d1));
		EXPECT_TRUE(d1.Equals(d3));

		EXPECT_FALSE(d1 == d2);
		EXPECT_TRUE(d1 == d1);
		EXPECT_TRUE(d1 == d3);

		EXPECT_TRUE(d1 != d2);
		EXPECT_FALSE(d1 != d1);
		EXPECT_FALSE(d1 != d3);
	}

	TYPED_TEST(DegreeTest, Clamp)
	{
		const TypeParam d1_val = TypeParam{ 10.0 };
		Deg<TypeParam> d1 = d1_val;
		d1.Clamp();
		EXPECT_EQ(d1, d1_val);

		const TypeParam d2_val = TypeParam{ 310.0 };
		const TypeParam d2_clampedVal = TypeParam{ -50.0 };
		Deg<TypeParam> d2 = d2_val;
		d2.Clamp();
		EXPECT_EQ(d2, d2_clampedVal);

		const TypeParam d3_val = TypeParam{ 670.0 };
		const TypeParam d3_clampedVal = TypeParam{ -50.0 };
		Deg<TypeParam> d3 = d3_val;
		d3.Clamp();
		EXPECT_EQ(d3, d3_clampedVal);

		const TypeParam d4_val = TypeParam{ -200.0 };
		const TypeParam d4_clampedVal = TypeParam{ 160.0 };
		Deg<TypeParam> d4 = d4_val;
		d4.Clamp();
		EXPECT_EQ(d4, d4_clampedVal);

		const TypeParam d5_val = TypeParam{ -560.0 };
		const TypeParam d5_clampedVal = TypeParam{ 160.0 };
		Deg<TypeParam> d5 = d5_val;
		d5.Clamp();
		EXPECT_EQ(d5, d5_clampedVal);
	}

	TYPED_TEST(DegreeTest, OperatorSelfMinus)
	{
		const Deg<TypeParam> d1 = TypeParam{ 180.0 };

		EXPECT_EQ(-d1, TypeParam{ -180.0 });

		// Ensure correct conversion.
		const Rad<TypeParam> r1 = -d1;
		EXPECT_EQ(r1, -Maths::Pi<TypeParam>);
	}

	TYPED_TEST(DegreeTest, OperatorPlus)
	{
		const Deg<TypeParam> d1 = TypeParam{ 160.0 };
		const Deg<TypeParam> d2 = TypeParam{ 20.0 };

		EXPECT_EQ(d1 + d2, TypeParam{ 180.0 });

		// Ensure correct conversion.
		const Rad<TypeParam> r1 = d1 + d2;
		EXPECT_EQ(r1, Maths::Pi<TypeParam>);

		Deg<TypeParam> d3 = d1;
		d3 += d2;
		EXPECT_EQ(d3, d1 + d2);
	}

	TYPED_TEST(DegreeTest, OperatorMinus)
	{
		const Deg<TypeParam> d1 = TypeParam{ 200.0 };
		const Deg<TypeParam> d2 = TypeParam{ 20.0 };

		EXPECT_EQ(d1 - d2, TypeParam{ 180.0 });

		// Ensure correct conversion.
		const Rad<TypeParam> r1 = d1 - d2;
		EXPECT_EQ(r1, Maths::Pi<TypeParam>);

		Deg<TypeParam> d3 = d1;
		d3 -= d2;
		EXPECT_EQ(d3, d1 - d2);
	}

	TYPED_TEST(DegreeTest, OperatorScale)
	{
		const Deg<TypeParam> d1 = TypeParam{ 90.0 };

		EXPECT_EQ(d1 * 2, TypeParam{ 180.0 });

		// Ensure correct conversion.
		const Rad<TypeParam> r1 = d1 * 2;
		EXPECT_EQ(r1, Maths::Pi<TypeParam>);

		Deg<TypeParam> d3 = d1;
		d3 *= 2;
		EXPECT_EQ(d3, d1 * 2);
	}

	TYPED_TEST(DegreeTest, OperatorUnScale)
	{
		const Deg<TypeParam> d1 = TypeParam{ 180.0 };

		EXPECT_EQ(d1 / 2, TypeParam{ 90.0 });

		// Ensure correct conversion.
		const Rad<TypeParam> r1 = d1 / 2;
		EXPECT_EQ(r1, Maths::PiOv2<TypeParam>);

		Deg<TypeParam> d3 = d1;
		d3 /= 2;
		EXPECT_EQ(d3, d1 / 2);
	}


	TEST(Degree, Literals)
	{
		const Degf d1 = 4_deg;
		EXPECT_EQ(d1.Handle(), 4.0f);

		const Degd d2 = 1.3_deg;
		EXPECT_EQ(d2.Handle(), 1.3);
	}
}
