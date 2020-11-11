#include "../template.hpp"

vi RuffleSort(vi arr) { // qsort O(n^2) has complexity if elements sorted
    random_shuffle(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    return arr;
}

int main() { TimeMeasure _;
    cout << RuffleSort({1, 20, 5, -1, 6, 4, 5}) << '\n';
}
