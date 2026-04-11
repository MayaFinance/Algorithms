# Day 1: Two Pointers (Same Direction) — Problem Set

---

## Problem 1: Remove Element ⭐ Easy (LC 27)
**Statement:** Given array `nums` and value `val`, remove all occurrences of `val` in-place. Return new length.
**Constraints:** 0 ≤ n ≤ 100, 0 ≤ val ≤ 100
**Example:** `nums=[3,2,2,3], val=3` → `2` (array becomes `[2,2,_,_]`)
**Edge cases:** all elements = val (return 0), no elements = val (return n), n=0.
**Pattern:** Write pointer — fast reads all, slow writes only non-val elements.
**Complexity:** O(n) time, O(1) space.

---

## Problem 2: Remove Duplicates from Sorted Array ⭐ Easy (LC 26)
**Statement:** Given sorted array, remove duplicates in-place. Return new length.
**Constraints:** 1 ≤ n ≤ 3×10⁴, sorted.
**Example:** `[1,1,2]` → `2`, `[0,0,1,1,1,2,2,3,3,4]` → `5`
**Edge cases:** n=1 (already unique), all same (length 1), all unique (length n).
**Pattern:** slow holds last unique; only advance slow when `arr[fast] != arr[slow]`.
**Complexity:** O(n), O(1).

---

## Problem 3: Remove Duplicates II — Keep at Most 2 ⭐⭐ Easy-Medium (LC 80)
**Statement:** Sorted array. Keep each element at most twice. In-place. Return new length.
**Constraints:** 1 ≤ n ≤ 3×10⁴
**Example:** `[1,1,1,2,2,3]` → `5` → array `[1,1,2,2,3]`
**Edge cases:** n ≤ 2 (always valid), all same (keep 2), alternating.
**Pattern:** Compare `arr[fast]` to `arr[slow-2]` (not slow-1). If different, keep.
**Complexity:** O(n), O(1).

---

## Problem 4: Move Zeros with Order ⭐ Easy (LC 283)
**Statement:** Move all zeros to end, maintain relative order of non-zeros. In-place.
**Constraints:** 1 ≤ n ≤ 10⁴
**Example:** `[0,1,0,3,12]` → `[1,3,12,0,0]`
**Edge cases:** all zeros, no zeros, single zero at start/end.
**Pattern:** Write non-zeros via slow pointer, then fill tail with zeros.
**Complexity:** O(n), O(1).

---

## Problem 5: Squares of Sorted Array ⭐ Easy (LC 977)
**Statement:** Given **sorted** (possibly negative) array, return array of squares **sorted**.
**Constraints:** 1 ≤ n ≤ 10⁴, -10⁴ ≤ a[i] ≤ 10⁴
**Example:** `[-4,-1,0,3,10]` → `[0,1,9,16,100]`
**Edge cases:** all negative, all positive, single element, contains zero.
**Pattern:** Opposite-direction two pointers (two ends), fill result from back. (Uses same-direction variant if only negatives/positives.)
**Complexity:** O(n), O(n) for result.

---

## Problem 6: Find the Duplicate Number ⭐⭐ Medium (LC 287)
**Statement:** Array of n+1 integers in [1,n]. Exactly one duplicate exists. Find it without modifying array, O(1) extra space.
**Constraints:** 1 ≤ n ≤ 10⁵
**Example:** `[1,3,4,2,2]` → `2`, `[3,1,3,4,2]` → `3`
**Edge cases:** duplicate appears more than twice, n=2 (trivial).
**Pattern:** Floyd's cycle detection. Array treated as implicit linked list: `f(i) = arr[i]`.
- Phase 1: find meeting point (slow×1, fast×2).
- Phase 2: reset slow to 0, both move ×1, meet at cycle start = duplicate.
**Complexity:** O(n), O(1).

---

## Problem 7: Longest Substring Without Repeating Characters ⭐⭐ Medium (LC 3)
**Statement:** Find length of longest substring without repeating characters.
**Constraints:** 0 ≤ n ≤ 5×10⁴
**Example:** `"abcabcbb"` → `3` ("abc"), `"bbbbb"` → `1`, `"pwwkew"` → `3`
**Edge cases:** empty string → 0, all same → 1, all unique → n.
**Pattern:** Sliding window (same-direction). Right expands; left shrinks when character repeats. Use HashMap for last seen index.
**Complexity:** O(n), O(min(n, charset)).

---

## Problem 8: Minimum Size Subarray Sum ⭐⭐ Medium (LC 209)
**Statement:** Positive integer array. Find minimum-length subarray with sum ≥ s.
**Constraints:** 1 ≤ n ≤ 10⁵, 1 ≤ s ≤ 10⁸
**Example:** `[2,3,1,2,4,3], s=7` → `2` (subarray `[4,3]`)
**Edge cases:** total sum < s (return 0), single element ≥ s (return 1).
**Pattern:** Sliding window — right always advances; left shrinks when sum ≥ s, recording min length.
**Complexity:** O(n), O(1).

---

## Problem 9: Merge Sorted Array ⭐⭐ Easy-Medium (LC 88)
**Statement:** Two sorted arrays `nums1` (m+n space) and `nums2` (n elements). Merge into `nums1` in-place sorted.
**Constraints:** 0 ≤ m, n ≤ 200
**Example:** `nums1=[1,2,3,0,0,0], m=3; nums2=[2,5,6], n=3` → `[1,2,2,3,5,6]`
**Edge cases:** m=0 (just copy nums2), n=0 (nothing to do), all nums2 > all nums1.
**Pattern:** Fill from the back. Two read pointers (m-1, n-1), one write pointer (m+n-1). Avoid overwriting unread nums1 elements.
**Complexity:** O(m+n), O(1).

---

## Problem 10: Count Pairs with Sum < K ⭐⭐ Medium (Codeforces style)
**Statement:** Given **sorted** array `a` of n integers. Count pairs (i, j) with i < j and `a[i] + a[j] < k`.
**Constraints:** 1 ≤ n ≤ 10⁵, -10⁹ ≤ a[i] ≤ 10⁹
**Example:** `a=[-2,0,1,3], k=2` → `5` (pairs: (-2,0),(-2,1),(-2,3),(0,1),(0,3)... let's verify: -2+3=1<2✓, 0+1=1<2✓, 0+3=3≥2✗. Answer=4.)
**Edge cases:** all pairs valid, no pairs valid, n=2.
**Pattern:** Two pointers from both ends (opposite-direction). For each left pointer: if `a[l]+a[r] < k`, all elements a[l+1..r] paired with a[l] are valid → count += r-l, then l++. Else r--.
**Complexity:** O(n log n) sort + O(n) scan = O(n log n).

---

## Problem 11: Subarray Product Less Than K ⭐⭐ Medium (LC 713)
**Statement:** Count subarrays where product of all elements is strictly less than k.
**Constraints:** 1 ≤ n ≤ 3×10⁴, 0 < nums[i] < 1000, 0 < k ≤ 10⁶
**Example:** `[10,5,2,6], k=100` → `8`
**Edge cases:** k ≤ 1 (no subarray can have product < 1 since all elements ≥ 1 → return 0), single element.
**Pattern:** Sliding window. Right expands multiplying in; left shrinks dividing out when product ≥ k. Each valid right position contributes (r - l + 1) subarrays.
**Complexity:** O(n), O(1).

---

## Problem 12: Maximum Consecutive Ones III ⭐⭐ Medium (LC 1004)
**Statement:** Binary array. Flip at most k zeros to ones. Find length of longest subarray of ones.
**Constraints:** 1 ≤ n ≤ 10⁵, 0 ≤ k ≤ n
**Example:** `[1,1,1,0,0,0,1,1,1,1,0], k=2` → `6`
**Edge cases:** k=0 (only count existing runs), k≥n (answer is n), all zeros, all ones.
**Pattern:** Sliding window. Track count of zeros in window. Left shrinks when zeros > k.
**Complexity:** O(n), O(1).

---

## QUIZ (attempt before checking solutions)
1. What is the correct initialization for `slow` when removing duplicates from a sorted array of length ≥ 1?
2. In Floyd's cycle detection, why does resetting slow to head and moving both 1 step find the cycle start?
3. Why does sliding window work for product-less-than-k but NOT for subarray-count-equal-to-k?
4. In Problem 9 (merge sorted array), why do we fill from the back, not the front?
5. What is `slow` equal to at the end of the remove-element operation — the new length or the last index?
