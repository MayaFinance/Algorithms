# Day 4: Dutch National Flag & Partitioning

---

## SECTION 1: THE CORE INVARIANT

Partitioning is about dividing an array into distinct contiguous regions based on a condition, **in-place**.

The **Dutch National Flag (DNF)** algorithm (Dijkstra) uses 3 pointers to divide an array into 3 regions (e.g., 0s, 1s, and 2s; or <pivot, ==pivot, >pivot).

**The Invariant:** At any point, the array is partitioned into 4 zones:
1. `arr[0 ... low-1]` = elements < pivot (e.g., 0s)
2. `arr[low ... mid-1]` = elements == pivot (e.g., 1s)
3. `arr[mid ... high]` = UNEXPLORED elements
4. `arr[high+1 ... n-1]` = elements > pivot (e.g., 2s)

**Loop condition:** `while (mid <= high)`
The loop ends when the unexplored region vanishes (`mid > high`).

---

## SECTION 2: WHY 3 REGIONS?

Standard QuickSort partition (Lomuto or Hoare) divides the array into TWO regions (<= pivot, > pivot).
DNF divides it into THREE. This is crucial when:
- There are many duplicate elements (standard generic QuickSort degrades to O(n²) without 3-way partition).
- The problem explicitly asks for 3 categories (e.g., sort colors: red, white, blue).
- Segregating negatives, zeros, and positives.

---

## SECTION 3: HOW TO MAINTAIN LOW, MID, HIGH

We scan using `mid`.
```cpp
int low = 0, mid = 0, high = n - 1;

while (mid <= high) {
    if (a[mid] == 0) {       // CASE 1: Belongs to bottom group
        swap(a[low], a[mid]);
        low++;
        mid++;
    } 
    else if (a[mid] == 1) {  // CASE 2: Belongs to middle group
        mid++;
    } 
    else {                   // CASE 3: Belongs to top group
        swap(a[mid], a[high]);
        high--;
    }
}
```

### Why does mid++ in Case 1 but NOT in Case 3?
- **Case 1 (a[mid]==0):** We swap `a[mid]` with `a[low]`. What was at `a[low]`? It was either part of the middle group (1s) or it was `low == mid`. In either case, after the swap, `a[mid]` is a 1 (or we just swapped the element with itself). It is fully processed and belongs in the middle group. Hence, `mid++`.
- **Case 3 (a[mid]==2):** We swap `a[mid]` with `a[high]`. What was at `a[high]`? We have **no idea** — it's from the unexplored zone. It could be a 0, 1, or 2. Therefore, `mid` CANNOT advance. We must process the new element now sitting at `mid` in the next iteration.

---

## SECTION 4: TWO-WAY PARTITIONING (LOMUTO)

If you only need 2 groups (e.g., move all even numbers to the front), you only need 2 pointers: `slow` (boundary of group 1) and `fast` (explorer).

```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (a[fast] % 2 == 0) {
        swap(a[slow], a[fast]);
        slow++;
    }
}
```
This is a direct application of the *Day 1 reading/writing pointers*, but using `swap` instead of overwrite, which preserves the discarded elements at the back.

---

## SECTION 5: STABLE VS UNSTABLE PARTITIONING

**DNF and Lomuto are UNSTABLE.**
If you have `[1_a, 0, 1_b, 0, 2]`, after DNF, the relative order of 1_a and 1_b, or the 0s, might change depending on swaps.

**If stability is required:**
- Use extra space (O(n)).
- Merge sort logic (O(n log n)).
- You CANNOT do O(n) time, O(1) space, stable 0/1/2 sort. (It's mathematically complex/impossible without shifting operations which cause O(n²)).

---

## SECTION 6: WHY IT'S EASY TO MESS UP UNDER PRESSURE

1. **Loop condition:** Writing `while (mid < high)` instead of `<=`. When `mid == high`, `a[mid]` is unexplored! It could be a 0, putting it in the wrong place if we stop.
2. **Incrementing mid on Case 3:** Swapping with `high` brings an unknown element to `mid`. If you do `mid++`, you skip processing it.
3. **Off-by-one in pointer init:** `high = n-1`, not `n`.

---

## SECTION 7: POINTER STATE TABLE

Let's trace `[2, 0, 2, 1, 1, 0]`

| Step | Array State | low | mid | high | Action |
|---|---|---|---|---|---|
| Init | `[2, 0, 2, 1, 1, 0]` | 0 | 0 | 5 | mid points to 2. Swap mid, high. high-- |
| 1 | `[0, 0, 2, 1, 1, 2]` | 0 | 0 | 4 | mid points to 0. Swap mid, low. low++, mid++ |
| 2 | `[0, 0, 2, 1, 1, 2]` | 1 | 1 | 4 | mid points to 0. Swap mid, low. low++, mid++ |
| 3 | `[0, 0, 2, 1, 1, 2]` | 2 | 2 | 4 | mid points to 2. Swap mid, high. high-- |
| 4 | `[0, 0, 1, 1, 2, 2]` | 2 | 2 | 3 | mid points to 1. mid++ |
| 5 | `[0, 0, 1, 1, 2, 2]` | 2 | 3 | 3 | mid points to 1. mid++ |
| End | `[0, 0, 1, 1, 2, 2]` | 2 | 4 | 3 | mid > high. Stop. |

---

## SECTION 8: REVISION SHEET (MEMORIZE)

**The DNF Template:**
```cpp
int low=0, mid=0, high=n-1;
while(mid <= high) {
    if(a[mid] == 0)      swap(a[low++], a[mid++]);
    else if(a[mid] == 1) mid++;
    else                 swap(a[mid], a[high--]); // NO mid++ here!
}
```

**Two-Way Partition (Lomuto):**
```cpp
int slow = 0;
for(int fast = 0; fast < n; fast++) {
    if (matches_condition(a[fast])) swap(a[slow++], a[fast]);
}
```

**Checklist:**
- [ ] Are there 3 categories? → DNF (3 pointers)
- [ ] Are there 2 categories? → Lomuto (2 pointers, slow/fast)
- [ ] Does order matter? → Partition is UNSTABLE.
