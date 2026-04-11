/*
 * Week 2 — Day 5: Array Rotation & Rearrangement
 * Solutions with Dry Runs
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// P1: Rotate Array Right (LC 189) O(n)/O(1)
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    auto rev = [&](int l, int r) { while(l<r) swap(nums[l++], nums[r--]); };
    rev(0, n-1);
    rev(0, k-1);
    rev(k, n-1);
}

// P2: Rotate Image 90 deg clockwise (LC 48) O(n^2)/O(1)
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
/*
Python:
def rotate(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(i+1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for row in matrix:
        row.reverse()
*/

// P3: Build Array from Permutation (LC 1920) O(n)/O(1)
vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        // nums[i] % n gives the old value
        nums[i] = nums[i] + (nums[nums[i]] % n) * n;
    }
    for(int i=0; i<n; i++) {
        nums[i] = nums[i] / n;
    }
    return nums;
}
/*
Dry run: [0, 2, 1, 5, 3, 4] n=6
i=0: nums[0]=0, nums[0]%6=0  -> nums[0] += 0 * 6 = 0
i=1: nums[1]=2, nums[2]%6=1  -> nums[1] += 1 * 6 = 8
i=2: nums[1]=1, nums[1]%6=2  -> nums[2] += 2 * 6 = 13 (wait, nums[1] is 8, 8%6 = 2)
Decode:
i=1: 8/6 = 1
i=2: 13/6 = 2
*/

// P4: Rearrange Array Alternately O(n)/O(1) space
void rearrangeAlternate(vector<long long>& arr, int n) {
    int max_idx = n - 1;
    int min_idx = 0;
    long long M = arr[n-1] + 1; // M needs to be strictly larger than any element
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            arr[i] += (arr[max_idx] % M) * M;
            max_idx--;
        } else {
            arr[i] += (arr[min_idx] % M) * M;
            min_idx++;
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] /= M;
    }
}

// P5: Search in Rotated Sorted Array (LC 33) O(log n)/O(1)
int searchRotated(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        
        if(nums[l] <= nums[mid]) { // Left half is sorted
            if(target >= nums[l] && target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        } else { // Right half is sorted
            if(target > nums[mid] && target <= nums[r]) l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;
}

// P6: Find Minimum in Rotated Sorted Array (LC 153) O(log n)/O(1)
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] > nums[r]) {
            // Min must be to the right of mid
            l = mid + 1;
        } else {
            // Min could be mid or to the left of mid
            r = mid;
        }
    }
    return nums[l];
}

// P7: Minimum Increments (LC 1526) O(n)/O(1)
int minNumberOperations(vector<int>& target) {
    int ans = target[0];
    for (int i = 1; i < (int)target.size(); i++) {
        if (target[i] > target[i-1]) {
            ans += target[i] - target[i-1];
        }
    }
    return ans;
}

// P8: Spiral Matrix (LC 54) O(m*n)/O(1) extra space
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.empty()) return res;
    
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    
    while(top <= bottom && left <= right) {
        for(int j=left; j<=right; j++) res.push_back(matrix[top][j]);
        top++;
        
        for(int i=top; i<=bottom; i++) res.push_back(matrix[i][right]);
        right--;
        
        if(top <= bottom) {
            for(int j=right; j>=left; j--) res.push_back(matrix[bottom][j]);
            bottom--;
        }
        
        if(left <= right) {
            for(int i=bottom; i>=top; i--) res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
}

// P9: Set Matrix Zeroes (LC 73) O(m*n)/O(1)
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;
    
    // Check first col
    for(int i=0; i<m; i++) if(matrix[i][0] == 0) firstColZero = true;
    // Check first row
    for(int j=0; j<n; j++) if(matrix[0][j] == 0) firstRowZero = true;
    
    // Mark inner zeroes using first row and col
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Zero out inner elements based on markers
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if(firstColZero) for(int i=0; i<m; i++) matrix[i][0] = 0;
    if(firstRowZero) for(int j=0; j<n; j++) matrix[0][j] = 0;
}

int main() {
    vector<int> a = {1,2,3,4,5,6,7};
    rotate(a, 3);
    for(int x:a) cout<<x<<" "; cout<<"\n"; // 5 6 7 1 2 3 4
    
    return 0;
}
