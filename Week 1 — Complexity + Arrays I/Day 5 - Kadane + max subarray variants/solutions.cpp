// kadane_solutions.cpp
// Day 5: Kadane's Algorithm + Maximum Subarray Variants
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ==========================================
// 1. Maximum Subarray (LeetCode 53)
// ==========================================
int maxSubArray(vector<int>& nums) {
    // Initialize both to first element — handles all-negative arrays
    int curr_max = nums[0];
    int global_max = nums[0];

    for (int i = 1; i < (int)nums.size(); i++) {
        // Extend or reset: if curr_max < 0 it only drags us down
        curr_max = max(nums[i], curr_max + nums[i]);
        global_max = max(global_max, curr_max);
    }
    return global_max;
}

// ==========================================
// 2. Maximum Sum Circular Subarray (LeetCode 918)
// ==========================================
int maxCircularSubarraySum(vector<int>& nums) {
    int total = 0;
    int max_sum = nums[0], curr_max = nums[0];
    int min_sum = nums[0], curr_min = nums[0];

    for (int i = 1; i < (int)nums.size(); i++) {
        curr_max = max(nums[i], curr_max + nums[i]);
        max_sum  = max(max_sum, curr_max);

        curr_min = min(nums[i], curr_min + nums[i]);
        min_sum  = min(min_sum, curr_min);

        total += nums[i];
    }
    total += nums[0]; // Add nums[0] which was skipped in loop

    // All-negative guard: if total == min_sum, circular sum would be 0 (invalid empty)
    // So return max_sum only in that case
    if (total == min_sum) return max_sum;
    return max(max_sum, total - min_sum);
}

// ==========================================
// 3. Maximum Product Subarray (LeetCode 152)
// ==========================================
int maxProductSubarray(vector<int>& nums) {
    int curr_max = nums[0];
    int curr_min = nums[0];
    int result   = nums[0];

    for (int i = 1; i < (int)nums.size(); i++) {
        int x = nums[i];
        // Must snapshot before overwriting curr_max
        int temp_max = max({x, curr_max * x, curr_min * x});
        int temp_min = min({x, curr_max * x, curr_min * x});
        curr_max = temp_max;
        curr_min = temp_min;
        result = max(result, curr_max);
    }
    return result;
}

// ==========================================
// 4. Best Time to Buy and Sell Stock (LeetCode 121)
// ==========================================
int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int price : prices) {
        // Greedy: always buy at the lowest price seen so far
        min_price = min(min_price, price);
        // Greedy: always check if selling today beats current max profit
        max_profit = max(max_profit, price - min_price);
    }
    return max_profit;
}

// ==========================================
// 5. Maximum Subarray Sum with One Deletion (LeetCode 1186)
// ==========================================
int maximumSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);

    // Forward Kadane: max sum ending at i
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(arr[i], left[i-1] + arr[i]);

    // Backward Kadane: max sum starting at i
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
        right[i] = max(arr[i], right[i+1] + arr[i]);

    // Non-deleted maximum
    int result = *max_element(left.begin(), left.end());

    // Bridge: delete element at position k
    for (int k = 1; k < n-1; k++) {
        result = max(result, left[k-1] + right[k+1]);
    }
    return result;
}

// ==========================================
// 6. Maximum Absolute Sum (LeetCode 1749)
// ==========================================
int maxAbsoluteSum(vector<int>& nums) {
    int f = 0; // max sum ending here
    int g = 0; // min sum ending here
    int ans = 0;

    for (int x : nums) {
        f = max(f, 0) + x;
        g = min(g, 0) + x;
        ans = max({ans, f, abs(g)});
    }
    return ans;
}

// ==========================================
// 7. Count Subarrays with Score < K (LeetCode 2302)
// ==========================================
long long countSubarrays(vector<int>& nums, long long k) {
    long long count = 0;
    long long window_sum = 0;
    int left = 0;

    for (int right = 0; right < (int)nums.size(); right++) {
        window_sum += nums[right];
        // Shrink window while score (sum * length) >= k
        while (window_sum * (right - left + 1) >= k) {
            window_sum -= nums[left++];
        }
        // All subarrays ending at 'right' with left pointer valid
        count += (right - left + 1);
    }
    return count;
}

// ==========================================
// 8. Maximum Sum Rectangle (2D Kadane)
// ==========================================
int maxSumRectangle(vector<vector<int>>& matrix) {
    int R = matrix.size(), C = matrix[0].size();
    int global_max = INT_MIN;

    for (int left = 0; left < C; left++) {
        vector<int> row_sums(R, 0);

        for (int right = left; right < C; right++) {
            // Accumulate column sums into 1D row compression
            for (int r = 0; r < R; r++)
                row_sums[r] += matrix[r][right];

            // Standard Kadane on the compressed 1D array
            int curr = row_sums[0];
            int best = row_sums[0];
            for (int r = 1; r < R; r++) {
                curr = max(row_sums[r], curr + row_sums[r]);
                best = max(best, curr);
            }
            global_max = max(global_max, best);
        }
    }
    return global_max;
}

// ==========================================
// 9. Subarray Sum Equals K (LeetCode 560)
// ==========================================
// NOTE: This is NOT Kadane — it uses Prefix Sum + HashMap.
// Included here to contrast when Kadane does NOT apply.
#include <unordered_map>
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_count;
    prefix_count[0] = 1;
    int sum = 0, count = 0;

    for (int x : nums) {
        sum += x;
        // If sum - k was seen before, those subarrays sum to exactly k
        if (prefix_count.count(sum - k))
            count += prefix_count[sum - k];
        prefix_count[sum]++;
    }
    return count;
}

int main() {
    cout << "Kadane's Algorithm Solutions compiled successfully.\n";
    return 0;
}
