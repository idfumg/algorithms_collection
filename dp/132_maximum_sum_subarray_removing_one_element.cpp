#include "../template.hpp"

int tab(vi& arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1));

    for (int k = 0; k <= K; ++k) {
        dp[k][1] = arr[0];
    }
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = max(dp[0][i - 1] + arr[i - 1], arr[i - 1]);
    }
    for (int k = 1; k <= K; ++k) {
        for (int i = 2; i <= n; ++i) {
            dp[k][i] = max({dp[k][i - 1] + arr[i - 1],
                            arr[i - 1],
                            dp[k - 1][i - 1]});
        }
    }
    int maxi = -INF;
    for (int i = 0; i <= n; ++i) {
        maxi = max(maxi, dp[K][i]);
    }
    return maxi;
}

di tab_elems(vi& arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1));
    vvvi prev(K + 1, vvi(n + 1));

    for (int k = 0; k <= K; ++k) {
        dp[k][1] = arr[0];
    }
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = max(dp[0][i - 1] + arr[i - 1], arr[i - 1]);
        if (dp[0][i] == dp[0][i - 1] + arr[i - 1]) {
            prev[0][i] = {0, i - 1, 1};
        }
        else {
            prev[0][i] = {0, i - 1, 2};
        }
    }
    for (int k = 1; k <= K; ++k) {
        for (int i = 2; i <= n; ++i) {
            dp[k][i] = max({dp[k][i - 1] + arr[i - 1],
                            arr[i - 1],
                            dp[k - 1][i - 1]});
            if (dp[k][i] == dp[k][i - 1] + arr[i - 1]) {
                prev[k][i] = {k, i - 1, 1};
            }
            else if (dp[k][i] == dp[k - 1][i - 1]) {
                prev[k][i] = {k - 1, i - 1, 0};
            }
            else if (dp[k][i] == arr[i - 1]) {
                prev[k][i] = {0, i - 1, 2};
            }
        }
    }
    int maxpos = 0, maxi = -INF;
    for (int i = 0; i <= n; ++i) {
        if (dp[K][i] > maxi) {
            maxi = dp[K][i];
            maxpos = i;
        }
    }
    di elems;
    for (vi at = prev[K][maxpos]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            elems.push_front(arr[at[1]]);
        }
        else if (at[2] == 2) {
            elems.push_front(arr[at[1]]);
            break;
        }
    }
    return elems;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3, -4, 5}; // 11
    vi arr2 = {-2, -3, 4, -1, -2, 1, 5, -3}; // 9
    vi arr3 = {-2, -3, 4, -1, -2, 1, 5, -3}; // 10
    cout << tab(arr1, 1) << '\n';
    cout << tab(arr2, 1) << '\n';
    cout << tab(arr3, 2) << '\n';
    cout << '\n';
    cout << tab_elems(arr1, 1) << '\n';
    cout << tab_elems(arr2, 1) << '\n';
    cout << tab_elems(arr3, 2) << '\n';
}
