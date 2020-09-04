#include "../../template.hpp"

int rec(vi& arr, vi& elems, vi& maxelems, int& maxsum, int length, int sum, int n) {
    if (length == 0) {
        if (sum > maxsum) {
            maxsum = sum;
            maxelems = elems;
        }
        return sum;
    }
    if (n < 0 or length < 0) return 0;
    const auto a = rec(arr, elems, maxelems, maxsum, length, sum, n - 1);

    elems.push_back(arr[n]);
    const auto b = rec(arr, elems, maxelems, maxsum, length - n - 1, sum + arr[n], n);
    elems.pop_back();
    return max(a, b);
}

int rec(vi& arr, int length) {
    vi elems, maxelems;
    int maxsum = 0;
    int res = rec(arr, elems, maxelems, maxsum, length, 0, arr.size() - 1);
    cout << maxelems;
    return res;
}

int tab(vi& arr, int length) {
    const auto n = arr.size();
    vvi dp(length + 1, vi(n + 1));
    vvpi prev(length + 1, vpi(n + 1));
    vvb used(length + 1, vb(n + 1));
    for (int i = 1; i <= length; ++i) {
        for (int j = 1; j <= n; ++j) {
            const auto a = dp[i][j - 1];
            if (i >= j) {
                const auto b = dp[i - j][j] + arr[j - 1];
                dp[i][j] = max(a, b);
                if (a > b) {
                    prev[i][j] = {i, j - 1};
                    used[i][j] = false;
                }
                else {
                    prev[i][j] = {i - j, j};
                    used[i][j] = true;
                }
            }
            else {
                dp[i][j] = a;
                prev[i][j] = {i, j - 1};
                used[i][j] = false;
            }
        }
    }
    auto at = pair<int, int>(length, n);
    for (; at.first != 0 and at.second != 0; at = prev[at.first][at.second]) {
        if (used[at.first][at.second]) {
            cout << arr[at.second - 1] << ' ';
        }
    }
    cout << endl;
    return dp[length][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1,  5,  8,  9, 10, 17, 17, 20};
    vi arr2 = {3,  5,  8,  9, 10, 17, 17, 20};
    cout << rec(arr1, arr1.size()) << endl;
    cout << rec(arr2, arr2.size()) << endl;
    cout << tab(arr1, arr1.size()) << endl;
    cout << tab(arr2, arr2.size()) << endl;
}
