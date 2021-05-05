#include "../../template.hpp"

int MinLengthUnsorted(vi arr) {
    int n = arr.size(), left = 1, right = n - 2;

    while (arr[left] >= arr[left - 1]) ++left;
    while (arr[right] <= arr[right + 1] and left < right) --right;

    if (left > right) return 0;

    int mini = *min_element(arr.begin() + left, arr.begin() + right);
    while (arr[left - 1] > mini) --left;

    int maxi = *max_element(arr.begin() + left, arr.begin() + right);
    while (arr[right + 1] < maxi) ++right;

    return right - left + 1;
}

int main() { TimeMeasure _;
    cout << MinLengthUnsorted({10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60}) << '\n'; // 6
    cout << MinLengthUnsorted({0, 1, 15, 25, 6, 7, 30, 40, 50}) << '\n'; // 4
    cout << MinLengthUnsorted({0, 1, 2, 3, 4, 5}) << '\n'; // 0
}
