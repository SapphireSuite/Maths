// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

#include <SA/Maths/Algorithms/InvSqrt.hpp>

#include "../Tools/Random.hpp"

namespace Sa::Benchmark
{
	template <typename T>
	static void STD_InvSqrt(benchmark::State& _state)
	{
		T x = T();

		for (auto _ : _state)
			benchmark::DoNotOptimize(x += (T(1) / std::sqrt(Rand<T>())));
	}

	BENCHMARK_TEMPLATE(STD_InvSqrt, float);
	BENCHMARK_TEMPLATE(STD_InvSqrt, double);


	template <typename T>
	static void Fast_InvSqrt(benchmark::State& _state)
	{
		T x = T();

		for (auto _ : _state)
			benchmark::DoNotOptimize(x += Maths::InvSqrt(Rand<T>()));
	}

	BENCHMARK_TEMPLATE(Fast_InvSqrt, float);
	BENCHMARK_TEMPLATE(Fast_InvSqrt, double);
}
