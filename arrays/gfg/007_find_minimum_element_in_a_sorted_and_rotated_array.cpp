#include "../../template.hpp"

int FindMinimumInSortedAndRotated(vi arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return arr[i];
        }
    }
    return arr[0];
}

int FindMinimumInSortedAndRotated2(vi arr) {
    int n = arr.size(), low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= arr[0]) {
            if (arr[mid] >= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
        else {
            if (mid - 1 >= low and arr[mid - 1] <= arr[mid]) high = mid - 1;
            else return arr[mid];
        }
    }
    return arr[high];
}

int main() { TimeMeasure _;
    vi arr1 = {5, 6, 1, 2, 3, 4}; // 1
    vi arr2 = {1, 2, 3, 4}; // 1
    vi arr3 = {2, 1}; // 1
    vi arr4 = {1}; // 1
    vi arr5 = {5, 6, 7, 1, 2, 3, 4}; // 1
    vi arr6 = {2, 3, 4, 5, 6, 7, 8, 1}; // 1
    vi arr7 = {3, 4, 5, 1, 2}; // 1
    vi arr8 = {4, 5, 1, 2, 3}; // 1

    cout << FindMinimumInSortedAndRotated(arr1) << '\n'; // O(n)
    cout << FindMinimumInSortedAndRotated(arr2) << '\n';
    cout << FindMinimumInSortedAndRotated(arr3) << '\n';
    cout << FindMinimumInSortedAndRotated(arr4) << '\n';
    cout << FindMinimumInSortedAndRotated(arr5) << '\n';
    cout << FindMinimumInSortedAndRotated(arr6) << '\n';
    cout << FindMinimumInSortedAndRotated(arr7) << '\n';
    cout << FindMinimumInSortedAndRotated(arr8) << '\n';
    cout << '\n';
    cout << FindMinimumInSortedAndRotated2(arr1) << '\n'; // O(logn)
    cout << FindMinimumInSortedAndRotated2(arr2) << '\n';
    cout << FindMinimumInSortedAndRotated2(arr3) << '\n';
    cout << FindMinimumInSortedAndRotated2(arr4) << '\n';
    cout << FindMinimumInSortedAndRotated2(arr5) << '\n';
    cout << FindMinimumInSortedAndRotated2(arr6) << '\n';
    cout << FindMinimumInSortedAndRotated2(arr7) << '\n';
    cout << FindMinimumInSortedAndRotated2(arr8) << '\n';
}
