BUILD_DIR = ./build

gemm_asm_asmid: driver.cpp ../exercise_4/src/gemm_ref.cpp ../exercise_4/src/util.cpp gemm_asm_asimd_16_4_4.s gemm_asm_asimd_16_4_12.s
		g++ -g -pedantic -Wall -Wextra -Werror -O2 -c ../exercise_4/src/gemm_ref.cpp -o ${BUILD_DIR}/gemm_ref.o
		g++ -g -pedantic -Wall -Wextra -Werror -O2 -c ../exercise_4/src/util.cpp -o ${BUILD_DIR}/util.o
		gcc -g -pedantic -Wall -Wextra -Werror -c gemm_asm_asimd_16_4_4.s -o ${BUILD_DIR}/gemm_asm_asimd_16_4_4.o
		gcc -g -pedantic -Wall -Wextra -Werror -c gemm_asm_asimd_16_4_12.s -o ${BUILD_DIR}/gemm_asm_asimd_16_4_12.o
		g++ -g -pedantic -Wall -Wextra -Werror -O2 driver.cpp  ${BUILD_DIR}/gemm_ref.o  ${BUILD_DIR}/util.o  ${BUILD_DIR}/gemm_asm_asimd_16_4_4.o ${BUILD_DIR}/gemm_asm_asimd_16_4_12.o -o ${BUILD_DIR}/driver 
$(shell mkdir -p build)
    
