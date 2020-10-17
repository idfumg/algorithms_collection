#include "../../template.hpp"

int naive(vi& arr) {
    int res = 0, n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                const int cube = arr[i] + arr[j] + arr[k];
                const int cuberoot = cbrt(cube);
                if (cube == cuberoot * cuberoot * cuberoot) {
                    res += 1;
                }
            }
        }
    }
    return res;
}

int main() { TimeMeasure _; __x();
    vi arr = {2, 5, 1, 20, 6};
    cout << naive(arr) << endl;
}
