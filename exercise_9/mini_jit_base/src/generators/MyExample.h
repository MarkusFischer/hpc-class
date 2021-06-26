#ifndef MINI_JIT_GENERATORS_MYEXAMPLE_H
#define MINI_JIT_GENERATORS_MYEXAMPLE_H

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
     * Generates a kernel which calculates the factorial through a loop.
     *
     * @param i_fac number for which the factorial should be computed
     * @return function pointer to kernel.
     **/
    uint32_t ( *generate(uint32_t i_fac) )();
};

#endif