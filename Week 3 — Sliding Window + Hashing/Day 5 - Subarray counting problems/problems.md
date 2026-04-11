# Day 5: Subarray Counting Problems — Problem Set

---

## Problem 1: Subarray Sum Equals K ⭐⭐ Medium (LC 560)
**Statement:** Array of integers, find total number of continuous subarrays whose sum equals to `k`. Can contain negatives.
**Example:** `nums = [1,-1,0], k = 0` → `3` (`[1,-1]`, `[0]`, `[1,-1,0]`)
**Pattern:** Core Prefix Sum + Hash Map template. `ans += map[sum - k]`.

---

## Problem 2: Contiguous Array ⭐⭐ Medium (LC 525)
**Statement:** Binary array. Find MAX LENGTH of contiguous subarray with equal number of 0s and 1s.
**Example:** `nums = [0,1,0]` → `2`
**Pattern:** Treat 0s as -1. Target sum is 0. Store `map[sum] = index`. If we see `sum` again, length is `i - map[sum]`. (Initialize `map[0] = -1`).

---

## Problem 3: Subarray Sums Divisible by K ⭐⭐ Medium (LC 974)
**Statement:** Array of integers. Return number of non-empty subarrays that have sum divisible by `k`.
**Example:** `nums = [4,5,0,-2,-3,1], k = 5` → `7`
**Pattern:** Math/Modulo. Track `rem = (sum % k + k) % k`. `ans += map[rem]`.

---

## Problem 4: Make Sum Divisible by P ⭐⭐ Medium (LC 1590)
**Statement:** Subarray of positive integers. We want to remove the SHORTEST subarray (can be empty) such that the sum of the remaining elements is divisible by `p`.
**Example:** `nums = [3,1,4,2], p = 6` → `1` (Remove `4`)
**Pattern:** Target remainder to remove `rem = total_sum % p`. Find shortest subarray with mod equal to `rem`. Map tracks latest index seen. Formula: `(current_mod - rem + p) % p`.

---

## Problem 5: Continuos Subarray Sum ⭐⭐ Medium (LC 523)
**Statement:** Array of non-negative integers. Return true if there is a subarray of size at least 2 whose sum is a multiple of `k`.
**Example:** `nums = [23,2,6,4,7], k = 6` → `true`
**Pattern:** Store earliest index of each modulo. If we see a modulo again, check if `i - map[mod] >= 2`.

---

## Problem 6: Maximum Size Subarray Sum Equals k ⭐⭐ Medium (LC 325)
**Statement:** Array of integers, find maximum length of subarray that sums to `k`.
**Example:** `nums = [1,-1,5,-2,3], k = 3` → `4`
**Pattern:** Same as P2, but target is `sum - k`. Store FIRST index where a prefix sum occurs.

---

## Problem 7: Path Sum III ⭐⭐ Medium (LC 437) (Tree Variant)
**Statement:** Given root of binary tree, number of paths where sum of node values equals `targetSum`. Paths must go downwards.
**Pattern:** Prefix sum map passed through DFS! Add node to map on way down, remove it on backtrack. Applies array prefix map to tree topologies.

---

## Problem 8: Count Number of Bad Pairs ⭐⭐ Medium (LC 2364)
**Statement:** A pair `(i, j)` is bad if `j - i != nums[j] - nums[i]`. Find number of bad pairs.
**Example:** `nums = [4,1,3,3]` → `5`
**Pattern:** Algebraic rearrangement: `nums[j] - j != nums[i] - i`. Map the differences! Total pairs `n*(n-1)/2` minus number of good pairs (where differences match).

---

## Problem 9: Number of Subarrays With Odd Sum ⭐⭐ Medium (LC 1524)
**Statement:** Given array, return number of subarrays with an odd sum. Return mod 10^9 + 7.
**Example:** `nums = [1,3,5]` → `4`
**Pattern:** Math/Prefix Parity. Maintain counts of odd prefixes and even prefixes. If current sum is odd, it forms an odd subarray with all previous EVEN prefixes.

---

## Problem 10: Number of Excellent Pairs ⭐⭐⭐ Hard (Hashing + Bitmasking) (LC 2354)
**Statement:** Given `nums` and `k`. Find number of pairs where sum of set bits in `(num1 OR num2)` + `(num1 AND num2)` >= `k`.
**Pattern:** Set Theory magic: `bits(a & b) + bits(a | b)` is strictly equal to `bits(a) + bits(b)`. Problem reduces to: count frequencies of set bit counts, then return pairs where bit sum >= k.
