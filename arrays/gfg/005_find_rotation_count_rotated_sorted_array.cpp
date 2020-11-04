#include "../../template.hpp"

int FindMaxRightRotationsCount(vi arr) {
    int n = arr.size();
    int left = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            left = i + 1;
        }
    }
    return left == -1 ? 0 : left;
}

int main() { TimeMeasure _;
    cout << FindMaxRightRotationsCount({15, 18, 2, 3, 6, 12}) << '\n'; // 2
    cout << FindMaxRightRotationsCount({7, 9, 11, 12, 5}) << '\n'; // 4
    cout << FindMaxRightRotationsCount({7, 9, 11, 12, 15}) << '\n'; // 0
}
