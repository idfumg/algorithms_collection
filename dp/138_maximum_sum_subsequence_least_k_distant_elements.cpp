#include "../../template.hpp"

int tab(vi& arr, int k) {
    int n = arr.size();
    vi dp = arr;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(i - j) > k) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    return max(dp);
}

int fast(vi& arr, int k) {
    int n = arr.size();
    vi dp(n);
    dp[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (i + k + 1 >= n) {
            dp[i] = max(arr[i], dp[i + 1]);
        }
        else {
            dp[i] = max(arr[i] + dp[i + k + 1], dp[i + 1]);
        }
    }
    return dp[0];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 5, 8, 7, 5, 4, 3, 4, 6, 5}; int k1 = 2;
    vi arr2 = {50, 70, 40, 50, 90, 70, 60, 40, 70, 50}; int k2 = 2;
    cout << tab(arr1, k1) << endl;
    cout << tab(arr2, k2) << endl;
    cout << fast(arr1, k1) << endl;
    cout << fast(arr2, k2) << endl;
}
