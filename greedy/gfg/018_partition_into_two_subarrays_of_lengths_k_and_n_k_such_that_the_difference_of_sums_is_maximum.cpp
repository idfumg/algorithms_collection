#include "../../template.hpp"

int PartitionIntoToAndSum(vi& arr, int k) {
    sort(arr);
    return accumulate(arr.begin() + k, arr.end(), 0) -
        accumulate(arr.begin(), arr.begin() + k, 0);
}

int main() { TimeMeasure _;
    vi arr1 = {8, 4, 5, 2, 10};
    vi arr2 = {1, 1, 1, 1, 1, 1, 1, 1};

    cout << PartitionIntoToAndSum(arr1, 2) << '\n'; // 17
    cout << PartitionIntoToAndSum(arr2, 3) << '\n'; // 2
}
