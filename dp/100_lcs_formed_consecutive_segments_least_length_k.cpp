#include "../../template.hpp"

int lcs(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// how many such common subsequences that they are
// consist of parts which are consecutive and of length >= K
int tab_count(const string& a, const string& b, const int K) {
    int m = a.size(), n = b.size();
    vvi count(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                count[i][j] = 1 + count[i - 1][j - 1];
            }
        }
    }
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1] and count[i][j] >= K) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// the longest common subsequence that it
// consists of parts which are consecutive and of length >= K
int tab(const string& a, const string& b, const int K) {
    int m = a.size(), n = b.size(), maxlen = 0;
    vvi count(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                count[i][j] = 1 + count[i - 1][j - 1];
            }
            maxlen = max(maxlen, count[i][j]);
        }
    }
    if (maxlen < K) {
        return -1;
    }
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1] and count[i][j] == maxlen) {
                dp[i][j] = maxlen + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// find exact values of the problem
string tab_str(const string& a, const string& b, const int K) {
    int m = a.size(), n = b.size(), maxlen = 0;
    vvi count(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                count[i][j] = 1 + count[i - 1][j - 1];
            }
            maxlen = max(maxlen, count[i][j]);
        }
    }
    if (maxlen < K) {
        return {};
    }
    vvi dp(m + 1, vi(n + 1));
    vvvi prev(m + 1, vvi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1] and count[i][j] == maxlen) {
                dp[i][j] = maxlen + dp[i - 1][j - 1];
                prev[i][j] = {i - 1, j - 1, 1};
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j] = {i - 1, j, 0};
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    prev[i][j] = {i, j - 1, 0};
                }
            }
        }
    }
    string res(dp[m][n], ' ');
    int pos = res.size() - 1;
    for (vi at = prev[m][n]; pos >= 0 and not at.empty();at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            for (int i = 0; i < maxlen; ++i) {
                res[pos--] = a[at[0] - i];
            }
        }
    }
    return res;
}

int main() { TimeMeasure _; __x();
    cout << lcs("abcde", "bcd") << endl;
    cout << lcs("aggayxysdfa", "aggajxaaasdfa") << endl;
    cout << endl;
    cout << tab_count("aacbb", "aabb", 2) << endl;
    cout << tab_count("aggayxysdfa", "aggajxaaasdfa", 4) << endl;
    cout << tab_count("aggasdfa", "aggajasdfaxy", 5) << endl;
    cout << tab_count("aabcaaaa", "baaabcd", 3) << endl;
    cout << endl;
    cout << tab("aacbb", "aabb", 2) << endl; // 4
    cout << tab("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 8
    cout << tab("aggasdfa", "aggajasdfaxy", 5) << endl; // 5
    cout << tab("aabcaaaa", "baaabcd", 3) << endl; // 4
    cout << endl;
    cout << tab_str("aacbb", "aabb", 2) << endl; // aabb
    cout << tab_str("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // aggasdfa
    cout << tab_str("aggasdfa", "aggajasdfaxy", 5) << endl; // asdfa
    cout << tab_str("aabcaaaa", "baaabcd", 3) << endl; // aabc
}
