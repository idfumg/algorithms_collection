#include "../../template.hpp"

int rec(vi arr, int n) {
    if (n == arr.size() - 1) return 1;
    if (n >= arr.size()) return 0;
    if (arr[n] == 0) return 0;
    int count = 0;
    for (int i = 1; i <= arr[n]; ++i) {
        count += rec(arr, n + i);
    }
    return count;
}

vi rec(vi arr) {
    int n = arr.size();
    vi dp(n);
    for (int i = 0; i < n - 1; ++i) {
        if (int count = rec(arr, i); count != 0) {
            dp[i] = count;
        }
        else {
            dp[i] = -1;
        }
    }
    return dp;
}

vi tab(vi arr) {
    int n = arr.size();
    vi dp(n, 0);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] == 0) {
            dp[i] = 0;
        }
        else {
            for (int p = 1; p <= arr[i]; ++p) {
                if (i + p < arr.size() and dp[i + p] > 0) {
                    dp[i] += dp[i + p];
                }
            }
        }
        if (dp[i] == 0) {
            dp[i] = -1;
        }
    }
    dp[n - 1] = 0;
    return dp;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 2, 0, 1};
    vi arr2 = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    cout << rec(arr1) << endl; // 2 1 -1 0
    cout << rec(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
    cout << endl;
    cout << tab(arr1) << endl; // 2 1 -1 0
    cout << tab(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
}
