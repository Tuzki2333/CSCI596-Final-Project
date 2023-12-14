#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=4
#SBATCH --time=00:29:59
#SBATCH --output=MCKP_mpi.out
#SBATCH -A anakano_429

mpirun -n 1 ./MCKP_mpi 1000000 2 1
mpirun -n 2 ./MCKP_mpi 1000000 2 1
mpirun -n 4 ./MCKP_mpi 1000000 2 1
mpirun -n 8 ./MCKP_mpi 1000000 2 1
mpirun -n 1 ./MCKP_mpi 1000000 2 2
mpirun -n 2 ./MCKP_mpi 1000000 2 2
mpirun -n 4 ./MCKP_mpi 1000000 2 2
mpirun -n 8 ./MCKP_mpi 1000000 2 2
mpirun -n 1 ./MCKP_mpi 1000000 2 3
mpirun -n 2 ./MCKP_mpi 1000000 2 3
mpirun -n 4 ./MCKP_mpi 1000000 2 3
mpirun -n 8 ./MCKP_mpi 1000000 2 3
mpirun -n 1 ./MCKP_mpi 10000000 2 1
mpirun -n 2 ./MCKP_mpi 10000000 2 1
mpirun -n 4 ./MCKP_mpi 10000000 2 1
mpirun -n 8 ./MCKP_mpi 10000000 2 1
mpirun -n 1 ./MCKP_mpi 10000000 2 2
mpirun -n 2 ./MCKP_mpi 10000000 2 2
mpirun -n 4 ./MCKP_mpi 10000000 2 2
mpirun -n 8 ./MCKP_mpi 10000000 2 2
mpirun -n 1 ./MCKP_mpi 10000000 2 3
mpirun -n 2 ./MCKP_mpi 10000000 2 3
mpirun -n 4 ./MCKP_mpi 10000000 2 3
mpirun -n 8 ./MCKP_mpi 10000000 2 3