# Day 1 TODO Checklist

Structured sequential plan for completing Day 1 - Theoretical Foundations and Complexity Analysis.

## Phase 1: Theory and Core Notations
- [ ] Read the "Foundations of Complexity and Formal Notations" section in `concepts.md`.
- [ ] Memorize the mathematical definitions of Big O, Big $\Omega$, and Big $\Theta$.
- [ ] Understand the Hierarchy of Complexity Growth ($O(1) \dots O(2^n)$) and their implications on a standard $1 \dots 2$ second execution limit constraint.
- [ ] Review Space Complexity vs. Auxiliary Space differences.

## Phase 2: Structural Analysis & Amortization
- [ ] Read the "Dynamic Analysis: Amortized Complexity" section in `concepts.md`.
- [ ] Verify the math behind the dynamic resizing of `std::vector` (why it's $O(1)$ amortized).
- [ ] Review how independent loops differ from nested loops, and how triangular loops calculate into $O(n^2)$.
- [ ] Study the recursion tree patterns for estimating recursive function complexities.

## Phase 3: Advanced Complexity Patterns
- [ ] Read "Harmonic Complexity in Number Theory" and understand why $n/1 + n/2 \dots + n/n = O(n \log n)$. 
- [ ] Understand how Logarithmic Nested Loops collapse into a Linear Bound ($O(n)$) via Geometric Series.
- [ ] Review the 10 Recurrence Intuition examples.

## Phase 4: Practical Coding and Benchmarking
- [ ] Copy the C++ Fast I/O Benchmark code from `concepts.md` and run it on your local machine.
- [ ] Observe the execution time differences as $N$ scales from $1,000$ to $100,000$.

## Phase 5: Pattern Recognition Drills
- [ ] Open `problems.md` and manually solve snippets 1 through 20. Do not look at the answers until you've guessed!
- [ ] Manually solve snippets 21 through 40. Keep note of the ones you got wrong.
- [ ] **Optional/Advanced:** Open `solutions.cpp` and compile the file. Follow the code to see how these snippets are implemented in valid C++ functions. 

## Phase 6: Codeforces Case Studies
- [ ] Read "Case Study 1: Codeforces 791A - Bear and Big Brother".
- [ ] Read "Case Study 2: Codeforces 158A - Next Round".
- [ ] Read "Case Study 3: Codeforces 231A - Team".
- [ ] Review the "Complexity Audit Checklist".
