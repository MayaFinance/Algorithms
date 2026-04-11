/*
 * Week 2 Contest Solutions & Editorial
 * =====================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// ---------------------------------------------------------
// PROBLEM A: Remove Duplicates II
// Pattern: Same Direction Two Pointers (Read/Write)
// ---------------------------------------------------------
int removeDuplicates(vector<int>& nums) {
    int slow = 0;
    for (int fast : nums) {
        if (slow < 2 || fast != nums[slow - 2]) {
            nums[slow++] = fast;
        }
    }
    return slow;
}

// ---------------------------------------------------------
// PROBLEM B: Sort Colors
// Pattern: Dutch National Flag (3-Way Partition)
// ---------------------------------------------------------
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while(mid <= high) {
        if(nums[mid] == 0)      swap(nums[low++], nums[mid++]);
        else if(nums[mid] == 1) mid++;
        else                    swap(nums[mid], nums[high--]); // no mid++
    }
}

// ---------------------------------------------------------
// PROBLEM C: Subarray Product Less Than K
// Pattern: Sliding Window
// ---------------------------------------------------------
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k <= 1) return 0;
    int left = 0, ans = 0;
    long long prod = 1;
    for(int right = 0; right < nums.size(); right++) {
        prod *= nums[right];
        while(prod >= k) {
            prod /= nums[left++];
        }
        ans += right - left + 1; // All subarrays ending at right
    }
    return ans;
}

// ---------------------------------------------------------
// PROBLEM D: Rotate Image
// Pattern: Matrix Transpose + Reversal
// ---------------------------------------------------------
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            swap(matrix[i][j], matrix[j][i]);
    
    for(int i=0; i<n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

// ---------------------------------------------------------
// PROBLEM E: Meeting Rooms II
// Pattern: Sweep-Line / Events
// ---------------------------------------------------------
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<pair<int, int>> events;
    for(auto& i : intervals) {
        events.push_back({i[0], 1});
        events.push_back({i[1], -1}); // end happens BEFORE start on ties conceptually
    }
    sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if(a.first == b.first) return a.second < b.second; // Process -1 before 1
        return a.first < b.first;
    });
    
    int max_rooms = 0, current = 0;
    for(auto& e : events) {
        current += e.second;
        max_rooms = max(max_rooms, current);
    }
    return max_rooms;
}

// ---------------------------------------------------------
// PROBLEM F: Minimum Window Substring
// Pattern: Sliding Window with Frequency Map
// ---------------------------------------------------------
string minWindow(string s, string t) {
    unordered_map<char, int> target;
    for(char c : t) target[c]++;
    
    int required = target.size();
    int formed = 0;
    unordered_map<char, int> window;
    
    int l = 0, r = 0;
    int min_len = 1e9, start_idx = 0;
    
    while(r < s.length()) {
        char c = s[r];
        window[c]++;
        if(target.count(c) && window[c] == target[c]) formed++;
        
        while(l <= r && formed == required) {
            c = s[l];
            if(r - l + 1 < min_len) {
                min_len = r - l + 1;
                start_idx = l;
            }
            window[c]--;
            if(target.count(c) && window[c] < target[c]) formed--;
            l++;
        }
        r++;
    }
    return min_len == 1e9 ? "" : s.substr(start_idx, min_len);
}

// ---------------------------------------------------------
// PROBLEM G: First Missing Positive
// Pattern: Cyclic Placement (In-Place Array Rearrangement)
// ---------------------------------------------------------
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        // Place x at index x-1 if possible.
        // Condition nums[nums[i]-1] != nums[i] prevents infinite loop on duplicates.
        while(nums[i] >= 1 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
            swap(nums[i], nums[nums[i]-1]);
        }
    }
    
    for(int i=0; i<n; i++) {
        if(nums[i] != i + 1) return i + 1;
    }
    return n + 1;
}

int main() {
    cout << "Week 2 Contest Solutions compiled successfully.\n";
    return 0;
}
