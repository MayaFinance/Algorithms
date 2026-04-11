/*
 * Week 2 — Day 2: Two Pointers (Opposite Direction)
 * Solutions with Dry Runs, Complexity, and Python
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// P1: Two Sum II — Sorted Array (LC 167) O(n)/O(1)
vector<int> twoSumSorted(vector<int>& a, int target) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        int s = a[l] + a[r];
        if (s == target) return {l+1, r+1};
        else if (s < target) l++;
        else r--;
    }
    return {};
}
/*
Dry run: [2,7,11,15] target=9
l=0,r=3: 2+15=17>9 → r=2
l=0,r=2: 2+11=13>9 → r=1
l=0,r=1: 2+7=9==9  → return [1,2] ✓

Python:
def twoSum(a,t):
    l,r=0,len(a)-1
    while l<r:
        s=a[l]+a[r]
        if s==t: return [l+1,r+1]
        elif s<t: l+=1
        else: r-=1
*/

// P2: Valid Palindrome (LC 125) O(n)/O(1)
bool isPalindrome(string s) {
    auto ok = [](char c){ return isalnum(c); };
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        while (l < r && !ok(s[l])) l++;
        while (l < r && !ok(s[r])) r--;
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++; r--;
    }
    return true;
}
/*
Python:
def isPalindrome(s):
    s=''.join(c.lower() for c in s if c.isalnum())
    return s==s[::-1]
*/

// P3: Container With Most Water (LC 11) O(n)/O(1)
int maxArea(vector<int>& h) {
    int l = 0, r = (int)h.size()-1, best = 0;
    while (l < r) {
        best = max(best, min(h[l], h[r]) * (r-l));
        if (h[l] < h[r]) l++;   // move shorter side — it's the bottleneck
        else r--;
    }
    return best;
}
/*
Dry run: [1,8,6,2,5,4,8,3,7]
l=0(h=1),r=8(h=7): area=min(1,7)*8=8. h[l]<h[r]→l=1
l=1(8),r=8(7): area=min(8,7)*7=49. h[r]<h[l]→r=7
l=1(8),r=7(3): area=min(8,3)*6=18. r=6
...best=49 ✓

Python:
def maxArea(h):
    l,r,best=0,len(h)-1,0
    while l<r:
        best=max(best,min(h[l],h[r])*(r-l))
        if h[l]<h[r]: l+=1
        else: r-=1
    return best
*/

// P4: Reverse Array O(n)/O(1)
void reverseArray(vector<int>& a) {
    int l = 0, r = (int)a.size()-1;
    while (l < r) { swap(a[l++], a[r--]); }
}

// P5: Three Sum (LC 15) O(n²)/O(1) extra
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n-2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;  // skip dup outer
        int l = i+1, r = n-1;
        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];
            if (s == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l+1]) l++;  // skip dup
                while (l < r && nums[r] == nums[r-1]) r--;
                l++; r--;
            }
            else if (s < 0) l++;
            else r--;
        }
    }
    return res;
}
/*
Dry run: [-1,0,1,2,-1,-4] → sorted: [-4,-1,-1,0,1,2]
i=0(-4): l=1(-1),r=5(2): -4-1+2=-3<0→l++
  l=2(-1),r=5(2): -4-1+2=-3<0→l++. ... no triple.
i=1(-1): skip (nums[1]==-1==nums[2]... wait i=1 is first -1, no skip)
  l=2(-1),r=5(2): -1-1+2=0→ save [-1,-1,2], skip dups.
  l=3(0),r=4(1): -1+0+1=0→ save [-1,0,1].
i=2(-1): skip (dup of i=1)
... Result: [[-1,-1,2],[-1,0,1]] ✓

Python:
def threeSum(nums):
    nums.sort(); res=[]
    for i in range(len(nums)-2):
        if i>0 and nums[i]==nums[i-1]: continue
        l,r=i+1,len(nums)-1
        while l<r:
            s=nums[i]+nums[l]+nums[r]
            if s==0:
                res.append([nums[i],nums[l],nums[r]])
                while l<r and nums[l]==nums[l+1]: l+=1
                while l<r and nums[r]==nums[r-1]: r-=1
                l+=1;r-=1
            elif s<0: l+=1
            else: r-=1
    return res
*/

// P6: Three Sum Closest (LC 16) O(n²)/O(1)
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), best = nums[0]+nums[1]+nums[2];
    for (int i = 0; i < n-2; i++) {
        int l = i+1, r = n-1;
        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];
            if (abs(s-target) < abs(best-target)) best = s;
            if (s < target) l++;
            else if (s > target) r--;
            else return s;  // exact match
        }
    }
    return best;
}

// P8: Trapping Rain Water (LC 42) O(n)/O(1)
int trap(vector<int>& h) {
    int l = 0, r = (int)h.size()-1;
    int lmax = 0, rmax = 0, water = 0;
    while (l < r) {
        if (h[l] <= h[r]) {
            lmax = max(lmax, h[l]);
            water += lmax - h[l];  // guaranteed: rmax >= lmax limits nothing
            l++;
        } else {
            rmax = max(rmax, h[r]);
            water += rmax - h[r];
            r--;
        }
    }
    return water;
}
/*
Dry run: [0,1,0,2,1,0,1,3,2,1,2,1]
l=0(0),r=11(1): h[l]<=h[r]. lmax=0. water+=0-0=0. l=1
l=1(1),r=11(1): h[l]<=h[r]. lmax=1. water+=1-1=0. l=2
l=2(0),r=11(1): h[l]<=h[r]. lmax=1. water+=1-0=1. l=3
...total water=6 ✓

Python:
def trap(h):
    l,r,lm,rm,w=0,len(h)-1,0,0,0
    while l<r:
        if h[l]<=h[r]: lm=max(lm,h[l]); w+=lm-h[l]; l+=1
        else: rm=max(rm,h[r]); w+=rm-h[r]; r-=1
    return w
*/

// P9: Four Sum (LC 18) O(n³)/O(1)
vector<vector<int>> fourSum(vector<int>& nums, long long target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n-3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < n-2; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int l = j+1, r = n-1;
            while (l < r) {
                long long s = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                if (s == target) {
                    res.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while (l<r && nums[l]==nums[l+1]) l++;
                    while (l<r && nums[r]==nums[r-1]) r--;
                    l++; r--;
                } else if (s < target) l++;
                else r--;
            }
        }
    }
    return res;
}

// P12: Valid Palindrome II — One Deletion (LC 680) O(n)/O(1)
bool validPalindrome(string s) {
    auto isPalin = [](const string& s, int l, int r) {
        while (l < r) { if (s[l++] != s[r--]) return false; }
        return true;
    };
    int l = 0, r = (int)s.size()-1;
    while (l < r) {
        if (s[l] != s[r])
            return isPalin(s,l+1,r) || isPalin(s,l,r-1);
        l++; r--;
    }
    return true;
}

int main() {
    vector<int> a = {2,7,11,15};
    auto r = twoSumSorted(a, 9); cout << r[0] << " " << r[1] << "\n";  // 1 2

    vector<int> b = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(b) << "\n";  // 49

    vector<int> c = {-1,0,1,2,-1,-4};
    auto trips = threeSum(c);
    for (auto& t : trips) cout << t[0]<<","<<t[1]<<","<<t[2]<<"\n";

    vector<int> d = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(d) << "\n";  // 6

    return 0;
}
