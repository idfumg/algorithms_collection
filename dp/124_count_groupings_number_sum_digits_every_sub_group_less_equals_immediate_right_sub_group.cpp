#include "../../template.hpp"

int rec(vi& arr, int from, int prev, vvi& dp) {
    if (from >= arr.size()) return 1;
    if (dp[from][prev] != -1) return dp[from][prev];

    int sum = 0, count = 0;

    for (int i = from; i < arr.size(); ++i) {
        sum += arr[i];
        if (sum >= prev) {
            count += rec(arr, i + 1, sum, dp);
        }
    }

    return dp[from][prev] = count;
}

int rec(vi& arr) {
    vvi dp(arr.size(), vi(accumulate(arr.begin(), arr.end(), 0), -1));
    return rec(arr, 0, 0, dp);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 1, 1, 9};
    vi arr2 = {1, 2, 3, 4};
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
}
