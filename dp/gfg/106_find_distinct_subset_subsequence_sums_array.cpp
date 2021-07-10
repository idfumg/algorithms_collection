#include "../../template.hpp"

set<int> naive(vi arr) {
    int n = arr.size();
    set<int> ans;
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        ans.insert(sum);
    }
    return ans;
}

bool rec(vi arr, int n, int target) {
    if (target == 0) return true;
    if (n == 0 or target < 0) return false;
    return rec(arr, n - 1, target - arr[n - 1]) or rec(arr,  n - 1, target);
}

vi rec(vi arr) {
    int n = arr.size();
    int total = reduce(arr.begin(), arr.end(), 0);
    vi ans;
    for (int i = 0; i <= total; ++i) {
        if (rec(arr, n, i)) {
            ans.push_back(i);
        }
    }
    return ans;
}

vi tab(vi arr) {
    int n = arr.size();
    int total = reduce(arr.begin(), arr.end(), 0);

    vvi dp(n + 1, vi(total + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= total; ++j) {
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] or (j >= arr[i - 1] ? dp[i - 1][j - arr[i - 1]] : 0);
        }
    }

    vi ans;
    for (int i = 0; i <= total; ++i) {
        if (dp[n][i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

vi tab_elems(vi arr) {
    int n = arr.size();
    int total = reduce(arr.begin(), arr.end(), 0);

    vvi dp(n + 1, vi(total + 1));
    vvvi prev(n + 1, vvi(total + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= total; ++j) {
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else {
                if (dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j] = {i - 1, j, 0};
                }
                else if (j >= arr[i - 1] and dp[i - 1][j - arr[i - 1]]) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]];
                    prev[i][j] = {i - 1, j - arr[i - 1], 1};
                }
            }
        }
    }

    vi ans;
    for (int i = 0; i <= total; ++i) {
        if (dp[n][i]) {
            cout << i << ':' << ' ';
            for (vi at = prev[n][i]; not at.empty(); at = prev[at[0]][at[1]]) {
                if (at[2] == 1) {
                    cout << arr[at[0]] << ' ';
                }
            }
            cout << '\n';
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3};
    vi arr2 = {2, 3, 4, 5, 6};
    vi arr3 = {20, 30, 50};
    cout << naive(arr1) << '\n';
    cout << naive(arr2) << '\n';
    cout << naive(arr3) << '\n';
    cout << '\n';
    cout << rec(arr1) << '\n'; // 0 1 2 3 4 5 6
    cout << rec(arr2) << '\n'; // 0 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 20
    cout << rec(arr3) << '\n'; // 0 20 30 50 70 80 100
    cout << '\n';
    cout << tab(arr1) << '\n';
    cout << tab(arr2) << '\n';
    cout << tab(arr3) << '\n';
    cout << '\n';
    cout << tab_elems(arr1) << '\n';
    cout << tab_elems(arr2) << '\n';
    cout << tab_elems(arr3) << '\n';
}
