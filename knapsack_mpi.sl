#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=4
#SBATCH --time=00:29:59
#SBATCH --output=knapsack_mpi.out
#SBATCH -A anakano_429

mpirun -n 1 ./knapsack_mpi 1000000 1
mpirun -n 2 ./knapsack_mpi 1000000 1
mpirun -n 4 ./knapsack_mpi 1000000 1
mpirun -n 8 ./knapsack_mpi 1000000 1
mpirun -n 1 ./knapsack_mpi 1000000 2
mpirun -n 2 ./knapsack_mpi 1000000 2
mpirun -n 4 ./knapsack_mpi 1000000 2
mpirun -n 8 ./knapsack_mpi 1000000 2
mpirun -n 1 ./knapsack_mpi 1000000 3
mpirun -n 2 ./knapsack_mpi 1000000 3
mpirun -n 4 ./knapsack_mpi 1000000 3
mpirun -n 8 ./knapsack_mpi 1000000 3
mpirun -n 1 ./knapsack_mpi 10000000 1
mpirun -n 2 ./knapsack_mpi 10000000 1
mpirun -n 4 ./knapsack_mpi 10000000 1
mpirun -n 8 ./knapsack_mpi 10000000 1
mpirun -n 1 ./knapsack_mpi 10000000 2
mpirun -n 2 ./knapsack_mpi 10000000 2
mpirun -n 4 ./knapsack_mpi 10000000 2
mpirun -n 8 ./knapsack_mpi 10000000 2
mpirun -n 1 ./knapsack_mpi 10000000 3
mpirun -n 2 ./knapsack_mpi 10000000 3
mpirun -n 4 ./knapsack_mpi 10000000 3
mpirun -n 8 ./knapsack_mpi 10000000 3
mpirun -n 1 ./knapsack_mpi 100000000 1
mpirun -n 2 ./knapsack_mpi 100000000 1
mpirun -n 4 ./knapsack_mpi 100000000 1
mpirun -n 8 ./knapsack_mpi 100000000 1
mpirun -n 1 ./knapsack_mpi 100000000 2
mpirun -n 2 ./knapsack_mpi 100000000 2
mpirun -n 4 ./knapsack_mpi 100000000 2
mpirun -n 8 ./knapsack_mpi 100000000 2
mpirun -n 1 ./knapsack_mpi 100000000 3
mpirun -n 2 ./knapsack_mpi 100000000 3
mpirun -n 4 ./knapsack_mpi 100000000 3
mpirun -n 8 ./knapsack_mpi 100000000 3