#include "../../template.hpp"

int tab(const vi& arr, const int K = 1) {
    int n = arr.size(), maxi = 0;
    pi maxipos{};
    vvi dp(K + 2, vi(n + 1, -INF));
    vvvi prev(K + 2, vvi(n + 1));
    for (int k = 1; k <= K + 1; ++k) {
        for (int i = 1; i <= n; ++i) {
            dp[k][i] = max({dp[k][i - 1] + arr[i - 1],
                            dp[k - 1][i - 1],
                            arr[i - 1]});
            if (maxi < dp[k][i]) {
                maxi = max(maxi, dp[k][i]);
                maxipos = {k, i};
            }
            if (dp[k][i] == dp[k][i - 1] + arr[i - 1]) {
                prev[k][i] = {k, i - 1, 1};
            }
            else if (dp[k][i] == dp[k - 1][i - 1]) {
                prev[k][i] = {k - 1, i - 1, 0};
            }
            else if (dp[k][i] == arr[i - 1]) {
                prev[k][i] = {0, i - 1, 2};
            }
        }
    }
    vi elems;
    for (vi at = prev[maxipos.first][maxipos.second]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == 1 or at[2] == 2) {
            elems.push_back(arr[at[1]]);
        }
    }
    reverse(elems);
    cout << elems << endl;
    return maxi;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3, -4, 5}; // 11
    vi arr2 = {-2, -3, 4, -1, -2, 1, 5, -3}; // 9
    print(tab(arr1));
    print(tab(arr2));
}
