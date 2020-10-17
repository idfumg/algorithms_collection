#include "../../template.hpp"

int tab(vi& arr) {
    int n = arr.size(), maxi = 0;
    vi dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] >= arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
            maxi = max(maxi, dp[i]);
        }
    }
    return n - maxi;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 3, 5, 1, 4, 7, 6};
    vi arr2 = {4, 6, 5, 1};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
