#include "../../template.hpp"

int MajorityElement(vi arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 1;
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            ++count;
        }
        else {
            count = 1;
            ans = arr[i];
        }
    }
    return count > n / 2 ? ans : -1;
}

int MajorityElement2(vi arr) {
    int n = arr.size();
    unordered_map<int, int> count;
    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
        if (count[arr[i]] > n / 2) {
            return arr[i];
        }
    }
    return -1;
}

int main() { TimeMeasure _;
    cout << MajorityElement({3, 3, 4, 2, 4, 4, 2, 4, 4}) << '\n'; // O(nlogn)
    cout << MajorityElement({3, 3, 4, 2, 4, 4, 2, 4}) << '\n';
    cout << '\n';
    cout << MajorityElement2({3, 3, 4, 2, 4, 4, 2, 4, 4}) << '\n'; // O(n)
    cout << MajorityElement2({3, 3, 4, 2, 4, 4, 2, 4}) << '\n';
}
