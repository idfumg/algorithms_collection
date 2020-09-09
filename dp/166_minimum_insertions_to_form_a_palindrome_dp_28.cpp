#include "../template.hpp"

int tab(const string& s) {
    int n = size(s);
    vvi dp(n + 2, vi(n + 2, INF));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == s[i]) {
            dp[i][i + 1] = 0;
        }
        else {
            dp[i][i + 1] = 1;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = min({j - 1, dp[i + 1][j] + dp[i][j - 1]});
            }
        }
    }
    return dp[1][n];
}

int tab2(const string& s) {
    int n = size(s);
    vvi dp(n + 2, vi(n + 2, INF));
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
                //dp[i][j] = min(j - 1, dp[i][j - 1] + dp[i + 1][j]);
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << tab("ab") << endl; // 1
    cout << tab("aa") << endl; // 0
    cout << tab("abc") << endl; // 2
    cout << tab("abcd") << endl; // 3
    cout << tab("abcda") << endl; // 2
    cout << tab("abcde") << endl; // 4
    cout << endl;
    cout << tab2("ab") << endl; // 1
    cout << tab2("aa") << endl; // 0
    cout << tab2("abc") << endl; // 2
    cout << tab2("abcd") << endl; // 3
    cout << tab2("abcda") << endl; // 2
    cout << tab2("abcde") << endl; // 4
}
