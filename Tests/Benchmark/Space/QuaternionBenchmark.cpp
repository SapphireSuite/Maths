// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

#include <SA/Maths/Space/Quaternion.hpp>
#include <SA/Maths/Space/Vector3.hpp>

namespace Sa::Benchmark::Quaternion
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
    static void SqrLength(benchmark::State& _state)
    {
        T x = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(x += q3<T>.SqrLength());
    }

    BENCHMARK_TEMPLATE(SqrLength, float);
    BENCHMARK_TEMPLATE(SqrLength, double);


    template <typename T>
    static void GetNormalized(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q3<T>.GetNormalized());
    }

    BENCHMARK_TEMPLATE(GetNormalized, float);
    BENCHMARK_TEMPLATE(GetNormalized, double);


    template <typename T>
    static void Rotate(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q1<T>.Rotate(q2<T>));
    }

    BENCHMARK_TEMPLATE(Rotate, float);
    BENCHMARK_TEMPLATE(Rotate, double);


    template <typename T>
    static void Dot(benchmark::State& _state)
    {
        T dot = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(dot += Quat<T>::Dot(q1<T>, q2<T>));
    }

    BENCHMARK_TEMPLATE(Dot, float);
    BENCHMARK_TEMPLATE(Dot, double);


    template <typename T>
    static void ToEuler(benchmark::State& _state)
    {
        Vec3<Deg<T>> euler;

        for (auto _ : _state)
            benchmark::DoNotOptimize(euler += q1<T>.ToEuler());
    }

    BENCHMARK_TEMPLATE(ToEuler, float);
    BENCHMARK_TEMPLATE(ToEuler, double);


    template <typename T>
    static void FromEuler(benchmark::State& _state)
    {
       Quat<T> qres;
       const Vec3<Deg<T>> euler(43.21_deg, 33.21_deg, 136.23_deg);

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += Quat<T>::FromEuler(euler));
    }

    BENCHMARK_TEMPLATE(FromEuler, float);
    BENCHMARK_TEMPLATE(FromEuler, double);


    template <typename T>
    static void OperatorPlus(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q1<T> + q2<T>);
    }

    BENCHMARK_TEMPLATE(OperatorPlus, float);
    BENCHMARK_TEMPLATE(OperatorPlus, double);


    template <typename T>
    static void OperatorMult(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += q1<T> * q2<T>);
    }

    BENCHMARK_TEMPLATE(OperatorMult, float);
    BENCHMARK_TEMPLATE(OperatorMult, double);
}
