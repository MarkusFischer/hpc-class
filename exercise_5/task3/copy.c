#include <stdint.h>

void copy_c(uint32_t const * i_a,
            uint64_t       * o_b)
{
    for (unsigned int i = 0; i < 7; ++i)
    {
        *(o_b + i) = *(i_a + i);
    }
}
