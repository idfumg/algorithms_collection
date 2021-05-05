#include "../../template.hpp"

int rec(vi arr, int k, int n, int was) {
    if (k < 0) return -INF;
    if (n == 0 and was) return -INF;
    if (n == 0 or k == 0) return 0;
    if (was) return max(rec(arr, k, n - 1, 1), rec(arr, k - 1, n - 1, 0) - arr[n - 1]);
    return max(rec(arr, k, n - 1, 0), rec(arr, k, n - 1, 1) + arr[n - 1]);
}

int rec(vi arr) {
    return rec(arr, 2, arr.size(), 0);
}

int tab(vi arr) {
    int n = arr.size(), K = 2;
    vvvi dp(K + 1, vvi(n + 1, vi(2)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j : {0, 1}) {
                if (i == 0 and j) dp[k][i][j] = -INF;
                else if (i == 0 or k == 0) dp[k][i][j] = 0;
                else if (j) dp[k][i][j] = max(dp[k][i - 1][1], dp[k - 1][i - 1][0] - arr[i - 1]);
                else dp[k][i][j] = max(dp[k][i - 1][0], dp[k][i - 1][1] + arr[i - 1]);
            }
        }
    }
    return dp[K][n][0];
}

int tab_opt(vi arr) {
    int n = arr.size(), K = 2, idx = 0;
    vvvi dp(2, vvi(n + 1, vi(2)));
    for (int k = 0; k <= K; ++k) {
        idx = k & 1;
        for (int i = 0; i <= n; ++i) {
            for (int j : {0, 1}) {
                if (i == 0 and j) dp[idx][i][j] = -INF;
                else if (i == 0 or k == 0) dp[idx][i][j] = 0;
                else if (j) dp[idx][i][j] = max(dp[idx][i - 1][1], dp[1 - idx][i - 1][0] - arr[i - 1]);
                else dp[idx][i][j] = max(dp[idx][i - 1][0], dp[idx][i - 1][1] + arr[i - 1]);
            }
        }
    }
    return dp[idx][n][0];
}

int main() { TimeMeasure _;
    cout << rec({10, 22, 5, 75, 65, 80}) << '\n'; // 87
    cout << rec({2, 30, 15, 10, 8, 25, 80}) << '\n'; // 100
    cout << rec({100, 30, 15, 10, 8, 25, 80}) << '\n'; // 72
    cout << rec({90, 80, 70, 60, 50}) << '\n'; // 0
    cout << rec({75, 4, 25, 20, 60, 45}) << '\n'; // 61
    cout << '\n';
    cout << tab({10, 22, 5, 75, 65, 80}) << '\n'; // 87
    cout << tab({2, 30, 15, 10, 8, 25, 80}) << '\n'; // 100
    cout << tab({100, 30, 15, 10, 8, 25, 80}) << '\n'; // 72
    cout << tab({90, 80, 70, 60, 50}) << '\n'; // 0
    cout << tab({75, 4, 25, 20, 60, 45}) << '\n'; // 61
    cout << '\n';
    cout << tab_opt({10, 22, 5, 75, 65, 80}) << '\n'; // 87
    cout << tab_opt({2, 30, 15, 10, 8, 25, 80}) << '\n'; // 100
    cout << tab_opt({100, 30, 15, 10, 8, 25, 80}) << '\n'; // 72
    cout << tab_opt({90, 80, 70, 60, 50}) << '\n'; // 0
    cout << tab_opt({75, 4, 25, 20, 60, 45}) << '\n'; // 61
}
