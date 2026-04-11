# Day 6: Pattern Revision & Synthesis — Problem Set

*Today combines mixed problems to force you to actively identify the pattern rather than blindly applying the single theme of the day.*

---

## Problem 1: Maximum Erasure Value ⭐⭐ Medium (LC 1695)
**Statement:** Array of positive integers. You want to erase a subarray containing unique elements such that the sum of the subarray is maximized.
**Pattern Test:** Is this sliding window or prefix sum? It has positive integers and asks for max condition. It's Variable Window + Hash Set.

---

## Problem 2: Find All Anagrams in a String ⭐⭐ Medium (LC 438)
**Statement:** Repeat problem from Day 1 without checking notes.
**Pattern Test:** Fixed size string match. Fixed Sliding window with flat frequency array `vector<int>(26)`.

---

## Problem 3: Continuous Subarray Sum ⭐⭐ Medium (LC 523)
**Statement:** Repeat problem from Day 5 exactly without checking notes. Size $\geq$ 2, multiple of `k`.
**Pattern Test:** Target modulo logic + Subarray length. Prefix Hash Map storing index.

---

## Problem 4: Grumpy Bookstore Owner ⭐⭐ Medium (LC 1052)
**Statement:** Array of `customers`, array of `grumpy` (0 or 1), integer `minutes`. You can use a secret technique to make owner not grumpy for `minutes` consecutive minutes. Maximize satisfied customers.
**Pattern Test:** "Consecutive minutes" -> Fixed Sliding Window. Calculate base satisfied customers, then map a window of size `minutes` over grumpy spots to find max gain.

---

## Problem 5: Sliding Window Maximum ⭐⭐⭐ Hard (LC 239)
**Statement:** Try to write the Monotonic Deque from memory entirely.
**Pattern Test:** Fixed Sliding window + `deque<int>`. Pop smaller from back. Pop old from front.

---

## Problem 6: Maximum Points You Can Obtain from Cards ⭐⭐ Medium (LC 1423)
**Statement:** Array of cards. You can take exactly `k` cards from the beginning or the end. Maximize score.
**Pattern Test:** Taking from extremes. Inverse Window trick! Find the MINIMUM subarray in the middle of size `N - k`.

---

## Problem 7: Minimum Window Substring ⭐⭐⭐ Hard (LC 76)
**Statement:** Given string `s` and `t`, return minimum window substring of `s` such that every char in `t` is included.
**Pattern Test:** Variable window. Expand until all counts met. Shrink while all counts met to minimize. Two frequency arrays or one frequency array counting drops/satisfactions.

---

## Problem 8: Count Vowel Substrings of a String ⭐ Easy (LC 2062)
**Statement:** Find number of substrings that consist ENTIRELY of all 5 vowels ('a','e','i','o','u').
**Pattern Test:** Count subarrays exactly? Mathematically: `AtMost(5 vowels) - AtMost(4 vowels)` using pure variables sliding windows.

---

## Problem 9: Subarray Sum Equals K ⭐⭐ Medium (LC 560)
**Statement:** Rewrite it completely from memory in 3 minutes.
**Pattern Test:** Prefix Sum + Hash Map seeded with `map[0] = 1`.

---

## Problem 10: Longest Nice Subarray ⭐⭐ Medium (LC 2401)
**Statement:** Array `nums`. Subarray is "nice" if `bitwise AND` of every pair of elements is `0`. Longest length?
**Pattern Test:** Variable sliding window! Since AND must be 0, bits cannot overlap. Keep a running `OR` state. If `window_state & nums[right]` is not zero, shrink until it is 0.
