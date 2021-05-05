#include "../../template.hpp"

void KthSmallest(vi arr, int k) {
    int n = arr.size();
    set<int> set;
    for (int i = 0; i < n; ++i) {
        set.insert(arr[i]);
        if (set.size() > k) {
            set.erase(*set.rbegin());
        }
    }
    cout << *set.rbegin() << endl;
}

int main() { TimeMeasure _;
    vi arr1 = {7, 10, 4, 3, 20, 15}; int k1 = 2;
    vi arr2 = {7, 10, 4, 3, 3, 15}; int k2 = 2;
    vi arr3 = {7, 10, 4, 3, 20, 15}; int k3 = 4;

    KthSmallest(arr1, k1); // 4
    KthSmallest(arr2, k2); // 4
    KthSmallest(arr3, k3); // 10
}
