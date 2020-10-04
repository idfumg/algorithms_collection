#include "../template.hpp"

bool rec(const string& a, const string& b, int m, int n) {
    if (m == 0 and n == 0) return true;
    if (m != 0 and n == 0) return false;
    if (m == 0 and b[n - 1] != '*') return false;
    if (m == 0 and b[n - 1] == '*') return rec(a, b, m, n - 1);
    if (a[m - 1] == b[n - 1]) return rec(a, b, m - 1, n - 1);
    if (b[n - 1] == '?') return rec(a, b, m - 1, n - 1);
    if (b[n - 1] == '*') return rec(a, b, m - 1, n) or rec(a, b, m, n - 1);
    return false;
}

bool rec(const string& a, const string& b) {
    return rec(a, b, a.size(), b.size());
}

bool tab(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vvb dp(m + 1, vb(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[i][j] = true;
            else if (i != 0 and j == 0) dp[i][j] = false;
            else if (i == 0 and b[j - 1] != '*') dp[i][j] = false;
            else if (i == 0 and b[j - 1] == '*') dp[i][j] = dp[i][j - 1];
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else if (b[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if (b[j - 1] == '*') dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("baaabab", "*****ba*****ab") << '\n'; // true
    cout << rec("baaabab", "baaa?ab") << '\n'; // true
    cout << rec("baaabab", "ba*a?") << '\n'; // true
    cout << rec("baaabab", "a*ab") << '\n'; // false
    cout << rec("baaabab", "*b") << '\n'; // true
    cout << '\n';
    cout << tab("baaabab", "*****ba*****ab") << '\n'; // true
    cout << tab("baaabab", "baaa?ab") << '\n'; // true
    cout << tab("baaabab", "ba*a?") << '\n'; // true
    cout << tab("baaabab", "a*ab") << '\n'; // false
    cout << tab("baaabab", "*b") << '\n'; // true
}
