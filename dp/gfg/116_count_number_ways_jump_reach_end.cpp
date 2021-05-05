#include "../../template.hpp"

int rec(vi arr, int i, vi& dp) {
    int n = arr.size();
    if (i == n) return 1;
    if (i > n) return 0;
    int ans = 0;
    for (int j = i + 1; j <= i + arr[i - 1] and j <= n; ++j) {
        ans += rec(arr, j, dp);
    }
    return dp[i] = ans;
}

vi rec(vi arr) {
    int n = arr.size();
    vi dp(n + 1);
    rec(arr, 1, dp);
    return dp;
}

vi tab(vi arr) {
    int n = arr.size();
    vi dp(n + 1);
    for (int i = n; i >= 1; --i) {
        if (i == n) dp[i] = 1;
        else {
            for (int j = i + 1; j <= i + arr[i - 1] and j <= n; ++j) {
                dp[i] += dp[j];
            }
        }
    }
    return dp;
}

int rec2(vi& arr, int n) {
    if (n == 1) return 1;
    if (n <= 0 or arr[n - 1] == 0) return 0;
    int ans = 0;
    for (int k = 1; k <= arr[n - 1]; ++k) {
        ans += rec2(arr, n - k);
    }
    return ans;
}

vi rec2(vi arr) {
    reverse(arr.begin(), arr.end());
    int n = arr.size();
    vi ways(n);
    for (int i = 2; i <= n; ++i) {
        ways[i - 1] = rec2(arr, i);
        if (ways[i - 1] == 0) {
            ways[i - 1] = -1;
        }
    }
    reverse(ways.begin(), ways.end());
    return ways;
}

vi tab2(vi arr) {
    int n = arr.size();
    reverse(arr.begin(), arr.end());
    vi dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            dp[i] = 1;
        }
        else if (arr[i - 1] == 0) {
            dp[i] = 0;
        }
        else {
            int ans = 0;
            for (int k = 1; k <= arr[i - 1]; ++k) {
                if (i >= k) {
                    ans += dp[i - k];
                }
            }
            dp[i] = ans;
        }
    }
    vi ways(n, 0);
    for (int i = 2; i <= n; ++i) {
        ways[i - 1] = dp[i];
        if (ways[i - 1] == 0) {
            ways[i - 1] = -1;
        }
    }
    reverse(ways.begin(), ways.end());
    return ways;
}

int main() { // TimeMeasure _; __x();
    vi arr1 = {3, 2, 0, 1};
    vi arr2 = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    cout << rec(arr1) << endl; // 2 1 -1 0
    cout << rec(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
    cout << endl;
    cout << tab(arr1) << endl; // 2 1 -1 0
    cout << tab(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
    cout << endl;
    cout << rec2(arr1) << endl; // 2 1 -1 0
    cout << rec2(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
    cout << endl;
    cout << tab2(arr1) << endl; // 2 1 -1 0
    cout << tab2(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
}
