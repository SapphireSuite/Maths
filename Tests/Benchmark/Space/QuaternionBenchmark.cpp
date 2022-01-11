// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

#include <SA/Maths/Space/Quaternion.hpp>
#include <SA/Maths/Space/Vector3.hpp>

namespace Sa::Benchmark
{
    template <typename T>
    const Quat<T> q1(
        T{ 0.65379899684951437 },
        T{ 0.49198400932684733 },
        T{ -0.57343602132006610 },
        T{ -0.040862400050191698 }
    );

    template <typename T>
    const Quat<T> q2(
        T{ 0.28456911695921927 },
        T{ 0.055287819843885436 },
        T{ -0.16261099422502870 },
        T{ -0.94314438937370981 }
    );

    template <typename T>
    const Quat<T> q3(T{ 13.21 }, T{ 1.346 }, T{ 55.21 }, T{ 75.21 });


    template <typename T>
    static void Quat_SqrLength(benchmark::State& _state)
    {
        T x = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(x += q3<T>.SqrLength());
    }

    BENCHMARK_TEMPLATE(Quat_SqrLength, float);
    BENCHMARK_TEMPLATE(Quat_SqrLength, double);


    template <typename T>
    static void Quat_GetNormalized(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q3<T>.GetNormalized());
    }

    BENCHMARK_TEMPLATE(Quat_GetNormalized, float);
    BENCHMARK_TEMPLATE(Quat_GetNormalized, double);


    template <typename T>
    static void Quat_Rotate(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q1<T>.Rotate(q2<T>));
    }

    BENCHMARK_TEMPLATE(Quat_Rotate, float);
    BENCHMARK_TEMPLATE(Quat_Rotate, double);


    template <typename T>
    static void Quat_Dot(benchmark::State& _state)
    {
        T dot = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(dot += Quat<T>::Dot(q1<T>, q2<T>));
    }

    BENCHMARK_TEMPLATE(Quat_Dot, float);
    BENCHMARK_TEMPLATE(Quat_Dot, double);


    template <typename T>
    static void Quat_ToEuler(benchmark::State& _state)
    {
        Vec3<Deg<T>> euler;

        for (auto _ : _state)
            benchmark::DoNotOptimize(euler += q1<T>.ToEuler());
    }

    BENCHMARK_TEMPLATE(Quat_ToEuler, float);
    BENCHMARK_TEMPLATE(Quat_ToEuler, double);


    template <typename T>
    static void Quat_FromEuler(benchmark::State& _state)
    {
        Quat<T> qres;
        const Vec3<Deg<T>> euler(43.21_deg, 33.21_deg, 136.23_deg);

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += Quat<T>::FromEuler(euler));
    }

    BENCHMARK_TEMPLATE(Quat_FromEuler, float);
    BENCHMARK_TEMPLATE(Quat_FromEuler, double);


    template <typename T>
    static void Quat_OperatorPlus(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q1<T> + q2<T>);
    }

    BENCHMARK_TEMPLATE(Quat_OperatorPlus, float);
    BENCHMARK_TEMPLATE(Quat_OperatorPlus, double);


    template <typename T>
    static void Quat_OperatorMult(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q1<T> * q2<T>);
    }

    BENCHMARK_TEMPLATE(Quat_OperatorMult, float);
    BENCHMARK_TEMPLATE(Quat_OperatorMult, double);
}
