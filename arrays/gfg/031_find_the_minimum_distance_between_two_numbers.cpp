#include "../../template.hpp"

int FindMinDistance(vi arr, int x, int y) {
    int n = arr.size();

    vi xs;
    vi ys;

    for (int i = 0; i < n; ++i) {
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
    n = ys.size();
    int ans = INF;

    while (i < m and j < n) {
        ans = min(ans, abs(ys[j]  - xs[i]));
        ++i;

        if (abs(ys[j] - xs[i]) < ans) {
            continue;
        }
        else if (abs(ys[j] - xs[i]) > ans) {
            ++j;
        }
    }

    return ans;
}

int main() { TimeMeasure _;
    cout << FindMinDistance({1, 2}, 1, 2) << '\n'; // 1
    cout << FindMinDistance({3, 4, 5}, 3, 5) << '\n'; // 2
    cout << FindMinDistance({3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, 3, 6) << '\n'; // 4
    cout << FindMinDistance({2, 5, 3, 5, 4, 4, 2, 3}, 3, 2) << '\n'; // 1
}
