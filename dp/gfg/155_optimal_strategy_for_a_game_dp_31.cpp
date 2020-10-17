#include "../../template.hpp"

pi rec(vi& arr, int i, int j, bool isFirst, int sum1, int sum2) {
    if (i > j) {
        return {sum1, sum2};
    }
    if (isFirst) {
        const auto a = rec(arr, i + 1, j, !isFirst, sum1 + arr[i], sum2);
        const auto b = rec(arr, i, j - 1, !isFirst, sum1 + arr[j], sum2);
        return a.first > b.first ? a : b;
    }
    else {
        const auto a = rec(arr, i + 1, j, !isFirst, sum1, sum2 + arr[i]);
        const auto b = rec(arr, i, j - 1, !isFirst, sum1, sum2 + arr[j]);
        return a.second > b.second ? a : b;
    }
}

int rec(vi& arr) {
    return rec(arr, 0, arr.size() - 1, true, 0, 0).first;
}

int tab(vi& arr) {
    int n = arr.size(), idx = 0;
    vvvpi dp(n, vvpi(2, vpi(2)));
    for (int j = 0; j < n; ++j) {
        idx = j & 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int isFirst : {1, 0}) {
                if (i > j) {
                }
                else if (isFirst) {
                    if (i + 1 < n) {
                        dp[i][idx][isFirst] = dp[i + 1][idx][!isFirst];
                        dp[i][idx][isFirst].first += arr[i];
                    }
                    if (j > 0) {
                        auto b = dp[i][1 - idx][!isFirst]; b.first += arr[j];
                        if (b.first > dp[i][idx][isFirst].first) {
                            dp[i][idx][isFirst] = b;
                        }
                    }
                }
                else {
                    if (i + 1 < n) {
                        dp[i][idx][isFirst] = dp[i + 1][idx][!isFirst];
                        dp[i][idx][isFirst].second += arr[i];
                    }
                    if (j > 0) {
                        auto b = dp[i][1- idx][!isFirst]; b.second += arr[j];
                        if (b.second > dp[i][idx][isFirst].second) {
                            dp[i][idx][isFirst] = b;
                        }
                    }
                }
            }
        }
    }
    return dp[0][idx][1].first;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {8, 15, 3, 7};
    vi arr2 = {2, 2, 2, 2};
    vi arr3 = {20, 30, 2, 2, 2, 10};
    vi arr4 = {5, 3, 7, 10};
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
}
