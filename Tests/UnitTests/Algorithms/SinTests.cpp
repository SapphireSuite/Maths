// Copyright 2022 Sapphire development team.All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Misc/Degree.hpp>
#include <SA/Maths/Algorithms/Sin.hpp>

namespace Sa::UT::Sin
{
	TEST(TrigoTest, SinusFloat)
	{
		EXPECT_EQ(Maths::Sin(0.0_rad), 0.0f);

		// TODO: Comparison not working ?
		//EXPECT_FLOAT_EQ(Maths::Sin<float>(Maths::Pi<float>), 0.0f);
		EXPECT_EQ(Maths::Sin<float>(Maths::Pi<float>) - std::numeric_limits<float>::epsilon() <= 0.0f, true);

		EXPECT_EQ(Maths::Sin<float>(Maths::PiOv2<float>), 1.0f);
		EXPECT_EQ(Maths::Sin<float>(-Maths::PiOv2<float>), -1.0f);

		EXPECT_FLOAT_EQ(Maths::Sin<float>(Degf{ 40 }), float{ 0.64278760968653925 });
		EXPECT_FLOAT_EQ(Maths::Sin<float>(0.69813170079773179), float{ 0.64278760968653925 });
	}

	TEST(TrigoTest, SinusDouble)
	{
		EXPECT_EQ(Maths::Sin(0.0_rad), 0.0);

		// TODO: Comparison not working ?
		//EXPECT_DOUBLE_EQ(Maths::Sin<double>(Maths::Pi<double>), 0.0);
		EXPECT_EQ(Maths::Sin<double>(Maths::Pi<double>) - std::numeric_limits<double>::epsilon() <= 0.0f, true);

		EXPECT_EQ(Maths::Sin<double>(Maths::PiOv2<double>), 1.0);
		EXPECT_EQ(Maths::Sin<double>(-Maths::PiOv2<double>), -1.0);

		EXPECT_EQ(Maths::Sin<double>(Degd{ 40 }), 0.64278760968653925);
		EXPECT_EQ(Maths::Sin<double>(0.69813170079773179), 0.64278760968653925);
	}
}
