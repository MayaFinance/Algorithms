# Day 6: Array Edge Cases & Optimizations — Problem Set

All problems categorized by difficulty. Attempt before revealing solutions in `solutions.cpp`.

---

## LEVEL 1: WARM-UP (Basic Edge Cases)

---

## Problem 1: Running Sum Queries ⭐ Easy
**Platform:** LeetCode 303 variant / Custom
**Description:** Given array `A` and `q` queries `(l, r)`, answer each with `sum(A[l..r])`.
**Constraints:** `1 ≤ n ≤ 10^5`, `-10^4 ≤ A[i] ≤ 10^4`, `1 ≤ q ≤ 10^5`
**Example:**
```
A = [3, -1, 4, 1, -5, 9, 2]
Query (1,4) → -1
Query (0,6) → 13
Query (5,5) → 9
```
**Edge case target:** Negatives, single-element query (`l == r`), large `q` (must be O(1) per query).
**Optimization:** Prefix sum array — O(n) build, O(1) query.

---

## Problem 2: Find the Missing Number ⭐ Easy
**Platform:** LeetCode 268
**Description:** Array of `n` distinct integers in `[0, n]`. One number is missing. Find it.
**Constraints:** `1 ≤ n ≤ 10^4`, all values distinct, exactly one missing.
**Example:**
```
A = [3, 0, 1]           → 2
A = [9,6,4,2,3,5,7,0,1] → 8
A = [0]                  → 1
```
**Edge case target:** Missing is `0` (smallest), missing is `n` (largest), single element.
**Optimization:** XOR trick or Gauss sum: `expected_sum - actual_sum`. O(n) time, O(1) space.

---

## Problem 3: Move Zeros to End ⭐ Easy
**Platform:** LeetCode 283
**Description:** Move all zeros to end of array, maintaining relative order of non-zero elements. In-place.
**Constraints:** `1 ≤ n ≤ 10^4`, in-place, O(1) space.
**Example:**
```
A = [0, 1, 0, 3, 12]  → [1, 3, 12, 0, 0]
A = [0]                → [0]
A = [1]                → [1]
```
**Edge case target:** All zeros, no zeros, single zero at start/end, single element.
**Optimization:** Write-pointer single-pass. O(n) time, O(1) space.

---

## Problem 4: Check Sorted and Rotated ⭐ Easy
**Platform:** LeetCode 1752
**Description:** Return `true` if array can be obtained by rotating some non-decreasing array.
**Constraints:** `1 ≤ n ≤ 100`, `1 ≤ A[i] ≤ 100`.
**Example:**
```
A = [3,4,5,1,2]  → true
A = [2,1,3,4]    → false
A = [1,1,1]      → true
```
**Edge case target:** All equal, n=1 (always true), already sorted.
**Optimization:** Count "drop points" (A[i] > A[(i+1)%n]). ≤ 1 drops → true. O(n).

---

## LEVEL 2: CORE (Pattern-Based)

---

## Problem 5: Longest Subarray with Sum ≤ K ⭐⭐ Medium
**Platform:** Custom / LeetCode 209 variant
**Description:** Given non-negative integer array and `k`, find the longest contiguous subarray with sum ≤ k.
**Constraints:** `1 ≤ n ≤ 10^5`, `0 ≤ A[i] ≤ 10^4`, `0 ≤ k ≤ 10^9`.
**Example:**
```
A = [2,3,1,2,4,3], k = 7  → 3  (e.g., [2,3,1] or [3,1,2])
A = [0,0,0], k = 0         → 3
A = [5,6,7], k = 4         → 0
```
**Edge case target:** k=0 (only zeros), single large element, all small elements.
**Optimization:** Sliding window (works because values are non-negative — adding can only grow sum). O(n).

---

## Problem 6: Count Subarrays with Sum = K ⭐⭐ Medium
**Platform:** LeetCode 560
**Description:** Given integer array (can have negatives) and `k`, count subarrays with sum = k.
**Constraints:** `1 ≤ n ≤ 2×10^4`, `-10^3 ≤ A[i] ≤ 10^3`, `-10^7 ≤ k ≤ 10^7`.
**Example:**
```
A = [1,1,1], k = 2   → 2
A = [1,-1,1], k = 1  → 3
A = [1,2,3], k = 6   → 1
```
**Edge case target:** k=0 (subarrays that sum to zero), negatives, large k with no match.
**Optimization:** Prefix sum + HashMap. Sliding window FAILS with negatives. O(n).

---

## Problem 7: Maximum Sum of Non-Adjacent Elements ⭐⭐ Medium
**Platform:** LeetCode 198 (House Robber)
**Description:** Given non-negative integer array, maximize sum such that no two selected elements are adjacent.
**Constraints:** `1 ≤ n ≤ 100`, `0 ≤ A[i] ≤ 400`.
**Example:**
```
A = [2,7,9,3,1]  → 12  (2+9+1)
A = [2,1,1,2]    → 4   (2+2)
A = [0]           → 0
```
**Edge case target:** n=1 (return A[0]), n=2 (return max(A[0],A[1])), all zeros.
**Optimization:** O(n) DP with O(1) space: `prev2 = 0, prev1 = 0`.

---

## Problem 8: Minimum Size Subarray Sum ≥ S ⭐⭐ Medium
**Platform:** LeetCode 209
**Description:** Array of positive integers. Find minimum length subarray with sum ≥ s. Return 0 if impossible.
**Constraints:** `1 ≤ n ≤ 10^5`, `1 ≤ A[i] ≤ 10^4`, `1 ≤ s ≤ 10^8`.
**Example:**
```
A = [2,3,1,2,4,3], s = 7  → 2  ([4,3])
A = [1,4,4], s = 4         → 1  ([4])
A = [1,1,1,1,1], s = 11   → 0
```
**Edge case target:** Sum of all elements < s, single element ≥ s, all elements equal to s-1.
**Optimization:** Sliding window (positive values only). O(n).

---

## Problem 9: Product of Array Except Self ⭐⭐ Medium
**Platform:** LeetCode 238
**Description:** Return array B where B[i] = product of all A except A[i]. No division, O(n) time, O(1) space.
**Constraints:** `2 ≤ n ≤ 10^5`, `-30 ≤ A[i] ≤ 30`, product fits 32-bit int.
**Example:**
```
A = [1,2,3,4]      → [24,12,8,6]
A = [-1,1,0,-3,3]  → [0,0,9,0,0]
```
**Edge case target:** One zero (only that position gets non-zero product, others get 0), two zeros (all zeros), negatives.
**Optimization:** Forward pass for prefix products, backward pass for suffix — O(n) time, O(1) extra space.

---

## Problem 10: Trapping Rain Water ⭐⭐ Medium-Hard
**Platform:** LeetCode 42
**Description:** Given elevation map, compute how much water is trapped after rain.
**Constraints:** `1 ≤ n ≤ 2×10^4`, `0 ≤ height[i] ≤ 10^5`.
**Example:**
```
height = [0,1,0,2,1,0,1,3,2,1,2,1]  → 6
height = [4,2,0,3,2,5]               → 9
height = [3,0,3]                      → 3
```
**Edge case target:** n=1 or n=2 (no water), strictly increasing (no left walls), all equal (no water).
**Optimization Level 1:** O(n) time, O(n) space — left-max + right-max arrays.
**Optimization Level 2:** O(n) time, O(1) space — two pointers.

---

## LEVEL 3: ADVANCED (Tricky + Optimization Heavy)

---

## Problem 11: Maximum Sum After K Negations ⭐⭐ Medium-Hard
**Platform:** LeetCode 1005
**Description:** Given array and integer `k`, flip sign of exactly `k` elements (can repeat). Maximize sum.
**Constraints:** `1 ≤ n ≤ 10^4`, `-100 ≤ A[i] ≤ 100`, `1 ≤ k ≤ 10^4`.
**Example:**
```
A = [4,2,3], k = 1        → 5   (flip 2 → [4,-2,3]; that's 5. Wait flip to negate: [4,-2,3]=5)
A = [3,-1,0,2], k = 3     → 6   (flip -1, flip 0, flip 0)
A = [-2,-3,-1], k = 2     → -1  (flip -3 and -2: [2,3,-1]=4)
```
**Edge case target:** k odd with all positives (must lose smallest), zeros present (free flips), all negatives.
**Optimization:** Sort → flip negatives from most-negative → if k remains odd, subtract 2× smallest absolute value. O(n log n).

---

## Problem 12: Maximum Width Ramp ⭐⭐⭐ Hard
**Platform:** LeetCode 962
**Description:** A ramp is pair (i,j) with i<j and A[i]≤A[j]. Find maximum width j-i. Return 0 if none.
**Constraints:** `2 ≤ n ≤ 5×10^4`, `0 ≤ A[i] ≤ 5×10^4`.
**Example:**
```
A = [6,0,8,2,1,5]          → 4  (i=1,j=5: 0≤5)
A = [9,8,1,0,1,9,4,0,4,1] → 7
A = [0,1]                   → 1
```
**Edge case target:** Strictly decreasing (multiple answers at distance 0), all same (answer=n-1), n=2.
**Optimization:** Monotone decreasing stack for left candidates. Sweep from right. O(n).

---

## Problem 13: Shortest Subarray with Sum ≥ K (Negatives Allowed) ⭐⭐⭐ Hard
**Platform:** LeetCode 862
**Description:** Array may have negatives. Find minimum length subarray with sum ≥ k. Return -1 if none.
**Constraints:** `1 ≤ n ≤ 5×10^4`, `-10^5 ≤ A[i] ≤ 10^5`, `-10^9 ≤ k ≤ 10^9`.
**Example:**
```
A = [1], k = 1      → 1
A = [1,2], k = 4    → -1
A = [2,-1,2], k = 3 → 3
```
**Edge case target:** No valid subarray, k is negative (any non-empty subarray with positive elements works), negatives in array.
**Optimization:** Prefix sum + monotone deque (deque of increasing prefix values). O(n). (Sliding window fails due to negatives.)

---

## Problem 14: Maximum Score from Subarray (Min × Length) ⭐⭐⭐ Hard
**Platform:** Codeforces-style (CF 1900 equivalent)
**Description:** For every subarray [l,r], score = min(A[l..r]) × (r-l+1). Find maximum score.
**Constraints:** `1 ≤ n ≤ 10^5`, `1 ≤ A[i] ≤ 10^9`.
**Example:**
```
A = [1,3,2,4]   → 6  (subarray [3,2,4], min=2, length=3, score=6)
A = [6,6,6]     → 18 (whole array, min=6, length=3)
A = [4,2,1,3]   → 4  (single element [4])
```
**Edge case target:** All equal (whole array wins), strictly decreasing (each single element is its own best).
**Optimization:** Monotone stack → find PreviousSmaller and NextSmaller for each index. Each element is the min for exactly one range. O(n).

---

## Problem 15: Subarray Sum Divisible by K ⭐⭐ Medium-Hard
**Platform:** LeetCode 974
**Description:** Given integer array and `k`, return the count of contiguous subarrays whose sum is divisible by `k`.
**Constraints:** `1 ≤ n ≤ 3×10^4`, `-10^4 ≤ A[i] ≤ 10^4`, `2 ≤ k ≤ 10^4`.
**Example:**
```
A = [4,5,0,-2,-3,1], k = 5  → 7
A = [5], k = 9              → 0
A = [0,0,0,0], k = 1       → 10
```
**Edge case target:** k=1 (every subarray counts → n*(n+1)/2), zeros, negatives in remainder computation.
**Optimization:** Prefix sum modulo k + HashMap. Key: `((prefix % k) + k) % k` to normalize negatives. O(n).
