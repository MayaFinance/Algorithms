# 📚 Theoretical Foundations: Arrays – Basics, Traversal, Constraints

The efficiency of an array is derived from its structural simplicity. By mandating that all elements reside in a single, uninterrupted sequence in memory, the data structure gains unique properties that enable $O(1)$ access and maximize the throughput of the modern Central Processing Unit (CPU).

---

## 1. Static Arrays and Memory Allocation Models

A static array is a fixed-size collection of elements where the total memory requirement is determined and allocated at the inception of its scope. In C++, the distinction between static and dynamic allocation is defined by the memory segment utilized: **the stack** versus **the heap**.

*   **Stack Allocation (`int arr[100];`):** Allocated on the program's execution stack. This mechanism is governed by the compiler, which calculates the exact offset required. Allocation is almost instantaneous. However, the stack is a finite resource (typically 1–8 MB), necessitating that large data structures be offloaded.
*   **Heap Allocation (`int* arr = new int[n];`):** These persist until explicitly deallocated via `delete[]`. While flexible, it introduces the overhead of OS memory management and risks fragmentation and leaks if not managed carefully (e.g., using RAII like `std::unique_ptr` or `std::vector`).

## 2. Indexing Mechanics and Address Arithmetic

The defining characteristic of an array is its $O(1)$ random access, achieved through deterministic mapping:

$$ \text{Address} = \text{Base\_Address} + (\text{Index} \times \text{sizeof(DataType)}) $$

Because the elements are contiguous, address calculation is a pure algebraic function. This is why **zero-based indexing** is used—it allows the index to serve as a direct multiplier (offset) without requiring a subtraction of one, saving CPU cycles.

Internally, C++ treats the name of an array as a pointer to its first element.
*   `arr + i` is mathematically equivalent to `&arr[i]`.
*   Dereferencing `arr[i]` translates to `*(arr + i)`.

> **⚠️ Warning:** C++ does not perform bounds checking on raw arrays. Accessing memory outside the allocated range results in undefined behavior (e.g., segmentation faults).

## 3. The Mechanics of `std::vector` and Amortized Analysis

`std::vector` is the C++ STL's implementation of a dynamic array. It manages an underlying heap-allocated buffer using two critical metadata variables:
1.  **`size`:** The number of current elements.
2.  **`capacity`:** The total space available in the current buffer.

When `push_back` is called and `size == capacity`, the vector undergoes **reallocation**:
1.  Allocating a new block (typically twice the size).
2.  Moving/copying elements to the new block.
3.  Deallocating the old block.

While a single reallocation is $O(n)$, the **amortized complexity** is $O(1)$. Using the Potential Method ($\Phi = 2 \times \text{Size} - \text{Capacity}$), the potential "stored energy" pays for the expensive $O(n)$ moves.

## 4. Cache Locality and the Memory Wall

The performance dominance of arrays over linked lists relies on CPU cache lines. Modern CPUs fetch 64-byte blocks of memory. Arrays exhibit high **spatial locality**, meaning fetching `arr[i]` loads subsequent elements into the L1 cache.

Linked lists frequently cause "cache misses" as nodes are scattered across the heap, forcing the CPU to wait for slower RAM—a bottleneck known as the **memory wall**.

In multidimensional arrays (stored in row-major order), looping row-by-row is heavily optimized by cache prefetching, while column-by-column iteration destroys cache performance.

## 5. Implementation Strategies in C++

When implementing patterns, a C++ engineer must be mindful of STL optimizations:
*   `std::vector::reserve(n)` eliminates reallocation overhead, making insertions strictly $O(1)$.
*   `std::accumulate` (from `<numeric>`) provides clean prefix sum logic.
*   `std::vector<bool>` packs bits into memory to save space but complicates pointer arithmetic and multi-threading.
*   `ios_base::sync_with_stdio(false); cin.tie(NULL);` minimizes the I/O gap between `cin` and `scanf`.

---

## 🚦 Core Traversal Paradigms

| Pattern | Strategy | Common Use Case | Complexity |
| :--- | :--- | :--- | :--- |
| **Linear Scan** | Forward/Backward | Summing, searching, min/max finding | $O(n)$ |
| **Two-Pointer** | Converging or Same-Direction | Sorted pairs, partitioning, cycle detection | $O(n)$ |
| **Sliding Window** | Maintaining contiguous range | Max/Min subarray sum, unique substrings | $O(n)$ |

## 💡 Edge Case Checklist for Technical Interviews

- [ ] **Empty Arrays:** Return `0`, `-1`, or an empty list as appropriate.
- [ ] **Single Element Arrays:** Algorithms like majority element behave uniquely when $n=1$.
- [ ] **Arrays with Duplicates:** Ensure logic (e.g., Two Sum) handles repeated values without reusing indices.
- [ ] **All Elements Equal:** Verify partitioning/sorting logic doesn't infinite loop.
- [ ] **Negative Numbers:** Do prefix sum/minimum logic assumptions hold if inputs are negative?
- [ ] **Integer Overflow:** $n \le 10^5$ and $A[i] \le 10^9$ means sums will exceed $2^{31}-1$. Always use `long long`.
