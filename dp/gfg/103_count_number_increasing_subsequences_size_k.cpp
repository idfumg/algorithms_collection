#include "../../template.hpp"

int rec(vi arr, int k, int n, int prev) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    if (arr[n - 1] < arr[prev - 1]) return rec(arr, k - 1, n - 1, n) + rec(arr, k, n - 1, prev);
    return rec(arr, k, n - 1, prev);
}

int rec(vi arr, int k) {
    int ans = 0, n = arr.size();
    for (int i = 1; i <= n; ++i) {
        ans += rec(arr, k - 1, i - 1, i);
    }
    return ans;
}

int tab(vi arr, int K) {
    int n = arr.size();
    vvvi dp(K + 1, vvi(n + 1, vi(n + 1)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i > j) dp[k][i][j] = 0;
                else if (k == 0) dp[k][i][j] = 1;
                else if (i == 0) dp[k][i][j] = 0;
                else if (arr[i - 1] < arr[j - 1]) dp[k][i][j] = dp[k - 1][i - 1][i] + dp[k][i - 1][j];
                else dp[k][i][j] = dp[k][i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[K - 1][i - 1][i];
    }
    return ans;
}

int rec2(vi arr, int k, int n) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] < arr[n - 1]) {
            ans += rec2(arr, k - 1, i);
        }
    }
    return ans;
}

int rec2(vi arr, int k) {
    int ans = 0, n = arr.size();
    for (int i = 1; i <= n; ++i) {
        ans += rec2(arr, k - 1, i);
    }
    return ans;
}

int tab2(vi arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            if (k == 0) {
                dp[k][i] = 1;
            }
            else if (i == 0) {
                dp[k][i] = 0;
            }
            else {
                for (int j = 1; j < i; ++j) {
                    if (arr[j - 1] < arr[i - 1]) {
                        dp[k][i] += dp[k - 1][j];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[K - 1][i];
    }
    return ans;
}

int main() { // TimeMeasure _; __x();
    vi arr1 = {2, 6, 4, 5, 7}; int k1 = 3;
    vi arr2 = {12, 8, 11, 13, 10, 15, 14, 16, 20}; int k2 = 4;
    vi arr3 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k3 = 3;

    cout << rec(arr1, k1) << endl; // 5
    cout << rec(arr2, k2) << endl; // 39
    cout << rec(arr3, k3) << endl; // 31
    cout << endl;
    cout << tab(arr1, k1) << endl; // 5
    cout << tab(arr2, k2) << endl; // 39
    cout << tab(arr3, k3) << endl; // 31
    cout << endl;
    cout << rec2(arr1, k1) << endl; // 5
    cout << rec2(arr2, k2) << endl; // 39
    cout << rec2(arr3, k3) << endl; // 31
    cout << endl;
    cout << tab2(arr1, k1) << endl; // 5
    cout << tab2(arr2, k2) << endl; // 39
    cout << tab2(arr3, k3) << endl; // 31
}
