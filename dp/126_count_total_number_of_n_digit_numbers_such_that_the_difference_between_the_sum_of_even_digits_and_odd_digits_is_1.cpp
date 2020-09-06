#include "../template.hpp"

int rec(int n, int prev, bool even) {
    if (n == 0 and prev == 1) return 1;
    if (n == 0) return 0;
    int count = 0;
    for (int i = 0; i <= 9; ++i) {
        count += rec(n - 1, even ? (prev + i) : (prev - i), not even);
    }
    return count;
}

int rec(int n) {
    int count = 0;
    for (int i = 1; i <= 9; ++i) {
        count += rec(n - 1, i, false);
    }
    return count;
}

int tab(int n) {
    vvvi dp(n + 1, vvi(n * 9 + 2, vi(2)));
    int total = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= n * 9; ++j) {
            for (bool even : {false, true}) {
                if (i == 0 and j == 1) {
                    dp[i][j][true] = dp[i][j][false] = 1;
                }
                else if (i == 0) {
                    dp[i][j][true] = dp[i][j][false] = 0;
                }
                else {
                    int count = 0;
                    for (int k = (i == 1 ? 1 : 0); k <= 9; ++k) {
                        if (j + k <= n * 9 and even) {
                            count += dp[i - 1][j + k][false];
                        }
                        else if (j - k >= 0) {
                            count += dp[i - 1][j - k][true];
                        }
                    }
                    dp[i][j][even] = count;
                    total = max(total, count);
                }
            }
        }
    }
    return total;
}

int main() { TimeMeasure _; __x();
    cout << rec(2) << endl;
    cout << rec(3) << endl;
    cout << tab(2) << endl;
    cout << tab(3) << endl;
}
