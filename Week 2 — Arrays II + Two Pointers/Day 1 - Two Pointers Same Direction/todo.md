# Day 1: Two Pointers (Same Direction) — Study Checklist

## Block 1: Core Theory (2h)
- [ ] Read all sections of `concepts.md`.
- [ ] Write the fast/slow template from memory (no peeking).
- [ ] List all 6 "When to use" triggers from memory.
- [ ] Identify 3 differences between sliding window and write-pointer two pointers.

## Block 2: Easy Problems (2h)
- [ ] P1: Remove Element — code from scratch, test on [3,2,2,3] val=3 and [].
- [ ] P2: Remove Duplicates I — code the key line: compare fast to arr[slow-1].
- [ ] P3: Remove Duplicates II — code the key line: compare fast to arr[slow-2].
- [ ] P4: Move Zeros — two-pass version; try to do it in one pass.

## Block 3: Medium Problems (4h)
- [ ] P5: Squares of Sorted Array — use two-end pointers, fill from back.
- [ ] P6: Floyd's Cycle Detection — trace Phase 1 and Phase 2 manually.
- [ ] P7: Longest Substring No Repeat — sliding window with last-seen map.
- [ ] P8: Min Size Subarray Sum — sliding window, shrink on condition.
- [ ] P9: Merge Sorted Array — fill from back, why this avoids overwrite.

## Block 4: Hard Problems (4h)
- [ ] P10: Count Pairs < K — opposite-direction on sorted array, count += r-l.
- [ ] P11: Subarray Product < K — sliding window with product; edge: k≤1.
- [ ] P12: Max Consecutive Ones III — track zero count in window.

## Block 5: Consolidation (2h)
- [ ] Answer all 5 quiz questions without looking at solutions.
- [ ] Compile and run solutions.cpp — verify all outputs.
- [ ] For each problem, state its complexity in one sentence.
- [ ] Write down 3 mistakes from today's session and how to avoid them.
