# Day 3: Frequency Maps — Checklist

## Block 1: Theory (2h)
- [ ] Read concepts.md closely.
- [ ] Understand why `int count[128] = {0}` is dramatically faster than `unordered_map<char, int>`.
- [ ] Memorize the palindrome rule: length += `(count / 2) * 2`. Max one odd.

## Block 2: Basics (3h)
- [ ] P1: Valid Anagram — Do this with a size-26 integer array.
- [ ] P5: Ransom Note — Same pattern but map drops below 0 condition.
- [ ] P6: First Unique Character — Two-pass pattern.

## Block 3: Hash Signatures & Groups (3h)
- [ ] P4: Group Anagrams — String sorting as a map key is `O(K log K)`. Group them efficiently.
- [ ] P7: Sort Characters By Frequency — Master bucket sort `vector<string> buckets(max_freq + 1)`. Reconstruct the string backward.

## Block 4: Math & Extrapolation (2h)
- [ ] P2: Find the Difference — Try the XOR trick. It uses `O(1)` space!
- [ ] P8: Max Number of Balloons — Finding the limiting character constraint. Treat `l` and `o` as divided by 2.

## Block 5: The LRU Boss Battle (4h)
- [ ] P9: LRU Cache — Setup the `list<pair<int,int>>` and `unordered_map` structure.
- [ ] Master `splice()`. It moves nodes in `O(1)` without reallocation.
- [ ] Compile solutions and ensure 0 memory leaks!
