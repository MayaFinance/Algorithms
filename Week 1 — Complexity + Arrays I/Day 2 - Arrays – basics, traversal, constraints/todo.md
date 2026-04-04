# Day 2 TODO Checklist

Structured sequential plan for mastering Arrays: basics, traversal, and constraints.

## Phase 1: Core Array Mechanics
- [ ] Read `concepts.md` sections on Static Arrays vs Heap Allocation.
- [ ] Understand the deterministic equation: `Address = Base + (Index * sizeof)`.
- [ ] Grasp why `std::vector` reallocation takes amortized $O(1)$ time. 
- [ ] Understand Cache Locality and the "Memory Wall" (Row-major vs Col-major traversal).

## Phase 2: Fundamental Problem Solving
- [ ] Open `problems.md` and read the Two-Pointer vs Hash Map tradeoffs for **Two Sum**.
- [ ] Understand the "Fast-Slow Pointer" approach for in-place modifications (**Remove Element**, **Move Zeroes**).
- [ ] Review the mathematical logic behind grid distances (**Beautiful Matrix**) and numeric manipulation (**Even Odds**).

## Phase 3: Advanced Pattern Logic
- [ ] Study the **Boyer-Moore Voting Algorithm**. Understand *why* the majority element always survives subtraction.
- [ ] Study **Prefix/Suffix Patterns**.
    - Mentally walk through how to calculate a **Pivot Index**.
    - Trace the two-pass logic for **Product of Array Except Self**.
- [ ] Learn the $XOR$ trick ($x \oplus x = 0$) for the **Missing Number** problem to avoid integer operations.

## Phase 4: Complex Partitioning & Merging
- [ ] Study the **Triple Reverse Trick** for rotating arrays in $O(1)$ space.
- [ ] Study the **Reverse Merge Trick** for combining sorted arrays from right to left.
- [ ] Map out the invariants of the **Dutch National Flag Algorithm** and learn how to partition an array into 3 sections in one pass.

## Phase 5: Code Implementation
- [ ] Open `solutions.cpp` and compile the file.
- [ ] Verify you understand the C++ syntax used to implement Two Pointers and Prefix Sums.
- [ ] Implement the `sortColors` function from scratch to test your memory of the Dutch National Flag pointers.

## Phase 6: Edge Case Defense Readiness
- [ ] Run through the 6 points on the Edge Case Checklist in `concepts.md`. Are you checking for $N=1$? Are you using `long long` for large accumulations?
