#include "../../template.hpp"

int edit_distance(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

bool tab1(string& s1, int k) {
    string s2 = s1; reverse(s2);
    return edit_distance(s1, s2) <= 2 * k;
}

bool tab2(string& s, int k) {
    int n = s.size();
    vvi dp(n, vi(n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return n - dp[0][n - 1] <= k;
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
