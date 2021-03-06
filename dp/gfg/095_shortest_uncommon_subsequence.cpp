#include "../../template.hpp"

set<string> GenSubsets(string s) {
    int m = s.size();
    set<string> as;
    for (int i = 0; i < (1 << m); ++i) {
        string elems;
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                elems += s[j];
            }
        }
        as.insert(elems);
    }
    return as;
}

int brute(string a, string b) {
    set<string> as = GenSubsets(a);
    set<string> bs = GenSubsets(b);

    int mini = INF;
    for (const auto& elems : as) {
        if (not bs.count(elems) and elems.size() < mini) {
            mini = elems.size();
        }
    }
    return mini == INF ? -1 : mini;
}

int rec(const string& s1, const string& s2, const int n1, const int n2) {
    if (n1 == 0) return INF;
    if (n2 == 0) return 1;

    int k = n2;
    for (; k > 0; --k) {
        if (s2[k - 1] == s1[n1 - 1]) {
            break;
        }
    }
    if (k == 0) return 1;

    return min(rec(s1, s2, n1 - 1, n2),
               1 + rec(s1, s2, n1 - 1, k - 1));
}

int rec(const string& s1, const string& s2) {
    const auto res = rec(s1, s2, s1.size(), s2.size());
    return res == INF ? -1 : res;
}

int tab(const string& s1, const string& s2) {
    const int m = s1.size();
    const int n = s2.size();
    vvi dp(m + 1, vi(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = INF;
            }
            else if (j == 0) {
                dp[i][j] = 1;
            }
            else {
                int k = j;
                for (; k > 0; --k) {
                    if (s2[k - 1] == s1[i - 1]) {
                        break;
                    }
                }
                if (k == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][k - 1]);
                }
            }
        }
    }
    return dp[m][n] == INF ? -1 : dp[m][n];
}

int main() { TimeMeasure _; __x();
    static const string s11 = "babab", s12 = "babba";
    static const string s21 = "abb", s22 = "abab";
    cout << brute(s11, s12) << endl;
    cout << brute(s21, s22) << endl;
    cout << rec(s11, s12) << endl;
    cout << rec(s21, s22) << endl;
    cout << tab(s11, s12) << endl;
    cout << tab(s21, s22) << endl;
}
