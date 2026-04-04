# Day 6: Array Edge Cases & Optimizations — README

## Overview
This module covers the **foundations of correctness and efficiency** in array programming. Before applying advanced algorithms, every competitive programmer must master: what can go wrong (edge cases), why naive solutions fail (pitfalls), and how to systematically optimize (O(n²) → O(n)).

This is the bridge between "it works on the sample" and "it passes all test cases."

## Files in this Module
| File | Purpose |
|---|---|
| `README.md` | This file — module overview |
| `concepts.md` | Full 8-section deep theory: edge cases, pitfalls, optimization techniques, patterns, interview simulation, stress testing, mistake analysis, revision sheet |
| `problems.md` | 15 problems across 3 difficulty levels |
| `solutions.cpp` | Optimal C++ implementations + Python (in comments) with inline edge case tests |
| `todo.md` | 16-hour interactive study checklist |
| `index.html` | Interactive visual dashboard with progress tracking |

## Topics Covered
- **Array Edge Cases** — Empty, single, all-same, overflow, negatives, duplicates, circular, boundary indices
- **Common Pitfalls** — Off-by-one, index out of bounds, integer overflow, wrong assumptions
- **Optimization Techniques** — Prefix sum, suffix sum, difference array, sliding window (fixed & variable), two pointers, in-place modification, precomputation, bit manipulation
- **Pattern Recognition** — 7 key patterns with triggers, key ideas, and traps
- **Interview Simulation** — Brute force → insight → optimization pathway for core problems

## Complexity Reference
| Technique | Time | Space |
|---|---|---|
| Prefix sum (build) | O(n) | O(n) |
| Prefix sum (query) | O(1) | — |
| Sliding window | O(n) | O(1) |
| Two pointers | O(n) | O(1) |
| Difference array | O(n) | O(n) |
| Monotone stack | O(n) | O(n) |

## How to Proceed
1. Open `index.html` in your browser (Live Server) for interactive progress tracking.
2. Study `concepts.md` sections 1–3 for theory and pattern recognition.
3. Attempt each problem in `problems.md` before opening solutions.
4. Compare with `solutions.cpp` for reference implementations.
5. Run the inline `runTests()` in `solutions.cpp` to verify edge cases.
6. Check off tasks in `todo.md` and `index.html`.
