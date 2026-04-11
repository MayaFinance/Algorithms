/*
 * Week 3 — Day 2: Variable Sliding Window
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// P1: Minimum Size Subarray Sum (LC 209) O(N) / O(1)
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0;
    int sum = 0, min_len = 1e9;
    
    while (right < nums.size()) {
        sum += nums[right];
        
        while (sum >= target) {
            // Valid window, capture min
            min_len = min(min_len, right - left + 1);
            // Shrink
            sum -= nums[left++];
        }
        
        right++;
    }
    return min_len == 1e9 ? 0 : min_len;
}

// P2: Longest Substring Without Repeating Characters (LC 3) O(N) / O(128)
int lengthOfLongestSubstring(string s) {
    int count[128] = {0};
    int left = 0, right = 0;
    int max_len = 0;
    
    while (right < s.length()) {
        count[(unsigned char)s[right]]++;
        
        // Invalid window (duplicate found)
        while (count[(unsigned char)s[right]] > 1) {
            count[(unsigned char)s[left]]--;
            left++;
        }
        
        // Valid window, capture max
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}

// P3: Max Consecutive Ones III (LC 1004) O(N) / O(1)
int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int zero_cnt = 0, max_len = 0;
    
    while (right < nums.size()) {
        if (nums[right] == 0) zero_cnt++;
        
        // Invalid window
        while (zero_cnt > k) {
            if (nums[left] == 0) zero_cnt--;
            left++;
        }
        
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}

// P4: Longest Repeating Character Replacement (LC 424) O(N) / O(26)
int characterReplacement(string s, int k) {
    int count[26] = {0};
    int left = 0, right = 0, max_freq = 0, max_len = 0;
    
    while (right < s.length()) {
        count[s[right] - 'A']++;
        max_freq = max(max_freq, count[s[right] - 'A']);
        
        // condition: window_len - max_freq <= k
        while ((right - left + 1) - max_freq > k) {
            count[s[left] - 'A']--;
            // We don't strictly HAVE to update max_freq here! 
            // Because max_len only grows when max_freq GROWS.
            left++;
        }
        
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}

// P7: Minimum Operations to Reduce X to Zero (LC 1658) O(N) / O(1)
int minOperations(vector<int>& nums, int x) {
    int total_sum = 0;
    for (int num : nums) total_sum += num;
    
    int target = total_sum - x;
    if (target < 0) return -1;
    if (target == 0) return nums.size();
    
    // Now just find longest subarray with sum == target
    int left = 0, right = 0;
    int sum = 0, max_len = -1;
    
    while (right < nums.size()) {
        sum += nums[right];
        
        while (sum > target && left <= right) {
            sum -= nums[left++];
        }
        
        if (sum == target) {
            max_len = max(max_len, right - left + 1);
        }
        right++;
    }
    
    return max_len == -1 ? -1 : nums.size() - max_len;
}

// Helper for P8 & P10: Number of subarrays with at most K distinct elements
int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
    if (k == 0) return 0;
    unordered_map<int, int> count;
    int left = 0, right = 0, ans = 0;
    
    while (right < nums.size()) {
        count[nums[right]]++;
        
        while (count.size() > k) {
            count[nums[left]]--;
            if (count[nums[left]] == 0) count.erase(nums[left]);
            left++;
        }
        
        // Every time window is valid, it adds (right-left+1) valid subarrays
        ans += (right - left + 1);
        right++;
    }
    return ans;
}

// P8: Subarrays with K Different Integers (LC 992) O(N) / O(N)
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
}

int main() {
    cout << "Day 2 solutions ready!\n";
    return 0;
}
