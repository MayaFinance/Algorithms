# Day 7: Week 1 Contest — Study & Analysis Checklist

## Phase 1: Contest Attempt (2.5h)
- [ ] Open index.html and start the timer.
- [ ] Solve Problem A (Lucky Prefix) — target: 15 min.
- [ ] Solve Problem B (Storm Coverage) — target: 20 min.
- [ ] Solve Problem C (Zero Hunters) — target: 25 min.
- [ ] Solve Problem D (Maximum Flip Gain) — target: 30 min.
- [ ] Solve Problem E (Dominance Count) — target: 30 min.
- [ ] Solve Problem F (Circular Champion) — target: 25 min.
- [ ] Solve Problem G (Double Harvest) — target: 25 min.

## Phase 2: Post-Contest Editorial Review (2h)
- [ ] A: Verify you used `long long`. Understand why `int` fails.
- [ ] B: Confirm difference array logic. Trace D[] manually for the example.
- [ ] C: Confirm `freq[0]=1` is the first line before the loop (not after).
- [ ] D: Prove that min Kadane handles the "all positive" case correctly.
- [ ] E: Understand why inversions in prefix array = pairs with negative sum.
- [ ] F: Test your solution on an all-negative array. Does it return max_linear?
- [ ] G: Trace L[] and R[] arrays on the example. Confirm they are running-max arrays (not just Kadane curr).

## Phase 3: Mistake Analysis (1h)
- [ ] List every bug you encountered during the contest.
- [ ] For each bug: classify (overflow / off-by-one / wrong init / wrong formula).
- [ ] Identify which problems you couldn't solve — why? Pattern gap or time?
- [ ] Rewrite the solution for any problem you got wrong from scratch.

## Phase 4: Code Optimization (30 min)
- [ ] Ensure all problems compile cleanly (swap `solveX()` in main).
- [ ] Run edge case inputs: n=1, all same, all negative, n=max.
- [ ] Note which problems would TLE with brute force on n=2×10^5.

## Performance Grade
| Problems Solved | Grade |
|---|---|
| 7/7 | Elite (CF 1900+) |
| 5–6/7 | Strong (CF 1600–1900) |
| 3–4/7 | Solid (CF 1200–1600) |
| 1–2/7 | Developing (CF < 1200) |
