#include "../template.hpp"

int SumOfDigits(const string& s, int from, int count) {
    int res = 0;
    for (int i = from; i < from + count; ++i) {
        res += s[i] - '0';
    }
    return res;
}

int rec(const string& a, const string& b, int m, int n) { // naive
    if (m == 0 and n != 0) return SumOfDigits(b, 0, n);
    if (n == 0 and m != 0) return SumOfDigits(a, 0, m);
    if (m == 0 and n == 0) return 0;
    if (a[m - 1] == b[n - 1]) return rec(a, b, m - 1, n - 1);
    return min({rec(a, b, m - 1, n) + (a[m - 1] - '0'),
                rec(a, b, m, n - 1) + (b[n - 1] - '0')});
}

int rec(const string& a, const string& b) {
    return rec(a, b, a.size(), b.size());
}

int tab1(const string& a, const string& b) { // we can print exact elems here
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = SumOfDigits(a, 0, i);
    }
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = SumOfDigits(b, 0, j);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = min({a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] : INF,
                            dp[i - 1][j] + a[i - 1] - '0',
                            dp[i][j - 1] + b[j - 1] - '0'});
        }
    }
    return dp[m][n];
}

int tab2(const string& a, const string& b) { // we can just find answer fast here
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1, INF));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 or j == 0) {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] - '0') * 2;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int total = 0;
    for (int i = 0; i < m; ++i) total += a[i] - '0';
    for (int i = 0; i < n; ++i) total += b[i] - '0';
    return total - dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("3759", "9350") << endl; // 23
    cout << rec("3198", "98") << endl; // 4
    cout << '\n';
    cout << tab1("3759", "9350") << endl; // 23
    cout << tab1("3198", "98") << endl; // 4
    cout << '\n';
    cout << tab2("3759", "9350") << endl; // 23
    cout << tab2("3198", "98") << endl; // 4
}
