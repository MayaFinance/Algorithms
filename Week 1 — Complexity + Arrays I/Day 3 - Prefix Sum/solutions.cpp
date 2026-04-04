#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

// Problem 1: Range Sum Query - Immutable
class NumArray {
    vector<long long> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    long long sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

// Problem 2: Running Sum of 1D Array
vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

// Problem 3: Subarray Sum Equals K
int subarraySum(vector<int>& nums, int k) {
    unordered_map<long long, int> prefix_counts;
    prefix_counts[0] = 1;
    long long sum = 0;
    int count = 0;
    for (int num : nums) {
        sum += num;
        if (prefix_counts.count(sum - k)) {
            count += prefix_counts[sum - k];
        }
        prefix_counts[sum]++;
    }
    return count;
}

// Problem 4: Continuous Subarray Sum (Modulo K)
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> remainder_idx;
    remainder_idx[0] = -1; // Base case for prefix starting at index 0
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int rem = sum % k;
        if (rem < 0) rem += k; // C++ modulo negatives
        
        if (remainder_idx.count(rem)) {
            if (i - remainder_idx[rem] >= 2) return true;
        } else {
            remainder_idx[rem] = i; // Store only earliest mapping to maximize length
        }
    }
    return false;
}

// Problem 5: Maximum Size Subarray Sum Equals K
int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<long long, int> prefix_idx;
    long long sum = 0;
    int max_len = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == k) max_len = i + 1;
        
        if (prefix_idx.count(sum - k)) {
            max_len = max(max_len, i - prefix_idx[sum - k]);
        }
        // ONLY insert if missing (preserves earliest occurrence!)
        if (!prefix_idx.count(sum)) {
            prefix_idx[sum] = i;
        }
    }
    return max_len;
}

// Problem 6: Binary Subarrays with Sum
// Utilizing the "at-most" trick to keep $O(1)$ space.
int helperAtMost(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int res = 0, sum = 0, l = 0;
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while (sum > goal) {
            sum -= nums[l++];
        }
        res += (r - l + 1);
    }
    return res;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return helperAtMost(nums, goal) - helperAtMost(nums, goal - 1);
}

// Problem 7: Contiguous Array (Equal 0s and 1s)
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> prefix_idx;
    prefix_idx[0] = -1;
    int sum = 0, max_len = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] == 0) ? -1 : 1;
        if (prefix_idx.count(sum)) {
            max_len = max(max_len, i - prefix_idx[sum]);
        } else {
            prefix_idx[sum] = i;
        }
    }
    return max_len;
}

// Problem 8: Number of Submatrices That Sum to Target
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int r = matrix.size(), c = matrix[0].size();
    int count = 0;
    
    // Convert matrix paths into 1D prefix arrays across columns
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }
    
    for (int c1 = 0; c1 < c; c1++) {
        for (int c2 = c1; c2 < c; c2++) {
            unordered_map<int, int> map;
            map[0] = 1;
            int sum = 0;
            for (int i = 0; i < r; i++) {
                sum += matrix[i][c2] - (c1 > 0 ? matrix[i][c1 - 1] : 0);
                count += map[sum - target];
                map[sum]++;
            }
        }
    }
    return count;
}

// Problem 9: Maximum Average Subarray II
// Note: This incorporates binary search combined with prefix constraints
bool maxAverageHelper(vector<int>& nums, double avg_candidate, int k) {
    double min_prefix = 0.0, current_prefix_sum = 0.0, k_ago_prefix_sum = 0.0;
    for (int i = 0; i < k; ++i) {
        current_prefix_sum += (nums[i] - avg_candidate);
    }
    if (current_prefix_sum >= 0) return true;
    for (int i = k; i < nums.size(); ++i) {
        current_prefix_sum += (nums[i] - avg_candidate);
        k_ago_prefix_sum += (nums[i - k] - avg_candidate);
        min_prefix = min(min_prefix, k_ago_prefix_sum);
        if (current_prefix_sum - min_prefix >= 0) return true;
    }
    return false;
}
double findMaxAverage(vector<int>& nums, int k) {
    double left = -10000, right = 10000;
    while (right - left > 1e-5) {
        double mid = left + (right - left) / 2.0;
        if (maxAverageHelper(nums, mid, k)) left = mid;
        else right = mid;
    }
    return left; // or right
}

// Problem 10: Corporate Flight Bookings Strategy (Difference Array)
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n + 1, 0); // extra space to prevent out-of-bounds on last+1
    for (const auto& bk : bookings) {
        int first = bk[0] - 1; // 0-indexed
        int last = bk[1] - 1;
        int seats = bk[2];
        
        diff[first] += seats;
        diff[last + 1] -= seats;
    }
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1]; // reconstruct
    }
    diff.pop_back(); // Remove extra padding
    return diff;
}

// Problem 11: Car Pooling (Sweep Line Array Variant)
bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> stops(1001, 0);
    for (const auto& trip : trips) {
        stops[trip[1]] += trip[0]; // pick up
        stops[trip[2]] -= trip[0]; // drop off
    }
    int current_passengers = 0;
    for (int i = 0; i <= 1000; i++) {
        current_passengers += stops[i];
        if (current_passengers > capacity) return false;
    }
    return true;
}

int main() {
    cout << "Day 3 Solutions compiled successfully. Prefix map strategies loaded." << endl;
    return 0;
}
