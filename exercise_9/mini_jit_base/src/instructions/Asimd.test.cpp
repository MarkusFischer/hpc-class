#include <catch2/catch.hpp>
#include "Asimd.h"

TEST_CASE( "Tests lsLdrImmUnsOff.", "[Asimd][lsLdrImmUnsOff]" ) {
  uint32_t l_ins = 0;
  mini_jit::instructions::Asimd::regsize_t l_rs = mini_jit::instructions::Asimd::regsize_t::b;
  l_ins = mini_jit::instructions::Asimd::lsLdrImmUnsOff( 0,
                                                         0,
                                                         l_rs,
                                                         0 );
  REQUIRE( l_ins == 0x3d400000 );

  l_rs = mini_jit::instructions::Asimd::regsize_t::q;
  l_ins = mini_jit::instructions::Asimd::lsLdrImmUnsOff( 2,
                                                         4,
                                                         l_rs,
                                                         32 );
  REQUIRE( l_ins == 0x3dc08082 );
}

TEST_CASE( "Tests lsStrImmUnsOff.", "[Asimd][lsStrImmUnsOff]" ) {
  uint32_t l_ins = 0;
  mini_jit::instructions::Asimd::regsize_t l_rs = mini_jit::instructions::Asimd::regsize_t::s;
  l_ins = mini_jit::instructions::Asimd::lsStrImmUnsOff( 1,
                                                         0,
                                                         l_rs,
                                                         64 );
  REQUIRE( l_ins == 0xbd010001 );
}

TEST_CASE( "Tests lsLd1MultipleNoOff.", "[Asimd][lsLd1MultipleNoOff]" ) {
  uint32_t l_ins = 0;
  mini_jit::instructions::Asimd::arrspec_t l_as = mini_jit::instructions::Asimd::arrspec_t::s4;

  l_ins = mini_jit::instructions::Asimd::lsLd1MultipleNoOff( 0,
                                                             0,
                                                             l_as,
                                                             4 );
  REQUIRE( l_ins == 0x4c402800 );

  l_ins = mini_jit::instructions::Asimd::lsLd1MultipleNoOff( 3,
                                                             7,
                                                             l_as,
                                                             2 );
  REQUIRE( l_ins == 0x4c40a8e3 );

  l_as = mini_jit::instructions::Asimd::arrspec_t::d2;
  l_ins = mini_jit::instructions::Asimd::lsLd1MultipleNoOff( 9,
                                                             2,
                                                             l_as,
                                                             1 );
  REQUIRE( l_ins == 0x4c407c49 );
}

TEST_CASE( "Tests lsSt1MultipleNoOff.", "[Asimd][lsLd1MultipleNoOff]" ) {
  uint32_t l_ins = 0;
  mini_jit::instructions::Asimd::arrspec_t l_as = mini_jit::instructions::Asimd::arrspec_t::s2;
  l_ins = mini_jit::instructions::Asimd::lsSt1MultipleNoOff( 2,
                                                             5,
                                                             l_as,
                                                             3 );
  REQUIRE( l_ins == 0x0c0068a2 );
}

TEST_CASE( "Tests dpFmovVectorImm.", "[Asimd][dpFmovVectorImm]" ) {
  uint32_t l_ins = 0;
  mini_jit::instructions::Asimd::arrspec_t l_as = mini_jit::instructions::Asimd::arrspec_t::s4;

  // fmov	v0.4s, #2.000000000000000000e+00
  uint8_t l_imm = 0;
  l_ins = mini_jit::instructions::Asimd::dpFmovVectorImm( 0,
                                                          l_imm,
                                                          l_as );
  REQUIRE( l_ins == 0x4f00f400 );

  // fmov	v5.2d, #-2.000000000000000000e+00
  l_imm = 0b10000000;
  l_as = mini_jit::instructions::Asimd::arrspec_t::d2;
  l_ins = mini_jit::instructions::Asimd::dpFmovVectorImm( 5,
                                                          l_imm,
                                                          l_as );
  REQUIRE( l_ins == 0x6f04f405 );

  // fmov	v17.2s, #1.000000000000000000e+00
  l_imm = 0b01110000;
  l_as = mini_jit::instructions::Asimd::arrspec_t::s2;
  l_ins = mini_jit::instructions::Asimd::dpFmovVectorImm( 17,
                                                          l_imm,
                                                          l_as );
  REQUIRE( l_ins == 0x0f03f611 );

}
