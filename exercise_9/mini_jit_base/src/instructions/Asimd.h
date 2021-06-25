#ifndef MINI_JIT_INSTRUCTIONS_ASIMD_H
#define MINI_JIT_INSTRUCTIONS_ASIMD_H

#include <cstdint>

namespace mini_jit {
  namespace instructions {
    class Asimd;
  }
}

class mini_jit::instructions::Asimd {
  public:
    //! arrangement specifiers
    enum arrspec_t: char {
      s2 = 0,
      s4 = 1,
      d2 = 2
    };

    //! register sizes
    enum regsize_t: char {
      b = 0,
      h = 1,
      s = 2,
      d = 3,
      q = 4
    };

    /**
     * Gets the machine code for load SIMD&FP register (immediate offset, unsigned offset)
     *
     * @param i_regSimdDes SIMD&FP destination register.
     * @param i_regGpAddr general purpose register holding the address from which data is loaded.
     * @param i_regSize size of of register to which data is loaded.
     * @param i_imm12 value of the 12-bit immediate.
     *
     * @return instruction.
     **/
    static uint32_t lsLdrImmUnsOff( uint8_t   i_regSimdDes,
                                    uint8_t   i_regGpAddr,
                                    regsize_t i_regSize,
                                    uint16_t  i_imm12 );

    /**
     * Gets the machine code for store SIMD&FP register (immediate offset, unsigned offset)
     *
     * @param i_regSimdDes SIMD&FP destination register.
     * @param i_regGpAddr general purpose register holding the address to which the data is stored.
     * @param i_regSize size of register whose data is stored.
     * @param i_imm12 value of the 12-bit immediate.
     *
     * @return instruction.
     **/
    static uint32_t lsStrImmUnsOff( uint8_t   i_regSimdDes,
                                    uint8_t   i_regGpAddr,
                                    regsize_t i_regSize,
                                    uint16_t  i_imm12 );

    /**
     * Gets the machine code for load multiple structures (no offset).
     *
     * @param i_regSimdDes first or only SIMD&FP destination register.
     * @param i_regGpAddr general purpose register holding the address from which data is loaded.
     * @param i_arrSpec arrangement specifier.
     * @param i_nStructures number of structures which are loaded. 1, 2, 3 or 4.
     *
     * @return instruction.
     **/
    static uint32_t lsLd1MultipleNoOff( uint8_t   i_regSimdDes,
                                        uint8_t   i_regGpAddr,
                                        arrspec_t i_arrSpec,
                                        uint8_t   i_nStructures );

    /**
     * Gets the machine code for store multiple structures (no offset).
     *
     * @param i_regSimdDes first or only SIMD&FP destination register.
     * @param i_regGpAddr general purpose register holding the address to where the data is stored.
     * @param i_arrSpec arrangement specifier.
     * @param i_nStructures number of structures which are stored. 1, 2, 3 or 4.
     *
     * @return instruction.
     **/
    static uint32_t lsSt1MultipleNoOff( uint8_t   i_regSimdDes,
                                        uint8_t   i_regGpAddr,
                                        arrspec_t i_arrSpec,
                                        uint8_t   i_nStructures );

    /**
     * Gets the machine code for floating-point move immediate (vector).
     *
     * @param i_regSimdDes SIMD&FP destination register.
     * @param i_imm8 value of the 8-bit immediate.
     * @param i_arrSpec arrangement specifier.
     *
     * @return instruction.
     **/
    static uint32_t dpFmovVectorImm( uint8_t   i_regSimdDes,
                                     uint8_t   i_imm8,
                                     arrspec_t i_arrSpec );
};

#endif
