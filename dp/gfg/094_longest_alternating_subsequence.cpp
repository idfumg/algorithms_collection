#include "../../template.hpp"

int rec(vi arr, int n, bool increase, int total) {
    if (n == 0) {
        return total;
    }
    if ((increase and arr[n - 1] > arr[n]) or (not increase and arr[n - 1] < arr[n])) {
        return max(rec(arr, n - 1, not increase, total + 1),
                   rec(arr, n - 1, increase, total));
    }
    return rec(arr, n - 1, increase, total);
}

int rec(vi arr) {
    int n = arr.size();
    return max(rec(arr, n - 1, true, 1), rec(arr, n - 1, false, 1));
}

int rec2(vi arr, int n, bool increase) {
    if (n == 0) {
        return 0;
    }
    if ((increase and arr[n - 1] > arr[n]) or (not increase and arr[n - 1] < arr[n])) {
        return max(rec2(arr, n - 1, not increase) + 1,
                   rec2(arr, n - 1, increase));
    }
    return rec2(arr, n - 1, increase);
}

int rec2(vi arr) {
    int n = arr.size();
    return max(rec2(arr, n - 1, true), rec2(arr, n - 1, false)) + 1;
}

int tab(vi arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(2));
    for (int i = 1; i <= n; ++i) {
        for (bool increase : {true, false}) {
            if ((increase and arr[i - 1] > arr[i]) or (not increase and arr[i - 1] < arr[i])) {
                dp[i][increase] = max(dp[i - 1][not increase] + 1,
                                      dp[i - 1][increase]);
            }
            else {
                dp[i][increase] = dp[i - 1][increase];
            }
        }
    }
    return max(dp[n - 1][true], dp[n - 1][false]) + 1;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 4};
    vi arr2 = {1, 4, 5};
    vi arr3 = {10, 22, 9, 33, 49, 50, 31, 60};
    vi arr4 = {10, 22, 9, 33, 49, 50, 31, 60, 100, 1000};
    vi arr5 = {8, 2, 3, 5, 7, 9, 10};

    cout << rec(arr1) << endl; // 3
    cout << rec(arr2) << endl; // 2
    cout << rec(arr3) << endl; // 6
    cout << rec(arr4) << endl; // 6
    cout << rec(arr5) << endl; // 3
    cout << '\n';
    cout << rec2(arr1) << endl; // 3
    cout << rec2(arr2) << endl; // 2
    cout << rec2(arr3) << endl; // 6
    cout << rec2(arr4) << endl; // 6
    cout << rec2(arr5) << endl; // 3
    cout << '\n';
    cout << tab(arr1) << endl; // 3
    cout << tab(arr2) << endl; // 2
    cout << tab(arr3) << endl; // 6
    cout << tab(arr4) << endl; // 6
    cout << tab(arr5) << endl; // 3
}
