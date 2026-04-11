/*
 * Week 3 — Day 4: Hashing Collisions & Tricks
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <numeric>

using namespace std;

// P1: Design HashMap (LC 706) Separate Chaining
class MyHashMap {
    struct Node {
        int key;
        int val;
    };
    int SIZE = 10007; // Prime number
    vector<list<Node>> buckets;
    
public:
    MyHashMap() {
        buckets.resize(SIZE);
    }
    
    void put(int key, int value) {
        int hash = key % SIZE;
        for (auto& node : buckets[hash]) {
            if (node.key == key) {
                node.val = value;
                return;
            }
        }
        buckets[hash].push_back({key, value});
    }
    
    int get(int key) {
        int hash = key % SIZE;
        for (auto& node : buckets[hash]) {
            if (node.key == key) return node.val;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = key % SIZE;
        for (auto it = buckets[hash].begin(); it != buckets[hash].end(); ++it) {
            if (it->key == key) {
                buckets[hash].erase(it);
                return;
            }
        }
    }
};

// P2: Encode and Decode TinyURL (LC 535)
class Solution {
    unordered_map<string, string> urlToCode;
    unordered_map<string, string> codeToUrl;
    string base = "http://tinyurl.com/";
    int id = 0;
public:
    string encode(string longUrl) {
        if (urlToCode.count(longUrl)) return base + urlToCode[longUrl];
        string code = to_string(id++);
        urlToCode[longUrl] = code;
        codeToUrl[code] = longUrl;
        return base + code;
    }

    string decode(string shortUrl) {
        string code = shortUrl.substr(base.length());
        return codeToUrl[code];
    }
};

// P5: Contains Duplicate III (LC 220) O(N) Buketing
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(t < 0 || k < 1) return false;
    unordered_map<long long, long long> buckets;
    long long width = (long long)t + 1;
    
    for (int i = 0; i < nums.size(); i++) {
        long long num = nums[i];
        long long id = num < 0 ? (num + 1) / width - 1 : num / width;
        
        // Same bucket
        if(buckets.count(id)) return true;
        // Adjacent left
        if(buckets.count(id - 1) && abs(num - buckets[id - 1]) <= t) return true;
        // Adjacent right
        if(buckets.count(id + 1) && abs(num - buckets[id + 1]) <= t) return true;
        
        buckets[id] = num;
        if(i >= k) {
            long long rem_id = nums[i - k] < 0 ? (nums[i - k] + 1) / width - 1 : nums[i - k] / width;
            buckets.erase(rem_id);
        }
    }
    return false;
}

// P6: Brick Wall (LC 554) O(Total Bricks)
int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> edge_freq;
    int max_edges = 0;
    for(auto& row : wall) {
        int pos = 0;
        // Stop before the very last brick, because edge of wall doesn't count
        for(int i = 0; i < row.size() - 1; i++) {
            pos += row[i];
            edge_freq[pos]++;
            max_edges = max(max_edges, edge_freq[pos]);
        }
    }
    return wall.size() - max_edges;
}

// P7: Fractional Recurring Decimal (LC 166)
string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0) return "0";
    string res;
    if(numerator < 0 ^ denominator < 0) res += "-";
    
    long long n = abs((long long)numerator);
    long long d = abs((long long)denominator);
    res += to_string(n / d);
    long long rem = n % d;
    if (rem == 0) return res;
    
    res += ".";
    unordered_map<long long, int> map;
    while(rem != 0) {
        if(map.count(rem)) {
            res.insert(map[rem], "(");
            res += ")";
            break;
        }
        map[rem] = res.length();
        rem *= 10;
        res += to_string(rem / d);
        rem %= d;
    }
    return res;
}

// P8: Max Points on a Line (LC 149) Custom Pair Hashing
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1,T2>& p) const {
        return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 1);
    }
};

int maxPoints(vector<vector<int>>& points) {
    if(points.size() <= 2) return points.size();
    int global_max = 0;
    
    for(int i=0; i<points.size(); i++) {
        unordered_map<pair<int,int>, int, pair_hash> slopes;
        int local_max = 0, duplicates = 1;
        for(int j=i+1; j<points.size(); j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            
            if(dx == 0 && dy == 0) {
                duplicates++;
                continue;
            }
            
            int g = gcd(dx, dy);
            dx /= g; dy /= g;
            
            // Standardize sign
            if(dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx; dy = -dy;
            }
            
            slopes[{dx, dy}]++;
            local_max = max(local_max, slopes[{dx, dy}]);
        }
        global_max = max(global_max, local_max + duplicates);
    }
    return global_max;
}

int main() {
    cout << "Day 4 solutions ready!\n";
    return 0;
}
