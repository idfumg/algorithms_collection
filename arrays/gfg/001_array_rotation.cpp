#include "../../template.hpp"

void LeftRotate(vi arr, int k) {
    int n = arr.size();
    while (k-- > 0) {
        int temp = arr[0];
        for (int j = 1; j < n; ++j) {
            swap(arr[j], arr[j - 1]);
        }
        arr[n - 1] = temp;
    }
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr = { 1, 2, 3, 4, 5, 6, 7 };
    LeftRotate(arr, 2);
}
