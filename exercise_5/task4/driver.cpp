#include <cstdint>
#include <iostream>


extern "C" 
{
void gemm_asm_gp( uint32_t const * i_a,
                  uint32_t const * i_b,
                  uint32_t       * io_c );

}

int main()
{

    uint32_t a[8] = {1, 2, 3, 5, 7, 11, 13, 17};
    uint32_t b[4] = {1, 2, 3, 4};
    uint32_t c[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    //NOTE more unit tests would be better but ... better than nothing
    uint32_t c_res[8] = {16, 26, 32, 43, 36, 56, 68, 91};
    
    gemm_asm_gp(a, b, c);
    
    std::cout << "Comparing results... " << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        if (c[i] != c_res[i])
        {
            std::cout << "Found mismatch at index " << i << " c:" << c[i] << " != c_res:" << c_res[i] << std::endl; 
        }
    }
    return 0;
}
