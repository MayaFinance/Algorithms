#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    // P1: Valid Palindrome (LC 125)
    // O(N) time, O(1) space. Two Pointers.
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (!isalnum(s[l])) l++;
            else if (!isalnum(s[r])) r--;
            else if (tolower(s[l]) != tolower(s[r])) return false;
            else { l++; r--; }
        }
        return true;
    }

    // P2: Valid Palindrome II (LC 680)
    // O(N) time, O(1) space. Two pointers with one skip.
    bool validPalindrome(string s) {
        auto check = [&](int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        };
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                // Skip left or skip right
                return check(l + 1, r) || check(l, r - 1);
            }
            l++; r--;
        }
        return true;
    }

    // P3: Longest Palindrome (LC 409)
    // O(N) time, O(1) space.
    int longestPalindrome(string s) {
        int count[128] = {0};
        for (char c : s) count[c]++;
        int ans = 0;
        bool hasOdd = false;
        for (int v : count) {
            if (v % 2 == 0) ans += v;
            else {
                ans += v - 1;
                hasOdd = true;
            }
        }
        return ans + (hasOdd ? 1 : 0);
    }

    // P4: Longest Substring Without Repeating Characters (LC 3)
    // O(N) time, O(1) space. Sliding Window.
    int lengthOfLongestSubstring(string s) {
        int map[128] = {0};
        int l = 0, r = 0, maxLen = 0;
        while (r < s.length()) {
            map[s[r]]++;
            while (map[s[r]] > 1) { // Window violates condition
                map[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }

    // P5: Longest Repeating Character Replacement (LC 424)
    // O(N) time, O(1) space. Sliding Window + max frequency tracking.
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int l = 0, maxF = 0, maxLen = 0;
        for (int r = 0; r < s.length(); r++) {
            maxF = max(maxF, ++count[s[r] - 'A']);
            if (r - l + 1 - maxF > k) { // Characters to replace > k
                count[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }

    // P6: Palindromic Substrings (LC 647)
    // O(N^2) time, O(1) space. Expand Around Center.
    int countSubstrings(string s) {
        int count = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                count++; l--; r++;
            }
        };
        for (int i = 0; i < s.length(); i++) {
            expand(i, i);     // odd length centers
            expand(i, i + 1); // even length centers
        }
        return count;
    }

    // P7: Longest Palindromic Substring (LC 5)
    // O(N^2) time, O(1) space. Expand Around Center.
    string longestPalindromeSubstring(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--; r++;
            }
            int len = r - l - 1;
            if (len > maxLen) {
                maxLen = len;
                start = l + 1;
            }
        };
        for (int i = 0; i < s.length(); i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, maxLen);
    }

    // P8: Repeated DNA Sequences (LC 187)
    // O(N) time, O(N) space. String Hashing/Rolling Substrings.
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, res;
        vector<string> ans;
        if (s.length() < 10) return ans;
        for (int i = 0; i <= s.length() - 10; i++) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) res.insert(sub);
            seen.insert(sub);
        }
        return vector<string>(res.begin(), res.end());
    }

    // P9: Palindrome Partitioning (LC 131)
    // O(N * 2^N) time, O(N) space. Backtracking.
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        
        auto isPal = [&](int l, int r) {
            while(l < r) if(s[l++] != s[r--]) return false;
            return true;
        };
        
        function<void(int)> dfs = [&](int start) {
            if (start == s.size()) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < s.size(); i++) {
                if (isPal(start, i)) {
                    path.push_back(s.substr(start, i - start + 1));
                    dfs(i + 1);
                    path.pop_back();
                }
            }
        };
        
        dfs(0);
        return res;
    }

    // P10: Longest Palindromic Substring (Manacher's Algorithm, LC 5 Advanced)
    // O(N) time, O(N) space.
    string longestPalindromeManacher(string s) {
        if (s.empty()) return "";
        // Transform the string to avoid even/odd center issues.
        // E.g., "aba" -> "^#a#b#a#$"
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";
        
        int n = t.length();
        vector<int> p(n, 0); // palindrome radius array
        int C = 0, R = 0; // Current center and right boundary
        
        int maxLen = 0, maxCenter = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            
            // If inside boundary, initialize with mirror radius
            if (R > i) {
                p[i] = min(R - i, p[i_mirror]);
            }
            
            // Expand palindrome centered at i
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }
            
            // Update center and right boundary
            if (i + p[i] > R) {
                C = i;
                R = i + p[i];
            }
            
            // Track maximum
            if (p[i] > maxLen) {
                maxLen = p[i];
                maxCenter = i;
            }
        }
        
        // Extract from original string
        int start = (maxCenter - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    cout << "Week 4 Day 2 Solutions Compiled Successfully.\n";
    cout << "Manacher test on 'babad': " << sol.longestPalindromeManacher("babad") << endl;
    return 0;
}
