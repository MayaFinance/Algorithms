# Day 2: Two Pointers (Opposite Direction) — Problem Set

---

## Problem 1: Two Sum II — Sorted Array ⭐ Easy (LC 167)
**Statement:** Given sorted array, find two indices (1-indexed) summing to target. Exactly one solution guaranteed.
**Example:** `[2,7,11,15], target=9` → `[1,2]`
**Edge:** target very large (overflow guard), single valid pair.
**Pattern:** Classic two-end pointer. sum<target→l++, sum>target→r--.
**Complexity:** O(n), O(1).

---

## Problem 2: Valid Palindrome ⭐ Easy (LC 125)
**Statement:** String may have non-alphanumeric chars. Ignore case. Is it a palindrome?
**Example:** `"A man, a plan, a canal: Panama"` → true, `"race a car"` → false
**Edge:** empty/single char → true, all non-alphanumeric → true.
**Pattern:** l from left (skip non-alnum), r from right (skip non-alnum). Compare lowercased.
**Complexity:** O(n), O(1).

---

## Problem 3: Container With Most Water ⭐⭐ Medium (LC 11)
**Statement:** n non-negative heights. Find two bars enclosing maximum water.
**Example:** `[1,8,6,2,5,4,8,3,7]` → `49`
**Edge:** n=2 (only one container), all same height, strictly increasing.
**Pattern:** Move the shorter-height pointer inward. Proof: moving taller pointer can only decrease or maintain water (taller already limits nothing).
**Complexity:** O(n), O(1).

---

## Problem 4: Reverse String / Array ⭐ Easy (LC 344)
**Statement:** Reverse array in-place.
**Example:** `['h','e','l','l','o']` → `['o','l','l','e','h']`
**Edge:** n=1 (no-op), n=2 (single swap).
**Pattern:** swap(l, r); l++; r--. Loop while l < r.
**Complexity:** O(n), O(1).

---

## Problem 5: Three Sum ⭐⭐ Medium (LC 15)
**Statement:** Find all unique triplets summing to zero.
**Constraints:** -10⁵ ≤ nums[i] ≤ 10⁵, 3 ≤ n ≤ 3000
**Example:** `[-1,0,1,2,-1,-4]` → `[[-1,-1,2],[-1,0,1]]`
**Edge:** all positive (no solution), all same (only if 0,0,0), many duplicates.
**Pattern:** Sort. Fix i (skip dups). Two-pointer on right portion. Skip dups after finding triple.
**Complexity:** O(n²), O(1) extra.

---

## Problem 6: Three Sum Closest ⭐⭐ Medium (LC 16)
**Statement:** Find triplet with sum closest to target. Return the sum.
**Constraints:** 3 ≤ n ≤ 500, -10⁴ ≤ nums[i] ≤ 10⁴
**Example:** `[-1,2,1,-4], target=1` → `2`
**Pattern:** Same outer loop. Track closest. If sum<target→l++, sum>target→r--.
**Complexity:** O(n²), O(1).

---

## Problem 7: Two Sum IV (BST) → Array Variant ⭐⭐ Medium
**Statement:** Given sorted array. Count pairs (i,j) with i<j where |a[i]-a[j]| ≤ k.
**Example:** `a=[1,3,5,7], k=3` → `5`
**Pattern:** Opposite pointers. Trick: if |a[r]-a[l]|≤k, all inner pairs (l…r-1, r) and (l, l+1…r) qualify → count += r-l. Then l++.
**Complexity:** O(n), O(1) (after sort).

---

## Problem 8: Trapping Rain Water ⭐⭐ Medium-Hard (LC 42)
**Statement:** Elevation map. Total water trapped.
**Example:** `[0,1,0,2,1,0,1,3,2,1,2,1]` → `6`
**Pattern:** Two-end pointers. Track lmax, rmax. Process shorter side — water at that cell = max_side - height.
**Complexity:** O(n), O(1).

---

## Problem 9: Four Sum ⭐⭐ Medium (LC 18)
**Statement:** Find all unique quadruplets summing to target.
**Constraints:** 1 ≤ n ≤ 200
**Example:** `[1,0,-1,0,-2,2], target=0` → `[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]`
**Pattern:** Two outer loops (fix i,j) + inner two-pointer. Skip dups at all 3 levels.
**Complexity:** O(n³), O(1).

---

## Problem 10: Shortest Unsorted Subarray ⭐⭐ Medium (LC 581)
**Statement:** Find length of shortest subarray that, when sorted, makes whole array sorted.
**Example:** `[2,6,4,8,10,9,15]` → `5`
**Pattern:** From left: find rightmost element out of place. From right: find leftmost element out of place. Find min/max in that range, expand boundaries.
**Complexity:** O(n), O(1).

---

## Problem 11: Minimum Absolute Difference in Sorted Array ⭐ Easy-Medium
**Statement:** Sorted array. You want the pair (i,j), i<j, minimizing |a[i]-a[j]|.
**Example:** `[1,3,6,10,15], pair?` → `(1,3)` diff=2
**Pattern:** Adjacent elements always form the minimum difference pair in sorted arrays. But if asked to "maximize minimum" → opposite-direction binary search.
**Complexity:** O(n) scan adjacent OR O(n) two-pointer.

---

## Problem 12: Valid Palindrome II — One Deletion Allowed ⭐⭐ Medium (LC 680)
**Statement:** Can the string be made palindrome by deleting at most one character?
**Example:** `"aba"` → true, `"abca"` → true (delete b or c), `"abc"` → false
**Pattern:** Two-end pointer. On mismatch at (l,r): try skip l OR skip r, check if remaining is palindrome.
**Complexity:** O(n), O(1).
