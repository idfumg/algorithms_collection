#include "../template.hpp"

int tab(vi& arr) {
    int n = arr.size();
    sort(arr);
    vi dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] % arr[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return max(dp);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {10, 5, 3, 15, 20};
    vi arr2 = {18, 1, 3, 6, 13, 17};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
