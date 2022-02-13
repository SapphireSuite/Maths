// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>
using namespace Sa;

int main(int argc, char** argv)
{
#if SA_LOGGER_IMPL

	Logger logger;
	ConsoleLogStream cslStr;
	logger.Register(cslStr);

	Debug::logger = &logger;

#endif

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
