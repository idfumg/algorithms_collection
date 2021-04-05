#include "../../template.hpp"

int rec(vi& arr, int sum) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    int count = 0, n = arr.size();
    for (int i = 0; i < n; ++i) {
        count += rec(arr, sum - arr[i]);
    }
    return count;
}

int tab(vi& arr, int sum) {
    int n = arr.size();
    vi dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= sum; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= arr[j]) {
                dp[i] += dp[i - arr[j]];
            }
        }
    }
    return dp[sum];
}

int rec2(vi arr, int sum, int i, int total) {
    int n = arr.size();
    if (total == sum) {
        return 1;
    }
    if (total > sum or i > n) {
        return 0;
    }
    return rec2(arr, sum, 1, total + arr[i - 1]) + rec2(arr, sum, i + 1, total);
}

int rec2(vi arr, int sum) {
    return rec2(arr, sum, 1, 0);
}

int tab2(vi arr, int sum) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0) + max(arr);
    vvi dp(n + 2, vi(total + 2));
    for (int j = sum; j >= 0; --j) {
        for (int i = n; i >= 1; --i) {
            if (j == sum) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[1][j + arr[i - 1]] + dp[i + 1][j];
            }
        }
    }
    return dp[1][0];
}

int rec(vi arr, int target, int n) {
    if (target == 0) return 1;
    if (n == 0 or target < 0) return 0;
    return rec(arr, target, n - 1) + rec(arr, target - arr[n - 1], arr.size());
}

int rec3(vi arr, int target) {
    return rec(arr, target, arr.size());
}

int tab3(vi arr, int target) {
    int n = arr.size();
    vvi dp(target + 1, vi(n + 1));
    for (int i = 0; i <= target; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (i >= arr[j - 1]) {
                    dp[i][j] += dp[i - arr[j - 1]][n];
                }
            }
        }
    }
    return dp[target][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 6}; int sum1 = 7; // 6
    vi arr2 = {12, 3, 1, 9}; int sum2 = 14; // 150
    cout << rec(arr1, sum1) << endl;
    cout << rec(arr2, sum2) << endl;
    cout << '\n';
    cout << tab(arr1, sum1) << endl;
    cout << tab(arr2, sum2) << endl;
    cout << '\n';
    cout << rec2(arr1, sum1) << endl;
    cout << rec2(arr2, sum2) << endl;
    cout << '\n';
    cout << tab2(arr1, sum1) << endl;
    cout << tab2(arr2, sum2) << endl;
    cout << '\n';
    cout << rec3(arr1, sum1) << endl;
    cout << rec3(arr2, sum2) << endl;
    cout << '\n';
    cout << tab3(arr1, sum1) << endl;
    cout << tab3(arr2, sum2) << endl;
}
