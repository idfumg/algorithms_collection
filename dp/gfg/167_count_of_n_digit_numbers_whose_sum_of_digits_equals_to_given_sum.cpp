#include "../../template.hpp"

int rec_(int n, int sum) {
    if (sum == 0 and n == 0) return 1;
    if (n < 0 or sum < 0) return 0;
    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        ans += rec_(n - 1, sum - i);
    }
    return ans;
}

int rec(int n, int sum) {
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        ans += rec_(n - 1, sum - i);
    }
    return ans;
}

int rec2(int n, int sum, int digit, int total) {
    if (total == sum and n == 0) return 1;
    if (n <= 0 or digit > 9) return 0;
    return
        rec2(n - 1, sum, 0, total + digit) +
        rec2(n, sum, digit + 1, total);
}

int rec2(int n, int sum) {
    return rec2(n, sum, 1, 0);
}

int tab(int n, int sum) {
    vvvi dp(n + 1, vvi(9 + 2, vi(sum + 10)));
    for (int i = 0; i <= n; ++i) {
        for (int digit = 9; digit >= 0; --digit) {
            for (int total = sum; total >= 0; --total) {
                if (total == sum and i == 0) {
                    dp[i][digit][total] = 1;
                }
                else if (i == 0) {
                    dp[i][digit][total] = 0;
                }
                else {
                    dp[i][digit][total] = dp[i - 1][0][total + digit] + dp[i][digit + 1][total];
                }
            }
        }
    }
    return dp[n][1][0];
}

int tab2(int n, int sum) {
    vvvi dp(2, vvi(9 + 2, vi(sum + 10)));
    int idx = 0;
    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int digit = 9; digit >= 0; --digit) {
            for (int total = sum; total >= 0; --total) {
                if (total == sum and i == 0) {
                    dp[idx][digit][total] = 1;
                }
                else if (i == 0) {
                    dp[idx][digit][total] = 0;
                }
                else {
                    dp[idx][digit][total] = dp[1 - idx][0][total + digit] + dp[idx][digit + 1][total];
                }
            }
        }
    }
    return dp[idx][1][0];
}

int tab3(int n, int sum) {
    vvi dp(sum + 1, vi(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = 0;
            else {
                int ans = 0;
                for (int k = 0; k <= 9; ++k) {
                    if (i >= k) {
                        ans += dp[i - k][j - 1];
                    }
                }
                dp[i][j] = ans;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        if (sum >= i) {
            ans += dp[sum - i][n - 1];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec(2, 2) << endl; // 2
    cout << rec(2, 5) << endl; // 5
    cout << rec(3, 6) << endl; // 21
    cout << endl;
    cout << rec2(2, 2) << endl; // 2
    cout << rec2(2, 5) << endl; // 5
    cout << rec2(3, 6) << endl; // 21
    cout << endl;
    cout << tab(2, 2) << endl;
    cout << tab(2, 5) << endl;
    cout << tab(3, 6) << endl;
    cout << endl;
    cout << tab2(2, 2) << endl;
    cout << tab2(2, 5) << endl;
    cout << tab2(3, 6) << endl;
    cout << endl;
    cout << tab3(2, 2) << endl;
    cout << tab3(2, 5) << endl;
    cout << tab3(3, 6) << endl;
}
