# Problem Set: String Manipulation Fundamentals

These 10 problems rebuild your foundational muscle for string traversal, mapping, and edge-handling.

---

### **P1: Reverse String (LC 344)**
- **Difficulty:** Easy
- **Concept:** String Basics / Two Pointers
- **Task:** Reverse an array of characters in-place with $O(1)$ extra memory.
- **Goal:** Loop `while (left < right)` and swap to achieve $O(N)$ Time and pure $O(1)$ Space.

### **P2: Reverse Vowels of a String (LC 345)**
- **Difficulty:** Easy
- **Concept:** Conditional Two Pointers
- **Task:** Given a string `s`, reverse only all the vowels in the string and return it.
- **Goal:** Advance `left` until vowel, decrement `right` until vowel, swap. $O(N)$ Time.

### **P3: Valid Anagram (LC 242)**
- **Difficulty:** Easy
- **Concept:** Frequency Counting
- **Task:** Return true if `t` is an anagram of `s`.
- **Goal:** Maintain an `int count[26] = {0}`. Increment for `s`, decrement for `t`. Check if all counts are 0. $O(N)$ Time, $O(1)$ Space.

### **P4: Isomorphic Strings (LC 205)**
- **Difficulty:** Easy
- **Concept:** ASCII Map
- **Task:** Determine if strings `s` and `t` are isomorphic (characters in `s` map uniquely to characters in `t`, preserving order).
- **Goal:** Dual `int mapS[256]` and `int mapT[256]` arrays tracking the last seen string position. $O(N)$ Time.

### **P5: Longest Common Prefix (LC 14)**
- **Difficulty:** Easy
- **Concept:** Prefix-based Logic
- **Task:** Find the longest common prefix string amongst an array of strings.
- **Goal:** Use the first string as a baseline. For each string, truncate the baseline prefix until it matches. $O(N \cdot M)$ Time.

### **P6: Find the Index of the First Occurrence in a String (LC 28)**
- **Difficulty:** Easy / Medium
- **Concept:** Pattern Matching Basics
- **Task:** Return the index of the first occurrence of `needle` in `haystack`, or -1 if missing.
- **Goal:** Implement clean nested scanning $O(N \cdot M)$ bounds, avoiding index-out-of-bounds. 

### **P7: Find All Anagrams in a String (LC 438)**
- **Difficulty:** Medium
- **Concept:** Hashing-based Substrings / Sliding Window
- **Task:** Find all start indices of `p`'s anagrams in `s`.
- **Goal:** Window of length `p` slides across `s`, maintaining a rolling `count[26]` frequency. $O(N)$ Time.

### **P8: Group Anagrams (LC 49)**
- **Difficulty:** Medium
- **Concept:** String Building & Transformation / Hashing
- **Task:** Group anagrams together from an array of strings `strs`.
- **Goal:** Avoid $O(K \log K)$ sorting. Instead, transform `"aab"` to a hash key like `"2#1#0..."` using frequency arrays. $O(N \cdot K)$ Time.

### **P9: String to Integer (atoi) (LC 8)**
- **Difficulty:** Medium
- **Concept:** Traps & Character Handling
- **Task:** Convert a string to a 32-bit signed integer implementing strict parsing rules.
- **Goal:** Process spaces $\to$ process sign $\to$ parse numbers while checking overflow limits actively. $O(N)$ Time.

### **P10: Reverse Words in a String (LC 151)**
- **Difficulty:** Medium
- **Concept:** In-place vs Extra Space Trade-offs
- **Task:** Reverse the order of the words concatenating by a single space.
- **Goal:** $O(1)$ Extra Space approach: Reverse the entire string, reverse each individual word, then shift words down to compact excess spaces. $O(N)$ Time.
