## Task 4.1 

Compiling and executing test (Note to myself: makefile!):

g++ -o gemm_ref_test src/gemm_ref_test.cpp src/gemm_ref.cpp src/util.cpp

Test passed

## Task 4.2 and 4.3

Expected floating point operations:

For C_{i,j} we have to multiply k times and add k - 1 times. Total: 2k - 1 Operations

C has m \cdot n entrys. Therefor the total number of floating point operations is: mn(2k -1).


Compiling: 

g++ -O{i} -o driver_O{i} src/driver.cpp src/gemm_ref.cpp src/util.cpp src/gemm_compiler_32_32_32_32_32_32.cpp

i \in {0, 2, 3}

Note: I'm not printing GFLOPS to the command line but FLOPS. Wrong in the result log file. 

Performance for no optimization: 
For the reference kernel we get roughly 3e+8 FLOPS (0.3 GFLOPS).
The optimized kernel has a performance of ~0.4 GFLOPS

Optimization level 2 increases the performance of the reference kernel to 2 GFLOPS where the optimized kernel reaches ~2.3 GFLOPS

At optimization level 3 the performance of the reference kernel increases slightly to 2.2 GFLOPS where the performance of the optimized kernel stays nearly the same. 

However, comparing the mnk and the nkm version of the kernel the latter one perform slightly better. The reason for this might be the usage of the cache and a better locality of the nkm version.
