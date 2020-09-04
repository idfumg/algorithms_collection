#include "../template.hpp"

int tab(vi& arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n));
    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            if (k == 1) {
                dp[k][i] = 1;
            }
            else {
                for (int j = 0; j < i; ++j) {
                    if (arr[i] > arr[j]) {
                        dp[k][i] += dp[k - 1][j];
                    }
                }
            }
        }
    }
    return accumulate(dp[K].begin(), dp[K].end(), 0);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 6, 4, 5, 7}; int k1 = 3;
    vi arr2 = {12, 8, 11, 13, 10, 15, 14, 16, 20}; int k2 = 4;
    vi arr3 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k3 = 3;

    cout << tab(arr1, k1) << endl; // 5
    cout << tab(arr2, k2) << endl; // 39
    cout << tab(arr3, k3) << endl; // 31
}
