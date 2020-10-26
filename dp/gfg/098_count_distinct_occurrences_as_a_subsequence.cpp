#include "../../template.hpp"

int rec(string s, string p, int m, int n) {
    if (n == 0) return 1;
    if (m == 0 or n == 0) return 0;
    if (s[m - 1] == p[n - 1]) {
        return rec(s, p, m - 1, n - 1) + rec(s, p, m - 1, n);
    }
    return rec(s, p, m - 1, n);
}

int rec(string s, string p) {
    int m = s.size(), n = p.size();
    return rec(s, p, m, n);
}

int tab(string s, string p) {
    int m = s.size(), n = p.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

int tab2(string s, string p) {
    int m = s.size(), n = p.size();
    int idx = 0;
    vvi dp(3, vi(n + 1));
    for (int i = 0; i <= 2; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        idx = i & 1;
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == p[j - 1]) {
                dp[idx][j] = dp[1 - idx][j - 1] + dp[1 - idx][j];
            }
            else {
                dp[idx][j] = dp[1 - idx][j];
            }
        }
    }
    return dp[idx][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("banana", "ban") << endl; // 3
    cout << rec("geeksforgeeks", "ge") << endl; // 6
    cout << '\n';
    cout << tab("banana", "ban") << endl; // 3
    cout << tab("geeksforgeeks", "ge") << endl; // 6
    cout << '\n';
    cout << tab2("banana", "ban") << endl; // 3
    cout << tab2("geeksforgeeks", "ge") << endl; // 6
}
