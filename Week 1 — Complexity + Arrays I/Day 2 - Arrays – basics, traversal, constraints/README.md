# 🧱 Day 2: Arrays – Basics, Traversal, and Constraints

The array is the foundational primitive upon which the edifice of modern computer science is constructed. It represents the most direct abstraction of physical memory, providing a contiguous block of addressable storage that maps directly to the hardware’s linear address space. 

For the software engineer or competitive programmer, understanding arrays is not merely a matter of learning syntax; it is a rigorous study of the intersection between high-level algorithmic logic and the low-level constraints of silicon, cache hierarchies, and memory controllers.

---

## 🎯 Objectives
- Understand memory allocation (Static/Stack vs Dynamic/Heap).
- Calculate address offsets algebraically.
- Prove why dynamic array expansion (`std::vector::push_back`) takes an amortized $O(1)$ time.
- Identify how CPU Cache Locality impacts performance compared to non-contiguous structures.
- Master Core Traversal Paradigms: Two-Pointers, Sliding Windows, Fast-Slow pointers.

## 📖 Study Materials
- **Concepts & Theory:** Read [`concepts.md`](./concepts.md) to build foundational hardware and algorithmic knowledge regarding arrays and C++ `std::vector` implementation.
- **Problem Set Review:** Open [`problems.md`](./problems.md) which segregates 12 specific core array problems. These showcase distinct patterns (Dutch National Flag, Boyer-Moore, Reverse Merge) that form the building blocks for harder problems.

## 💻 Practice Solutions
- **Implementation Validation:** Review [`solutions.cpp`](./solutions.cpp), a compiled library of optimal $O(n)$ / $O(1)$-space algorithms answering the 12 problems described in `problems.md`.

## 📝 Check your TODO
- Open [`todo.md`](./todo.md) to follow the sequential 6-phase roadmap for completing today's material. Do not skip the "Edge Case Readiness" checklist!

> **Insight:** In competitive programming, when constraints state $N = 10^{12}$ (like *Even Odds*), an $O(N)$ vector allocation will physically crash your memory manager. Theoretical math must replace data structures. 
