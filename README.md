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
Benchmark | Time | CPU | Iterations
aligned_array_benchmark/8 | 0.021 us | 0.020 us | 31151123|
aligned_array_benchmark/256 | 10.4 us | 10.3 us | 68327|
aligned_array_benchmark/8192 |     28792 us   |     28743 us  |         25|
aligned_c_array_benchmark/8 |     0.019 us   |     0.019 us  |   37516615|
aligned_c_array_benchmark/256 |      10.1 us   |      10.1 us  |      70820|
aligned_c_array_benchmark/8192 |     31104 us   |     31005 us  |         25|
array_benchmark/8              |     0.019 us   |     0.019 us  |   37582682|
array_benchmark/256            |      12.0 us   |      11.8 us  |      71342|
array_benchmark/8192           |     35231 us   |     35189 us  |         15|
