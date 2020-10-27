#include "../../template.hpp"

int MinOperationsToMakeGCD(vi arr, int k) {
    int count = 0, n = arr.size();
    for (int i = 0; i < n; ++i) {
        int x = (arr[i] - 1) % k;
        int y = (arr[i] + 1) % k;

        if (arr[i] % k == 0) {
            count += 0;
        }
        else if (x < y) {
            count += 1 + x;
        }
        else {
            count += 1 + y;
        }
    }
    return count;
}

int MinOperationsToMakeGCD2(vi arr, int k) {
    int count = 0, n = arr.size();
    for (int i = 0; i < n; ++i) {
        count += min(arr[i] % k, k - arr[i] % k);
    }
    return count;
}

int MinOperationsToMakeGCD3(vi arr, int k) {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int mod = arr[i] % k;
        int a = mod % k;
        int b = abs(k - mod);
        ans += min(a, b);
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << MinOperationsToMakeGCD({4, 5, 6}, 5) << '\n'; // 2
    cout << MinOperationsToMakeGCD({4, 9, 6}, 5) << '\n'; // 3
    cout << '\n';
    cout << MinOperationsToMakeGCD2({4, 5, 6}, 5) << '\n'; // 2
    cout << MinOperationsToMakeGCD2({4, 9, 6}, 5) << '\n'; // 3
    cout << '\n';
    cout << MinOperationsToMakeGCD3({4, 5, 6}, 5) << '\n'; // 2
    cout << MinOperationsToMakeGCD3({4, 9, 6}, 5) << '\n'; // 3
}
