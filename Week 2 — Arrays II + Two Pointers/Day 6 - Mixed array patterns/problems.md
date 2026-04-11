# Day 6: Mixed Array Patterns — Problem Set

---

## Problem 1: Majority Element ⭐ Easy (LC 169)
**Statement:** Array of size n. Find the element appearing > `n/2` times. Guaranteed to exist.
**Example:** `[2,2,1,1,1,2,2]` → `2`
**Pattern:** Boyer-Moore Voting. O(n), O(1) space.

---

## Problem 2: Majority Element II ⭐⭐ Medium (LC 229)
**Statement:** Find all elements appearing > `n/3` times.
**Example:** `[3,2,3]` → `[3]`
**Pattern:** Boyer-Moore extended. Keep 2 candidates and 2 counts. If a third element arrives, decrement both counts. Second pass required!

---

## Problem 3: Top K Frequent Elements ⭐⭐ Medium (LC 347)
**Statement:** Find top K most frequent elements. Time must be better than O(n log n).
**Example:** `[1,1,1,2,2,3], k=2` → `[1,2]`
**Pattern:** Hash map to count freq → Array of lists as buckets (index = freq) → traverse back to front.

---

## Problem 4: Merge Intervals ⭐⭐ Medium (LC 56)
**Statement:** Array of intervals where `intervals[i] = [start_i, end_i]`. Merge all overlapping intervals.
**Example:** `[[1,3],[2,6],[8,10],[15,18]]` → `[[1,6],[8,10],[15,18]]`
**Pattern:** Sort by start. Iterate, updating `.back()[1] = max(...)` on overlap.

---

## Problem 5: Insert Interval ⭐⭐ Medium (LC 57)
**Statement:** Insert newInterval into sorted, non-overlapping intervals and merge if needed.
**Example:** `[[1,2],[3,5],[6,7],[8,10],[12,16]], new = [4,8]` → `[[1,2],[3,10],[12,16]]`
**Pattern:** 3 phases: 1) add strictly before, 2) merge overlapping into one `newInterval`, 3) add strictly after.

---

## Problem 6: Meeting Rooms II ⭐⭐ Medium (LC 253)
**Statement:** Array of meeting time intervals. Find min number of conference rooms required.
**Example:** `[[0,30],[5,10],[15,20]]` → `2`
**Pattern:** Sweep-line (Events). Start times +1, End times -1. Calculate running sum max.

---

## Problem 7: H-Index ⭐⭐ Medium (LC 274)
**Statement:** Given citation counts. H-index `h` means `h` papers have ≥ `h` citations. Maximum possible `h`.
**Example:** `[3,0,6,1,5]` → `3`
**Pattern:** Counting sort. Papers with `>n` citations can be capped at `n`. Keep array `count` of size `n+1`. Iterate backward calculating running sum.

---

## Problem 8: Next Greater Element III ⭐⭐⭐ Hard (LC 556)
**Statement:** Convert integer to digit array. Find smallest integer > `n` with same digits.
**Pattern:** This is EXACTLY `Next Permutation` (Day 3), applied to the digits of a 32-bit integer. Return -1 if not possible or overflows.

---

## Problem 9: Summary Ranges ⭐ Easy (LC 228)
**Statement:** Return smallest sorted list of ranges covering all numbers in array exactly.
**Example:** `[0,1,2,4,5,7]` → `["0->2","4->5","7"]`
**Pattern:** Two pointers / `while` loop keeping track of start and advancing `i` while `nums[i] == nums[i-1] + 1` (Careful of overflow!).

---

## Problem 10: Task Scheduler ⭐⭐ Medium (LC 621)
**Statement:** Array of character tasks. CPU must idle for `n` intervals if executing same task again. Find min intervals to finish.
**Example:** `tasks=["A","A","A","B","B","B"], n=2` → `8` (`A->B->idle->A->B->idle->A->B`)
**Pattern:** Math. `(max_freq - 1) * (n + 1) + num_tasks_with_max_freq`. Max between that and `tasks.length`.
