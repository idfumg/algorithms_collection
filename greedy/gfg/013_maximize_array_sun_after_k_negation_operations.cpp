#include "../../template.hpp"

int MaximizeArraySum(vi arr, int k) {
    int n = arr.size();
    int ans = 0;
    sort(arr.begin(), arr.end());
    int i = 0;
    int lastNegative = -1;
    while (i < n and arr[i] < 0) {
        arr[i] *= -1;
        ++i;
        --k;
        lastNegative = i;
    }
    if (arr[i] == 0) {
        k = 0;
    }
    else if (k % 2 == 0) {
        k = 0;
    }
    else {
        if (lastNegative != -1 and arr[lastNegative] < arr[i]) {
            arr[lastNegative] *= -1;
        }
        else {
            arr[i] *= -1;
        }
    }
    return accumulate(arr.begin(), arr.end(), 0);
}

int main() { TimeMeasure _;
    vi arr1 = {-2, 0, 5, -1, 2}; // 10
    vi arr2 = {9, 8, 8, 5}; // 20
    cout << MaximizeArraySum(arr1, 4) << '\n';
    cout << MaximizeArraySum(arr2, 3) << '\n';
}
