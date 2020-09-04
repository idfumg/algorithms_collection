#include "../template.hpp"

int rec(vi& v, vi& w, int W, int total, int n) {
    if (W == 0) return total;
    if (n < 0 or W < 0) return -INF;
    const auto a = rec(v, w, W, total, n - 1);
    const auto b = rec(v, w, W - w[n], total + v[n], n);
    return max(a, b);
}

int rec(vi& v, vi& w, int W) {
    return rec(v, w, W, 0, v.size() - 1);
}

int tab(vi& v, vi& w, int W) {
    const auto n = v.size();
    vvi dp(n + 1, vi(W + 1));
    vvpi prev(n + 1, vpi(W + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            prev[i][j] = pi{i - 1, j};
            if (j >= w[i - 1]) {
                const auto b = dp[i][j - w[i - 1]] + v[i - 1];
                if (b > dp[i][j]) {
                    dp[i][j] = max(dp[i][j], b);
                    prev[i][j] = pi{i, j - w[i - 1]};
                }
            }
        }
    }
    int currentW = W;
    for (pi i = pi{n, W}; i.first != 0 && i.second != 0; i = prev[i.first][i.second]) {
        if (w[i.first - 1] <= currentW) {
            cout << w[i.first - 1] << ':' << v[i.first - 1] << ' ';
            currentW -= w[i.first - 1];
        }
    }
    cout << endl;
    return dp[n][W];
}

int main() { TimeMeasure _; __x();
    vi v1 = {1, 30}, w1 = {1, 50}; int W1 = 100;
    vi v2 = {10, 40, 50, 70}, w2 = {1, 3, 4, 5}; int W2 = 8;
    cout << rec(v1, w1, W1) << endl;
    cout << rec(v2, w2, W2) << endl;
    cout << tab(v1, w1, W1) << endl;
    cout << tab(v2, w2, W2) << endl;
}
