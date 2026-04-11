# Day 6: Mixed Array Patterns

---

## SECTION 1: THE "BUCKET SORT" / FREQUENCY ARRAY PATTERN

When values in the array are bounded by a small range `[0, k]` or we are counting frequencies, we can use an array of size `k` to count them.

**Key Triggers:**
- Elements are small (e.g., ages `0-120`, characters `a-z`, test scores `0-100`).
- "Find the top K frequent elements" (bucket sort by frequency).
- "H-Index" calculation.

**How it works (Top K Frequent):**
1. Count frequencies using a Hash Map: `x -> freq`.
2. Create an array of lists (buckets) where the index is the frequency. `buckets[freq]` contains a list of elements with that frequency.
3. Iterate from the back of the buckets array (highest frequency down to 0) to gather the top K elements.
*Time: O(n), Space: O(n)*

---

## SECTION 2: THE "MAJORITY ELEMENT" (BOYER-MOORE VOTING)

Finding an element that appears strictly MORE than `n/2` times.

**The Algorithm:**
Maintain a `candidate` and a `count`.
- If `count == 0`, `candidate = a[i]`, `count = 1`.
- If `a[i] == candidate`, `count++`.
- If `a[i] != candidate`, `count--`.

**Why it works:**
The majority element appears more than all other elements combined. Every time we pair a majority element with a non-majority element and "cancel" them out (`count--`), the majority element will STILL be left over.

*Note:* If the problem doesn't guarantee a majority element exists, you MUST do a second pass to verify the `candidate` actually appears `> n/2` times.
*Time: O(n), Space: O(1)*

---

## SECTION 3: INTERVALS (MERGING & INTERSECTIONS)

Interval problems `[start, end]` are everywhere.

**Golden Rule:** ALMOST ALWAYS sort the intervals by their start time.
```cpp
sort(intervals.begin(), intervals.end()); // sorts by first element natively in C++
```

**Pattern: Merge Overlapping Intervals:**
1. Sort by start.
2. Push `intervals[0]` to `res`.
3. Try to merge `intervals[i]` with the last interval in `res`.
   - If `intervals[i].start <= res.back().end`: overlap! Update `res.back().end = max(res.back().end, intervals[i].end)`.
   - Else: push `intervals[i]` to `res`.

**Pattern: Insert Interval:**
Find where it belongs, insert it, then run the merge logic (or handle before/merge/after explicitly).

---

## SECTION 4: THE SWEEP LINE (OR PREFIX SUM ON INTERVALS)

Also known as the "Events" or "Meeting Rooms II" pattern.
You have `n` intervals `[start, end]`. How many overlap at any point? What is the max overlap?

**Method 1: Events mapping (Difference Array logic)**
- Create an event `(start, +1)`
- Create an event `(end, -1)`
- Sort all events by time. (If times match, process `-1` before `+1` to free up spaces).
- Keep a running sum. The maximum running sum is the max overlap.

*Time: O(n log n)* due to sorting events.

---

## SECTION 5: 2D MATRIX TRICKS (ROW/COL SUMS)

When dealing with simple games or grids (like Tic-Tac-Toe or determining row/col validity):
Don't use a full 2D array if you only need the aggregate.

Instead, track `rowSum[n]` and `colSum[n]`.
For a grid of `+1` and `-1`, if `rowSum[i] == n`, someone won.

---

## SECTION 6: THE "TRAP" SUMMARY

1. **Top K Elements:** People instinctively use a Priority Queue (Heaps) O(n log k). If frequencies are bounded by `n`, Bucket Sort by frequency is strictly O(n)!
2. **Intervals:** Forgetting to update the end of the merged interval to `max(current_end, new_end)`. (e.g., `[1, 5]` and `[2, 3]` -> merged is `[1, 5]`, NOT `[1, 3]`).
3. **Voting Algorithm:** Using Boyer-Moore when the target is `n/3`. You need TWO candidates and two counts for `n/3`.
