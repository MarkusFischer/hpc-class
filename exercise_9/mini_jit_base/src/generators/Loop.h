#ifndef MINI_JIT_GENERATORS_LOOP_H
#define MINI_JIT_GENERATORS_LOOP_H

#include "../backend/Kernel.h"
#include "../instructions/Base.h"

namespace mini_jit {
  namespace generators {
    class Loop;
  }
}

class mini_jit::generators::Loop {
  private:
    //! kernel backend
    backend::Kernel m_kernel;
    
  public:
    /**
     * Generates a kernel which increments x0 through a loop.
     *
     * @param i_nIterations number of iterations in the loop.
     * @return function pointer to kernel.
     **/
    uint32_t ( *generate( uint32_t i_nIterations ) )();
};

#endif