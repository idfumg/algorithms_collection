#include "../../template.hpp"

int rec(int n, int len, int prod) {
    if (n <= len) {
        return prod * n;
    }
    return max({rec(n - len, len, prod * len),
                rec(n, len + 1, prod)});
}

int rec(int n) {
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        ans = max(ans, rec(n - i, 1, i));
    }
    return ans;
}

int rec2(int n, int len) {
    if (n <= len) {
        return n;
    }
    return max({rec2(n - len, len) * len,
                rec2(n, len + 1)});
}

int rec2(int n) {
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        ans = max(ans, rec2(n - i, 1) * i);
    }
    return ans;
}

int rec3(int init, int n, int i, int total) {
    if (i > 9 or n < 0 or i == init) {
        return -1;
    }
    if (n == 0) {
        return total;
    }
    return max(rec3(init, n - i, i, total * i),
               rec3(init, n, i + 1, total));
}

int rec3(int n) {
    return rec3(n, n, 1, 1);
}

int tab(int n) {
    vvi dp(n + 1, vi(10, 1));
    int ans = 0;
    for (int len = min(9, n); len >= 1; --len) {
        for (int i = 0; i <= n - len; ++i) {
            for (int j = len; j >= 1; --j) {
                if (i <= j) {
                    dp[i][j] = i;
                }
                else {
                    dp[i][j] = max(dp[i - j][j] * j, dp[i][j + 1]);
                }
            }
        }
        ans = max(ans, dp[n - len][1] * len);
    }
    return ans;
}

int tab2(int n) { // TC O(n), MC O(n)
    vvi dp(n + 1, vi(2, 1));
    int ans = 0;
    int idx = 0;
    for (int len = min(9, n); len >= 1; --len) {
        for (int i = 0; i <= n - len; ++i) {
            for (int j = len; j >= 1; --j) {
                idx = j & 1;
                if (i <= j) {
                    dp[i][idx] = i;
                }
                else {
                    dp[i][idx] = max(dp[i - j][idx] * j, dp[i][1 - idx]);
                }
            }
        }
        ans = max(ans, dp[n - len][1] * len);
    }
    return ans;
}

int tab3(int n) {
    vvi dp(n + 1, vi(11, 1));
    for (int j = 9; j >= 1; --j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 9; j >= 1; --j) {
            if (j != n) {
                dp[i][j] = dp[i][j + 1];
                if (i >= j) {
                    dp[i][j] = max(dp[i][j], dp[i - j][j] * j);
                }
            }
        }
    }
    return dp[n][1];
}

int rec4_(int n) {
    if (n <= 1) return 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, rec4_(n - i) * i);
    }
    return max(ans, n);
}

int rec4(int n) {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, rec4_(n - i) * i);
    }
    return ans;
}

int tab4(int n) {
    vi dp(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (i == 0 or i == 1) dp[i] = 1;
        else {
            int ans = 0;
            for (int k = 1; k <= i; ++k) {
                ans = max(ans, dp[i - k] * k);
            }
            dp[i] = max(ans, i);
        }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, dp[n - i] * i);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec(2) << endl; // 1
    cout << rec(3) << endl; // 2
    cout << rec(4) << endl; // 4
    cout << rec(5) << endl; // 6
    cout << rec(10) << endl; // 36
    cout << endl;
    cout << rec2(2) << endl; // 1
    cout << rec2(3) << endl; // 2
    cout << rec2(4) << endl; // 4
    cout << rec2(5) << endl; // 6
    cout << rec2(10) << endl; // 36
    cout << endl;
    cout << rec3(2) << endl; // 1
    cout << rec3(3) << endl; // 2
    cout << rec3(4) << endl; // 4
    cout << rec3(5) << endl; // 6
    cout << rec3(10) << endl; // 36
    cout << endl;
    cout << tab(2) << endl; // 1
    cout << tab(3) << endl; // 2
    cout << tab(4) << endl; // 4
    cout << tab(5) << endl; // 6
    cout << tab(10) << endl; // 36
    cout << endl;
    cout << tab2(2) << endl; // 1
    cout << tab2(3) << endl; // 2
    cout << tab2(4) << endl; // 4
    cout << tab2(5) << endl; // 6
    cout << tab2(10) << endl; // 36
    cout << endl;
    cout << tab3(2) << endl; // 1
    cout << tab3(3) << endl; // 2
    cout << tab3(4) << endl; // 4
    cout << tab3(5) << endl; // 6
    cout << tab3(10) << endl; // 36
    cout << endl;
    cout << rec4(2) << endl; // 1
    cout << rec4(3) << endl; // 2
    cout << rec4(4) << endl; // 4
    cout << rec4(5) << endl; // 6
    cout << rec4(10) << endl; // 36
    cout << endl;
    cout << tab4(2) << endl; // 1
    cout << tab4(3) << endl; // 2
    cout << tab4(4) << endl; // 4
    cout << tab4(5) << endl; // 6
    cout << tab4(10) << endl; // 36
}
