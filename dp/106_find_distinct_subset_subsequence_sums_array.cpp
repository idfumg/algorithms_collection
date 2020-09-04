#include "../template.hpp"

vi tab(vi& arr) {
    int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);
    vvb dp(sum + 1, vb(n + 1));
    dp[0][0] = true;
    vi res;
    for (int i = 0; i <= sum; ++i) {
        bool can = false;
        for (int j = 1; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = true;
                continue;
            }
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1] and not dp[i][j]) {
                dp[i][j] = dp[i - arr[j - 1]][j - 1];
            }
            if (dp[i][j]) {
                can = true;
            }
        }
        if (can) {
            res.push_back(i);
        }
    }
    return res;
}

vi tab_elems(vi& arr) {
    int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);
    vvb dp(sum + 1, vb(n + 1));
    dp[0][0] = true;
    vi can(sum + 1, -1);
    vvvi prev(sum + 1, vvi(n + 1));
    vi res;
    for (int i = 0; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = true;
                continue;
            }
            if (i >= arr[j - 1] and not dp[i][j]) {
                dp[i][j] = dp[i - arr[j - 1]][j - 1];
                prev[i][j] = {i - arr[j - 1], j - 1, 1};
            }
            if (not dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                prev[i][j] = {i, j - 1, 0};
            }
            if (dp[i][j]) {
                can[i] = j;
            }
        }
        if (can[i] != -1) {
            res.push_back(i);
        }
    }
    vvi elems;
    for (int i = 0; i <= sum; ++i) {
        if (can[i] != -1) {
            elems.push_back({});
            for (vi at = prev[i][can[i]]; not at.empty(); at = prev[at[0]][at[1]]){
                if (at[2] == 1) {
                    elems.back().push_back(arr[at[1]]);
                }
            }
        }
    }
    debug(elems);
    return res;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3};
    vi arr2 = {2, 3, 4, 5, 6};
    vi arr3 = {20, 30, 50};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab_elems(arr1) << endl;
    cout << tab_elems(arr2) << endl;
    cout << tab_elems(arr3) << endl;
}
