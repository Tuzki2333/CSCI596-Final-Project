#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=8
#SBATCH --time=00:29:59
#SBATCH --output=knapsack_openmp_2.out
#SBATCH -A anakano_429


export OMP_NUM_THREADS=1
./knapsack_openmp 1000000 1
export OMP_NUM_THREADS=2
./knapsack_openmp 1000000 1
export OMP_NUM_THREADS=4
./knapsack_openmp 1000000 1
export OMP_NUM_THREADS=8
./knapsack_openmp 1000000 1
export OMP_NUM_THREADS=1
./knapsack_openmp 1000000 2
export OMP_NUM_THREADS=2
./knapsack_openmp 1000000 2
export OMP_NUM_THREADS=4
./knapsack_openmp 1000000 2
export OMP_NUM_THREADS=8
./knapsack_openmp 1000000 2
export OMP_NUM_THREADS=1
./knapsack_openmp 1000000 3
export OMP_NUM_THREADS=2
./knapsack_openmp 1000000 3
export OMP_NUM_THREADS=4
./knapsack_openmp 1000000 3
export OMP_NUM_THREADS=8
./knapsack_openmp 1000000 3
export OMP_NUM_THREADS=1
./knapsack_openmp 10000000 1
export OMP_NUM_THREADS=2
./knapsack_openmp 10000000 1
export OMP_NUM_THREADS=4
./knapsack_openmp 10000000 1
export OMP_NUM_THREADS=8
./knapsack_openmp 10000000 1
export OMP_NUM_THREADS=1
./knapsack_openmp 10000000 2
export OMP_NUM_THREADS=2
./knapsack_openmp 10000000 2
export OMP_NUM_THREADS=4
./knapsack_openmp 10000000 2
export OMP_NUM_THREADS=8
./knapsack_openmp 10000000 2
export OMP_NUM_THREADS=1
./knapsack_openmp 10000000 3
export OMP_NUM_THREADS=2
./knapsack_openmp 10000000 3
export OMP_NUM_THREADS=4
./knapsack_openmp 10000000 3
export OMP_NUM_THREADS=8
./knapsack_openmp 10000000 3
export OMP_NUM_THREADS=1
./knapsack_openmp 100000000 1
export OMP_NUM_THREADS=2
./knapsack_openmp 100000000 1
export OMP_NUM_THREADS=4
./knapsack_openmp 100000000 1
export OMP_NUM_THREADS=8
./knapsack_openmp 100000000 1
export OMP_NUM_THREADS=1
./knapsack_openmp 100000000 2
export OMP_NUM_THREADS=2
./knapsack_openmp 100000000 2
export OMP_NUM_THREADS=4
./knapsack_openmp 100000000 2
export OMP_NUM_THREADS=8
./knapsack_openmp 100000000 2
export OMP_NUM_THREADS=1
./knapsack_openmp 100000000 3
export OMP_NUM_THREADS=2
./knapsack_openmp 100000000 3
export OMP_NUM_THREADS=4
./knapsack_openmp 100000000 3
export OMP_NUM_THREADS=8
./knapsack_openmp 100000000 3