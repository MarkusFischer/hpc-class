#include "util.hpp"
#include "gemm_ref.hpp"

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
        
        auto start_time = std::chrono::high_resoultion_clock::now();
        for (size_t i = 0; i < iterations; ++i) 
        {
            gemm_ref(A, B, C, lambda, lambda, lambda, lambda, lambda, lambda);
        }
        auto end_time = std::chrono::high_resoultion_clock::now();
        auto needed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        
        std::cout << "Needed time for " << iterations << " multiplications: " << needed_time << std::endl;
        std::cout << "Average time: " << needed_time / iterations << std::endl;
        std::cout << "Sustained GFLOPS: " << flop_gemm * iterations / needed_time << std::endl;
        delete[] A;
        delete[] B;
        delete[] C;
    }
}
