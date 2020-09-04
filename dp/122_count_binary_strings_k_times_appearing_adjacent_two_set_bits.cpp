#include "../../template.hpp"

int rec(int n, int k, int prev) {
    if (n == 0 && k == 0) return 1;
    if (n <= 0 || k < 0) return 0;
    return rec(n - 1, k, 0) + (prev == 0
                               ? rec(n - 1, k, 1)
                               : rec(n - 1, k - 1, 1));
}

int rec(int n, int k) {
    return rec(n-1, k, 0) + rec(n-1, k, 1);
}

int tab(int n, int k) {
    vvvi dp(n + 1, vvi(k + 1, vi(2)));
    dp[1][0][0] = dp[1][0][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j][0] + (j > 0 ? dp[i - 1][j - 1][1] : 0);
        }
    }
    return dp[n][k][0] + dp[n][k][1];
}

int main() { TimeMeasure _; __x();
    int n1 = 5, k1 = 2;
    int n2 = 4, k2 = 1;

    cout << rec(n1, k1) << endl;
    cout << rec(n2, k2) << endl;
    cout << tab(n1, k1) << endl;
    cout << tab(n2, k2) << endl;
}
