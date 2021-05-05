#include "../../template.hpp"

void CoundDistinctElementsInWindow(vi arr, int k) {
    int n = arr.size();
    unordered_map<int, int> window;
    int windowSize = 0;
    for (int i = 0; i < n; ++i) {
        ++window[arr[i]];
        ++windowSize;
        if (windowSize == k) {
            cout << window.size() << ' ';
            if (--window[arr[i - k + 1]] == 0) {
                window.erase(arr[i - k + 1]);
            }
            --windowSize;
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    CoundDistinctElementsInWindow({1, 2, 1, 3, 4, 2, 3}, 4); // 3 4 4 3
    CoundDistinctElementsInWindow({1, 2, 4, 4}, 2); // 2 2 1
}
