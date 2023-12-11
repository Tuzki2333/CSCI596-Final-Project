#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=4
#SBATCH --time=00:09:59
#SBATCH --output=knapsack_openmp.out
#SBATCH -A anakano_429

export OMP_NUM_THREADS=1
./knapsack_openmp 10000000 1
export OMP_NUM_THREADS=2
./knapsack_openmp 10000000 1
export OMP_NUM_THREADS=4
./knapsack_openmp 10000000 1