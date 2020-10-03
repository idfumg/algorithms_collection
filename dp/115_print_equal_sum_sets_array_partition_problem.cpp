#include "../template.hpp"

int FindSum(vi& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    int sum = total / 2;
    if (total != sum * 2) {
        cout << '[' << ']' << '\n';
        return -1;
    }
    return sum;
}

void rec(vi& arr, vi& elems, int sum, int n, vvb& dp) {
    if (sum == 0) {
        cout << '[' << ' ' << elems << ']' << ' ';
        return;
    }
    if (n <= 0 or sum < 0) {
        return;
    }
    if (dp[sum][n - 1]) {
        rec(arr, elems, sum, n - 1, dp);
    }
    if (sum >= arr[n - 1] and dp[sum - arr[n - 1]][n - 1]) {
        elems.push_back(arr[n - 1]);
        rec(arr, elems, sum - arr[n - 1], n - 1, dp);
        elems.pop_back();
    }
}

int rec(vi& arr) {
    int sum = FindSum(arr);
    if (sum == -1) return -1;
    int n = arr.size();
    vvb dp(sum + 1, vb(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = true;
            }
            else if (j == 0) {
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (i >= arr[j - 1]) dp[i][j] = dp[i][j] or dp[i - arr[j - 1]][j - 1];
            }
        }
    }
    vi elems;
    rec(arr, elems, sum, n, dp);
    cout << '\n';
    return 1;
}

void PrintPaths(const vvvvi& prev, const int sum, const int n, vi& elems, vi& arr){
    if (sum <= 0 or n <= 0) {
        cout << '[' << ' ' << elems << ']' << ' ';
        return;
    }
    for (vi at : prev[sum][n]) {
        if (at[2] == 1) {
            elems.push_back(arr[n - 1]);
        }
        PrintPaths(prev, at[0], at[1], elems, arr);
        if (at[2] == 1) {
            elems.pop_back();
        }
    }
}

int tab(vi& arr) {
    int sum = FindSum(arr);
    if (sum == -1) return -1;
    int n = arr.size();
    vvb dp(sum + 1, vb(n + 1)); // dp[i][j] when sum is i and count of elems is j
    vvvvi prev(sum + 1, vvvi(n + 1));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = true;
            }
            else if (j == 0) {
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (dp[i][j - 1]) {
                    prev[i][j].push_back(vi{i, j - 1, 0});
                }
                if (i >= arr[j - 1]) {
                    dp[i][j] = dp[i][j] or dp[i - arr[j - 1]][j - 1];
                    if (dp[i - arr[j - 1]][j - 1]) {
                        prev[i][j].push_back(vi{i - arr[j - 1], j - 1, 1});
                    }
                }
            }
        }
    }
    vi elems;
    PrintPaths(prev, sum, n, elems, arr);
    cout << '\n';
    return dp[sum][n];
}

int tab2(vi& arr) {
    int n = arr.size();
    int sum = FindSum(arr);
    if (sum == -1) return -1;
    vvi dp(sum + 1, vi(n + 1));
    vvvi prev(sum + 1, vvi(n + 1));
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j - 1]) {
                dp[i][j] = 1;
                prev[i][j] = {i, j - 1, 0};
            }
            if (i >= arr[j - 1] and dp[i - arr[j - 1]][j - 1]) {
                dp[i][j] = 1;
                prev[i][j] = {i - arr[j - 1], j - 1, 1};
            }
        }
    }
    vb elems(n);
    for (vi at = prev[sum][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            elems[at[1]] = true;
        }
    }
    cout << '[' << ' ';
    for (int i = 0; i < n; ++i) {
        if (elems[i]) {
            cout << arr[i] << ' ';
        }
    }
    cout << ']' << ' ' << '[' << ' ';
    for (int i = 0; i < n; ++i) {
        if (not elems[i]) {
            cout << arr[i] << ' ';
        }
    }
    cout << ']' << ' ' << '\n';
    return dp[sum][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {5, 5, 1, 11};
    vi arr2 = {1, 5, 3};
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << endl;
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
}
