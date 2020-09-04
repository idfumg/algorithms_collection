#include "../template.hpp"

int tab(vi& arr) {
    int n = arr.size(), maxi = 0, posmaxi = 0;
    vi dp(n, 1), prev(n, -1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && arr[i] - arr[j] == 1) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if (maxi < dp[i]) {
                        maxi = dp[i];
                        posmaxi = i;
                    }
                }

            }
        }
    }
    vi result(maxi); int pos = result.size() - 1;
    for (int at = posmaxi; at != -1; at = prev[at]) {
        result[pos--] = arr[at];
    }
    cout << result;
    return maxi;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12};
    vi arr2 = {6, 7, 8, 3, 4, 5, 9, 10};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
