/*
 * Day 7: Week 1 Contest — "Array Siege"
 * Full Editorial + Solutions (C++ with Python in comments)
 * =========================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <climits>
using namespace std;

// ============================================================
// PROBLEM A — Lucky Prefix (★ 900)
// ============================================================
/*
EDITORIAL:
Intuition: Build prefix sums. For index k, prefix[k] > total - prefix[k]
           → 2*prefix[k] > total. Linear scan, first k satisfying this.

Brute force: O(n²) — recompute both sides for each k.
Optimized:   O(n)  — precompute total, then scan with running prefix.

Key edge cases:
- All equal elements: only k=n satisfies (prefix=total, suffix=0, total>0)
- Single element: k=1 always (prefix=a[0], suffix=0 → a[0]>0 ✓)
- Two equal elements: k=2 works (prefix=total, suffix=0) → output 2, not -1
  Wait: "strictly greater than remaining" — if suffix=0 (empty), prefix=total>0 → YES.
  So for positive arrays answer is always ≤ n. Only -1 if... actually impossible
  for positive arrays since prefix at k=n = total > 0 = suffix at k=n.
  Problem says positive integers (a[i] ≥ 1) so answer always exists.
  But for generality (if 0s are allowed) we keep the -1 path.

Common mistake: Using int instead of long long (sum can reach 2×10^14).
*/
int solveA() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    long long total = 0;
    for (long long x : a) total += x;

    long long prefix = 0;
    for (int k = 1; k <= n; k++) {
        prefix += a[k-1];
        long long suffix = total - prefix;
        if (prefix > suffix) { cout << k << "\n"; return 0; }
    }
    cout << -1 << "\n";
    return 0;
}
/*
Python A:
n = int(input())
a = list(map(int, input().split()))
total = sum(a)
prefix = 0
for k, x in enumerate(a, 1):
    prefix += x
    if prefix > total - prefix:
        print(k); exit()
print(-1)
*/

// ============================================================
// PROBLEM B — Storm Coverage (★ 1100)
// ============================================================
/*
EDITORIAL:
Intuition: Range update [l,r] += v on n up to 10^6, q up to 10^5.
           O(n*q) = 10^11 → TLE. Difference array: O(1) per update, O(n) final pass.

Dry run on example:
  D = [0,0,0,0,0,0]  (size n+2 for safety)
  Storm 1: [1,3]+10 → D[1]+=10, D[4]-=10
  Storm 2: [2,4]+20 → D[2]+=20, D[5]-=20
  Storm 3: [3,5]+5  → D[3]+=5,  D[6]-=5
  Prefix of D: [10, 30, 35, 25, 5, 0] → max=35 at index 3.

Common mistake: 0-indexed vs 1-indexed confusion. D[r+1] must be in bounds.
*/
int solveB() {
    int n, q; cin >> n >> q;
    vector<long long> D(n + 2, 0);
    for (int i = 0; i < q; i++) {
        int l, r; long long rain;
        cin >> l >> r >> rain;
        D[l] += rain;
        if (r + 1 <= n) D[r + 1] -= rain;
    }
    // Reconstruct and find max
    long long maxRain = LLONG_MIN, running = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        running += D[i];
        if (running > maxRain) { maxRain = running; ans = i; }
    }
    cout << ans << "\n";
    return 0;
}
/*
Python B:
n, q = map(int, input().split())
D = [0] * (n + 2)
for _ in range(q):
    l, r, rain = map(int, input().split())
    D[l] += rain
    D[r+1] -= rain
maxr, running, ans = -float('inf'), 0, 1
for i in range(1, n+1):
    running += D[i]
    if running > maxr:
        maxr = running; ans = i
print(ans)
*/

// ============================================================
// PROBLEM C — Zero Hunters (★ 1200)
// ============================================================
/*
EDITORIAL:
Intuition: sum(l..r) = prefix[r] - prefix[l-1] = 0 ↔ prefix[r] = prefix[l-1].
           Count pairs of equal prefix values. If freq[v] = k, these k indices
           contribute C(k,2) = k*(k-1)/2 zero-sum subarrays.
           Plus: prefix[0]=0, and any time prefix[i]=0, subarray [1..i] sums to 0.

Initialize: freq[0] = 1 (the empty prefix).
For each i: ans += freq[prefix[i]]; then freq[prefix[i]]++.

Dry run on [1,-1,2,-2,3,-3]:
  prefix: 0,1,0,2,0,3,0
  At prefix=1: freq[1]=0 → ans+=0, freq[1]=1
  At prefix=0: freq[0]=1 → ans+=1, freq[0]=2
  At prefix=2: ans+=0, freq[2]=1
  At prefix=0: freq[0]=2 → ans+=2, freq[0]=3
  At prefix=3: ans+=0, freq[3]=1
  At prefix=0: freq[0]=3 → ans+=3, freq[0]=4
  Total ans = 0+1+0+2+0+3 = 6... but expected 3.

Hmm — re-verify. Subarrays of [1,-1,2,-2,3,-3] with sum=0:
[1,-1]=0, [2,-2]=0, [3,-3]=0, [1,-1,2,-2]=0, [2,-2,3,-3]=0, [1,-1,2,-2,3,-3]=0 → 6 subarrays, not 3.
The sample in problems.md had an error. The correct answer for [1,-1,2,-2,3,-3] is 6.
Sample 2: [0,0,0,0] → all subarrays. Count = C(5,2) = 10 (pairs in prefix array [0,0,0,0,0]).

Common mistake: Using int prefix when values cause prefix overflow (use long long).
*/
int solveC() {
    int n; cin >> n;
    unordered_map<long long, long long> freq;
    freq[0] = 1;
    long long prefix = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        prefix += x;
        ans += freq[prefix];
        freq[prefix]++;
    }
    cout << ans << "\n";
    return 0;
}
/*
Python C:
from collections import defaultdict
n = int(input())
a = list(map(int, input().split()))
freq = defaultdict(int); freq[0] = 1
prefix = ans = 0
for x in a:
    prefix += x
    ans += freq[prefix]
    freq[prefix] += 1
print(ans)
*/

// ============================================================
// PROBLEM D — Maximum Flip Gain (★ 1400)
// ============================================================
/*
EDITORIAL:
Intuition: Negating [l,r] changes total by -2*sum(l,r).
           New total = original_total - 2 * sum(l,r).
           Maximize → minimize sum(l,r) → use Kadane for MINIMUM subarray sum.

If min_subarray_sum < 0: answer = total - 2 * min_subarray_sum > total.
If min_subarray_sum >= 0: we must still negate something.
   Negate the element with min absolute value (that single element gives max result).
   Or equivalently: run Kadane for min on negated a[] = max of negated,
   but the smallest positive element is cheapest to negate.

Unified formula:
  answer = max(total_sum, total_sum - 2 * min_kadane_sum)
  (If min_kadane_sum >= 0, we get total - something_positive ≤ total,
   so we still pick best single element. But choosing min single element
   is the same as min_subarray of size 1. Kadane's min includes single elements.)

Wait: min_kadane_sum is always ≤ min single element. The minimum subarray
could be a single element or longer. So -2*min_kadane_sum is maximized.
If all positive: min_kadane = min(a[i]) > 0, so we negate that single element.
This is naturally handled by the formula: answer = total - 2*min_kadane.

Dry run on [1,-3,2,-2,4]:
  total = 2
  Kadane min: track min_so_far
  i=0: curr_min = 1, global_min = 1
  i=1: curr_min = min(-3, 1-3) = min(-3,-2) = -3, global_min = -3
  i=2: curr_min = min(2, -3+2) = min(2,-1) = -1, global=-3
  i=3: curr_min = min(-2,-1-2) = min(-2,-3) = -3, global=-3 (tie, global stays -3)
        Actually: curr_min at i=3: min(-2, -1+-2)=min(-2,-3)=-3, global_min=-3
  i=4: curr_min = min(4,-3+4)=min(4,1)=1, global=-3
  min_kadane = -3. answer = 2 - 2*(-3) = 2 + 6 = 8? But expected 13.

Re-check: negate [-3] → [1,3,2,-2,4], total = 8. Not 13.
Negate [-3,2,-2] → [1,3,-2,2,4], total = 8. Still 8.

Hmm the sample expected 13 seems wrong. Let me recompute:
[1,-3,2,-2,4]: total=2. Best negate: [-3] → change: -2*(-3)=+6. New total=8.
Or negate [-3,2,-2] = sum(-3): same result. Or negate just [-3,-2]: sum=-5 → total+10=12.
Actually [-3,...,-2] → indices 1-3 in 0-indexed: [-3,2,-2], sum=-3 → gain=6, total=8.
Negate indices [1,3] = [-3,2,-2,-2]? No, must be contiguous.
Subarray [-3] (len 1): sum=-3, new total = 2-2(-3)=8.
Subarray [-3,2,-2] (len 3): sum=-3, new total=8.
Subarray [2,-2,4] : sum=4, new total=2-8=-6. Bad.

So actual answer for [1,-3,2,-2,4] is 8, not 13. The problem.md sample needs correction.
Let me fix: use [1,-3,2,-2,4] → 8, [-5,2,3,-1,4] → total=3, minSub=-5, 3+10=13.

Let's use A=[-5,2,3,-1,4] for example with output 13.
*/
int solveD() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    long long total = 0;
    for (long long x : a) total += x;

    // Kadane for minimum subarray sum
    long long curr_min = a[0], global_min = a[0];
    for (int i = 1; i < n; i++) {
        curr_min = min(a[i], curr_min + a[i]);
        global_min = min(global_min, curr_min);
    }
    // answer = total - 2 * global_min (negating the min subarray)
    cout << total - 2 * global_min << "\n";
    return 0;
}
/*
Python D:
n = int(input())
a = list(map(int, input().split()))
total = sum(a)
curr_min = global_min = a[0]
for x in a[1:]:
    curr_min = min(x, curr_min + x)
    global_min = min(global_min, curr_min)
print(total - 2 * global_min)
*/

// ============================================================
// PROBLEM E — Dominance Count (★ 1600)
// ============================================================
/*
EDITORIAL:
Intuition: sum(l,r) ≥ 0 ↔ prefix[r] ≥ prefix[l-1].
           Count pairs (i < j) in P[0..n] where P[j] >= P[i].
           = total_pairs - inversions in P.
           Total pairs = C(n+1, 2) = (n+1)*n/2.
           Inversions = pairs (i<j) where P[i] > P[j]. Use merge sort.

O(n²) brute force: enumerate all (i,j) pairs checking P[j] >= P[i].
O(n log n) optimized: merge sort based inversion counting on prefix array.

Alternative: coordinate compress + BIT (Fenwick tree). For each j, count
i < j where P[i] ≤ P[j] using BIT query.

Edge case: n=1 → only subarray is the whole array. One pair (0,1).
           P = [0, a[0]]. If a[0] >= 0, answer=1. Else 0.
*/
long long mergeCount(vector<long long>& arr, int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (l + r) / 2;
    long long cnt = mergeCount(arr, l, mid) + mergeCount(arr, mid, r);
    vector<long long> tmp;
    int i = l, j = mid;
    while (i < mid && j < r) {
        if (arr[i] <= arr[j]) { tmp.push_back(arr[i++]); }
        else {
            cnt += (mid - i);  // all remaining left elements form inversions
            tmp.push_back(arr[j++]);
        }
    }
    while (i < mid) tmp.push_back(arr[i++]);
    while (j < r)   tmp.push_back(arr[j++]);
    copy(tmp.begin(), tmp.end(), arr.begin() + l);
    return cnt;
}

int solveE() {
    int n; cin >> n;
    vector<long long> P(n + 1);
    P[0] = 0;
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        P[i] = P[i-1] + x;
    }
    long long total = (long long)(n+1) * n / 2;
    long long inversions = mergeCount(P, 0, n + 1);
    cout << total - inversions << "\n";
    return 0;
}
/*
Python E (O(n^2) for small n, replace with BIT for large):
n = int(input())
a = list(map(int, input().split()))
P = [0]
for x in a: P.append(P[-1]+x)
ans = 0
for i in range(len(P)):
    for j in range(i+1, len(P)):
        if P[j] >= P[i]: ans += 1
print(ans)
# O(n log n): use SortedList or BIT with coordinate compression
*/

// ============================================================
// PROBLEM F — Circular Champion (★ 1700)
// ============================================================
/*
EDITORIAL:
Intuition: Two cases for max circular subarray:
  Case 1 (no wrap): Standard Kadane → linear max.
  Case 2 (wrap):    Wrapping subarray = total - (some middle non-wrapping subarray).
                    Maximize by minimizing the excluded middle = min subarray sum.
                    circular_max = total_sum - min_subarray_sum.

Answer = max(case1, case2).

CRITICAL GUARD: If all elements are negative, min_subarray = total (entire array),
so case2 = total - total = 0. But we cannot pick empty subarray. Return case1.
Detection: if max_linear < 0, all elements negative → return max_linear.

Dry run on [5,-2,3,-6,4]:
  total = 4
  Kadane max: 5, 3, 6(-2+3... wait): 
    curr=5,best=5 → curr=max(-2,5-2)=3,best=5 → curr=max(3,3+3)=6,best=6
    → curr=max(-6,6-6)=0,best=6 → curr=max(4,0+4)=4,best=6.
  max_linear=6.
  Kadane min (for case2):
    curr=5,min=5 → curr=min(-2,5-2)=-2,min=-2 → curr=min(3,-2+3)=1... 
    wait: min(3,-2+3)=min(3,1)=1,min=-2 → curr=min(-6,1-6)=-6,min=-6
    → curr=min(4,-6+4)=-2,min=-6.
  min_linear=-6. case2 = 4-(-6) = 10.
  Answer = max(6,10) = 10 ✓

Common mistake: Forgetting the all-negative guard.
*/
int solveF() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    long long total = 0;
    for (int x : a) total += x;

    // Kadane for max
    long long curr_max = a[0], max_lin = a[0];
    // Kadane for min
    long long curr_min = a[0], min_lin = a[0];
    for (int i = 1; i < n; i++) {
        curr_max = max((long long)a[i], curr_max + a[i]);
        max_lin  = max(max_lin, curr_max);
        curr_min = min((long long)a[i], curr_min + a[i]);
        min_lin  = min(min_lin, curr_min);
    }

    // All-negative guard
    if (max_lin < 0) { cout << max_lin << "\n"; return 0; }
    cout << max(max_lin, total - min_lin) << "\n";
    return 0;
}
/*
Python F:
n = int(input())
a = list(map(int, input().split()))
total = sum(a)
c_max = mx = c_min = mn = a[0]
for x in a[1:]:
    c_max = max(x, c_max+x); mx = max(mx, c_max)
    c_min = min(x, c_min+x); mn = min(mn, c_min)
print(mx if mx < 0 else max(mx, total - mn))
*/

// ============================================================
// PROBLEM G — Double Harvest (★ 1900)
// ============================================================
/*
EDITORIAL:
Intuition: For every split point i (1 ≤ i ≤ n-1):
  pick best subarray from a[0..i-1] + best subarray from a[i..n-1].
  Precompute L[i] = max subarray sum in a[0..i] (forward, updated as i grows).
  Precompute R[i] = max subarray sum in a[i..n-1] (backward, from right).
  Answer = max over i=0..n-2 of L[i] + R[i+1].

L[i]: Run Kadane left-to-right, keeping a running global max.
R[i]: Run Kadane right-to-left (symmetric), keeping a running global max from right.

Time: O(n). Space: O(n) for L and R arrays.

Dry run on [-1,3,-2,4]:
  Forward Kadane (L):
    i=0: curr=-1, best=-1, L[0]=-1
    i=1: curr=max(3,-1+3)=3, best=3, L[1]=3
    i=2: curr=max(-2,3-2)=1, best=3, L[2]=3
    i=3: curr=max(4,1+4)=5, best=5, L[3]=5
  Backward Kadane (R):
    i=3: curr=4, best=4, R[3]=4
    i=2: curr=max(-2,-2+4)=2, best=4, R[2]=4
    i=1: curr=max(3,3+2)=5, best=5, R[1]=5
    i=0: curr=max(-1,-1+5)=4, best=5, R[0]=5
  Candidates: L[0]+R[1]=-1+5=4, L[1]+R[2]=3+4=7, L[2]+R[3]=3+4=7.
  Answer = 7 ✓

Edge case: n=2 → only one split: L[0] + R[1] = a[0] + a[1].
If both elements negative: pick max of each (forced).
Must ensure both subarrays are non-empty → L[i] and R[i+1] are always ≥ min element.

Common mistake: Not tracking best-so-far separately from curr in L/R build.
*/
int solveG() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    // L[i] = max subarray sum in a[0..i]
    vector<long long> L(n), R(n);
    long long curr = a[0], best = a[0];
    L[0] = best;
    for (int i = 1; i < n; i++) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
        L[i] = best;
    }

    // R[i] = max subarray sum in a[i..n-1]
    curr = a[n-1]; best = a[n-1];
    R[n-1] = best;
    for (int i = n-2; i >= 0; i--) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
        R[i] = best;
    }

    long long ans = LLONG_MIN;
    for (int i = 0; i < n-1; i++)
        ans = max(ans, L[i] + R[i+1]);
    cout << ans << "\n";
    return 0;
}
/*
Python G:
n = int(input())
a = list(map(int, input().split()))
L = [0]*n; R = [0]*n
curr = best = a[0]; L[0] = best
for i in range(1, n):
    curr = max(a[i], curr+a[i]); best = max(best, curr); L[i] = best
curr = best = a[-1]; R[-1] = best
for i in range(n-2, -1, -1):
    curr = max(a[i], curr+a[i]); best = max(best, curr); R[i] = best
print(max(L[i]+R[i+1] for i in range(n-1)))
*/

// ============================================================
// COMMON MISTAKES SUMMARY
// ============================================================
/*
1. A: Using int for prefix sum — values reach 2×10^14.
2. B: D[r+1] out of bounds when r = n (allocate D of size n+2).
3. C: Forgetting freq[0]=1 initialization — misses subarrays from index 1.
4. D: Forgetting to handle "must negate something" — min subarray ≥ 0 case
      is handled automatically by Kadane's min (picks least positive single element).
5. E: Off-by-one in prefix size (should be n+1 elements: P[0..n]).
6. F: All-negative guard — without it, returns 0 (wrong, empty subarray not allowed).
7. G: Not tracking best separately from curr — L[i] must be global max, not just local.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // Call appropriate solver based on problem
    // solveA(); solveB(); solveC(); solveD(); solveE(); solveF(); solveG();
    return 0;
}
