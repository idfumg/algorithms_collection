#include "../template.hpp"

int tab(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1, INF));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 or j == 0) {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] - '0') * 2;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int total = 0;
    for (int i = 0; i < m; ++i) total += a[i] - '0';
    for (int i = 0; i < n; ++i) total += b[i] - '0';
    return total - dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << tab("3759", "9350") << endl;
    cout << tab("3198", "98") << endl;
}
