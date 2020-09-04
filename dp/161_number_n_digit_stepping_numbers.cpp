#include "../template.hpp"

int rec(int n, int prev) {
    if (n == 0) return 1;
    if (prev == 0 or prev == 1) return rec(n - 1, prev + 1);
    if (prev == 9) return rec(n - 1, prev - 1);
    return rec(n - 1, prev + 1) + rec(n - 1, prev - 1);
}

int rec(int n) {
    int count = 0;
    for (int i = 0; i <= 9; ++i) {
        count += rec(n - 1, i);
    }
    return count;
}

int tab(int n) {
    vvi dp(n + 1, vi(10));
    if (n == 1) return 10;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (i == 1) dp[1][j] = 1;
            else if (j == 0) dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }
    return accumulate(dp[n].begin(), dp[n].end(), 0) - dp[n][0];
}

int tab2(int n) {
    if (n == 1) return 10;
    vvi dp(n + 1, vi(10));
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= 9; ++k) {
            for (int j = 0; j <= 9; ++j) {
                if (i == 1) {
                    dp[i][j] = 1;
                }
                else if (abs(j - k) == 1) {
                    dp[i][k] += dp[i - 1][j];
                }
            }
        }
    }
    return accumulate(dp[n].begin(), dp[n].end(), 0) - dp[n][0];
}

int main() { TimeMeasure _; __x();
    cout << rec(1) << endl;
    cout << rec(2) << endl;
    cout << tab(1) << endl;
    cout << tab(2) << endl;
}
