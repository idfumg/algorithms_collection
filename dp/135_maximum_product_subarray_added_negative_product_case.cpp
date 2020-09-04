#include "../../template.hpp"

int tab(vi arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (arr[i] * arr[i - 1] > arr[i]) {
            if (abs(arr[i] * arr[i - 1]) > 0) {
                arr[i] = arr[i] * arr[i - 1];
            }
        }
    }
    return max(arr);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {-2, -3, 0, -2, -40};
    vi arr2 = {0, -4, 0, -2};
    vi arr3 = {-4, 3, 4};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
}
