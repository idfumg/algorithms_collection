#include "../../template.hpp"

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
    int n = arr.size();
    int floor = LowerBound(arr, key);
    int ceil = UpperBound(arr, key);

    if (arr[floor] == key or arr[ceil] == key) {
        cout << key << ' ' << key;
    }
    else if (floor == n - 1 and arr[floor] < key) {
        cout << arr[floor] << ' ' << -1;
    }
    else if (ceil == 0 and arr[ceil] > key) {
        cout << -1 << ' ' << arr[ceil];
    }
    else {
        cout << arr[floor - 1] << ' ' << arr[ceil];
    }

    cout << '\n';
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
