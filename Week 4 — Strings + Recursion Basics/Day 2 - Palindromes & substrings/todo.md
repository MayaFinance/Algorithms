# To-Do: Palindromes and Substrings

## 1. Conceptual Mastery
- [ ] Understand the symmetry and pointers necessary for palindrome checking.
- [ ] Grasp why Expand Around Center is $O(N^2)$ and how to handle even/odd length centers.
- [ ] Internalize the Sliding Window pattern for substring constraints.
- [ ] Understand the state definition for Palindrome DP: `dp[i][j] = s[i]==s[j] && dp[i+1][j-1]`.
- [ ] (Advanced) Visualize how Manacher's Algorithm skips symmetric redundant checks.

## 2. Implementation Check
- [ ] **P1:** Valid Palindrome
- [ ] **P2:** Valid Palindrome II
- [ ] **P3:** Longest Palindrome
- [ ] **P4:** Longest Substring Without Repeating Characters
- [ ] **P5:** Longest Repeating Character Replacement
- [ ] **P6:** Palindromic Substrings
- [ ] **P7:** Longest Palindromic Substring (Expand Around Center / DP)
- [ ] **P8:** Repeated DNA Sequences
- [ ] **P9:** Palindrome Partitioning
- [ ] **P10:** Longest Palindromic Substring (Manacher's Algorithm $O(N)$)

## 3. Review & Debugging
- [ ] **Edge Cases:** Did you handle `0` or `1` length bounds?
- [ ] **Out of Bounds:** Did you properly enforce `l >= 0` and `r < n` during center expansion?
- [ ] **Sliding Window State:** In sliding window, are you removing the `s[left]` character state accurately from your map/array before `left++`?
- [ ] **DP Order:** In Palindrome DP, are you iterating lengths first or iterating `i` from $N-1$ down to $0$? (Inner structures matter!)
