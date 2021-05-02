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

Measuring with likwid-bench -t latency_src_asimd_fmla_sp -w S0:1GB:1 
gave as result MFlops/s:               4996.79

This is twice the value compared to the theoretical peak performance. However our Neoverse N1 has two pipelines and so the tpp value must be doubled.

# Task 4: micro-benchmark fmul

Measuring with likwid-bench -t latency_src_asimd_fmul_sp -w S0:1GB:1
gave as result: MFlops/s:               6662.08
Which coincides with the theoretical peak performance of one pipeline and two pipelines used by the Neoverse N1.

# Task 5: data dependency destination register

Measuring with likwid-bench -t latency_dst_asimd_fmla_sp -w S0:1GB:1 
MFlops/s:               9993.08

Measuring with likwid-bench -t latency_dst_asimd_fmul_sp -w S0:1GB:1
MFlops/s:               39968.92

The performance is much higher in both cases.
Since the results are never used again (and especially not by the next instruction) and therefor the pipeline can be kept full. 
