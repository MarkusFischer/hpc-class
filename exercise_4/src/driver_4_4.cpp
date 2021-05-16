#include "util.hpp"
#include "gemm_ref.hpp"

#include <vector>
#include <iostream>
#include <chrono>

#include <libxsmm.h>

int main()
{
    std::vector<unsigned int> lambdas = {4, 8, 12, 16, 24, 32, 48, 64};
    const unsigned int iterations = 10000;
    
    for (auto lambda : lambdas) 
    {
        unsigned int m = lambda;
        unsigned int n = lambda;
        unsigned int k = lambda;
        unsigned int lda = lambda;
        unsigned int ldb = lambda;
        unsigned int ldc = lambda;
        
        std::cout << " M = N = K = ld A = ld B = ld C = " << lambda << std::endl;
        std::cout << " Initializing random matrices..." << std::endl;
        float* A = random_matrix(m, k, lda);
        float* B = random_matrix(k, n, ldb);
        float* C = random_matrix(m, n, ldc);
        
        int flop_gemm = lambda * lambda * (2 * lambda);
        std::cout << "Necessary floating point operations per gemm: " << flop_gemm << std::endl;
        
        std::cout << "Starting time measuring (reference kernel)." << std::endl;
        
        gemm_ref(A, B, C, m, n, k, lda, ldb, ldc);
        
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
        
        std::cout << "###########################" << std::endl << std::endl;
        
        std::cout << "Performance of libxsmm kernel" << std::endl;
        
        double alpha = 1.0, beta = 1.0;
        int flags = LIBXSMM_GEMM_FLAG_NONE;
        libxsmm_dmmfunction kernel = libxsmm_smmdispatch(m, n, k, lda, ldb, ldc, &alpha, &beta, &flags, nullptr /*prefetch*/);
        
        kernel(A, B, C);
        
        
        std::cout << "Starting time measuring (libxsmm kernel)." << std::endl;
        auto start_time = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < iterations; ++i) 
        {
            kernel(A, B, C);
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double> needed_time = end_time - start_time;
        
        std::cout << "Needed time for " << iterations << " multiplications: " << needed_time.count() << std::endl;
        std::cout << "Average time: " << needed_time.count() / iterations << std::endl;
        std::cout << "Sustained FLOPS: " << flop_gemm * iterations / needed_time.count() << std::endl;
        
        delete[] A;
        delete[] B;
        delete[] C;
    }
    
    
}
