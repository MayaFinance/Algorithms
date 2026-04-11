# Day 6: Mixed Array Patterns — Study Checklist

## Block 1: Theory (2h)
- [ ] Read concepts.md. Understand why Boyer-Moore works intuitively.
- [ ] Contrast Bucket Sort Frequency vs Heap approach for Top K.
- [ ] Explain Sweep Line logic for intervals.

## Block 2: Overlapping Intervals (4h)
- [ ] P4: Merge Intervals — master `res.back()[1] = max(...)`.
- [ ] P5: Insert Interval — split logic into Before, Merge, After.
- [ ] P6: Meeting Rooms II — Sweep Line. Remember to process `-1` before `+1` if times tie!

## Block 3: Frequency & Bounded Arrays (3h)
- [ ] P3: Top K Frequent Elements — Bucket sort by frequency logic.
- [ ] P7: H-Index — Counting sort with a `n+1` array. Max elements > n fall to index n.

## Block 4: Math/Counting Tricks (3h)
- [ ] P1: Majority Element — Code Boyer-Moore voting blindly.
- [ ] P2: Majority Element II — Keep two counters. Second pass check.
- [ ] P10: Task Scheduler — Write the mathematical formula.

## Block 5: Consolidation (2h)
- [ ] What happens in Interval Merging if you don't use `max()` and just assign?
- [ ] Write event sorting logic for Sweep Line handling same-time collision manually.
- [ ] Compile solutions.cpp and trace outputs.
