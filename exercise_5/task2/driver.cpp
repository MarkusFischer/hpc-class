#include <cstdint>
#include <cstdlib>

extern "C" {
  void load_asm( uint64_t const * i_a );
}

int main() {
  uint64_t * l_a = new uint64_t[10];
  for( unsigned short l_va = 0; l_va < 10; l_va++ ) {
    l_a[l_va] = (l_va+1)*100;
  }

  // ok
  load_asm( l_a+2 );

  // not ok #1
  // load_asm( l_a+12 );

  // not ok #2
  // load_asm( l_a+8 );

  // not ok #3
  // load_asm( l_a+6 );

  delete[] l_a;

  return EXIT_SUCCESS;
}
