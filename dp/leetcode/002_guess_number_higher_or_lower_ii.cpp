#include "../../template.hpp"

int getMoneyAmount(int low, int high) {
    if (low >= high) return 0;
    int ans = INF;
    for (int i = low; i <= high; ++i) {
        ans = min(ans, max(getMoneyAmount(low, i - 1) + i, getMoneyAmount(i + 1, high) + i));
    }
    return ans;
}

int getMoneyAmount(int n) {
    return getMoneyAmount(1, n);
}

int tab(int n) {
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                int ans = INF;
                for (int p = i; p <= j; ++p) {
                    int a = p >= 1 ? dp[i][p - 1] : INF;
                    int b = p <= j ? dp[p + 1][j] : INF;
                    ans = min(ans, max(a + p, b + p));
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << getMoneyAmount(1) << endl; // 0
    cout << getMoneyAmount(2) << endl; // 1
    cout << getMoneyAmount(6) << endl; // 8
    cout << getMoneyAmount(8) << endl; // 12
    cout << getMoneyAmount(10) << endl; // 16
    cout << endl;
    cout << tab(1) << endl; // 0
    cout << tab(2) << endl; // 1
    cout << tab(6) << endl; // 8
    cout << tab(8) << endl; // 12
    cout << tab(10) << endl; // 16
}
