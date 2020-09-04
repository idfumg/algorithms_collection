#include "../template.hpp"

int rec(vi& wines, int year, int left, int right) {
    if (left > right) return 0;
    return max(rec(wines, year + 1, left + 1, right) + wines[left] * year,
               rec(wines, year + 1, left, right - 1) + wines[right] * year);
}

int rec(vi& wines) {
    return rec(wines, 1, 0, wines.size() - 1);
}

int tab(vi& wines) {
    int n = wines.size();
    vvvi dp(n + 2, vvi(n + 2, vi(n + 1)));
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            for (int k = 1; k <= n; ++k) {
                if (j == k) {
                    dp[i][j][k] = wines[j - 1] * i;
                }
                else {
                    dp[i][j][k] = max(
                        dp[i + 1][j + 1][k] + wines[j - 1] * i,
                        dp[i + 1][j][k - 1] + wines[k - 1] * i);
                }
            }
        }
    }
    return dp[1][1][n];
}

int tab2(vi& arr) {
    int n = arr.size();
    vvi dp(n + 2, vi(n + 2));
    vvvi prev(n + 2, vvi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            int years = (i + n - j);
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = arr[i - 1] * years;
                prev[i][j] = {0, i - 1, i - 1};
            }
            else {
                if (dp[i + 1][j] + arr[i - 1] * years >
                    dp[i][j - 1] + arr[j - 1] * years) {
                    prev[i][j] = {i + 1, j, i - 1};
                }
                else {
                    prev[i][j] = {i, j - 1, j - 1};
                }
                dp[i][j] = max(dp[i + 1][j] + arr[i - 1] * years,
                               dp[i][j - 1] + arr[j - 1] * years);
            }
        }
    }
    vi res;
    for (vi at = prev[1][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        res.push_back(arr[at[2]]);
    }
    cout << res << endl;
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    vi wines = {2, 4, 6, 2, 5};
    cout << rec(wines) << endl;
    cout << tab(wines) << endl;
    cout << tab2(wines) << endl;
}
