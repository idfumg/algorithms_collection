#include "../template.hpp"

int MaximumSumOfDifferences(vi arr) {
    sort(arr);
    int n = arr.size(), sum = 0;
    for (int i = 0, j = n - 1 - i; i <= j; ++i, --j) {
        if (i == j) {
            sum += abs(arr[j] - arr[0]);
            break;
        }
        sum += abs(arr[j] - arr[i]); // max with prev min
        if (j - i != 1) {
            sum += abs(arr[j] - arr[i + 1]); // max with next min
        }
        if (j - i == 1) { // last minimum of maximums with the 0 one
            sum += abs(arr[j] - arr[0]);
        }
    }
    return sum;
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
