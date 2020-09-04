#include "../../template.hpp"

void get_subsequences_helper(vi& arr, set<vi>& res, vi& elems, int from) {
    if (from >= arr.size()) {
        res.insert(elems);
        return;
    }
    for (int i = from; i < arr.size(); ++i) {
        get_subsequences_helper(arr, res, elems, i + 1);
        elems.push_back(arr[i]);
        get_subsequences_helper(arr, res, elems, i + 1);
        elems.pop_back();
    }
}

set<vi> get_subsequences(vi& arr, int from) {
    set<vi> res;
    vi elems;
    get_subsequences_helper(arr, res, elems, from);
    return res;
}

int minimal_distance(const vi& arr1, const vi& arr2) {
    const int m = arr1.size();
    const int n = arr2.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j - 1] + 1});
            }
        }
    }
    return dp[m][n];
}

int naive(vi& arr1, vi& arr2, int k) {
    const auto seqs1 = get_subsequences(arr1, 0);
    const auto seqs2 = get_subsequences(arr2, 0);
    int longest = 0;
    for (const auto& seq1 : seqs1) {
        for (const auto& seq2 : seqs2) {
            if (minimal_distance(seq1, seq2) == k) {
                if (seq1.size() > longest) {
                    longest = seq1.size();
                }
            }
        }
    }
    return longest;
}

int rec(vi& arr1, vi& arr2, int k, int m, int n) {
    if (k < 0) return -INF;
    if (m < 0 || n < 0) return 0;

    if (arr1[m] == arr2[n]) {
        return rec(arr1, arr2, k, m - 1, n - 1) + 1;
    }

    return max({rec(arr1, arr2, k, m - 1, n),
                rec(arr1, arr2, k, m, n - 1),
                rec(arr1, arr2, k - 1, m - 1, n - 1) + 1});
}

int rec(vi& arr1, vi& arr2, int k) {
    return rec(arr1, arr2, k, arr1.size() - 1, arr2.size() - 1);
}

int tab(vi& a, vi& b, int K) {
    int m = a.size(), n = b.size();
    vvvi dp(K + 2, vvi(m + 1, vi(n + 1)));
    for (int k = 0; k <= K + 1; ++k) {
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (k == 0) {
                    dp[k][i][j] = -INF;
                }
                else if (i == 0 or j == 0) {
                    dp[k][i][j] = 0;
                }
                else if (a[i - 1] == b[j - 1]) {
                    dp[k][i][j] = 1 + dp[k][i - 1][j - 1];
                }
                else {
                    dp[k][i][j] = max({dp[k][i - 1][j],
                                       dp[k][i][j - 1],
                                       1 + dp[k - 1][i - 1][j - 1]});
                }
            }
        }
    }
    return dp[K + 1][m][n];
}

vi tab_elems(vi& a, vi& b, int K) {
    int m = a.size(), n = b.size();
    vvvi dp(K + 2, vvi(m + 1, vi(n + 1)));
    vvvvi prev(K + 2, vvvi(m + 1, vvi(n + 1)));
    for (int k = 1; k <= K + 1; ++k) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[k][i][j] = 1 + dp[k][i - 1][j - 1];
                    prev[k][i][j] = {k, i - 1, j - 1, 1};
                }
                else {
                    dp[k][i][j] = max({dp[k][i - 1][j],
                                       dp[k][i][j - 1],
                                       1 + dp[k - 1][i - 1][j - 1]});
                    if (dp[k][i][j] == 1 + dp[k - 1][i - 1][j - 1]) {
                        prev[k][i][j] = {k - 1, i - 1, j - 1, 2};
                    }
                    else if (dp[k][i][j] == dp[k][i][j - 1]) {
                        prev[k][i][j] = {k, i, j - 1, 0};
                    }
                    else {
                        prev[k][i][j] = {k, i - 1, j, 0};
                    }
                }
            }
        }
    }
    vi elems;
    for (vi at = prev[K][m][n]; not at.empty(); at = prev[at[0]][at[1]][at[2]]) {
        if (at[3] == 2) {
            elems.push_back(a[at[1]]);
        }
    }
    return elems;
}

int main() { TimeMeasure _; __x();
    vi arr11 = {8, 3}, arr12 = {1, 3}; int k1 = 1;
    vi arr21 = {1, 2, 3, 4, 5}, arr22 = {5, 3, 1, 4, 2}; int k2 = 1;
    vi arr31 = {1, 2, 3, 4}, arr32 = {5, 1, 2, 3, 8}; int k3 = 1;
    cout << naive(arr11, arr12, k1) << endl; // 2
    cout << naive(arr21, arr22, k2) << endl; // 3
    cout << naive(arr31, arr32, k3) << endl; // 4

    cout << rec(arr11, arr12, k1) << endl; // 2
    cout << rec(arr21, arr22, k2) << endl; // 3
    cout << rec(arr31, arr32, k3) << endl; // 4

    cout << tab(arr11, arr12, k1) << endl; // 2
    cout << tab(arr21, arr22, k2) << endl; // 3
    cout << tab(arr31, arr32, k3) << endl; // 4
}
