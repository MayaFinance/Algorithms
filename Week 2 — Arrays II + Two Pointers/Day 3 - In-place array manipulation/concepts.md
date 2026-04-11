# Day 3: In-Place Array Manipulation — Concepts

---

## SECTION 1: WHAT "IN-PLACE" MEANS

**Definition:** Solve the problem using O(1) extra space — modify the input array itself, not a copy. Output is reflected in the modified input.

**Why it matters:**
- Interviews test memory-awareness — "Can you do it without extra space?"
- Competitive programming: large inputs may TLE or MLE with O(n) copies.
- Fundamental building block: every efficient sort, partition, and rearrangement is in-place.

---

## SECTION 2: THE READ/WRITE SEPARATION PRINCIPLE

In-place works when you can separate the "role" of the array into two zones:

```
[0 .... slow-1]         [slow .... fast-1]          [fast .... n-1]
  WRITTEN ZONE           PROCESSING ZONE              UNREAD ZONE
  (output built here)    (might be overwritten)       (not yet seen)
```

**Critical:** You can overwrite `arr[slow]` only when you've already read and used `arr[slow]` or it no longer matters. The fast pointer always reads before the slow pointer writes to that position.

---

## SECTION 3: CORE TECHNIQUES

### 3.1 Filter In-Place (Two Pointers)
Already covered in Day 1. Slow = write head, fast = read head.

### 3.2 Compress In-Place
Group by property, maintain relative order. Example: move all evens first, then odds.

### 3.3 Rotate In-Place
Reverse entire array + reverse each part (reversal method). Zero extra space.

### 3.4 Mark Using Sign / Original Value
When forced to NOT use extra space but need a "visited" flag:
- Mark visited by negating the value at that index: `arr[|arr[i]|-1] *= -1`.
- Extract the result by checking signs.
- **Requirement:** Array values must map to valid indices (e.g., values in [1,n]).

### 3.5 Cyclic Replacement
For out-of-place elements that need to go to specific positions, follow cycles.
```
start at position i → place arr[i] at its target position → that position's old value
needs to go somewhere → follow the chain until cycle closes.
```

---

## SECTION 4: IN-PLACE SAFETY RULES

1. **Never overwrite before reading.** Always read `arr[fast]` before writing to `arr[slow]`.
2. **fast always reaches its target position before slow.** If `fast < slow` at any point, danger.
3. **For fill-from-back (merge sorted):** Start write pointer at the end where existing data isn't.
4. **For marking with negatives:** Only use this trick when values are positive and map to valid indices.
5. **For cyclic replacement:** Track starting position to detect cycle end. Use `count` to exit.
6. **Prefer two-pass if needed.** First pass: mark. Second pass: clean up. Still O(n) total.

---

## SECTION 5: COMMON PITFALLS

### Pitfall 1: Overwriting Unread Data
```cpp
// WRONG: fills from front, overwrites nums1 data still to be read
nums1[i] = nums1[j] // when i <= j and data at i+1...j is still unread
```

### Pitfall 2: Modifying Array While Iterating
In cyclic replacement, you must track whether the cycle has been processed.
Use a counter: if `count == n`, done. Or use a start pointer.

### Pitfall 3: Sign-Marking Breaks on Zero
If `arr[i] == 0`, you can't negate it to distinguish "visited". Handle zeros separately.

### Pitfall 4: Relative Order Lost
In-place partitioning (like Lomuto) is NOT stable — relative order of equal elements may change.
If stability required: use merge sort (O(n log n)) or extra O(n) buffer.

---

## SECTION 6: REVISION SHEET

| Problem Type | In-Place Strategy | Complexity |
|---|---|---|
| Filter elements | Read/Write two pointers | O(n) |
| Remove duplicates | Read/Write with condition | O(n) |
| Rotate array by k | Triple reverse | O(n) |
| Find missing/dup | Negate at index | O(n) |
| Cyclic rearrange | Follow cycle chains | O(n) |
| Stable partition | Merge sort | O(n log n) |

### Key Formulas
```
Rotate right k: reverse(0,n-1); reverse(0,k-1); reverse(k,n-1)
Rotate left  k: reverse(0,k-1); reverse(k,n-1); reverse(0,n-1)
Mark visited:   arr[abs(arr[i])-1] = -abs(arr[abs(arr[i])-1])
Cycle target:   target = (current_pos + k) % n
```
