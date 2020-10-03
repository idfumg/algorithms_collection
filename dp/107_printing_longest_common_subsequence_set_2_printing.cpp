#include "../template.hpp"

set<string> rec(vvi& dp, const string& a, const string& b, int m, int n) {
    set<string> res;

    if (m == 0 or n == 0) {
        return {""};
    }

    if (a[m - 1] == b[n - 1]) {
        const set<string> paths = rec(dp, a, b, m - 1, n - 1);
        for (const auto& path : paths) res.insert(path + a[m - 1]);
    }
    else if (dp[m - 1][n] > dp[m][n - 1]) {
        const set<string> paths = rec(dp, a, b, m - 1, n);
        for (const auto& path : paths) res.insert(path);
    }
    else if (dp[m - 1][n] < dp[m][n - 1]) {
        const set<string> paths = rec(dp, a, b, m, n - 1);
        for (const auto& path : paths) res.insert(path);
    }
    else {
        const set<string> pathsm = rec(dp, a, b, m - 1, n);
        const set<string> pathsn = rec(dp, a, b, m, n - 1);
        for (const auto& path : pathsm) res.insert(path);
        for (const auto& path : pathsn) res.insert(path);
    }

    return res;
}

void rec(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << rec(dp, a, b, m, n) << '\n';
}

void GetElems(const string& a, set<string>& res, vvvvi& prev, vvi& paths, string& current) {
    if (paths.empty()) {
        string temp = current;
        reverse(temp);
        res.insert(temp);
        return;
    }
    for (const auto& path : paths) {
        if (path[2] == 1) {
            current.push_back(a[path[0]]);
            GetElems(a, res, prev, prev[path[0]][path[1]], current);
            current.pop_back();
        }
        else {
            GetElems(a, res, prev, prev[path[0]][path[1]], current);
        }
    }
}

void GetElems(const string& a, set<string>& res, vvvvi& prev) {
    int m = prev.size() - 1, n = prev[0].size() - 1;
    string current;
    GetElems(a, res, prev, prev[m][n], current);
}

void tab(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    vvvvi prev(m + 1, vvvi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                prev[i][j].push_back({i - 1, j - 1, 1});
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                prev[i][j].push_back({i - 1, j, 0});
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                prev[i][j].push_back({i, j - 1, 0});
            }
            else {
                dp[i][j] = dp[i - 1][j];
                prev[i][j].push_back({i - 1, j, 0});
                prev[i][j].push_back({i, j - 1, 0});
            }
        }
    }

    set<string> res;
    GetElems(a, res, prev);
    cout << res << '\n';
}

int main() { TimeMeasure _; __x();
    rec("AGTGATG", "GTTAG"); // 4
    rec("AATCC", "ACACG"); // 3
    rec("ABCBDAB", "BDCABA"); // 4
    cout << '\n';
    tab("AGTGATG", "GTTAG");
    tab("AATCC", "ACACG");
    tab("ABCBDAB", "BDCABA");
}
