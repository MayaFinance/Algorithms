#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <array>
#include <climits>

using namespace std;

class Solution {
public:
    // P1: Reverse String (LC 344)
    // Concept: Two Pointers. O(N) time, O(1) space.
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    // P2: Reverse Vowels of a String (LC 345)
    // Concept: Conditional Two Pointers. O(N) time, O(1) space.
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;
            if (left < right) swap(s[left++], s[right--]);
        }
        return s;
    }

    // P3: Valid Anagram (LC 242)
    // Concept: Frequency Counting. O(N) time, O(1) space.
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }

    // P4: Isomorphic Strings (LC 205)
    // Concept: Dual Hash mapping via Arrays. O(N) time, O(1) space.
    bool isIsomorphic(string s, string t) {
        int mapS[256] = {0}, mapT[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (mapS[s[i]] != mapT[t[i]]) return false;
            mapS[s[i]] = i + 1; // +1 to avoid 0 index collision
            mapT[t[i]] = i + 1;
        }
        return true;
    }

    // P5: Longest Common Prefix (LC 14)
    // Concept: Prefix bounding. O(N * M) time, O(1) space.
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) { // While not matching at start
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }

    // P6: Find the Index of the First Occurrence in a String (LC 28)
    // Concept: Pattern matching basics (naive scanner). O(N*M) time. string::find does this internally.
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.length(), m = needle.length();
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }
        return -1;
    }

    // P7: Find All Anagrams in a String (LC 438)
    // Concept: Fixed Sliding Window + array equality. O(N) time, O(1) space.
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) return ans;
        
        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;
        
        int k = p.length();
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            if (i >= k) sCount[s[i - k] - 'a']--; // slide out left char
            if (i >= k - 1 && pCount == sCount) { 
                ans.push_back(i - k + 1);
            }
        }
        return ans;
    }

    // P8: Group Anagrams (LC 49)
    // Concept: String building for Hashing. O(N * K) time.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& s : strs) {
            int count[26] = {0};
            for (char c : s) count[c - 'a']++;
            
            // Build frequency string instead of sorting for optimal time
            string key = "";
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    key += to_string(count[i]) + "#" + char(i + 'a');
                }
            }
            map[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& pair : map) {
            ans.push_back(std::move(pair.second));
        }
        return ans;
    }

    // P9: String to Integer (atoi) (LC 8)
    // Concept: Edge cases & Transformations. O(N) time.
    int myAtoi(string s) {
        int i = 0, n = s.length();
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;
        
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return ans * sign;
    }

    // P10: Reverse Words in a String (LC 151)
    // Concept: In-place memory shifting. O(N) time, O(1) space approach.
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); // Reverse whole string
        
        int n = s.length();
        int left = 0, right = 0, i = 0;
        
        while (i < n) {
            while (i < n && s[i] == ' ') i++; // Skip spaces
            if (i == n) break;
            while (i < n && s[i] != ' ') s[right++] = s[i++]; // Copy word down
            
            reverse(s.begin() + left, s.begin() + right); // Reverse the individual word
            
            s[right++] = ' '; // add singular trailing space
            left = right;
        }
        
        s.resize(max(0, right - 1)); // Trim last space
        return s;
    }
};

int main() {
    Solution sol;
    cout << "Week 4 Day 1 (Redo) Solutions Compiled Successfully.\n";
    
    // Quick test on Reverse Words to verify O(1) space logic
    string test = "  hello world  ";
    cout << "Reverse Words test: '" << sol.reverseWords(test) << "'" << endl;
    
    return 0;
}
