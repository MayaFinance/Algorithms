# Day 5: Subarray Counting Problems

---

## SECTION 1: THE LIMITATION OF SLIDING WINDOW

Sliding Window logic mathematically breaks down if expanding the window can *both* increase OR decrease the target condition indiscriminately.

**Rule:** You CANNOT use a standard Sliding Window to find `Subarray Sum == Target` IF the array contains negative numbers.
Why? Because `sum` loses its monotonic property. If the sum is `8` and target is `5`, a sliding window wants to shrink `left`. But what if the very next element on the right is `-3`? Expanding right WOULD have given us `5`. Sliding window cannot predict this.

---

## SECTION 2: THE PREFIX SUM + HASH MAP PATTERN

When asked to find the **number of subarrays** / **length of subarray** that meet a sum condition, use Prefix Sums with a Hash Map.

A **Prefix Sum** at `i` is the sum of `nums[0...i]`.
The sum of a subarray spanning index `j` to `i` is:
`SubarraySum(j, i) = PrefixSum(i) - PrefixSum(j - 1)`

If we want to find if there is a subarray that equals `k`:
`k = PrefixSum(i) - PrefixSum(j - 1)`
Rearranging the formula:
`PrefixSum(j - 1) = PrefixSum(i) - k`

**The Algorithm (Continuous Subarray Sum == K):**
1. Iterate through array accumulating `prefix_sum`.
2. Assume the current `prefix_sum` is `PrefixSum(i)`.
3. Check using `O(1)` Hash Map if we have ever seen a prefix sum equal to `PrefixSum(i) - k` in the past.
4. Add the frequency of that past prefix sum to our `ans` count.
5. Add the current `prefix_sum` to the Hash Map.

---

## SECTION 3: THE MOST CRITICAL LINE OF CODE

Before the loop starts, you MUST seed the Hash Map:
```cpp
unordered_map<int, int> prefix_counts;
prefix_counts[0] = 1; // Extremely important
```
Why? If a subarray starting from index `0` up to `i` exactly adds up to `k`, then `PrefixSum(i) - k` will be `0`. We need the map to acknowledge that an empty prefix sum of `0` exists exactly ONE time initially.

---

## SECTION 4: THE UNIVERSAL TEMPLATE

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_counts;
    prefix_counts[0] = 1; // Base case
    
    int prefix_sum = 0, count = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        prefix_sum += nums[i];
        
        // Have we seen (prefix_sum - k) before?
        int target = prefix_sum - k;
        if (prefix_counts.count(target)) {
            count += prefix_counts[target];
        }
        
        // Store current sum
        prefix_counts[prefix_sum]++;
    }
    
    return count;
}
```

---

## SECTION 5: MODULAR ARITHMETIC VARIANTS (Divisibility)

What if the target is "Subarray Sum Divisible by `K`"?
If `SubarraySum(j, i) % K == 0`, then:
`(PrefixSum(i) - PrefixSum(j-1)) % K == 0`
Which mathematically means:
`PrefixSum(i) % K == PrefixSum(j-1) % K`

**The Pattern:**
1. Maintain `running_sum % K`.
2. Check Hash Map to see if we've seen this exact remainder before.
3. If we have, add its count to `ans`.

*Fixing negative remainders in C++ / Java:*
`int rem = (prefix_sum % k + k) % k;`

---

## SECTION 6: ODD/EVEN PARITY VARIANTS

What if the target involves counts of properties? e.g., "Equal numbers of 0s and 1s".
**The Trick:** Translate properties into +1 and -1.
- Replace `0` with `-1`, keep `1` as `1`.
- Now the problem is identical to: "Find longest subarray with sum == 0". Use Prefix Sum + Hash Map (storing the *earliest index* it was seen instead of frequencies).

---

## SECTION 7: REVISION SHEET (MEMORIZE)

1. Negative numbers + Subarray sums $\rightarrow$ You MUST use Prefix Sum + HashMap.
2. Magic Formula: `PrefixSum(i) - K` must exist in the map.
3. Divisibility Magic Formula: `PrefixSum(i) % K` must exist in the map (handle negative modulos).
4. Equal 0s and 1s $\rightarrow$ change to `-1` and `1`, search for `target = 0`.
5. ALWAYS initialize `map[0] = 1` for counting, or `map[0] = -1` for lengths!
