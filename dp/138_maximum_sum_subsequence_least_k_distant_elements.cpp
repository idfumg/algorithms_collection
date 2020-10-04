#include "../template.hpp"

int rec(vi& arr, int k, int n) {
    if (n <= 0) return 0;
    return max(rec(arr, k, n - 1), rec(arr, k, n - k) + arr[n - 1]);
}

int rec(vi& arr, int k) {
    return rec(arr, k + 1, arr.size());
}

int tab(vi& arr, int k) {
    int n = arr.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1], (i - k - 1 ? dp[i - k - 1] : 0) + arr[i - 1]);
    }
    return dp[n];
}

int tab2(vi& arr, int k) {
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

int tab3(vi& arr, int k) {
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

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 5, 8, 7, 5, 4, 3, 4, 6, 5}; int k1 = 2; // 19
    vi arr2 = {50, 70, 40, 50, 90, 70, 60, 40, 70, 50}; int k2 = 2; // 230

    cout << rec(arr1, k1) << endl;
    cout << rec(arr2, k2) << endl;
    cout << '\n';
    cout << tab(arr1, k1) << endl;
    cout << tab(arr2, k2) << endl;
    cout << '\n';
    cout << tab2(arr1, k1) << endl;
    cout << tab2(arr2, k2) << endl;
    cout << '\n';
    cout << tab3(arr1, k1) << endl;
    cout << tab3(arr2, k2) << endl;
}
