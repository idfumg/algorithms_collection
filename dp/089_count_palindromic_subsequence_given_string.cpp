#include "../../template.hpp"

int rec(const string& s, int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (s[i] == s[j]) {
        return 1 + rec(s, i + 1, j) + rec(s, i, j - 1);
    }
    return rec(s, i + 1, j) + rec(s, i, j - 1) - rec(s, i + 1, j - 1);
}

int rec(const string& s) {
    return rec(s, 0, s.size() - 1);
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    int idx = 0;
    for (int j = 0; j <= n; ++j) {
        idx = j & 1;
        for (int i = n; i >= 0; --i) {
            if (i > j) {
                dp[i][idx] = 0;
            }
            else if (i == j) {
                dp[i][idx] = 1;
            }
            else if (i > 0 && j > 0 && i < n && s[i - 1] == s[j - 1]) {
                dp[i][idx] = 1 + dp[i + 1][idx] + dp[i][1 - idx];
            }
            else if (i < n && j > 0) {
                dp[i][idx] = dp[i + 1][idx] + dp[i][1 - idx] - dp[i + 1][1 - idx];
            }
        }
    }
    return dp[1][idx];
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
