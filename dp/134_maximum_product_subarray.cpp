#include "../template.hpp"

int tab(vi arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i] * arr[i - 1]) > abs(arr[i])) {
            arr[i] = arr[i] * arr[i - 1];
        }
    }
    return max(arr);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {6, -3, -10, 0, 2};
    vi arr2 = {-1, -3, -10, 0, 60};
    vi arr3 = {-2, -3, 0, -2, -40};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
}
