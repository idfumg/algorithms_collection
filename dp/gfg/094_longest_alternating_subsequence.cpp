#include "../../template.hpp"

int rec(vi arr, int i, int prev, bool isincr) {
    int n = arr.size();
    if (i == n) {
        return 0;
    }
    if (isincr and arr[i] > arr[prev]) {
        return max(1 + rec(arr, i + 1, i, false), rec(arr, i + 1, prev, isincr));
    }
    else if (not isincr and arr[i] < arr[prev]) {
        return max(1 + rec(arr, i + 1, i, true), rec(arr, i + 1, prev, isincr));
    }
    return rec(arr, i + 1, prev, isincr);
}

int rec(vi arr) {
    return max(rec(arr, 1, 0, false), rec(arr, 1, 0, true)) + 1;
}

int tab(vi arr) {
    int n = arr.size();
    vvvi dp(n + 2, vvi(n + 2, vi(2)));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            for (int k : {0, 1}) {
                if (i == n) {
                    dp[i][j][k] = 0;
                }
                else if (k == 1 and arr[i] > arr[j]) {
                    dp[i][j][k] = max(1 + dp[i + 1][i][0], dp[i + 1][j][1]);
                }
                else if (k == 0 and arr[i] < arr[j]) {
                    dp[i][j][k] = max(1 + dp[i + 1][i][1], dp[i + 1][j][0]);
                }
                else {
                    dp[i][j][k] = dp[i + 1][j][k];
                }
            }
        }
    }
    return 1 + max(dp[1][0][0], dp[1][0][1]);
}

int rec2(vi arr, int n, int prev, int down) {
    if (n == 0) return 0;
    if (down) {
        if (arr[n - 1] < arr[prev - 1]) {
            return max(rec2(arr, n - 1, n, !down) + 1, rec2(arr, n - 1, prev, down));
        }
        else {
            return rec2(arr, n - 1, prev, down);
        }
    }
    if (arr[n - 1] > arr[prev - 1]) {
        return max(rec2(arr, n - 1, n, !down) + 1, rec2(arr, n - 1, prev, down));
    }
    else {
        return rec2(arr, n - 1, prev, down);
    }
}

int rec2(vi arr) {
    return max(rec2(arr, arr.size() - 1, arr.size(), 0), rec2(arr, arr.size() - 1, arr.size(), 1)) + 1;
}

int tab2(vi arr) {
    int n = arr.size();
    vvvi dp(n + 1, vvi(n + 1, vi(2)));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k : {0, 1}) {
                if (k) {
                    if (arr[i - 1] < arr[j - 1]) dp[i][j][k] = max(dp[i - 1][i][!k] + 1, dp[i - 1][j][k]);
                    else dp[i][j][k] = dp[i - 1][j][k];
                }
                else {
                    if (arr[i - 1] > arr[j - 1]) dp[i][j][k] = max(dp[i - 1][i][!k] + 1, dp[i - 1][j][k]);
                    else dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
    }
    return max(dp[n - 1][n][0], dp[n - 1][n][1]) + 1;
}


int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 4};
    vi arr2 = {1, 4, 5};
    vi arr3 = {10, 22, 9, 33, 49, 50, 31, 60};
    vi arr4 = {10, 22, 9, 33, 49, 50, 31, 60, 100, 1000};
    vi arr5 = {8, 2, 3, 5, 7, 9, 10};

    cout << rec(arr1) << endl; // 3
    cout << rec(arr2) << endl; // 2
    cout << rec(arr3) << endl; // 6
    cout << rec(arr4) << endl; // 6
    cout << rec(arr5) << endl; // 3
    cout << '\n';
    cout << tab(arr1) << endl; // 3
    cout << tab(arr2) << endl; // 2
    cout << tab(arr3) << endl; // 6
    cout << tab(arr4) << endl; // 6
    cout << tab(arr5) << endl; // 3
    cout << '\n';
    cout << rec2(arr1) << endl; // 3
    cout << rec2(arr2) << endl; // 2
    cout << rec2(arr3) << endl; // 6
    cout << rec2(arr4) << endl; // 6
    cout << rec2(arr5) << endl; // 3
    cout << '\n';
    cout << tab2(arr1) << endl; // 3
    cout << tab2(arr2) << endl; // 2
    cout << tab2(arr3) << endl; // 6
    cout << tab2(arr4) << endl; // 6
    cout << tab2(arr5) << endl; // 3
}
