import matplotlib.pyplot as plt
import subprocess

benchmarks = ["peak_asimd_scalar_dp", "peak_asimd_scalar_sp", "peak_asmid_simd_dp", "peak_asmid_simd_sp"]


#data = [(1,1000.),(2,2000.),(3,3000.)]

for benchmark in benchmarks:
    print(benchmark)
    data = []
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
        data.append((i, flops)) 
    plt.figure()
    plt.title(benchmark)
    plt.scatter(*zip(*data))
    plt.ylabel("FLOPS")
    plt.xlabel("No. of cores")
    plt.savefig(benchmark + "_cores_" + ".png")
    
    data = []
    for i in range(1, 33):
        print(f"Threads: {i}")
        worker_string = "S0:1GB:" + str(i)
        benchmark_results = subprocess.run(["likwid-pin", "-c", "S0:0", "likwid-bench", "-t", benchmark, "-w", worker_string],
                                capture_output=True).stdout
        splitted_string = str(benchmark_results).split('\\n')
        flops = 0
        for string in splitted_string:
            if string.startswith("MFlops/s:"):
                flops = float(string.split("\\t")[-1])
                break
        print((i, flops))
        data.append((i, flops)) 
    plt.figure()
    plt.title(benchmark)
    plt.scatter(*zip(*data))
    plt.ylabel("FLOPS")
    plt.xlabel("No. of threads")
    plt.savefig(benchmark + "_threads_" + ".png")

