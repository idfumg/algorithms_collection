#include "../../template.hpp"

int rec(const string& s, int m, int n) {
    if (m < 0 || n < 0) return 0;
    if (s[m] == s[n] && m != n) return 1 + rec(s, m - 1, n - 1);
    return max(rec(s, m - 1, n), rec(s, m, n - 1));
}

int rec(const string& s) {
    return rec(s, s.size() - 1, s.size() - 1);
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 or j == 0) {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == s[j - 1] && i != j) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main() { TimeMeasure _; __x();
    static const string s1 = "abc";
    static const string s2 = "aab";
    static const string s3 = "aabb";
    static const string s4 = "axxxy";
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
