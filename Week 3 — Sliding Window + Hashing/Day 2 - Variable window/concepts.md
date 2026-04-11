# Day 2: Variable Sliding Window

---

## SECTION 1: WHAT IS A VARIABLE SLIDING WINDOW?

Unlike Day 1 where the size of the window was fixed to `k`, a **variable sliding window** expands and shrinks dynamically to satisfy a specific condition.

You want to find the **longest/shortest** subarray or substring that meets some constraint (e.g., "subarray sum >= 7", or "contains exactly K distinct characters").

**The Core Idea:**
Two pointers, `left` and `right`, both start at `0`.
- Expand the window by conditionally moving `right` and adding `a[right]` to the state.
- If the current window *violates* the condition (or if we need to minimize), we shrink the window from the left by moving `left` strictly forward and removing `a[left]` from the state.

---

## SECTION 2: THE UNIVERSAL TEMPLATE

Memorize this exactly. Almost every variable window problem uses this loop structure:

```cpp
int variableWindow(vector<int>& nums) {
    int left = 0, right = 0;
    int state = 0; // sum, hash map, etc.
    int best = 0; // MAX_INT if seeking minimum length
    
    while (right < nums.size()) {
        // 1. ADD incoming element nums[right] to state
        state += nums[right];
        
        // 2. SHRINK window while the condition is violated
        // (If seeking minimum length, shrink WHILE condition IS satisfied)
        while (/* condition violated */) {
            // Remove left element from state
            state -= nums[left];
            left++;
        }
        
        // 3. CAPTURE optimal result
        best = max(best, right - left + 1); // Or min
        
        // 4. EXPAND right
        right++;
    }
    
    return best;
}
```

---

## SECTION 3: FINDING THE LONGEST VS FINDING THE SHORTEST

### Goal: Longest Window (e.g., Longest Substring Without Repeating Chars)
- Expand `right` to gather more elements.
- When the window becomes invalid (e.g., duplicate found), shrink `left` *until* valid again.
- **Capture max length** AFTER the `while` loop (when the window is guaranteed valid).

### Goal: Shortest Window (e.g., Minimum Size Subarray Sum)
- Expand `right` to gather elements.
- When the window BECOMES valid (e.g., `sum >= target`), try to optimize it by shrinking `left`.
- **Capture min length** INSIDE the `while` loop, right before you move `left`!

---

## SECTION 4: THE MAP STATE (CHARACTER FREQUENCIES)

Strings inherently deal with counts. State is usually an `unordered_map<char, int>` or `int count[128]`.

**"At most K distinct characters"**:
```cpp
count[s[right]]++;
if (count[s[right]] == 1) distinct++; // new distinct char!

while (distinct > K) {
    count[s[left]]--;
    if (count[s[left]] == 0) distinct--; // char fully removed!
    left++;
}
```
*Crucial*: Only decrement `distinct` when a character's count hits exactly 0.

---

## SECTION 5: COMMON MISTAKES AND PITFALLS

1. **Negative Numbers**:
   Wait, if you are looking for `sum >= target` and the array has negative numbers, CAN YOU USE SLIDING WINDOW?
   **NO!** If an array has negative numbers, expanding `right` might DECREASE the sum, breaking the monotonic property that makes sliding windows work. You must use Prefix Sum + HashMap (Day 5).
   *Rule: Pure Sliding window for sum requires POSITIVE arrays.*

2. **Capturing length at the wrong time/place**:
   - `longest`: `max(ans, right - left + 1)` outside `while` loop.
   - `shortest`: `min(ans, right - left + 1)` inside `while` loop.

3. **Subarray combinations**:
   If a problem asks for "Total Number of Subarrays with exactly K distinct", sliding window for "exactly K" is hard. 
   Math trick: `Exact(K) = AtMost(K) - AtMost(K - 1)`. Use sliding window to find "At Most K".

---

## SECTION 6: REVISION SHEET (MEMORIZE)

**Variable Window Checklist:**
1. Can expanding right break the condition? -> Shrink left!
2. Are array elements strictly non-negative? (If not, sliding window sum fails).
3. Update state for `right`.
4. While (state is invalid/valid), update state for `left`, `left++`.
5. Capture `longest` after while. Capture `shortest` inside while.
6. `right++`.
