// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <SA/Maths/Algorithms/InvSqrt.hpp>

#include <SA/Maths/Config.hpp>

namespace Sa::Maths
{
	template <>
	float InvSqrt(float _in)
	{
#if SA_MATHS_INV_SQRT_SIMD

#else

		const float threehalfs = 1.5f;

		float y = _in;
		float x2 = _in * 0.5F;

		int64_t i = *(int64_t*)&y;

		i = 0x5f3759df - (i >> 1);
		y = *(float*)&i;

		for (int j = 0; j < __SA_INV_SQRT_IT_NUM; ++j)
			y *= threehalfs - (x2 * y * y);

		return y;

#endif

	}

	template <>
	double InvSqrt(double _in)
	{
#if SA_MATHS_INV_SQRT_SIMD


#else

		const double threehalfs = 1.5f;

		double y = _in;
		double x2 = _in * 0.5F;

		int64_t i = *(int64_t*)&y;

		i = 0x5fe6eb50c7b537a9 - (i >> 1);
		y = *(double*)&i;

		for (int j = 0; j < __SA_INV_SQRT_IT_NUM; ++j)
			y *= threehalfs - (x2 * y * y);

		return y;

#endif
	}

}
