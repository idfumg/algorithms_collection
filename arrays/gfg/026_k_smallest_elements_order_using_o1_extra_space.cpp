#include "../../template.hpp"

void KSmallestElems(vi arr, int k) {
    int n = arr.size();
    stable_sort(arr.begin(), arr.end());
    for (int i = 0; i < k and i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void KSmallestElems2(vi arr, int k) {
    int n = arr.size();
    for (int i = 0; i < k and i < n; ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[idx]) {
                idx = j;
            }
        }
        if (idx != i) {
            swap(arr[i], arr[idx]);
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void KSmallestElems3(vi arr, int k) {
    int n = arr.size();
    for (int i = k; i < n; ++i) {
        int maxvalue = arr[0];
        int maxpos = 0;
        for (int j = 1; j < k; ++j) {
            if (arr[j] > maxvalue) {
                maxvalue = arr[j];
                maxpos = j;
            }
        }
        if (maxvalue > arr[i]) {
            arr[maxpos] = arr[i];
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() { TimeMeasure _;
    vi arr1 = {4, 2, 6, 1, 5}; int k1 = 3; // 4 2 1
    vi arr2 = {4, 12, 16, 21, 25}; int k2 = 3; // 4, 12, 16

    KSmallestElems(arr1, k1); // O(nlogn) + Om(n)
    KSmallestElems(arr2, k2);
    cout << '\n';
    KSmallestElems2(arr1, k1); // O(n*k) + Om(1)
    KSmallestElems2(arr2, k2);
    cout << '\n';
    KSmallestElems3(arr1, k1); // O(n) + Om(1)
    KSmallestElems3(arr2, k2);
}
