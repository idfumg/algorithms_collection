#include "../../template.hpp"

int MinimumProductSubset(vi& arr) { // O(nlogn)
    int n = arr.size();
    sort(arr);
    int negative = count_if(arr.begin(), arr.end(), [](int x){return x < 0;});
    if (n == 0) return 0;
    if (negative == 0) return arr[0];
    int prod = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            prod *= arr[i];
        }
    }
    if (negative % 2 == 0) return prod / arr[0];
    return prod;
}

int MinimumProductSubset3(vi arr) {
    int n = arr.size();
    int total = 0;
    int maxnegative = -INF;
    int minpositive = INF;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) maxnegative = max(maxnegative, arr[i]);
        else if (arr[i] >= 0) minpositive = min(minpositive, arr[i]);
        if (arr[i] != 0) total = total == 0 ? arr[i] : total * arr[i];
    }

    if (maxnegative == -INF) return minpositive;
    if (total > 0) return total / maxnegative;
    return total;
}

int MinimumProductSubset4(vi arr) {
    int n = arr.size();
    if (n == 0) {
        return -INF;
    }
    int negativesProd = INF;
    int positivesProd = -INF;
    int zeroesCount = 0;
    int maxNegative = -INF;
    int minPositive = INF;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            negativesProd = negativesProd == INF ? arr[i] : negativesProd * arr[i];
            maxNegative = max(maxNegative, arr[i]);
        }
        else if (arr[i] > 0) {
            positivesProd = positivesProd == -INF ? arr[i] : positivesProd * arr[i];
            minPositive = min(minPositive, arr[i]);
        }
        else {
            ++zeroesCount;
        }
    }
    if (negativesProd == INF and positivesProd == -INF) return 0;
    if (negativesProd == INF) return minPositive;
    if (positivesProd == -INF) return negativesProd;
    if (negativesProd > 0) negativesProd /= maxNegative;
    return negativesProd * positivesProd;
}

int MinimumProductSubset5(vi arr) {
    sort(arr.begin(), arr.end());

    if (arr[0] == 0 or arr[0] > 0) {
        return arr[0];
    }

    int ans = 1;
    int n = arr.size();
    int i = 0;

    while (i < n and arr[i] < 0) {
        ans *= arr[i++];
    }

    if (ans > 0 and i > 0) {
        ans *= arr[i - 1];
    }

    while (i < n and arr[i] == 0) {
        ++i;
    }

    while (i < n) {
        ans *= arr[i++];
    }

    return ans;
}


int main() { TimeMeasure _;
    vi arr1 = { -1, -1, -2, 4, 3 }; // -24
    vi arr2 = { -1, 0 }; // -1
    vi arr3 = { 0, 0, 0 }; // 0
    vi arr4 = { 1, 2, 3 }; // 1
    vi arr5 = { -1, -1, -1, -2, 4, 3 }; // -24

    cout << MinimumProductSubset(arr1) << '\n';
    cout << MinimumProductSubset(arr2) << '\n';
    cout << MinimumProductSubset(arr3) << '\n';
    cout << MinimumProductSubset(arr4) << '\n';
    cout << MinimumProductSubset(arr5) << '\n';
    cout << '\n';
    cout << MinimumProductSubset3(arr1) << '\n';
    cout << MinimumProductSubset3(arr2) << '\n';
    cout << MinimumProductSubset3(arr3) << '\n';
    cout << MinimumProductSubset3(arr4) << '\n';
    cout << MinimumProductSubset3(arr5) << '\n';
    cout << '\n';
    cout << MinimumProductSubset4(arr1) << '\n';
    cout << MinimumProductSubset4(arr2) << '\n';
    cout << MinimumProductSubset4(arr3) << '\n';
    cout << MinimumProductSubset4(arr4) << '\n';
    cout << MinimumProductSubset4(arr5) << '\n';
    cout << '\n';
    cout << MinimumProductSubset5(arr1) << '\n';
    cout << MinimumProductSubset5(arr2) << '\n';
    cout << MinimumProductSubset5(arr3) << '\n';
    cout << MinimumProductSubset5(arr4) << '\n';
    cout << MinimumProductSubset5(arr5) << '\n';
}
