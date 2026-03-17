#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

// Problem 1: Two Sum
// Two-Pointer Approach (Requires sorted array, returns values)
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {nums[left], nums[right]};
        else if (sum < target) left++;
        else right--;
    }
    return {};
}

// Problem 2: Remove Element
// Fast-Slow Pointer
int removeElement(vector<int>& nums, int val) {
    int write_ptr = 0;
    for (int read_ptr = 0; read_ptr < nums.size(); read_ptr++) {
        if (nums[read_ptr] != val) {
            nums[write_ptr] = nums[read_ptr];
            write_ptr++;
        }
    }
    return write_ptr;
}

// Problem 3: Move Zeroes
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

// Problem 4: Beautiful Matrix (Codeforces logic representation)
int beautifulMatrix(int r, int c) {
    // Expected center is row 2, col 2 (0-indexed)
    return abs(r - 2) + abs(c - 2);
}

// Problem 5: Even Odds
long long evenOdds(long long n, long long k) {
    long long count_odd = (n + 1) / 2;
    if (k <= count_odd) {
        return 2 * k - 1;
    } else {
        return 2 * (k - count_odd);
    }
}

// Problem 6: Majority Element (Boyer-Moore)
int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

// Problem 7: Find Pivot Index
int pivotIndex(vector<int>& nums) {
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        int right_sum = total_sum - left_sum - nums[i];
        if (left_sum == right_sum) return i;
        left_sum += nums[i];
    }
    return -1;
}

// Problem 8: Product of Array Except Self
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    
    // Prefix
    for (int i = 1; i < n; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    // Suffix combined
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= nums[i];
    }
    return res;
}

// Problem 9: Missing Number (XOR)
int missingNumber(vector<int>& nums) {
    int xor_sum = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        xor_sum ^= i ^ nums[i];
    }
    return xor_sum;
}

// Problem 10: Rotate Array
void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// Problem 11: Merge Sorted Array
void mergeSorted(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;
    
    while (p2 >= 0) {
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
}

// Problem 12: Sort Colors (Dutch National Flag)
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--; 
            // Do NOT increment mid, element swapped from high needs to be checked
        }
    }
}

int main() {
    cout << "Day 2 Solutions compiled successfully. Review functions for implementation details." << endl;
    return 0;
}
