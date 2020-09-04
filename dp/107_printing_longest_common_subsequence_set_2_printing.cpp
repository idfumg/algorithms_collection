#include "../template.hpp"

set<string> rec(const string& s1, const string& s2, vvi& dp, int m, int n) {
    set<string> res;

    if (m == 0 or n == 0) {
        res.insert("");
        return res;
    }

    if (s1[m - 1] == s2[n - 1]) {
        const auto tmp = rec(s1, s2, dp, m - 1, n - 1);
        for (const auto& partial : tmp) res.insert(partial + s1[m - 1]);
    }
    else {
        if (dp[m - 1][n] == dp[m][n - 1]) {
            const auto tmp1 = rec(s1, s2, dp, m - 1, n);
            const auto tmp2 = rec(s1, s2, dp, m, n - 1);
            for (const auto& partial : tmp1) res.insert(partial);
            for (const auto& partial : tmp2) res.insert(partial);
        }
        else if (dp[m - 1][n] > dp[m][n - 1]) {
            const auto tmp1 = rec(s1, s2, dp, m - 1, n);
            for (const auto& partial : tmp1) res.insert(partial);
        }
        else {
            const auto tmp2 = rec(s1, s2, dp, m, n - 1);
            for (const auto& partial : tmp2) res.insert(partial);
        }
    }
    return res;
}

set<string> rec(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    const auto res = rec(s1, s2, dp, m, n);
    cout << "Longest size: " << res.begin()->size() << " => ";
    return res;
}

void get_elems(const string& a, vvvvi& prev, unordered_set<string>& res, vvi& elems, string& current, int n) {
    if (current.size() == n) {
        res.insert(current);
        return;
    }
    for (const auto& elem : elems) {
        if (elem[2] == 1) {
            current += a[elem[0]];
            get_elems(a, prev, res, prev[elem[0]][elem[1]], current, n);
            current.pop_back();
        }
        else {
            get_elems(a, prev, res, prev[elem[0]][elem[1]], current, n);
        }
    }
}

unordered_set<string> tab(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    vvvvi prev(m + 1, vvvi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                prev[i][j].push_back({i - 1, j - 1, 1});
            }
            else {
                if (dp[i - 1][j] == dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j].push_back({i - 1, j, 0});
                    prev[i][j].push_back({i, j - 1, 0});
                }
                else if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j].push_back({i - 1, j, 0});
                }
                else if (dp[i - 1][j] < dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                    prev[i][j].push_back({i, j - 1, 0});
                }
            }
        }
    }
    unordered_set<string> res;
    string current;
    get_elems(a, prev, res, prev[m][n], current, dp[m][n]);
    return res;
}

int main() { TimeMeasure _; __x();
    print(rec("AGTGATG", "GTTAG"));
    print(rec("AATCC", "ACACG"));
    print(rec("ABCBDAB", "BDCABA"));
    print(tab("AGTGATG", "GTTAG"));
    print(tab("AATCC", "ACACG"));
    print(tab("ABCBDAB", "BDCABA"));
}
