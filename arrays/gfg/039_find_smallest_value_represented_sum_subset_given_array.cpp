#include "../../template.hpp"

bool rec__(vi& arr, int total, int n) {
    if (total == 0) return true;
    if (total < 0 or n == 0) return false;
    return rec__(arr, total, n - 1) or rec__(arr, total - arr[n - 1], n - 1);
}

int rec_(vi& arr, int total, int current) {
    if (not rec__(arr, current, arr.size())) return current;
    return rec_(arr, total, current + 1);
}

int rec(vi arr) {
    return rec_(arr, accumulate(arr.begin(), arr.end(), 0) + 1, 1);
}

bool rec2(vi arr, int sum, int n) {
    if (sum == 0) return true;
    if (n == 0) return false;
    return rec2(arr, sum, n - 1) or rec2(arr, sum - arr[n - 1], n - 1);
}

int rec2(vi arr) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0) + 1;
    for (int i = 1; i <= total; ++i) {
        if (not rec2(arr, i, n)) {
            return i;
        }
    }
    return -1;
}

int tab(vi arr) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0) + 1;
    vvi dp(total + 1, vi(n + 1));
    for (int i = 0; i <= total; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (j == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i][j - 1] or (j >= arr[j - 1] ? dp[i - arr[j - 1]][j - 1] : 0);
            }
        }
    }
    for (int i = 0; i <= total; ++i) {
        bool sumCanBeAchieved = true;
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j]) {
                sumCanBeAchieved = false;
            }
        }
        if (sumCanBeAchieved) {
            return i;
        }
    }
    return -1;
}

int SmallestPosIntegerWhichCantBeSummed(vi arr) {
    int prevsum = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (prevsum + 1 < arr[i]) {
            return prevsum + 1;
        }
        prevsum += arr[i];
    }
    return prevsum + 1;
}

int main() { TimeMeasure _;
    cout << rec({1, 3, 6, 10, 11, 15}) << '\n'; // 2 // O(n * 2^n)
    cout << rec({1, 1, 1, 1}) << '\n'; // 5
    cout << rec({1, 1, 3, 4}) << '\n'; // 10
    cout << rec({1, 2, 5, 10, 20, 40}) << '\n'; // 4
    cout << rec({1, 2, 3, 4, 5, 6}) << '\n'; // 22
    cout << '\n';
    cout << rec2({1, 3, 6, 10, 11, 15}) << '\n'; // 2
    cout << rec2({1, 1, 1, 1}) << '\n'; // 5
    cout << rec2({1, 1, 3, 4}) << '\n'; // 10
    cout << rec2({1, 2, 5, 10, 20, 40}) << '\n'; // 4
    cout << rec2({1, 2, 3, 4, 5, 6}) << '\n'; // 22
    cout << '\n';
    cout << tab({1, 3, 6, 10, 11, 15}) << '\n'; // 2 // O(n^2)
    cout << tab({1, 1, 1, 1}) << '\n'; // 5
    cout << tab({1, 1, 3, 4}) << '\n'; // 10
    cout << tab({1, 2, 5, 10, 20, 40}) << '\n'; // 4
    cout << tab({1, 2, 3, 4, 5, 6}) << '\n'; // 22
    cout << '\n';
    cout << SmallestPosIntegerWhichCantBeSummed({1, 3, 6, 10, 11, 15}) << '\n'; // 2 // O(n)
    cout << SmallestPosIntegerWhichCantBeSummed({1, 1, 1, 1}) << '\n'; // 5
    cout << SmallestPosIntegerWhichCantBeSummed({1, 1, 3, 4}) << '\n'; // 10
    cout << SmallestPosIntegerWhichCantBeSummed({1, 2, 5, 10, 20, 40}) << '\n'; // 4
    cout << SmallestPosIntegerWhichCantBeSummed({1, 2, 3, 4, 5, 6}) << '\n'; // 22
}
