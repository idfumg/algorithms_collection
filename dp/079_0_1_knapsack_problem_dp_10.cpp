#include "../../template.hpp"

int rec(vi& v, vi& w, int W, int total, int n) {
    if (W == 0) return total;
    if (n < 0 or W < 0) return -INF;
    const auto a = rec(v, w, W, total, n - 1);
    const auto b = rec(v, w, W - w[n], total + v[n], n - 1);
    return max(a, b);
}

int rec(vi& v, vi& w, int W) {
    return rec(v, w, W, 0, v.size() - 1);
}

int tab(vi& v, vi& w, int W) {
    const int n = v.size();
    vvi dp(2, vi(W + 1));
    vvpi prev(n + 1, vpi(W + 1));
    int idx = 0;
    for (int j = 1; j <= n; ++j) {
        idx = j & 1;
        for (int i = 1; i <= W; ++i) {
            const auto a = dp[1 - idx][i];
            dp[idx][i] = a;
            prev[j][i] = pi{j - 1, i};

            if (i >= w[j - 1]) {
                const auto b = dp[1 - idx][i - w[j - 1]] + v[j - 1];
                if (b > a) {
                    dp[idx][i] = b;
                    prev[j][i] = pi{j - 1, i - w[j - 1]};
                }
            }
        }
    }
    int currentW = W;
    for (pi i = pi{n, W}; i.first != 0 and i.second != 0; i = prev[i.first][i.second]) {
        if (w[i.first - 1] <= currentW) {
            cout << w[i.first - 1] << ':' << v[i.first - 1] << ' ';
            currentW -= w[i.first - 1];
        }
    }
    cout << endl;
    return dp[idx][W];
}

int main() { TimeMeasure _; __x();
    vi v1 = {60, 100, 120}, w1 = {10, 20, 30}; int W1 = 50;
    vi v2 = {40, 100, 50, 60}, w2 = {20, 10, 40, 30}; int W2 = 60;
    cout << rec(v1, w1, W1) << endl;
    cout << rec(v2, w2, W2) << endl;
    cout << tab(v1, w1, W1) << endl;
    cout << tab(v2, w2, W2) << endl;
}
