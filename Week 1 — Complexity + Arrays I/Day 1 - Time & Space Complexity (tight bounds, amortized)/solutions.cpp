#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

// This file contains all 40 complexity estimation snippets written out as functions.
// This allows you to compile, benchmark, and play around with the different constructs.
// Note: Many of these functions simply increment a 'sum' variable to represent O(1) baseline work.
// To prevent the compiler from optimizing empty loops away, 'sum' is declared as volatile.

void snippet_01(int n) { volatile long long sum = 0; for (int i = 0; i < n; i++) { sum++; } } // O(n)
void snippet_02(int n) { volatile long long sum = 0; for (int i = 0; i < n; i += 2) { sum++; } } // O(n)
void snippet_03(int n) { volatile long long sum = 0; for (int i = n; i > 0; i /= 2) { sum++; } } // O(log n)
void snippet_04(int n) { volatile long long sum = 0; for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { sum++; } } } // O(n^2)
void snippet_05(int n) { volatile long long sum = 0; for (int i = 0; i < n; i++) { for (int j = i; j < n; j++) { sum++; } } } // O(n^2)
void snippet_06(int n) { volatile long long sum = 0; for (int i = 1; i < n; i *= 2) { for (int j = 0; j < n; j++) { sum++; } } } // O(n log n)
void snippet_07(int n) { volatile long long sum = 0; for (int i = 0; i < n; i++) { for (int j = 1; j < n; j *= 2) { sum++; } } } // O(n log n)
void snippet_08(int n) { volatile long long sum = 0; for (int i = 1; i * i <= n; i++) { sum++; } } // O(sqrt(n))
void snippet_09(int n, int m) { volatile long long sum = 0; for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { sum++; } } } // O(n*m)
void snippet_10(int n) { volatile long long sum = 0; for (int i = 0; i < n; i++) { if (i > 100) break; sum++; } } // O(1)
void snippet_11(int n) { volatile long long sum = 0; for (int i = 0; i < n; i++) { for (int j = 0; j < i * i; j++) { sum++; } } } // O(n^3)
void snippet_12(int n) { volatile long long sum = 0; for (int i = 1; i < n; i *= 2) { for (int j = 0; j < i; j++) { sum++; } } } // O(n)
void snippet_13(int n) { volatile long long sum = 0; for (int i = 1; i < n; i++) { for (int j = 1; j < n; j += i) { sum++; } } } // O(n log n)
void snippet_14(int n) { volatile long long sum = 0; for (int i = 2; i < n; i = i * i) { sum++; } } // O(log log n)
void snippet_15(int n, int m) { volatile long long sum = 0; for (int i = 0; i < n; i++) { sum++; } for (int j = 0; j < m; j++) { sum++; } } // O(n + m)
void snippet_16(int n) { volatile long long sum = 0; while (n > 0) { n /= 2; for (int j = 0; j < n; j++) sum++; } } // O(n)
void snippet_17(int n) { volatile long long sum = 0; for (int i = 0; i < n; i++) { for (int j = 0; j < n; j += sqrt(n)) sum++; } } // O(n sqrt(n))
void snippet_18(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= i; j++) { for (int k = 1; k <= j; k++) sum++; } } } // O(n^3)
void snippet_19(int n) { vector<int> v; for (int i = 0; i < n; i++) { v.push_back(i); } } // O(n)
void snippet_20(int n) { volatile long long sum = 0; for (int i = 1; i < n; i++) { if (n % i == 0) sum++; } } // O(n)
void snippet_21(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j *= 2) { for (int k = 1; k <= n; k *= 2) sum++; } } } // O(n log^2 n)
void snippet_22(int n) { volatile long long sum = 0; for (int i = 0; i < n * n; i++) { sum++; } } // O(n^2)
void snippet_23(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = i; j <= n; j *= 2) sum++; } } // O(n)
void snippet_24(int n) { set<int> s; for (int i = 0; i < n; i++) { s.insert(i); } } // O(n log n)
void snippet_25(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= 10; j++) sum++; } } // O(n)
void snippet_26(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j += 100) sum++; } } // O(n^2)
void snippet_27(int target, const vector<int>& arr) { 
    int low = 0, high = arr.size() - 1; 
    while (low <= high) { int mid = (low + high)/2; if (arr[mid] == target) break; else if (arr[mid] < target) low = mid + 1; else high = mid - 1; } 
} // O(log n)
void snippet_28(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { n /= 2; } } // O(log n)
void snippet_29(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i *= 2) { for (int j = 0; j < i; j++) { for (int k = 0; k < j; k++) sum++; } } } // O(n^2)
void snippet_30(int n) { for (int i = 0; i < n; i++) { string s(i, 'a'); } } // O(n^2)
void snippet_31(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { if (i == j) { for (int k = 0; k < n; k++) sum++; } } } } // O(n^2)

void snippet_32_f(int n) { if (n <= 1) return; snippet_32_f(n-1); } // O(n)
void snippet_32(int n) { snippet_32_f(n); } 

void snippet_33_f(int n) { if (n <= 1) return; snippet_33_f(n/2); snippet_33_f(n/2); } // O(n)
void snippet_33(int n) { snippet_33_f(n); } 

void snippet_34(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { if (rand() % 2) break; sum++; } } } // O(n^2)
void snippet_35(int n) { map<int, int> m; for (int i = 0; i < n; i++) { m[i] = i; } } // O(n log n)
void snippet_36(int n) { unordered_map<int, int> um; for (int i = 0; i < n; i++) { um[i] = i; } } // O(n)
void snippet_37(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= i; j *= 2) sum++; } } // O(n log n)
void snippet_38(int n) { volatile long long sum = 0; for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j += i) { for (int k = 0; k < 100; k++) sum++; } } } // O(n log n)
void snippet_39(int n, int m, bool cond) { int j = 0; for (int i = 0; i < n; i++) { while (j < m && cond) { j++; cond = false; } } } // O(n + m)
void snippet_40(int n) { volatile long long sum = 0; for (int i = 1; i * i * i <= n; i++) { sum++; } } // O(n^(1/3))

int main() {
    cout << "To benchmark a specific snippet, call it from main() with an input variable." << endl;
    return 0;
}
