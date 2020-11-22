#include "../../template.hpp"

int MinLengthUnsorted(vi arr) {
    int n = arr.size();
    int left = 1;
    int right = n - 2;

    while (left < right and arr[left] > arr[left - 1]) ++left;
    while (right > left and arr[right] < arr[right + 1]) --right;

    int mini = *min_element(arr.begin() + left, arr.begin() + right);
    while (left > 0 and arr[left - 1] > mini) --left;

    int maxi = *max_element(arr.begin() + left, arr.begin() + right);
    while (right < n - 1 and arr[right + 1] < maxi) ++right;

    return right - left;
}

int main() { TimeMeasure _;
    cout << MinLengthUnsorted({10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60}) << '\n'; // 5
    cout << MinLengthUnsorted({0, 1, 15, 25, 6, 7, 30, 40, 50}) << '\n'; // 3
}
