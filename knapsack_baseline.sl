#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=4
#SBATCH --time=00:09:59
#SBATCH --output=knapsack_baseline.out
#SBATCH -A anakano_429

./knapsack_lagrangian 10000000 1
./knapsack_greedy 10000000 1