#include "../../template.hpp"

bool IsNonDecreasing(vi& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void naive(vi& arr, int k, int& res, vi& current, int from) {
    int n = arr.size(), m = current.size();
    if (m > k) {
        return;
    }
    if (from == n) {
        if (current.size() == k and IsNonDecreasing(current)) {
            res = min(res, accumulate(current.begin(), current.end(), 0));
        }
        return;
    }
    for (int i = from; i < n; ++i) {
        naive(arr, k, res, current, i + 1);
        current.push_back(arr[i]);
        naive(arr, k, res, current, i + 1);
        current.pop_back();
    }
}

int naive(vi& arr, int k) {
    int res = INF;
    vi current;
    naive(arr, k, res, current, 0);
    return res;
}

int tab(vi& arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = arr[i - 1];
    }
    for (int k = 2; k <= K; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i - 1] > arr[j - 1]) {
                    dp[k][i] = min(dp[k][i], dp[k - 1][j] + arr[i - 1]);
                }
            }
        }
    }
    return min(dp[K]);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k1 = 3;
    vi arr2 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k2 = 4;
    vi arr3 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k3 = 5;

    cout << naive(arr1, k1) << '\n'; // 39
    cout << naive(arr2, k2) << '\n'; // 120
    cout << naive(arr3, k3) << '\n'; // 206
    cout << '\n';
    cout << tab(arr1, k1) << '\n'; // 39
    cout << tab(arr2, k2) << '\n'; // 120
    cout << tab(arr3, k3) << '\n'; // 206
}
