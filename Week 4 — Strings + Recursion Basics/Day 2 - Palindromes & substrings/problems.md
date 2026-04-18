# Problem Set: Palindromes and Substrings

These 10 problems progressively build your mastery over string segments (substrings) and symmetrical patterns (palindromes).

---

### **P1: Valid Palindrome (LC 125)**
- **Difficulty:** Easy
- **Concept:** Two Pointers
- **Task:** Given a string `s`, return `true` if it is a palindrome, considering only alphanumeric characters and ignoring cases.
- **Goal:** $O(N)$ Time, $O(1)$ Space.

### **P2: Valid Palindrome II (LC 680)**
- **Difficulty:** Easy
- **Concept:** Two Pointers + Skip
- **Task:** Given a string `s`, return `true` if the `s` can be palindrome after deleting **at most one** character from it.
- **Goal:** $O(N)$ Time. When a mismatch occurs, check either skipping the left character or the right character.

### **P3: Longest Palindrome (LC 409)**
- **Difficulty:** Easy
- **Concept:** Hash Table / Greedy
- **Task:** Given a string `s` which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
- **Goal:** $O(N)$ Time, $O(1)$ Space (since alphabet size is fixed).

### **P4: Longest Substring Without Repeating Characters (LC 3)**
- **Difficulty:** Medium
- **Concept:** Sliding Window
- **Task:** Given a string `s`, find the length of the longest substring without repeating characters.
- **Goal:** $O(N)$ Time using a set or frequency array to shrink the window when duplicates appear.

### **P5: Longest Repeating Character Replacement (LC 424)**
- **Difficulty:** Medium
- **Concept:** Sliding Window
- **Task:** You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character at most `k` times. Return the length of the longest substring containing the same letter you can get.
- **Goal:** $O(N)$ Time. Window validity: `window_size - max_frequency_in_window <= k`.

### **P6: Palindromic Substrings (LC 647)**
- **Difficulty:** Medium
- **Concept:** Expand Around Center
- **Task:** Given a string `s`, return the number of palindromic substrings in it.
- **Goal:** $O(N^2)$ Time, $O(1)$ Space by expanding around all $2N - 1$ centers.

### **P7: Longest Palindromic Substring (LC 5)**
- **Difficulty:** Medium
- **Concept:** Expand Around Center / DP
- **Task:** Given a string `s`, return the longest palindromic substring in `s`.
- **Goal:** Complete a clean $O(N^2)$ implementation with Expand Around Center. (Optional: $O(N^2)$ DP implementation).

### **P8: Repeated DNA Sequences (LC 187)**
- **Difficulty:** Medium
- **Concept:** Substring Hashing / Rolling Window
- **Task:** Given a string `s` that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
- **Goal:** $O(N)$ Time using a hash set. 

### **P9: Palindrome Partitioning (LC 131)**
- **Difficulty:** Medium
- **Concept:** DP / Backtracking
- **Task:** Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of `s`.
- **Goal:** Precalculate palindromes in $O(N^2)$, then use Backtracking to construct combinations.

### **P10: Longest Palindromic Substring - Manacher's Algorithm (LC 5 opt)**
- **Difficulty:** Hard
- **Concept:** Advanced String Algorithm
- **Task:** Solve LC 5 (Longest Palindromic Substring) in strict linear time $O(N)$.
- **Goal:** Implement the string transformation (`#a#b#a#`) and array skipping logic to learn Manacher bounds tracking.
