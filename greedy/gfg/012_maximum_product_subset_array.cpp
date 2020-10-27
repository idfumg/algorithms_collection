#include "../../template.hpp"

int MaximumProductSubset(vi arr) {
    int n = arr.size();
    if (n == 0) return -INF;
    int total = -INF;
    int maxNegative = -INF;
    int negatives = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            maxNegative = max(maxNegative, arr[i]);
            ++negatives;
        }
        if (arr[i] != 0) {
            total = total == -INF ? arr[i] : total * arr[i];
        }
    }
    if (total == -INF) return 0;
    if (total > 0) return total;
    if (negatives == 0 or negatives == 1) return 0;
    return total / maxNegative;
}

int main() { TimeMeasure _;
    vi arr1 = { -1, -1, -2, 4, 3 };
    vi arr2 = { -1, 0 };
    vi arr3 = { 0, 0, 0 };
    cout << MaximumProductSubset(arr1) << '\n';
    cout << MaximumProductSubset(arr2) << '\n';
    cout << MaximumProductSubset(arr3) << '\n';
}
