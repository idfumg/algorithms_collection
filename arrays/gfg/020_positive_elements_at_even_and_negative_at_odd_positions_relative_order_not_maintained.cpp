#include "../../template.hpp"

void Rearrange(vi arr) {
    int n = arr.size();
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (arr[j] < 0) {
            swap(arr[i++], arr[j]);
        }
    }
    for (int j = 0; j < n and arr[j] < 0 and i < n; j += 2) {
        swap(arr[j], arr[i++]);
    }
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr1 = {1, -3, 5, 6, -3, 6, 7, -4, 9, 10};
    vi arr2 = {-1, 3, -5, 6, 3, 6, -7, -4, -9, 10};

    Rearrange(arr1);
    Rearrange(arr2);
}
