#ifndef MINI_JIT_GENERATORS_LOOP_H
#define MINI_JIT_GENERATORS_LOOP_H

#include "../backend/Kernel.h"
#include "../instructions/Base.h"

namespace mini_jit {
  namespace generators {
    class MyExample;
  }
}

class mini_jit::generators::MyExample {
  private:
    //! kernel backend
    backend::Kernel m_kernel;
    
  public:
    /**
     * Generates a kernel which calculates the faculty of x0 through a loop.
     *
     * @return function pointer to kernel.
     **/
    uint32_t ( *generate() )();
};

#endif