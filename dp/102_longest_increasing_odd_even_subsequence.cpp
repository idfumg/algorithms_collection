#include "../template.hpp"

int tab(vi& arr) {
    const int n = arr.size();
    vi dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if ((arr[i] % 2) + (arr[j] % 2) == 1) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
    }
    return max(dp);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {5, 6, 9, 4, 7, 8};
    vi arr2 = {1, 12, 2, 22, 5, 30, 31, 14, 17, 11};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
