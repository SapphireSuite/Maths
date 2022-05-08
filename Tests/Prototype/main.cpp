// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Collections/Transform>
using namespace Sa;

int main()
{
	TrPRSf tr1 {
		{ Vec3f(6.3f, 5.14f, 9.25f) },
		{ Quatf(40_deg, Vec3f::Up) },
		{ Vec3f(1.0f, 2.0f, 3.0f) }
	};

	Mat4f mTr = Mat4f::MakeTransform(Vec3f(6.3f, 5.14f, 9.25f), Quatf(40_deg, Vec3f::Up), Vec3f(1.0f, 2.0f, 3.0f));

	auto mm = tr1.Matrix();

	LOG(ToString(mm));
	LOG("------------------------------------");
	LOG(ToString(mTr));

	LOG("Equals: " << (mm == mTr));


	return 0;
}
