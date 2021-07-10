#include "../../template.hpp"

int rec(vi arr, int n) {
    if (n >= arr.size() - 1) return 1;
    int count = 0;
    for (int i = n + 1; i < arr.size(); ++i) {
        if (arr[n] >= i - n) {
            count += rec(arr, i);
        }
    }
    return count;
}

vi rec(vi arr) {
    int count = 0, n = arr.size();
    vi dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = rec(arr, i);
    }
    return dp;
}

vi tab(vi arr) {
    int n = arr.size();
    vi dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] >= j - i) {
                dp[i] += dp[j];
            }
        }
    }
    return dp;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 2, 0, 1};
    vi arr2 = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    cout << rec(arr1) << endl; // 2 1 0 1
    cout << rec(arr2) << endl; // 52 52 28 16 8 0 0 4 2 1 1
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
