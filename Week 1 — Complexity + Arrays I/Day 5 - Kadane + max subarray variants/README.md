# Day 5: Kadane's Algorithm + Maximum Subarray Variants

## Overview
This module covers **Kadane's Algorithm** — one of the most elegant dynamic programming algorithms in computer science, achieving an O(n) solution to the Maximum Subarray Problem, an improvement over O(n³) brute force. First derived by Jay Kadane in 1984 in under a minute at a seminar, it remains a foundational pattern in modern competitive programming and systems engineering.

## Files in this Module
| File | Purpose |
|---|---|
| `README.md` | This file — module overview |
| `concepts.md` | Deep theoretical breakdown of the algorithm and all its variants |
| `problems.md` | All challenge problems — categorized by difficulty |
| `solutions.cpp` | Full C++ reference implementations |
| `todo.md` | Your 14-hour interactive study checklist |
| `index.html` | Interactive visual dashboard with progress tracking |

## Topics Covered
- **Core Kadane's Algorithm** — O(n) DP with local/global max state tracking
- **Circular Subarray Variant** — Dual-case insight: linear max vs. `total - min`
- **Maximum Product Subarray** — Sign-flip volatility using min-max dual tracking
- **Subarray with One Deletion** — Left/right Kadane preprocessing + bridge logic
- **Maximum Absolute Sum** — Tracking both max and min Kadane states simultaneously
- **2D Maximum Sum Rectangle** — Row-reduction to 1D Kadane in O(C²R)
- **Segment Tree Range Maximum Subarray** — O(log n) per query with 4 augmented attributes

## How to Proceed
1. Open `index.html` in your live server for interactive progress tracking.
2. Study `concepts.md` for mathematical derivations and the DP recurrence relation.
3. Attempt problems in `problems.md` in order (progressively harder).
4. Compare with `solutions.cpp` for benchmarked reference implementations.
5. Check off tasks in `todo.md` and `index.html`.
