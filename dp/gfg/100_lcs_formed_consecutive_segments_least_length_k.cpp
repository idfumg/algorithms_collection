#include "../../template.hpp"

int rec_count(const string& a, const string& b, int k, int m, int n, int current) {
    if (m == 0 or n == 0) return current >= k ? 1 : 0;
    if (a[m - 1] == b[n - 1]) {
        return rec_count(a, b, k, m - 1, n - 1, current + 1);
    }
    return (current >= k ? 1 : 0) + max(rec_count(a, b, k, m - 1, n, 0),
                                        rec_count(a, b, k, m, n - 1, 0));
}

// Straightforward algorithm for total count such of lcs substrings
int rec_count(const string& a, const string& b, int k) {
    return rec_count(a, b, k, a.size(), b.size(), 0);
}

int rec(const string& a, const string& b, int k, int m, int n, int current) {
    if (m == 0 or n == 0) return current >= k ? current : 0;
    if (a[m - 1] == b[n - 1]) {
        return rec(a, b, k, m - 1, n - 1, current + 1);
    }
    return (current >= k ? current : 0) + max(rec(a, b, k, m - 1, n, 0),
                                              rec(a, b, k, m, n - 1, 0));
}

// Straightforward algorithm for total size of such lcs substrings
int rec(const string& a, const string& b, int k) {
    return rec(a, b, k, a.size(), b.size(), 0);
}

// Straightforward iterative algorithm for total count such of lcs substrings
int tab_count(const string& a, const string& b, int K) {
    int m = a.size(), n = b.size(), p = min(m, n);
    vvi count(m + 2, vi(n + 2));
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
            if (a[i - 1] == b[j - 1] and
                count[i][j] >= K and
                count[i + 1][j + 1] == 0)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// Straightforward iterative algorithm for total size of such lcs substrings
int tab(const string& a, const string& b, int K) {
    int m = a.size(), n = b.size(), p = min(m, n);
    vvi count(m + 2, vi(n + 2));
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
            if (a[i - 1] == b[j - 1] and
                count[i][j] >= K and
                count[i + 1][j + 1] == 0)
            {
                    dp[i][j] = count[i][j] + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// Straightforward iterative algorithm for printing such lcs substrings
int tab_str(const string& a, const string& b, int K) {
    int m = a.size(), n = b.size(), p = min(m, n);
    vvi count(m + 2, vi(n + 2));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                count[i][j] = 1 + count[i - 1][j - 1];
            }
        }
    }
    vvi dp(m + 1, vi(n + 1));
    vvvi prev(m + 1, vvi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1] and
                count[i][j] >= K and
                count[i + 1][j + 1] == 0)
            {
                    dp[i][j] = count[i][j] + dp[i - 1][j - 1];
                    prev[i][j] = {i - 1, j - 1, count[i][j]};
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (dp[i][j] == dp[i - 1][j]) {
                    prev[i][j] = {i - 1, j, 0};
                }
                else {
                    prev[i][j] = {i, j - 1, 0};
                }
            }
        }
    }
    string res;
    for (vi at = prev[m][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        int len = at[2];
        if (len > 0) {
            for (int i = at[0]; i > at[0] - len; --i) {
                res += a[i];
            }
            res += ' ';
        }
    }
    res.pop_back();
    reverse(res);
    cout << res << '\n';
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec_count("aacbb", "aabb", 2) << endl; // 2
    cout << rec_count("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 2
    cout << rec_count("aggasdfa", "aggajasdfaxy", 5) << endl; // 1
    cout << rec_count("aabcaaaa", "baaabcd", 3) << endl; // 1
    cout << endl;
    cout << rec("aacbb", "aabb", 2) << endl; // 4
    cout << rec("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 8
    cout << rec("aggasdfa", "aggajasdfaxy", 5) << endl; // 5
    cout << rec("aabcaaaa", "baaabcd", 3) << endl; // 4
    cout << endl;
    cout << tab_count("aacbb", "aabb", 2) << endl; // 2
    cout << tab_count("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 2
    cout << tab_count("aggasdfa", "aggajasdfaxy", 5) << endl; // 1
    cout << tab_count("aabcaaaa", "baaabcd", 3) << endl; // 2
    cout << endl;
    cout << tab("aacbb", "aabb", 2) << endl; // 4
    cout << tab("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 8
    cout << tab("aggasdfa", "aggajasdfaxy", 5) << endl; // 5
    cout << tab("aabcaaaa", "baaabcd", 3) << endl; // 4
    cout << endl;
    cout << tab_str("aacbb", "aabb", 2) << endl; // aa bb
    cout << tab_str("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // agga sdfa
    cout << tab_str("aggasdfa", "aggajasdfaxy", 5) << endl; // asdfa
    cout << tab_str("aabcaaaa", "baaabcd", 3) << endl; // aabc
}
