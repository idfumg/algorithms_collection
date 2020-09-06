#include "../template.hpp"

int rec_(int n, int sum) {
    if (sum == 0 and n == 0) return 1;
    if (n == 0) return 0;
    int count = 0;
    for (int i = 0; i <= 9; ++i) {
        count += rec_(n - 1, sum - i);
    }
    return count;
}

int rec(int n, int sum) {
    int count = 0;
    for (int i = 1; i <= 9; ++i) {
        count += rec_(n - 1, sum - i);
    }
    return count;
}

int tab(int n, int sum) {
    vvi dp(sum + 1, vi(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            int count = 0;
            for (int i = (j == 1 ? 1 : 0); i <= 9; ++i) {
                if (sum >= i) {
                    count += dp[sum - i][j - 1];
                }
            }
            dp[i][j] = count;
        }
    }
    return dp[sum][n];
}

int main() { TimeMeasure _; __x();
    cout << rec(2, 2) << endl;
    cout << rec(2, 5) << endl;
    cout << rec(3, 6) << endl;
    cout << endl;
    cout << tab(2, 2) << endl;
    cout << tab(2, 5) << endl;
    cout << tab(3, 6) << endl;
}
