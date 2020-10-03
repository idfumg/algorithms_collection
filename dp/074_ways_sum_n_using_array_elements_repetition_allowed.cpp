#include "../template.hpp"

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

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 6}; int sum1 = 7; // 6
    vi arr2 = {12, 3, 1, 9}; int sum2 = 14; // 150
    cout << rec(arr1, sum1) << endl;
    cout << rec(arr2, sum2) << endl;
    cout << tab(arr1, sum1) << endl;
    cout << tab(arr2, sum2) << endl;
}
