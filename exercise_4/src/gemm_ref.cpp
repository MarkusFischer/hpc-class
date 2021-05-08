#include "gemm_ref.hpp"

#include <cstddef>

void gemm_ref(float const* i_a,
              float const* i_b,
              float      * io_c,
              unsigned int i_m,
              unsigned int i_n,
              unsigned int i_k,
              unsigned int i_lda,
              unsigned int i_ldb,
              unsigned int i_ldc) 
{
    for (size_t m = 0; m < i_m; ++m) 
    {
        for (size_t n = 0; n < i_n; ++n)
        {
            for (size_t k = 0; k < i_k; ++k)
            {
                io_c[(i_ldc * n) + m] += i_a[(i_lda * k) + m] * i_b[(i_ldb * n) + k];
            }
        }
    }
}
