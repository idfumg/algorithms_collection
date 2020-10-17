#include "../../template.hpp"

int MinNumberPlatformsRequired(vi arr, vi dep) {
    int n = arr.size();
    sort(arr);
    sort(dep);
    int i = 0, j = 0, count = 0, ans = 0;
    while (i < n and j < n) {
        if (arr[i] < dep[j]) {
            ans = max(ans, ++count);
            ++i;
        }
        else {
            ans = max(ans, --count);
            ++j;
        }
    }
    return ans;
}

int MinNumberPlatformsRequired2(vi arr, vi dep) {
    int n = arr.size(), ans = 0;
    vi idxes(n);
    iota(idxes.begin(), idxes.end(), 0);
    sort(idxes.begin(), idxes.end(), [&](int i, int j){return arr[i] < arr[j];});
    int count = 1, prev = idxes[0];
    for (int i = 1; i < n; ++i) {
        int idx = idxes[i];
        if (arr[idx] < dep[prev]) {
            ++count;
        }
        else {
            count = 1;
            prev = idx;
        }
        ans = max(ans, count);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    {
        vi arr = { 900, 940, 950, 1100, 1500, 1800 };
        vi dep = { 910, 1200, 1120, 1130, 1900, 2000 };
        cout << MinNumberPlatformsRequired(arr, dep) << '\n'; // 3
        cout << MinNumberPlatformsRequired2(arr, dep) << '\n'; // 3
    }
    {
        vi arr = {900, 940};
        vi dep = {910, 1200};
        cout << MinNumberPlatformsRequired(arr, dep) << '\n'; // 1
        cout << MinNumberPlatformsRequired2(arr, dep) << '\n'; // 1
    }
}
