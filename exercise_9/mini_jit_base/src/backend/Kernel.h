#include <cstdint>
#include <vector>
#include <string>

#ifndef MINI_JIT_BACKEND_KERNEL_H
#define MINI_JIT_BACKEND_KERNEL_H

namespace mini_jit {
  namespace backend {
    class Kernel;
  }
}

class mini_jit::backend::Kernel {
  private:
    //! high-level code buffer
    std::vector< uint32_t > m_codeBuffer;

    //! size of the kernel
    std::size_t m_sizeKernel = 0;

    //! executable kernel
    uint32_t * m_kernel = nullptr;

    //! instruction-offset in bytes since last reset
    uint32_t m_offset = 0;

    /**
     * Allocates memory through POSIX mmap.
     *
     * @param i_nBytes number of bytes.
     **/
    void * allocMmap( std::size_t i_nBytes ) const;

    /**
     * Frees POSIX mmap allocated memory.
     *
     * @param i_nBytes number of bytes.
     * @param i_mem pointer to memory which is freed.
     **/
    void freeMmap( std::size_t   i_nBytes,
                   void        * i_mem ) const;
  
    /**
     * Sets the given memory region executable.
     *
     * @param i_nBytes number of bytes.
     * @param i_mem point to memory.
     **/
    void setExecutable( std::size_t   i_nBytes,
                        void        * i_mem ) const;

    /**
     * Frees the code buffer and frees the kernel if set.
     **/
    void free();

  public:
    /**
     * Destructor
     **/
    ~Kernel();

    /**
     * Adds an instruction to the code buffer.
     *
     * @param i_ins instruction which is added.
     **/
    void addInstruction( uint32_t i_ins );

    /**
     * Resets the offset
     **/
    void resetOffset();

    /**
     * Gets the offset.
     *
     * @return offset in byte since last reset.
     **/
    uint32_t getOffset();

    /**
     * Gets the size of the kernel.
     *
     * @return size of the generated code in byte.
     **/
    uint32_t getSize();

    /**
     * Sets the kernel based on the code buffer.
     **/
    void setKernel();

    /**
     * Gets a pointer to the kernel.
     **/
    void const * getKernel() const;


    /**
     * Writs the code buffer to the given file.
     *
     * @param i_path path to the file.
     **/
    void write( char const *i_path ) const;
};

#endif