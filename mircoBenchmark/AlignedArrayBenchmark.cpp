#include <benchmark/benchmark.h>

#include <core/include/AlignedArray.h>
#include <core/include/AlignedCArray.h>

using namespace all;

static void aligned_array_benchmark(benchmark::State& state)
{
    AlignedArray<float> alignedArray(static_cast<size_t>(state.range(0)), static_cast<size_t>(state.range(0)));

    for (auto _ : state)
    {
        for (size_t i = 0; i < state.range(0); ++i)
            for (size_t j = 0; j < state.range(0); ++j)
                alignedArray[i][j] *= .4f + alignedArray[i][j];
    }
}

BENCHMARK(aligned_array_benchmark)->RangeMultiplier(2)->Range(8, 8<<10)->Unit(benchmark::kMicrosecond);

static void aligned_c_array_benchmark(benchmark::State& state)
{
    AlignedCArray<float> alignedArray(static_cast<size_t>(state.range(0)), static_cast<size_t>(state.range(0)));

    for (auto _ : state)
    {
        for (size_t i = 0; i < state.range(0); ++i)
            for (size_t j = 0; j < state.range(0); ++j)
                alignedArray[i][j] *= .4f + alignedArray[i][j];
    }
}

BENCHMARK(aligned_c_array_benchmark)->RangeMultiplier(2)->Range(8, 8<<10)->Unit(benchmark::kMicrosecond);


static void array_benchmark(benchmark::State& state)
{
    auto** array = new float*[state.range(0)];

    for (size_t i = 0; i < state.range(0); ++i)
        array[i] = new float[state.range(0)];

    for (auto _ : state)
    {
        for (size_t i = 0; i < state.range(0); ++i)
            for (size_t j = 0; j < state.range(0); ++j)
                array[i][j] *= .4f + array[i][j];
    }

    for (size_t i = 0; i < state.range(0); ++i)
        delete[] array[i];

    delete[] array;
}

BENCHMARK(array_benchmark)->RangeMultiplier(2)->Range(8, 8<<10)->Unit(benchmark::kMicrosecond);
