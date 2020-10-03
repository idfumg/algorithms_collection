#include "../template.hpp"

int rec_naive(vi& wines, int i, int j, int year) {
    if (i == j) return year * wines[i - 1];
    return max(rec_naive(wines, i + 1, j, year + 1) + wines[i - 1] * year,
               rec_naive(wines, i, j - 1, year + 1) + wines[j - 1] * year);
}

int rec_naive(vi& wines) {
    return rec_naive(wines, 1, wines.size(), 1);
}

int rec(vi& wines, int i, int j) {
    int n = wines.size(), year = n - (j - i);
    if (i == j) return year * wines[i - 1];
    return max(rec(wines, i + 1, j) + wines[i - 1] * year,
               rec(wines, i, j - 1) + wines[j - 1] * year);
}

int rec(vi& wines) {
    return rec(wines, 1, wines.size());
}

int tab_naive(vi& wines) {
    int n = wines.size();
    vvvi dp(n + 2, vvi(n + 2, vi(n + 2)));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = n; k >= 1; --k) {
                if (i > j) {
                    dp[i][j][k] = 0;
                }
                else if (i == j) {
                    dp[i][j][k] = wines[i - 1] * k;
                }
                else {
                    dp[i][j][k] = max(dp[i + 1][j][k + 1] + wines[i - 1] * k,
                                      dp[i][j - 1][k + 1] + wines[j - 1] * k);
                }
            }
        }
    }
    return dp[1][n][1];
}

int tab(vi& wines) {
    int n = wines.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            int year = n - (j - i);
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = year * wines[i - 1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j] + wines[i - 1] * year,
                               dp[i][j - 1] + wines[j - 1] * year);
            }
        }
    }
    return dp[1][n];
}

int tab_elems(vi& wines) {
    int n = wines.size();
    vvi dp(n + 1, vi(n + 1));
    vvvi prev(n + 1, vvi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            int year = n - (j - i);
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = year * wines[i - 1];
                prev[i][j] = {0, 0, i - 1};
            }
            else {
                int a = dp[i + 1][j] + wines[i - 1] * year;
                int b = dp[i][j - 1] + wines[j - 1] * year;
                if (a > b) {
                    dp[i][j] = a;
                    prev[i][j] = {i + 1, j, i - 1};
                }
                else {
                    dp[i][j] = b;
                    prev[i][j] = {i, j - 1, j - 1};
                }
            }
        }
    }
    vi elems;
    for (vi at = prev[1][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        elems.push_back(wines[at[2]]);
    }
    cout << elems << ':' << ' ';
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    vi wines = {2, 4, 6, 2, 5};
    cout << rec_naive(wines) << endl; // 64 // Straightforward algorithm
    cout << rec(wines) << endl; // 64 // Eliminate unnecessary params
    cout << tab_naive(wines) << endl; // 64 // Straightforward algorithm
    cout << tab(wines) << endl; // 64 // Eliminate unnecessary params
    cout << tab_elems(wines) << endl; // 64 // Print the order of  chosen elements
}
