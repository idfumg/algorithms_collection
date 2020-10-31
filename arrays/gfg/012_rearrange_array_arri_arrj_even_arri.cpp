#include "../../template.hpp"

void Rearrange(vi arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vi ans(n);
    int idx = n - 1;
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
        ans[idx--] = arr[i];
        if (i != j) {
            ans[idx--] = arr[j];
        }
    }
    cout << ans << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {1, 2, 3, 4, 5, 6, 7};
    vi arr2 = {1, 2, 1, 4, 5, 6, 8, 8};

    Rearrange(arr1);
    Rearrange(arr2);
}
