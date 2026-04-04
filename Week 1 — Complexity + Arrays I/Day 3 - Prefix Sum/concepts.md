# 📚 Theoretical Foundations: Prefix Sum Methodology

The prefix sum technique represents a fundamental paradigm shift in how computational systems approach range-based data aggregation. By precomputing cumulative totals, the algorithm transitions from linear-time $O(n)$ query processing to constant-time $O(1)$ retrieval.

---

## 1. The Mathematical Paradigm

Given an input array $A$ of length $n$, the prefix sum array $P$ is formally constructed such that:
$$ P[i] = A[0] + A[1] + \dots + A[i] $$

In implementation, this iterative relation is used:
$$ P[i] = P[i-1] + A[i] $$

### The Range Query Formula
For any range $[L, R]$, the sum is computed through **inclusion-exclusion**:
$$ \text{Sum}(L, R) = P[R] - P[L-1] $$
If $L=0$, conditionally handle it to avoid $P[-1]$, or utilize an $N+1$ padded array where $P[i+1]$ corresponds to the prefix up to $A[i]$.

| Operation | Naive Complexity | Prefix Sum Complexity | Logic |
| :--- | :--- | :--- | :--- |
| Construction | $O(1)$ | $O(n)$ | $\sum A[j]$ |
| Range Query | $O(n)$ | $O(1)$ | $P[R] - P[L-1]$ |
| Point Update | $O(1)$ | $O(n)$ | Cascading propagation |

> **Strategic Trade-off:** Prefix sums are for **Static-Read-Heavy** profiles. If data mutates frequently, $O(n)$ point updates destroy efficiency. In such cases, Segment Trees or Fenwick Trees ($O(\log n)$ updates/queries) are required.

## 2. Generalized Scan Operations

Addition is the most common associative operator $\oplus$, but the technique generalizes to any operator possessing an **inverse**.
*   **Addition:** Inverse is subtraction. Range Sum = $P[R] - P[L-1]$
*   **XOR:** Inverse is XOR itself ($x \oplus x = 0$). Range XOR = $P[R] \oplus P[L-1]$

Operators without inverses (like $\max$ or $\min$) can only support prefix queries ($0$ to $i$) but not arbitrary range queries $[L, R]$.

## 3. The Prefix Sum + Hash Map Architecture

When analyzing subarrays matching a dynamic condition, a naive $O(n^2)$ search is optimized to $O(n)$ via Hash Maps.

The logic: If $P[i] - P[j] = K$, then the subarray from $j+1$ to $i$ sums to $K$.
Rearranged: $P[j] = P[i] - K$.
We iterate $i$, checking the Hash Map to see if the required $P[j]$ has been encountered before.

| Condition | Hash Map Key | Hash Map Value | Goal |
| :--- | :--- | :--- | :--- |
| Exact Sum == K | `prefix` | Frequency | Total Count |
| Maximum Length for Sum K | `prefix` | Earliest Index `i` | Max $(i - j)$ |
| Divisible by K | `prefix % K` | Earliest Index `i` | Existence / Length |
| Equal 0s and 1s | `count(1) - count(0)` | Earliest Index `i` | Max Balance Length |

## 4. Dimensional Scaling (2D Prefix Sums)

In a 2D grid, parsing submatrices traditionally takes $O(row^2 \cdot col^2)$. 

1. **2D Prefix Inclusion-Exclusion:**
   To build: $P[r][c] = A[r][c] + P[r-1][c] + P[r][c-1] - P[r-1][c-1]$
   To query $[r_1, c_1]$ to $[r_2, c_2]$: 
   $S = P[r_2][c_2] - P[r_1-1][c_2] - P[r_2][c_1-1] + P[r_1-1][c_1-1]$
2. **2D to 1D Compression:**
   Iterate every pair of row boundaries $[top, bottom]$. Compute the sum of each column natively. This reduces a 2D matrix sum problem into a 1D "Subarray Sum Equals K" problem, solved in $O(row^2 \cdot col)$.

## 5. The Difference Array (Range Updates)

The mathematical dual of the prefix sum is the **Difference Array**.
$D[i] = A[i] - A[i-1]$

Adding $V$ to range $[L, R]$ requires only $O(1)$ operations:
*   $D[L] += V$
*   $D[R+1] -= V$

To finalize the array, you take the **Prefix Sum of the Difference Array**. Highly effective for offline point-update problems (e.g., flight bookings, carpooling capacities).
