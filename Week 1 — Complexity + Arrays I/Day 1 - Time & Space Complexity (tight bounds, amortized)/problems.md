# Complexity Estimation Problems

Develop your algorithmic intuition by analyzing the following code snippets to determine their Big O complexity.

## Problem Set

Analyze each C++ snippet to determine its Big O complexity in terms of time.

1.  **Snippet:** `for (int i = 0; i < n; i++) { sum++; }`
    *   **Explanation:** The loop runs $n$ times with $O(1)$ work inside.
    *   **Answer:** $O(n)$

2.  **Snippet:** `for (int i = 0; i < n; i += 2) { sum++; }`
    *   **Explanation:** The loop runs $n/2$ times. Constants are ignored.
    *   **Answer:** $O(n)$

3.  **Snippet:** `for (int i = n; i > 0; i /= 2) { sum++; }`
    *   **Explanation:** The value of $i$ is halved each iteration, occurring $\log_2 n$ times.
    *   **Answer:** $O(\log n)$

4.  **Snippet:** `for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { sum++; } }`
    *   **Explanation:** A standard nested structure where the inner loop runs $n$ times for each of the $n$ outer iterations.
    *   **Answer:** $O(n^2)$

5.  **Snippet:** `for (int i = 0; i < n; i++) { for (int j = i; j < n; j++) { sum++; } }`
    *   **Explanation:** Triangular loop. Iterations: $n + (n-1) + (n-2) + \dots + 1 = n(n+1)/2$.
    *   **Answer:** $O(n^2)$

6.  **Snippet:** `for (int i = 1; i < n; i *= 2) { for (int j = 0; j < n; j++) { sum++; } }`
    *   **Explanation:** Outer loop is logarithmic ($\log n$); inner loop is linear ($n$).
    *   **Answer:** $O(n \log n)$

7.  **Snippet:** `for (int i = 0; i < n; i++) { for (int j = 1; j < n; j *= 2) { sum++; } }`
    *   **Explanation:** Inner loop is logarithmic; outer loop is linear.
    *   **Answer:** $O(n \log n)$

8.  **Snippet:** `for (int i = 1; i * i <= n; i++) { sum++; }`
    *   **Explanation:** The loop terminates when $i$ exceeds $\sqrt{n}$.
    *   **Answer:** $O(\sqrt{n})$

9.  **Snippet:** `for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { sum++; } }`
    *   **Explanation:** Nested loops with independent variables $n$ and $m$.
    *   **Answer:** $O(n \cdot m)$

10. **Snippet:** `for (int i = 0; i < n; i++) { if (i > 100) break; sum++; }`
    *   **Explanation:** The break statement limits iterations to a constant number.
    *   **Answer:** $O(1)$

11. **Snippet:** `for (int i = 0; i < n; i++) { for (int j = 0; j < i * i; j++) { sum++; } }`
    *   **Explanation:** Summation of $i^2$ from 1 to $n$ approximates $n^3/3$.
    *   **Answer:** $O(n^3)$

12. **Snippet:** `for (int i = 1; i < n; i *= 2) { for (int j = 0; j < i; j++) { sum++; } }`
    *   **Explanation:** Geometric sum $1 + 2 + 4 + 8 + \dots + n = O(n)$.
    *   **Answer:** $O(n)$

13. **Snippet:** `for (int i = 1; i < n; i++) { for (int j = 1; j < n; j += i) { sum++; } }`
    *   **Explanation:** Harmonic sum: $n/1 + n/2 + n/3 + \dots + n/n = n \log n$.
    *   **Answer:** $O(n \log n)$

14. **Snippet:** `for (int i = 2; i < n; i = i * i) { sum++; }`
    *   **Explanation:** Double logarithmic growth; $i$ reaches $n$ when $2^{2^k} = n$.
    *   **Answer:** $O(\log \log n)$

15. **Snippet:** `for (int i = 0; i < n; i++) { sum++; } for (int j = 0; j < m; j++) { sum++; }`
    *   **Explanation:** Consecutive loops; complexity is the sum of parts.
    *   **Answer:** $O(n + m)$

16. **Snippet:** `while (n > 0) { n /= 2; for (int j = 0; j < n; j++) sum++; }`
    *   **Explanation:** Geometric reduction: $n + n/2 + n/4 + \dots + 1 = 2n$.
    *   **Answer:** $O(n)$

17. **Snippet:** `for (int i = 0; i < n; i++) { for (int j = 0; j < n; j += sqrt(n)) sum++; }`
    *   **Explanation:** Inner loop runs $n/\sqrt{n} = \sqrt{n}$ times. Total is $n \cdot \sqrt{n}$.
    *   **Answer:** $O(n\sqrt{n})$

18. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= i; j++) { for (int k = 1; k <= j; k++) sum++; } }`
    *   **Explanation:** Triple triangular loop; triple summation.
    *   **Answer:** $O(n^3)$

19. **Snippet:** `for (int i = 0; i < n; i++) { vector.push_back(i); }`
    *   **Explanation:** Amortized $O(1)$ per `push_back` over $n$ iterations.
    *   **Answer:** $O(n)$

20. **Snippet:** `for (int i = 1; i < n; i++) { if (n % i == 0) sum++; }`
    *   **Explanation:** Simple linear scan up to $n$.
    *   **Answer:** $O(n)$

21. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j *= 2) { for (int k = 1; k <= n; k *= 2) sum++; } }`
    *   **Explanation:** Linear outer loop with two nested logarithmic loops.
    *   **Answer:** $O(n \log^2 n)$

22. **Snippet:** `for (int i = 0; i < n * n; i++) { sum++; }`
    *   **Explanation:** The loop limit is $n^2$, and work per step is constant.
    *   **Answer:** $O(n^2)$

23. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = i; j <= n; j *= 2) sum++; }`
    *   **Explanation:** The number of iterations is $\sum \log(n/i)$, which is $O(n)$.
    *   **Answer:** $O(n)$

24. **Snippet:** `for (int i = 0; i < n; i++) { set.insert(i); }`
    *   **Explanation:** C++ `std::set` insertion is $O(\log n)$; $n$ insertions occur.
    *   **Answer:** $O(n \log n)$

25. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= 10; j++) sum++; }`
    *   **Explanation:** Inner loop is constant time (10 iterations).
    *   **Answer:** $O(n)$

26. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j += 100) sum++; }`
    *   **Explanation:** Linear inner loop with a large step; constant factor ignored.
    *   **Answer:** $O(n^2)$

27. **Snippet:** `while (low <= high) { int mid = (low + high)/2; if (arr[mid] == target) break; }`
    *   **Explanation:** Search space halves each step; binary search logic.
    *   **Answer:** $O(\log n)$

28. **Snippet:** `for (int i = 1; i <= n; i++) { n /= 2; }`
    *   **Explanation:** The loop limit decreases exponentially.
    *   **Answer:** $O(\log n)$

29. **Snippet:** `for (int i = 1; i <= n; i *= 2) { for (int j = 0; j < i; j++) { for (int k = 0; k < j; k++) sum++; } }`
    *   **Explanation:** Nested triangular loops within a doubling outer loop. $\sum i^2 \approx O(n^2)$.
    *   **Answer:** $O(n^2)$

30. **Snippet:** `for (int i = 0; i < n; i++) { string s = string(i, 'a'); }`
    *   **Explanation:** String construction of length $i$ takes $O(i)$ time. Total $\sum i$.
    *   **Answer:** $O(n^2)$

31. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { if (i == j) { for (int k = 0; k < n; k++) sum++; } } }`
    *   **Explanation:** The innermost loop only runs when $i=j$, which happens $n$ times.
    *   **Answer:** $O(n^2)$

32. **Snippet:** `void f(int n) { if (n <= 1) return; f(n-1); }`
    *   **Explanation:** Linear recursion; $n$ calls made.
    *   **Answer:** $O(n)$

33. **Snippet:** `void f(int n) { if (n <= 1) return; f(n/2); f(n/2); }`
    *   **Explanation:** Binary tree recursion; $2^0 + 2^1 + \dots + 2^{\log n}$ nodes.
    *   **Answer:** $O(n)$

34. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { if (rand() % 2) break; sum++; } }`
    *   **Explanation:** Worst case: the break never happens.
    *   **Answer:** $O(n^2)$

35. **Snippet:** `for (int i = 0; i < n; i++) { map[i] = i; }`
    *   **Explanation:** `std::map` (Red-Black Tree) insertion is $O(\log n)$.
    *   **Answer:** $O(n \log n)$

36. **Snippet:** `for (int i = 0; i < n; i++) { unordered_map[i] = i; }`
    *   **Explanation:** Average case for hash map insertion is $O(1)$.
    *   **Answer:** $O(n)$

37. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= i; j *= 2) sum++; }`
    *   **Explanation:** $\sum_{i=1}^n \log i = \log(n!)$, which is $O(n \log n)$.
    *   **Answer:** $O(n \log n)$

38. **Snippet:** `for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j += i) { for (int k = 0; k < 100; k++) sum++; } }`
    *   **Explanation:** Harmonic series $O(n \log n)$ multiplied by constant work.
    *   **Answer:** $O(n \log n)$

39. **Snippet:** `int j = 0; for (int i = 0; i < n; i++) { while (j < m && cond) { j++; } }`
    *   **Explanation:** Two-pointer pattern. $i$ and $j$ both move at most $n$ and $m$ times.
    *   **Answer:** $O(n + m)$

40. **Snippet:** `for (int i = 1; i * i * i <= n; i++) { sum++; }`
    *   **Explanation:** Loop runs until $i^3$ exceeds $n$.
    *   **Answer:** $O(n^{1/3})$

## Case Studies: Codeforces Standard Problems

In competitive programming, the problem constraints dictate the required time complexity. Analyzing these constraints is a primary skill for identifying the correct algorithmic pattern.

### Case Study 1: Codeforces 791A - Bear and Big Brother
Limak weighs $a$ and Bob weighs $b$. Limak’s weight triples every year, while Bob’s doubles. We need the years until $a > b$.
*   **Constraints:** $1 \le a \le b \le 10$
*   **Analysis:** Even though the constraints are tiny, the mathematical growth is exponential. The weight ratio $a/b$ increases by a factor of $1.5$ each year. The loop runs while $a \le b$, multiplying $a$ by $3$ and $b$ by $2$.
*   **Complexity:** $O(\log_{1.5} (b/a))$. Because $b$ is at most 10, the loop runs at most a few times.
*   **Optimal Solution:** A simple `while` loop simulation is $O(1)$ relative to the maximum possible $b$.

### Case Study 2: Codeforces 158A - Next Round
Calculate how many participants advance based on a $k$-th finisher's score.
*   **Constraints:** $n \le 50$, $k \le n$
*   **Analysis:** We must read $n$ integers and compare them to the $k$-th value. Any participant with score $\ge \text{score}[k-1]$ and score $> 0$ advances.
*   **Complexity:** Reading the input is $O(n)$. Comparing elements is $O(n)$. Total complexity is $O(n)$.
*   **Optimal Solution:** Linear traversal. With $n=50$, this is essentially instantaneous for an online judge.

### Case Study 3: Codeforces 231A - Team
A team of three solve a problem if at least two are confident.
*   **Constraints:** $n \le 1000$
*   **Analysis:** For $n$ problems, we receive three inputs (0 or 1). We increment our answer if the sum of these three is $\ge 2$.
*   **Complexity:** For each of the $n$ rows, we perform constant-time addition and comparison.
*   **Optimal Solution:** $O(n)$. With $n=1000$, the total operations are 3000, well under the $10^8$ operations allowed per second.
