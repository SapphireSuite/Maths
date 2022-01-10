// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

#include <SA/Maths/Space/Quaternion.hpp>

namespace Sa::Benchmark::Quaternion
{
    template <typename T>
    static void SqrLength(benchmark::State& _state)
    {
        const Sa::Quat<T> q(T{ 13.21 }, T{ 1.346 }, T{ 55.21 }, T{ 75.21 });

        for (auto _ : _state)
            q.SqrLength();
    }

    BENCHMARK_TEMPLATE(SqrLength, float);
    BENCHMARK_TEMPLATE(SqrLength, double);
}
