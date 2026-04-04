// difference_array_solutions.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. Range Addition (LeetCode 370)
// ==========================================
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    // Array of size length + 1 to prevent OOB when r == length - 1
    vector<int> diff(length + 1, 0);
    
    // O(K) Updates
    for (const auto& u : updates) {
        int l = u[0];
        int r = u[1];
        int val = u[2];
        
        diff[l] += val;
        diff[r + 1] -= val; 
    }
    
    // O(N) Reconstruction
    vector<int> result(length);
    int current_sum = 0;
    for (int i = 0; i < length; i++) {
        current_sum += diff[i];
        result[i] = current_sum;
    }
    
    return result;
}

// ==========================================
// 2. Corporate Flight Bookings (LeetCode 1109)
// ==========================================
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    // Allocate n+2 because flights are 1-indexed and we need an r+1 buffer
    vector<int> diff(n + 2, 0);
    
    for (const auto& b : bookings) {
        int first = b[0];
        int last = b[1];
        int seats = b[2];
        
        diff[first] += seats; 
        diff[last + 1] -= seats;
    }
    
    vector<int> result(n);
    int current_seats = 0;
    // Walk from 1 to n to align directly
    for (int i = 1; i <= n; i++) {
        current_seats += diff[i];
        result[i - 1] = current_seats; // Store cleanly into 0-indexed return vector
    }
    return result;
}

// ==========================================
// 3. Little Girl and Maximum Sum (Codeforces 276C)
// ==========================================
long long littleGirlMaxSum(int n, vector<int>& arr, vector<pair<int, int>>& queries) {
    vector<int> diff(n + 1, 0);
    
    // Step 1: Use difference array to build frequency map of queries
    for (const auto& q : queries) {
        int l = q.first - 1; // Translate to 0-indexed
        int r = q.second - 1;
        
        diff[l]++;
        diff[r + 1]--;
    }
    
    // Step 2: Reconstruct the frequencies
    vector<int> freq(n);
    int current_freq = 0;
    for (int i = 0; i < n; i++) {
        current_freq += diff[i];
        freq[i] = current_freq;
    }
    
    // Step 3: Sort arrays to align highest multiplier with highest number
    sort(freq.begin(), freq.end());
    sort(arr.begin(), arr.end());
    
    // Step 4: Map frequencies via greedy dot-product distribution
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        // Safe 64-bit integer overflow protection logic included
        total_sum += (1LL * freq[i] * arr[i]); 
    }
    
    return total_sum;
}

// ==========================================
// 10. Car Pooling (LeetCode 1094)
// ==========================================
bool carPooling(vector<vector<int>>& trips, int capacity) {
    int maxLocation = 0;
    for (auto& t : trips) maxLocation = max(maxLocation, t[2]);
    vector<int> diff(maxLocation + 1, 0);
    
    for (auto& t : trips) {
        diff[t[1]] += t[0];
        diff[t[2]] -= t[0];
    }
    
    int current_passengers = 0;
    for (int i = 0; i <= maxLocation; i++) {
        current_passengers += diff[i];
        if (current_passengers > capacity) return false;
    }
    return true;
}

// ==========================================
// 11. My Calendar II (LeetCode 731)
// ==========================================
#include <map>
class MyCalendarTwo {
    map<int, int> diff;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        diff[start]++;
        diff[end]--;
        
        int active = 0;
        for (auto& [time, delta] : diff) {
            active += delta;
            if (active >= 3) {
                // Revert
                diff[start]--;
                diff[end]++;
                return false;
            }
        }
        return true;
    }
};

// ==========================================
// 12. Describe the Painting (LeetCode 1943)
// ==========================================
vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    map<int, long long> diff;
    for (auto& seg : segments) {
        diff[seg[0]] += seg[2];
        diff[seg[1]] -= seg[2];
    }
    
    vector<vector<long long>> res;
    long long color_sum = 0;
    int last_pos = -1;
    
    for (auto& [pos, delta] : diff) {
        if (color_sum > 0 && last_pos != -1) {
            res.push_back({last_pos, pos, color_sum});
        }
        color_sum += delta;
        last_pos = pos;
    }
    return res;
}

// ==========================================
// 13. Stamping the Grid (LeetCode 2132)
// ==========================================
bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
    int m = grid.size(), n = grid[0].size();
    
    // 2D Prefix Sum to check for obstacles
    vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + grid[i][j];
        }
    }
    
    // 2D Difference Array to place stamps
    vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                int r2 = i + stampHeight;
                int c2 = j + stampWidth;
                if (r2 <= m && c2 <= n) {
                    // Check if region is free of obstacles
                    int obstacles = pref[r2][c2] - pref[i][c2] - pref[r2][j] + pref[i][j];
                    if (obstacles == 0) {
                        diff[i][j]++;
                        diff[r2][j]--;
                        diff[i][c2]--;
                        diff[r2][c2]++;
                    }
                }
            }
        }
    }
    
    // Reconstruct Difference Array & verify all 0s are stamped
    vector<vector<int>> stamped(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            stamped[i][j] = diff[i][j];
            if (i > 0) stamped[i][j] += stamped[i-1][j];
            if (j > 0) stamped[i][j] += stamped[i][j-1];
            if (i > 0 && j > 0) stamped[i][j] -= stamped[i-1][j-1];
            
            if (grid[i][j] == 0 && stamped[i][j] == 0) return false;
        }
    }
    return true;
}

// ==========================================
// 14. Rectangle Area II (LeetCode 850)
// ==========================================
int rectangleArea(vector<vector<int>>& rectangles) {
    int MOD = 1e9 + 7;
    vector<int> x_coords;
    for (auto& r : rectangles) {
        x_coords.push_back(r[0]);
        x_coords.push_back(r[2]);
    }
    sort(x_coords.begin(), x_coords.end());
    x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
    
    long long total_area = 0;
    
    // Sweep-line over each vertical slab (Compressing X axis natively via iteration)
    for (int i = 0; i < x_coords.size() - 1; ++i) {
        int x1 = x_coords[i], x2 = x_coords[i+1];
        int width = x2 - x1;
        if (width == 0) continue;
        
        vector<pair<int, int>> intervals;
        for (auto& r : rectangles) {
            if (r[0] <= x1 && r[2] >= x2) {
                intervals.push_back({r[1], r[3]});
            }
        }
        sort(intervals.begin(), intervals.end());
        
        // 1D Line sweeping down the Y axis for this current X slab
        long long y_coverage = 0;
        int current_y1 = -1, current_y2 = -1;
        for (auto& iv : intervals) {
            if (iv.first > current_y2) {
                y_coverage += max(0, current_y2 - current_y1);
                current_y1 = iv.first;
                current_y2 = iv.second;
            } else {
                current_y2 = max(current_y2, iv.second);
            }
        }
        y_coverage += max(0, current_y2 - current_y1);
        
        total_area = (total_area + y_coverage * width) % MOD;
    }
    return total_area;
}

int main() {
    cout << "Difference Array Solutions compiled successfully.\n";
    return 0;
}
