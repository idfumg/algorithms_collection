#include "../../template.hpp"

int rec(const string& a, const string& b, int m, int n) {
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (a[m - 1] == b[n - 1]) {
        return rec(a, b, m - 1, n - 1) + rec(a, b, m - 1, n);
    }
    return rec(a, b, m - 1, n);
}

int rec(const string& a, const string& b) {
    return rec(a, b, a.size(), b.size());
}

int tab(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("banana", "ban") << endl; // 3
    cout << rec("geeksforgeeks", "ge") << endl; // 6
    cout << tab("banana", "ban") << endl; // 3
    cout << tab("geeksforgeeks", "ge") << endl; // 6
}
