// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_RANDOM_BENCHMARK_GUARD
#define SAPPHIRE_MATHS_RANDOM_BENCHMARK_GUARD

#include <cstdlib>

namespace Sa::Benchmark
{
    static bool randomInit = []() { srand((unsigned int)time(nullptr)); return true; }();

    template <typename T>
    static T Rand(T _min = T(0), T _max = T(1))
    {
        return _min + static_cast<T>(rand()) / (static_cast<T> (RAND_MAX / (_max - _min)));
    }
}

#endif // GUARD
