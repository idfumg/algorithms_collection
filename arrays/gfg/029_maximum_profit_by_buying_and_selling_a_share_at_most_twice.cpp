#include "../../template.hpp"

int rec(vi arr, int k, int n, int prev, int total) {
    if (k == 0) {
        return total;
    }
    if (n == 0) {
        return total;
    }
    if (prev == -1) {
        return max(rec(arr, k, n - 1, prev, total),
                   rec(arr, k, n - 1, n, total));
    }
    return max(rec(arr, k, n - 1, prev, total),
               rec(arr, k - 1, n - 1, -1, total + arr[prev - 1] - arr[n - 1]));
}

int rec(vi arr) {
    return rec(arr, 2, arr.size(), -1, 0);
}

int rec2(vi arr, int k, int n, int prev) {
    if (k == 0) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    if (prev == -1) {
        return max(rec2(arr, k, n - 1, prev),
                   rec2(arr, k, n - 1, n));
    }
    return max(rec2(arr, k, n - 1, prev),
               rec2(arr, k - 1, n - 1, -1) + arr[prev - 1] - arr[n - 1]);
}

int rec2(vi arr) {
    return rec2(arr, 2, arr.size(), -1);
}

int tab(vi arr) {
    int n = arr.size();
    vvvi dp(3, vvi(n + 1, vi(n + 2)));
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = n; k >= 0; --k) {
                if (i == 0) {
                    dp[i][j][k] = 0;
                }
                else if (j == 0) {
                    dp[i][j][k] = 0;
                }
                else if (k == 0) {
                    dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j - 1][j]);
                }
                else {
                    dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j - 1][0] + arr[k - 1] - arr[j - 1]);
                }
            }
        }
    }
    return dp[2][n][0];
}

int efficient(vi arr) {
    int n = arr.size();
    vi profit(n);

    int maxi = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxi = max(maxi, arr[i]);
        profit[i] = max(profit[i + 1], maxi - arr[i]);
    }

    int mini = arr[0];
    for (int i = 1; i < n; ++i) {
        mini = min(mini, arr[i]);
        profit[i] = max(profit[i - 1], profit[i] + arr[i] - mini);
    }

    return profit[n - 1];
}

int efficient2(vi arr) {
    int n = arr.size();
    vi profit1(n);
    int maxi = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxi = max(maxi, arr[i]);
        profit1[i] = max(profit1[i + 1], maxi - arr[i]);
    }
    vi profit2(n);
    int mini = arr[0];
    for (int i = 1; i < n; ++i) {
        mini = min(mini, arr[i]);
        profit2[i] = max(profit2[i - 1], arr[i] - mini);
    }
    for (int i = 1; i < n; ++i) {
        profit2[i] = max({profit1[i], profit2[i], profit1[i] + profit2[i], profit2[i - 1]});
    }
    return profit2[n - 1];
}

int main() { TimeMeasure _;
    cout << rec({10, 22, 5, 75, 65, 80}) << '\n'; // 87
    cout << rec({2, 30, 15, 10, 8, 25, 80}) << '\n'; // 100
    cout << rec({100, 30, 15, 10, 8, 25, 80}) << '\n'; // 72
    cout << rec({90, 80, 70, 60, 50}) << '\n'; // 0
    cout << rec({75, 4, 25, 20, 60, 45}) << '\n'; // 61
    cout << '\n';
    cout << rec2({10, 22, 5, 75, 65, 80}) << '\n';
    cout << rec2({2, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << rec2({100, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << rec2({90, 80, 70, 60, 50}) << '\n';
    cout << rec2({75, 4, 25, 20, 60, 45}) << '\n';
    cout << '\n';
    cout << tab({10, 22, 5, 75, 65, 80}) << '\n';
    cout << tab({2, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << tab({100, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << tab({90, 80, 70, 60, 50}) << '\n';
    cout << tab({75, 4, 25, 20, 60, 45}) << '\n';
    cout << '\n';
    cout << efficient({10, 22, 5, 75, 65, 80}) << '\n';
    cout << efficient({2, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << efficient({100, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << efficient({90, 80, 70, 60, 50}) << '\n';
    cout << efficient({75, 4, 25, 20, 60, 45}) << '\n';
    cout << '\n';
    cout << efficient2({10, 22, 5, 75, 65, 80}) << '\n';
    cout << efficient2({2, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << efficient2({100, 30, 15, 10, 8, 25, 80}) << '\n';
    cout << efficient2({90, 80, 70, 60, 50}) << '\n';
    cout << efficient2({75, 4, 25, 20, 60, 45}) << '\n';

}
