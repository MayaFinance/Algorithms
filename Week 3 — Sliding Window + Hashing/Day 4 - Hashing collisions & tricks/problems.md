# Day 4: Hashing Collisions & Tricks — Problem Set

---

## Problem 1: Design HashMap ⭐ Easy (LC 706)
**Statement:** Design a HashMap without using any built-in hash table libraries.
**Example:** `put(1, 1), put(2, 2), get(1) -> 1`
**Pattern:** Implement Separate Chaining using an array of `std::list` (or vectors). Modulo bucket count.

---

## Problem 2: Encode and Decode TinyURL ⭐⭐ Medium (LC 535)
**Statement:** Design a service to encode a URL to a TinyURL and decode back.
**Example:** `https://leetcode.com/problems/design-tinyurl` -> `http://tinyurl.com/4e9iAk`
**Pattern:** Math/Hash generation. Generate a random 6-character alphanumeric string. Store mapping in two HashMaps `(long->short)` and `(short->long)` to handle collisions.

---

## Problem 3: Repeated DNA Sequences ⭐⭐ Medium (LC 187)
**Statement:** DNA sequences are A, C, G, T. Return all 10-letter-long sequences that occur more than once in a DNA molecule.
**Example:** `"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"` -> `["AAAAACCCCC","CCCCCAAAAA"]`
**Pattern:** Sliding Window + HashMap. (Advanced: Represent 10 characters as a 20-bit integer since there are only 4 characters `(A=00, C=01, G=10, T=11)`. This avoids string slicing overhead).

---

## Problem 4: Longest Duplicate Substring ⭐⭐⭐ Hard (LC 1044)
**Statement:** Find the longest substring that occurs at least twice in the string.
**Example:** `"banana"` -> `"ana"`
**Pattern:** Binary Search on the length of the substring + Rabin-Karp Rolling Hash. Map the hash of the sliding window to a set to find duplicates in `O(N)`.

---

## Problem 5: Contains Duplicate III ⭐⭐⭐ Hard (LC 220)
**Statement:** Array `nums`, integers `k`, `t`. Find if `abs(nums[i] - nums[j]) <= t` and `abs(i - j) <= k`.
**Example:** `nums = [1,2,3,1], k = 3, t = 0` -> `true`
**Pattern:** Bucketing! Instead of searching the whole window, divide numbers into buckets of size `t+1`. If a number maps to a bucket that already has an item, return true! Also check adjacent buckets.

---

## Problem 6: Brick Wall ⭐⭐ Medium (LC 554)
**Statement:** A brick wall is `n` rows. Find the vertical line that crosses the LEAST number of bricks.
**Example:** `[[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]` -> `2`
**Pattern:** We don't count bricks we cross, we count EDGES. Use a Hash Map to track the frequency of edge positions (`x` coordinates). The line with max edges = least bricks crossed (`Total rows - max edges`).

---

## Problem 7: Fractional Recurring Decimal ⭐⭐ Medium (LC 166)
**Statement:** Given numerator and denominator, return fractional part in string format. If repeating, enclose in parentheses.
**Example:** `numerator = 4, denominator = 333` -> `"0.(012)"`
**Pattern:** Hash Map mapping the *remainder* to its length index in the result string. When you see a remainder you've seen before, the sequence repeats.

---

## Problem 8: Maximum Number of Points on a Line ⭐⭐⭐ Hard (LC 149)
**Statement:** Return max number of points that lie on the same straight line.
**Example:** `[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]` -> `4`
**Pattern:** Hash map counting slopes. A slope is a double, but doubles cause precision errors. Store slope as a reduced fraction pair `(dy/gcd, dx/gcd)` in a custom hash map.

---

## Problem 9: Number of Boomerangs ⭐⭐ Medium (LC 447)
**Statement:** Find number of tuples `(i, j, k)` such that distance `i-j` equals distance `i-k`.
**Example:** `[[0,0],[1,0],[2,0]]` -> `2`
**Pattern:** For each point `i`, create a frequency map of distances to all other points. If `m` points have the same distance, they can form `m * (m - 1)` boomerangs.

---

## Problem 10: Find Duplicate Subtrees ⭐⭐ Medium (LC 652) (Trees + Hashing)
**Statement:** Given the root of a binary tree, return all duplicate subtrees.
**Pattern:** Tree serialization + Hashing. Serialize the tree to a string (e.g. `(Root_val, Left_serialize, Right_serialize)`). Store in map to find duplicates.
