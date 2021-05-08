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
