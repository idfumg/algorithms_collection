#include "../template.hpp"

int tab(const string& s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 2));
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == '(' and s[i] == ')') {
            dp[i][i + 1] = 2;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            if (s[i - 1] == '(' and s[j - 1] == ')') {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            for (int p = 0; p <= k; ++p) {
                dp[i][j] = max(dp[i][j], dp[i][p] + dp[i + p + 1][j]);
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    print(tab("()())")); // 4
    print(tab("()(((((()")); // 4
    print(tab("((()))")); // 6
    print(tab("())")); // 2
}
