#include "../../template.hpp"

int tab(vi& arr) {
    int n = arr.size();
    vvi dp(2, vi(n));
    dp[1][0] = arr[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] and j != 0 and dp[0][j] != 0) {
                dp[1][i] = max(dp[1][i], dp[0][j] + arr[i]);
            }
            if (arr[i] < arr[j] and dp[1][j] != 0) {
                dp[0][i] = max(dp[0][i], dp[1][j] + arr[i]);
            }
        }
    }
    return max(dp[1]);
}

int rec(vi arr, int i, int prev, bool isDecreasing, int total) {
    int n = arr.size();
    if (i > n) {
        return total;
    }
    if ((not isDecreasing and arr[i - 1] > prev) or (isDecreasing and arr[i - 1] < prev)) {
        return max(rec(arr, i + 1, arr[i - 1], not isDecreasing, total + arr[i - 1]),
                   rec(arr, i + 1, prev, isDecreasing, total));
    }
    return rec(arr, i + 1, prev, isDecreasing, total);
}

int rec(vi arr) {
    return rec(arr, 2, arr[0], true, arr[0]);
}

int rec2(vi arr, int i, int prev, bool isDecreasing) {
    int n = arr.size();
    if (i > n) {
        return 0;
    }
    if ((not isDecreasing and arr[i - 1] > arr[prev - 1]) or (isDecreasing and arr[i - 1]<arr[prev - 1])){
        return max(rec2(arr, i + 1, i, not isDecreasing) + arr[i - 1],
                   rec2(arr, i + 1, prev, isDecreasing));
    }
    return rec2(arr, i + 1, prev, isDecreasing);
}

int rec2(vi arr) {
    return rec2(arr, 2, 1, true) + arr[0];
}

int tab2(vi arr) {
    int n = arr.size();
    vvvi dp(n + 2, vvi(n + 2, vi(2)));
    for (int i = n; i >= 2; --i) {
        for (int j = n; j >= 1; --j) {
            for (bool isDecreasing : {true, false}) {
                if ((not isDecreasing and arr[i - 1] > arr[j - 1]) or (isDecreasing and arr[i - 1]<arr[j - 1])){
                    dp[i][j][isDecreasing] = max(dp[i + 1][i][not isDecreasing] + arr[i - 1],
                                                 dp[i + 1][j][isDecreasing]);
                }
                else {
                    dp[i][j][isDecreasing] = dp[i + 1][j][isDecreasing];
                }
            }
        }
    }
    return dp[2][1][true] + arr[0];
}

int tab3(vi arr) {
    int n = arr.size();
    int idx = 0;
    vvvi dp(3, vvi(n + 2, vi(2)));
    for (int i = n; i >= 2; --i) {
        idx = i & 1;
        for (int j = n; j >= 1; --j) {
            for (bool isDecreasing : {true, false}) {
                if ((not isDecreasing and arr[i - 1] > arr[j - 1]) or (isDecreasing and arr[i - 1]<arr[j - 1])){
                    dp[idx][j][isDecreasing] = max(dp[1 - idx][i][not isDecreasing] + arr[i - 1],
                                                 dp[1 - idx][j][isDecreasing]);
                }
                else {
                    dp[idx][j][isDecreasing] = dp[1 - idx][j][isDecreasing];
                }
            }
        }
    }
    return dp[idx][1][true] + arr[0];
}

int rec3(vi arr, int n, int prev, int isdown) {
    if (n == arr.size() + 1) {
        return 0;
    }
    else if (isdown) {
        if (arr[n - 1] < arr[prev - 1]) {
            return max(rec3(arr, n + 1, n, 0) + arr[n - 1], rec3(arr, n + 1, prev, 1));
        }
        else {
            return rec3(arr, n + 1, prev, 1);
        }
    }
    else {
        if (arr[n - 1] > arr[prev - 1]) {
            return max(rec3(arr, n + 1, n, 1) + arr[n - 1], rec3(arr, n + 1, prev, 0));
        }
        else {
            return rec3(arr, n + 1, prev, 0);
        }
    }
}

int rec3(vi arr) {
    return rec3(arr, 2, 1, 1) + arr[0];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 3, 8, 5, 3, 8}; // 28
    vi arr2 = {4, 8, 2, 5, 6, 8}; // 14
    vi arr3 = {8, 2, 3, 5, 7, 9, 10}; // 25
    vi arr4 = {1, 20, 6, 7, 8, 2, 10, 8, 10, 7}; // 1
    vi arr5 = {4, 8, 6, 10}; // 4
    vi arr6 = {100, 1, 50, 100}; // 250
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
    cout << tab(arr5) << endl;
    cout << tab(arr6) << endl;
    cout << '\n';
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << rec(arr5) << endl;
    cout << rec(arr6) << endl;
    cout << '\n';
    cout << rec2(arr1) << endl;
    cout << rec2(arr2) << endl;
    cout << rec2(arr3) << endl;
    cout << rec2(arr4) << endl;
    cout << rec2(arr5) << endl;
    cout << rec2(arr6) << endl;
    cout << '\n';
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
    cout << tab2(arr3) << endl;
    cout << tab2(arr4) << endl;
    cout << tab2(arr5) << endl;
    cout << tab2(arr6) << endl;
    cout << '\n';
    cout << tab3(arr1) << endl;
    cout << tab3(arr2) << endl;
    cout << tab3(arr3) << endl;
    cout << tab3(arr4) << endl;
    cout << tab3(arr5) << endl;
    cout << tab3(arr6) << endl;
    cout << '\n';
    cout << rec3(arr1) << endl;
    cout << rec3(arr2) << endl;
    cout << rec3(arr3) << endl;
    cout << rec3(arr4) << endl;
    cout << rec3(arr5) << endl;
    cout << rec3(arr6) << endl;
}
