# Day 2: Variable Sliding Window — Problem Set

---

## Problem 1: Minimum Size Subarray Sum ⭐ Medium (LC 209)
**Statement:** Array of positive integers `nums` and positive `target`. Find minimum length of a contiguous subarray of which the sum `>= target`. If none, 0.
**Example:** `target = 7, nums = [2,3,1,2,4,3]` → `2` (`[4,3]`)
**Pattern:** Shortest window. Shrink `while (sum >= target)` and capture `min` inside the inner loop.

---

## Problem 2: Longest Substring Without Repeating Characters ⭐⭐ Medium (LC 3)
**Statement:** Find length of longest substring without repeating characters.
**Example:** `"abcabcbb"` → `3` (`"abc"`)
**Pattern:** Longest window. State is `unordered_set` or boolean array. `while (set.contains(s[right])) set.erase(s[left++])`.

---

## Problem 3: Max Consecutive Ones III ⭐⭐ Medium (LC 1004)
**Statement:** Binary array `nums`, integer `k`. Find max number of consecutive `1`s if you can flip at most `k` `0`s.
**Example:** `nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2` → `6`
**Pattern:** Longest window. Read as: "Longest subarray with AT MOST K zeros". State = zero_count. `while (zeros > k) left++`.

---

## Problem 4: Longest Repeating Character Replacement ⭐⭐ Medium (LC 424)
**Statement:** String `s` and integer `k`. You can change any character in string to any other uppercase English character at most `k` times. Longest repeating string possible?
**Example:** `s = "AABABBA", k = 1` → `4`
**Pattern:** Window length - count of most frequent char <= `k`. If invalid, shrink. (Optimization: we don't need to decrement `max_freq` strictly on shrink).

---

## Problem 5: Fruit Into Baskets ⭐⭐ Medium (LC 904)
**Statement:** Array of integers (types of fruit). You have 2 baskets. Each basket holds exactly one type of fruit. Longest subarray of fruits you can pick?
**Example:** `fruits = [1,2,3,2,2]` → `4` (`[2,3,2,2]`)
**Pattern:** Longest window with AT MOST 2 distinct elements. State = Hash Map tracking fruit type frequency.

---

## Problem 6: Longest Subarray of 1's After Deleting One Element ⭐ Medium (LC 1493)
**Statement:** Binary array `nums`. You must delete exactly one element. Longest subarray of `1`s?
**Example:** `nums = [1,1,0,1]` → `3`
**Pattern:** Identical to Max Consecutive Ones III with `k=1`. Result is `max_len - 1` because you MUST delete exactly one.

---

## Problem 7: Minimum Operations to Reduce X to Zero ⭐⭐⭐ Medium (LC 1658)
**Statement:** Array `nums`. You can remove elements from either the extreme left or extreme right. Min operations to reduce `x` to `0`?
**Example:** `nums = [1,1,4,2,3], x = 5` → `2` (`[2,3]` from right)
**Pattern:** "Two ends" equals "Find longest subarray in middle summing to `Total_Sum - X`". Inverse the problem! Then apply P1 pattern.

---

## Problem 8: Subarrays with K Different Integers ⭐⭐⭐ Hard (LC 992)
**Statement:** Integer array `nums`. Return number of good subarrays (exactly `k` different integers).
**Example:** `nums = [1,2,1,2,3], k = 2` → `7`
**Pattern:** `AtMost(K) - AtMost(K-1)`. Compute passing sliding window twice.

---

## Problem 9: Get Equal Substrings Within Budget ⭐⭐ Medium (LC 1208)
**Statement:** Two strings `s` and `t` of same length. Cost to change `s[i]` to `t[i]` is `abs(s[i] - t[i])`. Max length of substring you can change under `maxCost`?
**Example:** `s = "abcd", t = "bcdf", maxCost = 3` → `3`
**Pattern:** Treat as integer array of costs diffs. Find longest subarray with sum `<= maxCost`.

---

## Problem 10: Count Number of Nice Subarrays ⭐⭐ Medium (LC 1248)
**Statement:** Array `nums`, integer `k`. A subarray is "nice" if there are exactly `k` odd numbers on it. Return count.
**Example:** `nums = [1,1,2,1,1], k = 3` → `2`
**Pattern:** Replace evens with 0, odds with 1. Problem becomes: "Number of subarrays with exactly sum K". `Exact(K) = AtMost(K) - AtMost(K-1)`.
