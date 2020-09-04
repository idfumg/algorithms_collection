#include "../../template.hpp"

int rec(int n, int k) {
    if (k == 1 || k == 0) return k;
    if (n == 1) return k;
    int mini = INF;
    for (int i = 1; i <= k; ++i) {
        mini = min(mini, max(rec(n - 1, i - 1), rec(n, k - i)));
    }
    return mini + 1;
}

int tab(int n, int k) {
    vvi dp(n + 1, vi(k + 1, INF));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j == 0 || j == 1 || i == 1) {
                dp[i][j] = j;
            }
            else {
                int mini = INF;
                for (int ik = 1; ik <= j; ++ik) {
                    mini = min(mini, max(dp[i - 1][ik - 1], dp[i][j - ik]));
                }
                dp[i][j] = mini + 1;
            }
        }
    }
    return dp[n][k];
}

int main() { TimeMeasure _; __x();
    // n - number of eggs, k - number of floors
    // find minimum number of trials in the worst case to find the critical floor on which an egg will broke
    cout << rec(2, 10) << endl; // 4
    cout << tab(2, 10) << endl; // 4
    cout << tab(2, 36) << endl; // 8
}
