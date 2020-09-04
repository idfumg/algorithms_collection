#include "../../template.hpp"

int rec(const int n, const int m, const int k) {
    if (n == 0) return 1;
    if (n < 0 || m <= 0) return 0;

    int count = 0;
    for (int i = 0; i <= k; ++i) {
        count += rec(n - i, m - 1, k);
    }
    return count;
}

int tab(const int n, const int m, const int k) {
    vvi dp(n + 1, vi(m + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (j > 0) {
                int count = 0;
                for (int ik = 0; ik <= k; ++ik) {
                    if (i >= ik) {
                        count += dp[i - ik][j - 1];
                    }
                }
                dp[i][j] = count;
            }
        }
    }
    return dp[n][m];
}

int tab2(const int n, const int m, const int k) {
    vvi dp(n + 1, vi(m + 1));
    vvi prefixsum(n + 1, vi(m + 1));
    for (int j = 0; j <= m; ++j) {
        for (int i = 0; i <= n; ++i) {
            if (i == 0) {
                dp[i][j] = 1;
                prefixsum[i][j] = 1;
            }
            if (j == 0) {
                prefixsum[i][j] = 1;
            }
            else {
                dp[i][j] = prefixsum[i][j - 1];
                if (i > k) {
                    dp[i][j] -= prefixsum[i - k - 1][j - 1];
                }
            }
        }
        debug(prefixsum);
        for (int i = 1; i <= n; ++i) {
            prefixsum[i][j] = dp[i][j] + prefixsum[i - 1][j];
        }
    }
    return dp[n][m];
}

int main() { TimeMeasure _; __x();
    // `n` - tiles, `1..m` - size, `k` - repetitions of each tile
    cout << rec(3, 3, 1) << endl; // 1
    cout << rec(3, 3, 2) << endl; // 7
    cout << tab(3, 3, 1) << endl; // 1
    cout << tab(3, 3, 2) << endl; // 7
    cout << tab2(3, 3, 1) << endl; // 1
    cout << tab2(3, 3, 2) << endl; // 7
}
