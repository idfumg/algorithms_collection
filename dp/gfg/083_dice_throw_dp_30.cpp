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

int main() { TimeMeasure _; __x();
    cout << rec(4, 2, 1) << endl; // 0
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
}
