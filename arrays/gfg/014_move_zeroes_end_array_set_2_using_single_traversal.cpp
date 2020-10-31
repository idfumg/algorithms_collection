#include "../../template.hpp"

void MoveZeroes(vi arr) {
    int n = arr.size();
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (arr[j] != 0) {
            arr[i++] = arr[j];
        }
    }
    for (; i < n; ++i) {
        arr[i] = 0;
    }
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {1, 2, 0, 0, 0, 3, 6};
    vi arr2 = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};

    MoveZeroes(arr1);
    MoveZeroes(arr2);
}
