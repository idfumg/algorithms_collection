#include "../../template.hpp"

int rec(vi arr, int k, int n, int total) {
    if (k < 0) return -INF;
    if (n == 0) return total;
    return max({
            rec(arr, k, n - 1, 0),
            rec(arr, k, n - 1, total + arr[n - 1]),
            rec(arr, k - 1, n - 1, total),
            total});
}

int rec(vi arr, int k) {
    return rec(arr, k, arr.size(), 0);
}

int rec2(vi arr, int k, int n) {
    if (k < 0) return -INF;
    if (n == 0) return 0;
    return max({
            rec2(arr, k, n - 1) + arr[n - 1],
            arr[n - 1],
            rec2(arr, k - 1, n - 1)});
}

int rec2(vi arr, int k) {
    int ans = -INF;
    int n = arr.size();
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, rec2(arr, k, i));
    }
    return ans;
}

int tab_logn(vi arr, int K) {
    int n = arr.size();
    int maxi = -INF, maxipos = 0;
    vi dp = arr;
    vi prev(n, -1);
    for (int i = 1; i < n; ++i) {
        if (dp[i - 1] + arr[i] > dp[i]) {
            dp[i] = dp[i - 1] + arr[i];
            prev[i] = i - 1;
        }
        if (maxi < dp[i]) {
            maxi = dp[i];
            maxipos = i;
        }
    }

    int to = maxipos;
    int from = maxipos;
    for (; prev[from] != -1; from = prev[from]) {}

    if (from == to) {
        return maxi;
    }

    sort(arr.begin() + from, arr.begin() + to);
    while (K-- > 0 and from < to and arr[from] < 0) {
        maxi -= arr[from++];
    }

    return maxi;
}

int tab_logn_elems(vi arr, int K) {
    int n = arr.size();
    int maxi = -INF, maxipos = 0;
    vi dp = arr;
    vi prev(n, -1);
    for (int i = 1; i < n; ++i) {
        if (dp[i - 1] + arr[i] > dp[i]) {
            dp[i] = dp[i - 1] + arr[i];
            prev[i] = i - 1;
        }
        if (maxi < dp[i]) {
            maxi = dp[i];
            maxipos = i;
        }
    }

    int to = maxipos;
    int from = maxipos;
    for (; prev[from] != -1; from = prev[from]) {}

    if (from == to) {
        return maxi;
    }

    vi idxes(n);
    iota(idxes.begin(), idxes.end(), 0);
    sort(idxes.begin() + from, idxes.begin() + to, [&](int i, int j){return arr[i] < arr[j];});
    unordered_set<int> skip;
    vi elems;
    for (int i = from; i < to and K > 0; ++i) {
        int idx = idxes[i];
        if (arr[idx] < 0 and K-- > 0) {
            skip.insert(idx);
        }
    }

    int ans = 0;
    for (int i = from; i <= to; ++i) {
        if (skip.count(i)) continue;
        ans += arr[i];
        elems.push_back(arr[i]);
    }
    debugn(elems);

    return ans;
}

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

deque<int> tab_elems(vi& arr, int K) {
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
    deque<int> elems;
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

int tab2(vi arr, int K) {
    int n = arr.size();
    int ans = 0;
    vvvi dp(K + 1, vvi(n + 2, vi(n + 2)));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) dp[0][i][j] = arr[i - 1];
            else if (j - i == 1) dp[0][i][j] = arr[i - 1] + arr[j - 1];
            else dp[0][i][j] = dp[0][i][j - 1] + arr[j - 1];
            ans = max(ans, dp[0][i][j]);
        }
    }
    vector<vector<vector<si>>> used(K + 1, vector<vector<si>>(n + 2, vector<si>(n + 2)));
    for (int k = 1; k <= K; ++k) {
        for (int i = n; i >= 1; --i) {
            for (int j = 1; j <= n; ++j) {
                for (int p = i; p <= j; ++p) {
                    if (dp[k - 1][i][j] - arr[p - 1] > dp[k - 1][i][j]) {
                        if (not used[k - 1][i][j].count(p)) {
                            dp[k][i][j] = dp[k - 1][i][j] - arr[p - 1];
                            used[k][i][j] = used[k - 1][i][j];
                            used[k][i][j].insert(p);
                        }
                    }
                }
                if (used[k][i][j].empty()) {
                    used[k][i][j] = used[k - 1][i][j];
                }
                ans = max(ans, dp[k][i][j]);
            }
        }
    }
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
    cout << rec2(arr1, 0) << '\n'; // 7
    cout << rec2(arr1, 1) << '\n'; // 11
    cout << rec2(arr2, 1) << '\n'; // 9
    cout << rec2(arr3, 2) << '\n'; // 10
    cout << '\n';
    cout << tab_logn(arr1, 0) << '\n';
    cout << tab_logn(arr1, 1) << '\n';
    cout << tab_logn(arr2, 1) << '\n';
    cout << tab_logn(arr3, 2) << '\n';
    cout << '\n';
    cout << tab_logn_elems(arr1, 0) << '\n';
    cout << tab_logn_elems(arr1, 1) << '\n';
    cout << tab_logn_elems(arr2, 1) << '\n';
    cout << tab_logn_elems(arr3, 2) << '\n';
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
    cout << '\n';
    cout << tab2(arr1, 0) << '\n';
    cout << tab2(arr1, 1) << '\n';
    cout << tab2(arr2, 1) << '\n';
    cout << tab2(arr3, 2) << '\n';
}
