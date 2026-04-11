# Day 4: Hashing Collisions & Tricks

## Overview
Go beneath the surface of `std::unordered_map`. Find out why Codeforces hackers can target standard map implementations and how to avoid `O(N)` TLEs. We will design standard maps from scratch via separate chaining, use bucketing instead of standard hashing for sliding window ranges, and learn to hash structs, fractions, and DNA sequences natively.

## Core Concepts
1. **Bucketing / Separate Chaining**: How hash collisions are formally handled and architected.
2. **Custom Hashing / Randomized Anti-Hash**: Adding a salt via `#include <chrono>` to outwit deterministic hacking.
3. **Geometrical / Fraction-Based Constraints**: Converting doubles (`slopes`, `division`) to reduced integer pairs to avoid `.000001` precision mismatches.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Separate Chaining, Rabin-Karp Hash, Tuple/Fraction Hashing |
| `problems.md` | 10 medium/hard architecture & logic problems |
| `solutions.cpp` | Clean implementations of `gcd()` fraction tracking and custom buckets |
| `todo.md` | Checklist block |
| `index.html` | Interactive tracking |
