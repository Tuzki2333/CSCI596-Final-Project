# CSCI596-Final-Project

## Problem Description

The knapsack problem is a well-known problem described as follows:

**Input**: a set of $n$ items with weights $w_1, w_2, \cdots, w_n$ and values $v_1, v_2, \cdots, v_n$; the space limit $W$

**Output**: a subset of items. Denote $x_i = 1$ if the $i$-th item is chosen; otherwise, $x_i = 0$.

**Constraint**: the total weight of chosen items is less than or equal to the space limit, that is, $\sum_{i=1}^n x_i w_i \leq W$.

**Objective**: maximize the total value of chosen items, that is, maximize $\sum_{i=1}^n x_i v_i$.

In this project, I plan to solve the very-large-scale knapsack problem. That is, $n$ is very large.

## Challenges

The knapsack problem 

$$ \max_{x_1,x_2\cdots,x_n} \sum_{i=1}^n x_i v_i$$

$$ s.t. \sum_{i=1}^n x_i w_i \leq W $$

$$ x_i \in \{ 0,1 \}, i = 1,2,\cdots,n $$

is known as NP-hard. Some existing algorithms include:

* Dynamic programming - Exact algorithm, pesudo-polynomial time $O(nW)$

* Branch-and-bound - Exact algorithm, exponential time $O(2^n)$

* Greedy algorithm - Approximate algorithm, require sorting, $O(n \log n)$

When $n$ is very large, the aboved algorithms result in long running times and some new algorithms need to be developed. A desried algorithm should satisfy:

- The time complexity is $O(n)$
- The algorithm can be run in parallel

## Methods


## Expected Results
