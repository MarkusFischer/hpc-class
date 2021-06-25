#include "Loop.h"

uint32_t ( *mini_jit::generators::Loop::generate( uint32_t i_nIterations ) )() {
  uint32_t l_ins = 0;

  // init output
  l_ins = instructions::Base::dpMovImm( 0,
                                        0,
                                        0 );
  m_kernel.addInstruction( l_ins );

  // set loop counter
  l_ins = instructions::Base::dpMovImm( 1,
                                        i_nIterations,
                                        0 );
  m_kernel.addInstruction( l_ins );

  // reset offset
  m_kernel.resetOffset();

  // increase output
  l_ins = instructions::Base::dpAddImm( 0,
                                        0,
                                        1,
                                        0 );
  m_kernel.addInstruction( l_ins );

  // decrease loop-counter
  l_ins = instructions::Base::dpSubImm( 1,
                                        1,
                                        1,
                                        0 );
  m_kernel.addInstruction( l_ins );

  // loop if required
  int32_t l_jumpPc = -m_kernel.getOffset() / 4;
  l_ins = instructions::Base::bCbnz( 1,
                                     l_jumpPc,
                                     0 );
  m_kernel.addInstruction( l_ins );


  // ret
  l_ins = instructions::Base::bRet();
  m_kernel.addInstruction( l_ins );

  // we might debug through file-io
  // std::string l_file = "loop.bin";
  // m_kernel.write( l_file.c_str() );

  m_kernel.setKernel();

  return (uint32_t (*)()) m_kernel.getKernel();
}