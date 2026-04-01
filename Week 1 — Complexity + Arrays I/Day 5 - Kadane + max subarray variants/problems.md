# Kadane's Algorithm — Problem Set

All problems categorized by difficulty. Attempt before revealing solutions.

---

## Problem 1: Maximum Subarray (LeetCode 53) ⭐ Easy-Medium
**Description:** Given an integer array `nums`, find the subarray with the largest sum and return its sum.

**Goal:** Standard Kadane's. Initialize with first element to handle all-negative arrays. O(n) time, O(1) space.

**Constraints:** `1 <= nums.length <= 10^5`, `-10^4 <= nums[i] <= 10^4`

---

## Problem 2: Maximum Sum Circular Subarray (LeetCode 918) ⭐⭐ Medium
**Description:** Given a circular integer array `nums`, return the maximum possible sum of a non-empty subarray.

**Goal:** Dual case. Run standard Kadane for `max_sum`. Run inverse Kadane for `min_sum`. Answer is `max(max_sum, total_sum - min_sum)`. Guard against all-negative case.

**Constraints:** `1 <= nums.length <= 3 * 10^4`, `-3 * 10^4 <= nums[i] <= 3 * 10^4`

---

## Problem 3: Maximum Product Subarray (LeetCode 152) ⭐⭐ Medium
**Description:** Given an integer array `nums`, find the contiguous subarray that has the largest product and return the product.

**Goal:** Maintain both `curr_max` and `curr_min` at each step because a negative product of two negatives becomes the new maximum.

**Constraints:** `1 <= nums.length <= 2 * 10^4`, `-10 <= nums[i] <= 10`

---

## Problem 4: Best Time to Buy and Sell Stock (LeetCode 121) ⭐ Easy
**Description:** You are given a `prices` array where `prices[i]` is the price on day `i`. Maximize profit by buying and selling once.

**Goal:** Kadane's pattern applied to price differences. Track running min price and max profit in one pass.

---

## Problem 5: Maximum Subarray Sum with One Deletion (LeetCode 1186) ⭐⭐ Medium
**Description:** Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deleted.

**Goal:** Precompute `left[i]` (max sum ending at i) and `right[i]` (max sum starting at i). Bridge them at each possible deletion point.

---

## Problem 6: Maximum Absolute Sum (LeetCode 1749) ⭐⭐ Medium
**Description:** Return the maximum absolute sum of any (possibly empty) subarray.

**Goal:** Track both max-ending-here and min-ending-here Kadane states. The answer is `max(global_max, abs(global_min))`.

---

## Problem 7: Count Subarrays with Score Less Than K (LeetCode 2302) ⭐⭐ Medium-Hard
**Description:** The score of an array is the product of its sum and its length. Return the number of non-empty subarrays with score strictly less than `k`.

**Goal:** Sliding window + prefix sums. Recognize the Kadane-type contiguous constraint combined with a two-pointer shrinking window.

---

## Problem 8: Maximum Sum Rectangle (2D Kadane) ⭐⭐⭐ Hard
**Description:** Given a 2D matrix of integers, find the submatrix with the largest sum.

**Goal:** For each pair of left/right column boundaries, compress all rows into a 1D array (summing each row horizontally). Run Kadane on the 1D array to get optimal top/bottom boundaries.

---

## Problem 9: Subarray Sum Equals K (LeetCode 560) ⭐⭐ Medium
**Description:** Given an integer array, return the total number of subarrays whose sum equals `k`.

**Goal:** Prefix sum + HashMap pattern (NOT Kadane), but critical to recognize when Kadane doesn't apply — it requires a fixed target rather than maximization.

---

## Problem 10: Kadane on Segment Tree (Range Maximum Subarray Query) ⭐⭐⭐ Hard
**Description:** Given a static or dynamic array and multiple range [l, r] queries asking for the maximum subarray sum within the range.

**Goal:** Augment each segment tree node with 4 values: `total`, `max_prefix`, `max_suffix`, `max_sub`. Merge logic mimics Kadane's transition. O(log n) per query.
