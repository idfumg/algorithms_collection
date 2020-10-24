#include "../../template.hpp"

int rec(vi arr, int at) {
    int n = arr.size();
    if (at >= n - 1) {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= arr[at]; i++) {
        ans += rec(arr, at + i);
    }
    if (at + arr[at] >= n - 1) {
        ans += 1;
    }
    return ans;
}

vi rec(vi arr) {
    int n = arr.size();
    vi elems;
    for (int i = 0; i < n; ++i) {
        int ans = rec(arr, i);
        elems.push_back(ans);
    }
    for (int i = 0; i < n; ++i) {
        if (elems[i] == 0) {
            elems[i] = -1;
        }
    }
    elems[n - 1] = 0;
    return elems;
}

vi tab(vi& arr) {
    int n = arr.size();
    vi dp(n);

    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            dp[i] = 1;
        }
    }

    for (int i = n - 3; i >= 0; i--) {
        for (int j = 1; i + j < n and j <= arr[i]; ++j) {
            dp[i] += dp[i + j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dp[i] == 0) {
            dp[i] = -1;
        }
    }

    dp[n - 1] = 0;

    return dp;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 2, 0, 1};
    vi arr2 = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    cout << rec(arr1) << endl; // 2 1 -1 0
    cout << rec(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
    cout << tab(arr1) << endl; // 2 1 -1 0
    cout << tab(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
}
