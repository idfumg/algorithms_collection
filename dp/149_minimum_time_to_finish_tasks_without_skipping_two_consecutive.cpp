#include "../template.hpp"

int choose(vi& arr, int n) {
    return n > 0 ? arr[n - 1] : 0;
}

int rec(vi& arr, int n) {
    if (n <= 0) return 0;
    return min(rec(arr, n - 1) + choose(arr, n),
               rec(arr, n - 2) + choose(arr, n - 1));
}

int rec(vi& arr) {
    return rec(arr, arr.size());
}

int tab(vi& arr) {
    int n = arr.size();
    vi dp(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + arr[i - 1],
                    dp[i - 2] + arr[i - 2]);
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {10, 5, 7, 10}; // 12
    vi arr2 = {10}; // 0
    vi arr3 = {10, 30}; // 10
    vi arr4 = {10, 5, 2, 4, 8, 6, 7, 10}; // 22
    vi arr5 = {467, 334, 500, 169, 724, 478, 358, 962, 464, 705, 145, 281}; // 1948
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << rec(arr5) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
    cout << tab(arr5) << endl;
}
