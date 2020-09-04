#include "../template.hpp"

int rec(const vi& arr, const int from, const int n) {
    if (from == n - 1) return 0;
    if (arr[from] == 0) return -1;
    int count = 0;
    for (int i = from + 1; i < n; ++i) {
        if (arr[from] >= i - from) {
            const int res = rec(arr, i, n);
            if (res != -1) {
                count += res;
            }
        }
    }
    if (arr[from] >= n - from - 1) {
        ++count;
    }
    return count;
}

int rec(const vi& arr) {
    return rec(arr, 0, arr.size());
}

vi tab(const vi& arr) {
    const int n = arr.size();
    vi dp(n);
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] == 0) {
            dp[i] = -1;
        }
        else {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] >= j - i and dp[j] != -1) {
                    dp[i] += dp[j];
                }
            }
            if (arr[i] >= n - i - 1) {
                dp[i] += 1;
            }
        }
    }
    return dp;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 2, 0, 1};
    vi arr2 = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
}
