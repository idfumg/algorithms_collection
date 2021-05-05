#include "../../template.hpp"

int CountMinSteps(vi arr) {
    int n = arr.size();
    int ans = 0;
    int minNumber = INF;
    int maxNumber = -INF;
    for (int i = 0; i < n; ++i) {
        if (arr[i] & 1 and arr[i] != 1) {
            --arr[i];
            ++ans;
        }
        minNumber = min(minNumber, arr[i]);
        maxNumber = max(maxNumber, arr[i]);
    }
    if (minNumber == 0 and maxNumber != 0) return INF; // we can't make it
    if (minNumber == 0 and maxNumber == 0) return 0; // nothing to do
    int p = log2(minNumber);
    ans += p;
    for (int i = 0; i < n; ++i) {
        if (p > 0) {
            arr[i] /= pow(2, p); // reduce by maximum power of 2 to 1 if we can
        }
        ans += arr[i]; // add 1s or whatever remains and we can't simplify it anymore
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << CountMinSteps({2, 3}) << '\n'; // 4
    cout << CountMinSteps({2, 1}) << '\n'; // 3
    cout << CountMinSteps({16, 16, 16}) << '\n'; // 7
    cout << CountMinSteps({2, 5}) << '\n'; // 5
    cout << CountMinSteps({5, 3}) << '\n'; // 6
    cout << CountMinSteps({5, 1}) << '\n'; // 6
}
