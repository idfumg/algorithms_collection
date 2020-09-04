#include "../../template.hpp"

int tab(vi& arr) {
    int n = arr.size(), maxi = 0;
    vi dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], (arr[i] > arr[j]) * dp[j] + 1);
        }
        maxi = max(maxi, dp[i]);
    }
    return n - maxi;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {5, 6, 1, 7, 4};
    vi arr2 = {30, 40, 2, 5, 1, 7, 45, 50, 8};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
