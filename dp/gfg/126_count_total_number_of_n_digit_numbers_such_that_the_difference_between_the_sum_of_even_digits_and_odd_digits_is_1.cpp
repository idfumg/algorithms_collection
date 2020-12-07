#include "../../template.hpp"

bool IsSatisfy(int n) {
    int isodd = static_cast<int>(log10(n)) & 1;
    int odd = 0;
    int even = 0;
    while (n > 0) {
        if (isodd) {
            odd += n % 10;
        }
        else {
            even += n % 10;
        }
        isodd = !isodd;
        n /= 10;
    }
    return even - odd == 1;
}

int naive(int n) {
    int start = pow(10, n - 1);
    int stop = pow(10, n) - 1;
    int ans = 0;
    for (int i = start; i <= stop; ++i) {
        if (IsSatisfy(i)) {
            ++ans;
        }
    }
    return ans;
}

int rec(int n, int even, int odd) {
    bool isodd = (n + 1) & 1;
    if (n == 0) {
        if (even - odd == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int ans = 0;
    for (int i = n == 1; i <= 9; ++i) {
        if (isodd) {
            ans += rec(n - 1, even, odd + i);
        }
        else {
            ans += rec(n - 1, even + i, odd);
        }
    }
    return ans;
}

int rec(int n) {
    return rec(n, 0, 0);
}

int rec2(int n, int diff) {
    bool isodd = (n + 1) & 1;
    if (n == 0) {
        if (diff == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int ans = 0;
    for (int i = n == 1; i <= 9; ++i) {
        if (isodd) {
            ans += rec2(n - 1, diff - i);
        }
        else {
            ans += rec2(n - 1, diff + i);
        }
    }
    return ans;
}

int rec2(int n) {
    return rec2(n, 0);
}

int tab(int digits) {
    int n = digits * 9;
    vvvi dp(digits + 1, vvi(n + 1, vi(n + 1)));
    for (int i = 0; i <= digits; ++i) {
        for (int j = n; j >= 0; --j) {
            for (int k = n; k >= 0; --k) {
                if (i == 0) {
                    if (j - k == 1) {
                        dp[i][j][k] = 1;
                    }
                    else {
                        dp[i][j][k] = 0;
                    }
                }
                else {
                    int ans = 0;
                    bool isodd = (i + 1) & 1;
                    for (int p = i == 1; p <= 9; ++p) {
                        if (isodd) {
                            if (k + p <= n) {
                                ans += dp[i - 1][j][k + p];
                            }
                        }
                        else {
                            if (j + p <= n) {
                                ans += dp[i - 1][j + p][k];
                            }
                        }
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
    }
    return dp[digits][0][0];
}

int rec3(int total, int n, int odd, int even) {
    if (n == total) return even - odd == 1;
    int count = 0;
    for (int i = ((odd == 0 and even == 0) ? 1 : 0); i < 10; ++i) {
        if (n % 2 == 0) count += rec3(total, n + 1, odd, even + i);
        else count += rec3(total, n + 1, odd + i, even);
    }
    return count;
}

int rec3(int n) {
    return rec3(n, 0, 0, 0);
}

int tab3(int n) {
    int total = pow(9, n / 2 + 1);
    vvvi dp(n + 2, vvi(total + 10, vi(total + 10)));
    for (int i = n; i >= 0; --i) {
        for (int j = total; j >= 0; --j) {
            for (int k = total; k >= 0; --k) {
                if (i == n) {
                    dp[i][j][k] = k - j == 1;
                }
                else {
                    int count = 0;
                    for (int p = (j == 0 and k == 0); p < 10; ++p) {
                        if (i % 2 == 0) count += dp[i + 1][j][k + p];
                        else count += dp[i + 1][j + p][k];
                    }
                    dp[i][j][k] = count;
                }
            }
        }
    }
    return dp[0][0][0];
}

int main() { TimeMeasure _; __x();
    cout << naive(2) << endl; // 9
    cout << naive(3) << endl; // 54
    cout << rec(2) << endl; // 9
    cout << rec(3) << endl; // 54
    cout << rec2(2) << endl; // 9
    cout << rec2(3) << endl; // 54
    cout << tab(2) << endl; // 9
    cout << tab(3) << endl; // 54
    cout << rec3(2) << endl; // 9
    cout << rec3(3) << endl; // 54
    cout << tab3(2) << endl; // 9
    cout << tab3(3) << endl; // 54
}
