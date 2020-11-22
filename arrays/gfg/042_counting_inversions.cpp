#include "../../template.hpp"

int naive(vi arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                ++count;
            }
        }
    }
    return count;
}

int Merge(vi& arr, vi& temp, int left, int mid, int right) {
    int count = 0;
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid and j <= right) {
        if (arr[i] > arr[j]) count += mid - i + 1;
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; ++i) arr[i] = temp[i];
    return count;
}

int MergeSort(vi& arr, vi& temp, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += MergeSort(arr, temp, left, mid);
        count += MergeSort(arr, temp, mid + 1, right);
        count += Merge(arr, temp, left, mid, right);
    }
    return count;
}

int MergeSort(vi& arr) {
    int n = arr.size();
    vi temp(n);
    return MergeSort(arr, temp, 0, n - 1);
}

int fast(vi arr) {
    return MergeSort(arr);
}

int main() { TimeMeasure _;
    cout << naive({8, 4, 2, 1}) << '\n'; // 6
    cout << naive({3, 1, 2}) << '\n'; // 2
    cout << naive({8, 7, 6, 10, 11, 5}) << '\n'; // 8
    cout << naive({1, 20, 6, 4, 5}) << '\n'; // 5
    cout << '\n';
    cout << fast({8, 4, 2, 1}) << '\n'; // 6 // O(logn)
    cout << fast({3, 1, 2}) << '\n'; // 2
    cout << fast({8, 7, 6, 10, 11, 5}) << '\n'; // 8
    cout << fast({1, 20, 6, 4, 5}) << '\n'; // 5
}
