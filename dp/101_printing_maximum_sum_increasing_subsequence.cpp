#include "../../template.hpp"

int tab(vi& arr) {
    const int n = arr.size();

    vi dp = arr;
    vi prev(n, -1);
    int maxidx = 0, maxi = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if (dp[j] + arr[i] > dp[i]) {
                    dp[i] = dp[j] + arr[i];
                    prev[i] = j;
                    if (maxi < dp[i]) {
                        maxi = dp[i];
                        maxidx = i;
                    }
                }
            }
        }
    }

    vi result;
    for (int i = maxidx; i != -1; i = prev[i]) {
        result.push_back(arr[i]);
    }
    reverse(result);
    cout << result;

    return dp[maxidx];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 101, 2, 3, 100, 4, 5};
    vi arr2 = {3, 4, 5, 10};
    vi arr3 = {10, 5, 4, 3};
    vi arr4 = {3, 2, 6, 4, 5, 1};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
}
