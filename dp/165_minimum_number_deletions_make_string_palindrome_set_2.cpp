#include "../template.hpp"

int tab(const string& a) {
    string b = a;
    reverse(b);
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return n - dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << tab("baca") << endl; // 1
    cout << tab("geek") << endl; // 2
}
