#include "../template.hpp"

bool IsIncreasing(vi& elems) {
    int n = elems.size();
    for (int i = 1; i < n; ++i) {
        if (elems[i] < elems[i - 1]) {
            return false;
        }
    }
    return true;
}

void naive(vi& arr, set<vi>& all, vi& current, int from) {
    int n = arr.size();
    if (from == n) {
        if (not current.empty() and IsIncreasing(current)) {
            all.insert(current);
        }
        return;
    }
    for (int i = from; i < n; ++i) {
        naive(arr, all, current, i + 1);
        current.push_back(arr[i]);
        naive(arr, all, current, i + 1);
        current.pop_back();
    }
}

int naive(vi& arr) {
    vi current;
    set<vi> all;
    naive(arr, all, current, 0);
    return all.size();
}

int tab(vi& arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1;
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (arr[i - 1] > arr[j - 1]) {
                    dp[k][i] += dp[k - 1][j];
                }
            }
        }
    }
    int total = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            total += dp[k][i];
        }
    }
    return total;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3, 4};
    vi arr2 = {4, 3, 6, 5};
    vi arr3 = {3, 2, 4, 5, 4};
    cout << naive(arr1) << endl; // 15
    cout << naive(arr2) << endl; // 8
    cout << naive(arr3) << endl; // 14
    cout << tab(arr1) << endl; // 15
    cout << tab(arr2) << endl; // 8
    cout << tab(arr3) << endl; // 14
}
