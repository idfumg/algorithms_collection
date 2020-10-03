#include "../template.hpp"

pair<vvi, vvi> GetMaxElements(vi& arr) {
    int n = arr.size();
    vvi mins(n, vi(n));
    vvi maxs(n, vi(n));
    for (int i = 0; i < n; ++i) {
        mins[i][i] = maxs[i][i] = arr[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        mins[i][i + 1] = min(arr[i], arr[i + 1]);
        maxs[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 0, j = i + k; j < n; ++i, ++j) {
            mins[i][j] = min(mins[i][j - 1], arr[j]);
            maxs[i][j] = max(maxs[i][j - 1], arr[j]);
        }
    }
    return {mins, maxs};
}

int rec(vi& arr, vvi& mins, vvi& maxs, int left, int right, int k) {
    if (left == right or mins[left][right] * 2 > maxs[left][right]) return k;
    return min(rec(arr, mins, maxs, left + 1, right, k + 1),
               rec(arr, mins, maxs, left, right - 1, k + 1));
}

int rec(vi& arr) {
    auto [mins, maxs] = GetMaxElements(arr);
    return rec(arr, mins, maxs, 0, arr.size() - 1, 0);
}

int tab(vi& arr) {
    int n = arr.size();
    auto [mins, maxs] = GetMaxElements(arr);
    vvi dp(n, vi(n));
    for (int i = n; i >= 0; --i) {
        for (int j = 1; j < n; ++j) {
            if (i <= j) {
                if (mins[i][j] * 2 <= maxs[i][j]) {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
    }
    return dp[0][n - 1];
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
