#include "../../template.hpp"

int rec(vi arr, int i, int j) {
    if (i > j) {
        return INF;
    }
    int mini = *min_element(arr.begin() + i - 1, arr.begin() + j);
    int maxi = *max_element(arr.begin() + i - 1, arr.begin() + j);
    if (2 * mini > maxi) {
        return 0;
    }
    return min(rec(arr, i + 1, j),
               rec(arr, i, j - 1)) + 1;
}

int rec(vi arr) {
    int n = arr.size();
    return rec(arr, 1, n);
}

int tab(vi arr) {
    int n = arr.size();

    vvi mini(n + 1, vi(n + 1, INF));
    vvi maxi(n + 1, vi(n + 1, -INF));

    for (int j = 1; j <= n; ++j) {
        mini[j][j] = arr[j - 1];
        maxi[j][j] = arr[j - 1];
    }

    for (int j = 2; j <= n; ++j) {
        mini[j - 1][j] = min(arr[j - 1], arr[j - 2]);
        maxi[j - 1][j] = max(arr[j - 1], arr[j - 2]);
    }

    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            mini[i][j] = min(arr[i - 1], mini[i + 1][j]);
            maxi[i][j] = max(arr[i - 1], maxi[i + 1][j]);
        }
    }

    vvi dp(n + 1, vi(n + 1, INF));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = INF;
            }
            else if (2 * mini[i][j] > maxi[i][j]) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 5, 100, 9, 10, 11, 12, 15, 200}; // 4
    vi arr2 = {4, 7, 5, 6}; // 0
    vi arr3 = {20, 7, 5, 6}; // 1
    vi arr4 = {20, 4, 1, 3}; // 3

    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << '\n';
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
}
