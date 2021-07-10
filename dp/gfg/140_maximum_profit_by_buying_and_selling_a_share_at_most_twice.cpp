#include "../../template.hpp"

int rec(vi arr, int n, int prev, int k) {
    if (n == 0 and prev != -1) return -INF;
    if (k <= 0 or n == 0) return 0;
    if (prev != -1) return max(rec(arr, n - 1, prev, k), rec(arr, n - 1, -1, k - 1) - arr[n - 1]);
    return max(rec(arr, n - 1, n, k) + arr[n - 1], rec(arr, n - 1, -1, k));
}

int rec(vi arr) {
    int ans = -INF;
    int n = arr.size();
    for (int i = n; i >= 1; --i) {
        ans = max(ans, rec(arr, i - 1, i, 2) + arr[i - 1]);
    }
    return max(0, ans);
}

int tab(vi arr) {
    int n = arr.size();
    int K = 2;
    vvvi dp(n + 1, vvi(2 + 1, vi(K + 1)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 1; k <= K; ++k) {
                if (i == 0 and j != 0) {
                    dp[i][j][k] = -INF;
                }
                else if (i == 0 or k == 0) {
                    dp[i][j][k] = 0;
                }
                else if (j != 0 and k != 0) {
                    dp[i][j][k] = max(dp[i - 1][1][k], dp[i - 1][0][k - 1] - arr[i - 1]);
                }
                else {
                    dp[i][j][k] = max(dp[i - 1][1][k] + arr[i - 1], dp[i - 1][0][k]);
                }
            }
        }
    }

    int ans = -INF;
    for (int i = n; i >= 1; --i) {
        ans = max(ans, dp[i - 1][1][2] + arr[i - 1]);
    }
    return max(0, ans);
}

int opt(vi arr) {
    int n = arr.size();
    int K = 2;
    int idx = 0;
    vvvi dp(2, vvi(n + 1, vi(K + 1)));
    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int j = 0; j <= n; ++j) {
            for (int k = 1; k <= K; ++k) {
                if (i == 0 and j != 0) {
                    dp[idx][j][k] = -INF;
                }
                else if (i == 0 or k == 0) {
                    dp[idx][j][k] = 0;
                }
                else if (j != 0 and k != 0) {
                    dp[idx][j][k] = max(dp[1 - idx][j][k], dp[1 - idx][0][k - 1] - arr[i - 1]);
                }
                else {
                    dp[idx][j][k] = max(dp[1 - idx][i][k] + arr[i - 1], dp[1 - idx][0][k]);
                }
            }
        }
    }

    int ans = -INF;
    for (int i = n; i >= 1; --i) {
        idx = i & 1;
        ans = max(ans, dp[1 - idx][i][2] + arr[i - 1]);
    }
    return max(0, ans);
}

int rec2(vi arr, int n, int k, int chosen) {
    if (k == 0 and not chosen) return 0;
    if (n == 0 and not chosen) return 0;
    if (k == 0 and chosen) return -INF;
    if (n == 0 and chosen) return -INF;
    if (chosen == 0) return max(rec2(arr, n - 1, k, 1) + arr[n - 1], rec2(arr, n - 1, k, 0));
    return max(rec2(arr, n - 1, k - 1, 0) - arr[n - 1], rec2(arr, n - 1, k, 1));
}

int rec2(vi arr) {
    return rec2(arr, arr.size(), 2, 0);
}

int tab2(vi arr) {
    int n = arr.size();
    int K = 2;
    vvvi dp(n + 1, vvi(K + 1, vi(2)));
    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k <= K; ++k) {
            for (int chosen : {0, 1}) {
                if (k == 0 and !chosen) dp[i][k][chosen] = 0;
                else if (i == 0 and !chosen) dp[i][k][chosen] = 0;
                else if (k == 0 and chosen) dp[i][k][chosen] = -INF;
                else if (i == 0 and chosen) dp[i][k][chosen] = -INF;
                else if (chosen == 0) dp[i][k][chosen] = max(dp[i - 1][k][1] + arr[i - 1], dp[i - 1][k][0]);
                else dp[i][k][chosen] = max(dp[i - 1][k - 1][0] - arr[i - 1], dp[i - 1][k][1]);
            }
        }
    }
    return dp[n][2][0];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {10, 22, 5, 75, 65, 80}; // 87
    vi arr2 = {2, 30, 15, 10, 8, 25, 80}; // 100
    vi arr3 = {100, 30, 15, 10, 8, 25, 80}; // 72
    vi arr4 = {90, 80, 70, 60, 50}; // 0
    vi arr5 = {75, 4, 25, 20, 60, 45}; // 61
    vi arr6 = {40, 5, 80, 20, 60}; // 115

    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << rec(arr5) << endl;
    cout << rec(arr6) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
    cout << tab(arr5) << endl;
    cout << tab(arr6) << endl;
    cout << endl;
    cout << opt(arr1) << endl;
    cout << opt(arr2) << endl;
    cout << opt(arr3) << endl;
    cout << opt(arr4) << endl;
    cout << opt(arr5) << endl;
    cout << opt(arr6) << endl;
    cout << endl;
    cout << rec2(arr1) << endl;
    cout << rec2(arr2) << endl;
    cout << rec2(arr3) << endl;
    cout << rec2(arr4) << endl;
    cout << rec2(arr5) << endl;
    cout << rec2(arr6) << endl;
    cout << endl;
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
    cout << tab2(arr3) << endl;
    cout << tab2(arr4) << endl;
    cout << tab2(arr5) << endl;
    cout << tab2(arr6) << endl;
}
