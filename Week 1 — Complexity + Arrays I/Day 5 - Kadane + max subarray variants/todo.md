# Day 5: Kadane's Algorithm — Study Checklist

## Block 1: Theory & Foundations (3h)
- [ ] Read the historical evolution of sequence optimization in `concepts.md`.
- [ ] Formally derive the recurrence: `f(i) = max(A[i], f(i-1) + A[i])`.
- [ ] Trace through the dry run on `A = [-2,1,-3,4,-1,2,1,-5,4]` manually.
- [ ] Code the standard Kadane (LeetCode 53) from memory.

## Block 2: Core Variants (4h)
- [ ] Solve Maximum Sum Circular Subarray (LC 918). Master the dual-case insight.
- [ ] Solve Maximum Product Subarray (LC 152). Track min AND max simultaneously.
- [ ] Solve Best Time to Buy and Sell Stock (LC 121). Recognize the Kadane pattern in disguise.
- [ ] Solve Maximum Subarray with One Deletion (LC 1186). Build left[] and right[] arrays.

## Block 3: Advanced Variants (4h)
- [ ] Solve Maximum Absolute Sum Subarray (LC 1749). Track both Kadane extremes in one pass.
- [ ] Solve Count Subarrays with Score < K (LC 2302). Combine Kadane reset with sliding window.
- [ ] Solve Maximum Sum Rectangle (2D Kadane).
    - [ ] Understand the row-compression reduction to 1D.
    - [ ] Run Kadane on each compressed column pair.
- [ ] Contrast Subarray Sum Equals K (LC 560) — recognize when Kadane does NOT apply (Prefix + HashMap instead).

## Block 4: Segment Tree Extension (3h)
- [ ] Understand how to augment segment tree nodes with 4 fields: `total`, `max_prefix`, `max_suffix`, `max_sub`.
- [ ] Derive the merge logic for two child nodes.
- [ ] Understand the practical use case: real-time range queries in high-frequency systems.
