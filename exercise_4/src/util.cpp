#include <cmath>

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
