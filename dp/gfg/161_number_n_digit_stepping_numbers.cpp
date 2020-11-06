#include "../../template.hpp"

int rec(int n, int i, int prev) {
    if (i > 9 or i < 0) return 0;
    if (n == 0) return 1;
    if (prev != INF and abs(i - prev) != 1) return rec(n, i + 1, prev);
    return rec(n - 1, 0, i) + rec(n, i + 1, prev);
}

int rec(int n) {
    return rec(n, 1, INF);
}

int tab(int n) {
    vvvi dp(n + 1, vvi(11, vi(11, 0)));
    for (int i = 1; i <= n; ++i) {
        for (int j = 9; j >= 0; --j) {
            for (int k = 0; k <= 9; ++k) {
                if (i == 1) {
                    dp[i][j][k] = 1;
                }
                else if (abs(j - k) != 1) {
                    dp[i][j][k] = dp[i][j + 1][k];
                }
                else {
                    dp[i][j][k] = dp[i - 1][0][j] + dp[i][j + 1][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        ans += dp[n][1][i];
    }
    return ans + 1;
}

int rec2(int n, int prev) {
    if (n == 0) return 1;
    int count = 0;
    for (int i = 0; i <= 9; ++i) {
        if (abs(i - prev) == 1) {
            count += rec2(n - 1, i);
        }
    }
    return count;
}

int rec2(int n) {
    int count = 0;
    for (int i = 1; i <= 9; ++i) {
        count += rec2(n - 1, i);
    }
    return count;
}

int tab2(int n) {
    vvi dp(n + 1, vi(10));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else {
                for (int k = 0; k <= 9; ++k) {
                    if (abs(k - j) == 1) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= 9; ++k) {
        ans += dp[n - 1][k];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    // cout << naive(1) << endl; // 10
    // cout << naive(2) << endl; // 17
    // cout << naive(3) << endl; // 32
    // cout << '\n';
    cout << tab(1) << endl;
    cout << tab(2) << endl;
    cout << tab(3) << endl;
    cout << '\n';
    cout << rec(1) << endl;
    cout << rec(2) << endl;
    cout << rec(3) << endl;
    cout << '\n';
    cout << rec2(1) << endl;
    cout << rec2(2) << endl;
    cout << rec2(3) << endl;
    cout << '\n';
    cout << tab2(1) << endl;
    cout << tab2(2) << endl;
    cout << tab2(3) << endl;
}
