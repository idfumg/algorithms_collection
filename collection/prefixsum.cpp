#include <bits/stdc++.h>

using namespace std;

void prefix_sums(const vector<int>& arr, const vector<pair<int, int>>& ranges) {
    const size_t n = arr.size();
    vector<int> prefix(n + 1);
    for (size_t i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    for (const auto& [i, j] : ranges) {
        cout << prefix[j] - prefix[i - 1] << ' ';
    }
    cout << endl;
}

int main() {
    static const vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    prefix_sums(arr, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 3 6 9 32 6
    return 0;
}
