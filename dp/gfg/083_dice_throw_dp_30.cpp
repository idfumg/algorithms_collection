#include "../../template.hpp"

int rec(int m, int n, int sum) {
    if (n == 0 && sum == 0) return 1;
    if (n < 0 || sum < 0) return 0;
    int ways = 0;
    for (int i = 1; i <= m; ++i) {
        ways += rec(m, n - 1, sum - i);
    }
    return ways;
}

int tab(int m, int n, int sum) {
    vvi dp(sum + 1, vi(n + 1));
    int idx = 0;
    for (int j = 0; j <= n; ++j) {
        idx = j & 1;
        for (int i = 0; i <= sum; ++i) {
            if (i == 0 && j == 0) {
                dp[i][idx] = 1;
            }
            else {
                for (int k = 1; k <= m; ++k) {
                    if (i >= k && j > 0) {
                        dp[i][idx] += dp[i - k][1 - idx];
                    }
                }
            }
        }
    }
    return dp[sum][idx];
}

int rec2(int m, int n, int sum, int face) {
    if (n < 0 or sum < 0 or face > m) {
        return 0;
    }
    if (n == 0 and sum == 0) {
        return 1;
    }
    return rec2(m, n, sum, face + 1) + rec2(m, n - 1, sum - face, 1);
}

int rec2(int m, int n, int sum) {
    return rec2(m, n, sum, 1);
}

int tab2(int m, int n, int sum) {
    vvvi dp(n + 1, vvi(sum + 1, vi(m + 2)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            for (int k = m; k >= 1; --k) {
                if (i == 0 and j == 0) {
                    dp[i][j][k] = 1;
                }
                else if (i == 0 or j == 0) {
                    dp[i][j][k] = 0;
                }
                else {
                    dp[i][j][k] = dp[i][j][k + 1] + (j >= k ? dp[i - 1][j - k][1] : 0);
                }
            }
        }
    }
    return dp[n][sum][1];
}

int main() { TimeMeasure _; __x();
    cout << rec(4, 2, 1) << endl; // 0 // faces n target
    cout << rec(2, 2, 3) << endl; // 2
    cout << rec(6, 3, 8) << endl; // 21
    cout << rec(4, 2, 5) << endl; // 4
    cout << rec(4, 3, 5) << endl; // 6
    cout << endl;
    cout << tab(4, 2, 1) << endl; // 0
    cout << tab(2, 2, 3) << endl; // 2
    cout << tab(6, 3, 8) << endl; // 21
    cout << tab(4, 2, 5) << endl; // 4
    cout << tab(4, 3, 5) << endl; // 6
    cout << endl;
    cout << rec2(4, 2, 1) << endl; // 0
    cout << rec2(2, 2, 3) << endl; // 2
    cout << rec2(6, 3, 8) << endl; // 21
    cout << rec2(4, 2, 5) << endl; // 4
    cout << rec2(4, 3, 5) << endl; // 6
    cout << endl;
    cout << tab2(4, 2, 1) << endl; // 0
    cout << tab2(2, 2, 3) << endl; // 2
    cout << tab2(6, 3, 8) << endl; // 21
    cout << tab2(4, 2, 5) << endl; // 4
    cout << tab2(4, 3, 5) << endl; // 6
}
