import matplotlib.pyplot as plt
import subprocess

benchmarks = ["peak_asimd_scalar_dp", "peak_asimd_scalar_sp", "peak_asmid_simd_dp", "peak_asmid_simd_sp"]


for benchmark in benchmarks:
    print(benchmark)
    data_cores = []
    data_threads = []
    for i in range(1, 33):
        print(f"Cores: {i}")
        worker_string = "S0:1GB:" + str(i)
        benchmark_results = subprocess.run(["likwid-bench", "-t", benchmark, "-w", worker_string],
                                capture_output=True).stdout
        splitted_string = str(benchmark_results).split('\\n')
        flops = 0
        for string in splitted_string:
            if string.startswith("MFlops/s:"):
                flops = float(string.split("\\t")[-1])
                break
        print((i, flops))
        data_cores.append((i, flops)) 
        
        benchmark_results = subprocess.run(["likwid-pin", "-c", "S0:0", "likwid-bench", "-t", benchmark, "-w", worker_string],
                                capture_output=True).stdout
        splitted_string = str(benchmark_results).split('\\n')
        flops = 0
        for string in splitted_string:
            if string.startswith("MFlops/s:"):
                flops = float(string.split("\\t")[-1])
                break
        print((i, flops))
        data_threads.append((i, flops))
        
    plt.figure()
    plt.title(benchmark)
    plt.scatter(*zip(*data_cores), label="Cores")
    plt.scatter(*zip(*data_threads, label="Threads"))
    plt.ylabel("MFLOP/s")
    plt.xlabel("No. of cores/Threads")
    plt.legend()
    plt.savefig(benchmark + ".png")
