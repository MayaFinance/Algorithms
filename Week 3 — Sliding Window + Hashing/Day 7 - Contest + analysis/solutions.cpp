/*
 * Week 3 — Day 7: Contest Editorials
 * Solutions and Deep Dives
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 🟢 Problem A: Maximum Erasure Value
/*
 * EDITORIAL:
 * We need unique elements. That's a HashSet.
 * We want maximum sum -> we maintain current sum.
 * Expand right, adding to set and sum.
 * If right exists in set, invalid window -> Shrink until right is removed from set, subtracting from sum.
 * Capture max outside inner loop.
 * Complexity: O(N) Time, O(N) Space.
 */
int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> seen;
    int left = 0, current_sum = 0, max_sum = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        while (seen.count(nums[right])) {
            seen.erase(nums[left]);
            current_sum -= nums[left];
            left++;
        }
        seen.insert(nums[right]);
        current_sum += nums[right];
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

// 🟢 Problem B: Find All Anagrams in a String
/*
 * EDITORIAL:
 * Fixed Sliding Window. 
 * Track arrays of size 26.
 * Add s[right], remove s[right - p.length]. Compare arrays.
 * Code omitted here, direct implementation from Day 1.
 */

// 🟡 Problem C: Subarray Sums Divisible by K
/*
 * EDITORIAL:
 * Map of prefix sum remainders.
 * If Prefix(i) % K == Prefix(j) % K, subarray between them is divisible by K.
 * Formula for neg mods: rem = (sum % K + K) % K.
 */
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    count[0] = 1; 
    int sum = 0, ans = 0;
    for (int num : nums) {
        sum += num;
        int rem = (sum % k + k) % k;
        ans += count[rem];
        count[rem]++;
    }
    return ans;
}

// 🟡 Problem D: Max Consecutive Ones III
/*
 * EDITORIAL:
 * Variable sliding window.
 * Track count of zeros. When zeros > k, shrink.
 * Capture max length.
 */
int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeros = 0, max_len = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeros++;
        while (zeros > k) {
            if (nums[left] == 0) zeros--;
            left++;
        }
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

// 🔴 Problem E: Make Sum Divisible by P
/*
 * EDITORIAL:
 * We need to REMOVE a subarray that sums to `rem = Total % P`.
 * This becomes "Find shortest subarray whose sum % P == rem".
 * Use Prefix Hash map mapping Prefix % P to exact index.
 * Wanted Remainder in past = (Current_Mode - Rem + P) % P.
 */
int minSubarray(vector<int>& nums, int p) {
    long long total_sum = 0;
    for (int x : nums) total_sum += x;
    int target_rem = total_sum % p;
    if (target_rem == 0) return 0;
    
    unordered_map<int, int> pos;
    pos[0] = -1;
    long long pref = 0;
    int ans = nums.size();
    
    for (int i = 0; i < nums.size(); i++) {
        pref += nums[i];
        int cur_mod = pref % p;
        int needed = (cur_mod - target_rem + p) % p;
        if (pos.count(needed)) {
            ans = min(ans, i - pos[needed]);
        }
        pos[cur_mod] = i; // update latest index
    }
    return ans == nums.size() ? -1 : ans;
}

// 🔴 Problem F: Subarrays with K Different Integers
/*
 * EDITORIAL:
 * Exact(K) = AtMost(K) - AtMost(K - 1).
 * Use a helper function for AtMost.
 */
int atMostK(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int left = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (count[nums[right]] == 0) k--; // completely new element
        count[nums[right]]++;
        
        while (k < 0) {
            count[nums[left]]--;
            if (count[nums[left]] == 0) k++; 
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main() {
    cout << "Contest editorals analyzed!" << endl;
    return 0;
}
