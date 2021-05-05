#include "../../template.hpp"

si naive(vi arr) {
    int n = arr.size();
    si ans;
    for (int i = 0; i < (1 << n); ++i) {
        int current = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                current += arr[j];
            }
        }
        ans.insert(current);
    }
    return ans;
}

void rec(vi arr, si& ans, int n, int total) {
    ans.insert(total);
    if (n == 0) return;
    rec(arr, ans, n - 1, total + arr[n - 1]);
    rec(arr, ans, n - 1, total);
}

si rec(vi arr) {
    si ans;
    rec(arr, ans, arr.size(), 0);
    return ans;
}

vi tab(vi arr) {
    int n = arr.size();
    int total = reduce(arr.begin(), arr.end(), 0);

    vvi dp(total + 1, vi(n + 1));
    vi ans;

    for (int i = 0; i <= total; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (j > 0) {
                if (dp[i][j - 1]) {
                    dp[i][j] = 1;
                }
                if (i >= arr[j - 1] and dp[i - arr[j - 1]][j - 1]) {
                    dp[i][j] = 1;
                }
            }
            if (dp[i][j]) {
                if (ans.empty() or ans.back() != i) {
                    ans.push_back(i);
                }
            }
        }
    }

    return ans;
}

vi tab_elems(vi arr) {
    int n = arr.size();
    int total = reduce(arr.begin(), arr.end(), 0);

    vvi dp(total + 1, vi(n + 1));
    vi can(total + 1);
    vi from(total + 1, -1);
    vvvi prev(total + 1, vvi(n + 1));
    vi ans;

    for (int i = 0; i <= total; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (j > 0) {
                if (dp[i][j - 1]) {
                    dp[i][j] = 1;
                    prev[i][j] = {i, j - 1, 0};
                }
                if (i >= arr[j - 1] and dp[i - arr[j - 1]][j - 1]) {
                    dp[i][j] = 1;
                    prev[i][j] = {i - arr[j - 1], j - 1, 1};
                }
            }
            if (dp[i][j] and can[i] == 0) {
                can[i] = 1;
                ans.push_back(i);
                from[i] = j;
            }
        }
    }

    for (int i = 0; i <= total; ++i) {
        if (can[i] and from[i] != -1) {
            cout << i << ':' << ' ';
            for (vi at = prev[i][from[i]]; not at.empty(); at = prev[at[0]][at[1]]) {
                if (at[2] == 1) {
                    cout << arr[at[1]] << ' ';
                }
            }
            cout << '\n';
        }
    }

    return ans;
}

int main() { // TimeMeasure _; __x();
    vi arr1 = {1, 2, 3};
    vi arr2 = {2, 3, 4, 5, 6};
    vi arr3 = {20, 30, 50};
    cout << naive(arr1) << '\n';
    cout << naive(arr2) << '\n';
    cout << naive(arr3) << '\n';
    cout << '\n';
    cout << rec(arr1) << '\n';
    cout << rec(arr2) << '\n';
    cout << rec(arr3) << '\n';
    cout << '\n';
    cout << tab(arr1) << '\n';
    cout << tab(arr2) << '\n';
    cout << tab(arr3) << '\n';
    cout << '\n';
    cout << tab_elems(arr1) << '\n';
    cout << tab_elems(arr2) << '\n';
    cout << tab_elems(arr3) << '\n';
}
