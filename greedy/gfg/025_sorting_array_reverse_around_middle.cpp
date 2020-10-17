#include "../../template.hpp"

bool SortingWithReverse(vi arr) {
    vi sorted = arr;
    sort(sorted);
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            if (sorted[i] != arr[n - i - 1] and arr[n - i - 1] != arr[n / 2]) {
                return false;
            }
        }
        else {
            if (sorted[i] != arr[i] and sorted[i] != arr[n / 2]) {
                return false;
            }
        }
    }
    return true;
}

int main() { TimeMeasure _;
    cout << SortingWithReverse({1,6,3,4,5,2,7}) << '\n'; // true
    cout << SortingWithReverse({1,1,1,6,1,1,1}) << '\n'; // true
    cout << SortingWithReverse({1,6,3,4,5,7,2}) << '\n'; // false
}
