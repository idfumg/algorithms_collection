#include "../../template.hpp"

int SearchInRotatedAndSorted(vi arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > arr[0] and target < arr[0]) low = mid + 1; // left side
        else if (arr[mid] < arr[0] and target >= arr[0]) high = mid - 1; // right side
        else if (arr[mid] < target) low = mid + 1;
        else if (arr[mid] > target) high = mid - 1;
    }
    return -1;
}

int main() { TimeMeasure _;
    vi arr1 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    vi arr2 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    vi arr3 = {30, 40, 50, 10, 20};
    vi arr4 = {10, 1, 2, 3, 5, 6, 7, 8, 9};
    vi arr5 = {1, 2, 3, 5, 6, 7, 8, 9};
    vi arr6 = {1, 2};
    vi arr7 = {1};
    vi arr8 = {};
    vi arr9 = {12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    vi arr10 = {1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 0, 0, 0};

    cout << SearchInRotatedAndSorted(arr1, 3) << '\n'; // 8
    cout << SearchInRotatedAndSorted(arr1, 10) << '\n'; // 5
    cout << SearchInRotatedAndSorted(arr1, 7) << '\n'; // 2
    cout << SearchInRotatedAndSorted(arr2, 30) << '\n'; // -1
    cout << SearchInRotatedAndSorted(arr3, 10) << '\n'; // 3
    cout << SearchInRotatedAndSorted(arr4, 10) << '\n'; // 0
    cout << SearchInRotatedAndSorted(arr5, 3) << '\n'; // 2
    cout << SearchInRotatedAndSorted(arr6, 2) << '\n'; // 1
    cout << SearchInRotatedAndSorted(arr7, 1) << '\n'; // 0
    cout << SearchInRotatedAndSorted(arr8, 1) << '\n'; // -1
    cout << SearchInRotatedAndSorted(arr9, 15) << '\n'; // 3
    cout << SearchInRotatedAndSorted(arr9, 5) << '\n'; // 13
    cout << SearchInRotatedAndSorted(arr9, 0) << '\n'; // 8
    cout << SearchInRotatedAndSorted(arr9, 19) << '\n'; // 7
    cout << SearchInRotatedAndSorted(arr9, 20) << '\n'; // -1
    cout << SearchInRotatedAndSorted(arr9, -1) << '\n'; // -1
    cout << SearchInRotatedAndSorted(arr10, 2) << '\n'; // 5
}
