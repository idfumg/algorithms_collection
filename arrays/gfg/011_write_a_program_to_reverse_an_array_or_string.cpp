#include "../../template.hpp"

void Reverse(vi arr) {
    int n = arr.size();
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        swap(arr[i], arr[j]);
    }
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {1, 2, 3};
    vi arr2 = {4, 5, 1, 2};

    Reverse(arr1);
    Reverse(arr2);
}
