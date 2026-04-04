# 🧠 Day 1: Theoretical Foundations and Empirical Analysis of Algorithmic Complexity

The rigor of algorithm analysis constitutes the core of computer science, providing a standardized language for evaluating the efficiency of computational processes. In the high-stakes environment of competitive programming and elite technical interviews, the ability to predict how an algorithm will behave as the input size $n$ scales toward infinity is not merely a theoretical exercise but a practical necessity for success. 

This comprehensive framework is designed to bridge the gap between abstract mathematical definitions and the pragmatic constraints of hardware, compilers, and online judges. By mastering both the formal notations and the empirical benchmarking techniques, a developer develops an intuition that allows them to "see" the runtime of a solution before a single line of code is written.

---

## 📚 Block 1: Foundations of Complexity and Formal Notations

Algorithmic complexity analysis begins with the understanding of asymptotic behavior, which focuses on the growth rate of a function as its input approaches a limit, typically infinity. This perspective is crucial because, for large datasets, the constant factors and lower-order terms become negligible compared to the dominant growth term.

### Formal Asymptotic Notations
The mathematical language of complexity is defined by three primary notations: **Big O**, **Big $\Omega$**, and **Big $\Theta$**. These notations represent the upper, lower, and tight bounds of a function’s growth, respectively.

* **Big O ($O$)**: Provides an asymptotic **upper bound**. Formally, a function $f(n)$ is said to be $O(g(n))$ if there exist positive constants $c$ and $n_0$ such that $0 \le f(n) \le c \cdot g(n)$ for all $n \ge n_0$. In the context of competitive programming, Big O is the "worrier's notation," as it describes the worst-case scenario. Graphically, $c \cdot g(n)$ remains above $f(n)$ for all points beyond the intersection point $n_0$.
* **Big Omega ($\Omega$)**: Provides an asymptotic **lower bound**. A function $f(n)$ is $\Omega(g(n))$ if there exist positive constants $c$ and $n_0$ such that $0 \le c \cdot g(n) \le f(n)$ for all $n \ge n_0$. This represents the "optimist's notation," establishing the minimum work required by an algorithm. 
* **Big Theta ($\Theta$)**: Represents a **tight bound**. A function $f(n)$ is $\Theta(g(n))$ if it is both $O(g(n))$ and $\Omega(g(n))$. This implies that $f(n)$ is "sandwiched" between $c_1 \cdot g(n)$ and $c_2 \cdot g(n)$ for sufficiently large $n$.

| Notation | Mathematical Relation | Intuitive Interpretation | Bound Type |
| :--- | :--- | :--- | :--- |
| **$O(g(n))$** | $f(n) \le c \cdot g(n)$ | Worst-case growth | Upper Bound |
| **$\Omega(g(n))$**| $f(n) \ge c \cdot g(n)$ | Best-case growth | Lower Bound |
| **$\Theta(g(n))$**| $c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n)$ | Precise growth | Tight Bound |

### Hierarchy of Complexity Growth

The relative efficiency of algorithms is categorized by their complexity classes. Understanding this hierarchy allows developers to determine if a chosen approach will pass within the standard 1-2 second limit of an online judge based on the provided constraints.

> **$O(1)$ < $O(\log n)$ < $O(\sqrt{n})$ < $O(n)$ < $O(n \log n)$ < $O(n^2)$ < $O(n^3)$ < $O(2^n)$ < $O(n!)$**

### Comparison of Time and Space Complexity
Efficiency is measured in two dimensions: **time** (computational steps) and **space** (memory usage). While time complexity is often the primary bottleneck, space complexity is equally vital. 

It is necessary to distinguish between total space and *auxiliary space*. Auxiliary space refers to the temporary memory used by the algorithm during its execution, excluding the space required by the input itself. An algorithm is considered "in-place" if it uses $O(1)$ or $O(\log n)$ auxiliary space.

### Dynamic Analysis: Amortized Complexity

Amortized analysis is a technique used to determine the average cost per operation over a long sequence of operations, even if some individual operations are very expensive. A classic example is the dynamic resizing of a `std::vector` in C++.

When a `std::vector::push_back` is called, it usually adds the element in $O(1)$ time if there is capacity. However, if full, it must allocate a new, larger memory block, move elements, and then append. This resizing is $O(n)$. By growing capacity geometrically (usually doubling), we ensure that the $O(n)$ operations happen rarely.

**The expansion sequence:**
* **Insert 1:** Cost 1 *(size 1, cap 1)*
* **Insert 2:** Cost 1 (move) + 1 (new) = 2 *(size 2, cap 2)*
* **Insert 3:** Cost 2 (move) + 1 (new) = 3 *(size 3, cap 4)*
* **Insert 4:** Cost 1 (new) = 1 *(size 4, cap 4)*
* **Insert 5:** Cost 4 (move) + 1 (new) = 5 *(size 5, cap 8)*
* **Insert 6, 7, 8:** Cost 1 each

Across $n$ operations, total cost of all reallocations is $1 + 2 + 4 + \dots + n/2$, which sums to $n-1$. Adding the $n$ individual constant-time insertions results in a total work of $O(2n)$, making the amortized cost per insertion **$O(1)$**.

### Structural Loop Analysis and Recursion Trees
* **Simple Loops:** Incrementing linearly are $O(n)$.
* **Nested Loops (Independent):** Result in the product of their complexities, e.g., $O(n \cdot m)$.
* **Triangular Loops:** Inner loop depends on outer loop's index `for(j=0; j<i; j++)`. Results in $n(n+1)/2$ which is $O(n^2)$.
* **Recursion Trees:** 
    * $T(n) = T(n/2) + O(1) \rightarrow O(\log n)$
    * $T(n) = 2T(n/2) + O(n) \rightarrow O(n \log n)$

---

## ⚡ Block 2: Complexity Estimation Problems and Case Studies

Analyze each C++ snippet to determine its Big O complexity.

<details><summary><b>Snippet 1-10: Basic Iterations</b></summary>

1. `for (int i = 0; i < n; i++) { sum++; }`
   * **Answer:** $O(n)$. The loop runs $n$ times with $O(1)$ work inside.
2. `for (int i = 0; i < n; i += 2) { sum++; }`
   * **Answer:** $O(n)$. Runs $n/2$ times.
3. `for (int i = n; i > 0; i /= 2) { sum++; }`
   * **Answer:** $O(\log n)$. Halved each iteration.
4. `for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { sum++; } }`
   * **Answer:** $O(n^2)$. Standard nested structure.
5. `for (int i = 0; i < n; i++) { for (int j = i; j < n; j++) { sum++; } }`
   * **Answer:** $O(n^2)$. Triangular loop, sum of $1$ to $n$.
6. `for (int i = 1; i < n; i *= 2) { for (int j = 0; j < n; j++) { sum++; } }`
   * **Answer:** $O(n \log n)$. Outer is logarithmic; inner is linear.
7. `for (int i = 0; i < n; i++) { for (int j = 1; j < n; j *= 2) { sum++; } }`
   * **Answer:** $O(n \log n)$. Inner is logarithmic; outer is linear.
8. `for (int i = 1; i * i <= n; i++) { sum++; }`
   * **Answer:** $O(\sqrt{n})$. Loop terminates when $i > \sqrt{n}$.
9. `for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { sum++; } }`
   * **Answer:** $O(n \cdot m)$. Independent variables $n$ and $m$.
10. `for (int i = 0; i < n; i++) { if (i > 100) break; sum++; }`
    * **Answer:** $O(1)$. Bounded by a constant 100.
</details>

<details><summary><b>Snippet 11-20: Mathematical Series</b></summary>

11. `for (int i = 0; i < n; i++) { for (int j = 0; j < i * i; j++) { sum++; } }`
    * **Answer:** $O(n^3)$. Sum of squares.
12. `for (int i = 1; i < n; i *= 2) { for (int j = 0; j < i; j++) { sum++; } }`
    * **Answer:** $O(n)$. Geometric sum $1+2+4+\dots=O(n)$.
13. `for (int i = 1; i < n; i++) { for (int j = 1; j < n; j += i) { sum++; } }`
    * **Answer:** $O(n \log n)$. Harmonic sum: $n/1 + n/2 + \dots = n \log n$.
14. `for (int i = 2; i < n; i = i * i) { sum++; }`
    * **Answer:** $O(\log \log n)$. Double logarithmic growth.
15. `for (int i=0; i<n; i++) sum++; for (int j=0; j<m; j++) sum++;`
    * **Answer:** $O(n+m)$. Consecutive loops.
16. `while (n > 0) { n /= 2; for (int j = 0; j < n; j++) sum++; }`
    * **Answer:** $O(n)$. Geometric reduction.
17. `for (int i = 0; i < n; i++) { for (int j = 0; j < n; j += sqrt(n)) sum++; }`
    * **Answer:** $O(n\sqrt{n})$. Inner loop runs $\sqrt{n}$ times.
18. `for(i=1..n){ for(j=1..i){ for(k=1..j) } }`
    * **Answer:** $O(n^3)$. Triple triangular sum.
19. `for (int i = 0; i < n; i++) { vector.push_back(i); }`
    * **Answer:** $O(n)$. Amortized $O(1)$ inside loop.
20. `for (int i = 1; i < n; i++) { if (n % i == 0) sum++; }`
    * **Answer:** $O(n)$. Linear scan.
</details>

<details><summary><b>Snippet 21-30: Mixes and Data Structures</b></summary>

21. `for (i=1..n) for (j=1..n; j*=2) for (k=1..n; k*=2)`
    * **Answer:** $O(n \log^2 n)$. Linear outer, two logarithmic inner loops.
22. `for (int i = 0; i < n * n; i++) { sum++; }`
    * **Answer:** $O(n^2)$. 
23. `for (int i = 1; i <= n; i++) { for (int j = i; j <= n; j *= 2) sum++; }`
    * **Answer:** $O(n)$. Iterations sum to $O(n)$.
24. `for (int i = 0; i < n; i++) { set.insert(i); }`
    * **Answer:** $O(n \log n)$. Tree insertion is $O(\log n)$.
25. `for (int i = 1; i <= n; i++) { for (int j = 1; j <= 10; j++) sum++; }`
    * **Answer:** $O(n)$. Inner loop is constant time.
26. `for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j += 100) sum++; }`
    * **Answer:** $O(n^2)$. Constants drop out.
27. `while (low <= high) { mid = (low+high)/2; if(arr[mid]==t) break; }`
    * **Answer:** $O(\log n)$. Binary search.
28. `for (int i = 1; i <= n; i++) { n /= 2; }`
    * **Answer:** $O(\log n)$.
29. `for (i=1..n; i*=2) for (j=0..i) for (k=0..j)`
    * **Answer:** $O(n^2)$. Nested triangular within a doubling loop.
30. `for (int i = 0; i < n; i++) { string s = string(i, 'a'); }`
    * **Answer:** $O(n^2)$. String dynamic allocation takes $O(i)$ time per step.
</details>

<details><summary><b>Snippet 31-40: Advanced Edges</b></summary>

31. `for (i=1..n) for (j=1..n) if (i==j) for (k=0..n)`
    * **Answer:** $O(n^2)$. Innermost runs only $n$ times.
32. `void f(int n) { if (n <= 1) return; f(n-1); }`
    * **Answer:** $O(n)$. Linear stack depth.
33. `void f(int n) { if (n <= 1) return; f(n/2); f(n/2); }`
    * **Answer:** $O(n)$. Binary tree recursion summing to $2n-1$ nodes.
34. `for (i=1..n) for (j=1..n) { if(rand()%2) break; sum++; }`
    * **Answer:** $O(n^2)$. Worst-case scenario bounds it.
35. `for (int i = 0; i < n; i++) { map[i] = i; }`
    * **Answer:** $O(n \log n)$. `std::map` is a Red-Black Tree.
36. `for (int i = 0; i < n; i++) { unordered_map[i] = i; }`
    * **Answer:** $O(n)$. Hash map average insertion is $O(1)$.
37. `for (i=1..n) for (j=1..i; j*=2)`
    * **Answer:** $O(n \log n)$. Sum of logarithms is $\log(n!)$.
38. `for (i=1..n) for (j=1..n; j+=i) for (k=0..100)`
    * **Answer:** $O(n \log n)$. Harmonic series with constant work.
39. `int j = 0; for (int i = 0; i < n; i++) { while (j < m && cond) j++; }`
    * **Answer:** $O(n+m)$. Two-pointer tracking.
40. `for (int i = 1; i * i * i <= n; i++) { sum++; }`
    * **Answer:** $O(n^{1/3})$. Runs until $i^3 > n$.
</details>

### Case Study Analysis: Codeforces Standard Problems

* **Case Study 1: Bear and Big Brother (CF 791A)**
  * **Constraints:** $a \le b \le 10$
  * **Complexity:** Loop runs while $a \le b$, multiplying $a$ by 3 and $b$ by 2. This is $O(\log_{1.5}(b/a))$. Because $b \le 10$, it is effectively $O(1)$.
* **Case Study 2: Next Round (CF 158A)**
  * **Constraints:** $n \le 50$. 
  * **Complexity:** Linear scan to count items meeting condition. $O(n)$. Instantaneous.
* **Case Study 3: Team (CF 231A)**
  * **Constraints:** $n \le 1000$ rows of 3 numbers.
  * **Complexity:** $O(n)$ iteration. 3000 operations is $\ll 10^8$.

---

## 🔬 Block 3: Harder Analysis and Advanced Complexity Patterns

Moving beyond simple iterations, advanced algorithmic designs utilize mathematical series and recursive structures that require deeper analytical tools.

### Harmonic Complexity in Number Theory
Harmonic complexity is a cornerstone of number theory algorithms, such as the *Sieve of Eratosthenes*.

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
        // inner loop runs n/i times
    }
}
```
The total number of operations is $n \cdot (1/1 + 1/2 + 1/3 + \dots + 1/n)$. The sum of the Harmonic Series is asymptotically $\ln n$. Total complexity is **$O(n \log n)$**.

### Logarithmic Nested Loops and Geometric Series
```cpp
for (int i = 1; i <= n; i *= 2) {
    for (int j = 0; j < i; j++) {
        // operation
    }
}
```
The outer loop executes $\log n$ times, while the inner runs $i$ times. Work = $1 + 2 + 4 + 8 \dots = 2n-1$. Complexity is **$O(n)$**.

### Recurrence Intuition
1. **$T(n) = T(n/2) + 1$** $\rightarrow O(\log n)$ *(Binary Search)*
2. **$T(n) = 2T(n/2) + n$** $\rightarrow O(n \log n)$ *(Merge Sort)*
3. **$T(n) = T(n/2) + n$** $\rightarrow O(n)$ *(QuickSelect)*
4. **$T(n) = 2T(n/2) + 1$** $\rightarrow O(n)$ *(Tree Traversal)*
5. **$T(n) = T(n-1) + 1$** $\rightarrow O(n)$ *(Sequential Recursion)*
6. **$T(n) = T(n-1) + n$** $\rightarrow O(n^2)$ *(Bubble Sort)*
7. **$T(n) = 2T(n-1) + 1$** $\rightarrow O(2^n)$ *(Tower of Hanoi)*
8. **$T(n) = 4T(n/2) + n$** $\rightarrow O(n^2)$
9. **$T(n) = T(n/4) + T(n/2) + n$** $\rightarrow O(n)$
10. **$T(n) = 8T(n/2) + n^2$** $\rightarrow O(n^3)$

---

## 💻 Block 4: Implementation and Empirical Benchmarking

### C++ Benchmarking and Fast I/O Template
Standard I/O can be the bottleneck. Disable C stream sync and decoupling `cin`/`cout` is critical in C++.

```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

template <typename Func>
void benchmark(string name, Func func, int n) {
    auto start = chrono::steady_clock::now();
    func(n);
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << name << " (n=" << n << "): " << duration.count() << " ms\n";
}
```

### Observation of Computational Explosions

| Complexity | $n \rightarrow 2n$ Time Factor | Growth Explanation |
| :--- | :--- | :--- |
| **$O(n)$** | $\times 2$ | Scales exactly with input size. |
| **$O(n \log n)$** | $\approx \times 2.1$ | Slightly more than double. |
| **$O(n^2)$** | $\times 4$ | Squaring input means 4x operations. |
| **$O(2^n)$** | Square of time | Doubling $n$ is catastrophic. |

### Complexity Audit Checklist
- [x] **Constraint Scan:** What is $n$? ($10^3 \rightarrow O(n^2)$, $10^5 \rightarrow O(n \log n)$, $10^9 \rightarrow O(\log n)$).
- [x] **Identify Sub-operations:** Does the code use sets, maps, or hidden $O(N)$ string creations?
- [x] **Trace Iterator Variables:** Linear increment $\rightarrow O(n)$, Multiplying/Dividing $\rightarrow O(\log n)$.
- [x] **Audit Memory:** Is auxiliary space within the judge's limit (usually 256MB)?
- [x] **Calculate Overall Bound:** Sum consecutive blocks, multiply nested independent blocks, and grab the dominant term.
