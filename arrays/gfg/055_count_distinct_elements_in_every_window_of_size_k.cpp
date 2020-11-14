#include "../../template.hpp"

void CoundDistinctElementsInWindow(vi arr, int k) {
    debugn(arr);
    int n = arr.size();
    unordered_map<int, int> freq;
    for (int i = 0; i < k; ++i) {
        ++freq[arr[i]];
    }
    for (int i = k; i <= n; ++i) {
        cout << freq.size() << ' ';
        if (i == n) break;
        if (--freq[arr[i - k]] == 0) {
            freq.erase(arr[i - k]);
        }
        ++freq[arr[i]];
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    CoundDistinctElementsInWindow({1, 2, 1, 3, 4, 2, 3}, 4); // 3 4 4 3
    CoundDistinctElementsInWindow({1, 2, 4, 4}, 2); // 2 2 1
}
