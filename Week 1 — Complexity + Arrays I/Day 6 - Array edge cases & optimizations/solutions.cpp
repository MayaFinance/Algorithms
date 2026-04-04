/*
 * Day 6: Array Edge Cases & Optimizations
 * Complete C++ Reference Solutions
 * ======================================
 * Includes Python solutions as comment blocks.
 * All solutions: optimal time & space complexity.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>
#include <stack>
#include <numeric>
#include <climits>
#include <cassert>
using namespace std;

// ============================================================
// LEVEL 1: WARM-UP
// ============================================================

// ---------------------------------------------------------
// Problem 1: Running Sum Queries (Prefix Sum)
// Time: O(n) build + O(1) per query | Space: O(n)
// ---------------------------------------------------------
class RangeSumQuery {
    vector<long long> prefix;
public:
    // Build prefix sum array in O(n)
    RangeSumQuery(vector<int>& A) {
        int n = A.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + A[i];  // prefix[i+1] = sum of A[0..i]
    }
    // Query sum of A[l..r] in O(1)
    long long query(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }
};
/*
Python:
class RangeSumQuery:
    def __init__(self, A):
        self.prefix = [0] * (len(A) + 1)
        for i, x in enumerate(A):
            self.prefix[i+1] = self.prefix[i] + x
    def query(self, l, r):
        return self.prefix[r+1] - self.prefix[l]
*/

// ---------------------------------------------------------
// Problem 2: Find Missing Number
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    // Gauss formula: sum of 0..n = n*(n+1)/2
    long long expected = (long long)n * (n + 1) / 2;
    long long actual = 0;
    for (int x : nums) actual += x;
    return (int)(expected - actual);
    // Alternative XOR approach:
    // int xorAll = 0;
    // for (int i = 0; i <= n; i++) xorAll ^= i;
    // for (int x : nums) xorAll ^= x;
    // return xorAll;
}
/*
Python:
def missingNumber(nums):
    n = len(nums)
    return n*(n+1)//2 - sum(nums)
    # XOR approach: reduce(xor, range(n+1)) ^ reduce(xor, nums)
*/

// ---------------------------------------------------------
// Problem 3: Move Zeros to End
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
void moveZeroes(vector<int>& nums) {
    int write = 0;  // write pointer: next position for non-zero
    // Pass 1: write all non-zeros in order
    for (int x : nums)
        if (x != 0) nums[write++] = x;
    // Pass 2: fill remaining positions with zeros
    while (write < (int)nums.size()) nums[write++] = 0;
}
/*
Python:
def moveZeroes(nums):
    write = 0
    for x in nums:
        if x != 0:
            nums[write] = x
            write += 1
    while write < len(nums):
        nums[write] = 0
        write += 1
*/

// ---------------------------------------------------------
// Problem 4: Check if Array is Sorted & Rotated
// Time: O(n) | Space: O(1)
// Key insight: a sorted+rotated array has at most ONE drop point
// ---------------------------------------------------------
bool check(vector<int>& nums) {
    int n = nums.size();
    int drops = 0;
    for (int i = 0; i < n; i++) {
        // Use modular indexing to check circular neighbor
        if (nums[i] > nums[(i + 1) % n]) drops++;
        if (drops > 1) return false;  // More than 1 break → cannot be rotation
    }
    return true;
}
/*
Python:
def check(nums):
    n = len(nums)
    drops = sum(1 for i in range(n) if nums[i] > nums[(i+1) % n])
    return drops <= 1
*/

// ============================================================
// LEVEL 2: CORE
// ============================================================

// ---------------------------------------------------------
// Problem 5: Longest Subarray with Sum ≤ K (Non-Negative Only)
// Time: O(n) | Space: O(1)
// ONLY works for non-negative values (monotonic window property)
// ---------------------------------------------------------
int longestSubarraySumAtMostK(vector<int>& A, int k) {
    int n = A.size(), l = 0, ans = 0;
    long long sum = 0;
    for (int r = 0; r < n; r++) {
        sum += A[r];
        // Shrink window from left when sum exceeds k
        while (sum > k) sum -= A[l++];
        ans = max(ans, r - l + 1);
    }
    return ans;
}
/*
Python:
def longestSubarray(A, k):
    l, total, ans = 0, 0, 0
    for r, x in enumerate(A):
        total += x
        while total > k:
            total -= A[l]; l += 1
        ans = max(ans, r - l + 1)
    return ans
*/

// ---------------------------------------------------------
// Problem 6: Count Subarrays with Sum = K
// Time: O(n) | Space: O(n)
// KEY: Sliding window FAILS with negatives. Use prefix + map.
// ---------------------------------------------------------
int subarraySum(vector<int>& nums, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;        // Critical: empty prefix has sum 0
    long long prefix = 0;
    int count = 0;
    for (int x : nums) {
        prefix += x;
        // How many prefixes ended with value (prefix - k)?
        // Those subarrays all sum to exactly k when ending here.
        count += freq[prefix - k];
        freq[prefix]++;
    }
    return count;
}
/*
Python:
from collections import defaultdict
def subarraySum(nums, k):
    freq = defaultdict(int)
    freq[0] = 1
    prefix, count = 0, 0
    for x in nums:
        prefix += x
        count += freq[prefix - k]
        freq[prefix] += 1
    return count
*/

// ---------------------------------------------------------
// Problem 7: Maximum Sum of Non-Adjacent Elements (House Robber)
// Time: O(n) | Space: O(1)
// DP recurrence: dp[i] = max(dp[i-2] + A[i], dp[i-1])
// ---------------------------------------------------------
int rob(vector<int>& A) {
    int n = A.size();
    if (n == 1) return A[0];          // Edge case: single element
    int prev2 = 0, prev1 = 0;
    for (int x : A) {
        int curr = max(prev1, prev2 + x);  // extend from 2 steps back OR skip
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
/*
Python:
def rob(A):
    prev2 = prev1 = 0
    for x in A:
        prev2, prev1 = prev1, max(prev1, prev2 + x)
    return prev1
*/

// ---------------------------------------------------------
// Problem 8: Minimum Size Subarray Sum ≥ S (Positive Only)
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
int minSubArrayLen(int s, vector<int>& A) {
    int n = A.size(), l = 0, ans = INT_MAX;
    long long sum = 0;
    for (int r = 0; r < n; r++) {
        sum += A[r];
        // Shrink window from left while constraint is satisfied
        while (sum >= s) {
            ans = min(ans, r - l + 1);
            sum -= A[l++];
        }
    }
    return (ans == INT_MAX) ? 0 : ans;
}
/*
Python:
def minSubArrayLen(s, A):
    l, total, ans = 0, 0, float('inf')
    for r, x in enumerate(A):
        total += x
        while total >= s:
            ans = min(ans, r - l + 1)
            total -= A[l]; l += 1
    return 0 if ans == float('inf') else ans
*/

// ---------------------------------------------------------
// Problem 9: Product of Array Except Self
// Time: O(n) | Space: O(1) extra (output array not counted)
// ---------------------------------------------------------
vector<int> productExceptSelf(vector<int>& A) {
    int n = A.size();
    vector<int> result(n, 1);

    // Forward pass: result[i] = product of all A[0..i-1]
    int left = 1;
    for (int i = 0; i < n; i++) {
        result[i] = left;
        left *= A[i];
    }

    // Backward pass: multiply result[i] by product of all A[i+1..n-1]
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= right;
        right *= A[i];
    }
    return result;
}
/*
Python:
def productExceptSelf(A):
    n = len(A)
    result = [1] * n
    left = 1
    for i in range(n):
        result[i] = left
        left *= A[i]
    right = 1
    for i in range(n-1, -1, -1):
        result[i] *= right
        right *= A[i]
    return result
*/

// ---------------------------------------------------------
// Problem 10: Trapping Rain Water
// Time: O(n) | Space: O(1) — two pointer approach
// ---------------------------------------------------------
int trap(vector<int>& height) {
    int l = 0, r = (int)height.size() - 1;
    int lmax = 0, rmax = 0, water = 0;
    while (l < r) {
        if (height[l] <= height[r]) {
            // Right side is guaranteed tall enough.
            // Water at l is determined by lmax alone.
            if (height[l] >= lmax) lmax = height[l];
            else water += lmax - height[l];
            l++;
        } else {
            // Left side is tall enough.
            // Water at r is determined by rmax alone.
            if (height[r] >= rmax) rmax = height[r];
            else water += rmax - height[r];
            r--;
        }
    }
    return water;
}
/*
Python:
def trap(height):
    l, r, lmax, rmax, water = 0, len(height)-1, 0, 0, 0
    while l < r:
        if height[l] <= height[r]:
            if height[l] >= lmax: lmax = height[l]
            else: water += lmax - height[l]
            l += 1
        else:
            if height[r] >= rmax: rmax = height[r]
            else: water += rmax - height[r]
            r -= 1
    return water
*/

// ============================================================
// LEVEL 3: ADVANCED
// ============================================================

// ---------------------------------------------------------
// Problem 11: Maximum Sum After K Negations
// Time: O(n log n) | Space: O(1)
// Strategy: sort, flip negatives (most negative first), if k
// remains odd after all negatives flipped, flip smallest |abs|
// ---------------------------------------------------------
int largestSumAfterKNegations(vector<int>& A, int k) {
    // Sort by absolute value descending to process greedily
    sort(A.begin(), A.end(), [](int a, int b) {
        return abs(a) > abs(b);
    });
    for (int i = 0; i < (int)A.size() && k > 0; i++) {
        if (A[i] < 0) {           // Flip negatives first (highest magnitude)
            A[i] = -A[i];
            k--;
        }
    }
    // If k is still odd, flip the smallest absolute value (last element after sort)
    if (k % 2 == 1) A.back() = -A.back();
    return accumulate(A.begin(), A.end(), 0);
}
/*
Python:
def largestSumAfterKNegations(A, k):
    A.sort(key=abs, reverse=True)
    for i in range(len(A)):
        if A[i] < 0 and k > 0:
            A[i] = -A[i]; k -= 1
    if k % 2 == 1:
        A[-1] = -A[-1]
    return sum(A)
*/

// ---------------------------------------------------------
// Problem 12: Maximum Width Ramp
// Time: O(n) | Space: O(n)
// Monotone decreasing stack for left candidates, then right sweep.
// ---------------------------------------------------------
int maxWidthRamp(vector<int>& A) {
    int n = A.size(), ans = 0;
    stack<int> stk;  // Stores indices forming decreasing values (candidate left edges)

    // Build monotone decreasing stack of left-endpoint indices
    for (int i = 0; i < n; i++) {
        if (stk.empty() || A[stk.top()] > A[i])
            stk.push(i);
    }

    // Sweep from right: for each j, pop valid left-endpoints
    for (int j = n - 1; j >= 0; j--) {
        while (!stk.empty() && A[stk.top()] <= A[j]) {
            ans = max(ans, j - stk.top());
            stk.pop();  // This index can't give a wider ramp → safe to discard
        }
    }
    return ans;
}
/*
Python:
def maxWidthRamp(A):
    n = len(A)
    stack = []
    for i in range(n):
        if not stack or A[stack[-1]] > A[i]:
            stack.append(i)
    ans = 0
    for j in range(n-1, -1, -1):
        while stack and A[stack[-1]] <= A[j]:
            ans = max(ans, j - stack[-1])
            stack.pop()
    return ans
*/

// ---------------------------------------------------------
// Problem 13: Shortest Subarray with Sum ≥ K (Negatives Allowed)
// Time: O(n) | Space: O(n)
// Uses prefix sum + monotone deque (minimum prefix tracking)
// Sliding window FAILS because negatives break monotonicity.
// ---------------------------------------------------------
int shortestSubarray(vector<int>& A, int k) {
    int n = A.size(), ans = INT_MAX;
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + A[i];

    deque<int> dq;  // Indices of monotonically increasing prefix values
    for (int r = 0; r <= n; r++) {
        // Pop from front: if prefix[r] - prefix[dq.front()] >= k,
        // we found a valid subarray; try to minimize length
        while (!dq.empty() && prefix[r] - prefix[dq.front()] >= k) {
            ans = min(ans, r - dq.front());
            dq.pop_front();
        }
        // Maintain increasing order in deque (pop worse candidates from back)
        while (!dq.empty() && prefix[dq.back()] >= prefix[r])
            dq.pop_back();
        dq.push_back(r);
    }
    return (ans == INT_MAX) ? -1 : ans;
}
/*
Python:
from collections import deque
def shortestSubarray(A, k):
    n = len(A)
    prefix = [0] * (n + 1)
    for i, x in enumerate(A):
        prefix[i+1] = prefix[i] + x
    dq = deque()
    ans = float('inf')
    for r in range(n + 1):
        while dq and prefix[r] - prefix[dq[0]] >= k:
            ans = min(ans, r - dq.popleft())
        while dq and prefix[dq[-1]] >= prefix[r]:
            dq.pop()
        dq.append(r)
    return -1 if ans == float('inf') else ans
*/

// ---------------------------------------------------------
// Problem 14: Maximum Score (min × length) — Largest Rect Variant
// Time: O(n) | Space: O(n)
// Monotone stack: find prev_smaller and next_smaller for each index.
// Each element A[i] is the minimum for exactly one maximal range.
// ---------------------------------------------------------
long long maxScore(vector<int>& A) {
    int n = A.size();
    // prev_smaller[i] = index of first element to the left < A[i]
    // next_smaller[i] = index of first element to the right < A[i]
    vector<int> prev_s(n, -1), next_s(n, n);
    stack<int> stk;

    // Compute previous smaller (monotone increasing stack)
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && A[stk.top()] >= A[i]) stk.pop();
        prev_s[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();

    // Compute next smaller
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && A[stk.top()] >= A[i]) stk.pop();
        next_s[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        // A[i] is the min for the range (prev_s[i]+1 .. next_s[i]-1)
        long long width = next_s[i] - prev_s[i] - 1;
        ans = max(ans, (long long)A[i] * width);
    }
    return ans;
}
/*
Python:
def maxScore(A):
    n = len(A)
    prev_s, next_s = [-1]*n, [n]*n
    stack = []
    for i, x in enumerate(A):
        while stack and A[stack[-1]] >= x:
            stack.pop()
        prev_s[i] = stack[-1] if stack else -1
        stack.append(i)
    stack = []
    for i in range(n-1, -1, -1):
        while stack and A[stack[-1]] >= A[i]:
            stack.pop()
        next_s[i] = stack[-1] if stack else n
        stack.append(i)
    return max(A[i] * (next_s[i] - prev_s[i] - 1) for i in range(n))
*/

// ---------------------------------------------------------
// Problem 15: Subarray Sum Divisible by K
// Time: O(n) | Space: O(k)
// KEY: ((prefix % k) + k) % k normalizes negative remainders
// ---------------------------------------------------------
int subarraysDivByK(vector<int>& A, int k) {
    unordered_map<int, int> freq;
    freq[0] = 1;   // Empty prefix has remainder 0
    int prefix = 0, count = 0;
    for (int x : A) {
        prefix += x;
        // Normalize: C++ '%' can return negative for negative numbers
        int rem = ((prefix % k) + k) % k;
        count += freq[rem];
        freq[rem]++;
    }
    return count;
}
/*
Python:
from collections import defaultdict
def subarraysDivByK(A, k):
    freq = defaultdict(int)
    freq[0] = 1
    prefix = count = 0
    for x in A:
        prefix += x
        rem = prefix % k   # Python '%' is always non-negative
        count += freq[rem]
        freq[rem] += 1
    return count
*/

// ============================================================
// EDGE CASE STRESS TESTS (inline verification)
// ============================================================

void runTests() {
    // Problem 2: Missing Number edge cases
    vector<int> t1 = {0};         assert(missingNumber(t1) == 1);
    vector<int> t2 = {1};         assert(missingNumber(t2) == 0);
    vector<int> t3 = {0, 1};      assert(missingNumber(t3) == 2);

    // Problem 3: Move Zeros edge cases
    vector<int> m1 = {0, 0, 0};  moveZeroes(m1); assert(m1 == vector<int>({0,0,0}));
    vector<int> m2 = {1, 2, 3};  moveZeroes(m2); assert(m2 == vector<int>({1,2,3}));

    // Problem 4: Check sorted & rotated
    vector<int> c1 = {1};         assert(check(c1) == true);
    vector<int> c2 = {3,4,5,1,2}; assert(check(c2) == true);
    vector<int> c3 = {2,1,3,4};   assert(check(c3) == false);

    // Problem 6: Count subarrays sum = k
    vector<int> s1 = {1,-1,1};   assert(subarraySum(s1, 1) == 3);
    vector<int> s2 = {1,1,1};    assert(subarraySum(s2, 2) == 2);

    // Problem 10: Trapping rain water
    vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1}; assert(trap(h1) == 6);
    vector<int> h2 = {4,2,0,3,2,5};               assert(trap(h2) == 9);
    vector<int> h3 = {1};                          assert(trap(h3) == 0);

    cout << "All tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}
