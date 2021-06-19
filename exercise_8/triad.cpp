#include <iostream>
#include <cstdint>

extern "C"
{
    void triad_low( uint64_t         i_nValues,
                    float    const * i_a,
                    float    const * i_b,
                    float          * o_c );

}

void triad_high( uint64_t         i_nValues,
                 float    const * i_a,
                 float    const * i_b,
                 float          * o_c ) {
  for( uint64_t l_va = 0; l_va < i_nValues; l_va++ ) {
    o_c[l_va] = i_a[l_va] + 2.0f * i_b[l_va];
  }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " nValues" << std::endl;
        return 0;
    }
    
    uint64_t n_values = atoi(argv[1]);

    //allocate Memory
    float* a = new float[n_values];
    float* b = new float[n_values];
    float* c_low = new float[n_values];
    float* c_high = new float[n_values];

    //fill a and b with values
    for (uint64_t i = 0; i < n_values; i++)
    {
        a[i] = i;
        b[i] = i % 10;
    }

    //run triad
    triad_high(n_values, a, b, c_high);

    triad_low(n_values, a, b, c_low);

    //compare results
    float max_diff = 0;
    for (uint64_t i = 0; i < n_values; i++)
    {
        max_diff = std::max(max_diff, std::abs(c_low[i] - c_high[i]));
    }
    
    if (max_diff < 10e-6)
    {
        std::cout << "Compared " << n_values << " values and triad_high and triad_low had same results" << std::endl;
    }
    else
    {
        std::cout << "Compared " << n_values << " values and triad_high and triad_low had different results" << std::endl;
    }

    delete[] a;
    delete[] b;
    delete[] c_low;
    delete[] c_high;

    return 0;
}