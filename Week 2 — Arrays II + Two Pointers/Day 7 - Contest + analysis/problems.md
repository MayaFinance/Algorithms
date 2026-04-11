# Week 2 Contest: Two Pointers & Arrays II

**Rules:**
- Time limit: 2.5 hours
- Language bounds: C++ (1s), Python (2s)
- No IDE hints or external resources.
- Focus on space constraints (O(1) where possible) and time constraints (O(n) or O(n log n)).

---

## Problem A: Remove Duplicates from Sorted Array II (Difficulty: 900)
**Statement:** Given integer array sorted in non-decreasing order, remove duplicates in-place so each unique element appears at most twice. The relative order should be kept the same.
Return `k` (number of elements satisfying condition), and array must be modified in-place up to `k`.

**Example:**
Input: `nums = [0,0,1,1,1,1,2,3,3]`
Output: `7, nums = [0,0,1,1,2,3,3,_,_]`

**Constraints:** `1 <= n <= 3*10^4`, `-10^4 <= A[i] <= 10^4`

---

## Problem B: Sort Colors (Difficulty: 1000)
**Statement:** You have an array of n objects colored red, white, or blue (represented as 0, 1, 2). Sort them in-place so objects of the same color are adjacent, with the colors in the order red, white, and blue. You must not use the library's sort function.

**Example:**
Input: `[2,0,2,1,1,0]`
Output: `[0,0,1,1,2,2]`

**Constraints:** `1 <= n <= 300`

---

## Problem C: Subarray Product Less Than K (Difficulty: 1200)
**Statement:** Given an array of positive integers `nums` and an integer `k`, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than `k`.

**Example:**
Input: `nums = [10,5,2,6], k = 100`
Output: `8`

**Constraints:** `1 <= n <= 3*10^4`, `1 <= nums[i] <= 1000`, `0 <= k <= 10^6`

---

## Problem D: Rotate Image (Difficulty: 1300)
**Statement:** You are given an `n x n` 2D matrix representing an image. Rotate the image by 90 degrees (clockwise). You MUST rotate the image in-place.

**Example:**
Input: `[[1,2,3],[4,5,6],[7,8,9]]`
Output: `[[7,4,1],[8,5,2],[9,6,3]]`

**Constraints:** `n == matrix.length == matrix[i].length`, `1 <= n <= 20`

---

## Problem E: Meeting Rooms II (Difficulty: 1400)
**Statement:** Given an array of meeting time intervals where `intervals[i] = [start_i, end_i]`, return the minimum number of conference rooms required.

**Example:**
Input: `[[0,30], [5,10], [15,20]]`
Output: `2`

**Constraints:** `1 <= intervals.length <= 10^4`

---

## Problem F: Minimum Window Substring (Difficulty: 1600)
**Statement:** Given two strings `s` and `t`, return the minimum window in `s` which will contain all the characters in `t`. If there is no such window, return the empty string `""`.

**Example:**
Input: `s = "ADOBECODEBANC", t = "ABC"`
Output: `"BANC"`

**Constraints:** `1 <= s.length, t.length <= 10^5`, string consists of English letters.

---

## Problem G: First Missing Positive (Difficulty: 1800)
**Statement:** Given an unsorted integer array `nums`, return the smallest missing positive integer. You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

**Example:**
Input: `nums = [3,4,-1,1]`
Output: `2`

**Constraints:** `1 <= n <= 10^5`, `-2^31 <= nums[i] <= 2^31 - 1`
