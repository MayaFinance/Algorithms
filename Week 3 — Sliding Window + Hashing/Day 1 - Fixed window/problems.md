# Day 1: Fixed Sliding Window — Problem Set

---

## Problem 1: Maximum Average Subarray I ⭐ Easy (LC 643)
**Statement:** Array of `n` integers. Find contiguous subarray of length `k` that has max average value, and return this value.
**Example:** `nums = [1,12,-5,-6,50,3], k = 4` → `12.75000` (from `[12,-5,-6,50]`)
**Pattern:** Pure fixed-window. Track max sum, then return `max_sum / (double)k`.

---

## Problem 2: Diet Plan Performance ⭐ Easy (LC 1176)
**Statement:** Array of `calories`, `k` (days). For every rolling `k` days, if sum `< lower`, lose 1 point. If `sum > upper`, gain 1 point. Return total points.
**Example:** `calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3` → `0`
**Pattern:** Fixed window sum. Apply the scoring logic on the first window, then on every subsequent window after sliding.

---

## Problem 3: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold ⭐⭐ Medium (LC 1343)
**Statement:** Given integer array `arr` and integers `k` and `threshold`. Return number of sub-arrays of size `k` with average >= `threshold`.
**Example:** `arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4` → `3`
**Pattern:** Mathematical optimization. Multiply threshold by `k` to avoid floats: check if `window_sum >= threshold * k`.

---

## Problem 4: Maximum Vowels in a Substring of Given Length ⭐⭐ Medium (LC 1456)
**Statement:** Given string `s` and length `k`, return max number of vowel letters in any substring of length `k`.
**Example:** `s = "abciiidef", k = 3` → `3`
**Pattern:** State is an integer. Incoming char: `if isVowel(s[i]) count++`. Outgoing char: `if isVowel(s[i-k]) count--`.

---

## Problem 5: Find All Anagrams in a String ⭐⭐ Medium (LC 438)
**Statement:** Given strings `s` and `p`, return array of all start indices of `p`'s anagrams in `s`.
**Example:** `s = "cbaebabacd", p = "abc"` → `[0, 6]`
**Pattern:** Sliding window with Hash Map / Frequency Array. Size of window is exactly `p.length()`. State is a 26-char frequency array for current window. Compare it with `p`'s frequency array.

---

## Problem 6: Permutation in String ⭐⭐ Medium (LC 567)
**Statement:** Given `s1` and `s2`, return true if `s2` contains a permutation of `s1`.
**Example:** `s1 = "ab", s2 = "eidbaooo"` → `true`
**Pattern:** Exact same logic as P5. Stop early if hash arrays match.

---

## Problem 7: First Negative Integer in Every Window of Size K ⭐⭐ Medium (GeeksforGeeks)
**Statement:** Array of integers. For every window of size `k`, print first negative integer. If none, print 0.
**Example:** `a=[-8, 2, 3, -6, 10], k=2` → `[-8, 0, -6, -6]`
**Pattern:** State management with a Queue. Store INDICES of negative numbers. When rolling window, remove indices that fall out of `i-k`.

---

## Problem 8: Contains Duplicate II ⭐ Easy (LC 219)
**Statement:** Array `nums` and integer `k`. Are there two distinct indices `i` and `j` such that `nums[i] == nums[j]` and `abs(i - j) <= k`?
**Example:** `nums = [1,2,3,1], k = 3` → `true`
**Pattern:** Fixed window of size `k+1`. Keep a HashSet. When sliding, `set.insert(nums[i])` and `set.erase(nums[i-k-1])`. If insert fails (already exists), return true.

---

## Problem 9: Sliding Window Maximum ⭐⭐⭐ Hard (LC 239)
**Statement:** Array `nums`, sliding window of size `k`. Return the max sliding window array. Must be O(N).
**Example:** `nums = [1,3,-1,-3,5,3,6,7], k = 3` → `[3,3,5,5,6,7]`
**Pattern:** Monotonic Deque. Store indices. Remove smaller elements from back when adding new. Remove elements from front if they drop out of `i-k`.

---

## Problem 10: Defuse the Bomb ⭐ Easy (LC 1652)
**Statement:** Array of `n` elements (circular). If `k>0`, replace `i` with sum of next `k` elements. If `k<0`, sum of previous `k` elements. If `k=0`, replace with 0.
**Pattern:** Circular fixed window. Duplicate array `a` to `a + a` to handle wrapping, then use standing fixed sliding window sum.
