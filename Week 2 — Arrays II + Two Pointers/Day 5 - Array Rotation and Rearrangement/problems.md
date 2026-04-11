# Day 5: Array Rotation & Rearrangement — Problem Set

---

## Problem 1: Rotate Array Right ⭐ Easy (LC 189)
**Statement:** Given integer array, rotate to right by `k` steps. Extra space = O(1).
**Example:** `[1,2,3,4,5,6,7], k=3` → `[5,6,7,1,2,3,4]`
**Pattern:** Triple Reversal method.

---

## Problem 2: Rotate Image (Matrix 90 deg) ⭐⭐ Medium (LC 48)
**Statement:** `n x n` 2D matrix representing image. Rotate 90 degrees clockwise in-place.
**Example:** `[[1,2,3],[4,5,6],[7,8,9]]` → `[[7,4,1],[8,5,2],[9,6,3]]`
**Pattern:** Transpose then reverse rows.

---

## Problem 3: Build Array from Permutation ⭐ Easy (LC 1920)
**Statement:** Array `nums` is a permutation of `0` to `n-1`. Build `ans` where `ans[i] = nums[nums[i]]`. Do it in O(1) space.
**Example:** `[0,2,1,5,3,4]` → `[0,1,2,4,5,3]`
**Pattern:** Encoding trick: `a[i] += (a[a[i]] % n) * n`. Then decode: `a[i] /= n`.

---

## Problem 4: Rearrange Array Alternately ⭐⭐ Medium
**Statement:** Sorted array of positive integers. Rearrange as: `max, min, 2nd max, 2nd min...` in O(1) space.
**Example:** `[1, 2, 3, 4, 5, 6, 7]` → `[7, 1, 6, 2, 5, 3, 4]`
**Pattern:** Use two pointers (`max_idx=n-1, min_idx=0`). Encode new values using `M = max_val + 1`.

---

## Problem 5: Search in Rotated Sorted Array ⭐⭐ Medium (LC 33)
**Statement:** Array is sorted, then rotated at unknown pivot. Find target in O(log n).
**Example:** `[4,5,6,7,0,1,2], target=0` → `4`
**Pattern:** Binary search. One half is always strictly strictly sorted. Find which half it is, check if target lies within that half.

---

## Problem 6: Find Minimum in Rotated Sorted Array ⭐⭐ Medium (LC 153)
**Statement:** Array is sorted, then rotated. Find minimum element in O(log n). All elements unique.
**Example:** `[3,4,5,1,2]` → `1`
**Pattern:** Binary search. If `a[mid] > a[right]`, min is to the right. Else it's `mid` or left.

---

## Problem 7: Minimum Number of Increments on Subarrays to Form a Target Array ⭐⭐⭐ Hard (LC 1526)
**Statement:** Array `target`. You have initial array `A` of all zeros. You can pick subarray and increment by 1. Minimum ops to match target?
**Example:** `[1,2,3,2,1]` → `3`
**Pattern:** Math/Rearrangement. Answer is `target[0] + sum(max(0, target[i] - target[i-1]))`. (Every time target goes up, we need new operations).

---

## Problem 8: Spiral Matrix Order ⭐⭐ Medium (LC 54)
**Statement:** Return all elements of `m x n` matrix in spiral order.
**Example:** `[[1,2,3],[4,5,6],[7,8,9]]` → `[1,2,3,6,9,8,7,4,5]`
**Pattern:** Four boundaries: top, bottom, left, right. Traverse and shrink boundaries until they overlap.

---

## Problem 9: Set Matrix Zeroes ⭐⭐ Medium (LC 73)
**Statement:** If an element is 0, set its entire row and col to 0 in-place.
**Example:** `[[1,1,1],[1,0,1],[1,1,1]]` → `[[1,0,1],[0,0,0],[1,0,1]]`
**Pattern:** Use first row and first column as the "storage markers" (O(1) space). Use 2 booleans for the first row/col themselves.

---

## Problem 10: Valid Array Rearrangement (Check if Array Pairs are Divisible by K) ⭐⭐ Medium (LC 1497)
**Statement:** Can array be paired such that `sum(pair) % k == 0`?
**Pattern:** Math/Frequency count of remainders modulo k. Count of `x` must equal count of `k-x`. Count of `0` must be even.
