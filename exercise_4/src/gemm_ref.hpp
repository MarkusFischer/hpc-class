#ifndef GEMM_REF_HPP
#define GEMM_REF_HPP

void gemm_ref(float const* i_a,
              float const* i_b,
              float      * io_c,
              unsigned int i_m,
              unsigned int i_n,
              unsigned int i_k,
              unsigned int i_lda,
              unsigned int i_ldb,
              unsigned int i_ldc);

#endif //GEMM_REF_HPP
