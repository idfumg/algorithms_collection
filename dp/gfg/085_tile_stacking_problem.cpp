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
        //debug(prefixsum);
        for (int i = 1; i <= n; ++i) {
            prefixsum[i][j] = dp[i][j] + prefixsum[i - 1][j];
        }
    }
    return dp[n][m];
}

int rec2(int n, int m, int k, int tries) {
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (k == 0) return rec2(n, m - 1, tries, tries);
    return rec2(n, m - 1, tries, tries) + rec2(n - 1, m, k - 1, tries);
}

int rec2(int n, int m, int k) {
    return rec2(n, m, k, k);
}

int tab3(int n, int m, int K) {
    vvvi dp(n + 1, vvi(m + 1, vi(K + 1)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= K; ++k) {
                if (i == 0) dp[i][j][k] = 1;
                else if (j == 0) dp[i][j][k] = 0;
                else if (k == 0) dp[i][j][k] = dp[i][j - 1][K];
                else dp[i][j][k] = dp[i][j - 1][K] + dp[i - 1][j][k - 1];
            }
        }
    }
    return dp[n][m][K];
}

int main() { TimeMeasure _; __x();
    // `n` - tiles, `1..m` - size, `k` - repetitions of each tile
    cout << rec(3, 3, 1) << endl; // 1
    cout << rec(3, 3, 2) << endl; // 7
    cout << endl;
    cout << tab(3, 3, 1) << endl; // 1
    cout << tab(3, 3, 2) << endl; // 7
    cout << endl;
    cout << tab2(3, 3, 1) << endl; // 1
    cout << tab2(3, 3, 2) << endl; // 7
    cout << endl;
    cout << rec2(3, 3, 1) << endl; // 1
    cout << rec2(3, 3, 2) << endl; // 7
    cout << endl;
    cout << tab3(3, 3, 1) << endl; // 1
    cout << tab3(3, 3, 2) << endl; // 7
}
