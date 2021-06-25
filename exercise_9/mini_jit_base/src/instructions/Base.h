#ifndef MINI_JIT_INSTRUCTIONS_BASE_H
#define MINI_JIT_INSTRUCTIONS_BASE_H

#include <cstdint>

namespace mini_jit {
  namespace instructions {
    class Base;
  }
}

class mini_jit::instructions::Base {
  public:
    /**
     * Gets the machine code for the return instruction.
     * 
     * @return return instruction.
     **/ 
    static uint32_t bRet();

     /**
      * Gets the machine code for compare and branch on nonzero.
      *
      * @param i_regGp general purpose register which is compared.
      * @param i_imm19 value of the 19-bit immediate.
      * @param i_size 32-bit version if 0, 64-bit version if 1.
      *
      * @return instruction.
      **/
    static uint32_t bCbnz( uint8_t i_regGp,
                           int32_t i_imm19,
                           uint8_t i_size );

    /**
     * Gets the machine code for a move.
     *
     * @param i_regGp general purpose register which is set.
     * @param i_imm16 value of the 16-bit immediate.
     * @param i_size 32-bit version if 0, 64-bit version if 1.
     *
     * @return instruction.
     **/
    static uint32_t dpMovImm( uint8_t  i_regGp,
                              uint16_t i_imm16,
                              uint8_t  i_size );

    /**
     * Gets the machine code for add immediate.
     *
     * @param i_regGpDes general purpose destination register.
     * @param i_regGpSrc general purpose source register.
     * @param i_imm12 value of the 12-bit immediate.
     * @param i_size 32-bit version if 0, 64-bit version if 1.
     *
     * @return instruction.
     **/
    static uint32_t dpAddImm( uint8_t  i_regGpDes,
                              uint8_t  i_regGpSrc,
                              uint16_t i_imm12,
                              uint8_t  i_size );

    /**
     * Gets the machine code for sub immediate.
     *
     * @param i_regGpDes general purpose destination register.
     * @param i_regGpSrc general purpose source register.
     * @param i_imm12 value of the 12-bit immediate.
     * @param i_size 32-bit version if 0, 64-bit version if 1.
     *
     * @return instruction.
     **/
    static uint32_t dpSubImm( uint8_t  i_regGpDes,
                              uint8_t  i_regGpSrc,
                              uint16_t i_imm12,
                              uint8_t  i_size );


    /**
     * Gets the machine code for multiply.
     *
     * @param i_regGpDes general purpose destination register.
     * @param i_regGpSrc1 general purpose source register 1.
     * @param i_regGpSrc1 general purpose source register 2.
     * @param i_size 32-bit version if 0, 64-bit version if 1.
     *
     * @return instruction.
     **/
    static uint32_t dpMulReg( uint8_t i_regGpDes,
                              uint8_t i_regGpSrc1,
                              uint8_t i_regGpSrc2,
                              uint8_t i_size );
};

#endif