#include "../../template.hpp"

int count(vi& arr, vi& dp, int n, int i) {
    if (i < 0) return 0;
    if (arr[n] > arr[i] and arr[n] - arr[i] >= n - i) {
        return max(dp[i], count(arr, dp, n, i - 1));
    }
    return count(arr, dp, n, i - 1);
}

void rec(vi& arr, vi& dp, int n) {
    if (n < 0) return;
    rec(arr, dp, n - 1);
    dp[n] = count(arr, dp, n, n - 1) + 1;
}

int rec(vi& arr) {
    vi dp(arr.size());
    rec(arr, dp, arr.size() - 1);
    return arr.size() - *max_element(dp.begin(), dp.end());
}

int tab(vi& arr) {
    const auto n = arr.size();
    vi dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] and arr[i] - arr[j] >= i - j) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    return n - *max_element(dp.begin(), dp.end());
}

int opt(vi& arr) {
    const auto n = arr.size();
    vi dp(n, 1);
    int maxi = -INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            const int diff = arr[i] - arr[j];
            if (diff > 0 and diff >= i - j) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }
    }
    return n - maxi;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 6, 5, 4}; // 2
    vi arr2 = {1, 2, 3, 5, 7, 11}; // 0
    vi arr3 = {1, 2, 5, 3, 4}; // 2
    cout << "Recursive: " << rec(arr1) << endl;
    cout << "Recursive: " << rec(arr2) << endl;
    cout << "Recursive: " << rec(arr3) << endl;
    cout << "Tabulation: " << tab(arr1) << endl;
    cout << "Tabulation: " << tab(arr2) << endl;
    cout << "Tabulation: " << tab(arr3) << endl;
    cout << "Optimization: " << opt(arr1) << endl;
    cout << "Optimization: " << opt(arr2) << endl;
    cout << "Optimization: " << opt(arr3) << endl;
}
