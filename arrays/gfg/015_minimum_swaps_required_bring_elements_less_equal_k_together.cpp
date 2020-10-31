#include "../../template.hpp"

void MinSwaps(vi arr, int k) {
    int n = arr.size();
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (arr[j] <= k) {
            swap(arr[i++], arr[j]);
        }
    }
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {2, 1, 5, 6, 3}; int k1 = 3;
    vi arr2 = {2, 7, 9, 5, 8, 7, 4}; int k2 = 5;

    MinSwaps(arr1, k1);
    MinSwaps(arr2, k2);
}
