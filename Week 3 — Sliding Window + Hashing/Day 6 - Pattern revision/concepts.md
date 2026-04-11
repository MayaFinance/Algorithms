# Day 6: Pattern Revision & Synthesis

---

## SECTION 1: THE FOUR PILLARS OF WEEK 3

You have learned four distinct architectures this week. Interviews often mask them. If you misidentify which pattern to use, you will be stuck before writing a single line of code.

Here is the decision tree:

1. **Does the problem specify an EXACT subarray length `K`?**
   $\rightarrow$ Use **Fixed Sliding Window** (Day 1).
   $\rightarrow$ Build window of size `K`, then loop `add right`, `remove left-K`.

2. **Are you asked to find the MIN/MAX length of a subarray meeting a condition, and are all array values strictly non-negative?**
   $\rightarrow$ Use **Variable Sliding Window** (Day 2).
   $\rightarrow$ `while(invalid) { remove left; left++; }`

3. **Are you simply counting distinct elements or matching characters?**
   $\rightarrow$ Use **Frequency Maps** (Day 3).
   $\rightarrow$ Use flat array `int count[128]` for strings to guarantee `O(1)` time without collisions.

4. **Are you asked to find the NUMBER of subarrays meeting a sum condition, or does the array contain NEGATIVE numbers?**
   $\rightarrow$ Use **Prefix Sum + Hash Map** (Day 5).
   $\rightarrow$ `map[0] = 1; ans += map[sum - k]`

---

## SECTION 2: THE "AT MOST" TRICK (SYNTHESIS)

We saw this in Day 2 for Subarrays with exactly K distinct characters.
Finding "exactly K" using a sliding window directly is incredibly complex because moving left to break EXACT K might instantly ruin the combination.

**The Golden Formula:**
`Exact(K) = AtMost(K) - AtMost(K - 1)`

You use a sliding window to count all valid subarrays with $\leq K$ traits. You do it again for $\leq K-1$. The difference is strictly EXACTLY $K$.

---

## SECTION 3: THE "INVERSE" WINDOW TRICK

If you are asked to "Remove operations from the left or right to meet a target constraint", this is a psychological trap.

You cannot use a sliding window on the "ends" of an array.
Instead, invert the problem:
"Find the minimum elements from left and right to equal `X`"
$\rightarrow$ "Find the **longest subarray in the middle** that equals `Total_Sum - X`"

Now you have a standard Variable Sliding Window (if non-negative) or Prefix Hash Map problem!

---

## SECTION 4: ROLLING HASH VS SLIDING WINDOW

Sliding Window keeps a dynamic "sum" or "object count".
A **Rolling Hash** (Rabin-Karp) keeps a cryptographic signature of the string so you can directly compare string equality in `O(1)` time instead of `O(K)`.

If you are sliding over substrings and need to check if the substring exactly matches another string, you should ideally use a Rolling Hash (Day 4) to avoid the `O(K)` overhead of `string::substr` comparison.

---

## SECTION 5: DEBUGGING CHECKLIST

If your output is wrong:
1. **Did you initialize `max_ans` to `INT_MIN`?** (If you set it to `0`, negative answers will fail).
2. **Did you add `map[0] = 1` for prefix hash maps?** (If not, subarrays starting exactly from index `0` won't be counted).
3. **If using Codeforces/Competitive Programming, did you use C++ `unordered_map`?** (Switch to `map` or use custom Anti-Hash salt, otherwise collision attacks will TLE your code).
4. **Is your Variable Sliding Window capturing length at the correct time?** `Min` -> Inside loop. `Max` -> Outside loop.
