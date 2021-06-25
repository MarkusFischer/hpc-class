#include "Kernel.h"
#include <sys/mman.h>
#include <unistd.h>
#include <cassert>
#include <iostream>
#include <fstream>

mini_jit::backend::Kernel::~Kernel() {
  free();
}

void * mini_jit::backend::Kernel::allocMmap( std::size_t i_nBytes ) const {
  void* l_mem = mmap( 0,
                      i_nBytes,
                      PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS,
                      -1,
                      0 );

  return l_mem;
}

void mini_jit::backend::Kernel::freeMmap( std::size_t   i_nBytes,
                                          void        * i_mem ) const {
  munmap( i_mem,
          i_nBytes );
}

void mini_jit::backend::Kernel::setExecutable( std::size_t   i_nBytes,
                                              void        * i_mem ) const {
  mprotect( i_mem,
            i_nBytes,
            PROT_READ | PROT_EXEC );
}

void mini_jit::backend::Kernel::addInstruction( uint32_t i_ins ) {
  m_codeBuffer.push_back( i_ins );
  m_offset += 4;
}

void mini_jit::backend::Kernel::resetOffset() {
  m_offset = 0;
}

uint32_t mini_jit::backend::Kernel::getOffset() {
  return m_offset;
}

uint32_t mini_jit::backend::Kernel::getSize() {
  return m_codeBuffer.size() * 4;
}

void mini_jit::backend::Kernel::setKernel() {
  // alloc mempage
  m_sizeKernel = getpagesize();
  assert( m_sizeKernel >= m_codeBuffer.size()/4 );
  m_kernel = (uint32_t*) allocMmap(  m_sizeKernel );

  // copy machine code over
  for( std::size_t l_in = 0; l_in < m_codeBuffer.size(); l_in++ ) {
    m_kernel[l_in] = m_codeBuffer[l_in];
  }

  // set executable
  setExecutable( m_sizeKernel,
                 m_kernel );
}

void const * mini_jit::backend::Kernel::getKernel() const {
  return m_kernel;
}

void mini_jit::backend::Kernel::free() {
  m_codeBuffer.resize( 0 );
  if( m_kernel != nullptr ) {
    freeMmap( m_sizeKernel,
              m_kernel );
  }
  m_sizeKernel = 0;
}

void mini_jit::backend::Kernel::write( char const *i_path ) const {
  std::ofstream l_out ( i_path,
                        std::ios::out | std::ios::binary );
  if( !l_out ) {
    std::cerr << "error: failed to open file: " << i_path << std::endl;
    return;
  }
  l_out.write( (char*) m_codeBuffer.data(),
               m_codeBuffer.size()*4 );
}