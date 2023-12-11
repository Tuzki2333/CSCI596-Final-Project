gcc -o knapsack_greedy knapsack_greedy.c
gcc -o knapsack_lagrangian knapsack_lagrangian.c
mpicc -o knapsack_mpi knapsack_mpi.c
gcc -o knapsack_openmp knapsack_openmp.c -fopenmp
mpicc -o knapsack_hybrid knapsack_hybrid.c -fopenmp