#include "../../template.hpp"

void Rearrange(vi arr) {
    int n = arr.size();
    vb count(n + 1, false);
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1) {
            count[arr[i]] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (count[i]) {
            arr[i] = i;
        }
        else {
            arr[i] = -1;
        }
    }
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    vi arr2 = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8, 11, 10, 9, 5, 13, 16, 2, 14, 17, 4};

    Rearrange(arr1);
    Rearrange(arr2);
}
