# Day 5: Array Rotation & Rearrangement

---

## SECTION 1: THE CORE THEORY OF ROTATION

"Rotating" an array means shifting all elements by `k` positions (left or right), wrapping around the ends.

**Right Rotation by `k`:** Element at index `i` goes to `(i + k) % n`.
**Left Rotation by `k`:** Element at index `i` goes to `(i - k + n) % n`.

*Fact:* Left rotation by `k` is exactly the same as Right rotation by `n - k`.

**Optimization rules:**
1. Array length `n`.
2. Always calculate `k = k % n` first. If `k == 0`, do nothing.

---

## SECTION 2: THREE METHODS TO ROTATE

### Method 1: Extra Space (The Safe Way)
Create `res` of size `n`.
```cpp
for(int i = 0; i < n; i++) res[(i+k)%n] = a[i];
```
*Time O(n), Space O(n).* Sometimes this is all you need if space isn't constrained.

### Method 2: Juggling Algorithm (GCD Method)
Cycles through elements. `gcd(n, k)` cycles exist. Complex to write without bugs.
*Time O(n), Space O(1).*

### Method 3: The Triple Reversal Method (The Gold Standard)
Brilliant trick. Reverse the whole array, then reverse the parts.

**Right rotate by k:**
1. Reverse whole array: `rev(0, n-1)`
2. Reverse first k elements: `rev(0, k-1)`
3. Reverse remaining n-k elements: `rev(k, n-1)`

**Example (Right rotate by 3):** `[1, 2, 3, 4, 5, 6, 7]`, k=3
1. Base: `[7, 6, 5, 4, 3, 2, 1]`
2. Rev 0..2: `[5, 6, 7, 4, 3, 2, 1]`
3. Rev 3..6: `[5, 6, 7, 1, 2, 3, 4]`

**Left rotate by k:**
1. Reverse first k: `rev(0, k-1)`
2. Reverse remaining: `rev(k, n-1)`
3. Reverse all: `rev(0, n-1)`

*Time O(n), Space O(1).* Always use this in interviews.

---

## SECTION 3: REARRANGEMENT TRICKS (Mathematical In-Place Swap)

When rearranging arrays without extra space but items are large or complex, we can't use simple swapping if we need to track both OLD and NEW values simultaneously.

### Trick 1: The Multiplication/Addition Hack (Values ≤ N)
If elements are strictly smaller than a constant `M` (often `M = max(input)+1` or `M = n`), you can store TWO values in one integer:
`arr[i] = arr[i] + (newValue % M) * M`

To retrieve the old value: `arr[i] % M`
To retrieve the new value: `arr[i] / M`

*Example:* Rearrange `a[i]` to `a[a[i]]` in-place.
```cpp
int n = a.size();
for(int i=0; i<n; i++) {
    int old_val = a[a[i]] % n; // extract original value
    a[i] = a[i] + old_val * n; // encode new value
}
for(int i=0; i<n; i++) {
    a[i] = a[i] / n; // decode to keep only new value
}
```

### Trick 2: Cycle Following (Placement Sort)
If mapping is a permutation (every element goes to exactly one unique spot), follow the cycle until you return to the start.
See: `First Missing Positive` (Day 3).

---

## SECTION 4: MATRIX ROTATION

A 2D matrix rotated 90 degrees can also be done using reversal tricks!

**Rotate 90 degrees Clockwise:**
1. Transpose the matrix (swap `m[i][j]` with `m[j][i]`).
2. Reverse each row.

**Rotate 90 degrees Counter-Clockwise:**
1. Transpose the matrix.
2. Reverse each column.

---

## SECTION 5: COMMON MISTAKES
1. **Forgetting `k = k % n`**: If `k > n`, rotation algorithms will throw index out of bounds.
2. **Reversal indices**: Using `k` instead of `k-1` for the first reversal segment. `[0...k-1]` has exactly `k` elements.
3. **M-encoding overflow**: If `M` is too large (e.g. `n = 10^5`), `old * M` can overflow a 32-bit integer. Use `long long` for the array elements during decoding if needed.
