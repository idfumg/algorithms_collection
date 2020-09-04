#include "../template.hpp"

int tab(vi& arr) {
    int n = arr.size(), maxi = -INF, maxipos = 0;
    vi dp(n, 1), prev(n, -1); vb isincreasing(n);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if ((dp[i] < dp[j] + 1 || (dp[i] == dp[j] + 1 && prev[i] != -1 && arr[j] > arr[prev[i]])) && (not isincreasing[j] || j == 0)) {
                    dp[i] = dp[j] + 1;
                    isincreasing[i] = true;
                    prev[i] = j;
                }
            }
            else {
                if ((dp[i] < dp[j] + 1 || (dp[i] == dp[j] + 1 && prev[i] != -1 && arr[j] > arr[prev[i]])) && (isincreasing[j] || j == 0)) {
                    dp[i] = dp[j] + 1;
                    isincreasing[i] = false;
                    prev[i] = j;
                }
            }
            if (maxi < dp[i] || (maxi == dp[i] && arr[i] > arr[maxipos])) {
                maxi = dp[i];
                maxipos = i;
            }
        }
    }
    vi result(maxi); int pos = result.size() - 1;
    for (int at = maxipos; pos >= 0 && at != -1; at = prev[at]) {
        result[pos--] = arr[at];
    }
    cout << result;
    return maxi;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 4};
    vi arr2 = {1, 4, 5};
    vi arr3 = {10, 22, 9, 33, 49, 50, 31, 60};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
}
