# Day 1: Fixed Sliding Window

---

## SECTION 1: WHAT IS A SLIDING WINDOW?

A **sliding window** is a subset of contiguous elements in an array or string. 
Instead of recalculating information for overlapping subarrays from scratch (which takes `O(n²)` or `O(n*k)` time), we maintain the state of the window. When the window "slides" right by one element:
1. We add the effect of the new element entering the window from the right.
2. We remove the effect of the old element leaving the window from the left.

This brings overlapping subarray array/string iterations down to **O(n)** time.

---

## SECTION 2: THE FIXED WINDOW TEMPLATE

When the problem explicitly states the subarray length is fixed to size `k` (e.g., "max sum of subarray of size k", "substring of length k").

**Characteristics:**
- The distance between `left` and `right` is always exactly `k` (once the window is hit).
- We first build the initial window of size `k`.
- Then, for the rest of the array, we slide: `add right, remove left, left++, right++`.

**The Standard Template:**

```cpp
int maxSubarraySum(vector<int>& a, int k) {
    if (a.size() < k) return -1; // Edge case
    
    int window_sum = 0, max_sum = 0;
    
    // Step 1: Build the first window of size k
    for (int i = 0; i < k; i++) {
        window_sum += a[i];
    }
    max_sum = window_sum;
    
    // Step 2: Slide the window
    for (int i = k; i < a.size(); i++) {
        // Add new element entering the window, remove old element leaving
        window_sum = window_sum + a[i] - a[i - k];
        max_sum = max(max_sum, window_sum);
    }
    
    return max_sum;
}
```

---

## SECTION 3: WHEN TO USE IT

**Trigger keywords:**
- "Maximum / Minimum / Average sum of subarray of size K"
- "Given a string, find anagrams of length equal to pattern"
- "Count occurrences of size K"
- "First negative integer in every window of size K"

**If the size is NOT given explicitly**, it is a *Variable* sliding window (Day 2).

---

## SECTION 4: STATE MANAGEMENT (THE TRICKY PART)

In simple cases (like max sum), the "state" is just an integer `sum`.
In harder cases, the state is more complex:
- **A frequency map or array**: Keep an array `count[26]` to track characters in the current window of length `k`.
- **A doubly-ended queue (deque)**: To efficiently find the maximum/minimum inside a window (Sliding Window Maximum).
- **A queue**: To track the positions of specific elements (e.g., negative numbers).

Whenever rolling the window:
1. Update state with `a[i]` (incoming).
2. Update state with `a[i-k]` (outgoing).

---

## SECTION 5: COMMON MISTAKES AND PITFALLS

1. **Off-by-one errors with `i-k`**: 
   When sliding, if `i` is the new element entering the window, the element that falls out is exactly `a[i - k]`.
   *Example:* array of length 5, k=3. 
   First window: indices 0,1,2.
   Next `i`=3. We add `a[3]` and remove `a[3-3] = a[0]`.

2. **Forgetting to check condition after first window:**
   Some people build the window and start looping but forget to check or record the answer for the very first window!

3. **Array smaller than k:**
   Always handle `if (a.size() < k)` right at the start.

4. **Negative sliding windows:**
   If asked for maximum sum, initialize `max_sum` to `INT_MIN` (or `-inf`), NOT `0`, because the max sum might be negative!

---

## SECTION 6: REVISION SHEET (MEMORIZE)

**Fixed Sliding Window Checklist:**
1. Check `n < k`.
2. Construct the first window manually covering `0` to `k-1`.
3. Capture initial state for the first window.
4. Loop from `i = k` to `n-1`.
5. Update state: `state += a[i]`, `state -= a[i-k]`.
6. Capture best state.

*Complexity:* Time O(n), Space config-dependent (O(1) for sums, O(K) for queues).
