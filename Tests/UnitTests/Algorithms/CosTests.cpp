// Copyright 2022 Sapphire development team.All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Misc/Degree.hpp>
#include <SA/Maths/Algorithms/Cos.hpp>

namespace Sa::UT::Cos
{
	TEST(TrigoTest, CosinusFloat)
	{
		EXPECT_EQ(Maths::Cos(0.0_rad), 1.0f);

		EXPECT_EQ(Maths::Cos<float>(Maths::Pi<float>), -1.0f);
		
		//EXPECT_FLOAT_EQ(Maths::Cos<float>(Maths::PiOv2<float>), 0.0);
		EXPECT_EQ(Maths::Cos<float>(Maths::PiOv2<float>) - std::numeric_limits<float>::epsilon() <= 0.0f, true);

		EXPECT_EQ(Maths::Cos<float>(Degf{ 40 }), float{ 0.76604444311897801 });
		EXPECT_EQ(Maths::Cos<float>(0.69813170079773179), float{ 0.76604444311897801 });
	}

	TEST(TrigoTest, CosinusDouble)
	{
		EXPECT_EQ(Maths::Cos(0.0_rad), 1.0);

		//EXPECT_EQ(Maths::Cos<double>(Maths::Pi<double>), -1.0);
		EXPECT_EQ(Maths::Cos<double>(Maths::PiOv2<double>) - std::numeric_limits<double>::epsilon() <= 0.0, true);

		EXPECT_EQ(Maths::Cos<double>(Degd{ 40 }), 0.76604444311897801);
		EXPECT_EQ(Maths::Cos<double>(0.69813170079773179), 0.76604444311897801);
	}
}
