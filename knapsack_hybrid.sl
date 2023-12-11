#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=4
#SBATCH --cpus-per-task=2
#SBATCH --time=00:09:59
#SBATCH --output=knapsack_hybrid.out
#SBATCH -A anakano_429

mpirun -bind-to none -n 1 ./knapsack_mpi 10000000 1
mpirun -bind-to none -n 2 ./knapsack_mpi 10000000 1
mpirun -bind-to none -n 4 ./knapsack_mpi 10000000 1
mpirun -bind-to none -n 8 ./knapsack_mpi 10000000 1
mpirun -bind-to none -n 1 ./knapsack_hybrid 10000000 1
mpirun -bind-to none -n 2 ./knapsack_hybrid 10000000 1
mpirun -bind-to none -n 4 ./knapsack_hybrid 10000000 1
mpirun -bind-to none -n 8 ./knapsack_hybrid 10000000 1