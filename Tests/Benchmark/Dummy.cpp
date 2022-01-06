// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

static void DummyBenchmark(benchmark::State& state)
{
    for (auto _ : state)
        std::string empty_string;
}

BENCHMARK(DummyBenchmark);
