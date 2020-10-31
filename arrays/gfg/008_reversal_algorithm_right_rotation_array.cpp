#include "../../template.hpp"

void RightRotate(vi arr, int k) {
    int n = arr.size();
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 8 9 10 1 2 3 4 5 6 7
    vi arr2 = {121, 232, 33, 43 ,5}; // 43 5 121 232 33

    RightRotate(arr1, 3);
    RightRotate(arr2, 2);
}
