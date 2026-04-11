/*
 * Week 3 — Day 3: Frequency Maps
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <list>
using namespace std;

// P1: Valid Anagram (LC 242) O(N) / O(26) ~ O(1)
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int count[26] = {0};
    for(int i=0; i<s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for(int x : count) {
        if(x != 0) return false;
    }
    return true;
}

// P2: Find the Difference (LC 389) O(N) / O(1) XOR trick
char findTheDifference(string s, string t) {
    char res = 0;
    for (char c : s) res ^= c;
    for (char c : t) res ^= c;
    return res;
}

// P3: Longest Palindrome (LC 409) O(N) / O(128)
int longestPalindrome(string s) {
    int count[128] = {0};
    for(char c : s) count[(unsigned char)c]++;
    
    int length = 0;
    bool has_odd = false;
    for(int x : count) {
        if(x % 2 == 0) length += x;
        else {
            length += x - 1;
            has_odd = true;
        }
    }
    return has_odd ? length + 1 : length;
}

// P4: Group Anagrams (LC 49) O(N * K log K) / O(N*K)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for(string& s : strs) {
        string sig = s;
        sort(sig.begin(), sig.end());
        map[sig].push_back(s);
    }
    vector<vector<string>> res;
    for(auto& pair : map) {
        res.push_back(pair.second);
    }
    return res;
}

// P6: First Unique Character (LC 387) O(N) / O(26)
int firstUniqChar(string s) {
    int count[26] = {0};
    for(char c : s) count[c - 'a']++;
    for(int i = 0; i < s.length(); i++) {
        if(count[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

// P7: Sort Characters By Frequency (LC 451) O(N)/O(N) Bucket Sort
string frequencySort(string s) {
    int count[128] = {0};
    int max_freq = 0;
    for(char c : s) {
        count[(unsigned char)c]++;
        max_freq = max(max_freq, count[(unsigned char)c]);
    }
    
    // Buckets
    vector<string> buckets(max_freq + 1, "");
    for(int i = 0; i < 128; i++) {
        if(count[i] > 0) {
            buckets[count[i]].append(count[i], (char)i);
        }
    }
    
    string res = "";
    for(int i = max_freq; i > 0; i--) {
        if(!buckets[i].empty()) {
            res += buckets[i];
        }
    }
    return res;
}

// P8: Maximum Number of Balloons (LC 1189) O(N) / O(26)
int maxNumberOfBalloons(string text) {
    int count[26] = {0};
    for(char c : text) count[c - 'a']++;
    
    return min({count['b' - 'a'], count['a' - 'a'], count['l' - 'a'] / 2, count['o' - 'a'] / 2, count['n' - 'a']});
}

// P9: LRU Cache (LC 146) O(1) Operations
class LRUCache {
    int capacity;
    list<pair<int, int>> cache_list; // doubly-linked list
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache_map.find(key) == cache_map.end()) return -1;
        
        // Move to front (most recently used)
        cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        return cache_map[key]->second;
    }
    
    void put(int key, int value) {
        // If exists, update and move to front
        if (cache_map.find(key) != cache_map.end()) {
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
            cache_map[key]->second = value;
            return;
        }
        
        // If full, pop back
        if (cache_list.size() == capacity) {
            auto last = cache_list.back();
            cache_map.erase(last.first);
            cache_list.pop_back();
        }
        
        // Insert new
        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();
    }
};

int main() {
    cout << "Day 3 solutions ready!\n";
    return 0;
}
