#include "../../template.hpp"

int tab(vi& arr) {
    int n = arr.size();
    vi dp(n, 1);
    for (int i = 1; i < n; ++i) {
        dp[i] = arr[i] > arr[i - 1] ? dp[i - 1] + 1 : dp[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = arr[i] > arr[i + 1] ? dp[i + 1] + 1 : dp[i];
    }
    return accumulate(dp.begin(), dp.end(), 0);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 4, 3, 6, 2, 1};
    vi arr2 = {1, 2, 2};
    cout << tab(arr1) << endl; // 10
    cout << tab(arr2) << endl; // 4
}
