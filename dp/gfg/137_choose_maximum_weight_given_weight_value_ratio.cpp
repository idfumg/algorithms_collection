#include "../../template.hpp"

int rec(vi& weights, vi& values, int k, int n, int diff, int total) {
    if (n == 0) return diff == 0 ? total : -INF;
    return max(
        rec(weights, values, k, n - 1, diff, total),
        rec(weights, values, k, n - 1, diff + weights[n - 1] - values[n - 1] * k, total + weights[n - 1]));
}

int rec(vi& weights, vi& values, int k) {
        return rec(weights, values, k, weights.size(), 0, 0);
}

int tab(vi& weights, vi& values, int k) {
    int n = values.size();
    vvi dp(10 + 1, vi(n + 1));
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (weights[j - 1] >= values[j - 1] * i) {
                dp[i][j] = max(dp[i][j],
                               dp[i][j - 1] + dp[weights[j - 1] - values[j - 1] * i][j - 1] + weights[j - 1]);
            }
        }
    }
    debug(dp);
    return dp[k][n];
}

int main() { TimeMeasure _; __x();
    vi weights = {4, 8, 9};
    vi values = {2, 4, 6};
    int k = 2;
    cout << rec(weights, values, k) << endl;
    cout << tab(weights, values, k) << endl;
}
