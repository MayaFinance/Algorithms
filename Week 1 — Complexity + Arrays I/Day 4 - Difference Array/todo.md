# Day 4: Interactive Mastery Checklist

## Theoretical Foundations (3h)
- [ ] Read through `concepts.md`.
- [ ] Formally define Difference Arrays mathematically `D[i] = A[i] - A[i-1]`.
- [ ] Write down the Proof for why the prefix sum reconstructs the array.
- [ ] Code the `O(1)` batch update bounds: `diff[l] += v`, `diff[r+1] -= v`.

## Real World Application (4h)
- [ ] Solve Range Addition (LeetCode 370). Notice the usage of `r+1`.
- [ ] Solve Corporate Flight Bookings (LeetCode 1109). Focus strictly on 1-index offsets translating smoothly to memory layouts.
- [ ] Solve *Little Girl & Maximum Sum* (Codeforces 276C). Master using the Diff array to plot "Frequencies/Heatmaps" instead of pure integers.
- [ ] Review `solutions.cpp` for alignment with your own source code.

## 2D Matrix Differencing (3h)
- [ ] Map out the Inclusion-Exclusion logic.
- [ ] Code the 4-Point Update for a matrix rectangle operation.
- [ ] Formulate the 2-D Prefix Sum unification formula visually on paper.

## Architecture Limitations & Enhancements (4h)
- [ ] Explore what happens when Domain limits breach 1,000,000,000 (Memory overflow!)
- [ ] Build a Coordinate Compression blueprint schema to shrink data constraints.
- [ ] Compare standard Difference array vs Single BIT vs Double BIT (interleaving Add/Sum constraints).
