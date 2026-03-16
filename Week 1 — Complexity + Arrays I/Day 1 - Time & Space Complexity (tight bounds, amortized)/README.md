# Day 1: Time & Space Complexity (tight bounds, amortized)

Welcome to Day 1 of Week 1! Today, we dive into the fundamental building blocks of algorithm analysis: Time and Space Complexity. Mastery of asymptotic notation and the ability to accurately estimate computational cost are paramount in competitive programming and technical interviews.

## 🎯 Objectives
- Understand Big O, Big $\Omega$, and Big $\Theta$ asymptotic notations.
- Analyze the time & space bounds of various array operation complexities.
- Understand amortized complexity (e.g., dynamic arrays like `std::vector`).
- Develop intuition to estimate expected runtime from given problem constraints (e.g., $N=10^6 \implies O(N)$ or $O(N \log N)$ running under 1-2 seconds).
- Learn how to benchmark algorithms using empirical runtime metrics.

## 📖 Study Materials
- **Concepts & Theory:** Review the rigorous foundation in [`concepts.md`](./concepts.md). This includes formal notations, amortized complexity breakdowns, and how to analyze complex nested loops and recursions.
- **Quick Revision Webpage:** [Big O Cheat Sheet](https://www.bigocheatsheet.com/) (Contains runtime charts and typical data structure complexities).

## 💻 Practice Problems
- **Complexity Estimation Drill:** Please review [`problems.md`](./problems.md) which contains 40 C++ code snippets. Try calculating the time complexity for each snippet manually before checking the explanation.
- **Case Studies Analysis:** Read over how complexity determines the solution strategy for standard competitive programming setups (Bear and Big Brother, Next Round, Team).

## 📝 TODO Checklist

- [ ] Read and understand the Big O formal definitions in `concepts.md`.
- [ ] Understand the Geometric Series implications for $O(\log n)$ nested structures.
- [ ] Understand why `push_back` on a vector is amortized $O(1)$.
- [ ] Solve snippets 1–20 in `problems.md` manually.
- [ ] Solve snippets 21–40 in `problems.md` manually.
- [ ] Read through the Empirical Benchmarking section and understand the C++ Fast I/O Template.

**Reflection:** Before moving to Day 2, make sure you can look at $N = 10^5$ and immediately know that an $O(N^2)$ brute-force solution will fail (TLE) on an online judge!
