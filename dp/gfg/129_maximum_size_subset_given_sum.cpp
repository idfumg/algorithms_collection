#include "../../template.hpp"

void rec(vi& arr, int sum, int n, int count, int& maxcount) {
    if (sum == 0) {
        maxcount = max(maxcount, count);
        return;
    }
    if (sum <= 0 or n <= 0) {
        return;
    }
    rec(arr, sum, n - 1, count, maxcount);
    rec(arr, sum - arr[n - 1], n - 1, count + 1, maxcount);
}

int rec(vi& arr, int sum) { // Recursive Implementation
    int maxcount = 0;
    rec(arr, sum, arr.size(), 0, maxcount);
    return maxcount;
}

int tab(vi& arr, int sum) { // Simultanious Logic process of generating count
    int n = arr.size();
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
                dp[i][j] = dp[i][j] or dp[i - arr[j - 1]][j - 1];
                count[i][j] = max(count[i][j], count[i - arr[j - 1]][j - 1] + 1);
            }
        }
    }
    return count[sum][n];
}

int tab2(vi& arr, int sum) { // Separate Logic Process of generating count
    int n = arr.size();
    vvi dp(sum + 1, vi(n + 1));
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1] and dp[i - arr[j - 1]][j - 1]) {
                dp[i][j] = 1;
            }
        }
    }
    vvi count(sum + 1, vi(n + 1));
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            count[i][j] = count[i][j - 1];
            if (i >= arr[j - 1]) {
                count[i][j] = max(count[i][j], count[i - arr[j - 1]][j - 1] + 1);
            }
        }
    }
    return count[sum][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 3, 5, 7, 10, 15}; int sum1 = 10; // 3
    vi arr2 = {1, 2, 3, 4, 5}; int sum2 = 4; // 2
    vi arr3 = {2, 3, 5, 10}; int sum3 = 20; // 4

    cout << rec(arr1, sum1) << endl;
    cout << rec(arr2, sum2) << endl;
    cout << rec(arr3, sum3) << endl;
    cout << '\n';
    cout << tab(arr1, sum1) << endl;
    cout << tab(arr2, sum2) << endl;
    cout << tab(arr3, sum3) << endl;
    cout << '\n';
    cout << tab2(arr1, sum1) << endl;
    cout << tab2(arr2, sum2) << endl;
    cout << tab2(arr3, sum3) << endl;
}
