#include "../template.hpp"

int rec(vi& arr) {
    const auto n = arr.size();
    vi dp(n, 1);
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) dp[i] = dp[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > arr[i + 1]) dp[i] = max(dp[i], dp[i + 1] + 1);
    }
    return accumulate(dp.begin(), dp.end(), 0);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 4, 3, 6, 2, 1};
    vi arr2 = {1, 2, 2};
    cout << rec(arr1) << endl; // 10
    cout << rec(arr2) << endl; // 4
}
