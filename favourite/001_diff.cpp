#include "../template.hpp"

static void PrintDiff(const string& a, const string& b) noexcept {
    const int m = size(a), n = size(b);
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res(max(m + 1, n + 1) * 3 + 3, ' ');
    int pos = res.size() - 3;
    for (int i = m, j = n; i >= 1 and j >= 1;) {
        if (a[i - 1] == b[j - 1]) {
            res[pos] = ' ';
            res[pos + 1] = ' ';
            res[pos + 2] = a[i - 1];
            pos -= 3;
            i -= 1;
            j -= 1;
        }
        else if (dp[i][j - 1] >= dp[i - 1][j]) {
            res[pos] = ' ';
            res[pos + 1] = '+';
            res[pos + 2] = b[j - 1];
            pos -= 3;
            j -= 1;
        }
        else {
            res[pos] = ' ';
            res[pos + 1] = '-';
            res[pos + 2] = a[i - 1];
            pos -= 3;
            i -= 1;
        }
    }
    cout << res << endl;
}

int main() { TimeMeasure _; __x();
    PrintDiff("ABCDFGHJQZ",
              "ABCDEFGIJKRXYZ");
    PrintDiff("XMJYAUZ",
              "XMJAATZ");
}
