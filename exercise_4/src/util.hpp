#ifndef UTIL_HPP
#define UTIL_HPP

bool compare_matrices(float const* i_a,
                      float const* i_b,
                      unsigned int i_m,
                      unsigned int i_n,
                      unsigned int i_lda,
                      unsigned int i_ldb,
                      float eps = 1.0e-5f);

#endif
