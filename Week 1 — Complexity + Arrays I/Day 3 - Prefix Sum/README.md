# 🧱 Day 3: Advanced Architectures for Cumulative Data Processing (Prefix Sum)

The prefix sum technique represents a fundamental paradigm shift in how computational systems approach range-based data aggregation and subarray analysis. At its core, the methodology transforms a static sequence of data into a cumulative state, enabling a transition from linear-time query processing to constant-time retrieval.

This transformation is not merely a localized optimization but a critical architectural pattern that underpins high-performance systems in computer vision (Integral Images), financial modeling, and distributed data processing. By precomputing cumulative totals, the algorithm effectively pre-resolves the internal dependencies of a sequence, allowing any arbitrary segment to be isolated and evaluated through simple arithmetic subtraction.

---

## 🎯 Objectives
- Understand why Range Queries drop from $O(N)$ to $O(1)$ through preprocessing.
- Grasp the core "Inclusion-Exclusion" mathematical principle $Sum = P[R] - P[L-1]$.
- Master Hash Map Integration: Combining $P[j] = P[i] - K$ to evaluate subarrays in exactly $O(N)$.
- Apply scaling rules to compress $O(N^4)$ 2D matrices queries down to $O(N^3)$.
- Learn the Difference Array pattern for static $O(1)$ range updates.

## 📖 Study Materials
- **Concepts & Theory:** Read [`concepts.md`](./concepts.md) to build foundational arithmetic mapping strategies around Prefix architecture.
- **Problem Set Review:** Open [`problems.md`](./problems.md) which segregates 11 specific Prefix and Difference array variants. This includes parity, divisibility, scaling dimensions, and bounding searches.

## 💻 Practice Solutions
- **Implementation Validation:** Review [`solutions.cpp`](./solutions.cpp), a compiled library of optimal algorithms answering the 11 problems described in `problems.md`. Crucially pay attention to the exact way the C++ `unordered_map` is utilized with cumulative values.

## 📝 Check your TODO
- Open [`todo.md`](./todo.md) to follow the sequential 6-phase roadmap for completing today's material. Do not proceed to Hash Maps without firmly grasping the formula!

> **Insight:** Always prepend a $\{0: 1\}$ dummy representation in your Frequency HashMap! Without it, any subarray exactly equating to your target *starting from index zero* will not be validated properly when doing $P[i] - K$.
