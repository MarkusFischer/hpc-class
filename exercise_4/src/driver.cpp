#include "util.hpp"
#include "gemm_ref.hpp"
#include "gemm_compiler_32_32_32_32_32_32.hpp"

#include <vector>
#include <iostream>
#include <chrono>

int main()
{
    std::vector<unsigned int> lambdas = {4, 8, 12, 16, 24, 32, 48, 64};
    const unsigned int iterations = 10;
    
    for (auto lambda : lambdas) 
    {
        std::cout << " M = N = K = ld A = ld B = ld C = " << lambda << std::endl;
        std::cout << " Initializing random matrices..." << std::endl;
        float* A = random_matrix(lambda, lambda, lambda);
        float* B = random_matrix(lambda, lambda, lambda);
        float* C = random_matrix(lambda, lambda, lambda);
        
        int flop_gemm = lambda * lambda * (2 * lambda - 1);
        std::cout << "Necessary floating point operations per gemm: " << flop_gemm << std::endl;
        
        std::cout << "Starting time measuring." << std::endl;
        
        auto start_time = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < iterations; ++i) 
        {
            gemm_ref(A, B, C, lambda, lambda, lambda, lambda, lambda, lambda);
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        //std::chrono::duration<double, std::seconds> needed_time = end_time - start_time;
        std::chrono::duration<double> needed_time = end_time - start_time;
        
        std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
        std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
        std::cout << "Sustained GFLOPS: " << flop_gemm * iterations / needed_time.count() << std::endl;
        delete[] A;
        delete[] B;
        delete[] C;
    }
    
    std::cout << "###########################" << std::endl << std::endl;
    
    float* A = random_matrix(32, 32, 32);
    float* B = random_matrix(32, 32, 32);
    float* C_ref = zero_matrix(32, 32, 32);
    float* C_mnk = zero_matrix(32, 32, 32);
    float* C_nkm = zero_matrix(32, 32, 32);
      
    std::cout << "Comparing results... " << std::endl;
    gemm_ref(A, B, C_ref, 32, 32, 32, 32, 32, 32);
    gemm_compiler_32_32_32_32_32_32_mnk(A, B, C_mnk);
    gemm_compiler_32_32_32_32_32_32_nkm(A, B, C_nkm);
    
    if (compare_matrices(C_ref, C_mnk, 32, 32, 32, 32) && compare_matrices(C_ref, C_nkm, 32, 32, 32, 32))
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cerr << "Test failed!" << std::endl;
    }
    
    std::cout << "Measuring performance... " << std::endl;
    int flop_gemm = 32 * 32 * (2 * 32 - 1);
    std::cout << "Necessary floating point operations per gemm: " << flop_gemm << std::endl;
    
    std::cout << "gemm_compiler_32_32_32_32_32_32_mnk:" << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) 
    {
        gemm_compiler_32_32_32_32_32_32_mnk(A, B, C_mnk);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> needed_time = end_time - start_time;
        
    std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
    std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
    std::cout << "Sustained GFLOPS: " << flop_gemm * iterations / needed_time.count() << std::endl;
    
    
    std::cout << "gemm_compiler_32_32_32_32_32_32_nkm:" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) 
    {
        gemm_compiler_32_32_32_32_32_32_nkm(A, B, C_mnk);
    }
    end_time = std::chrono::high_resolution_clock::now();
    needed_time = end_time - start_time;
        
    std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
    std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
    std::cout << "Sustained GFLOPS: " << flop_gemm * iterations / needed_time.count() << std::endl;
    
    
    delete[] A;
    delete[] B;
    delete[] C_ref;
    delete[] C_mnk;
    delete[] C_nkm;

}
