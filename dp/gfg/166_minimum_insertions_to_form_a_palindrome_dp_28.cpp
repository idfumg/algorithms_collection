#include "../../template.hpp"

int tab(const string& s) { // With Iterative Passes Algorithm (1..1, 1..2, .. , 1..n)
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] != s[i - 2]) {
            dp[i - 1][i] = 1;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k;  j <= n; ++i, ++j) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    return dp[1][n];
}

int tab2(const string& s) { // With Straightforward Algorithm (how minimum to insert from i..j)
    int n = size(s);
    vvi dp(n + 2, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
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
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
        }
    }
    return dp[1][n];
}

int rec(string s, int i, int j) {
    if (i >= j) return 0;
    if (s[i - 1] == s[j - 1]) return rec(s, i + 1, j - 1);
    return min(rec(s, i + 1, j), rec(s, i, j - 1)) + 1;
}

int rec(string s) {
    return rec(s, 1, s.size());
}

int tab3(string s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= j) dp[i][j] = 0;
            else if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
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
    cout << endl;
    cout << rec("ab") << endl; // 1
    cout << rec("aa") << endl; // 0
    cout << rec("abc") << endl; // 2
    cout << rec("abcd") << endl; // 3
    cout << rec("abcda") << endl; // 2
    cout << rec("abcde") << endl; // 4
    cout << endl;
    cout << tab3("ab") << endl; // 1
    cout << tab3("aa") << endl; // 0
    cout << tab3("abc") << endl; // 2
    cout << tab3("abcd") << endl; // 3
    cout << tab3("abcda") << endl; // 2
    cout << tab3("abcde") << endl; // 4
}
