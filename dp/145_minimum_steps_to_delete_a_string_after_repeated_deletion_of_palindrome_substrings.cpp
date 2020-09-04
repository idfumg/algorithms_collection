#include "../../template.hpp"

int tab1(const string& s) {
    int n = s.size();
    vvi dp(n, vi(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
        else {
            dp[i][i + 1] = 2;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 0, j = i + k; j < n; ++i, ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
            for (int p = i; p < j; ++p) {
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() { TimeMeasure _; __x();
    string s1 = "2553432";
    string s2 = "1234";
    string s3 = "85162566503856128680172737224361087222672066466435241335835361347840217282628340745876270884027722522328301315188686114874";
    string s4 = "237878137523660217782577430602023628512162227326873042583534544816746753873";

    cout << tab1(s1) << endl;
    cout << tab1(s2) << endl;
    cout << tab1(s3) << endl;
    cout << tab1(s4) << endl;
}
