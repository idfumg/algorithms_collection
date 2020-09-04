#include "../../template.hpp"

int rec(vi& arr, int number, int maxvalue, int n, int prev) {
    if (prev < 0 or prev > maxvalue) return 0;
    if (n < 0) return prev;
    if (n == 0) {
        return max(rec(arr, number, maxvalue, n - 1, prev + number),
                   rec(arr, number, maxvalue, n - 1, prev - number));
    }
    return max(rec(arr, number, maxvalue, n - 1, prev + arr[n - 1]),
               rec(arr, number, maxvalue, n - 1, prev - arr[n - 1]));
}

int rec(vi& arr, int number, int maxvalue) {
    return rec(arr, number, maxvalue, arr.size(), 0);
}

int tab(vi& arr, int number, int maxvalue) {
    int n = arr.size();
    vvi dp(n, vi(maxvalue + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= maxvalue; ++j) {
            if (i == 0) {
                if (number - arr[i] == j or number + arr[i] == j) {
                    dp[i][j] = 1;
                }
            }
            else {
                if (j - arr[i] >= 0 and j + arr[i] <= maxvalue) {
                    dp[i][j] = dp[i - 1][j - arr[i]] or dp[i - 1][j + arr[i]];
                }
                else if (j - arr[i] >= 0) {
                    dp[i][j] = dp[i - 1][j - arr[i]];
                }
                else if (j + arr[i] <= maxvalue) {
                    dp[i][j] = dp[i - 1][j + arr[i]];
                }
            }
        }
    }
    for (int i = maxvalue; i >= 0; --i) {
        if (dp[n - 1][i]) return i;
    }
    return -1;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 1, 7}; int number1 = 3, maxvalue1 = 7;
    vi arr2 = {3, 10, 6, 4, 5}; int number2 = 1, maxvalue2 = 15;
    cout << rec(arr1, number1, maxvalue1) << endl;
    cout << rec(arr2, number2, maxvalue2) << endl;
    cout << tab(arr1, number1, maxvalue1) << endl;
    cout << tab(arr2, number2, maxvalue2) << endl;
}
