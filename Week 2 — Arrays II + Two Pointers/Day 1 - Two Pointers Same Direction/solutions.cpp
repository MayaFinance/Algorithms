/*
 * Week 2 — Day 1: Two Pointers (Same Direction)
 * Full Solutions with Dry Runs, Complexity, Edge Cases
 * =====================================================
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

// ---------------------------------------------------------
// Problem 1: Remove Element (LC 27)
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != val)          // keep this element
            nums[slow++] = nums[fast];  // write then advance slow
    }
    return slow;  // new length
}
/*
Dry run: [3,2,2,3], val=3
fast=0: nums[0]=3==val → skip. slow=0
fast=1: nums[1]=2≠val → nums[0]=2, slow=1
fast=2: nums[2]=2≠val → nums[1]=2, slow=2
fast=3: nums[3]=3==val → skip. slow=2
Return 2. Array prefix = [2,2]. ✓

Python:
def removeElement(nums, val):
    slow = 0
    for x in nums:
        if x != val:
            nums[slow] = x; slow += 1
    return slow
*/

// ---------------------------------------------------------
// Problem 2: Remove Duplicates I (LC 26)
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 1;  // first element always kept, slow = next write pos
    for (int fast = 1; fast < (int)nums.size(); fast++) {
        if (nums[fast] != nums[slow - 1])  // new unique element
            nums[slow++] = nums[fast];
    }
    return slow;
}
/*
Dry run: [1,1,2,2,3]
slow=1. fast=1: 1==1 skip. fast=2: 2≠1 → nums[1]=2,slow=2
fast=3: 2==2 skip. fast=4: 3≠2 → nums[2]=3, slow=3. Return 3. [1,2,3] ✓

Python:
def removeDuplicates(nums):
    slow = 1
    for fast in range(1, len(nums)):
        if nums[fast] != nums[slow-1]:
            nums[slow] = nums[fast]; slow += 1
    return slow
*/

// ---------------------------------------------------------
// Problem 3: Remove Duplicates II — Keep at Most 2 (LC 80)
// Time: O(n) | Space: O(1)
// Key: compare fast with arr[slow-2], not arr[slow-1]
// ---------------------------------------------------------
int removeDuplicatesII(vector<int>& nums) {
    int slow = 0;
    for (int x : nums) {
        // Keep if we've written fewer than 2 elements OR
        // current element differs from the element 2 positions back
        if (slow < 2 || x != nums[slow - 2])
            nums[slow++] = x;
    }
    return slow;
}
/*
Dry run: [1,1,1,2,2,3]
x=1: slow=0<2 → write, slow=1
x=1: slow=1<2 → write, slow=2
x=1: nums[0]=1==x → skip (would be 3rd copy)
x=2: nums[0]=1≠2 → write, slow=3
x=2: nums[1]=1≠2 → write, slow=4
x=3: nums[2]=1≠3 → write, slow=5
Return 5. [1,1,2,2,3] ✓

Python:
def removeDuplicatesII(nums):
    slow = 0
    for x in nums:
        if slow < 2 or x != nums[slow-2]:
            nums[slow] = x; slow += 1
    return slow
*/

// ---------------------------------------------------------
// Problem 4: Move Zeros (LC 283)
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int x : nums)
        if (x != 0) nums[slow++] = x;
    while (slow < (int)nums.size()) nums[slow++] = 0;
}
/*
Python:
def moveZeroes(nums):
    slow = 0
    for x in nums:
        if x: nums[slow] = x; slow += 1
    while slow < len(nums): nums[slow] = 0; slow += 1
*/

// ---------------------------------------------------------
// Problem 5: Squares of Sorted Array (LC 977)
// Two-pointer from BOTH ends (opposite-direction variant)
// Time: O(n) | Space: O(n)
// ---------------------------------------------------------
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1, write = n - 1;
    vector<int> res(n);
    while (l <= r) {
        long long sl = (long long)nums[l] * nums[l];
        long long sr = (long long)nums[r] * nums[r];
        if (sl > sr) { res[write--] = sl; l++; }
        else         { res[write--] = sr; r--; }
    }
    return res;
}
/*
Dry run: [-4,-1,0,3,10]
l=0,r=4: 16 vs 100 → res[4]=100, r=3
l=0,r=3: 16 vs  9  → res[3]=16,  l=1
l=1,r=3:  1 vs  9  → res[2]=9,   r=2
l=1,r=2:  1 vs  0  → res[1]=1,   l=2
l=2,r=2:  0 vs  0  → res[0]=0,   r=1 (loop ends)
Result: [0,1,9,16,100] ✓

Python:
def sortedSquares(nums):
    l, r, res = 0, len(nums)-1, []
    while l <= r:
        sl, sr = nums[l]**2, nums[r]**2
        if sl > sr: res.append(sl); l += 1
        else:       res.append(sr); r -= 1
    return res[::-1]
*/

// ---------------------------------------------------------
// Problem 6: Find Duplicate — Floyd's Cycle (LC 287)
// Phase 1: find meeting point. Phase 2: find cycle start.
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
int findDuplicate(vector<int>& nums) {
    // Phase 1: tortoise and hare
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: find cycle entry (= duplicate)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
/*
Dry run: [1,3,4,2,2]
Phase 1: slow=1→3→2→4→2, fast=1→4→2→2. Meet at 2.
Phase 2: slow=1, fast=2. slow=3, fast=4. slow=2, fast=2. Return 2. ✓

Python:
def findDuplicate(nums):
    slow = fast = nums[0]
    while True:
        slow = nums[slow]; fast = nums[nums[fast]]
        if slow == fast: break
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]; fast = nums[fast]
    return slow
*/

// ---------------------------------------------------------
// Problem 7: Longest Substring Without Repeating (LC 3)
// Sliding window with last-seen index map
// Time: O(n) | Space: O(charset)
// ---------------------------------------------------------
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last;  // char → last seen index
    int left = 0, ans = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];
        // If c was seen inside current window, shrink left past it
        if (last.count(c) && last[c] >= left)
            left = last[c] + 1;
        last[c] = right;
        ans = max(ans, right - left + 1);
    }
    return ans;
}
/*
Dry run: "abcabcbb"
r=0 'a': last={a:0}, left=0, len=1
r=1 'b': last={a:0,b:1}, len=2
r=2 'c': last={a:0,b:1,c:2}, len=3
r=3 'a': last[a]=0>=left=0 → left=1. last[a]=3. len=3
r=4 'b': last[b]=1>=1 → left=2. last[b]=4. len=3
r=5 'c': last[c]=2>=2 → left=3. last[c]=5. len=3
r=6 'b': last[b]=4>=3 → left=5. last[b]=6. len=2
r=7 'b': last[b]=6>=5 → left=7. len=1
Answer=3 ✓

Python:
def lengthOfLongestSubstring(s):
    last, left, ans = {}, 0, 0
    for right, c in enumerate(s):
        if c in last and last[c] >= left:
            left = last[c] + 1
        last[c] = right
        ans = max(ans, right - left + 1)
    return ans
*/

// ---------------------------------------------------------
// Problem 8: Minimum Size Subarray Sum (LC 209)
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
int minSubArrayLen(int s, vector<int>& nums) {
    int left = 0, ans = INT_MAX;
    long long sum = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        sum += nums[right];
        while (sum >= s) {  // valid window — try to shrink
            ans = min(ans, right - left + 1);
            sum -= nums[left++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
/*
Python:
def minSubArrayLen(s, nums):
    left = total = 0; ans = float('inf')
    for right, x in enumerate(nums):
        total += x
        while total >= s:
            ans = min(ans, right - left + 1)
            total -= nums[left]; left += 1
    return 0 if ans == float('inf') else ans
*/

// ---------------------------------------------------------
// Problem 9: Merge Sorted Array (LC 88)
// Fill from back to avoid overwriting unread elements
// Time: O(m+n) | Space: O(1)
// ---------------------------------------------------------
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {  // while nums2 has elements left
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
}
/*
Dry run: nums1=[1,2,3,0,0,0] m=3, nums2=[2,5,6] n=3
i=2,j=2,k=5: 3<6 → nums1[5]=6, j=1, k=4
i=2,j=1,k=4: 3<5 → nums1[4]=5, j=0, k=3
i=2,j=0,k=3: 3>2 → nums1[3]=3, i=1, k=2
i=1,j=0,k=2: 2==2 → (j branch) nums1[2]=2, j=-1
Loop ends (j<0). nums1=[1,2,2,3,5,6] ✓

Python:
def merge(nums1, m, nums2, n):
    i, j, k = m-1, n-1, m+n-1
    while j >= 0:
        if i >= 0 and nums1[i] > nums2[j]:
            nums1[k] = nums1[i]; i -= 1
        else:
            nums1[k] = nums2[j]; j -= 1
        k -= 1
*/

// ---------------------------------------------------------
// Problem 10: Count Pairs with Sum < K (sorted array)
// Opposite-direction pointers on sorted array
// Time: O(n log n) | Space: O(1)
// ---------------------------------------------------------
long long countPairsLessThan(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    int l = 0, r = (int)a.size() - 1;
    long long count = 0;
    while (l < r) {
        if (a[l] + a[r] < k) {
            count += (r - l);  // all pairs (l, l+1..r) are valid
            l++;
        } else {
            r--;
        }
    }
    return count;
}
/*
Python:
def countPairsLessThan(a, k):
    a.sort(); l, r, count = 0, len(a)-1, 0
    while l < r:
        if a[l]+a[r] < k: count += r-l; l += 1
        else: r -= 1
    return count
*/

// ---------------------------------------------------------
// Problem 11: Subarray Product Less Than K (LC 713)
// Time: O(n) | Space: O(1) — only works for positive nums
// ---------------------------------------------------------
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;  // edge: product always ≥ 1 for positive nums
    int left = 0, ans = 0;
    long long prod = 1;
    for (int right = 0; right < (int)nums.size(); right++) {
        prod *= nums[right];
        while (prod >= k) prod /= nums[left++];
        ans += right - left + 1;  // subarrays ending at right with left..right
    }
    return ans;
}
/*
Dry run: [10,5,2,6], k=100
r=0: prod=10<100, left=0, ans+=1=1
r=1: prod=50<100, ans+=2=3
r=2: prod=100≥100 → div by 10, left=1. prod=10<100, ans+=2=5
r=3: prod=60<100, ans+=3=8
Answer=8 ✓

Python:
def numSubarrayProductLessThanK(nums, k):
    if k <= 1: return 0
    left = ans = 0; prod = 1
    for right, x in enumerate(nums):
        prod *= x
        while prod >= k: prod //= nums[left]; left += 1
        ans += right - left + 1
    return ans
*/

// ---------------------------------------------------------
// Problem 12: Max Consecutive Ones III (LC 1004)
// Sliding window: track count of zeros in window
// Time: O(n) | Space: O(1)
// ---------------------------------------------------------
int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeros = 0, ans = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        if (nums[right] == 0) zeros++;
        while (zeros > k) {
            if (nums[left++] == 0) zeros--;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}
/*
Python:
def longestOnes(nums, k):
    left = zeros = ans = 0
    for right, x in enumerate(nums):
        if x == 0: zeros += 1
        while zeros > k:
            if nums[left] == 0: zeros -= 1
            left += 1
        ans = max(ans, right - left + 1)
    return ans
*/

// ---------------------------------------------------------
// QUIZ ANSWERS
// ---------------------------------------------------------
/*
Q1: slow = 1 (first element always kept; slow = next write position)
Q2: Mathematical: if cycle length L, when slow meets fast inside cycle,
    the distance from head to cycle_start = distance from meeting_point
    to cycle_start (can be proved algebraically). So both pointers meet there.
Q3: Sliding window is monotonic (adding positive values always grows product).
    For exact-count subarrays (like subarray sum = k), a single element
    can make the window either valid or not — you can't cleanly shrink.
    Use prefix + HashMap instead.
Q4: Front-fill would overwrite unread nums1 elements before we read them,
    losing data. Back-fill uses the already-empty tail space.
Q5: slow equals the NEW LENGTH. It is the next position to write — one past
    the last valid element (0-indexed last valid is at slow-1).
*/

int main() {
    // Sample tests
    vector<int> a = {3,2,2,3};
    cout << removeElement(a, 3) << "\n";  // 2

    vector<int> b = {1,1,2,2,3};
    cout << removeDuplicates(b) << "\n";  // 3

    vector<int> c = {1,1,1,2,2,3};
    cout << removeDuplicatesII(c) << "\n";  // 5

    cout << lengthOfLongestSubstring("abcabcbb") << "\n";  // 3

    vector<int> d = {1,3,4,2,2};
    cout << findDuplicate(d) << "\n";  // 2

    vector<int> e = {10,5,2,6};
    cout << numSubarrayProductLessThanK(e, 100) << "\n";  // 8

    return 0;
}
