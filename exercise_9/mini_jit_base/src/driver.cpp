#include <iostream>
#include "generators/Simple.h"
#include "generators/Loop.h"
#include "generators/MyExample.h"

int main() {
  std::cout << "###########################" << std::endl;
  std::cout << "### welcome to mini_jit ###" << std::endl;
  std::cout << "###########################" << std::endl;

  std::cout << "simple:" << std::endl;
  std::cout << "  generating simple kernel" << std::endl;
  mini_jit::generators::Simple l_simple;
  uint32_t (* l_funcSimple)() = l_simple.generate();

  std::cout << "  running" << std::endl;
  std::cout << "    result: " << l_funcSimple() << std::endl;


  std::cout << "loop:" << std::endl;
  std::cout << "  generating" << std::endl;
  mini_jit::generators::Loop l_loop;
  uint32_t (* l_funcLoop)() = l_loop.generate( 32 );

  std::cout << "  running" << std::endl;
  std::cout << "    result: " << l_funcLoop() << std::endl;

  std::cout << "MyExample (faculty):" << std::endl;
  std::cout << "  generating" << std::endl;
  mini_jit::generators::MyExample l_myExample;
  uint32_t (* l_funcMyExample)() = l_myExample.generate( 4 );

  std::cout << "  running" << std::endl;
  std::cout << "    result: " << l_funcMyExample() << std::endl;


  std::cout << "##############################" << std::endl;
  std::cout << "### mini_jit says bye, bye ###" << std::endl;
  std::cout << "##############################" << std::endl;

  return EXIT_SUCCESS;
}
