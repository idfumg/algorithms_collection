#include "../../template.hpp"

int rec(const vvi& arr, const int m, const int n, const int i, const int j) {
    if (i == m and j == n) return 1;
    if (i < 0 or j < 0 or i > m or j > n) return 0;
    if (arr[i][j] == -1) return 0;
    return rec(arr, m, n, i + 1, j) + rec(arr, m, n, i, j + 1);
}

int rec(const vvi& arr) {
    return rec(arr, arr.size() - 1, arr[0].size() - 1, 0, 0);
}

int tab(const vvi& arr) {
    int m = arr.size(), n = arr[0].size(), idx = 0;
    vvi dp(m + 1, vi(2));
    for (int j = 1; j <= n; ++j) {
        idx = j & 1;
        for (int i = 1; i <= m; ++i) {
            if (i == 1 && j == 1) {
                dp[i][idx] = 1;
            }
            else if (i == 1) {
                if (arr[i - 1][j - 1] != -1 && dp[i][1 - idx] != 0) {
                    dp[i][idx] = 1;
                }
            }
            else if (j == 1) {
                if (arr[i - 1][j - 1] != -1 && dp[i - 1][idx] != 0) {
                    dp[i][idx] = 1;
                }
            }
            else {
                if (arr[i - 1][j - 1] == -1) {
                    dp[i][idx] = 0;
                }
                else {
                    dp[i][idx] = dp[i - 1][idx] + dp[i][1 - idx];
                }
            }
        }
    }
    return dp[m][idx];
}

int main() { TimeMeasure _; __x();
    vvi arr = {{0,  0, 0, 0},
               {0, -1, 0, 0},
               {-1, 0, 0, 0},
               {0,  0, 0, 0}};
    cout << rec(arr) << endl;
    cout << tab(arr) << endl;
}
