#include "../template.hpp"

int rec(vi& arr, int sum, int n, int count) {
    if (sum == 0) return count;
    if (n <= 0) return 0;
    return max(rec(arr, sum, n - 1, count),
               rec(arr, sum - arr[n - 1], n - 1, count + 1));
}

int rec(vi& arr, int sum) {
    return rec(arr, sum, arr.size(), 0);
}

int tab(vi& arr, int sum) {
    int n = arr.size();
    vvi dp(sum + 1, vi(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (j == 0) {
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (i >= arr[j - 1]) {
                    dp[i][j] = dp[i][j] or dp[i - arr[j - 1]][j - 1];
                }
            }
        }
    }
    vvi count(sum + 1, vi(n + 1));
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            count[i][j] = count[i][j - 1];
            if (i >= arr[j - 1] and dp[i][j]) {
                count[i][j] = max(count[i][j], count[i - arr[j - 1]][j - 1] + 1);
            }
        }
    }
    return count[sum][n];
}

int tab2(vi& arr, int sum) {
    int n = size(arr);
    vvi dp(sum + 1, vi(n + 1));
    vvi count(sum + 1, vi(n + 1));

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            count[i][j] = count[i][j - 1];
            if (i >= arr[j - 1]) {
                if (dp[i - arr[j - 1]][j - 1]) {
                    count[i][j] = max(count[i][j], count[i - arr[j - 1]][j - 1]+1);
                    dp[i][j] = dp[i][j] or dp[i - arr[j - 1]][j - 1];
                }
            }
        }
    }

    return count[sum][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 3, 5, 7, 10, 15}; int sum1 = 10;
    vi arr2 = {1, 2, 3, 4, 5}; int sum2 = 4;
    vi arr3 = {2, 3, 5, 10}; int sum3 = 20;
    cout << rec(arr1, sum1) << endl;
    cout << rec(arr2, sum2) << endl;
    cout << rec(arr3, sum3) << endl;
    cout << endl;
    cout << tab(arr1, sum1) << endl;
    cout << tab(arr2, sum2) << endl;
    cout << tab(arr3, sum3) << endl;
    cout << endl;
    cout << tab2(arr1, sum1) << endl;
    cout << tab2(arr2, sum2) << endl;
    cout << tab2(arr3, sum3) << endl;
}
