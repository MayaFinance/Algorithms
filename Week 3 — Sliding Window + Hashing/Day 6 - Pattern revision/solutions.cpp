/*
 * Week 3 — Day 6: Pattern Revision & Synthesis
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>

using namespace std;

// P4: Grumpy Bookstore Owner (LC 1052) O(N) Mixed logic
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int total_satisfied = 0;
    // 1. Calculate guaranteed satisfied
    for (int i = 0; i < customers.size(); i++) {
        if (grumpy[i] == 0) total_satisfied += customers[i];
    }
    
    // 2. Fixed sliding window of size `minutes` over grumpy spots ONLY
    int current_gain = 0;
    for (int i = 0; i < minutes; i++) {
        if (grumpy[i] == 1) current_gain += customers[i];
    }
    int max_gain = current_gain;
    
    for (int i = minutes; i < customers.size(); i++) {
        if (grumpy[i] == 1) current_gain += customers[i];
        if (grumpy[i - minutes] == 1) current_gain -= customers[i - minutes];
        max_gain = max(max_gain, current_gain);
    }
    
    return total_satisfied + max_gain;
}

// P6: Max Points You Can Obtain (LC 1423) O(N) Inverse Variable Window
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int total_pts = 0;
    for (int p : cardPoints) total_pts += p;
    
    int window_size = n - k;
    if (window_size == 0) return total_pts;
    
    int current_sum = 0;
    for (int i = 0; i < window_size; i++) current_sum += cardPoints[i];
    int min_sum = current_sum;
    
    for (int i = window_size; i < n; i++) {
        current_sum += cardPoints[i] - cardPoints[i - window_size];
        min_sum = min(min_sum, current_sum);
    }
    
    return total_pts - min_sum;
}

// P7: Minimum Window Substring (LC 76) O(N) String Variable Window
string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) return "";
    
    int countT[128] = {0};
    for (unsigned char c : t) countT[c]++;
    
    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (countT[i] > 0) required++;
    }
    
    int left = 0, right = 0;
    int formed = 0;
    int windowCounts[128] = {0};
    int ans_idx = -1, ans_len = 1e9;
    
    while (right < s.length()) {
        unsigned char c = s[right];
        windowCounts[c]++;
        if (countT[c] > 0 && windowCounts[c] == countT[c]) {
            formed++;
        }
        
        while (left <= right && formed == required) {
            unsigned char l_char = s[left];
            if (right - left + 1 < ans_len) {
                ans_len = right - left + 1;
                ans_idx = left;
            }
            windowCounts[l_char]--;
            if (countT[l_char] > 0 && windowCounts[l_char] < countT[l_char]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    
    return ans_idx == -1 ? "" : s.substr(ans_idx, ans_len);
}

// P10: Longest Nice Subarray (LC 2401) O(N) Bitwise Variable Window
int longestNiceSubarray(vector<int>& nums) {
    int left = 0, right = 0;
    int window_or = 0;
    int max_len = 0;
    
    while (right < nums.size()) {
        // While overlap exists
        while ((window_or & nums[right]) != 0) {
            // Remove left element bounds:
            // Since elements in nice subarray have NO overlapping bits,
            // XOR serves perfectly as a subtraction operator for OR!
            window_or ^= nums[left];
            left++;
        }
        
        // Add right to window
        window_or |= nums[right];
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}

int main() {
    cout << "Day 6 solutions ready!\n";
    return 0;
}
