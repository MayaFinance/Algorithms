# Day 3: Frequency Maps

---

## SECTION 1: THE POWER OF HASHING FREQUENCIES

A **Frequency Map** (often implemented via an Array for characters or a Hash Map for integers) is a fundamental tool for counting "how many times have I seen this element?". 

While sliding window uses frequency maps as part of its *condition testing*, standalone frequency map problems rely heavily on combinations, substring properties, or algebraic manipulations of the counts themselves.

---

## SECTION 2: MAP REPRESENTATION (ARRAY VS UNORDERED_MAP)

Whenever elements are densely clustered (e.g. chars `a-z`, digits `0-9`, or numbers `1-10^5`), **USE A FLAT ARRAY**.
```cpp
// For lowercase English letters: Size 26
int count[26] = {0};
count[c - 'a']++;

// For ALL ASCII characters: Size 128 or 256
int count[128] = {0};
count[c]++;
```
**Why an array?**
`std::unordered_map` has constant time `O(1)` *average* performance, but standard allocations and potential hashing collisions make it incredibly slow compared to a raw array indexing map.

**When to use unordered_map?**
When the elements are completely unpredictable or negative (e.g., array values up to `10^9`).

---

## SECTION 3: COMMON FREQUENCY MAP PATTERNS

### Pattern 1: Anagrams & Palindromes
- **Anagrams**: Two strings are anagrams if their frequency maps are identical. 
   - Anagram grouping: Sort the string. Or create a frequency signature `(e.g. "1#0#0#...#3#")` and use that as the hash map key.
- **Palindromes**: A string can form a palindrome if at most ONE character has an ODD frequency.
   - Example check: `for(int f : count) if (f % 2 != 0) odd_count++; return odd_count <= 1;`

### Pattern 2: Matching Arrays by Frequency
- "Are arrays equal?" -> `countA == countB`
- "Subarray sum divisible by K" (Wait, this is Day 5 content, but involves maps). For today, sticking to pure element frequencies.
- "Majority element" using maps (though Boyer-Moore is better `O(1)` space, hash maps are `O(n)`).

### Pattern 3: Substring Matching (Rolling Hash alternative)
If we need to check if a sliding window matches a target anagram, we maintain the frequency of the sliding window and compare it against the target frequency. (See Day 1: Find All Anagrams). 
Here we expand on this to handle overlapping conditions or variable substring signatures.

---

## SECTION 4: THE "MISSING OR EXTRA ELEMENT" PATTERN

If you are given two arrays and one element is missing or extra, you can easily find it using a frequency map:
1. Build a map of array 1.
2. Iterate array 2 and decrement the counts.
3. The element with a count of `1` or `-1` is the anomaly.

*(Note: If the elements are raw numbers and space must be `O(1)`, XOR operations are the better mathematical tool here).*

---

## SECTION 5: CUSTOM C++ HASHING FOR MAPS

If you want to use pairs or custom structs as keys in `unordered_map`:
C++ does not provide a default hash function for `std::pair`. You must supply one:
```cpp
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        // A common generic mix
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
unordered_map<pair<int,int>, int, pair_hash> my_map;
```
For Codeforces, be careful! Standard `unordered_map` is susceptible to "anti-hash" tests causing `O(N^2)` TLE. See Day 4 for custom hashing tricks to avoid hacks.

---

## SECTION 6: REVISION SHEET (MEMORIZE)

1. Use `int count[128]` for Strings.
2. Two strings are Anagrams if their `count` arrays match identically.
3. A palindrome can have at most ONE odd character frequency count.
4. Hash map operations `insert()` and `operator[]` are `O(1)` amortized, but `O(N)` worst case due to collisions. Keep array backups.
