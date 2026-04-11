# Day 6: Pattern Revision — Checklist

## Block 1: Pattern Identification (3h)
- [ ] Read concepts.md. Understand the decision tree.
- [ ] Can you conceptually explain the Exact(k) = AtMost(k) - AtMost(k-1) formula out loud?
- [ ] P1: Max Erasure Value — Identify it as Variable Window sum tracking.
- [ ] P4: Grumpy Owner — Separate the static sums from the window gain. Total = Static + SlidingMax

## Block 2: Inversions & Edges (3h)
- [ ] P6: Max Points Cards — Treat as fixed sliding window of size `N-k` extracting the min sum.
- [ ] P10: Longest Nice Subarray — Master the bitwise trick. You can "remove" elements from an `OR` state using `XOR` ONLY IF you are guaranteed their bits didn't overlap!

## Block 3: The Multi-String Boss (4h)
- [ ] P7: Minimum Window Substring — The most frequently asked Hard string problem.
- [ ] Implement it keeping an integer `formed` variable tracking how many target frequencies are satisfied.
- [ ] Do NOT use string substr within the loop. Store `ans_idx` and `ans_len`, run substr ONCE at the end.

## Block 4: Hard Recalls (3h)
- [ ] P5: Sliding Window Maximum — Try the Monotonic deque completely blind.
- [ ] P9: Subarray Sum = K — Try the prefix map logic completely blind. Both are 2-minute Codeforces drills.

## Block 5: Consolidation (1h)
- [ ] Review your Codeforces setup template as we head into the contest tomorrow.
- [ ] Compile and run.
