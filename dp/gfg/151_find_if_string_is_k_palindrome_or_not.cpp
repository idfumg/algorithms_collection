#include "../../template.hpp"

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

bool tab3(string s, int K) { // How many charachater we should delete from 1..n
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));

    for (int i = 2; i <= n; ++i) {
        if (s[i - 2] != s[i - 1]) {
            dp[i - 1][i] = 1;
        }
    }

    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[1][n] <= K;
}

bool tab4(string s, int K) {  // longest palindromic subsequence 2
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] == s[i - 2]) {
            dp[i - 1][i] = 2;
        }
        else {
            dp[i - 1][i] = 1;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return n - dp[1][n] <= K;
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
    cout << endl;
    cout << tab3(s1, k1) << endl;
    cout << tab3(s2, k2) << endl;
    cout << tab3(s3, k3) << endl;
    cout << endl;
    cout << tab4(s1, k1) << endl;
    cout << tab4(s2, k2) << endl;
    cout << tab4(s3, k3) << endl;
}
