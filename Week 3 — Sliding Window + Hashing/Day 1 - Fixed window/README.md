# Day 1: Fixed Sliding Window

## Overview
Learn the foundational trick to avoiding nested loops for contiguous subarray queries. A fixed sliding window is used when the size of the subarray is strictly explicitly given as a constant `k`.

## Core Logic
1. Accumulate state for the first window of size `k` (indices 0 to `k-1`).
2. Loop starting from `k` up to `n-1`.
3. Add the incoming element `a[i]` to the state.
4. Remove the outgoing element `a[i-k]` from the state.
5. Capture optimal result during the slide.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Core sliding window state management triggers constraints and formulas |
| `problems.md` | 10 Problems starting from basic max-sum to monotonic deques. |
| `solutions.cpp` | Code for problems including Anagrams and Max Window. |
| `todo.md` | Your 14h learning schedule. |
| `index.html` | Interactive tracking. |
