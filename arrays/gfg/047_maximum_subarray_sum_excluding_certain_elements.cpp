#include "../../template.hpp"

int BinarySearch(vi arr, int key) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while (left != right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < key) left = mid + 1;
        else right = mid;
    }
    return arr[left] == key ? left : -1;
}

void MaxSubArraySumExcludingSecondElements(vi arr1, vi arr2) {
    int m = arr1.size();
    int n = arr2.size();
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < m; ++i) {
        if (BinarySearch(arr2, arr1[i]) != -1) {
            arr1[i] = -INF;
        }
    }
    for (int i = 1; i < m; ++i) {
        if (arr1[i] + arr1[i - 1] > arr1[i]) {
            arr1[i] += arr1[i - 1];
        }
    }
    cout << max(arr1) << endl;
}

void MaxSubArraySumExcludingSecondElements2(vi arr1, vi arr2) {
    int m = arr1.size();
    int n = arr2.size();
    unordered_set<int> tab;
    for (const int value : arr2) {
        tab.insert(value);
    }
    for (int i = 1; i < m; ++i) {
        if (tab.count(arr1[i])) {
            arr1[i] = -INF;
        }
        else if (arr1[i] + arr1[i - 1] > arr1[i]) {
            arr1[i] += arr1[i - 1];
        }
    }
    cout << max(arr1) << endl;
}

void MaxSubArraySumExcludingSecondElements3(vi arr, vi arr2) {
    unordered_set<int> forbidden;
    for (int v : arr2) {
        forbidden.insert(v);
    }
    int window = 0;
    int windowSize = 0;
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (forbidden.count(arr[i])) {
            window = 0;
            windowSize = 0;
        }
        else {
            window += arr[i];
            ++windowSize;
        }
        ans = max(ans, window);
    }
    cout << ans << endl;
}

int main() { TimeMeasure _;
    MaxSubArraySumExcludingSecondElements({1, 7, -10, 6, 2}, {5, 6, 7, 1}); // 2 // O(nlogn)
    MaxSubArraySumExcludingSecondElements({3, 4, 5, -4, 6}, {1, 8, 5}); // 7
    cout << endl;
    MaxSubArraySumExcludingSecondElements2({1, 7, -10, 6, 2}, {5, 6, 7, 1}); // 2 // O(n)
    MaxSubArraySumExcludingSecondElements2({3, 4, 5, -4, 6}, {1, 8, 5}); // 7
    cout << endl;
    MaxSubArraySumExcludingSecondElements3({1, 7, -10, 6, 2}, {5, 6, 7, 1}); // 2 // O(n)
    MaxSubArraySumExcludingSecondElements3({3, 4, 5, -4, 6}, {1, 8, 5}); // 7
}
