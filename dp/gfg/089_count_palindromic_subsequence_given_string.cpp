#include "../../template.hpp"

int rec(string s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (s[i - 1] == s[j - 1]) {
        return 1 + rec(s, i + 1, j) + rec(s, i, j - 1);
    }
    return rec(s, i + 1, j) + rec(s, i, j - 1) - rec(s, i + 1, j - 1);
}

int rec(string s) {
    int n = s.size();
    return rec(s, 1, n);
}

int tab(string s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
            }
            else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    static const string s1 = "abcd"; // 4
    static const string s2 = "aab"; // 4
    static const string s3 = "aaaa"; // 15
    static const string s4 = "abcb"; // 6

    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << rec(s3) << endl;
    cout << rec(s4) << endl;
    cout << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
    cout << tab(s4) << endl;
}
