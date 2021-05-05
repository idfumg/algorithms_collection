#include "../../template.hpp"

int MaximumProductSubset(vi arr) {
    int n = arr.size();
    if (n == 0) return 0;
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

int MaximumProductSubset2(vi arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    int n = arr.size();
    if (n == 0) return 0;

    int ans = 1;
    int i = 0;
    while (i < n and arr[i] > 0) {
        ans *= arr[i++];
    }

    while (i < n and arr[i] == 0) {
        ++i;
    }

    i = n - 1;
    while (i >= 0 and arr[i] < 0) {
        ans *= arr[i--];
    }

    if (ans < 0 and i < n - 1) {
        ans /= arr[i + 1];
    }

    return arr[0] > 0 ? ans : arr[0];
}

int main() { TimeMeasure _;
    vi arr1 = { -1, -1, -2, 4, 3 }; // 24
    vi arr2 = { -1, 0 }; // 0
    vi arr3 = { 0, 0, 0 }; // 0
    cout << MaximumProductSubset(arr1) << '\n';
    cout << MaximumProductSubset(arr2) << '\n';
    cout << MaximumProductSubset(arr3) << '\n';
    cout << endl;
    cout << MaximumProductSubset2(arr1) << '\n';
    cout << MaximumProductSubset2(arr2) << '\n';
    cout << MaximumProductSubset2(arr3) << '\n';
}
