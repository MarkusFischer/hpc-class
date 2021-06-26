#include "MyExample.h"

uint32_t ( *mini_jit::generators::MyExample::generate(uint32_t i_fac) )() {
  uint32_t l_ins = 0;

  // init output
  l_ins = instructions::Base::dpMovImm( 0,
                                        1,
                                        1 );
  m_kernel.addInstruction( l_ins );

  l_ins = instructions::Base::dpMovImm( 1,
                                        i_fac,
                                        1 );
  m_kernel.addInstruction( l_ins );

  m_kernel.resetOffset();

  //multiply
  l_ins = instructions::Base::dpMulReg( 0, 
                                        1,
                                        0, 
                                        1 );
  m_kernel.addInstruction( l_ins );

  // decrease loop-counter
  l_ins = instructions::Base::dpSubImm( 1,
                                        1,
                                        1,
                                        1 );
  m_kernel.addInstruction( l_ins );

  int32_t l_jumpPc = -m_kernel.getOffset() / 4;
  l_ins = instructions::Base::bCbnz( 1,
                                     l_jumpPc,
                                     1 );
  m_kernel.addInstruction( l_ins );                                
  
  // ret
  l_ins = instructions::Base::bRet();
  m_kernel.addInstruction( l_ins );

  // we might debug through file-io
  std::string l_file = "myexample.bin";
  m_kernel.write( l_file.c_str() );

  m_kernel.setKernel();

  return (uint32_t (*)()) m_kernel.getKernel();
}