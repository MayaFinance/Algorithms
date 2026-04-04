# Day 6: Array Edge Cases & Optimizations — Deep Theory

---

## SECTION 1: CONCEPTUAL FOUNDATION

### 1.1 Edge Cases in Arrays

**Why edge cases matter:** Competitive programming judges and interviewers specifically craft inputs to break naive solutions. If your code works on the sample but fails on edge cases, you scored 0.

---

#### Empty Array `n = 0`
Many problems guarantee `n >= 1`, but never assume this in real systems. Always ask: *what happens when the array is empty?*

```
A = []
→ Sum = 0? Error? Return -INF?
```
**Rule:** Always clarify constraints. If unconstrained, add an explicit guard:
```cpp
if (n == 0) return 0; // or INT_MIN, or throw
```

---

#### Single Element `n = 1`
Every algorithm that depends on comparing two adjacent elements (`arr[i]` vs `arr[i-1]`) must be seeded correctly from the first element. Initializing with `arr[0]` — **not** with 0 or INT_MIN — is the canonical safe pattern.

```
A = [7]
→ Max subarray = 7 (not 0!)
→ Min = 7, Max = 7
```

---

#### All Elements Same
Critical for sliding window and two-pointer problems. The window never shrinks (or never grows), which can cause infinite loops or wrong pointer movement.

```
A = [3, 3, 3, 3, 3]
→ Longest distinct subarray: n=1 (only one distinct value)
→ Sorted check: all comparisons A[i] == A[i+1] → be careful with strictly-increasing logic
```

---

#### Strictly Increasing / Strictly Decreasing
- **Increasing:** Every next element is larger. Prefix sum grows monotonically.
- **Decreasing:** Kadane's-style greedy resets at every element.

```
A = [1, 2, 3, 4, 5]   → sorted_check = true
A = [5, 4, 3, 2, 1]   → max subarray = first element only (for min-product, it's the whole array)
```

---

#### Large Values / Overflow
The most invisible killer in C++. When arrays contain values up to `10^9` and the subarray can be up to `10^5` elements long:

```
Sum ≤ 10^9 × 10^5 = 10^14  → Exceeds int (2^31 - 1 ≈ 2.1 × 10^9)
→ ALWAYS use long long for sums, products, prefix arrays
```

**Product overflow:** Even `int64_t` overflows when multiplying multiple `10^9`. Use `__int128` or modular arithmetic.

```cpp
// WRONG: int prefix[n];
// RIGHT: long long prefix[n];
long long prefix[n+1];
prefix[0] = 0;
for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + a[i];
```

---

#### Negative Numbers
Algorithms that assume non-negative inputs break immediately with negatives:
- **Sliding window:** Window cannot shrink on sum increase — adding negatives always helps, so the window never shrinks.
- **Greedy max:** You cannot greedily pick the "most positive" without considering that removing a negative later could help.

**Kadane's handles negatives natively** because the reset `f(i) = max(A[i], f(i-1) + A[i])` abandons any negative prefix.

---

#### Duplicates
Break assumptions that are unique-index-dependent:
- Binary search on duplicates requires `lower_bound` / `upper_bound`, not plain `mid` convergence.
- Two-pointer deduplication: `if (arr[i] == arr[i-1]) continue;`
- HashMap count vs. existence check matters.

---

#### Circular Arrays
A circular array of size `n` means index `n` wraps to `0`. Access pattern: `arr[i % n]`. Two key techniques:
1. **Duplicate the array:** Create `A' = A + A` (length `2n`), then run sliding window of max size `n`.
2. **Complement trick:** `max_circular = total_sum - min_subarray_sum` (used in LC 918).

---

#### Boundary Indices (i=0, i=n-1)
These are the most common sources of off-by-one bugs:
- Index `0`: No previous element — initialize separately.
- Index `n-1`: No next element — loop must end at `i < n`, not `i <= n`.
- Two-pointer: `while (l < r)` not `while (l <= r)` unless you need single-element windows.

---

### 1.2 Common Pitfalls

#### Off-By-One Errors
```cpp
// WRONG: iterates n+1 times
for (int i = 0; i <= n; i++) process(arr[i]);

// RIGHT
for (int i = 0; i < n; i++) process(arr[i]);

// Prefix sum: prefix[i+1] = prefix[i] + a[i]
// Query sum(l, r) = prefix[r+1] - prefix[l]   ← NOT prefix[r] - prefix[l]
```

**One-indexed trap in Codeforces:** Many CF problems are 1-indexed. Mixing 0-indexed code with 1-indexed input is a guaranteed WA.

---

#### Index Out of Bounds
```cpp
// WRONG: accessing arr[i+1] at i = n-1
for (int i = 0; i < n; i++) check(arr[i], arr[i+1]);

// RIGHT
for (int i = 0; i < n-1; i++) check(arr[i], arr[i+1]);
```

---

#### Integer Overflow
```cpp
// WRONG: int a, b; a + b overflows if both near INT_MAX
int sum = a + b;

// RIGHT: cast before addition
long long sum = (long long)a + b;

// Overflow check without overflow:
if (a > INT_MAX - b) { /* overflow */ }
```

Overflow in product:
```cpp
// Product of two 10^9 values = 10^18 → fits in long long (max ~9.2 × 10^18)
long long product = (long long)a * b;
```

---

#### Wrong Assumptions About Sorted Arrays
- Sorted + duplicates ≠ strictly sorted.
- Binary search `while (l <= r)` works for exact search; use `l < r` for boundary search.
- Never assume `arr[mid] < arr[mid+1]` on arrays with equal elements.

---

### 1.3 Optimization Techniques

#### Prefix Sum
**Transforms O(n) per query → O(1) per query** after O(n) preprocessing.

```
A = [3, 1, 4, 1, 5, 9, 2]
P = [0, 3, 4, 8, 9, 14, 23, 25]

Sum(l, r) = P[r+1] - P[l]   // 0-indexed l, r
Sum(2, 5) = P[6] - P[2] = 23 - 4 = 19
```

**When to use:** Any problem asking for range sums repeatedly. Essential when combined with hash maps for "prefix sum = k" style queries.

---

#### Suffix Sum
The mirror of prefix sum, built from the right:
```
S[n] = 0
S[i] = A[i] + S[i+1]

Use: S[i] = sum from A[i] to A[n-1]
```
**Combined use:** `prefix[i] + suffix[i+1]` = "sum of everything except index i" — used in product-of-all-except-i problems.

---

#### Difference Array
**Transforms O(n) per range-update → O(1) per update**, then O(n) final reconstruction.

```
D[l] += val;  D[r+1] -= val;
// After all updates: prefix sum of D gives the final array
```

---

#### Sliding Window (Fixed Size)
A subarray of exactly size `k` slides from left to right:
```
sum = sum of first k elements
for i from k to n-1:
    sum += A[i] - A[i-k]
    update_answer(sum)
```
**O(n) time, O(1) space.** Key: subtract the element falling out of the left side.

#### Sliding Window (Variable Size)
Window expands on the right, contracts on the left based on a condition:
```cpp
int l = 0; long long curr = 0;
for (int r = 0; r < n; r++) {
    curr += A[r];
    while (violation(curr)) { curr -= A[l++]; }  // shrink
    update_answer(r - l + 1);
}
```
**Used for:** Longest/shortest subarray with property X, subarray sum ≥ / ≤ k, at-most-k-distinct elements.

---

#### Two Pointers
Two indices moving toward each other (or in the same direction) on a sorted (or partially structured) array.

```
Classic: Given sorted array, find pair summing to T.
l = 0, r = n-1
while (l < r):
    s = A[l] + A[r]
    if s == T: found
    elif s < T: l++
    else: r--
```
**Key invariant:** There must be a monotonic relationship between pointer movement and the goal.

---

#### In-Place Modification
Avoid extra arrays by using the input array itself (within problem constraints):
- **Dutch National Flag:** 3-partition in one pass, O(1) space.
- **Rotation:** Reverse entire, reverse first k, reverse last n-k.
- **Remove duplicates:** Write pointer pattern.

```cpp
// Remove duplicates in-place, return new length
int write = 1;
for (int i = 1; i < n; i++)
    if (arr[i] != arr[i-1]) arr[write++] = arr[i];
return write;
```

---

#### Space-Time Tradeoffs
| Strategy | Time | Space | Example |
|---|---|---|---|
| Recompute every query | O(n) per query | O(1) | naive range sum |
| Prefix sum precompute | O(1) per query | O(n) | range sum queries |
| Sorted + binary search | O(log n) per query | O(n) | frequency queries |
| HashMap | O(1) amortized | O(n) | subarray sum = k |

---

#### Precomputation
Build answers offline before processing queries. Classic: precompute `left[i]` and `right[i]` arrays in two passes, then answer each query in O(1).

---

#### Bit Manipulation (When Relevant)
- `x & (x-1)` → clears lowest set bit (check if power of 2: `x & (x-1) == 0`)
- `x ^ x = 0` → cancellation: find the single non-duplicate element
- `(i >> k) & 1` → check if bit k of i is set (subsets, bitmask DP)
- `x | (1 << k)` → set bit k

```
A = [4, 1, 2, 1, 2]  → XOR all = 4 ^ 1 ^ 2 ^ 1 ^ 2 = 4 (the single element)
```

---

### 1.4 Complexity Improvements: O(n²) → O(n)

| Problem | Naive | Optimized | Technique |
|---|---|---|---|
| Range sum query | O(n) per query | O(1) query / O(n) build | Prefix sum |
| Max subarray sum | O(n²) enumerate | O(n) | Kadane's |
| Range updates | O(n) per update | O(1) update / O(n) reconstruct | Difference array |
| Two-sum on sorted | O(n²) brute | O(n) | Two pointers |
| Longest subarray ≤ k | O(n²) | O(n) | Sliding window |
| Count subarrays sum=k | O(n²) | O(n) | Prefix sum + HashMap |

---

## SECTION 2: PATTERN RECOGNITION

### Pattern 1: Prefix Sum + HashMap

**When to use:** "Count subarrays with sum = k", "find if subarray with sum divisible by k exists"

**Key idea:** `sum(l, r) = prefix[r] - prefix[l-1]`. If `prefix[r] - k` has appeared before, those subarrays exist.

**Traps:**
- Initialize `map[0] = 1` (empty prefix has sum 0)
- Use `long long` for prefix when values are large
- For "divisible by k": use `((prefix % k) + k) % k` to normalize negative remainders

---

### Pattern 2: Sliding Window (Shrink on Violation)

**When to use:** "Longest/shortest subarray with property P" where P is monotonic in window size.

**Key idea:** Expand right always; shrink left only when constraint is violated. Count or update answer after every right-expand.

**Traps:**
- Variable window only works when adding elements worsens (or can only worsen) the constraint
- Does NOT work when you need exact sum = k (prefix sum + map is better)
- Infinite loop if shrink condition never triggers — check that adding elements changes the violation state

---

### Pattern 3: Two Pointers on Sorted Array

**When to use:** "Find pair/triplet with sum X in sorted array", "merge two sorted arrays", "remove duplicates"

**Key idea:** Monotonic movement — if sum is too small, move left pointer right; if too large, move right pointer left.

**Traps:**
- Array must be sorted (or structurally monotonic) — two pointers on unsorted arrays require extra work
- Skip duplicates explicitly with `while (l < r && arr[l] == arr[l+1]) l++;`
- For 3Sum: outer loop + inner two-pointer = O(n²) total

---

### Pattern 4: In-Place Write Pointer

**When to use:** "Remove elements in-place", "deduplicate", "move all zeros to end"

**Key idea:** Maintain a `write` pointer that only advances when a qualified element is found.

**Traps:**
- Don't read from write position if write > read distance (they can overlap)
- The tail of the array after `write` is garbage — return `write` as new length, don't access beyond it

---

### Pattern 5: Difference Array for Range Updates

**When to use:** "Apply +v to subarray [l, r] multiple times, then query final values"

**Key idea:** Update D[l] += v, D[r+1] -= v takes O(1). Final array = prefix sum of D.

**Traps:**
- D must have size `n+1` to safely write D[r+1] when r = n-1
- If queries come after each update, difference array doesn't help — need segment tree

---

### Pattern 6: Greedy + Sort

**When to use:** "Maximum sum after selecting k elements", "minimum operations to make array non-decreasing"

**Key idea:** Sort to expose the structure (largest/smallest elements), then greedily pick.

**Traps:**
- Greedy doesn't always work — prove exchange argument or use DP instead if there are dependencies
- Sort + greedy = O(n log n). If you need O(n), use partially sorted structures (heap, quickselect)

---

### Pattern 7: Circular Array

**When to use:** "Maximum subarray in circular array", "minimum window that wraps around"

**Key idea:**
- **Option A:** Duplicate array to length `2n`, run fixed window of max size `n`. O(n) space.
- **Option B:** Complement trick — `max_circular = total - min_linear_subarray`. O(1) space.

**Traps:**
- All-negative arrays: `total - min_sum = 0` which is wrong. Guard: if `max_linear < 0`, return `max_linear`.
- Window size must be `≤ n` in the duplication approach (use a deque or fixed-window max).

---

## SECTION 3: PROBLEM SET (PROGRESSIVE)

---

### LEVEL 1 — WARM-UP (Basic Edge Cases)

---

#### Problem 1: Running Sum Queries
**Difficulty:** Easy
**Platform:** Custom / LeetCode 303 variant

**Statement:** Given an array `A` of `n` integers (including negatives and zeros), answer `q` queries. Each query gives indices `(l, r)` and asks for `sum(A[l..r])`. Guarantee `0 ≤ l ≤ r < n`.

**Example:**
```
A = [3, -1, 4, 1, -5, 9, 2]
Query (1, 4) → -1 + 4 + 1 + (-5) = -1
Query (0, 6) → 13
Query (5, 5) → 9
```

**Edge case targets:** Negative values (no assumption sum is positive), single-element query `l == r`, large `q` (must not be O(n) per query).

**Optimization target:** O(n) build + O(1) per query via prefix sum.

---

#### Problem 2: Find the Missing Number
**Difficulty:** Easy
**Platform:** LeetCode 268

**Statement:** Given an array `A` containing `n` distinct numbers in range `[0, n]`, find the one missing number.

**Example:**
```
A = [3, 0, 1]   → missing = 2
A = [9,6,4,2,3,5,7,0,1] → missing = 8
```

**Edge case targets:** Missing number is `0` (the smallest), missing number is `n` (the largest), single element array `[0]` → missing is `1`.

**Optimization target:** O(n) time, O(1) space using XOR trick or Gauss sum formula: `expected = n*(n+1)/2 - actual_sum`.

---

#### Problem 3: Move Zeros to End
**Difficulty:** Easy
**Platform:** LeetCode 283

**Statement:** Move all zeros in array `A` to the end while maintaining relative order of non-zero elements. In-place, O(1) space.

**Example:**
```
A = [0, 1, 0, 3, 12] → [1, 3, 12, 0, 0]
A = [0]               → [0]
A = [1]               → [1]
```

**Edge case targets:** All zeros, no zeros, single zero at start, single zero at end.

**Optimization target:** Single-pass write-pointer: O(n) time, O(1) space.

---

#### Problem 4: Check if Array is Sorted and Rotated
**Difficulty:** Easy
**Platform:** LeetCode 1752

**Statement:** Given array `A`, return `true` if it can be obtained by rotating some non-decreasing array.

**Example:**
```
A = [3,4,5,1,2] → true  (rotate [1,2,3,4,5] by 3)
A = [2,1,3,4]   → false
A = [1,1,1]     → true  (all same)
```

**Edge case targets:** All elements equal, strictly sorted (no rotation needed), rotation at last index.

**Optimization target:** Count "drop points" (where `A[i] > A[i+1] % n`). If count > 1, false.

---

### LEVEL 2 — CORE (Pattern-Based)

---

#### Problem 5: Longest Subarray with Sum ≤ K
**Difficulty:** Medium
**Platform:** Codeforces-style / LeetCode 209 variant

**Statement:** Given array of **non-negative** integers and integer `k`, find the length of the longest contiguous subarray with sum ≤ k.

**Example:**
```
A = [2, 3, 1, 2, 4, 3], k = 7
→ [2, 3, 1] and [3, 1, 2] both have sum 6 ≤ 7, length 3
→ Answer: 4 (subarray [2,3,1,2], sum=8... wait: [2,3,1,2]=8 > 7) → Answer: 3
```

**Edge case targets:** k = 0 (only zeros count), single element > k (answer 0), all elements valid.

**Optimization target:** Sliding window shrink. Only works for non-negative (constraint is monotonic). O(n).

---

#### Problem 6: Count Subarrays with Sum Exactly K
**Difficulty:** Medium
**Platform:** LeetCode 560

**Statement:** Given integer array `A` (can have negatives) and integer `k`, return count of contiguous subarrays whose sum equals `k`.

**Example:**
```
A = [1,1,1], k = 2  → 2  (subarrays [1,1] at positions 0-1 and 1-2)
A = [1,-1,1], k = 1 → 3
```

**Edge case targets:** k = 0 (count subarrays that cancel out), all negatives, duplicates in prefix sum map.

**Optimization target:** Prefix sum + HashMap. Sliding window FAILS here (negatives break monotonicity).

---

#### Problem 7: Maximum Sum of Non-Adjacent Elements
**Difficulty:** Medium
**Platform:** LeetCode 198 (House Robber)

**Statement:** Given array `A` of non-negative integers, find the maximum sum such that no two chosen elements are adjacent.

**Example:**
```
A = [2, 7, 9, 3, 1]  → 2 + 9 + 1 = 12
A = [2, 1, 1, 2]     → 2 + 1 = ?? → 2 + 2 = 4 (positions 0 and 3)
```

**Edge case targets:** n=1 (answer is A[0]), n=2 (answer is max(A[0], A[1])), all equal elements.

**Optimization target:** O(n) DP with O(1) space: `dp = max(prev2 + A[i], prev1)`.

---

#### Problem 8: Minimum Size Subarray Sum ≥ S
**Difficulty:** Medium
**Platform:** LeetCode 209

**Statement:** Given array of positive integers and integer `s`, find the minimum length of a contiguous subarray with sum ≥ s. Return 0 if none.

**Example:**
```
A = [2,3,1,2,4,3], s = 7  → 2 (subarray [4,3])
A = [1,4,4], s = 4         → 1 (subarray [4])
A = [1,1,1,1,1], s = 11   → 0
```

**Edge case targets:** Sum of entire array < s (return 0), single element ≥ s, all elements equal to s-1.

**Optimization target:** Sliding window (works because all values positive). O(n).

---

#### Problem 9: Product of Array Except Self
**Difficulty:** Medium
**Platform:** LeetCode 238

**Statement:** Given array `A`, return array `B` where `B[i]` = product of all elements except `A[i]`. No division allowed. O(n) time, O(1) extra space (output array doesn't count).

**Example:**
```
A = [1,2,3,4]  → B = [24,12,8,6]
A = [-1,1,0,-3,3] → B = [0,0,9,0,0]
```

**Edge case targets:** Array with zeros (one zero → all become 0 except zero position; two zeros → all 0), array with negatives.

**Optimization target:** Left-pass prefix product + right-pass suffix product in O(n) and O(1) extra.

---

#### Problem 10: Trapping Rain Water
**Difficulty:** Medium-Hard
**Platform:** LeetCode 42

**Statement:** Given elevation map `height[n]`, compute total water trapped after rain.

**Example:**
```
height = [0,1,0,2,1,0,1,3,2,1,2,1]  → 6
height = [4,2,0,3,2,5]               → 9
```

**Edge case targets:** n ≤ 1 (no water possible), strictly increasing (no left walls), all equal (no water), single valley.

**Optimization target:** Left-max prefix array + right-max suffix array, then `water[i] = min(left_max[i], right_max[i]) - height[i]`. O(n), O(n). Further optimize with two pointers to O(1) space.

---

### LEVEL 3 — ADVANCED (Tricky + Optimization Heavy)

---

#### Problem 11: Maximum Sum Subarray after K Negations
**Difficulty:** Medium-Hard
**Platform:** LeetCode 1005

**Statement:** Given array `A` and integer `k`, you must flip the sign of exactly `k` elements (can repeat on same element). Maximize the sum.

**Example:**
```
A = [4,2,3], k = 1  → flip -2 to 2, but no negative. Flip smallest positive: [4,-2,3] → 5? Wrong.
Actually: flip 2 → [4,-2,3] sum=5. Flip 3 → [4,2,-3] sum=3. Best: flip 2 → sum=5.
Wait: A=[4,2,3], k=1 → flip smallest abs value minimum? Let's re-examine.
Best: flip 2 gives [4,-2,3]=5. But can we flip negative 2? A has no negatives. Flip 2: sum=5. Answer=5.

A = [3,-1,0,2], k=3 → flip -1, then flip 0 twice (doesn't change 0). → sum = 3+1+0+2 = 6
```

**Edge case targets:** k is odd with all positives (must flip smallest, then flip it back if k is odd), zeros present (flip zeros repeatedly for free), all negatives.

**Optimization target:** Sort, greedily flip negative values (largest magnitude first), if k remains, flip smallest absolute value. O(n log n).

---

#### Problem 12: Maximum Width Ramp
**Difficulty:** Hard (Codeforces 1700 level)
**Platform:** LeetCode 962

**Statement:** A ramp is a pair `(i, j)` with `i < j` and `A[i] ≤ A[j]`. Find the maximum width `j - i`.

**Example:**
```
A = [6,0,8,2,1,5]  → ramp (1,2): 0≤8, width=1. Ramp (1,5): 0≤5, width=4. Answer=4.
A = [9,8,1,0,1,9,4,0,4,1] → Answer=7
```

**Edge case targets:** Strictly decreasing (no ramp exists? No — A[i]≤A[j] allows equal, so answer ≥ 0). All same elements (answer = n-1). n=1 (answer=0).

**Optimization target:** Monotone decreasing stack for candidate left-endpoints, then right sweep from right to left. O(n).

---

#### Problem 13: Shortest Subarray with Sum ≥ K (Negatives Allowed)
**Difficulty:** Hard
**Platform:** LeetCode 862

**Statement:** Given array `A` (may contain negatives) and `k`, find the minimum length of subarray with sum ≥ k.

**Example:**
```
A = [1], k = 1         → 1
A = [1,2], k = 4       → -1
A = [2,-1,2], k = 3    → 3
```

**Edge case targets:** No valid subarray (return -1), k is very large, negatives present (sliding window breaks — must use prefix sum + deque).

**Optimization target:** Prefix sum array + **monotone deque** (sliding window minimum on prefix). O(n).

---

#### Problem 14: Maximum Score from Subarray Minimums
**Difficulty:** Hard (CF 1900 level)
**Platform:** Codeforces-style

**Statement:** Given array `A`, for every subarray `[l, r]`, define score as `min(A[l..r]) × (r - l + 1)`. Find the maximum score over all subarrays.

**Example:**
```
A = [1, 3, 2, 4]
Scores: [1]→1, [1,3]→2, [1,3,2]→3, [3]→3, [3,2]→4, [2]→2, [3,2,4]→6, [2,4]→4, [4]→4
→ Max = 6 (subarray [3,2,4], min=2, length=3)
Wait: [3]×1=3, [3,2,4] min=2, 2×3=6. Also [1,3,2,4] min=1, 1×4=4.
Answer = 6
```

**Edge case targets:** All equal elements (answer = n × A[0]), single element, entire array is the answer.

**Optimization target:** Monotone stack to find "previous smaller" and "next smaller" for each element, then O(1) per element. O(n) total — the classic "largest rectangle in histogram" variant.

---

#### Problem 15: Minimum Operations to Make Array Non-Decreasing
**Difficulty:** Hard
**Platform:** Codeforces-style

**Statement:** Given array `A` of integers, in one operation you can increment any element by 1. Find the minimum total operations to make `A` non-decreasing. (Alternatively: find minimum number of elements to remove to make it non-decreasing — Longest Non-Decreasing Subsequence variant.)

**Example:**
```
A = [3, 1, 2]
→ Increment A[1] to 3: [3,3,2]. Increment A[2] to 3: [3,3,3]. Operations = 3.
OR:
→ Increment A[0] to nothing, A[1] to 3, A[2] to 3. Same: 3.
Optimal: Keep A[0]=3, increment A[1] to 3 (cost 2), A[2] to 3 (cost 1). Total = 3.
```

**Edge case targets:** Already sorted (0 ops), strictly decreasing (many ops needed), all equal (0 ops).

**Optimization target:** For the "minimum decrements to make non-increasing" version: replace each value with `min(A[i], running_min)` from left — purely greedy. For increment version: equivalent DP O(n log n).

---

## SECTION 4: INTERVIEW SIMULATION

### Interview Simulation Format (Per Problem)

For each problem, follow this mental process:

**Step 1:** Clarify constraints (can values be negative? Can n=0? What's the return for empty/impossible?).

**Step 2:** Brute force first — always state it and its complexity.

**Step 3:** Identify the edge case or structural property being tested.

**Step 4:** Derive the optimization from the insight, not from memory.

**Step 5:** Dry-run on the example AND at least one edge case.

---

### Problem 6 Simulation (Count Subarrays Sum = K)

**Interviewer:** "How would you approach this?"

**Your answer (brute force):**
> "I'd enumerate all O(n²) subarrays, compute sum in O(1) using prefix sum, count those equal to k. O(n²) time, O(n) space."

**Interviewer:** "Can you do better?"

**Key insight:**
> "`sum(l, r) = k` means `prefix[r] - prefix[l-1] = k`, so `prefix[l-1] = prefix[r] - k`. If I know `prefix[r]`, I just need to count how many previous prefix values equal `prefix[r] - k`. Store prefix values in a hash map."

**Dry run on `A = [1,1,1], k = 2`:**
```
prefix: 0  → map = {0:1}
prefix: 1  → look for 1-2=-1, not found. map={0:1,1:1}
prefix: 2  → look for 2-2=0, found 1 time. count=1. map={0:1,1:1,2:1}
prefix: 3  → look for 3-2=1, found 1 time. count=2. map updated.
Answer: 2 ✓
```

---

### Problem 10 Simulation (Trapping Rain Water)

**Brute force:** For each position `i`, scan left for max, scan right for max: O(n²).

**Optimization insight:** Precompute `L[i]` (max to the left of i inclusive) and `R[i]` (max to the right of i inclusive). Then water at `i` = `max(0, min(L[i], R[i]) - height[i])`. O(n) time, O(n) space.

**Further optimization (two-pointer, O(1) space):**
```
l=0, r=n-1, left_max=0, right_max=0, water=0
while l < r:
    if height[l] <= height[r]:
        if height[l] >= left_max: left_max = height[l]
        else: water += left_max - height[l]
        l++
    else:
        if height[r] >= right_max: right_max = height[r]
        else: water += right_max - height[r]
        r--
```

**Dry run on `[0,1,0,2,1,0,1,3,2,1,2,1]`:** See solutions.cpp for full trace.

---

## SECTION 5: CODE IMPLEMENTATION

See `solutions.cpp` for full C++ implementations with comments.

Python implementations are embedded in `solutions.cpp` as comment blocks.

---

## SECTION 6: EDGE CASE STRESS TESTING

### Problem 1 (Range Sum)
| Edge Case | Input | Expected |
|---|---|---|
| Single element query | A=[5], query(0,0) | 5 |
| All negatives | A=[-1,-2,-3], query(0,2) | -6 |
| l = r = 0 | A=[4,5], query(0,0) | 4 |
| Full range | A=[1,2,3], query(0,2) | 6 |

### Problem 6 (Count Subarrays Sum = K)
| Edge Case | Input | Expected |
|---|---|---|
| k = 0 | [1,-1,2,-2], k=0 | 4 |
| All same | [3,3,3], k=6 | 2 |
| Single match | [1,2,3], k=6 | 1 |
| No match | [1,2,3], k=10 | 0 |

### Problem 10 (Trapping Rain Water)
| Edge Case | Input | Expected |
|---|---|---|
| No walls | [1,2,3,4,5] | 0 |
| Single valley | [3,0,3] | 3 |
| n=1 | [5] | 0 |
| All same | [2,2,2] | 0 |
| Flat bottom | [3,0,0,0,3] | 9 |

---

## SECTION 7: MISTAKE ANALYSIS

### Logical Mistakes
1. **Initializing with 0 instead of arr[0]:** When all elements are negative, initializing Kadane or max-so-far with 0 gives a wrong answer of 0 instead of the least-negative element.
2. **Using sliding window with negatives:** Sliding window works only when adding an element can never decrease the window's "score" monotonically. Negatives break this.
3. **Forgetting the `map[0] = 1` initialization in prefix-sum + map:** The first time `prefix == k`, the code doesn't count the subarray starting from index 0.
4. **In circular arrays:** Forgetting the all-negative guard: `if (max_sum < 0) return max_sum` before checking the circular case.
5. **Off-by-one in prefix sum query:** `sum(l, r) = prefix[r+1] - prefix[l]`, not `prefix[r] - prefix[l-1]` (unless 1-indexed).

### Performance Issues
1. **Using `vector.size() - 1` in an unsigned context:** If `size() == 0`, then `size() - 1` wraps around to a huge positive number (unsigned underflow). Cache `int n = arr.size()` and use `n-1`.
2. **Repeated calls to `.size()` inside loops:** Cache it once outside the loop.
3. **Using `sort` when `nth_element` suffices:** For finding the k-th element, `nth_element` is O(n) average vs O(n log n) for full sort.

### Edge Case Misses
1. **n=0 or n=1** — Most algorithms are designed for n≥2. Explicitly test these.
2. **All-negative arrays** — Kadane, max product, circular max all have special behavior.
3. **Overflow on product** — Even `long long` overflows on large product sequences.
4. **k=0 in "subarrays with sum=k"** — The empty subarray has sum 0, careful with definition.
5. **Zeros in product arrays** — Zeros reset products, creating boundaries.

---

## SECTION 8: REVISION SHEET

### Key Patterns
| Pattern | Trigger Keywords | Complexity |
|---|---|---|
| Prefix Sum + Map | "count subarrays", "sum equals k" | O(n) |
| Sliding Window | "longest/shortest subarray", non-negative values | O(n) |
| Two Pointers | "pair with sum", sorted array, "remove duplicates" | O(n) |
| Difference Array | "range update, point query" | O(n) |
| In-place Write Pointer | "in-place", "O(1) space", "remove elements" | O(n) |
| Monotone Stack | "next greater element", "largest rectangle" | O(n) |

### Key Formulas
```
Sum(l, r) [0-indexed]         = prefix[r+1] - prefix[l]
Max circular subarray         = max(max_linear, total - min_linear)
Water at position i           = max(0, min(left_max[i], right_max[i]) - height[i])
Missing number (Gauss)        = n*(n+1)/2 - actual_sum
Expected XOR                  = XOR(0..n) XOR XOR(array)
```

### Red Flags
- 🚨 Using `int` for large sums — always ask: can sum exceed 2×10⁹?
- 🚨 Sliding window on array with negatives — check monotonicity first
- 🚨 No `map[0] = 1` before the prefix sum loop
- 🚨 `arr.size() - 1` when size could be 0 (unsigned underflow)
- 🚨 Two-pointer on unsorted array without justification
- 🚨 Greedy approach without proving exchange argument

### Interview Tips
1. **Always start with edge cases BEFORE coding** — mention n=0, n=1, all-negative, overflow.
2. **State brute force first** — it shows you understand the problem and gives you a correctness baseline.
3. **Derive insight from the structure** — don't say "I'll use sliding window." Say "since values are non-negative, adding elements never decreases the sum, so I can maintain a valid window monotonically."
4. **Dry-run before claiming correct** — trace your code on the example AND one edge case.
5. **Name your variable clearly:** `left_max`, `right_max`, `write_ptr` — never `a`, `b`, `temp`.
6. **At Codeforces 1900+ level:** Look for "complementary" solutions — what if instead of finding the maximum, you find the minimum of something else and subtract?
