# Day 5: Array Rotation & Rearrangement

## Overview
How to maneuver elements globally across an array or matrix in-place. We cover the Triple Reversal method for rotation, the Multiplication/Addition modulo encoding hack for in-place data mapping, and matrix traversal/modification without extra space. Additionally, this module solidifies Binary Search on rotated arrays.

## Core Techniques
1. **Triple Reversal**: Reverse all, reverse part 1, reverse part 2.
2. **Modulo Encoding**: Storage trick: `A[i] = A[i] + (NewValue % M) * M`. Read old via `% M`, read new via `/ M`.
3. **2D Matrix Manipulation**: Transpose + reverse for 90-degree rotations. Shrinking boundaries for spiral. First row/col marking for propagating 0s.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Rotation math, reverse technique, Modulo encoding hack, matrix rotation math. |
| `problems.md` | 10 problems spanning 1D/2D arrays and search in rotated arrays. |
| `solutions.cpp` | Code implementations using in-place methods. |
| `todo.md` | Study Checklist. |
| `index.html` | Dashboard tracking. |
