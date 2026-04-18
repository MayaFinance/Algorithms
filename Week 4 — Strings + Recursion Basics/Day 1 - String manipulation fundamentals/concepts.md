# Concepts: String Manipulation Fundamentals

## 1. Strings: Memory and Mutability
- **The Concept:** A string is essentially an array of characters. However, depending on the language, it behaves differently.
- **C++:** `std::string` is **mutable**. You can update an index directly (`s[i] = 'x'`) in $O(1)$ time without extra space.
- **Python/Java:** Strings are **immutable**. Asking to modify a single character means you must allocate an entirely new string, which takes $O(N)$ time and space.
- **The Pitfall:** Avoid repeatedly concatenating immutable strings (`result += s[i]`) inside loops as it triggers $O(N^2)$ execution. In C++, `+=` is amortized $O(1)$, but using built-in fast builders like `std::string::reserve()` or `std::stringstream` for massive appends is safer.

## 2. ASCII & Rapid Lookup
- Standard characters are bounded by 128 (ASCII) or 256 (Extended ASCII) integer values. 
- You do **not** need a dynamic Hash Map structure (`std::unordered_map`) to count characters.
- **The Pattern:** Use `int count[256] = {0}` or `int count[26] = {0}` (if strictly lowercase). 
  - To index a lowercase letter: `int idx = s[i] - 'a';`
  - This guarantees pure $O(1)$ lookup with a tiny memory footprint.

## 3. The Two-Pointer Paradigm on Strings
- Useful for reversals, palindrome validation, and word boundary extraction.
- Place a `left` pointer at index `0` and a `right` pointer at `n - 1`. 
- Loop `while (left < right)`. Determine conditionals to swap, advance `left++`, or decrement `right--`.

## 4. Prefix & Pattern Boundaries
- Finding prefixes or matching substrings natively takes $O(N \cdot M)$ where $N$ is text length and $M$ is pattern length.
- **Techniques to consider:**
  - Prefix scanning: Compare character by character. Stop early to keep average-case time low.
  - Hashing: You can map substrings to a frequency hash representation (e.g., `"aab"` $\to$ `"2#1#0..."`) to compare "anagrams" across a sliding window cleanly.
