#include "util.hpp"
#include "gemm_ref.hpp"

#include <vector>
#include <iostream>
#include <chrono>

#include <libxsmm.h>

int main()
{
    std::vector<unsigned int> lambdas = {4, 8, 12, 16, 24, 32, 48, 64};
    const unsigned int iterations = 100000;
    
    
    
    
    for (auto lambda : lambdas) 
    {
        int m = lambda;
        int n = lambda;
        int k = lambda;
        int lda = lambda;
        int ldb = lambda;
        int ldc = lambda;
        std::cout << "#######################################" << std::endl; 
        std::cout << " M = N = K = ld A = ld B = ld C = " << lambda << std::endl;
        std::cout << " Initializing random matrices..." << std::endl;
        float* A = random_matrix(m, k, lda);
        float* B = random_matrix(k, n, ldb);
        float* C = random_matrix(m, n, ldc);
        
        int flop_gemm = lambda * lambda * (2 * lambda);
        std::cout << "Necessary floating point operations per gemm: " << flop_gemm << std::endl;
        
        std::cout << "Starting time measuring (reference kernel)." << std::endl;
        
        float* A_test = random_matrix(m, k, lda);
        float* B_test = random_matrix(k, n, ldb);
        float* C_ref = zero_matrix(m, n, ldc);
        float* C_xsmm = zero_matrix(m, n, ldc);
      
        
        gemm_ref(A_test, B_test, C_ref, m, n, k, lda, ldb, ldc);
        
        auto start_time = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < iterations; ++i) 
        {
            gemm_ref(A, B, C, m, n, k, lda, ldb, ldc);
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double> needed_time = end_time - start_time;
        
        std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
        std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
        std::cout << "Sustained FLOPS: " << flop_gemm * iterations / needed_time.count() << std::endl;
        
             
        std::cout << std::endl << "Performance of libxsmm kernel" << std::endl;
        
        float alpha = 1.0, beta = 1.0;
        int flags = LIBXSMM_GEMM_FLAG_NONE;
        libxsmm_smmfunction kernel = libxsmm_smmdispatch(m, n, k, &lda, &ldb, &ldc, &alpha, &beta, &flags, nullptr /*prefetch*/);
        
        kernel(A_test, B_test, C_xsmm);
        
        std::cout << "Comparing results... " << std::endl;
        if (compare_matrices(C_ref, C_xsmm, m, n, ldc, ldc))
        {
            std::cout << "Test passed!" << std::endl;
        }
        else
        {
            std::cerr << "Test failed!" << std::endl;
        }
        
        std::cout << "Starting time measuring (libxsmm kernel)." << std::endl;
        start_time = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < iterations; ++i) 
        {
            kernel(A, B, C);
        }
        end_time = std::chrono::high_resolution_clock::now();
        
        needed_time = end_time - start_time;
        
        std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
        std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
        std::cout << "Sustained FLOPS: " << flop_gemm * iterations / needed_time.count() << std::endl;
        
	std::cout << "################################" << std::endl << std::endl;
        delete[] A;
        delete[] B;
        delete[] C;
    }
    
    
}
