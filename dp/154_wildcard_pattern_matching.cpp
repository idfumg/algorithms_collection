#include "../../template.hpp"

bool rec(const string& S, const string& P, int m, int n) {
    if (m == 0 and n == 0) return true;
    if (n == 0) return false;
    if (m == 0 and P[n - 1] == '*') return rec(S, P, m, n - 1);
    if (m == 0 and P[n - 1] != '*') return false;
    if (P[n - 1] == '?') return rec(S, P, m - 1, n - 1);
    if (P[n - 1] == '*') return rec(S, P, m, n - 1) or rec(S, P, m - 1, n);
    if (P[n - 1] == S[m - 1]) return rec(S, P, m - 1, n - 1);
    return false;
}

bool rec(const string& S, const string& P) {
    return rec(S, P, S.size(), P.size());
}

bool tab(const string& S, const string& P) {
    int m = S.size(), n = P.size();
    vvb dp(m + 1, vb(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[i][j] = true;
            else if (j == 0) dp[i][j] = false;
            else if (i == 0 and P[j - 1] == '*') dp[i][j] = dp[i][j - 1];
            else if (i == 0 and P[j - 1] != '*') dp[i][j] = false;
            else if (P[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if (P[j - 1] == '*') dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
            else if (P[j - 1] == S[i - 1]) dp[i][j] = dp[i - 1][j - 1];
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("baaabab", "**a*****ab") << endl;
    cout << rec("baaabab", "baaa?ab") << endl;
    cout << rec("baaabab", "ba*a?") << endl;
    cout << rec("baaabab", "a*ab") << endl;
    cout << endl;
    cout << tab("baaabab", "**a*****ab") << endl;
    cout << tab("baaabab", "baaa?ab") << endl;
    cout << tab("baaabab", "ba*a?") << endl;
    cout << tab("baaabab", "a*ab") << endl;
}
