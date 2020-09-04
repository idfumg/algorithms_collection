#include "../../template.hpp"

int rec(vi& arr, int sum, int n, int count, int maxcount, int currentsum) {
    if (sum == currentsum) {
        maxcount = max(maxcount, count);
        return maxcount;
    }
    if (n == 0) return 0;
    return max(rec(arr, sum, n - 1, count, maxcount, currentsum),
               rec(arr, sum, n - 1, count + 1, maxcount, currentsum + arr[n - 1]));
}

int rec(vi& arr, int sum) {
    int maxcount = 0;
    return rec(arr, sum, arr.size(), 0, maxcount, 0);
}

int tab(vi& arr, int sum) {
    int n = arr.size(), maxcount = 0;
    vvb dp(sum + 1, vb(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = true;
            }
            else if (j == 0) {
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (i >= arr[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - arr[j - 1]][j - 1]);
                }
            }
        }
    }
    vvi count(sum + 1, vi(n + 1));
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            count[i][j] = count[i][j - 1];
            if (i >= arr[j - 1]) {
                if (dp[i][j] == true) {
                    count[i][j] = max(count[i][j],count[i - arr[j - 1]][j - 1]+1);
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
}
