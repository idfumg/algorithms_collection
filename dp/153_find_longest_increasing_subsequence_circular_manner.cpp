#include "../template.hpp"

int tab(vi arr) {
    int n = arr.size(), maxi = 0;
    for (int i = 0; i < n; ++i) {
        arr.push_back(arr[i]);
    }
    n *= 2;

    vi dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], (arr[i] > arr[j]) * dp[j] + 1);
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {5, 4, 3, 2, 1};
    vi arr2 = {5, 6, 7, 1, 2, 3};
    vi arr3 = {1, 4, 6, 2, 3};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
}
