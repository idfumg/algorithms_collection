#include "../../template.hpp"

int tab(string s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = INF;
            }
            else if (i == j) {
                dp[i][j] = 0;
            }
            else if (j - i == 1) {
                dp[i][j] = s[i - 1] != s[j - 1];
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << tab("baca") << endl; // 1
    cout << tab("geek") << endl; // 2
    cout << tab("aebcbda") << endl; // 2
    cout << tab("geeksforgeeks") << endl; // 8
}
