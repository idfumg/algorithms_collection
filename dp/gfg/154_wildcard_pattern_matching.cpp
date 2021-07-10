#include "../../template.hpp"

bool rec(string a, string b, int m, int n) {
    if (m == 0 and n == 0) return true;
    if (b[n - 1] == '*' and m == 0) return rec(a, b, m, n - 1);
    if (b[n - 1] == '*') return rec(a, b, m - 1, n) or rec(a, b, m, n - 1);
    if (m == 0 or n == 0) return false;
    if (a[m - 1] == b[n - 1]) return rec(a, b, m - 1, n - 1);
    if (b[n - 1] == '?') return rec(a, b, m - 1, n - 1);
    return false;
}

bool rec(string a, string b) {
    return rec(a, b, a.size(), b.size());
}

bool tab(string a, string b) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[i][j] = 1;
            else if (b[j - 1] == '*' and i == 0) dp[i][j] = dp[i][j - 1];
            else if (b[j - 1] == '*') dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
            else if (i == 0 or j == 0) dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else if (b[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 0;
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("baaabab", "**a*****ab") << endl; // 1
    cout << rec("baaabab", "baaa?ab") << endl; // 1
    cout << rec("baaabab", "ba*a?") << endl; // 1
    cout << rec("baaabab", "a*ab") << endl; // 0
    cout << rec("baaabab", "***?") << endl; // 1
    cout << endl;
    cout << tab("baaabab", "**a*****ab") << endl;
    cout << tab("baaabab", "baaa?ab") << endl;
    cout << tab("baaabab", "ba*a?") << endl;
    cout << tab("baaabab", "a*ab") << endl;
    cout << rec("baaabab", "***?") << endl;
}
