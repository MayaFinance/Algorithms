# Day 2: Two Pointers — Opposite Direction (Inward Pointers)

---

## SECTION 1: CORE IDEA

One pointer starts at the **left end** (`l = 0`), one at the **right end** (`r = n-1`). They move **toward each other** and stop when they meet or cross. The total pointer moves are at most n — hence O(n).

**Why it works:** A sorted array has a monotonic property: moving left pointer right increases the element; moving right pointer left decreases it. This monotonicity lets us make an informed decision at each step about which pointer to move.

**Key invariant:** At each step, the current pair `(A[l], A[r])` is the "best candidate" given the remaining unchecked elements. We eliminate one endpoint at a time with certainty.

---

## SECTION 2: WHEN TO USE OPPOSITE-DIRECTION

**Structural requirement:** The array must be **sorted**, OR there must be a **monotonic relationship** between moving a pointer and the goal (e.g., moving right pointer left always decreases the sum).

**Trigger keywords:**
- "pair with sum = T" / "closest sum to T"
- "two endpoints" / "container" / "palindrome check"
- "minimize/maximize difference between two elements"
- "three-sum / k-sum"
- "partition by condition from both ends"

---

## SECTION 3: POINTER MOVEMENT DECISION GUIDE

Ask: "Does the current pair satisfy the condition?"

```
For pair-sum problems (target T):
  sum = A[l] + A[r]
  if sum == T:  → FOUND or record, then move both (or one)
  if sum < T:   → need larger → l++  (A[l] is too small)
  if sum > T:   → need smaller → r-- (A[r] is too large)

For minimizing |A[l] - A[r]|:
  → Always move the pointer pointing to the smaller element → larger pointer stays

For container/water problems:
  → Always move the pointer with the SHORTER wall (it limits the container height)
  → Moving the taller wall can only maintain or decrease height — never helps
```

**Rule of thumb:** Move the pointer whose change gives the **best possible improvement** toward the goal.

---

## SECTION 4: COMMON PATTERNS

### 4.1 Two Sum in Sorted Array
```cpp
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == target) { /* found */ l++; r--; }
    else if (sum < target) l++;
    else r--;
}
```

### 4.2 Three Sum (Fix one, two-pointer the rest)
```cpp
sort(a);
for (int i = 0; i < n-2; i++) {
    if (i > 0 && a[i] == a[i-1]) continue;  // skip dup outer
    int l = i+1, r = n-1;
    while (l < r) {
        int s = a[i]+a[l]+a[r];
        if (s == 0) { save; skip dups; l++; r--; }
        else if (s < 0) l++;
        else r--;
    }
}
```

### 4.3 Palindrome Check
```cpp
while (l < r) {
    if (a[l] != a[r]) return false;
    l++; r--;
}
return true;
```

### 4.4 Container With Most Water
```cpp
while (l < r) {
    area = min(h[l], h[r]) * (r - l);
    best = max(best, area);
    if (h[l] < h[r]) l++;  // shorter side limits — move it
    else r--;
}
```

---

## SECTION 5: COMMON MISTAKES

### Mistake 1: Two-pointer on unsorted array without justification
Two-pointer requires that "moving left pointer right changes things monotonically". Without sorted order, you cannot guarantee this.

### Mistake 2: Not skipping duplicates in k-sum problems
After finding a valid triple, move both pointers AND skip all equal elements to avoid duplicate triples.
```cpp
while (l < r && a[l] == a[l+1]) l++;
while (l < r && a[r] == a[r-1]) r--;
```

### Mistake 3: Using `l <= r` instead of `l < r`
When `l == r`, we're looking at one element as both — that's an invalid pair. Use `while (l < r)`.

### Mistake 4: Wrong pointer movement in "closest pair" problems
Always move the pointer with the **smaller** element (to try to increase the sum toward the target).

### Mistake 5: Not handling the target-sum case correctly
After finding an exact sum, if you need ALL pairs: move both pointers AND skip duplicates. If you need just one: return immediately.

---

## SECTION 6: COMPLEXITY

| Version | Time | Space |
|---|---|---|
| Array given sorted | O(n) | O(1) |
| Sort + two-pointer | O(n log n) | O(1) |
| 3Sum | O(n²) | O(1) |
| kSum | O(n^(k-1)) | O(1) |

---

## SECTION 7: REVISION SHEET

### Decision Guide (memorize)
```
sum < target  → l++ (need bigger left)
sum > target  → r-- (need smaller right)
sum == target → record, skip dups, l++; r--
Container     → move shorter height pointer inward
Palindrome    → if mismatch → false; else l++, r--
```

### Traps
- 🚨 Unsorted input → must sort first
- 🚨 `while (l <= r)` → wrong (allows single-element pair)
- 🚨 Forgetting duplicate skip in k-sum
- 🚨 Moving wrong pointer in "closest" problems
- 🚨 Integer overflow with large values: use `long long`
