/*
 * Week 2 — Day 4: Dutch National Flag & Partitioning
 * Solutions + Dry Runs
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// P1: Sort Colors (LC 75) O(n)/O(1)
void sortColors(vector<int>& a) {
    int low = 0, mid = 0, high = (int)a.size() - 1;
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++; mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            swap(a[mid], a[high]);
            high--;
        }
    }
}
/*
Python:
def sortColors(a):
    low, mid, high = 0, 0, len(a)-1
    while mid <= high:
        if a[mid] == 0:
            a[low], a[mid] = a[mid], a[low]
            low += 1; mid += 1
        elif a[mid] == 1:
            mid += 1
        else:
            a[mid], a[high] = a[high], a[mid]
            high -= 1
*/

// P2: Move Zeros (Lomuto Partition) O(n)/O(1)
void moveZeroes(vector<int>& a) {
    int slow = 0;
    for (int fast = 0; fast < (int)a.size(); fast++) {
        if (a[fast] != 0) {
            swap(a[slow], a[fast]);
            slow++;
        }
    }
}

// P3: Segregate Even and Odd O(n)/O(1)
void sortArrayByParity(vector<int>& a) {
    int slow = 0;
    for (int fast = 0; fast < (int)a.size(); fast++) {
        if (a[fast] % 2 == 0) {
            swap(a[slow++], a[fast]);
        }
    }
}

// P4: Sort Array By Parity II (LC 922) O(n)/O(1)
void sortArrayByParityII(vector<int>& a) {
    int e = 0, o = 1;
    int n = a.size();
    while (e < n && o < n) {
        if (a[e] % 2 == 0) { e += 2; }
        else if (a[o] % 2 == 1) { o += 2; }
        else {
            swap(a[e], a[o]);
            e += 2; o += 2;
        }
    }
}
/*
Python:
def sortArrayByParityII(a):
    e, o, n = 0, 1, len(a)
    while e < n and o < n:
        if a[e]%2 == 0: e += 2
        elif a[o]%2 == 1: o += 2
        else:
            a[e], a[o] = a[o], a[e]
            e += 2; o += 2
    return a
*/

// P5: Partition Array According to Pivot O(n)/O(1) Unstable
void pivotArrayUnstable(vector<int>& a, int pivot) {
    int low = 0, mid = 0, high = (int)a.size()-1;
    while (mid <= high) {
        if (a[mid] < pivot) { swap(a[low++], a[mid++]); }
        else if (a[mid] == pivot) { mid++; }
        else { swap(a[mid], a[high--]); }
    }
}

// P6: Wiggle Sort (LC 280) O(n)/O(1)
void wiggleSort(vector<int>& a) {
    for (int i = 0; i < (int)a.size() - 1; i++) {
        if (((i % 2 == 0) && a[i] > a[i+1]) || 
            ((i % 2 == 1) && a[i] < a[i+1])) {
            swap(a[i], a[i+1]);
        }
    }
}

// P9: QuickSelect Kth Largest (LC 215) O(n) avg
int partition(vector<int>& a, int l, int r) {
    int pivot = a[r], slow = l;
    for (int i = l; i < r; i++) {
        if (a[i] <= pivot) swap(a[slow++], a[i]);
    }
    swap(a[slow], a[r]);
    return slow;
}
int findKthLargest(vector<int>& a, int k) {
    int l = 0, r = a.size() - 1, target = a.size() - k;
    while (l <= r) {
        int p = partition(a, l, r);
        if (p == target) return a[p];
        if (p < target) l = p + 1;
        else r = p - 1;
    }
    return -1;
}

int main() {
    vector<int> a = {2,0,2,1,1,0};
    sortColors(a);
    for (int x : a) cout << x << " "; cout << "\n"; // 0 0 1 1 2 2
    return 0;
}
