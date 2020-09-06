#include "../template.hpp"

int rec(const string& s, int i, int j) {
    if (i > j) return INF;
    if (i == j) return 0;
    if (j - i == 1)  return s[i] != s[j];
    if (s[i] == s[j]) {
        return rec(s, i + 1, j - 1);
    }
    return min({rec(s, i + 1, j), rec(s, i, j - 1)}) + 1;
}

int rec(const string& s) {
    return rec(s, 0, s.size() - 1);
}

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
    cout << rec("ab") << endl;
    cout << rec("aa") << endl;
    cout << rec("abcd") << endl;
    cout << rec("abcda") << endl;
    cout << rec("abcde") << endl;
    cout << endl;
    cout << tab("ab") << endl;
    cout << tab("aa") << endl;
    cout << tab("abcd") << endl;
    cout << tab("abcda") << endl;
    cout << tab("abcde") << endl;
}
