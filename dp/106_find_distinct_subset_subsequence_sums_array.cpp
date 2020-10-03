#include "../template.hpp"

void naive(vi& arr, si& elems, vi& current, int from) {
    int n = arr.size();
    if (from >= n) {
        int sum = 0;
        for (int value : current) {
            sum += value;
        }
        elems.insert(sum);
        return;
    }
    for (int i = from; i < n; ++i) {
        naive(arr, elems, current, i + 1);

        current.push_back(arr[i]);
        naive(arr, elems, current, i + 1);
        current.pop_back();
    }
}

si naive(vi& arr) {
    vi current;
    si elems;
    naive(arr, elems, current, 0);
    return elems;
}

vi tab(vi& arr) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    vvi dp(total + 1, vi(n + 1));
    vi res;
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = true;
    }
    res.push_back(0);
    for (int i = 1; i <= total; ++i) {
        bool can = false;
        for (int j = 1; j <= n; ++j) {
            if (i >= arr[j - 1]) {
                dp[i][j] = dp[i - arr[j - 1]][j - 1];
            }
            dp[i][j] = dp[i][j] or dp[i][j - 1];
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
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    vvb dp(total + 1, vb(n + 1));
    vi can(total + 1);
    vvvi prev(total + 1, vvi(n + 1));
    vi res;
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = true;
    }
    can[0] = true;
    res.push_back(0);
    for (int i = 1; i <= total; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= arr[j - 1]) {
                dp[i][j] = dp[i - arr[j - 1]][j - 1];
                if (dp[i - arr[j - 1]][j - 1]) {
                    prev[i][j] = {i - arr[j - 1], j - 1, 1};
                }
            }
            if (not dp[i][j] and dp[i][j - 1]) {
                prev[i][j] = {i, j - 1, 0};
            }
            dp[i][j] = dp[i][j] or dp[i][j - 1];
            if (dp[i][j]) {
                can[i] = j;
            }
        }
        if (can[i]) {
            res.push_back(i);
        }
    }
    for (int sum = 0; sum <= total; ++sum) {
        if (can[sum]) {
            if (sum == 0) {
                cout << sum;
            }
            int i = can[sum];
            for (vi at=prev[sum][i];not at.empty();at=prev[at[0]][at[1]]){
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
    cout << naive(arr1) << endl;
    cout << naive(arr2) << endl;
    cout << naive(arr3) << endl;
    cout << endl;
    cout << tab(arr1) << endl << '\n';
    cout << tab(arr2) << endl << '\n';
    cout << tab(arr3) << endl << '\n';
    cout << endl;
    cout << tab_elems(arr1) << endl << '\n';
    cout << tab_elems(arr2) << endl << '\n';
    cout << tab_elems(arr3) << endl << '\n';
}
