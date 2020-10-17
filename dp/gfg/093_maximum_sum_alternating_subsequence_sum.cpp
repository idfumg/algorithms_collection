#include "../../template.hpp"

int tab(vi& arr) {
    int n = arr.size();
    vvi dp(2, vi(n));
    dp[1][0] = arr[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] and j != 0 and dp[0][j] != 0) {
                dp[1][i] = max(dp[1][i], dp[0][j] + arr[i]);
            }
            if (arr[i] < arr[j] and dp[1][j] != 0) {
                dp[0][i] = max(dp[0][i], dp[1][j] + arr[i]);
            }
        }
    }
    return max(dp[1]);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 3, 8, 5, 3, 8}; // 28
    vi arr2 = {4, 8, 2, 5, 6, 8}; // 14
    vi arr3 = {8, 2, 3, 5, 7, 9, 10}; // 25
    vi arr4 = {1, 20, 6, 7, 8, 2, 10, 8, 10, 7}; // 1
    vi arr5 = {4, 8, 6, 10}; // 4
    vi arr6 = {100, 1, 50, 100}; // 250
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
    cout << tab(arr5) << endl;
    cout << tab(arr6) << endl;
}
