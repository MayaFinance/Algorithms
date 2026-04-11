# Day 6: Mixed Array Patterns

## Overview
This module isolates high-frequency array templates that aren't strictly two-pointers or sliding windows. These patterns frequently appear in interviews because they are clever invariants or optimizations over naive sorting or hashing.

## Essential Patterns
1. **Boyer-Moore Voting**: Find the majority element (> n/2) in `O(N)` time and `O(1)` space using cancellations.
2. **Bucket Sort (Frequency)**: Find Top K frequent elements in `O(N)` instead of `O(N log K)` by capping the max frequency bounded by array length.
3. **Sweep Line Algorithm**: Deal with overlaps across multiple intervals easily. Start = +1, End = -1, prefix sum it.
4. **Interval Operations**: Merging logic via sorting by start time.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Core theory for majority, bucket, intervals, line sweep, and 2D matrix sum tricks. |
| `problems.md` | 10 classic problems. |
| `solutions.cpp` | Code implementations using in-place methods where possible. |
| `todo.md` | Study Checklist. |
| `index.html` | Dashboard tracking. |
