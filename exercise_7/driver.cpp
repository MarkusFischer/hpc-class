#include "../exercise_4/src/util.hpp"
#include "../exercise_4/src/gemm_ref.hpp"

#include <vector>
#include <iostream>
#include <chrono>

extern "C"
{
    void gemm_asm_asimd_19_4_4(float const * i_a,
                               float const * i_b,
                               float       * io_c);
    
    void gemm_asm_asimd_32_32_32(float const * i_a,
                                 float const * i_b,
                                 float       * io_c);
}

int main()
{
    const unsigned int iterations = 100000000;
    const unsigned int iterations_large = 1000000;
    unsigned int m = 19;
    unsigned int n = 4;
    unsigned int k = 4;
    
    
    float* A = random_matrix(m, k, m);
    float* B = random_matrix(k, n, k);
    float* C_ref = zero_matrix(m, n, m);
    float* C_kernel = zero_matrix(m, n, m);
        
    gemm_asm_asimd_19_4_4(A, B, C_kernel);
    gemm_ref(A, B, C_ref, m, n, k, m, n, m);
    
    std::cout << "19x4x4" << std::endl;
    
    std::cout << "Comparing results...";
    if (compare_matrices(C_ref, C_kernel, m, n, m, m, 1.0e-6f, true))
    {
        std::cout << "passed";
    }
    else
    {
        std::cout << "failed";
    }
    std::cout << std::endl;
    
        
    int flop_gemm = m * n * k * 2;
    std::cout << "Necessary floating point operations per gemm: " << flop_gemm << std::endl;
        
    std::cout << "Starting time measuring." << std::endl;
        
    auto start_time = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) 
    {
        gemm_asm_asimd_19_4_4(A, B, C_kernel);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> needed_time = end_time - start_time;
        
    std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
    std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
    std::cout << "Sustained FLOPS: " << flop_gemm * ((double) iterations) / needed_time.count() << std::endl;
    
    delete[] A;
    delete[] B;
    delete[] C_ref;
    delete[] C_kernel;
    
    std::cout << std::endl << "#################" << std::endl << "32x32x32" << std::endl;
    
    m = 32;
    n = 32;
    k = 32;
    A = random_matrix(m, k, m);
    B = random_matrix(k, n, k);
    C_ref = zero_matrix(m, n, m);
    C_kernel = zero_matrix(m, n, m);
        
    gemm_asm_asimd_32_32_32(A, B, C_kernel);
    gemm_ref(A, B, C_ref, m, n, k, m, k, m);
    
    
    std::cout << "Comparing results...";
    if (compare_matrices(C_ref, C_kernel, m, n, m, m))
    {
        std::cout << "passed";
    }
    else
    {
        std::cout << "failed";
    }
    std::cout << std::endl;
    
        
    flop_gemm = m * n * k * 2;
    std::cout << "Necessary floating point operations per gemm: " << flop_gemm << std::endl;
        
    std::cout << "Starting time measuring." << std::endl;
        
    start_time = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations_large; ++i) 
    {
        gemm_asm_asimd_32_32_32(A, B, C_kernel);
    }
    end_time = std::chrono::high_resolution_clock::now();
    needed_time = end_time - start_time;
        
    std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
    std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
    std::cout << "Sustained FLOPS: " << flop_gemm * ((double) iterations) / needed_time.count() << std::endl;
    
    delete[] A;
    delete[] B;
    delete[] C_ref;
    delete[] C_kernel;
    
}
