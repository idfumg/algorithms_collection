#include "../../template.hpp"

int LargestContiguousSubArraySum(vi arr) {
    int n = arr.size();
    for (int i = 1; i <n; ++i) {
        if (arr[i] + arr[i - 1] > arr[i]) {
            arr[i] = arr[i] + arr[i - 1];
        }
    }
    return max(arr);
}

int main() { TimeMeasure _;
    vi arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << LargestContiguousSubArraySum(arr) << '\n';
}
