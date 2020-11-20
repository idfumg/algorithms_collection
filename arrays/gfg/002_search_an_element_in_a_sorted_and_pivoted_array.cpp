#include "../../template.hpp"

int SearchInRotatedAndSorted(vi arr, int key) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            if (arr[left] > key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        else {
            if (arr[left] >= key and arr[right] < key) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
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
}
