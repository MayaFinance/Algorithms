/*
 * Week 3 — Day 1: Fixed Sliding Window
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <numeric>

using namespace std;

// P1: Maximum Average Subarray I (LC 643) O(N) / O(1)
double findMaxAverage(vector<int>& nums, int k) {
    long long current_sum = 0;
    for (int i = 0; i < k; i++) current_sum += nums[i];
    
    long long max_sum = current_sum;
    for (int i = k; i < nums.size(); i++) {
        current_sum = current_sum + nums[i] - nums[i - k];
        max_sum = max(max_sum, current_sum);
    }
    return (double)max_sum / k;
}

// P2: Diet Plan Performance (LC 1176) O(N) / O(1)
int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    if (calories.size() < k) return 0;
    int current_sum = 0, points = 0;
    
    // First window
    for (int i = 0; i < k; i++) current_sum += calories[i];
    if (current_sum < lower) points--;
    if (current_sum > upper) points++;
    
    // Slide
    for (int i = k; i < calories.size(); i++) {
        current_sum += calories[i] - calories[i - k];
        if (current_sum < lower) points--;
        if (current_sum > upper) points++;
    }
    return points;
}

// P4: Maximum Vowels (LC 1456) O(N) / O(1)
int maxVowels(string s, int k) {
    auto isVowel = [](char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    };
    int current = 0;
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) current++;
    }
    int max_v = current;
    for (int i = k; i < s.length(); i++) {
        if (isVowel(s[i])) current++;
        if (isVowel(s[i - k])) current--;
        max_v = max(max_v, current);
    }
    return max_v;
}

// P5: Find All Anagrams (LC 438) O(N) / O(26) ~ O(1)
vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (s.length() < p.length()) return res;
    
    vector<int> pCount(26, 0), sCount(26, 0);
    for (char c : p) pCount[c - 'a']++;
    
    int k = p.length();
    for (int i = 0; i < k; i++) sCount[s[i] - 'a']++;
    if (pCount == sCount) res.push_back(0);
    
    for (int i = k; i < s.length(); i++) {
        sCount[s[i] - 'a']++;
        sCount[s[i - k] - 'a']--;
        if (pCount == sCount) res.push_back(i - k + 1);
    }
    return res;
}

// P7: First Negative (GFG) O(N) / O(K) Space
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<int> dq;
    vector<long long> res;
    
    // First window
    for(int i = 0; i < K; i++) {
        if (A[i] < 0) dq.push_back(i);
    }
    
    if (dq.empty()) res.push_back(0);
    else res.push_back(A[dq.front()]);
    
    // Slide
    for(int i = K; i < N; i++) {
        // Remove old
        if (!dq.empty() && dq.front() == i - K) dq.pop_front();
        // Add new
        if (A[i] < 0) dq.push_back(i);
        
        if (dq.empty()) res.push_back(0);
        else res.push_back(A[dq.front()]);
    }
    return res;
}

// P8: Contains Duplicate II (LC 219) O(N) / O(K) space
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window;
    for (int i = 0; i < nums.size(); i++) {
        // If window sz exceeds k, remove oldest
        if (i > k) window.erase(nums[i - k - 1]);
        // Insert returns pair<iterator, bool> (false if already exists)
        if (!window.insert(nums[i]).second) return true;
    }
    return false;
}

// P9: Sliding Window Maximum (LC 239) O(N) Time / O(K) Space
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores INDICES, forming a strictly decreasing seq of values
    vector<int> res;
    
    for (int i = 0; i < nums.size(); i++) {
        // 1. Remove elements that fell out of window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // 2. Maintain Monotonicity (remove strictly smaller from back)
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // 3. Add current
        dq.push_back(i);
        
        // 4. Record result (only if window has hit size k)
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}
/*
Dry run: nums=[1,3,-1,-3,5,3,6,7], k=3
i=0(1): dq=[0]
i=1(3): 3 > 1 -> pop 0. dq=[1]
i=2(-1): dq=[1,2]. res=[3]
i=3(-3): dq=[1,2,3]. res=[3]
i=4(5): 5 > -3 -> pop 3. 5 > -1 -> pop 2. pop 1(out of bounds). dq=[4]. res=[5]
... you get the drift!
*/

int main() {
    cout << "Day 1 solutions ready!\n";
    return 0;
}
