#include "../../template.hpp"

int naive(vi arr) {
    int n = arr.size();
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        vi elems;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                elems.push_back(arr[j]);
            }
        }
        if (is_sorted(elems.begin(), elems.end())) {
            ++ans;
        }
    }
    return ans;
}

int rec(vi arr, int n, int prev) {
    if (n == 0) return 1;
    if (arr[n - 1] > arr[prev - 1]) return rec(arr, n - 1, prev);
    return rec(arr, n - 1, prev) + rec(arr, n - 1, n);
}

int rec(vi arr) {
    int ans = 0;
    for (int i = 1; i <= arr.size(); ++i) {
        ans += rec(arr, i - 1, i);
    }
    return ans;
}

int rec2(vi arr, int n, int prev, int k) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    if (arr[n - 1] > arr[prev - 1]) return rec2(arr, n - 1, prev, k);
    return rec2(arr, n - 1, prev, k) + rec2(arr, n - 1, n, k - 1);
}

int rec2(vi arr) {
    int ans = 0;
    int n = arr.size();
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= n; ++k) {
            ans += rec2(arr, i - 1, i, k);
        }
    }
    return ans;
}

int rec3(vi arr, int n, int prev) {
    if (n == 0) return 1;
    if (arr[n - 1] < arr[prev - 1]) return rec3(arr, n - 1, n) + rec3(arr, n - 1, prev);
    return rec3(arr, n - 1, prev);
}

int rec3(vi arr) {
    int ans = 0;
    for (int i = 1; i <= arr.size(); ++i) {
        ans += rec3(arr, i - 1, i);
    }
    return ans;
}

int tab(vi arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (arr[i - 1] > arr[j - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][i];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i - 1][i];
    }
    return ans;
}

int tab2(vi arr) {
    int n = arr.size();
    vvvi dp(n + 1, vvi(n + 1, vi(n + 1)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (k == 0) {
                    dp[i][j][k] = 1;
                }
                else if (i == 0) {
                    dp[i][j][k] = 0;
                }
                else if (arr[i - 1] > arr[j - 1]) {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                else {
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][i][k - 1];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= n; ++k) {
            ans += dp[i - 1][i][k];
        }
    }
    return ans;
}

int main() { // TimeMeasure _; __x();
    vi arr1 = {1, 2, 3, 4};
    vi arr2 = {4, 3, 6, 5};
    vi arr3 = {3, 2, 4, 5, 4};
    cout << naive(arr1) << endl; // 15
    cout << naive(arr2) << endl; // 8
    cout << naive(arr3) << endl; // 17
    cout << endl;
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << endl;
    cout << rec2(arr1) << endl;
    cout << rec2(arr2) << endl;
    cout << rec2(arr3) << endl;
    cout << endl;
    cout << rec3(arr1) << endl;
    cout << rec3(arr2) << endl;
    cout << rec3(arr3) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << endl;
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
    cout << tab2(arr3) << endl;
}
