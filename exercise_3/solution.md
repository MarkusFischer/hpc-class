# Task 1: key metrics

instruction | used pipelines   | latency | throughput
-----------------------------------------------------
fmul        | FP/ASIMD 0 and 1 |       3 |         2

fmla        | FP/ASIMD 0 and 1 |       4 |         2


# Task 2: theoretical peak performance

operations / second = frequency * operations / cycle

Frequency: f = 2.5 GHz = 2.5 * 10^9 Hz

Our pipeline is bound by the latency. In this case the throughput per pipeline is 1/3 (or 1/4 in case of fmla).

operations / cycle = 1/latency * p where p is 2 for double precision and 4 for single precision

tpp_fmul_sp = 2.5 * 10^9 * 1/3 * 4 = 3.333... GFLOPS
tpp_fmla_sp = 2.5 * 10^9 * 1/4 * 4 = 2.5 GFLOPS

# Task 3: micro-benchmark fmla


# Task 4: micro-benchmark fmul


# Task 5: data dependency destination register

