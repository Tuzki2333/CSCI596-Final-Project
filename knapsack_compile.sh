gcc -o knapsack_greedy_nosorting knapsack_greedy_nosorting.c
gcc -o knapsack_greedy_sorting knapsack_greedy_sorting.c
gcc -o knapsack_lagrangian knapsack_lagrangian.c
mpicc -o knapsack_mpi knapsack_mpi.c
gcc -o knapsack_openmp knapsack_openmp.c -fopenmp
mpicc -o knapsack_hybrid knapsack_hybrid.c -fopenmp