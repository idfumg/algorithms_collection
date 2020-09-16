#include "../template.hpp"

bool rec(const std::string& S, const std::string& P, int m, int n) {
    if (n == 0 and m == 0) return true;
    if (n == 0 and m != 0) return false;
    if (m == 0 and P[n - 1] == '*') return rec(S, P, m, n - 1);
    if (m == 0 and P[n - 1] != '*') return false;
    if (S[m - 1] == P[n - 1]) return rec(S, P, m - 1, n - 1);
    if (P[n - 1] == '?') return rec(S, P, m - 1, n - 1);
    if (P[n - 1] == '*') return rec(S, P, m - 1, n) or rec(S, P, m, n - 1);
    return false;
}

bool rec(const std::string& S, const std::string& P) {
    return rec(S, P, size(S), size(P));
}

bool tab(const std::string& S, const std::string& P) {
    int m = size(S), n = size(P);
    vvb dp(m + 1, vb(n + 1));
    dp[0][0] = true;
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0 and P[j - 1] == '*') dp[0][j] = dp[0][j - 1];
            else if (i == 0 and P[j - 1] != '*') dp[0][j] = false;
            else if (S[i - 1] == P[j - 1] or P[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if (P[j - 1] == '*') dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("baaabab", "*****ba*****ab") << endl;
    cout << rec("baaabab", "baaa?ab") << endl;
    cout << rec("baaabab", "ba*a?") << endl;
    cout << rec("baaabab", "a*ab") << endl;

    cout << tab("baaabab", "*****ba*****ab") << endl;
    cout << tab("baaabab", "baaa?ab") << endl;
    cout << tab("baaabab", "ba*a?") << endl;
    cout << tab("baaabab", "a*ab") << endl;
}
