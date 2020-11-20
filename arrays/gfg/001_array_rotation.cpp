#include "../../template.hpp"

void LeftRotate(vi arr, int k) {
    int n = arr.size();
    if (k > n) {
        k = k % n;
    }
    while (k-- > 0) {
        int temp = arr[0];
        for (int j = 1; j < n; ++j) {
            swap(arr[j], arr[j - 1]);
        }
        arr[n - 1] = temp;
    }
    debugn(arr);
}

void LeftRotate2(vi arr, int k) {
    int n = arr.size();
    if (k > n) {
        k = k % n;
    }
    rotate(arr.begin(), arr.begin() + k, arr.end());
    debugn(arr);
}

void LeftRotate3(vi arr, int k) {
    k = k % arr.size();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
    debugn(arr);
}

void RightRotate(vi arr, int k) {
    k = k % arr.size();
    reverse(arr.rbegin(), arr.rbegin() + k);
    reverse(arr.rbegin() + k, arr.rend());
    reverse(arr.rbegin(), arr.rend());
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr = { 1, 2, 3, 4, 5, 6, 7 }; // 3 4 5 6 7 1 2
    LeftRotate(arr, 2); // O(n*K)
    LeftRotate2(arr, 2); // O(n)
    LeftRotate3(arr, 2); // O(n)

    RightRotate(arr, 2); // O(n) // 6 7 1 2 3 4 5
}
