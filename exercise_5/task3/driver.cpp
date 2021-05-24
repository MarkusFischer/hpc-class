#include <cstdint>
#include <cstdlib>
#include <iostream>

extern "C" {
  void copy_asm( uint32_t const * i_a,
                 uint64_t       * o_b );
  void copy_c( uint32_t const * i_a,
               uint64_t       * o_b );
}

bool check_and_reset(uint32_t const * i_a, uint64_t* io_b)
{
    bool same = true;
    for (int i = 0; i < 7; ++i)
    {
	//std::cout << "i_a[" << i << "] : " << i_a[i] << " io_b[" << i << "] : " << io_b[i] << std::endl;
        if (i_a[i] != io_b[i])
        {
            same = false;
        }
        io_b[i] = 0;
    }
    return same;
}

int main() {
  uint32_t l_a[7] = { 1, 21, 43, 78, 89, 91, 93 };
  uint64_t l_b[7] = { 0 };

  copy_asm( l_a,
            l_b );
  
  std::cout << "copy_asm ";
  if (check_and_reset(l_a, l_b))
  {
      std::cout << "succeed" << std::endl;
  }
  else
  {
      std::cout << "failed" << std::endl;
  }

  copy_c( l_a,
          l_b );

  std::cout << "copy_c ";
  if (check_and_reset(l_a, l_b))
  {
      std::cout << "succeed" << std::endl;
  }
  else
  {
      std::cout << "failed" << std::endl;
  }
  
  return EXIT_SUCCESS;
}
