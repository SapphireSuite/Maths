// Copyright 2022 Sapphire development team.All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Misc/Degree.hpp>
#include <SA/Maths/Algorithms/Tan.hpp>

namespace Sa::UT::Tan
{
	TEST(TrigoTest, TangentFloat)
	{
		// TODO: Comparison not working ?
		//EXPECT_EQ(Maths::Tan<float>(Maths::Pi<float>), 0.0f);
		EXPECT_EQ(Maths::Tan<float>(Maths::Pi<float>) - std::numeric_limits<float>::epsilon() <= 0.0f, true);
		
		EXPECT_FLOAT_EQ(Maths::Tan<float>(Maths::PiOv3<float>), float{ 1.7320508075688767 });
		EXPECT_EQ(Maths::Tan<float>(-Maths::PiOv6<float>), float{ -0.57735026918962573 });
		EXPECT_FLOAT_EQ(Maths::Tan<float>(40_deg), float{ 0.83909963117727993 });
		EXPECT_FLOAT_EQ(Maths::Tan<float>(0.69813170079773179_rad), float{ 0.83909963117727993 });
	}

	TEST(TrigoTest, TangentDouble)
	{
		// TODO: Comparison not working ?
		//EXPECT_EQ(Maths::Tan<double>(Maths::Pi<double>), 0.0f);
		EXPECT_EQ(Maths::Tan<double>(Maths::Pi<double>) - std::numeric_limits<double>::epsilon() <= 0.0f, true);

		EXPECT_EQ(Maths::Tan<double>(Maths::PiOv3<double>), 1.7320508075688767);
		EXPECT_EQ(Maths::Tan<double>(-Maths::PiOv6<double>), -0.57735026918962573);
		EXPECT_EQ(Maths::Tan<double>(40_deg), 0.83909963117727993);
		EXPECT_EQ(Maths::Tan<double>(0.69813170079773179_rad), 0.83909963117727993);
	}
}
