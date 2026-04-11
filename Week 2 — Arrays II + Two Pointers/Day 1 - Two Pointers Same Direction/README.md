# Day 1: Two Pointers (Same Direction)

## Overview
Master the **fast/slow pointer** paradigm — the foundation of all in-place array operations. Both pointers move right only, achieving O(n) where naive approaches need O(n²).

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Full theory: what, why, when, how + Floyd's cycle + revision sheet |
| `problems.md` | 12 progressive problems + 5-question quiz |
| `solutions.cpp` | All 12 solutions with dry runs, complexity, Python + quiz answers |
| `todo.md` | 14h study checklist |
| `index.html` | Interactive dashboard |

## Topics Covered
- Fast/slow (read/write) pointer template
- Remove elements, filter in-place
- Deduplicate sorted arrays (1 copy, 2 copies)
- Move zeros
- Squares of sorted array
- Floyd's cycle detection (find duplicate)
- Sliding window: longest unique substring, min size subarray, product < k, max ones with k flips
- Merge sorted arrays in-place

## Key Insight
> Fast moves unconditionally. Slow moves only when a condition is met. Together they achieve O(n) by ensuring each element is touched exactly once.
