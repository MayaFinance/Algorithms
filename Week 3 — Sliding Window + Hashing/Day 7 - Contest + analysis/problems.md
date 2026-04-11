# Day 7: Weekly Contest + Analysis

*Simulate a 2-Hour Codeforces Div 2 / LeetCode Weekly Contest. Do not look at solutions until time is up.*

---

## 🟢 Problem A: Maximum Erasure Value (LC 1695)
**Score:** 500
**Time Limit:** 1.0s
**Statement:** You are given an array of positive integers `nums` and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements. Return the maximum score you can get by erasing exactly one subarray.
**Constraints:**
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
**Example:** `nums = [4,2,4,5,6]` $\rightarrow$ `17` (erase `[2,4,5,6]`)
**Hidden Trick:** Variable Sliding Window + Hash Set. Same logic as Longest Substring Without Repeating.

---

## 🟢 Problem B: Find All Anagrams in a String (LC 438)
**Score:** 1000
**Time Limit:** 1.5s
**Statement:** Given two strings `s` and `p`, return an array of all the start indices of `p`'s anagrams in `s`. You may return the answer in any order.
**Constraints:**
- `1 <= s.length, p.length <= 3 * 10^4`
- `s` and `p` consist of lowercase English letters.
**Example:** `s = "cbaebabacd", p = "abc"` $\rightarrow$ `[0, 6]`
**Hidden Trick:** Fixed sliding window. State is a 26-char integer array. Match elements in `O(1)`.

---

## 🟡 Problem C: Subarray Sums Divisible by K (LC 974)
**Score:** 1500
**Time Limit:** 2.0s
**Statement:** Given an integer array `nums` and an integer `k`, return the number of non-empty subarrays that have a sum divisible by `k`.
**Constraints:**
- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `2 <= k <= 10^4`
**Example:** `nums = [4,5,0,-2,-3,1], k = 5` $\rightarrow$ `7`
**Hidden Trick:** Array contains negatives! Sliding window fails. Use Prefix Sum HashMap tracking remainder frequencies. Fix C++ modulo: `(x % k + k) % k`.

---

## 🟡 Problem D: Max Consecutive Ones III (LC 1004)
**Score:** 2000
**Time Limit:** 1.5s
**Statement:** Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`'s in the array if you can flip at most `k` `0`'s.
**Constraints:**
- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`
**Example:** `nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2` $\rightarrow$ `6`
**Hidden Trick:** Find longest subarray with strictly $\leq k$ zeros. Variable Window!

---

## 🔴 Problem E: Make Sum Divisible by P (LC 1590)
**Score:** 2500
**Time Limit:** 2.0s
**Statement:** Given an array of positive integers `nums`, remove the **shortest** subarray (can be empty) such that the sum of the remaining elements is divisible by `p`. It is not allowed to remove the whole array.
**Constraints:**
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= p <= 10^9`
**Example:** `nums = [3,1,4,2], p = 6` $\rightarrow$ `1` (Remove `4`. Total sum is 10. `10 % 6 = 4`. We must remove a subarray that modulos to 4).
**Hidden Trick:** Shortest Subarray Sum tracking. Store `map[mod] = Index`. Find `needed_mod = (current_mod - rem_to_remove + p) % p`.

---

## 🔴 Problem F: Subarrays with K Different Integers (LC 992)
**Score:** 3000
**Time Limit:** 2.5s
**Statement:** Given an integer array `nums` and an integer `k`, return the number of good subarrays of `nums`. A good array is an array where the number of different integers in that array is exactly `k`.
**Constraints:**
- `1 <= nums.length <= 2 * 10^4`
- `1 <= nums[i] <= nums.length`
- `1 <= k <= nums.length`
**Example:** `nums = [1,2,1,2,3], k = 2` $\rightarrow$ `7`
**Hidden Trick:** Exact logic. Implement a helper variable sliding window that finds `AtMost(K)` elements. Return `AtMost(K) - AtMost(K - 1)`.

---

### Contest Protocol:
1. Try A, B, C first. These are pure implementations of Day 1, 2, and 5.
2. D is the transition problem.
3. E and F require you to perfectly identify the algebraic inversions of the patterns.
4. Total Time Target: **2 Hours**.
