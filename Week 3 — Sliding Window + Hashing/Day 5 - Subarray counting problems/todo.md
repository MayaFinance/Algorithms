# Day 5: Subarray Counting — Checklist

## Block 1: Theory (2h)
- [ ] Read concepts.md. Understand why negative numbers break standard Sliding Windows.
- [ ] Understand why `map[0] = 1` or `map[0] = -1` is essential logic!
- [ ] Memorize stringently: Count -> `ans += map[sum - k]`. Length -> `i - map[sum - k]`.

## Block 2: Basics (3h)
- [ ] P1: Subarray Sum Equals K — Code standard logic.
- [ ] P2: Contiguous Array — Transform `0`s to `-1`s to find target sum of 0. Max Length.
- [ ] P6: Max Size Subarray Sum k — Longest length, so only update map if sum NOT seen before.

## Block 3: Divisibility tricks (4h)
- [ ] Verify you know the fix for negative C++ modulos: `(rem % k + k) % k`.
- [ ] P3: Subarray Sums Divisible by K — Remainder counting.
- [ ] P4: Make Sum Divisible by P — Inverse problem. Find shortest `rem = total % P` array to pop out.
- [ ] P5: Continuous Subarray Sum — Exact length >= 2 constraint.

## Block 4: Math/Trees (3h)
- [ ] P7: Path Sum III — Do the DFS recursion passing the prefix map. Standard Backtracking setup.
- [ ] P8: Count Bad Pairs — Equation manipulation. Count valid pairs and subtract from total `nC2`.
- [ ] P9: Odd Sums — Even + Odd = Odd. Tracking prefix sums mathematically.

## Block 5: Consolidation (2h)
- [ ] P10: Excellent Pairs — Bitmask Set theorem mapping. Only works if you remove duplicate array values first.
- [ ] Compile solutions and ensure completely bug-free math.
