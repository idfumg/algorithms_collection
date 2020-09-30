#include "../template.hpp"

int tab_count(const string& a, const string& b, int K) {
    int m = a.size(), n = b.size();
    vvi count(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                count[i][j] = count[i - 1][j - 1] + 1;
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

int tab(const string& a, const string& b, int K) {
    int m = a.size(), n = b.size();
    vvi count(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                count[i][j] = count[i - 1][j - 1] + 1;
            }
        }
    }
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (count[i][j] >= K) {
                int k = count[i][j];
                dp[i][j] = max(dp[i][j], dp[i - k][j - k] + k);
                // for (int k = K; k <= count[i][j]; ++k) {
                //     dp[i][j] = max(dp[i][j], dp[i - k][j - k] + k);
                // }
            }
        }
    }
    return dp[m][n];
}

int tab_str(const string& a, const string& b, int K) {
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
    vvvi prev(m + 1, vvi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                prev[i][j] = {i - 1, j, 0};
                dp[i][j] = dp[i - 1][j];
            }
            else {
                prev[i][j] = {i, j - 1, 0};
                dp[i][j] = dp[i][j - 1];
            }
            if (count[i][j] >= K) {
                int len = count[i][j];
                if (dp[i][j] < len + dp[i - len][j - len]) {
                    dp[i][j] = len + dp[i - len][j - len];
                    prev[i][j] = {i - len, j - len, len};
                }
            }

        }
    }
    string s;
    for (vi at = prev[m][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] != 0) {
            int len = at[2];
            for (int i = at[0] + len - 1; i >= at[0]; --i) {
                s += a[i];
            }
            s += ' ';
        }
    }
    reverse(s);
    cout << s << '\n';
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
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
