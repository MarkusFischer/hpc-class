#include "Simple.h"

uint32_t ( *mini_jit::generators::Simple::generate() )() {
  uint32_t l_ins = 0;

  // mov w0, #0x3
  l_ins = instructions::Base::dpMovImm( 0,
                                        3,
                                        0 );
  m_kernel.addInstruction( l_ins );

  // ret
  l_ins = instructions::Base::bRet();
  m_kernel.addInstruction( l_ins );


  // we might debug through file-io
  std::string l_file = "simple.bin";
  m_kernel.write( l_file.c_str() );

  m_kernel.setKernel();

  return (uint32_t (*)()) m_kernel.getKernel();
}