#include "../template.hpp"

int MaximumProductSubset(vi& arr) {
    int n = arr.size(), negatives = 0, positives = 0, zeroes = 0, maxNegative = -INF, prod = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            maxNegative = max(maxNegative, arr[i]);
            ++negatives;
            prod *= arr[i];
        }
        else if (arr[i] == 0) {
            ++zeroes;
        }
        else if (arr[i] > 0) {
            ++positives;
            prod *= arr[i];
        }
    }
    if (n == 0) return 0;
    if (zeroes == n) return 0;
    if (positives == 0 and zeroes == 0) return maxNegative;
    if (positives == 0 and zeroes > 0) return 0;
    if (prod > 0) return prod;
    if (negatives & 1) return prod / maxNegative;
    return prod;
}

int main() { TimeMeasure _;
    vi arr1 = { -1, -1, -2, 4, 3 };
    vi arr2 = { -1, 0 };
    vi arr3 = { 0, 0, 0 };
    cout << MaximumProductSubset(arr1) << '\n';
    cout << MaximumProductSubset(arr2) << '\n';
    cout << MaximumProductSubset(arr3) << '\n';
}
