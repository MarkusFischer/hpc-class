## Explain the call

The call of  libxsmm_dmmdispatch dispatches the just in time code generation. It returns a function pointer to an optimized, generated kernel. With the call of the kernel the optimized code gets executed.  

## Compile 

g++ -O3 -DNDEBUG -I/home/markus/lib/libxsmm/include src/driver_4_4.cpp src/gemm_ref.cpp src/util.cpp -pthread -lxsmm -L${HOME}/lib/libxsmm/lib /lib64/libopenblas.so.0 -ldl -o driver_4_4


## Performance

Compared with our reference kernel implementation the libxsmm implementation performs significantly better. We get at least ten times the number of FLOPS with a peak performance of ~32 GFLOPS.  
