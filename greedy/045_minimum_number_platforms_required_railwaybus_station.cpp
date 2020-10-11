#include "../template.hpp"

int MinNumberPlatformsRequired(vi arr, vi dep) {
    int n = arr.size(), ans = 0, i = 0, j = 0;
    sort(arr);
    sort(dep);

    int count = 0;
    while (i < n and j < n) {
        if (arr[i] <= dep[j]) {
            ++count;
            ++i;
        }
        else {
            --count;
            ++j;
        }
        ans = max(ans, count);
    }
    while (i++ < n) {
        ans = max(ans, ++count);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr = { 900, 940, 950, 1100, 1500, 1800 };
    vi dep = { 910, 1200, 1120, 1130, 1900, 2000 };

    cout << MinNumberPlatformsRequired(arr, dep) << '\n';
}
