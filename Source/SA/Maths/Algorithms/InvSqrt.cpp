// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <SA/Maths/Algorithms/InvSqrt.hpp>

#include <SA/Maths/Config.hpp>
#include <SA/Support/Intrinsics.hpp>

namespace Sa::Maths
{
	template <>
	float InvSqrt(float _in) noexcept
	{
#if SA_MATHS_INV_SQRT_SIMD && SA_INTRISC_SSE

		//const __m128 half = _mm_set_ss(0.5f);
		//__m128 Y0 = _mm_set_ss(_in);

		//__m128 resPack = _mm_rsqrt_ss(Y0);

		//for (int j = 0; j < __SA_INV_SQRT_IT_NUM; ++j)
		//{

		//}


		const __m128 fOneHalf = _mm_set_ss(0.5f);
		__m128 Y0, X0, X1, X2, FOver2;
		float temp;

		Y0 = _mm_set_ss(_in);
		X0 = _mm_rsqrt_ss(Y0);	// 1/sqrt estimate (12 bits)
		FOver2 = _mm_mul_ss(Y0, fOneHalf);

		// 1st Newton-Raphson iteration
		X1 = _mm_mul_ss(X0, X0);
		X1 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X1));
		X1 = _mm_add_ss(X0, _mm_mul_ss(X0, X1));

		// 2nd Newton-Raphson iteration
		X2 = _mm_mul_ss(X1, X1);
		X2 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X2));
		X2 = _mm_add_ss(X1, _mm_mul_ss(X1, X2));

		_mm_store_ss(&temp, X2);
		return temp;

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
	double InvSqrt(double _in) noexcept
	{
#if SA_MATHS_INV_SQRT_SIMD && SA_INTRISC_AVX

		return 0;

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
