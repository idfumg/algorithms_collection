#include "../template.hpp"

int tab(vi& arr) {
    int n = arr.size();
    vi dp(n, 1);
    vb condition(n);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] < arr[j] and (condition[j] == 0 || j == 0)) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    condition[i] = j == 0 ? 1 : !condition[j];
                }
            }
            else if (arr[i] > arr[j] and (condition[j] == 1 || j == 0)) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    condition[i] = j == 0 ? 0 : !condition[j];
                }
            }
        }
    }
    debug(dp);
    return max(dp);
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
