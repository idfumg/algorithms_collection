#include "../template.hpp"

bool tab1(const string& a, int k) { // lcs
    int m = a.size();
    string b(m, ' ');
    for (int i = 0; i < m; ++i) {
        b[i] = a[m - i - 1];
    }
    vvi dp(m + 1, vi(m + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return m - dp[m][m] <= k;
}

bool tab2(const string& a, int k) { // longest palindromic subsequence
    int n = a.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = 1;
            else if (a[i - 1] == a[j - 1]) dp[i][j] = 2 + dp[i + 1][j - 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return n - dp[1][n] <= k;
}

int main() { TimeMeasure _; __x();
    string s1 = "abcdecba"; int k1 = 1;
    string s2 = "abcdeca"; int k2 = 2;
    string s3 = "acdcb"; int k3 = 1;

    cout << tab1(s1, k1) << endl;
    cout << tab1(s2, k2) << endl;
    cout << tab1(s3, k3) << endl;
    cout << endl;
    cout << tab2(s1, k1) << endl;
    cout << tab2(s2, k2) << endl;
    cout << tab2(s3, k3) << endl;
}
