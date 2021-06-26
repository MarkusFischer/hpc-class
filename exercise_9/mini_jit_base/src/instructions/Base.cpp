#include "Base.h"

uint32_t mini_jit::instructions::Base::bRet() {
  return 0xd65f03c0;
}

uint32_t mini_jit::instructions::Base::bCbnz( uint8_t i_regGp,
                                              int32_t i_imm19,
                                              uint8_t i_size ) {
  uint32_t l_ins = 0x35000000;
  l_ins |= 0x1f & i_regGp;
  l_ins |= (0x7FFFF & i_imm19) << 5;
  l_ins |= (0x1 & i_size) << 31;

  return l_ins;
}

uint32_t mini_jit::instructions::Base::dpMovImm( uint8_t  i_regGp,
                                                 uint16_t i_imm16,
                                                 uint8_t  i_size ) {
  uint32_t l_ins = 0x52800000;
  l_ins |= 0x1f & i_regGp;
  l_ins |= i_imm16 << 5;
  l_ins |= (0x1 & i_size) << 31;

  return l_ins;
}

uint32_t mini_jit::instructions::Base::dpMovReg( uint8_t  i_regGpDes,
                                                 uint8_t i_regGpSrc,
                                                 uint8_t  i_size )
{
  uint32_t l_ins = 0xAA0003E0;
  l_ins |= 0x1f & i_regGpDes;
  l_ins |= (0x1f & i_regGpSrc) << 16;
  l_ins |= (0x1 & i_size) << 31;

  return l_ins;
}

uint32_t mini_jit::instructions::Base::dpAddImm( uint8_t  i_regGpDes,
                                                 uint8_t  i_regGpSrc,
                                                 uint16_t i_imm12,
                                                 uint8_t  i_size ) {
  uint32_t l_ins = 0x11000000;

  l_ins |= 0x1f & i_regGpDes;
  l_ins |= (0x1f & i_regGpSrc) << 5;
  l_ins |= (0xfff & i_imm12) << 10;
  l_ins |= (0x1 & i_size) << 31;

  return l_ins;
}

uint32_t mini_jit::instructions::Base::dpSubImm( uint8_t  i_regGpDes,
                                                 uint8_t  i_regGpSrc,
                                                 uint16_t i_imm12,
                                                 uint8_t  i_size ) {
  uint32_t l_ins = 0x51000000;

  l_ins |= 0x1f & i_regGpDes;
  l_ins |= (0x1f & i_regGpSrc) << 5;
  l_ins |= (0xfff & i_imm12) << 10;
  l_ins |= (0x1 & i_size) << 31;

  return l_ins;
}

uint32_t mini_jit::instructions::Base::dpMulReg( uint8_t i_regGpDes,
                                                 uint8_t i_regGpSrc1,
                                                 uint8_t i_regGpSrc2,
                                                 uint8_t i_size )
{
  uint32_t l_ins = 0x9B007C00;

  l_ins |= 0x1f & i_regGpDes;
  l_ins |= 0x1f & i_regGpSrc1 << 5;
  l_ins |= 0x1f & i_regGpSrc2 << 16;
  l_ins |= (0x1 & i_size) << 31;

  return l_ins;
}