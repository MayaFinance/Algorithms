/*
 * Week 3 — Day 5: Subarray Counting Problems
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

// P1: Subarray Sum Equals K (LC 560) O(N) / O(N)
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_counts;
    prefix_counts[0] = 1; // Critical base case
    
    int prefix_sum = 0, count = 0;
    for (int num : nums) {
        prefix_sum += num;
        if (prefix_counts.count(prefix_sum - k)) {
            count += prefix_counts[prefix_sum - k];
        }
        prefix_counts[prefix_sum]++;
    }
    return count;
}

// P2: Contiguous Array (LC 525) Equal 0s and 1s O(N)
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> prefix_index;
    prefix_index[0] = -1; // Base case for length calculation
    
    int prefix_sum = 0, max_len = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefix_sum += (nums[i] == 0) ? -1 : 1;
        
        if (prefix_index.count(prefix_sum)) {
            max_len = max(max_len, i - prefix_index[prefix_sum]);
        } else {
            // Only store the EARLIEST index to maximize length
            prefix_index[prefix_sum] = i;
        }
    }
    return max_len;
}

// P3: Subarray Sums Divisible by K (LC 974) O(N)
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainder_counts;
    remainder_counts[0] = 1; 
    
    int prefix_sum = 0, count = 0;
    for (int num : nums) {
        prefix_sum += num;
        int rem = (prefix_sum % k + k) % k; // Handle negative modulo correctly
        
        if (remainder_counts.count(rem)) {
            count += remainder_counts[rem];
        }
        remainder_counts[rem]++;
    }
    return count;
}

// P4: Make Sum Divisible by P (LC 1590) O(N) Length of Shortest Subarray
int minSubarray(vector<int>& nums, int p) {
    long long total_sum = 0;
    for (int num : nums) total_sum += num;
    
    int rem_target = total_sum % p;
    if (rem_target == 0) return 0;
    
    unordered_map<int, int> prefix_index;
    prefix_index[0] = -1;
    
    long long prefix_sum = 0;
    int min_len = nums.size();
    
    for (int i = 0; i < nums.size(); i++) {
        prefix_sum += nums[i];
        int current_rem = prefix_sum % p;
        
        int needed_rem = (current_rem - rem_target + p) % p;
        if (prefix_index.count(needed_rem)) {
            min_len = min(min_len, i - prefix_index[needed_rem]);
        }
        
        prefix_index[current_rem] = i; // Update with latest index to minimize length
    }
    return min_len == nums.size() ? -1 : min_len;
}

// P5: Continuous Subarray Sum (LC 523) Size >= 2 divisible by K
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_index;
    prefix_index[0] = -1;
    
    long long prefix_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefix_sum += nums[i];
        int rem = prefix_sum % k;
        
        if (prefix_index.count(rem)) {
            if (i - prefix_index[rem] >= 2) return true;
        } else {
            prefix_index[rem] = i;
        }
    }
    return false;
}

// P8: Count Number of Bad Pairs (LC 2364) O(N) Math Hashing
long long countBadPairs(vector<int>& nums) {
    long long n = nums.size();
    long long total_pairs = n * (n - 1) / 2;
    
    unordered_map<int, long long> diff_counts;
    long long good_pairs = 0;
    
    for (int i = 0; i < n; i++) {
        int diff = nums[i] - i;
        if (diff_counts.count(diff)) {
            good_pairs += diff_counts[diff];
        }
        diff_counts[diff]++;
    }
    return total_pairs - good_pairs;
}

// P9: Number of Subarrays With Odd Sum (LC 1524)
int numOfSubarrays(vector<int>& arr) {
    int odd = 0, even = 1; // 1 even prefix_sum initially (0)
    int MOD = 1e9 + 7;
    int prefix_sum = 0, count = 0;
    
    for (int num : arr) {
        prefix_sum += num;
        if (prefix_sum % 2 == 0) {
            count = (count + odd) % MOD;
            even++;
        } else {
            count = (count + even) % MOD;
            odd++;
        }
    }
    return count;
}

// P10: Number of Excellent Pairs (LC 2354) Bits Math + Hash Count
long long countExcellentPairs(vector<int>& nums, int k) {
    auto count_bits = [](int n) {
        int count = 0;
        while(n) { n &= (n - 1); count++; }
        return count;
    };
    
    vector<int> bit_counts(32, 0); // Freq array basically
    unordered_map<int, bool> seen; // Unique elements only
    
    for(int num : nums) {
        if(!seen[num]) {
            seen[num] = true;
            bit_counts[count_bits(num)]++;
        }
    }
    
    long long pairs = 0;
    for(int i = 1; i < 32; i++) {
        for(int j = 1; j < 32; j++) {
            if(i + j >= k) {
                pairs += (long long)bit_counts[i] * bit_counts[j];
            }
        }
    }
    return pairs;
}

int main() {
    cout << "Day 5 solutions ready!\n";
    return 0;
}
