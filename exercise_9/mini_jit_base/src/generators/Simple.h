#ifndef MINI_JIT_GENERATORS_SIMPLE_H
#define MINI_JIT_GENERATORS_SIMPLE_H

#include "../backend/Kernel.h"
#include "../instructions/Base.h"

namespace mini_jit {
  namespace generators {
    class Simple;
  }
}

class mini_jit::generators::Simple {
  private:
    //! kernel backend
    backend::Kernel m_kernel;
    
  public:
    /**
     * Generates a simple kernel which sets the value three to register w0.
     *
     * @return function pointer to kernel.
     **/
    uint32_t ( *generate() )();
};

#endif