#include "../template.hpp"

bool isIncreasing(const vi& arr) {
    if (arr.empty()) return false;
    for (int i = 0; i + 1 < arr.size(); ++i) {
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void naive(vi& arr, set<vi>& res, vi& elems, int from) {
    if (from >= arr.size()) {
        if (isIncreasing(elems)) {
            // we need to count positions also for [2, 4, 4]: (2,4)(2,4)
            res.insert(elems);
        }
        return;
    }
    for (int i = from; i < arr.size(); ++i) {
        naive(arr, res, elems, i + 1);
        elems.push_back(arr[i]);
        naive(arr, res, elems, i + 1);
        elems.pop_back();
    }
}

int naive(vi& arr) {
    set<vi> res;
    vi elems;
    naive(arr, res, elems, 0);
    return res.size();
}

int tab(vi& arr) {
    int n = arr.size();
    vvi dp(n, vi(n));
    int sum = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (k == 0) {
                dp[k][i] = 1;
            }
            else {
                for (int j = 0; j < i; ++j) {
                    if (arr[i] > arr[j]) {
                        dp[k][i] += dp[k - 1][j];
                    }
                }
            }
            sum += dp[k][i];
        }
    }
    return sum;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3, 4};
    vi arr2 = {4, 3, 6, 5};
    vi arr3 = {3, 2, 4, 5, 4};
    cout << naive(arr1) << endl;
    cout << naive(arr2) << endl;
    cout << naive(arr3) << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
}
