#include "../../template.hpp"

int ShortestUnordered(vi arr) {
    if (not is_sorted(arr.begin(), arr.end(), less<int>()) and
        not is_sorted(arr.begin(), arr.end(), greater<int>())) {
        return 3;
    }
    return 0;
}

int main() { TimeMeasure _;
    cout << ShortestUnordered({7, 9, 10, 8, 11}) << '\n'; // 3
    cout << ShortestUnordered({1, 2, 3, 4, 5}) << '\n'; // 0
}
