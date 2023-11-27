# CSCI596-Final-Project

## Problem Description

The knapsack problem is a well-known problem described as follows:

**Input**: a set of $n$ items with weights $w_1, w_2, \cdots, w_n$ and values $v_1, v_2, \cdots, v_n$; the space limit $W$

**Output**: a subset of items. Denote $x_i = 1$ if the $i$-th item is chosen; otherwise, $x_i = 0$.

**Constraint**: the total weight of chosen items is less than or equal to the space limit, that is, $\sum_{i} x_i w_i \leq W$.

**Objective**: maximize the total value of chosen items, that is, maximize $\sum_{i} x_i v_i$.

In this project, I plan to solve the large-scale knapsack problem. That is, $n$ is very large.

## Challenges

The knapsack problem 

$$ \max_{x_1,x_2\cdots,x_n} \sum^{n}_{i=1} x_i v_i$$

$$ s.t. \sum^{n}_{i=1} x_i w_i \leq W $$

$$ x_i = 0 or 1, i = 1,2,\cdots,n $$

is known as NP-hard. Some existing algorithms include:

* Dynamic programming - Exact algorithm, pseudo-polynomial time $O(nW)$

* Branch-and-bound - Exact algorithm, exponential time $O(2^n)$

* Greedy algorithm - Approximate algorithm, require sorting, $O(n \log n)$

When $n$ is very large, the above algorithms result in long running times and some new algorithms need to be developed. A desired algorithm should satisfy:

- The time complexity is $O(n)$
- The algorithm can be run in parallel

## Methods

To develop a desired algorithm, we formulate the Lagrangian dual problem as follows:

$$ \min_{\lambda \geq 0} \sup_{x_1,x_2\cdots,x_n} \sum_{i=1}^n x_i (v_i - \lambda w_i)$$

$$ s.t. x_i = 0 or 1, i = 1,2,\cdots,n $$

Interestingly, this Lagrangian dual problem has a separable structure, which allows us to develop our desired algorithm. 

So the high-level idea of our algorithm is:

- STEP 1: Initialize a value of $\lambda$
- STEP 2: Given $\lambda$, solve the inner maximization problem which can be done **in parallel** and in $O(n)$
- STEP 3: Update the value of $\lambda$ according to the dual ascent method
- Repeat STEP 2 and STEP 3 until converge

## Expected Results
