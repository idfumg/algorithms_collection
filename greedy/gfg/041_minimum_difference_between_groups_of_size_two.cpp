#include "../../template.hpp"

int MinDiffBetweenGroupsOfSize2(vi arr) {
    int n = arr.size(), mini = INF, maxi = -INF;
    sort(arr);
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        maxi = max(maxi, arr[i] + arr[j]);
        mini = min(mini, arr[i] + arr[j]);
    }
    return maxi - mini;
}

int main() { TimeMeasure _; __x();
    cout << MinDiffBetweenGroupsOfSize2({2,6,4,3}) << '\n';
    cout << MinDiffBetweenGroupsOfSize2({11,4,3,5,7,1}) << '\n';
}
