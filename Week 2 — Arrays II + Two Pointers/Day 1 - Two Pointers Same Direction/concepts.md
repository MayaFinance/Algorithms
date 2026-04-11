# Day 1: Two Pointers — Same Direction (Fast/Slow)

---

## SECTION 1: WHAT IS THE SAME-DIRECTION TWO POINTER PATTERN?

Two pointers both start at the left (or one at a defined position) and both move **rightward**. The key distinction from opposite-direction is: **both pointers never move left**.

The two pointers usually play different roles:
- **Fast pointer (reader):** scans every element — advances unconditionally.
- **Slow pointer (writer):** only advances when a condition is met — marks the "frontier" of kept elements.

**Core insight:** This is a streaming filter. The fast pointer reads the input; the slow pointer writes the output. Since both move right only, the algorithm is always O(n).

---

## SECTION 2: WHY IT WORKS

**Invariant:** At all times, `arr[0..slow-1]` (or `arr[0..slow]`) contains the valid processed elements. The fast pointer guarantees every element is seen exactly once. No quadratic rescan occurs.

Imagine a secretary (slow) accepting only qualified candidates (fast scans everyone). Once a candidate is accepted, the secretary's desk moves forward. This never requires going back — hence O(n).

---

## SECTION 3: WHEN TO USE SAME-DIRECTION TWO POINTERS

**Trigger keywords in problem statements:**
- "in-place"
- "without extra space"
- "remove/filter elements maintaining order"
- "find two elements at positions i < j with property P"
- "length of longest subarray where..."
- "skip duplicates"
- "merge sorted arrays"

**Structural triggers:**
- Array is sorted OR you are building sorted output
- You need to write valid elements to the front
- You need a "read head" and a "write head"
- The condition for advancing slow depends only on the current element and the last accepted element

---

## SECTION 4: HOW TO RECOGNIZE IT INSTANTLY

Ask yourself these 3 questions:
1. Am I processing elements **left to right without going back**?
2. Do I want to **keep some elements** and discard others (or count, or track)?
3. Can I determine if an element is kept by looking at just **the current element and the "frontier"**?

If all 3: same-direction two pointers.

**Contrast with sliding window:** Sliding window also uses same-direction, but specifically tracks a **window sum/count** and shrinks from the left when a constraint is violated. Two pointers (w/w write pointer) only move right. The patterns overlap — sliding window IS a form of two pointers.

---

## SECTION 5: THE FAST/SLOW (READ/WRITE) TEMPLATE

```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (should_keep(arr[fast], arr[slow-1])) {
        arr[slow++] = arr[fast];
    }
}
// arr[0..slow-1] is the result, length = slow
```

Variations:
- `slow` and `fast` start at different initial positions.
- Write at `slow` before incrementing vs after.
- Condition checks `arr[fast]` against `arr[slow]` (current write target) vs `arr[slow-1]` (last written).

---

## SECTION 6: COMMON VARIATIONS

### 6.1 Remove/Filter Elements
Keep elements satisfying a condition. Write pointer marks next valid position.
```
Read: [3, 2, 2, 3]  val=3 → result: [2, 2]  len=2
```

### 6.2 Deduplicate Sorted Array
Keep at most one (or k) copies of each element.
```
[1,1,2,2,3] → [1,2,3]  (slow=3)
```

### 6.3 Find Pair (i, j) with i < j and Property P
Fast scans, slow tracks a "useful" earlier position. Classic: Floyd's cycle detection (slow=1x, fast=2x).

### 6.4 Merge Two Sorted Arrays In-Place
Use two read pointers (one per array), one write pointer.

### 6.5 Sliding Window (Same-Direction Shrink)
Both left and right start at 0, right expands, left shrinks when constraint violated.
```
longest subarray with sum ≤ k: left shrinks, right always grows
```

---

## SECTION 7: COMMON MISTAKES & EDGE CASES

### Mistake 1: Off-by-one in write pointer initialization
```cpp
// WRONG: slow=1 when array has 1 element → reads arr[0] against arr[-1]
// RIGHT: initialize slow=0 or slow=1 depending on whether first element is always kept
```

### Mistake 2: Comparing fast to wrong reference (slow vs slow-1)
If slow is the "next write position", last written is at `arr[slow-1]`.
If slow is the "last written position", compare to `arr[slow]`.
Pick one convention and be consistent.

### Mistake 3: Not handling empty input
```cpp
if (n == 0) return 0;
```

### Mistake 4: Forgetting that slow is the length after filtering
Return `slow`, not `slow-1`.

### Mistake 5: Sliding window — forgetting that both pointers never cross
```cpp
while (left < right && violation) left++;  // not left <= right
```

### Edge Cases to Always Test:
- n = 0 (empty)
- n = 1 (single element)
- All elements same
- All elements to be removed (result empty)
- No elements to be removed (result = input)
- Alternating keep/remove

---

## SECTION 8: COMPLEXITY

| Operation | Time | Space |
|---|---|---|
| Fast pointer scan | O(n) | — |
| Slow pointer writes | ≤ O(n) total | — |
| Overall | **O(n)** | **O(1)** extra |

The brute force (nested loops, shift elements on each removal) is O(n²). Two-pointer eliminates the inner loop entirely.

**Why O(n)?** Each element is visited by the fast pointer exactly once. The slow pointer only advances (never retreats). Total pointer moves ≤ 2n.

---

## SECTION 9: FLOYD'S CYCLE DETECTION (Special Case)

Used on linked lists / implicit graphs. Slow moves 1 step, fast moves 2 steps.
- If there's a cycle, fast catches up to slow inside the cycle.
- If no cycle, fast reaches null first.

**Detection:** `slow == fast` inside loop → cycle.
**Cycle start:** After detection, reset slow to head, move both 1 step — they meet at cycle start.

This is same-direction two pointers where the "speed ratio" encodes the structural property.

---

## SECTION 10: PATTERN DECISION FLOWCHART

```
Problem needs O(n) array scan?
  └─ Both pointers go right?
       └─ One reads all, one tracks "boundary"?
            └─ SAME-DIRECTION TWO POINTERS ✓
  └─ Window with sum/count condition?
            └─ SLIDING WINDOW (same-direction variant) ✓
  └─ Pointers come from both ends?
            └─ OPPOSITE-DIRECTION TWO POINTERS (Day 2)
```

---

## SECTION 11: REVISION SHEET

### Rules
1. **Fast always moves.** Slow moves only on condition.
2. **Return `slow` as new length** (or `slow+1` if 0-indexed last position).
3. **Test:** empty, single, all-same, none-removed, all-removed.
4. **Sliding window** = same-direction + left shrinks on violation.
5. **Write before or after incrementing slow** — pick consistent convention.

### Key Formulas
```
new_length = slow          // after filtering
arr[slow++] = arr[fast]   // write then advance
arr[slow] = arr[fast]; slow++ // same thing
if keep: arr[slow++] = arr[fast]
```

### Traps
- 🚨 `slow` initialized wrong (0 vs 1 vs start of second array)
- 🚨 Comparing to `arr[slow]` vs `arr[slow-1]`
- 🚨 Not returning `slow` as new length
- 🚨 Using extra O(n) array when in-place is possible
- 🚨 Breaking the "fast always moves" rule
