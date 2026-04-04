# 📝 Problem Set: Array Mastery

This document segregates the classic array problems discussed in the text. Master these core mechanics.

---

## Problem 1: Two Sum
**Pattern:** Hashing vs. Two-Pointer Trade-offs
**Description:** Find the indices of two elements in an array that sum to a specific target.

*   **Approach A: Hash Map ($O(n)$ Time, $O(n)$ Space)**
    Iterate through the array. For each `nums[i]`, check if `target - nums[i]` exists in the hash map. If yes, return the pair. If not, store `{nums[i], i}`. Ideal for unsorted arrays where original indices must be returned.
*   **Approach B: Two-Pointer ($O(n \log n)$ Time, $O(1)$ Space)**
    If sorted (or returning values instead of indices), place `left` at $0$ and `right` at $n-1$. If `sum < target`, `left++`. If `sum > target`, `right--`.

---

## Problem 2: Remove Element
**Pattern:** Fast-Slow Pointer / In-Place Modification
**Description:** Remove all instances of a specific value `val` from an array in-place, returning the new length.

*   **Approach:** Maintain a `write_ptr` (slow) that increments only when the `read_ptr` (fast) encounters an element $\neq$ `val`. Copy "good" elements to `nums[write_ptr]`.

---

## Problem 3: Move Zeroes
**Pattern:** Fast-Slow Pointer Swaps / In-Place Modification
**Description:** Push all zeros to the end of an array while maintaining the relative order of non-zeros.

*   **Approach:** Use a slow pointer for the next available non-zero slot and a fast pointer to hunt for non-zeros. Swap `nums[slow]` and `nums[fast]` whenever a non-zero is found, bubbling zeroes back.

---

## Problem 4: Beautiful Matrix
**Pattern:** Geometric and Mathematical Indexing
**Description:** You have a 5x5 grid with a single `1` and the rest `0`s. Using adjacent swaps, move the `1` to the center `(2, 2)` (0-indexed). Return the minimum moves.

*   **Approach:** The optimal solution is the **Manhattan Distance** between the current coordinate $(r, c)$ and $(2, 2)$. Moves = $|r - 2| + |c - 2|$.

---

## Problem 5: Even Odds
**Pattern:** Mathematical Direct Calculation
**Description:** Find the $k$-th number in a sequence of $1 \ldots n$ where all odd numbers are listed before all evens. Constraints: $n \le 10^{12}$.

*   **Approach:** Since $O(n)$ memory allocation is impossible, purely calculate it.
    *   `count_odd = (n + 1) / 2`.
    *   If $k \le \text{count\_odd}$, it is the $k$-th odd: `2 * k - 1`.
    *   Else, it's the $(k - \text{count\_odd})$-th even: `2 * (k - count_odd)`.

---

## Problem 6: Majority Element
**Pattern:** Boyer-Moore Voting
**Description:** Find the element that appears more than $\lfloor n/2 \rfloor$ times.

*   **Approach:** Maintain a `candidate` and a `count`. If `count == 0`, pick the next element as `candidate`. If `nums[i] == candidate`, `count++`, else `count--`. The majority survives all cancellations. $O(n)$ time, $O(1)$ space.

---

## Problem 7: Find Pivot Index
**Pattern:** Prefix and Suffix Transformations
**Description:** An index is a pivot if the sum of elements left of it equals the sum to the right.

*   **Approach:** Precalculate `total_sum`. Maintain a running `left_sum`. At any index $i$, `right_sum = total_sum - left_sum - nums[i]`. Single $O(n)$ pass.

---

## Problem 8: Product of Array Except Self
**Pattern:** Prefix/Suffix Array Mixing
**Description:** Calculate the product of all elements except `nums[i]` without using division, in $O(n)$ time.

*   **Approach:** 
    1. Build `res` where `res[i]` is the product of all elements left of $i$.
    2. Traverse backwards, maintaining a running `suffix_product`, multiplying `res[i]` by `suffix_product` and updating it.

---

## Problem 9: Missing Number
**Pattern:** Bitwise Logic ($XOR$)
**Description:** Find the single missing number in the range $[0, n]$.

*   **Approach A:** Mathematical Sum: $\frac{n(n+1)}{2} - \sum \text{nums}$. Prone to integer overflow.
*   **Approach B:** XOR. $x \oplus x = 0$. XOR all numbers $0$ to $n$, then XOR with all elements in `nums`. The remaining value is the missing number. Completely immune to overflow.

---

## Problem 10: Rotate Array
**Pattern:** The Reversal Algorithm
**Description:** Rotate an array right by $k$ positions in $O(1)$ space.

*   **Approach:** The Triple Reverse Trick (`k = k % n`).
    1. Reverse the entire array.
    2. Reverse the first $k$ elements.
    3. Reverse the remaining $n-k$ elements.

---

## Problem 11: Merge Sorted Array
**Pattern:** The Reverse Merge Trick
**Description:** Merge two sorted arrays `nums1` and `nums2` inside `nums1`. `nums1` has enough zeros at the end to hold `nums2`.

*   **Approach:** Merge from right to left. Use three pointers ($p1$ at end of `nums1` valid data, $p2$ at end of `nums2`, $p$ at end of `nums1` total size). Compare and place the largest element at $p$, decrementing the respective pointers.

---

## Problem 12: Sort Colors (Dutch National Flag)
**Pattern:** Multi-Pointer Partitioning
**Description:** Sort an array of `0`s, `1`s, and `2`s in-place in a single pass.

*   **Approach:** Three pointers: `low` (boundary for 0s), `mid` (current), `high` (boundary for 2s).
    *   If `nums[mid] == 0`: `swap(low, mid)`. Increment both.
    *   If `nums[mid] == 1`: Increment `mid`.
    *   If `nums[mid] == 2`: `swap(mid, high)`. Decrement `high`. Do **not** increment `mid` since the newly swapped-in element must be checked.
