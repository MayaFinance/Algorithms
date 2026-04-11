# Day 1: Fixed Sliding Window — Checklist

## Block 1: Theory (2h)
- [ ] Read concepts.md closely.
- [ ] Memorize the exact indices for adding and removing (`i` and `i-k`).
- [ ] Understand why maximum tests should start `max_sum` at `-infinity` or the first window sum.

## Block 2: Essential Operations (2h)
- [ ] P1: Maximum Average Subarray — Implement from scratch without looking at code.
- [ ] P2: Diet Plan — Write out the scoring sequence.
- [ ] P3: Threshold Average — Avoid division by multiplying the threshold by `k`.

## Block 3: State using Strings & Maps (4h)
- [ ] P4: Max Vowels — State is a single integer.
- [ ] P5: Find All Anagrams — State is an array `count[26]`. Use `std::vector` equality `pCount == sCount`.
- [ ] P6: Permutation in String — Stop immediately when equality is met.

## Block 4: State using Queues (Deque) (4h)
- [ ] P7: First Negative — Use a standard `deque` to store indices of negatives. Pop from front if old.
- [ ] P9: Sliding Window Maximum — Master the Monotonic Deque. Always pop smaller elements from the back before adding `i`.
- [ ] Trace `nums=[1,3,-1,-3,5,3,6,7], k=3` entirely on paper using the Monotonic Deque.

## Block 5: Consolidation (2h)
- [ ] P10: Defuse the Bomb — Circular Arrays. Make the array `2N` to simulate wrapping.
- [ ] Run `solutions.cpp` and implement all checks.
