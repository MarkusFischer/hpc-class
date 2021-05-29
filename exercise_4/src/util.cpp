#include <cmath>
#include <random>

#include "util.hpp"

bool compare_matrices(float const* i_a,
                      float const* i_b,
                      unsigned int i_m,
                      unsigned int i_n,
                      unsigned int i_lda,
                      unsigned int i_ldb,
                      float eps)
{
    for (size_t m = 0; m < i_m; ++m)
    {
        for (size_t n = 0; n < i_n; ++n)
        {
            if (std::abs(i_a[(n * i_lda) + m] - i_b[(n * i_ldb) + m]) > eps)
                return false;
        }
    }
    return true;
}


float* random_matrix(unsigned int i_m, 
                     unsigned int i_n, 
                     unsigned int i_ld)
{
    if (i_ld < i_m)
    {
        return nullptr;
    }
    
    std::random_device rd;
    
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(0, 1);
    
    float* matrix = new float[i_n * i_ld];
    
    for (size_t m = 0; m < i_ld; ++m)
    {
        for (size_t n = 0; n < i_n; ++n)
        {
            matrix[(n * i_ld) + m] = 0;
        }
    }
    
    for (size_t m = 0; m < i_m; ++m)
    {
        for (size_t n = 0; n < i_n; ++n)
        {
            matrix[(n * i_ld) + m] = dist(e2);
        }
    }
    return matrix;
}


float* zero_matrix(unsigned int i_m, 
                     unsigned int i_n, 
                     unsigned int i_ld)
{
    if (i_ld < i_m)
    {
        return nullptr;
    }
    
    float* matrix = new float[i_n * i_ld];
    
    for (size_t m = 0; m < i_m; ++m)
    {
        for (size_t n = 0; n < i_n; ++n)
        {
            matrix[(n * i_ld) + m] = 0;
        }
    }
    return matrix;
}
