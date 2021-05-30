# Optimizations

## Baseline

The baseline approach is roughly the idea from the lecture. With this I achieved a performance of 20.30 GFLOPS.

## No stack usage

As a first optimization stack I got ride of the stack usage. This meant, that I reordered the register usages. After this it was not necessary to save registers d8 to d15 (and the x registers) on the stack, saving store and load operations.
This increased the performance to 24.36 GFLOPS

## Opposite store

As a final optimization step I tried to reorder the write back of the Matrix C to get ride of the first sub operation. That meant I stored the last column first then the second-last and so one. However, I gained no further performance boost. Instead compared to the non stack usage variant my performance dropped to 23.25 GFLOPS so I reverted back.

# Best performing solutions

Name | time (s) | #executions | GFLOPS | %peak
----------------------------------------------
Markus' ASM (16x4x4)  | 2.10127 | 100000000 | 24.36 | 60.9
Markus' ASM (16x4x12) | 4.6028  | 100000000 | 33.37 | 83.4
