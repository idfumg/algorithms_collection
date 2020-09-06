#include "../template.hpp"

int tab(const string& s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 2 + dp[i + 1][j -  1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return n - dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << tab("baca") << endl; // 1
    cout << tab("geek") << endl; // 2
}
