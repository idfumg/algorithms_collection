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

int MinimumProductSubset2(vi& arr) { // O(n)
    int n = arr.size(), negatives = 0, positives = 0, zeroes = 0, minPositive = INF, minNegative = INF, prod = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            ++negatives;
            minNegative = min(minNegative, arr[i]);
            prod *= arr[i];
        }
        else if (arr[i] == 0) {
            ++zeroes;
        }
        else if (arr[i] > 0) {
            minPositive = min(minPositive, arr[i]);
            ++positives;
            prod *= arr[i];
        }
    }
    if (n == 0) return 0;
    if (zeroes == n) return 0;
    if (negatives == 0) return minPositive;
    if (negatives % 2 == 0) return prod / minNegative;
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

int main() { TimeMeasure _;
    vi arr1 = { -1, -1, -2, 4, 3 };
    vi arr2 = { -1, 0 };
    vi arr3 = { 0, 0, 0 };

    cout << MinimumProductSubset(arr1) << '\n';
    cout << MinimumProductSubset(arr2) << '\n';
    cout << MinimumProductSubset(arr3) << '\n';
    cout << '\n';
    cout << MinimumProductSubset2(arr1) << '\n';
    cout << MinimumProductSubset2(arr2) << '\n';
    cout << MinimumProductSubset2(arr3) << '\n';
    cout << '\n';
    cout << MinimumProductSubset3(arr1) << '\n';
    cout << MinimumProductSubset3(arr2) << '\n';
    cout << MinimumProductSubset3(arr3) << '\n';
}
