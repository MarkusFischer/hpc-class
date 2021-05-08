#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "gemm_ref.hpp"
#include "util.hpp"


TEST_CASE( "Matrices are compared", "[compare_matrices]" ) 
{
    float eye[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    float a[20] = {1, 2, 3, 4, 42, 5, 6, 7, 8, 42, 9, 10, 11, 12, 42, 13, 14, 15, 16, 42};
    float b[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    float c[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
       
    REQUIRE(compare_matrices(eye, eye, 3, 3, 3, 3));
    REQUIRE(compare_matrices(a, a, 4, 4, 5, 5));
    REQUIRE(compare_matrices(b, b, 4, 4, 4, 4));
    REQUIRE(compare_matrices(a, b, 4, 4, 5, 4));
    REQUIRE(compare_matrices(a, c, 4, 4, 5, 4) == false);
    REQUIRE(compare_matrices(b, c, 4, 4, 4, 4) == false);
}

TEST_CASE( "GEMM reference kernel" "[gemm_ref]")
{
    // CASE 1
    float c_1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    float a_1[12] = {1, 4, 7, 25, 2, 5, 8, 25, 3, 6, 9, 25};
    float b_1[9] = {2, 8, 14, 4, 10, 16, 6, 12, 18};
    
    float c_1_res[9] = {61, 132, 204, 72, 163, 252, 84, 192, 301};
    
    gemm_ref(a_1, b_1, c_1, 3, 3, 3, 4, 3, 3); 
    REQUIRE(compare_matrices(c_1_res, c_1, 3, 3, 3, 3));
    
    // CASE 2
    float c_2[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float a_2[16] = {2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2};
    float b_2[16] = {3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3};
    
    float c_2_res[16] = {6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 6};
    
    gemm_ref(a_2, b_2, c_2, 4, 4, 4, 4, 4, 4);
    REQUIRE(compare_matrices(c_2, c_2_res, 4, 4, 4, 4));
    
    // CASE 3
    float c_3[20] = {2, 0, 0, 0, 24, 0, 2, 0, 0, 42, 0, 0, 2, 0, 42, 0, 0, 0, 2, 42};
    float a_3[24] = {3, 0, 0, 0, 52, 67, 0, 3, 0, 0, 215, 123, 0, 0, 3, 0, 5, 24, 0, 0, 0, 3, 42, 42};
    float b_3[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    
    float c_3_res[16] = {5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5};
    
    gemm_ref(a_3, b_3, c_3, 4, 4, 4, 6, 4, 5);
    REQUIRE(compare_matrices(c_3, c_3_res, 4, 4, 5, 4));
    
    // CASE 4
    float c_4[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    float a_4[3] = {1, 2, 3};
    float b_4[3] = {1, 2, 3};
    
    float c_4_res[9] = {1, 2, 3, 2, 4, 6, 3, 6, 9};
    
    gemm_ref(a_4, b_4, c_4, 3, 3, 1, 3, 1, 3);
    REQUIRE(compare_matrices(c_4, c_4_res, 3, 3, 3, 3));
    
    // CASE 5
    float c_5[1] = {0};
    float a_5[3] = {0.9653f, 0.2732f, 0.4596f};
    float b_5[3] = {0.5098f, 0.8970f, 0.7755f};
    
    float c_5_res[1] = {1.0937f};
    
    gemm_ref(a_5, b_5, c_5, 1, 1, 3, 1, 3, 1);
    REQUIRE(compare_matrices(c_5, c_5_res, 1, 1, 1, 1, 1.0e-3));
}
