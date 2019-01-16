# Adaptive Learning Library
*What started out as an attempt to write my own machine learning library, now turned into a playground for me to implement impossible stuff in C++, maybe somewhere along the way I go back to the original idea.*

## Event system 
yes! there is already boost's signal and slots, and you can also use the pattern used extensively in JUCE, but this one tries to mimick the behaviour of events in C#. That is the event is public for subscription and raising the event can be held private for the object that owns the event

## Experiment with dynamic 2d arrays
three different implementations of dynamic arrays are presented:
1. AlignedArray with underlying std::vector
2. AlignedCArray with underlying raw pointers and malloc
3. Simple imlementaiton with new and delete

### Results of the benchmark
Run on (4 X 2900 MHz CPU s)
CPU Caches:
  * L1 Data 32K (x2)
  * L1 Instruction 32K (x2)
  * L2 Unified 262K (x2)
  * L3 Unified 3145K (x1)
Load Average: 2.61, 2.80, 2.80
Benchmark                     |          Time       |      CPU |  Iterations
aligned_array_benchmark/8      |     0.021 us   |     0.020 us  |   31151123
aligned_array_benchmark/16     |     0.057 us   |    0.056 us   |  12282210
aligned_array_benchmark/32     |     0.172 us   |     0.170 us  |    3741275
aligned_array_benchmark/64     |     0.574 us   |     0.570 us  |    1268530
aligned_array_benchmark/128    |      2.32 us   |      2.31 us  |     283960
aligned_array_benchmark/256    |      10.4 us   |      10.3 us  |      68327
aligned_array_benchmark/512    |      58.0 us   |      57.7 us  |      12444
aligned_array_benchmark/1024   |       352 us   |       349 us  |       1936
aligned_array_benchmark/2048   |      1815 us   |      1812 us  |        365
aligned_array_benchmark/4096   |      7222 us   |      7215 us  |        101
aligned_array_benchmark/8192   |     28792 us   |     28743 us  |         25
aligned_c_array_benchmark/8    |     0.019 us   |     0.019 us  |   37516615
aligned_c_array_benchmark/16   |     0.053 us   |     0.053 us  |   13209043
aligned_c_array_benchmark/32   |     0.164 us   |     0.163 us  |    4293399
aligned_c_array_benchmark/64   |     0.540 us   |     0.537 us  |    1302907
aligned_c_array_benchmark/128  |      2.29 us   |      2.29 us  |     299182
aligned_c_array_benchmark/256  |      10.1 us   |      10.1 us  |      70820
aligned_c_array_benchmark/512  |      57.2 us   |      57.1 us  |      12609
aligned_c_array_benchmark/1024 |       354 us   |       352 us  |       1793
aligned_c_array_benchmark/2048 |      1745 us   |      1744 us  |        294
aligned_c_array_benchmark/4096 |      7259 us   |      7245 us  |        101
aligned_c_array_benchmark/8192 |     31104 us   |     31005 us  |         25
array_benchmark/8              |     0.019 us   |     0.019 us  |   37582682
array_benchmark/16             |     0.053 us   |     0.053 us  |   13215027
array_benchmark/32             |     0.165 us   |     0.164 us  |    4258400
array_benchmark/64             |    0.562 us    |    0.559 us   |   1263834
array_benchmark/128            |      2.26 us   |      2.26 us  |     299813
array_benchmark/256            |      12.0 us   |      11.8 us  |      71342
array_benchmark/512            |      57.1 us   |      56.9 us  |      11316
array_benchmark/1024           |       386 us   |       386 us  |       1753
array_benchmark/2048           |      1769 us   |      1763 us  |        285
array_benchmark/4096           |      7326 us   |      7281 us  |         86
array_benchmark/8192           |     35231 us   |     35189 us  |         15
