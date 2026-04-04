# Day 6: Array Edge Cases & Optimizations — Study Checklist

## Block 1: Edge Case Theory (3h)
- [ ] Read all edge case types in `concepts.md` Section 1 (empty, single, overflow, negatives, circular, boundary).
- [ ] Self-test: for each edge case type, write a 2-line example that would break a naive solution.
- [ ] Read all pitfalls (Section 1.2): off-by-one, index OOB, overflow, wrong assumptions.
- [ ] Verify: can you catch all 4 pitfall types in a code review?

## Block 2: Optimization Techniques (4h)
- [ ] Master Prefix Sum — derive `sum(l,r) = prefix[r+1] - prefix[l]` from first principles.
- [ ] Build prefix sum for `A = [3,-1,4,1,-5,9,2]` by hand. Verify 3 queries.
- [ ] Master Sliding Window (fixed) — code `max sum of exactly k elements` from scratch.
- [ ] Master Sliding Window (variable) — trace `longestSubarray(A=[2,3,1,2,4,3], k=7)` step by step.
- [ ] Master Two Pointers — solve `two sum in sorted array` without hash map.
- [ ] Master In-Place Write Pointer — implement `moveZeroes` from memory.
- [ ] Understand Difference Array — apply 3 range updates manually, reconstruct final array.

## Block 3: Pattern Recognition & Problem Solving (5h)
- [ ] Level 1 — Attempt Problems 1–4 before checking solutions.
    - [ ] P1: Range sum queries (prefix sum)
    - [ ] P2: Missing number (Gauss formula or XOR)
    - [ ] P3: Move zeros (write pointer)
    - [ ] P4: Sorted and rotated check (count drops)
- [ ] Level 2 — Attempt Problems 5–10 before checking solutions.
    - [ ] P5: Longest subarray sum ≤ k (sliding window)
    - [ ] P6: Count subarrays sum = k (prefix + map). Try sliding window first — confirm it fails.
    - [ ] P7: House Robber (O(1) DP)
    - [ ] P8: Min size subarray sum ≥ s (sliding window)
    - [ ] P9: Product except self (dual pass, no division)
    - [ ] P10: Trapping rain water (two pointers, O(1) space)
- [ ] Level 3 — Attempt Problems 11–15 before checking solutions.
    - [ ] P11: Max sum after k negations (sort by |abs|, greedy)
    - [ ] P12: Maximum width ramp (monotone stack + right sweep)
    - [ ] P13: Shortest subarray sum ≥ k with negatives (prefix + deque)
    - [ ] P14: Max score min×length (monotone stack, largest rect variant)
    - [ ] P15: Subarrays divisible by k (prefix mod + map, normalize negatives)

## Block 4: Edge Case Stress Testing & Review (2h)
- [ ] Compile and run `runTests()` in `solutions.cpp` — all must pass.
- [ ] Add 2 additional edge case tests per function for problems 5, 6, 10.
- [ ] Read Section 7 (Mistake Analysis) in `concepts.md` and identify which mistakes you made during solving.
- [ ] Memorize Section 8 (Revision Sheet) — key patterns, formulas, red flags.

## Block 5: Interview Drill (2h)
- [ ] Explain Problem 6 (subarray sum = k) — derive prefix+map from scratch, not from memory.
- [ ] Explain Problem 10 (rain water) — derive two-pointer from the O(n) space version.
- [ ] Timed: solve P8 (min size subarray) in under 10 minutes from scratch.
- [ ] Timed: solve P15 (divisible by k) in under 12 minutes from scratch.
