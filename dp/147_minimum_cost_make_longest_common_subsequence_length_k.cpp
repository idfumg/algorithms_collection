#include "../template.hpp"

int rec(string& s1, string& s2, int k, int m, int n) {
    if (k == 0) return 0;
    if (m == 0 or n == 0) return INF;
    int cost = (s1[m - 1] - 'a') ^ (s2[n - 1] - 'a');
    return min({rec(s1, s2, k, m - 1, n),
                rec(s1, s2, k, m, n - 1),
                rec(s1, s2, k - 1, m - 1, n - 1) + cost});
}

int rec(string& s1, string& s2, int k) {
    return rec(s1, s2, k, s1.size(), s2.size());
}

int tab(string& s1, string& s2, int K) {
    int m = s1.size(), n = s2.size();
    vvvi dp(K +1, vvi(m + 1, vi(n + 1, INF)));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k <= K; ++k) {
                if (k == 0) {
                    dp[k][i][j] = 0;
                }
                else {
                    int cost = (s1[i - 1] - 'a') ^ (s2[j - 1] - 'a');
                    dp[k][i][j] = min({dp[k][i - 1][j],
                                       dp[k][i][j - 1],
                                       dp[k - 1][i - 1][j - 1] + cost});
                }
            }
        }
    }
    return dp[K][m][n];
}

int main() { TimeMeasure _; __x();
    string s11 = "abble", s12 = "pie"; int k1 = 2;
    cout << rec(s11, s12, k1) << endl;
    cout << tab(s11, s12, k1) << endl;
}
