# Day 3 TODO Checklist

Structured sequential plan for mastering Prefix Sums and their associated architectures.

## Phase 1: Core Cumulative Mathematics
- [ ] Read `concepts.md` sections on The Mathematical Paradigm.
- [ ] Memorize the Range Query Formula using Inclusion-Exclusion: $Sum(L, R) = P[R] - P[L-1]$
- [ ] Understand why $O(n)$ point updates destroy Prefix Sum efficiency (Static vs Dynamic profiles).

## Phase 2: Fundamental Implementations
- [ ] Open `problems.md` and read **Range Sum Query** and **Running Sum of 1D Array**.
- [ ] Implement the $N+1$ array padding technique to safely retrieve prefix queries starting from $0$.

## Phase 3: The Hash Map Architecture (Crucial)
- [ ] Study the logic behind **Subarray Sum Equals K**. Understand *why* `P[j] = P[i] - K` allows us to look up identical conditions in the past.
- [ ] Apply modular arithmetic in **Continuous Subarray Sum**. Learn how tracking `P % K` isolates multiples of K.
- [ ] Understand how mapping parity (0 mapped to -1) perfectly solves **Contiguous Array** balancing.

## Phase 4: Dimensional & Search Scaling
- [ ] Study the **Number of Submatrices That Sum to Target**.
    - Mentally trace how fixing two row-boundaries reduces a 2D matrix into a 1D column-sum iteration.
- [ ] Trace **Maximum Average Subarray II**. How does subtracting the candidate `avg` convert an average problem into a `Sum >= 0` prefix sum problem?

## Phase 5: The Difference Array Update Strategy
- [ ] Read the logic for $D[i] = A[i] - A[i-1]$ in `concepts.md`.
- [ ] Understand how to perform $O(1)$ range updates and $O(n)$ full array reconstruction.
- [ ] Apply this pattern to **Corporate Flight Bookings** and **Car Pooling**.

## Phase 6: Code Validation
- [ ] Open `solutions.cpp` and compile the file.
- [ ] Verify you understand the C++ syntax used to implement Hash Map lookups (e.g., `unordered_map.find()`).
- [ ] Ensure you're comfortable with `long long` logic as required in cumulative summations over large ranges.
