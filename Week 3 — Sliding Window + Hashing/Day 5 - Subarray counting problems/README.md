# Day 5: Subarray Counting Problems

## Overview
What happens when standard Sliding Window fails because your array has negative numbers or non-monotonic properties? You transition to the **Prefix Sum + Hash Map** pattern. This is arguably the most frequently asked "trick" in medium/hard interviews.

## Core Concepts
1. **The Core Formula**: `PrefixSum(i) - K = Target` in map.
2. **The Base Case Requirement**: Always initialize `map[0] = 1` for sum counting, or `map[0] = -1` for maximum lengths.
3. **Divisibility Modulos**: `PrefixSum(i) % K == PrefixSum(j-1) % K`. Handling `+K` mathematically in C++ for negative modulos.
4. **Algebraic Re-organization**: Rearranging pairs `A[i] - i == A[j] - j`.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Core logic for mapping prefix bounds |
| `problems.md` | 10 classic prefix map problems |
| `solutions.cpp` | C++ implementations of modulo math mapping |
| `todo.md` | Your 14h learning schedule. |
| `index.html` | Interactive tracking. |
