# Kadane's Algorithm: Deep Theoretical Concepts

## Historical Evolution
| Approach | Time | Space | Mechanism |
|---|---|---|---|
| Naive Brute Force | O(n³) | O(1) | All pairs (i,j) with internal sum loop |
| Optimized Brute Force | O(n²) | O(1) | Iterative expansion from each starting point |
| Prefix Sum Method | O(n²) | O(n) | O(1) subarray sum via precomputed prefix |
| Divide and Conquer | O(n log n) | O(log n) | Split recursively; max in left/right/cross |
| Auxiliary DP | O(n) | O(n) | Memoization table of local maxima |
| **Kadane's Algorithm** | **O(n)** | **O(1)** | Two state variables: local max + global max |

---

## Core DP Recurrence Relation
At every index `i`, define `f(i)` = maximum subarray sum ending exactly at `i`:

```
f(i) = max(A[i], f(i-1) + A[i])
```

Or equivalently in greedy logic:
```
f(i) = max(0, f(i-1)) + A[i]
```

**Why this works:** If the previous running sum `f(i-1)` is negative, adding it to `A[i]` only hurts us. We reset to start fresh at `A[i]`. If it's positive, we extend.

**Global max** = max value reached by `f(i)` across all indices.

---

## Dry Run Walkthrough
Array: `A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`

| Index | Element | Local Max | Global Max |
|---|---|---|---|
| 0 | -2 | -2 | -2 |
| 1 | 1 | max(1, -1) = 1 | 1 |
| 2 | -3 | max(-3, -2) = -2 | 1 |
| 3 | 4 | max(4, 2) = 4 | 4 |
| 4 | -1 | max(-1, 3) = 3 | 4 |
| 5 | 2 | max(2, 5) = 5 | 5 |
| 6 | 1 | max(1, 6) = 6 | 6 |
| 7 | -5 | max(-5, 1) = 1 | 6 |
| 8 | 4 | max(4, 5) = 5 | 6 |

**Answer: 6** via subarray `[4, -1, 2, 1]`

---

## Variant 1: Circular Subarray
**Dual Case Insight:**
- **Case 1 (No wrap):** Standard Kadane.
- **Case 2 (Wrap):** `Total Sum - Minimum Subarray Sum` (exclude the worst middle segment).

**Final answer:** `max(kadane_max, total_sum - kadane_min)`

**Edge case:** If ALL elements are negative, `total_sum == kadane_min`, making `total_sum - kadane_min == 0`. Return `kadane_max` only.

---

## Variant 2: Maximum Product Subarray
**Challenge:** A negative number flips the sign — the minimum product can become the maximum if multiplied by another negative.

**Strategy:** Track BOTH `curr_max` and `curr_min` simultaneously.

At each element `x`:
```
new_max = max(x, curr_max * x, curr_min * x)
new_min = min(x, curr_max * x, curr_min * x)
```

---

## Variant 3: Max Subarray with One Deletion
**Strategy:** Two Kadane passes:
- `left[i]` = max sum ending at index `i` (forward Kadane)
- `right[i]` = max sum starting at index `i` (backward Kadane)

**Bridge:** For each deleted index `k`, the bridged sum = `left[k-1] + right[k+1]`
**Answer:** `max(standard_max, max over all k of left[k-1] + right[k+1])`

---

## Variant 4: Maximum Absolute Sum Subarray
**Goal:** `max(|sum(subarray)|)` — largest deviation in either direction.

**Strategy:** Run two Kadane states simultaneously:
```
f = max(f, 0) + x  // max sum ending here
g = min(g, 0) + x  // min sum ending here
ans = max(ans, f, abs(g))
```

---

## Variant 5: 2D Maximum Sum Rectangle
**Reduction:** Fix left and right column boundaries → column-compress each row into a 1D array → apply Kadane's to find the best top/bottom boundary.

**Complexity:** O(C² × R) total — iterating all column pairs is O(C²), Kadane per pair is O(R).

---

## Greedy Reset Pattern
The most distinctive Kadane signature:
```cpp
if (curr_sum < 0) curr_sum = 0;
```
This "reset" reflects a universal principle: **if any prefix of a sequence is detrimental to the goal, abandon it and start fresh.** This bridges greedy choices with dynamic programming.
