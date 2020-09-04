#include "../template.hpp"

void naive(const vi& arr, const int k,const int from,vi& elems, set<vi>&reselems) {
    if (from >= arr.size()) {
        reselems.insert(elems);
        return;
    }
    for (int i = from; i < arr.size(); ++i) {
        naive(arr, k, i + 1, elems, reselems);
        elems.push_back(arr[i]);
        naive(arr, k, i + 1, elems, reselems);
        elems.pop_back();
    }
}

int naive(const vi& arr, const int k) {
    vi elems;
    set<vi> reselems;
    naive(arr, k, 0, elems, reselems);
    int res = 0;
    for (const auto& elems : reselems) {
        int K = k;
        for (const int elem : elems) {
            K = K ^ elem;
        }
        if (K == 0) {
            ++res;
        }
    }
    return res;
}

int rec(vi& arr, int k, int n) {
    if (k == 0 and n == 0) return 1;
    if (n == 0) return 0;
    if (k == 0) return 1 + rec(arr, k ^ arr[n - 1], n - 1);

    const auto without = rec(arr, k, n - 1);
    const auto with = rec(arr, k ^ arr[n - 1], n - 1);
    return without + with;
}

int rec(vi& arr, int k) {
    return rec(arr, k, arr.size());
}

int tab(vi& arr, int K) {
    int n = arr.size(), maxelem = max(arr), maxxor=(1<<(int)(log2(maxelem)+1))-1;
    vvi dp(maxxor + 1, vi(n + 1));
    for (int k = 0; k <= maxxor; ++k) {
        for (int i = 0; i <= n; ++i) {
            if (k == 0 and i == 0) {
                dp[k][i] = 1;
            }
            else if (i == 0) {
                dp[k][i] = 0;
            }
            else if (k == 0) {
                dp[k][i] = 1;
                dp[k][i] += dp[k ^ arr[i - 1]][i - 1];
            }
            else {
                dp[k][i] = dp[k][i - 1];
                dp[k][i] += dp[k ^ arr[i - 1]][i - 1];
            }
        }
    }
    return dp[maxxor][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {6, 9, 4, 2}; int k1 = 6;
    vi arr2 = {1, 2, 3, 4, 5}; int k2 = 4;

    cout << naive(arr1, k1) << endl;
    cout << naive(arr2, k2) << endl;
    cout << rec(arr1, k1) << endl;
    cout << rec(arr2, k2) << endl;
    cout << tab(arr1, k1) << endl;
    cout << tab(arr2, k2) << endl;
}
