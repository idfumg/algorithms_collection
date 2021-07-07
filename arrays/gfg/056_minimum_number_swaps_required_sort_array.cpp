#include "../../template.hpp"

int MinSwaps(vi arr) {
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int idx = - 1;
        int mini = arr[i];
        for (int j = i + 1; j < n; ++j) {
            if (mini > arr[j]) {
                mini = arr[j];
                idx = j;
            }
        }
        if (idx != -1) {
            ++ans;
            swap(arr[i], arr[idx]);
        }
    }
    return ans;
}

int MinSwapsHash(vi arr) {
    int n = arr.size();

    vi temp = arr;
    sort(temp.begin(), temp.end());

    unordered_map<int, int> idx;
    for (int i = 0; i < n; ++i) {
        idx[arr[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != temp[i]) {
            ++ans;
            int value = arr[i];
            swap(arr[i], arr[idx[temp[i]]]);
            idx[value] = idx[temp[i]];
            idx[temp[i]] = i;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << MinSwaps({4, 3, 2, 1}) << endl; // 2
    cout << MinSwaps({4, 3, 1, 2}) << endl; // 3
    cout << MinSwaps({1, 5, 4, 3, 2}) << endl; // 2
    cout << MinSwaps({101, 758, 315, 730, 472, 619, 460, 479}) << endl; // 5
    cout << endl;
    cout << MinSwapsHash({4, 3, 2, 1}) << endl; // 2
    cout << MinSwapsHash({4, 3, 1, 2}) << endl; // 3
    cout << MinSwapsHash({1, 5, 4, 3, 2}) << endl; // 2
    cout << MinSwapsHash({101, 758, 315, 730, 472, 619, 460, 479}) << endl; // 5
}
