#include "../template.hpp"

int rec(const string& s, int i, int j, int total) {
    if (i > j) {
        return total;
    }
    if (i == j) {
        return total + 1;
    }
    if (s[i] == s[j]) {
        int res = rec(s, i + 1, j - 1, total + 2);
        return max({res, rec(s, i + 1, j, 0), rec(s, i, j - 1, 0)});
    }
    return max({total, rec(s, i + 1, j, 0), rec(s, i, j - 1, 0)});
}

int rec(const string& s) {
    return rec(s, 0, s.size() - 1, 0);
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n, vi(n));
    int maxi = -INF;

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if (maxi < dp[i][i]) maxi = dp[i][i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 2;
            if (maxi < dp[i][i + 1]) maxi = dp[i][i + 1];
        }
    }

    for (int k = 2; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            int j = i + k;
            if (j < n && s[i] == s[j] && dp[i + 1][j - 1] != 0) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                if (maxi < dp[i][j]) maxi = dp[i][j];
            }
        }
    }

    return maxi;
}

int main() { TimeMeasure _; __x();
    static const string s1 = "aaaabbaa"; // 6
    static const string s2 = "banana"; // 5
    static const string s3 = "forgeeksskeegfor"; // geeksskeeg // 10
    static const string s4 = "Geeks"; // geeksskeeg // 2

    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << rec(s3) << endl;
    cout << rec(s4) << endl;
    cout << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
    cout << tab(s4) << endl;
}
