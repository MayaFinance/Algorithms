# Day 2: Variable Sliding Window

## Overview
While fixed windows rely on `size == k`, variable sliding windows find the optimal `size` according to a constraint. This powers some of the most frequent interview problems involving string manipulations and subarray sums.

## Core Logic
1. Expand the window by incrementing `right`.
2. Check if the newly expanded window violates your invariant.
3. If it does, `while (invalid)`, increment `left` to shrink it until it becomes valid again.
4. Capture the `shortest` length inside the inner `while` loop, and the `longest` length directly outside of it.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Universal Variable Window template. Exact Exact(k) = AtMost(k) - AtMost(k-1). |
| `problems.md` | 10 intensive variable window problems. |
| `solutions.cpp` | Code logic for sum constraint, character frequency constraints, and exact-k arrays. |
| `todo.md` | Checklist block. |
| `index.html` | Interactive tracking. |
