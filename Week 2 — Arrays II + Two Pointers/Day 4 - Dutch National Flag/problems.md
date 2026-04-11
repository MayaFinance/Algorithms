# Day 4: Dutch National Flag & Partitioning — Problem Set

---

## Problem 1: Sort Colors ⭐ Easy (LC 75)
**Statement:** Array of n objects colored red (0), white (1), blue (2). Sort them in-place.
**Constraints:** 1 ≤ n ≤ 300, nums[i] in {0,1,2}
**Example:** `[2,0,2,1,1,0]` → `[0,0,1,1,2,2]`
**Pattern:** Pure DNF. `low`=0s, `mid`=1s (explorer), `high`=2s.

---

## Problem 2: Move Zeros (Partition Variant) ⭐ Easy (LC 283)
**Statement:** Move all 0s to the end while maintaining relative order of non-zeros.
**Example:** `[0,1,0,3,12]` → `[1,3,12,0,0]`
**Pattern:** 2-way partition (Lomuto). Condition: `a[fast] != 0`. Swap `a[slow]` and `a[fast]`.

---

## Problem 3: Segregate Even and Odd Numbers ⭐ Easy
**Statement:** Put all even numbers before odd numbers. Order doesn't matter. In-place.
**Example:** `[3, 1, 2, 4]` → `[2, 4, 3, 1]` or similar
**Pattern:** Lomuto 2-way.

---

## Problem 4: Sort Array by Parity II ⭐⭐ Medium (LC 922)
**Statement:** Half even, half odd array. Put evens at even indices, odds at odd indices. In-place.
**Example:** `[4,2,5,7]` → `[4,5,2,7]`
**Pattern:** Two points: `e=0` (evens) and `o=1` (odds). If `a[e]` is odd, find an even misplaced at `a[o]` and swap.

---

## Problem 5: Array Partition by Pivot ⭐⭐ Medium
**Statement:** Given array `a` and pivot `k`. Reorder so elements `< k` come first, `== k` next, `> k` last.
**Example:** `[5, 2, 8, 5, 1, 9], k=5` → `[2, 1, 5, 5, 8, 9]`
**Pattern:** Classic DNF but 0 is `<k`, 1 is `==k`, 2 is `>k`.

---

## Problem 6: Wiggle Sort ⭐⭐ Medium (LC 280)
**Statement:** Sort array such that `nums[0] <= nums[1] >= nums[2] <= nums[3]...` in O(n) in-place.
**Example:** `[3, 5, 2, 1, 6, 4]` → `[3, 5, 1, 6, 2, 4]`
**Pattern:** Odd/Even index swap rule. If `i` is odd and `a[i] < a[i-1]`, swap. If `i` is even and `a[i] > a[i-1]`, swap.

---

## Problem 7: Minimize Memory (Sort 0s, 1s, 2s, 3s) ⭐⭐ Medium
**Statement:** Sort array with 4 distinct values (0, 1, 2, 3) in O(n) O(1).
**Pattern:** Multi-pass DNF. Pass 1: separate 0s from the rest. Pass 2: separate 1s, 2s, 3s on the remainder.

---

## Problem 8: QuickSort Partition Step (Hoare's) ⭐⭐ Medium
**Statement:** Implement Hoare's partition scheme around pivot `a[0]`.
**Pattern:** Two-end pointers. Move `l` right while `< pivot`. Move `r` left while `> pivot`. Swap.

---

## Problem 9: Kth Largest Element (QuickSelect) ⭐⭐ Medium (LC 215)
**Statement:** Find the `k`th largest element in unsorted array.
**Constraints:** 1 ≤ k ≤ n ≤ 10⁵, **average** O(n) required.
**Pattern:** Lomuto partition with a random pivot. If pivot index == n-k, return it.

---

## Problem 10: Pancake Sorting ⭐⭐ Medium (LC 969)
**Statement:** Sort an array using only operations "reverse prefix of length k".
**Example:** `[3,2,4,1]`
**Pattern:** Find max unplaced element, flip it to index 0, flip it to its correct index at the back. Like Selection Sort but via flips.
