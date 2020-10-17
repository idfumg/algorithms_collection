#include "../../template.hpp"

int tab(vi& arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n));
    for (int i = 0; i < n; ++i) {
        dp[1][i] = 1;
    }
    for (int k = 2; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    dp[k][i] += dp[k - 1][j];
                }
            }
        }
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += dp[K][i];
    }
    return total;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 6, 4, 5, 7}; int k1 = 3;
    vi arr2 = {12, 8, 11, 13, 10, 15, 14, 16, 20}; int k2 = 4;
    vi arr3 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k3 = 3;

    cout << tab(arr1, k1) << endl; // 5
    cout << tab(arr2, k2) << endl; // 39
    cout << tab(arr3, k3) << endl; // 31
}
