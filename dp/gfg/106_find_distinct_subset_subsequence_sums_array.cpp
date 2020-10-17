#include "../../template.hpp"

void naive(vi& arr, si& res, vi& elems, int from) {
    int n = arr.size();
    if (from == n) {
        int sum = accumulate(elems.begin(), elems.end(), 0);
        res.insert(sum);
        return;
    }
    for (int i = from; i < n; ++i) {
        naive(arr, res, elems, i + 1);
        elems.push_back(arr[i]);
        naive(arr, res, elems, i + 1);
        elems.pop_back();
    }
}

si naive(vi& arr) {
    si res;
    vi elems;
    naive(arr, res, elems, 0);
    return res;
}

// Can we make some sum with or without an element [sum][element]
vi tab(vi& arr) {
    vi res;
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vvb dp(sum + 1, vb(n + 1));
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = true;
    }
    res.push_back(0);
    for (int i = 1; i <= sum; ++i) {
        bool wecan = false;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1]) {
                dp[i][j] = dp[i][j] or dp[i - arr[j - 1]][j - 1];
            }
            wecan = wecan or dp[i][j];
        }
        if (wecan) res.push_back(i);
    }
    return res;
}

// Print such elements
vi tab_elems(vi& arr) {
    vi res;
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vvb dp(sum + 1, vb(n + 1));
    vvvi prev(sum + 1, vvi(n + 1));
    vb wecan(sum + 1);
    vi fromwhere(sum + 1);
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = true;
    }
    wecan[0] = true;
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            prev[i][j] = {i, j - 1, 0};
            if (i >= arr[j - 1] and dp[i - arr[j - 1]][j - 1]) {
                dp[i][j] = true;
                prev[i][j] = {i - arr[j - 1], j - 1, 1};
                fromwhere[i] = j;
            }
            wecan[i] = wecan[i] or dp[i][j];
        }
        if (wecan[i]) res.push_back(i);
    }
    for (int i = 0; i <= sum; ++i) {
        if (wecan[i]) {
            cout << i << ':' << ' ';
            for (vi at = prev[i][fromwhere[i]]; not at.empty(); at = prev[at[0]][at[1]]) {
                if (at[2] == 1) {
                    cout << arr[at[1]] << ' ';
                }
            }
            cout << '\n';
        }
    }
    return res;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3};
    vi arr2 = {2, 3, 4, 5, 6};
    vi arr3 = {20, 30, 50};
    cout << naive(arr1) << '\n';
    cout << naive(arr2) << '\n';
    cout << naive(arr3) << '\n';
    cout << '\n';
    cout << tab(arr1) << '\n';
    cout << tab(arr2) << '\n';
    cout << tab(arr3) << '\n';
    cout << '\n';
    cout << tab_elems(arr1) << '\n';
    cout << tab_elems(arr2) << '\n';
    cout << tab_elems(arr3) << '\n';
}
