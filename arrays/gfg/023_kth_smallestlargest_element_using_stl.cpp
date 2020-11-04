#include "../../template.hpp"

void KthSmallest(vi arr, int k) {
    sort(arr);
    int i = 0;
    int n = arr.size();
    while (i < n - 1 and k > 1) {
        if (arr[i] != arr[i + 1]) {
            --k;
        }
        ++i;
    }
    cout << arr[i] << '\n';
}

void KthSmallest2(vi arr, int k) {
    si elems;
    for_each(arr.begin(), arr.end(), [&](int x){elems.insert(x);});
    auto it = elems.begin();
    for (; k > 1; ++it, --k) {
    }
    cout << *it << '\n';
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
