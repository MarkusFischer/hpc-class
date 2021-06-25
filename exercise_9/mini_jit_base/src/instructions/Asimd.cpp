#include "Asimd.h"

uint32_t mini_jit::instructions::Asimd::lsLdrImmUnsOff( uint8_t   i_regSimdDes,
                                                        uint8_t   i_regGpAddr,
                                                        regsize_t i_regSize,
                                                        uint16_t  i_imm12 ) {
  uint32_t l_ins = 0x3D400000;

  l_ins |= 0x1f & i_regSimdDes;
  l_ins |= (0x1f & i_regGpAddr) << 5;
  l_ins |= (0xfff & i_imm12) << 10;

  uint8_t l_opc = 0b01;
  if( i_regSize == regsize_t::q ) {
    l_opc = 0b11;
  }
  l_ins |= l_opc << 22;

  uint8_t l_size = 0;
  if( i_regSize == regsize_t::h ) {
    l_size = 0b01;
  }
  else if( i_regSize == regsize_t::s ) {
    l_size = 0b10;
  }
  else if( i_regSize == regsize_t::d ) {
    l_size = 0b11;
  }
  l_ins |= l_size << 30;

  return l_ins;
}

uint32_t mini_jit::instructions::Asimd::lsStrImmUnsOff( uint8_t   i_regSimdDes,
                                                        uint8_t   i_regGpAddr,
                                                        regsize_t i_regSize,
                                                        uint16_t  i_imm12 ) {
  uint32_t l_ins = lsLdrImmUnsOff( i_regSimdDes,
                                   i_regGpAddr,
                                   i_regSize,
                                   i_imm12 );
  l_ins &= ~(0b1 << 22);

  return l_ins;
}

uint32_t mini_jit::instructions::Asimd::lsLd1MultipleNoOff( uint8_t   i_regSimdDes,
                                                            uint8_t   i_regGpAddr,
                                                            arrspec_t i_arrSpec,
                                                            uint8_t   i_nStructures ) {
  uint32_t l_ins = 0xC402000;

  l_ins |= 0x1f & i_regSimdDes;
  l_ins |= (0x1f & i_regGpAddr) << 5;

  if( i_arrSpec == arrspec_t::s2 ) {
    l_ins |= 0b10 << 10;
    l_ins |= 0b0 << 30;
  }
  else if( i_arrSpec == arrspec_t::s4 ) {
    l_ins |= 0b10 << 10;
    l_ins |= 0b1 << 30;
  }
  else if( i_arrSpec == arrspec_t::d2 ) {
    l_ins |= 0b11 << 10;
    l_ins |= 0b1 << 30;
  }

  uint8_t l_opCode = 0;
  if( i_nStructures == 1 ) {
    l_opCode = 0b0111;
  }
  else if( i_nStructures == 2 ) {
    l_opCode = 0b1010;
  }
  else if( i_nStructures == 3 ) {
    l_opCode = 0b0110;
  }
  else {
    l_opCode = 0b0010;
  }
  l_ins |= l_opCode << 12;

  return l_ins;
}

uint32_t mini_jit::instructions::Asimd::lsSt1MultipleNoOff( uint8_t   i_regSimdDes,
                                                            uint8_t   i_regGpAddr,
                                                            arrspec_t i_arrSpec,
                                                            uint8_t   i_nStructures ) {
  uint32_t l_ins = lsLd1MultipleNoOff( i_regSimdDes,
                                       i_regGpAddr,
                                       i_arrSpec,
                                       i_nStructures );
  l_ins &= ~(0b1 << 22);

  return l_ins;
}

uint32_t mini_jit::instructions::Asimd::dpFmovVectorImm( uint8_t   i_regSimdDes,
                                                         uint8_t   i_imm8,
                                                         arrspec_t i_arrSpec ) {
  uint32_t l_ins = 0xf00f400;

  l_ins |= 0x1f & i_regSimdDes;

  // set a, b, c
  l_ins |= (0b111 & (i_imm8 >> 5)) << 16;
  // set d, e, f, g, h
  l_ins |= (0b11111 & i_imm8) << 5;

  if( i_arrSpec == arrspec_t::s4 || i_arrSpec == arrspec_t::d2 ) {
    l_ins |= 0x1 << 30;
  }
  if( i_arrSpec == arrspec_t::d2 ) {
    l_ins |= 0x1 << 29;
  }

  return l_ins;
}
