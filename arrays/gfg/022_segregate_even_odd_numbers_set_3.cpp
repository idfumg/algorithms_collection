#include "../../template.hpp"

void Segregate(vi arr) {
    int n = arr.size();
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (arr[j] % 2 == 0) {
            swap(arr[i++], arr[j]);
        }
    }
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr1 = {1, 9, 5, 3, 2, 6, 7, 11};
    vi arr2 = {1, 3, 2, 4, 7, 6, 9, 10};
    Segregate(arr1);
    Segregate(arr2);
}
