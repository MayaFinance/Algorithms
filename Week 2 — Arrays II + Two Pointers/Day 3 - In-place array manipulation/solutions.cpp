/*
 * Week 2 — Day 3: In-Place Array Manipulation
 * Core Solutions with Dry Runs + Python
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// P1: Move Zeros In-Place O(n)/O(1)
void moveZeroes(vector<int>& a) {
    int slow = 0;
    for (int x : a) if (x) a[slow++] = x;
    while (slow < (int)a.size()) a[slow++] = 0;
}

// P2: Remove Duplicates from Sorted — see Day 1

// P3: Find All Duplicates in Array [1..n] using sign-marking O(n)/O(1)
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int x : nums) {
        int idx = abs(x) - 1;
        if (nums[idx] < 0) res.push_back(abs(x));
        else nums[idx] = -nums[idx];
    }
    return res;
}
/*
Key: value v maps to index v-1. First visit: negate. Second visit: already negative → duplicate.
Example: [4,3,2,7,8,2,3,1]
x=4: idx=3, nums[3]=7>0 → nums[3]=-7
x=3: idx=2, nums[2]=2>0 → nums[2]=-2
x=2: idx=1, nums[1]=3>0 → nums[1]=-3
x=7: idx=6, nums[6]=3>0 → nums[6]=-3
x=8: idx=7, nums[7]=1>0 → nums[7]=-1
x=2: idx=1, nums[1]=-3<0 → DUPLICATE 2
x=3: idx=2, nums[2]=-2<0 → DUPLICATE 3
x=1: idx=0, nums[0]=4>0 → nums[0]=-4
Result: [2,3] ✓

Python:
def findDuplicates(nums):
    res=[]
    for x in nums:
        idx=abs(x)-1
        if nums[idx]<0: res.append(abs(x))
        else: nums[idx]=-nums[idx]
    return res
*/

// P4: Rotate Array Right by k (Reversal Method) O(n)/O(1)
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    if (k == 0) return;
    auto rev = [&](int l, int r) { while (l<r) swap(nums[l++], nums[r--]); };
    rev(0, n-1);
    rev(0, k-1);
    rev(k, n-1);
}
/*
Dry run: [1,2,3,4,5,6,7] k=3
Reverse all:  [7,6,5,4,3,2,1]
Reverse 0..2: [5,6,7,4,3,2,1]
Reverse 3..6: [5,6,7,1,2,3,4] ✓

Python:
def rotate(nums, k):
    n=len(nums); k%=n
    nums[:]=nums[::-1]; nums[:k]=nums[:k][::-1]; nums[k:]=nums[k:][::-1]
*/

// P5: Rotate Array Left by k
void rotateLeft(vector<int>& nums, int k) {
    int n = nums.size(); k %= n;
    auto rev = [&](int l, int r) { while (l<r) swap(nums[l++], nums[r--]); };
    rev(0, k-1); rev(k, n-1); rev(0, n-1);
}

// P6: First Missing Positive (Cyclic Placement) O(n)/O(1) LC 41
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    // Place each number x at index x-1 if 1<=x<=n
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
            swap(nums[i], nums[nums[i]-1]);
    }
    // First index where value != index+1 → missing
    for (int i = 0; i < n; i++)
        if (nums[i] != i+1) return i+1;
    return n+1;
}
/*
Dry run: [3,4,-1,1]
i=0(3): swap(nums[0]=3, nums[2]=-1) → [-1,4,3,1]
i=0(-1): -1<0, skip
i=1(4): swap(nums[1]=4, nums[3]=1) → [-1,1,3,4]
i=1(1): swap(nums[1]=1, nums[0]=-1) → [1,-1,3,4]
i=1(-1): skip
i=2(3): nums[2]=3==2+1? yes, skip
i=3(4): nums[3]=4==3+1? yes, skip
Scan: i=0:1=1✓, i=1:-1≠2 → return 2 ✓

Python:
def firstMissingPositive(nums):
    n=len(nums)
    for i in range(n):
        while 1<=nums[i]<=n and nums[nums[i]-1]!=nums[i]:
            nums[nums[i]-1],nums[i]=nums[i],nums[nums[i]-1]
    for i in range(n):
        if nums[i]!=i+1: return i+1
    return n+1
*/

// P7: Sort Colors — Dutch National Flag (preview Day 4) O(n)/O(1)
void sortColors(vector<int>& nums) {
    int low=0, mid=0, high=(int)nums.size()-1;
    while (mid <= high) {
        if (nums[mid]==0)      { swap(nums[low++], nums[mid++]); }
        else if (nums[mid]==1) { mid++; }
        else                   { swap(nums[mid], nums[high--]); }
    }
}

// P8: Find Duplicate (modify allowed version) O(n)/O(1)
// Mark by negating — but only works when values 1..n-1 and array has n elements
int findDuplicate_mark(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) return abs(nums[i]);
        nums[idx] = -nums[idx];
    }
    return -1;
}

// P9: Next Permutation (in-place) O(n)/O(1) LC 31
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n-2;
    // Find rightmost element smaller than successor
    while (i >= 0 && nums[i] >= nums[i+1]) i--;
    if (i >= 0) {
        // Find smallest element to the right > nums[i]
        int j = n-1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }
    // Reverse the suffix (was descending, now ascending)
    reverse(nums.begin()+i+1, nums.end());
}
/*
Dry run: [1,2,3]→[1,3,2]. [3,2,1]→[1,2,3]. [1,1,5]→[1,5,1].
[1,2,3]: i=1(2<3), j=2(3>2) → swap→[1,3,2], reverse suffix (empty) → [1,3,2] ✓
[3,2,1]: i=-1 (no i found), reverse all → [1,2,3] ✓

Python:
def nextPermutation(nums):
    n,i=len(nums),len(nums)-2
    while i>=0 and nums[i]>=nums[i+1]: i-=1
    if i>=0:
        j=n-1
        while nums[j]<=nums[i]: j-=1
        nums[i],nums[j]=nums[j],nums[i]
    l,r=i+1,n-1
    while l<r: nums[l],nums[r]=nums[r],nums[l]; l+=1; r-=1
*/

// P10: In-Place Matrix Transpose (square matrix)
void transposeMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
}

int main() {
    vector<int> a = {0,1,0,3,12};
    moveZeroes(a); for (int x:a) cout<<x<<" "; cout<<"\n";  // 1 3 12 0 0

    vector<int> b = {4,3,2,7,8,2,3,1};
    auto dups = findDuplicates(b); for(int x:dups) cout<<x<<" "; cout<<"\n"; // 2 3

    vector<int> c = {1,2,3,4,5,6,7};
    rotate(c, 3); for(int x:c) cout<<x<<" "; cout<<"\n"; // 5 6 7 1 2 3 4

    vector<int> d = {3,4,-1,1};
    cout << firstMissingPositive(d) << "\n"; // 2

    vector<int> e = {1,2,3};
    nextPermutation(e); for(int x:e) cout<<x<<" "; cout<<"\n"; // 1 3 2
    return 0;
}
