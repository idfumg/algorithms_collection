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
        else if (key <= arr[n - 1]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() { TimeMeasure _;
    vi arr1 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    vi arr2 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    vi arr3 = {30, 40, 50, 10, 20};
    cout << SearchInRotatedAndSorted(arr1, 3) << '\n';
    cout << SearchInRotatedAndSorted(arr2, 30) << '\n';
    cout << SearchInRotatedAndSorted(arr3, 10) << '\n';
}
