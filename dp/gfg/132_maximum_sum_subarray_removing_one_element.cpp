#include "../../template.hpp"

int rec(vi arr, int k, int n) {
    if (k < 0) return -INF;
    if (n == 0) return 0;
    return max({rec(arr, k, n - 1) + arr[n - 1], rec(arr, k - 1, n - 1), 0});
}

int rec(vi arr, int k) {
    int ans = 0, n = arr.size();
    for (int i = n; i >= 1; --i) {
        ans = max(ans, rec(arr, k, i));
    }
    return ans;
}

int rec_elems(vi arr, vvi dp, int k, int n, deque<int>& elems) {
    if (k < 0) return -INF;
    if (n == 0 or dp[k][n] == 0) return 0;
    if (k > 0 and dp[k][n - 1] + arr[n - 1] < dp[k - 1][n - 1]) {
        return rec_elems(arr, dp, k - 1, n - 1, elems);
    }
    elems.push_front(arr[n - 1]);
    return rec_elems(arr, dp, k, n - 1, elems) + arr[n - 1];
}

int rec_elems(vi arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1, -INF));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            if (i == 0) dp[k][i] = 0;
            else dp[k][i] = max({dp[k][i - 1] + arr[i - 1], k > 0 ? dp[k - 1][i - 1] : 0, 0});
        }
    }

    int ans = 0, idx = 0;
    for (int i = n; i >= 1; --i) {
        if (ans < dp[K][i]) {
            ans = dp[K][i];
            idx = i;
        }
    }

    deque<int> elems;
    rec_elems(arr, dp, K, idx, elems);
    cout << elems << ": ";
    return ans;
}

int tab(vi arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1, -INF));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            if (i == 0) dp[k][i] = 0;
            else dp[k][i] = max({dp[k][i - 1] + arr[i - 1], k > 0 ? dp[k - 1][i - 1] : 0, 0});
        }
    }

    int ans = 0;
    for (int i = n; i >= 1; --i) {
        ans = max(ans, dp[K][i]);
    }
    return ans;
}

int tab_elems(vi arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1, -INF));
    vvvi prev(K + 1, vvi(n + 1));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            if (i == 0) {
                dp[k][i] = 0;
            }
            else {
                dp[k][i] = max({dp[k][i - 1] + arr[i - 1], k > 0 ? dp[k - 1][i - 1] : 0, 0});

                if (dp[k][i] == 0) {
                    prev[k][i] = {-INF, -INF, -1};
                }
                else if (k > 0 and dp[k][i] == (k > 0 ? dp[k - 1][i - 1] : 0)) {
                    prev[k][i] = {k - 1, i - 1, 0};
                }
                else if (dp[k][i] == dp[k][i - 1] + arr[i - 1]) {
                    prev[k][i] = {k, i - 1, 1};
                }
            }
        }
    }

    int ans = 0, idx = 0;
    for (int i = n; i >= 1; --i) {
        if (ans < dp[K][i]) {
            ans = dp[K][i];
            idx = i;
        }
    }

    deque<int> elems;
    for (vi at = prev[K][idx]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == -1) break;
        else if (at[2] == 0) {}
        else if (at[2] == 1) elems.push_front(arr[at[1]]);
    }
    cout << elems << ": ";

    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3, -4, 5};
    vi arr2 = {-2, -3, 4, -1, -2, 1, 5, -3};
    vi arr3 = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << rec(arr1, 0) << '\n'; // 7
    cout << rec(arr1, 1) << '\n'; // 11
    cout << rec(arr2, 1) << '\n'; // 9
    cout << rec(arr3, 2) << '\n'; // 10
    cout << '\n';
    cout << rec_elems(arr1, 0) << '\n';
    cout << rec_elems(arr1, 1) << '\n';
    cout << rec_elems(arr2, 1) << '\n';
    cout << rec_elems(arr3, 2) << '\n';
    cout << '\n';
    cout << tab(arr1, 0) << '\n';
    cout << tab(arr1, 1) << '\n';
    cout << tab(arr2, 1) << '\n';
    cout << tab(arr3, 2) << '\n';
    cout << '\n';
    cout << tab_elems(arr1, 0) << '\n';
    cout << tab_elems(arr1, 1) << '\n';
    cout << tab_elems(arr2, 1) << '\n';
    cout << tab_elems(arr3, 2) << '\n';
}
