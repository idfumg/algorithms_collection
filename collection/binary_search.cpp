#include "../template.hpp"

int BinarySearch(vi arr, int key) {
    int n = arr.size(), low = 0, high = n - 1;

    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key) low = mid + 1;
        else high = mid;
    }

    return arr[low] == key ? low : -1;
}

int LowerBound(vi arr, int key) {
    int n = arr.size(), low = 0, high = n - 1;

    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key) low = mid + 1;
        else high = mid;
    }

    return low;
}

int UpperBound(vi arr, int key) {
    int n = arr.size(), low = 0, high = n - 1;

    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= key) low = mid + 1;
        else high = mid;
    }

    return high;
}

void CeilingInSortedArray(vi arr, int key) {
    int i = LowerBound(arr, key);

    if (arr[i] == key) {
        cout << key << ' ' << key << endl;
        return;
    }

    if (arr[i] < key) {
        cout << arr[i] << ' ' << -1 << endl;
        return;
    }

    if (arr[i] > key and i == 0) {
        cout << -1 << ' ' << arr[i] << endl;
        return;
    }

    cout << arr[i - 1] << ' ' << arr[i] << endl;
}

int main() { TimeMeasure _;
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 0); // -1, 1
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 1); // 1, 1
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 5); // 2, 8
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 20); // 19, -1
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 8); // 8, 8
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 10); // 10, 10
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 13); // 12, 19
    CeilingInSortedArray({1, 2, 8, 10, 10, 12, 19}, 19); // 19, 19
}
