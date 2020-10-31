#include "../../template.hpp"

int FindRotationCount(vi arr) {
    int n = arr.size();
    int high = -1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            high = i  - 1;
        }
    }
    if (high == -1) {
        return 0;
    }
    return high + 1;
}

int main() { TimeMeasure _;
    vi arr1 = {15, 18, 2, 3, 6, 12}; // 2
    vi arr2 = {7, 9, 11, 12, 5}; // 4
    vi arr3 = {7, 9, 11, 12, 15}; // 0
    cout << FindRotationCount(arr1) << '\n';
    cout << FindRotationCount(arr2) << '\n';
    cout << FindRotationCount(arr3) << '\n';
}
