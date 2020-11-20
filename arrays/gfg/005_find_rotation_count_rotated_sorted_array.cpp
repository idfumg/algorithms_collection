#include "../../template.hpp"

int FindMaxRightRotationsCount(vi arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return i;
        }
    }
    return 0;
}

int main() { TimeMeasure _;
    cout << FindMaxRightRotationsCount({15, 18, 2, 3, 6, 12}) << '\n'; // 2
    cout << FindMaxRightRotationsCount({7, 9, 11, 12, 5}) << '\n'; // 4
    cout << FindMaxRightRotationsCount({7, 9, 11, 12, 15}) << '\n'; // 0
}
