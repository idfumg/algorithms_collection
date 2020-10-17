#include "../../template.hpp"

int FindMaximumPyramidHeight(vi arr) {
    int n = arr.size();
    sort(arr);
    int height = 0, prevWidth = 0, currentWidth = 0;
    for (int i = 0; i < n; ++i) {
        ++currentWidth;
        if (currentWidth > prevWidth) {
            prevWidth = currentWidth;
            currentWidth = 0;
            ++height;
        }
    }
    return height;
}

int main() { TimeMeasure _;
    vi arr1 = {40, 100, 20, 30}; // 2
    vi arr2 = {10, 20, 30, 50, 60, 70}; // 3

    cout << FindMaximumPyramidHeight(arr1) << '\n';
    cout << FindMaximumPyramidHeight(arr2) << '\n';
}
