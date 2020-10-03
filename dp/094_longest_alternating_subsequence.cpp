#include "../template.hpp"

int tab(vi& arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(2, 1));
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int k : {0, 1}) {
                if (k == 0 and arr[i - 1] > arr[j - 1]) {
                    dp[i][k] = max(dp[i][k], dp[j][!k] + 1);
                }
                else if (k == 1 and arr[i - 1] < arr[j - 1]) {
                    dp[i][k] = max(dp[i][k], dp[j][!k] + 1);
                }
            }
        }
    }
    return max(dp[n]);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 4};
    vi arr2 = {1, 4, 5};
    vi arr3 = {10, 22, 9, 33, 49, 50, 31, 60};
    vi arr4 = {10, 22, 9, 33, 49, 50, 31, 60, 100, 1000};
    vi arr5 = {8, 2, 3, 5, 7, 9, 10};

    cout << tab(arr1) << endl; // 3
    cout << tab(arr2) << endl; // 2
    cout << tab(arr3) << endl; // 6
    cout << tab(arr4) << endl; // 6
    cout << tab(arr5) << endl; // 3
}
