#include "../../template.hpp"

int MaxSumOfTwoNumbers(vi arr) {
    if (arr.size() < 2) return arr[0];
    sort(arr);
    int n = arr.size(), a = arr[n - 1], b = arr[n - 2];
    for (int i = n - 3; i >= 0; i -= 2) {
        a = a * 10 + arr[i];
        if (i - 1 >= 0) {
            b = b * 10 + arr[i - 1];
        }
    }
    return a + b;
}

int MinSumOfTwoNumbers(vi arr) {
    if (arr.size() < 2) return arr[0];
    sort(arr);
    int n = arr.size(), a = arr[0], b = arr[1];
    for (int i = 2; i < n; i += 2) {
        a = a * 10 + arr[i];
        if (i + 1 < n) {
            b = b * 10 + arr[i + 1];
        }
    }
    return a + b;
}

int main() { TimeMeasure _;
    vi arr1 = {6, 8, 4, 5, 2, 3};
    vi arr2 = {5, 3, 0, 7, 4};

    cout << MinSumOfTwoNumbers(arr1) << '\n'; // 604
    cout << MinSumOfTwoNumbers(arr2) << '\n'; // 82

    cout << MaxSumOfTwoNumbers(arr1) << '\n'; // 604
    cout << MaxSumOfTwoNumbers(arr2) << '\n'; // 82
}
