#include <iostream>

extern "C" {
    int32_t load_store_0( int32_t const * i_a);
    void load_store_1( uint64_t const * i_a, uint64_t * o_b);
    void load_store_2( int64_t const * i_a, int64_t * o_b);
    void load_store_3();
}

int main(int i_argc, char * i_argv[])
{
    // first example
    int32_t l_data0 = 7743;
    int32_t * l_ptr0 = &l_data0
    
    std::cout << "l_data0 / l_ptr0 / return value: "
              << l_data0 << " / "
              << l_ptr0 << " / "
              << load_store_0( l_ptr0 )
              << std::endl;
    return EXIT_SUCCESS;
}
