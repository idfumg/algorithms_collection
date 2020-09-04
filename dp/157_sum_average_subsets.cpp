#include "../../template.hpp"

void naive(vi& arr, vi& elems, set<vi>& sets, int from) {
    int n = arr.size();
    if (from == n) {
        if (not elems.empty()) {
            sets.insert(elems);
        }
        return;
    }
    for (int i = from; i < n; ++i) {
        naive(arr, elems, sets, i + 1);
        elems.push_back(arr[i]);
        naive(arr, elems, sets, i + 1);
        elems.pop_back();
    }
}

double naive(vi& arr) {
    vi elems;
    set<vi> sets;
    naive(arr, elems, sets, 0);
    double res = 0;
    for (const vi& els : sets) {
        res += accumulate(els.begin(), els.end(), 0) / static_cast<double>(els.size());
    }
    return res;
}

double tab(vi& arr) {
    int n = arr.size();
    double total = 0;
    vvd dp(n + 1, vd(n + 1));
    vvi counts(n + 1, vi(n + 1));
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (k == 1) {
                dp[k][i] = arr[i - 1];
                counts[k][i] = 1;
            }
            else {
                int count = 0;
                for (int j = 1; j < i; ++j) {
                    if (dp[k - 1][j] > 0) {
                        dp[k][i] += dp[k - 1][j];
                        count += counts[k - 1][j];
                    }
                }
                dp[k][i] *= k - 1;
                if (dp[k][i] > 0) {
                    dp[k][i] += arr[i - 1] * count;
                    dp[k][i] /= k;
                }
                counts[k][i] = count;
            }
            total += dp[k][i];
        }
    }
    return total;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 3, 5};
    vi arr2 = {2, 3, 5, 7};
    cout << naive(arr1) << endl;
    cout << naive(arr2) << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
