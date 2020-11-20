#include "../../template.hpp"

void KthSmallest(vi arr, int k) {
    sort(arr.begin(), arr.end());
    if (k == 1) {
        cout << arr[0] << endl;
        return;
    }
    int i = 1;
    int n = arr.size();
    --k;
    while (i < n) {
        if (arr[i] != arr[i - 1]) {
            --k;
        }
        if (k == 0) {
            break;
        }
        ++i;
    }
    if (i != n) {
        cout << arr[i] << endl;
    }
    else {
        cout << -1 << endl;
    }
}

void KthSmallest2(vi arr, int k) {
    set<int> set(arr.begin(), arr.end());
    for (const auto& elem : set) {
        if (--k == 0) {
            cout << elem << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() { TimeMeasure _;
    vi arr1 = {7, 10, 4, 3, 20, 15}; int k1 = 2;
    vi arr2 = {7, 10, 4, 3, 3, 15}; int k2 = 2;
    vi arr3 = {7, 10, 4, 3, 20, 15}; int k3 = 4;

    KthSmallest(arr1, k1);
    KthSmallest(arr2, k2);
    KthSmallest(arr3, k3);
    cout << '\n';
    KthSmallest2(arr1, k1);
    KthSmallest2(arr2, k2);
    KthSmallest2(arr3, k3);
}
