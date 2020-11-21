#include "../../template.hpp"

int FindMinDistance(vi arr, int x, int y) {
    vi xs;
    vi ys;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == x) {
            xs.push_back(i);
        }
        else if (arr[i] == y) {
            ys.push_back(i);
        }
    }
    int i = 0;
    int j = 0;
    int m = xs.size();
    int n = ys.size();
    int minidist = INF;
    while (i < m and j < n) {
        minidist = min(minidist, abs(xs[i] - ys[j]));
        if (xs[i] < ys[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }
    return minidist;
}

int main() { TimeMeasure _;
    cout << FindMinDistance({1, 2}, 1, 2) << '\n'; // 1
    cout << FindMinDistance({3, 4, 5}, 3, 5) << '\n'; // 2
    cout << FindMinDistance({3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, 3, 6) << '\n'; // 4
    cout << FindMinDistance({2, 5, 3, 5, 4, 4, 2, 3}, 3, 2) << '\n'; // 1
}
