BUILD_DIR = ./build
OPTIONS = -pedantic -Wall -Wextra -Werror

mini_jit: src/driver.cpp src/instructions/Base.cpp src/instructions/Asimd.cpp src/backend/Kernel.cpp src/generators/Simple.cpp src/generators/Loop.cpp src/generators/MyExample.cpp
		g++ ${OPTIONS} -c src/instructions/Base.cpp -o ${BUILD_DIR}/instructions/Base.o
		g++ ${OPTIONS} -c src/instructions/Asimd.cpp -o ${BUILD_DIR}/instructions/Asimd.o
		g++ ${OPTIONS} -c src/backend/Kernel.cpp -o ${BUILD_DIR}/backend/Kernel.o
		g++ ${OPTIONS} -c src/generators/Simple.cpp -o ${BUILD_DIR}/generators/Simple.o
		g++ ${OPTIONS} -c src/generators/Loop.cpp -o ${BUILD_DIR}/generators/Loop.o
		g++ ${OPTIONS} -c src/generators/MyExample.cpp -o ${BUILD_DIR}/generators/MyExample.o

		g++ ${OPTIONS} src/driver.cpp ${BUILD_DIR}/instructions/Base.o ${BUILD_DIR}/instructions/Asimd.o \
		                              ${BUILD_DIR}/backend/Kernel.o \
		                              ${BUILD_DIR}/generators/Simple.o ${BUILD_DIR}/generators/Loop.o \
					      ${BUILD_DIR}/generators/MyExample.o \
		    -o ${BUILD_DIR}/mini_jit

test: src/test.cpp src/driver.cpp src/instructions/Base.cpp src/instructions/Asimd.cpp src/backend/Kernel.cpp src/generators/Simple.cpp src/generators/Loop.cpp src/instructions/Asimd.test.cpp
		g++ ${OPTIONS} -c src/instructions/Base.cpp -o ${BUILD_DIR}/instructions/Base.o
		g++ ${OPTIONS} -c src/instructions/Asimd.cpp -o ${BUILD_DIR}/instructions/Asimd.o
		g++ ${OPTIONS} -c src/instructions/Asimd.test.cpp -o ${BUILD_DIR}/instructions/Asimd.test.o
		g++ ${OPTIONS} -c src/backend/Kernel.cpp -o ${BUILD_DIR}/backend/Kernel.o
		g++ ${OPTIONS} -c src/generators/Simple.cpp -o ${BUILD_DIR}/generators/Simple.o
		g++ ${OPTIONS} -c src/generators/Loop.cpp -o ${BUILD_DIR}/generators/Loop.o

		g++ ${OPTIONS} src/test.cpp ${BUILD_DIR}/instructions/Base.o \
		                        ${BUILD_DIR}/instructions/Asimd.o ${BUILD_DIR}/instructions/Asimd.test.o \
		                        ${BUILD_DIR}/backend/Kernel.o \
		                        ${BUILD_DIR}/generators/Simple.o ${BUILD_DIR}/generators/Loop.o \
		    -o ${BUILD_DIR}/test
$(shell mkdir -p build/backend)
$(shell mkdir -p build/instructions)
$(shell mkdir -p build/generators)
