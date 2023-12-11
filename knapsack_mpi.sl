#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=4
#SBATCH --time=00:09:59
#SBATCH --output=knapsack_mpi.out
#SBATCH -A anakano_429

mpirun -n 1 ./knapsack_mpi 10000000 1
mpirun -n 2 ./knapsack_mpi 10000000 1
mpirun -n 4 ./knapsack_mpi 10000000 1
mpirun -n 8 ./knapsack_mpi 10000000 1