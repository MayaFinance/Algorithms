# Day 4: Dutch National Flag & Partitioning

## Overview
Master in-place array partitioning. The Dutch National Flag algorithm (3-way partition) and Lomuto (2-way partition) are the backbone of QuickSort, QuickSelect, and many grouping problems.

## The Invariant (DNF)
```
[0 .. low-1]    = bottom group (e.g., 0s)
[low .. mid-1]  = middle group (e.g., 1s)
[mid .. high]   = UNEXPLORED
[high+1 .. n-1] = top group (e.g., 2s)
```
Loop: `while (mid <= high)`. If we swap with `high`, we bring an unexplored element to `mid`, so **do not increment mid**. If we swap with `low`, we bring a processed element, so we **do increment mid**.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | DNF vs Lomuto, pointer rules, stability, pitfalls |
| `problems.md` | 10 problems: Sort Colors, Move Zeros, Wiggle Sort, QuickSelect |
| `solutions.cpp` | Code for DNF and variants |
| `todo.md` | 14h Study Checklist |
| `index.html` | Interactive Dashboard |
