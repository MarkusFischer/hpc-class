#include "../exercise_4/src/util.hpp"
#include "../exercise_4/src/gemm_ref.hpp"

#include <vector>
#include <iostream>
#include <chrono>

extern "C"
{
    void gemm_asm_asimd_16_4_4(float const * i_a,
                               float const * i_b,
                               float       * io_c);
    
    void gemm_asm_asimd_16_4_12(float const * i_a,
                                float const * i_b,
                                float       * io_c);
}

int main()
{
    const unsigned int iterations = 10000;
    const unsigned int m = 16;
    const unsigned int n = 4;
    const unsigned int k = 4;
    
    
    float* A = random_matrix(m, k, m);
    float* B = random_matrix(k, n, k);
    float* C_ref = zero_matrix(m, n, m);
    float* C_kernel = zero_matrix(m, n, m);
        
    gemm_asm_asimd_16_4_4(A, B, C_kernel);
    gemm_ref(A, B, C, m, n, k, m, n, m);
    
    
    std::cout << "Comparing results..." << (compare_matrices(C_ref, C_kernel, m, n, m, m)) ? "passed" : "failed" << std::endl;
    
        
    int flop_gemm = m * n * k * 2;
    std::cout << "Necessary floating point operations per gemm: " << flop_gemm << std::endl;
        
    std::cout << "Starting time measuring." << std::endl;
        
    auto start_time = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) 
    {
        gemm_asm_asimd_16_4_4(A, B, C_kernel);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> needed_time = end_time - start_time;
        
    std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
    std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
    std::cout << "Sustained GFLOPS: " << flop_gemm * ((double) iterations) / needed_time.count() << std::endl;
    
    delete[] A;
    delete[] B;
    delete[] C_ref;
    delete[] C_kernel;
}