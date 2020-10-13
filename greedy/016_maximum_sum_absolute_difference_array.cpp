#include "../template.hpp"

int MaximumSumOfDifferences(vi arr) {
    int n = arr.size(), ans = 0;
    sort(arr);
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
        if (i == j) {
            ans += arr[j] - arr[0];
        }
        else {
            ans += arr[j] - arr[i];
            if (j - i == 1) {
                ans += arr[j] - arr[0];
                break;
            }
            else if (i + 1 < j) {
                ans += arr[j] - arr[i + 1];
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    vi arr1 = { 4, 2, 1, 8 };
    vi arr2 = { 1, 2, 4, 8, 10 };
    vi arr3 = { 10, 12, 15 };
    vi arr4 = { 4, 10, 6, 1, 8 };

    cout << MaximumSumOfDifferences(arr1) << '\n'; // 18 | {1, 8, 2, 4}
    cout << MaximumSumOfDifferences(arr2) << '\n'; // 30 | {1, 10, 2, 8, 4}
    cout << MaximumSumOfDifferences(arr3) << '\n'; // 10 | {10, 15, 12}
    cout << MaximumSumOfDifferences(arr4) << '\n'; // 26
}
