# Day 4: Hashing Collisions & Tricks

---

## SECTION 1: HOW A HASH MAP REALLY WORKS

You've been using `unordered_map` blindly, but interviews often test *why* it's fast and *when* it breaks.

A Hash Map has:
1. **Hash Function**: Converts a key (like string "hello" or int `15`) into a massive integer (Hash Code).
2. **Buckets**: An array of size `m`. We do `Hash Code % m` to find which bucket the key belongs in.
3. **Collision Handling**: What if two keys end up in the exact same bucket?

---

## SECTION 2: HANDLING COLLISIONS

There are two primary methods used in production and interviews:

### 1. Separate Chaining (Used in C++ `std::unordered_map`)
Each bucket is a Linked List.
When you insert a key, you append it to the linked list at that bucket.
- **Search**: Go to bucket, traverse the linked list to find the key.
- **Weakness**: If hashing is bad and everything collides into 1 bucket, search becomes `O(N)` (traversing a long list).

### 2. Open Addressing (Linear/Quadratic Probing)
Used in Python's dict and high-performance flat maps.
If a bucket is full, just look at the **next** bucket `(i + 1)`. If that's full, check `(i + 2)`, etc.
- **Weakness**: "Clustering". If a section of the map gets full, it slows down all subsequent inserts in that area.

---

## SECTION 3: THE "ANTI-HASH" C++ CODEFORCES TRICK (CRITICAL)

In competitive programming (Codeforces), hackers will read your code. Since C++ `std::unordered_map` uses a deterministic (predictable) hash function for integers, a hacker can intentionally generate 100,000 distinct numbers that ALL map to the exact same bucket.
Your `O(1)` map suddenly performs at `O(N)` per insert, leading to `O(N^2)` TLE (Time Limit Exceeded).

**How to defend yourself:**
Supply a custom randomized hash function.
```cpp
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        // chrono provides randomness based on execution time
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Usage:
unordered_map<int, int, custom_hash> safe_map;
```

---

## SECTION 4: HASHING PAIRS AND ARRAYS (TUPLE HASHING)

Sometimes your key isn't a single string or int, but a Pair of ints, or a Vector!
C++ `unordered_map` **does not support pairs or vectors as keys natively**.

You must either:
1. Serialize it to a string: `"A,B"`. (Slow due to string allocation).
2. Write a custom hash function that combines hashes:
```cpp
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // simple combination
    }
};
// unordered_map<pair<int,int>, int, pair_hash> mp;
```

---

## SECTION 5: ROLLING HASH (RABIN-KARP)

How do you compare if two substrings of length `K` are equal in `O(1)` time?
You map the string to an integer! (A Rolling Hash).

String `"bcd"` can be viewed as a base-26 number:
Value = `(2 * 26^2) + (3 * 26^1) + (4 * 26^0)`

When the sliding window moves from `"bcd"` to `"cde"`, you:
1. Subtract the old char `"b"`: `Value - (2 * 26^2)`
2. Multiply by base: `Value * 26`
3. Add new char `"e"`: `Value + 5`

This achieves `O(1)` substring matching!

*Modulus is required* because base-26 numbers for lengths > 10 will overflow 64-bit integers.

---

## SECTION 6: REVISION SHEET (MEMORIZE)

1. `unordered_map` is average `O(1)`, worst case `O(N)`.
2. Standard C++ integral hash is deterministic $\rightarrow$ vulnerable to TLE.
3. Separate chaining uses Linked Lists at buckets. Open addressing uses sequential finding.
4. Rabin-Karp allows `O(1)` string matching by mathematically shifting bases.
5. C++ requires custom `struct` to hash `std::pair` or `std::vector`.
