#include "../../template.hpp"

int Count(string a, string b, int m, int n, int total) {
    if (m == 0 or n == 0) {
        return total;
    }
    if (a[m - 1] != b[n - 1]) {
        return total;
    }
    return Count(a, b, m - 1, n - 1, total + 1);
}

int Count(string a, string b, int m, int n) {
    return Count(a, b, m, n, 0);
}

int rec(string a, string b, int k, int m, int n, int total) {
    if (m <= 0 or n <= 0) {
        return total;
    }
    if (a[m - 1] == b[n - 1]) {
        int count = Count(a, b, m , n);
        if (count >= k) {
            return rec(a, b, k, m - count, n - count, total + count);
        }
    }
    return max(rec(a, b, k, m - 1, n, total),
               rec(a, b, k, m, n - 1, total));
}

int rec(string a, string b, int k) {
    int m = a.size(), n = b.size();
    return rec(a, b, k, m, n, 0);
}

int rec2(string a, string b, int k, int m, int n) {
    if (m <= 0 or n <= 0) {
        return 0;
    }
    int count = Count(a, b, m , n);
    if (a[m - 1] == b[n - 1] and count >= k) {
        return rec2(a, b, k, m - count, n - count) + count;
    }
    return max(rec2(a, b, k, m - 1, n),
               rec2(a, b, k, m, n - 1));
}

int rec2(string a, string b, int k) {
    int m = a.size(), n = b.size();
    return rec2(a, b, k, m, n);
}

int tab(string a, string b, int k) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int count = Count(a, b, i, j);
            if (a[i - 1] == b[j - 1] and count >= k) {
                dp[i][j] = max({dp[i - count][j - count] + count, dp[i - 1][j], dp[i][j - 1]});
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int tab_precount(string a, string b, int k) {
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
            if (a[i - 1] == b[j - 1] and count[i][j] >= k) {
                dp[i][j] = max({dp[i - count[i][j]][j - count[i][j]] + count[i][j], dp[i - 1][j], dp[i][j - 1]});
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int tab_str(string a, string b, int k) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    vvvi prev(m + 1, vvi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int count = Count(a, b, i, j);
            if (a[i - 1] == b[j - 1] and count >= k) {
                dp[i][j] = max({dp[i - count][j - count] + count, dp[i - 1][j], dp[i][j - 1]});
                prev[i][j] = {i - count, j - count, count};
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
    string res;
    for (vi at = prev[m][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2]) {
            res = a.substr(at[0], at[2]) + ' ' + res;
        }
    }
    debugn(res);
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("aacb", "aab", 2) << endl; // 2
    cout << rec("aacbb", "aabb", 2) << endl; // 4
    cout << rec("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 8
    cout << rec("aggasdfa", "aggajasdfaxy", 5) << endl; // 5
    cout << rec("aabcaaaa", "baaabcd", 3) << endl; // 4
    cout << rec("aabcaaaakkk", "baaabcdkkk", 3) << endl; // 7
    cout << endl;
    cout << rec2("aacb", "aab", 2) << endl; // 2
    cout << rec2("aacbb", "aabb", 2) << endl; // 4
    cout << rec2("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 8
    cout << rec2("aggasdfa", "aggajasdfaxy", 5) << endl; // 5
    cout << rec2("aabcaaaa", "baaabcd", 3) << endl; // 4
    cout << rec2("aabcaaaakkk", "baaabcdkkk", 3) << endl; // 7
    cout << endl;
    cout << tab("aacb", "aab", 2) << endl; // 2
    cout << tab("aacbb", "aabb", 2) << endl; // 4
    cout << tab("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 8
    cout << tab("aggasdfa", "aggajasdfaxy", 5) << endl; // 5
    cout << tab("aabcaaaa", "baaabcd", 3) << endl; // 4
    cout << tab("aabcaaaakkk", "baaabcdkkk", 3) << endl; // 7
    cout << endl;
    cout << tab_precount("aacb", "aab", 2) << endl; // 2
    cout << tab_precount("aacbb", "aabb", 2) << endl; // 4
    cout << tab_precount("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // 8
    cout << tab_precount("aggasdfa", "aggajasdfaxy", 5) << endl; // 5
    cout << tab_precount("aabcaaaa", "baaabcd", 3) << endl; // 4
    cout << tab_precount("aabcaaaakkk", "baaabcdkkk", 3) << endl; // 7
    cout << endl;
    cout << tab_str("aacb", "aab", 2) << endl; // 2
    cout << tab_str("aacbb", "aabb", 2) << endl; // aa bb
    cout << tab_str("aggayxysdfa", "aggajxaaasdfa", 4) << endl; // agga sdfa
    cout << tab_str("aggasdfa", "aggajasdfaxy", 5) << endl; // asdfa
    cout << tab_str("aabcaaaa", "baaabcd", 3) << endl; // aabc
    cout << tab_str("aabcaaaakkk", "baaabcdkkk", 3) << endl; // aabc kkk
}
