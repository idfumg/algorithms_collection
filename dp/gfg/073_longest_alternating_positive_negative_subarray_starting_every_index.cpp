#include "../../template.hpp"

void naive(vi& arr) {
    int n = arr.size(), res = 0;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] * arr[j - 1] < 0) {
                ++count;
            }
            else {
                break;
            }
        }
        cout << count << ' ';
    }
    cout << '\n';
}

int rec(vi arr, int i) {
    int n = arr.size();
    if (i == n) return 0;
    if (arr[i] * arr[i + 1] < 0) return rec(arr, i + 1) + 1;
    return 1;
}

void rec(vi arr) {
    int n = arr.size();
    vi ans(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        ans[i] = rec(arr, i);
    }
    cout << ans << endl;
}

void tab(vi arr) {
    int n = arr.size();
    vi dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] * arr[i + 1] < 0) {
            dp[i] = 1 + dp[i + 1];
        }
        else {
            dp[i] = 1;
        }
    }
    cout << dp << endl;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, -5, 1, -5}; // 4 3 2 1
    vi arr2 = {-5, -1, -1, 2, -2, -3}; // 1 1 3 2 1 1
    naive(arr1);
    naive(arr2);
    rec(arr1);
    rec(arr2);
    tab(arr1);
    tab(arr2);
}
