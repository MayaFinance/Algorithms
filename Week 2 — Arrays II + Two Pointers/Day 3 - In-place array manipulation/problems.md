# Day 3: In-Place Array Manipulation — Problem Set

---
## P1: Move Zeros ⭐ Easy (LC 283) — Write pointer + zero fill
## P2: Remove Duplicates Sorted ⭐ Easy (LC 26) — slow/fast
## P3: Find All Duplicates [1..n] ⭐⭐ Medium (LC 442) — sign-marking O(1) space
**Statement:** Array of n integers in [1,n]. Some appear twice. Find all duplicates.
**Example:** [4,3,2,7,8,2,3,1] → [2,3]
**Key:** Negate arr[|x|-1] as "visited" flag. Already negative → duplicate.
## P4: Rotate Array Right by k ⭐⭐ Easy (LC 189) — Triple reversal
**Statement:** Rotate array right by k positions.
**Example:** [1,2,3,4,5,6,7] k=3 → [5,6,7,1,2,3,4]
**Key:** rev(0,n-1); rev(0,k-1); rev(k,n-1). O(n) O(1).
## P5: Rotate Array Left by k — symmetric variant
## P6: First Missing Positive ⭐⭐ Hard (LC 41) — Cyclic placement
**Statement:** Find smallest missing positive integer. O(n) time O(1) space.
**Example:** [3,4,-1,1] → 2, [1,2,0] → 3, [7,8,9] → 1
**Key:** Place x at index x-1 using swaps. Then scan for index where arr[i]≠i+1.
## P7: Sort Colors ⭐⭐ Medium (LC 75) — Dutch National Flag preview
**Statement:** Sort [0,1,2] in-place.
**Example:** [2,0,2,1,1,0] → [0,0,1,1,2,2]
## P8: Next Permutation ⭐⭐ Medium (LC 31)
**Statement:** Rearrange to next lexicographic permutation in-place.
**Example:** [1,2,3]→[1,3,2], [3,2,1]→[1,2,3], [1,1,5]→[1,5,1]
**Key:** Find rightmost descent; swap with smallest larger element to right; reverse suffix.
## P9: Find Missing Number ⭐ Easy (LC 268) — XOR or Gauss formula
**Statement:** [0..n] with one missing. Find it. O(n) O(1).
**Example:** [3,0,1] → 2
**Key:** XOR all indices and all values → missing XORs out.
## P10: Maximum Product Subarray — Variation ⭐⭐ Medium
**Statement:** Float array with negatives. In-place tracking of max and min products.
**Key:** Track both max_prod and min_prod (negatives can flip sign).
