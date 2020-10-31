#include "../../template.hpp"

void DoubleAndMoveZeroes(vi arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1] and arr[i] != 0 and arr[i - 1] != 0) {
            arr[i - 1] *= 2;
            arr[i] = 0;
        }
    }
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (arr[j] != 0) {
            arr[i++] = arr[j];
        }
    }
    for (; i < n; ++i) {
        arr[i] = 0;
    }
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr1 = {2, 2, 0, 4, 0, 8};
    vi arr2 = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8};

    DoubleAndMoveZeroes(arr1);
    DoubleAndMoveZeroes(arr2);
}
