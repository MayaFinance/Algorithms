# 📝 Problem Set: Prefix Sum Applications

This document outlines the core challenges that leverage cumulative data states.

---

## 1. Range Sum Query - Immutable
**Pattern:** Static Array Optimization
**Description:** Answer multiple queries giving the sum of elements structurally between indices `L` and `R`.
*   **Approach:** Construct $P[i]$. For every query, return $P[R] - P[L-1]$. Use an $N+1$ array to elegantly bypass $L=0$ checks.

---

## 2. Running Sum of 1D Array
**Pattern:** Idempotent Transformation
**Description:** Calculate tracking cumulative state over time (e.g., S[i] = S[i-1] + nums[i]).
*   **Approach:** Mutate $O(1)$ space in-place: `nums[i] += nums[i-1]`.

---

## 3. Subarray Sum Equals K
**Pattern:** Prefix Sum + Hash Map (Frequency)
**Description:** Count continuous subarrays summing to exactly $K$.
*   **Approach:** Track running `sum`. If `sum - K` exists in the hash map, add its frequency to `count`. Map `(sum, frequency)`. Treat map initialization with `{0: 1}` to handle subarrays starting precisely at index 0.

---

## 4. Continuous Subarray Sum
**Pattern:** Modular Congruence
**Description:** Find if a subarray of length $\ge 2$ sums to a multiple of $k$.
*   **Approach:** Track running `sum % k`. Map `(remainder, FIRST_seen_index)`. If `remainder` is seen again at distance $\ge 2$, return true. 

---

## 5. Maximum Size Subarray Sum Equals K
**Pattern:** Prefix Sum + Hash Map (Earliest Index)
**Description:** Find the maximum length of a subarray summing to $K$.
*   **Approach:** Map `(sum, FIRST_seen_index)`. If `sum - K` exists, calculate $i - \text{map}[sum - K]$ and maximize the length. Do NOT update the map with new indices if `sum` is already seen to ensure maximum width.

---

## 6. Binary Subarrays with Sum
**Pattern:** At-Most Trick vs Hash Map
**Description:** Array of `0`s and `1`s. Find number of subarrays with sum $K$.
*   **Approach:** Can use Prefix+Map exactly like Problem 3. Alternatively, $O(1)$ space using `CountAtMost(K) - CountAtMost(K-1)`. The Map approach applies generally to negatives, while Sliding Window relies on monotonic property of absolute positives/zeros.

---

## 7. Contiguous Array
**Pattern:** Parity Balancing
**Description:** Find the max length subarray with an equal number of `0`s and `1`s.
*   **Approach:** Treat `0` as `-1`. Track running `sum`. Looking for a subarray with sum `0` means we search the Hash Map for the earliest index where we saw the *same* running sum.

---

## 8. Number of Submatrices That Sum to Target
**Pattern:** 2D to 1D Compression
**Description:** In a 2D matrix, find the number of submatrices summing to target.
*   **Approach:** Fix `top` and `bottom` rows ($O(R^2)$). For these rows, compress columns into a 1D array. Run 1D "Subarray Sum Equals K" ($O(C)$). Total time $O(R^2 \times C)$.

---

## 9. Maximum Average Subarray II
**Pattern:** Binary Search on Answer + Prefix Sum
**Description:** Find max average of a subarray of length $\ge K$.
*   **Approach:** Binary search the `avg`. To test if `avg` is feasible, subtract `avg` from all elements. Does a subarray of length $\ge K$ sum to $\ge 0$? Use prefix sums tracking the `min_prefix` seen at least $K$ indices ago. $O(n \log(\text{range}))$.

---

## 10. Corporate Flight Bookings
**Pattern:** 1D Difference Array
**Description:** Given bookings `[first, last, seats]`, return an array with total seats booked per flight.
*   **Approach:** For each booking, create a difference array: `D[first] += seats`, `D[last+1] -= seats`. Construct final array by taking the prefix sum of $D$.

---

## 11. Car Pooling
**Pattern:** Difference Array Sweep-line
**Description:** Check if a car can pick up and drop off passengers successfully without exceeding capacity along a single route.
*   **Approach:** `D[start] += passengers`, `D[end] -= passengers`. Calculate running sum of $D$. If running sum $>$ capacity at any point, return false.
