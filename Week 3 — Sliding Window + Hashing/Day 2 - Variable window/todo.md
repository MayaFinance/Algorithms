# Day 2: Variable Sliding Window — Checklist

## Block 1: Theory (2h)
- [ ] Read concepts.md closely.
- [ ] Type out the "Universal Template" from memory.
- [ ] Explain why pure sliding window fails for `sum == target` if array has negative numbers.

## Block 2: Shortest vs Longest (3h)
- [ ] P1: Minimum Size Subarray Sum — capture `min_len` INSIDE the while loop.
- [ ] P2: Longest Substring Without Repeating — capture `max_len` OUTSIDE the while loop.
- [ ] Ensure you understand the distinction perfectly.

## Block 3: State Tracking & Replacements (4h)
- [ ] P3: Max Consecutive Ones III — State is `zero_count`.
- [ ] P4: Character Replacement — Understand the Optimization where `max_freq` doesn't need to be decremented.
- [ ] P6: Longest Subarray of 1's (1 Delete) — Same as P3 with `k=1`, just remember `- 1` at the end.

## Block 4: Mathematical Optimization & Exact K (3h)
- [ ] P8: Subarrays with K Different — Write the `AtMost(K)` helper function.
- [ ] P10: Count Nice Subarrays — Convert evens/odds to 0s and 1s. Use `AtMost` logic.
- [ ] P7: Reduce X to Zero — Invert the problem! Finding shortest from ends == Longest from middle.

## Block 5: Consolidation (2h)
- [ ] Draw the changing window state for `P2 (LC 3)` with `"abcabcbb"`.
- [ ] Review your code for P4. It's historically tricky. Let it sink in.
- [ ] Compile solutions and ensure 0 bugs.
