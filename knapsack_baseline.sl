#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --time=05:59:59
#SBATCH --output=knapsack_baseline.out
#SBATCH -A anakano_429

./knapsack_lagrangian 1000000 1
./knapsack_greedy_nosorting 1000000 1
./knapsack_greedy_sorting 1000000 1
./knapsack_lagrangian 1000000 2
./knapsack_greedy_nosorting 1000000 2
./knapsack_greedy_sorting 1000000 2
./knapsack_lagrangian 1000000 3
./knapsack_greedy_nosorting 1000000 3
./knapsack_greedy_sorting 1000000 3
./knapsack_lagrangian 10000000 1
./knapsack_greedy_nosorting 10000000 1
./knapsack_greedy_sorting 10000000 1
./knapsack_lagrangian 10000000 2
./knapsack_greedy_nosorting 10000000 2
./knapsack_greedy_sorting 10000000 2
./knapsack_lagrangian 10000000 3
./knapsack_greedy_nosorting 10000000 3
./knapsack_greedy_sorting 10000000 3
./knapsack_lagrangian 100000000 1
./knapsack_greedy_nosorting 100000000 1
./knapsack_greedy_sorting 100000000 1
./knapsack_lagrangian 100000000 2
./knapsack_greedy_nosorting 100000000 2
./knapsack_greedy_sorting 100000000 2
./knapsack_lagrangian 100000000 3
./knapsack_greedy_nosorting 100000000 3
./knapsack_greedy_sorting 100000000 3