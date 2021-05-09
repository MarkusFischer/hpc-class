#include "gemm_compiler_32_32_32_32_32_32.hpp"
#include <cstddef>


void gemm_compiler_32_32_32_32_32_32_mnk(float const* i_a,
                                         float const* i_b,
                                         float*       io_c)
{
    for (size_t m = 0; m < 32; ++m) 
    {
        for (size_t n = 0; n < 32; ++n)
        {
            for (size_t k = 0; k < 32; ++k)
            {
                io_c[(32 * n) + m] += i_a[(32 * k) + m] * i_b[(32 * n) + k];
            }
        }
    }
}


void gemm_compiler_32_32_32_32_32_32_nkm(float const* i_a,
                                         float const* i_b,
                                         float*       io_c)
{
    for (size_t n = 0; n < 32; ++n)
    {
        for (size_t k = 0; k < 32; ++k)
        {
            for (size_t m = 0; m < 32; ++m) 
            {
                io_c[(32 * n) + m] += i_a[(32 * k) + m] * i_b[(32 * n) + k];
            }
        }
    }
}
