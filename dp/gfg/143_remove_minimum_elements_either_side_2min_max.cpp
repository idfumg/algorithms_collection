#include "../../template.hpp"

int rec(vi arr, int i, int j) {
    if (i >= j) return 0;
    int mini = *min_element(arr.begin() + i, arr.begin() + j + 1);
    int maxi = *max_element(arr.begin() + i, arr.begin() + j + 1);
    if (2 * mini > maxi) return 0;
    return min(rec(arr, i + 1, j), rec(arr, i, j - 1)) + 1;
}

int rec(vi arr) {
    return rec(arr, 0, arr.size() - 1);
}

int tab(vi arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j) {
                dp[i][j] = 0;
            }
            else {
                int mini = *min_element(arr.begin() + i, arr.begin() + j + 1);
                int maxi = *max_element(arr.begin() + i, arr.begin() + j + 1);
                if (2 * mini > maxi) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int tab2(vi arr) {
    int n = arr.size();
    vvi mins(n + 2, vi(n + 1));
    vvi maxs(n + 2, vi(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i > j) {
                mins[i][j] = INF;
            }
            else if (i == j) {
                mins[i][j] = arr[i];
            }
            else if (j - i == 1) {
                mins[i][j] = min(arr[i], arr[j]);
                maxs[i][j] = max(arr[i], arr[j]);
            }
            else {
                mins[i][j] = min(arr[i], mins[i + 1][j]);
                maxs[i][j] = max(arr[i], maxs[i + 1][j]);
            }
        }
    }

    vvi dp(n + 2, vi(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j) {
                dp[i][j] = 0;
            }
            else {
                if (2 * mins[i][j] > maxs[i][j]) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() { // TimeMeasure _; __x();
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
    cout << '\n';
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
    cout << tab2(arr3) << endl;
    cout << tab2(arr4) << endl;
}
