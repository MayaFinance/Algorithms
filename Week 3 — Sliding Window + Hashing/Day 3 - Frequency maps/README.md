# Day 3: Frequency Maps

## Overview
Frequency Mapping is the cornerstone of hash-based problems. It teaches you how to maintain the counts of elements and query them in O(1) time. Knowing when to use an array of size 26/128/256 vs `std::unordered_map` is an essential optimization.

## Core Concepts
1. **Array-based Hashing**: `count[ch - 'a']++` for localized domains.
2. **Anagram Signatures**: Group strings by sorting them or using a 26-digit frequency hash.
3. **Bucket Sorting**: Re-arranging strings based on counts using `vector<vector<char>> buckets`.
4. **Cache Architecture**: The combination of `std::unordered_map` with `std::list` (doubly-linked list) to govern insertion, lookup, and deletion all in `O(1)` time.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Hashing fundamentals and data structures |
| `problems.md` | 10 frequency map & caching problems |
| `solutions.cpp` | Code solutions for all map interactions |
| `todo.md` | Checklist block. |
| `index.html` | Dashboard. |
