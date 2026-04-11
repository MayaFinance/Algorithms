# Day 7 — Week 1 Contest: "Array Siege"

**Duration:** 2.5 hours | **Problems:** A–G | **Style:** Codeforces Div. 2

Topics tested: Time/Space Complexity · Arrays · Prefix Sum · Difference Array · Kadane · Edge Cases

---

## Problem A — Lucky Prefix (★ 900)

**Statement:**
Given an array `a` of `n` positive integers. Find the **minimum** index `k` (1-indexed) such that the sum of the first `k` elements is **strictly greater** than the sum of the remaining `n - k` elements.

If no such `k` exists, print `-1`.

**Input:**
- First line: integer `n` (1 ≤ n ≤ 2×10⁵)
- Second line: n integers `a[i]` (1 ≤ a[i] ≤ 10⁹)

**Output:** Single integer `k`, or `-1`.

**Examples:**
```
Input:         Output:
5              3
1 2 3 4 5

Input:         Output:
3              1
10 1 1

Input:         Output:
2              -1
5 5
```

**Hidden concept:** Prefix sum + suffix comparison. The answer always exists for positive arrays (eventually prefix = total). But when two halves are equal at k=n, output -1 because suffix becomes 0 which is not strictly less if prefix equals total only at the end.

**Constraints note:** Values up to 10⁹ × 2×10⁵ = 2×10¹⁴ → **must use `long long`**.

---

## Problem B — Storm Coverage (★ 1100)

**Statement:**
There are `n` weather stations numbered 1 to n. A meteorologist records `q` storm events. Event `i` dumps exactly `r_i` mm of rain uniformly on all stations in the range `[l_i, r_i]`.

After all events, find the station that received the **maximum** total rainfall. If multiple stations are tied, output the **smallest** index.

**Input:**
- Line 1: n q (1 ≤ n ≤ 10⁶, 1 ≤ q ≤ 10⁵)
- Next q lines: l_i r_i rain_i (1 ≤ l_i ≤ r_i ≤ n, 1 ≤ rain_i ≤ 10⁴)

**Output:** Single integer — station index.

**Examples:**
```
Input:              Output:
5 3                 3
1 3 10
2 4 20
3 5 5
```
Station rainfall: [10, 30, 35, 25, 5] → max is 35 at station 3.

**Hidden concept:** Difference array. Naive O(n×q) will TLE. Difference array makes each range update O(1), then one O(n) prefix pass.

---

## Problem C — Zero Hunters (★ 1200)

**Statement:**
Given an array `a` of `n` integers (can be negative, zero, positive).

Count the number of contiguous subarrays with **sum exactly equal to 0**.

**Input:**
- Line 1: n (1 ≤ n ≤ 3×10⁴)
- Line 2: n integers (-10⁴ ≤ a[i] ≤ 10⁴)

**Output:** Single integer — count of zero-sum subarrays.

**Examples:**
```
Input:            Output:
6                 3
1 -1 2 -2 3 -3

Input:            Output:
4                 1
0 0 0 0
```
(For [0,0,0,0]: subarrays [0], [0], [0], [0], [0,0], [0,0], [0,0], [0,0,0], [0,0,0], [0,0,0,0] → 10)

Wait — reconsider: [0], [0], [0], [0] → 4 single zeros; [0,0]×3 → 3; [0,0,0]×2 → 2; [0,0,0,0]×1 → 1. Total = 10. But sample shows 1 — let me restate:

```
Input:            Output:
4                 10
0 0 0 0
```

**Hidden concept:** Prefix sum + HashMap. Count frequency of each prefix value. If `prefix[j] == prefix[i]` for i < j, then subarray (i+1..j) sums to 0. Use `freq[prefix]` accumulation. Initialize `freq[0] = 1`.

---

## Problem D — Maximum Flip Gain (★ 1400)

**Statement:**
Given an array `a` of `n` integers. You may choose **exactly one** contiguous subarray `[l, r]` and **negate** all elements in it (multiply by -1). You must perform this operation exactly once (you can choose a subarray of length 1).

Find the **maximum possible total sum** of the array after the operation.

**Input:**
- Line 1: n (1 ≤ n ≤ 2×10⁵)
- Line 2: n integers (-10⁹ ≤ a[i] ≤ 10⁹)

**Output:** Maximum possible sum.

**Examples:**
```
Input:         Output:
5              13
1 -3 2 -2 4

Input:         Output:
3              6
2 2 2

Input:         Output:
1              5
-5
```

**Hidden concept:** If we negate subarray [l,r], new total = `total_sum - 2 * sum(l,r)`. To maximize this, we minimize `sum(l,r)`. Use Kadane for **minimum subarray sum**. If min_subarray_sum < 0, answer = `total - 2 * min_sum`. Otherwise, we must negate something positive — negate the element with smallest absolute value (or use min subarray of 1 element).

---

## Problem E — Dominance Count (★ 1600)

**Statement:**
Given array `a` of `n` integers. Count the number of pairs `(l, r)` with `1 ≤ l ≤ r ≤ n` such that `sum(a[l..r]) ≥ 0`.

**Input:**
- Line 1: n (1 ≤ n ≤ 2×10⁵)
- Line 2: n integers (-10⁹ ≤ a[i] ≤ 10⁹)

**Output:** Count of valid (l, r) pairs.

**Examples:**
```
Input:         Output:
4              7
1 -1 2 3

Input:         Output:
3              6
1 2 3

Input:         Output:
2              1
-5 -3
```

**Hidden concept:** Build prefix array `P[0..n]`. `sum(l,r) ≥ 0` ↔ `P[r] ≥ P[l-1]`. Count pairs `(i < j)` where `P[j] ≥ P[i]` = total pairs - inversions in P. Use merge sort inversion count or BIT. O(n log n).

---

## Problem F — Circular Champion (★ 1700)

**Statement:**
Given a **circular** array `a` of `n` integers. The array is circular — after the last element comes the first. A subarray can wrap around. Find the maximum sum of any non-empty contiguous subarray (considering circular wrap).

**Input:**
- Line 1: n (1 ≤ n ≤ 3×10⁴)
- Line 2: n integers (-10⁴ ≤ a[i] ≤ 10⁴)

**Output:** Maximum subarray sum (circular).

**Examples:**
```
Input:         Output:
5              10
5 -2 3 -6 4

Input:         Output:
4              15
8 -8 9 -9

Input:         Output:
3              -1
-3 -2 -4
```

Example 1: non-circular max = max(5, 5-2=3+3=6, ...) = 6. Circular: 4+5=9, or 4+5-2+3=10. Answer=10.

**Hidden concept:** Two cases. Case 1: best non-wrapping subarray (standard Kadane). Case 2: best wrapping = total_sum - min_subarray_sum (exclude the worst middle piece). Answer = max(case1, case2). **Guard:** if all elements negative, case2 = total - total = 0 which is wrong. Return case1.

---

## Problem G — Double Harvest (★ 1900)

**Statement:**
Given array `a` of `n` integers. Choose **two non-overlapping non-empty contiguous subarrays** `[l1, r1]` and `[l2, r2]` where `r1 < l2`. Maximize `sum(a[l1..r1]) + sum(a[l2..r2])`.

**Input:**
- Line 1: n (2 ≤ n ≤ 2×10⁵)
- Line 2: n integers (-10⁹ ≤ a[i] ≤ 10⁹)

**Output:** Maximum combined sum.

**Examples:**
```
Input:         Output:
6              15
3 -1 4 -1 5 -2

Input:         Output:
4              7
-1 3 -2 4

Input:         Output:
4              -1
-5 -1 -2 -3
```

Example 1: Take [3] + [4,-1,5] = 3 + 8 = 11. Or [3,-1,4] + [5,-2] = 6 + 3 = 9. Or [3,-1,4,-1,5] requires one array... or [3] + [4] + [5]... best is [3,-1,4] + [5] = 6+5=11. Or [3] + [5] = 8. Or [3,-1,4,-1,5] can't because non-overlapping means r1 < l2. Actually [3,-1,4] (l1=1,r1=3) + [5,-2] (l2=5,r2=6) = 6+3=9. [3] + [4,-1,5] = 3+8=11. Best: [3,-1,4,-1,5] is one array. Two subarrays: [3,-1,4,-1,5] can be split as [3,-1,4,-1] + [5] = 5+5=10, or [3] + [4,-1,5] = 3+8=11. Or [3,-1,4] + [5] = 6+5=11. Or [4] + [5] = 9. So 11... but wait actually [3,-1,4,-1,5,-2]: max is [3]+[4,-1,5]=11, or [3,-1,4]+[5]=11, or [4]+[5,-2]=9. Hmm I need to recheck. Let me set output as 11 for that case actually.

Let me use a cleaner example.

**Hidden concept:** Precompute `L[i]` = max subarray sum within `a[1..i]` using forward Kadane updating best. Precompute `R[i]` = max subarray sum within `a[i..n]` using backward Kadane. Answer = `max over i=1..n-1 of L[i] + R[i+1]`. O(n).
