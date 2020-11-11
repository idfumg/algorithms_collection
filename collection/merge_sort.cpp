#include "../template.hpp"

int Merge(vi& arr, vi& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int idx = left;
    int count = 0;

    while (i <= mid and j <= right) {
        if (arr[i] <= arr[j]) {
            temp[idx++] = arr[i++];
        }
        else {
            temp[idx++] = arr[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid) temp[idx++] = arr[i++];
    while (j <= right) temp[idx++] = arr[j++];
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

int MergeSort(vi arr) {
    int n = arr.size();
    vi temp(n);
    return MergeSort(arr, temp, 0, n - 1);
}

int main() { TimeMeasure _;
    cout << MergeSort({8, 4, 2, 1}) << '\n';
    cout << MergeSort({3, 1, 2}) << '\n';
    cout << MergeSort({8, 7, 6, 10, 11, 5}) << '\n';
    cout << MergeSort({1, 20, 6, 4, 5}) << '\n';
}
