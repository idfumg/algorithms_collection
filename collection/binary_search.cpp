#include "../template.hpp"

int LowerBound(vi arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) low = mid + 1;
        else high = mid;
    }
    return low;
}

int UpperBound(vi arr, int target) {
    int idx = LowerBound(arr, target);
    if (idx == arr.size() - 1) return -1;
    return idx + 1;
}

int BinarySearch(vi arr, int target) {
    int idx = LowerBound(arr, target);
    if (arr[idx] == target) return idx;
    return -1;
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
    cout << endl;
    assert(LowerBound({1,2,3,4,5,6,7,8,9}, 4) == 3);
    assert(LowerBound({1,2,3,4,5,6,7,8,9}, 10) == 8);
    assert(UpperBound({1,2,3,4,5,6,7,8,9}, 4) == 4);
    assert(UpperBound({1,2,3,4,5,6,7,8,9}, 10) == -1);
    assert(BinarySearch({1,2,3,4,5,6,7,8,9}, 4) == 3);
    assert(BinarySearch({1,2,3,4,5,6,7,8,9}, 10) == -1);
}
