/*
 * Week 2 — Day 6: Mixed Array Patterns
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// P1: Majority Element (LC 169) O(n)/O(1)
int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int x : nums) {
        if (count == 0) candidate = x;
        count += (x == candidate) ? 1 : -1;
    }
    return candidate;
}
/*
Dry run: [2,2,1,1,1,2,2]
x=2: count=0->cand=2, count=1
x=2: count=2
x=1: count=1
x=1: count=0
x=1: count=0->cand=1, count=1
x=2: count=0
x=2: count=0->cand=2, count=1
Return 2.
*/

// P2: Majority Element II (LC 229) O(n)/O(1)
vector<int> majorityElementII(vector<int>& nums) {
    int c1 = 0, count1 = 0;
    int c2 = 1, count2 = 0; // c1 and c2 must be different initially
    for (int x : nums) {
        if (x == c1) count1++;
        else if (x == c2) count2++;
        else if (count1 == 0) { c1 = x; count1 = 1; }
        else if (count2 == 0) { c2 = x; count2 = 1; }
        else { count1--; count2--; }
    }
    count1 = 0; count2 = 0;
    for (int x : nums) {
        if (x == c1) count1++;
        else if(x == c2) count2++;
    }
    vector<int> res;
    if (count1 > nums.size() / 3) res.push_back(c1);
    if (count2 > nums.size() / 3) res.push_back(c2);
    return res;
}

// P3: Top K Frequent Elements (LC 347) O(n)/O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int x : nums) freq[x]++;
    
    vector<vector<int>> buckets(nums.size() + 1);
    for(auto& pair : freq) {
        buckets[pair.second].push_back(pair.first);
    }
    
    vector<int> res;
    for(int i = buckets.size() - 1; i >= 0 && res.size() < k; i--) {
        for(int x : buckets[i]) {
            res.push_back(x);
            if(res.size() == k) break;
        }
    }
    return res;
}

// P4: Merge Intervals (LC 56) O(n log n)/O(n)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1; i<(int)intervals.size(); i++) {
        if(res.back()[1] >= intervals[i][0]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

// P6: Meeting Rooms II (Sweep line logic) O(n log n)/O(n)
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<pair<int, int>> events;
    for(auto& interval : intervals) {
        events.push_back({interval[0], 1});  // start -> +1
        events.push_back({interval[1], -1}); // end -> -1
    }
    
    // Sort events: if times equal, -1 comes first
    sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    
    int max_rooms = 0, current = 0;
    for(auto& e : events) {
        current += e.second;
        max_rooms = max(max_rooms, current);
    }
    return max_rooms;
}

// P7: H-Index (LC 274) Counting Sort O(n)/O(n)
int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> count(n + 1, 0);
    for(int c : citations) {
        if(c >= n) count[n]++;
        else count[c]++;
    }
    
    int total = 0;
    for(int i = n; i >= 0; i--) {
        total += count[i];
        if(total >= i) return i;
    }
    return 0;
}

// P9: Summary Ranges (LC 228) O(n)/O(1)
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int start = nums[i];
        while(i + 1 < n && nums[i+1] == nums[i] + 1) {
            i++;
        }
        if(start == nums[i]) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(nums[i]));
        }
    }
    return res;
}

// P10: Task Scheduler (LC 621) Math O(N)/O(1)
int leastInterval(vector<char>& tasks, int n) {
    vector<int> counts(26, 0);
    int max_val = 0;
    for(char c : tasks) {
        counts[c - 'A']++;
        max_val = max(max_val, counts[c - 'A']);
    }
    
    int num_max = 0;
    for(int c : counts) {
        if(c == max_val) num_max++;
    }
    
    int ans = (max_val - 1) * (n + 1) + num_max;
    return max(ans, (int)tasks.size());
}

int main() {
    vector<int> a = {2,2,1,1,1,2,2};
    cout << majorityElement(a) << "\n"; // 2
    return 0;
}
