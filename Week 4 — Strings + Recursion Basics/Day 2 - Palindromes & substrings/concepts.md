# Concepts: Palindromes and Substrings

## 1. The Anatomy of a Palindrome

A palindrome exhibits **perfect symmetry**. Recognizing this symmetry is the key to solving palindrome problems.

- **Two Pointers:** Place one pointer at the start and one at the end. Move inward. If they cross without mismatch, it's a palindrome. (Time: $O(N)$, Space: $O(1)$)
- **Even vs. Odd Lengths:** 
  - Odd lengths have a unique single center character (`"a b a"` center is 'b').
  - Even lengths have a center *between* two characters (`"a b b a"` center is between the two 'b's).

## 2. The "Expand Around Center" Technique

Instead of checking if every possible substring is a palindrome (which is $O(N^3)$), we iterate through each possible *center* and expand outwards.

- **Centers:** A string of length $N$ has $2N - 1$ possible centers (each character and each space between characters).
- **Time Complexity:** $O(N^2)$ — there are $O(N)$ centers, and expanding takes at most $O(N)$ time. Space is $O(1)$.

## 3. Substrings & Sliding Window

A substring is a contiguous sequence of characters. Whenever a problem asks for the "longest/shortest substring with condition X", always think **Sliding Window**.

**The Pattern:**
- Use `left` and `right` pointers.
- Expand the window by moving `right` until the condition is violated.
- Shrink the window by moving `left` until the condition is valid again.
- Keep track of global maximum or minimum.
- Use a hash map, frequency array, or bitmask to evaluate the condition in $O(1)$ time.

## 4. Introduction to Palindrome DP

Dynamic Programming applies naturally to palindromes because *subproblems overlap*.
- **State:** `dp[i][j]` is `true` if the substring `s[i...j]` is a palindrome.
- **Base Cases:**
  - Length 1: `dp[i][i] = true`.
  - Length 2: `dp[i][i+1] = (s[i] == s[i+1])`.
- **Transitions:** For length $\ge 3$, `dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]`.
- This evaluates all palindromic substrings in exactly $O(N^2)$ time and $O(N^2)$ space.

## 5. Manacher's Algorithm (Advanced Intro)

Finding the Longest Palindromic Substring in $O(N^2)$ via expanding around the center is great, but what if $N = 10^5$? Manacher's Algorithm achieves $O(N)$ time.

**The Intuition:**
Manacher's takes advantage of preexisting palindromes. If we know a large palindrome exists around center $C$, and we want to find a palindrome around a new center $i$ (where $i > C$), we can use the mirror image of $i$ (let's call it $i'$) across $C$. 
The length of the palindrome at $i$ is at least the length of the palindrome at $i'$, bounded by the right edge of the large palindrome at $C$.

**Key Steps:**
1. **Transform String:** Insert dummy characters (like `#`) between every letter so even/odd lengths are treated uniformly. `"aba"` $\rightarrow$ `"#a#b#a#"`.
2. **Track Bounds:** Keep a `center` and `right_boundary` of the palindrome extending furthest to the right.
3. **Mirror Lookup:** When finding the expansion radius at $i$, initialize it to the pre-computed radius at its mirror $i'$, capped by `right_boundary - i`.
4. **Expand:** Only expand beyond this initial radius.
