## Task 4.1 

Compiling and executing test (Note to myself: makefile!):

g++ -o gemm_ref_test src/gemm_ref_test.cpp src/gemm_ref.cpp src/util.cpp

Test passed

## Task 4.2 and 4.3

Expected floating point operations:

For C_{i,j} we have to multiply k times and add k - 1 times. Total: 2k - 1 Operations

C has m \cdot n entrys. Therefor the total number of floating point operations is: mn(2k -1).

### Optimization level O0:

g++ -O0 -o driver_O0 src/driver.cpp src/gemm_ref.cpp src/util.cpp src/gemm_compiler_32_32_32_32_32_32.cpp
