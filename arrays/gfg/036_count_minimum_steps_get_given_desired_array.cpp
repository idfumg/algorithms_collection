#include "../../template.hpp"

int CountMinSteps(vi arr) {
    int n = arr.size();
    int ans = 0;
    int doubleCount = INF;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= 1) {
            doubleCount = 0;
            break;
        }

        if (arr[i] & 1) {
            doubleCount = min(doubleCount, (int)log2(arr[i] - 1));
        }
        else {
            doubleCount = min(doubleCount, (int)log2(arr[i]));
        }
    }

    for (int i = 0; i < n; ++i) {
        if (doubleCount == 0) {
            ans += arr[i];
            continue;
        }

        if (arr[i] & 1) {
            ans += arr[i] - pow(2, doubleCount);
        }
        ans += 1;
    }
    return ans + doubleCount;
}

int main() { TimeMeasure _;
    cout << CountMinSteps({2, 3}) << '\n'; // 4
    cout << CountMinSteps({2, 1}) << '\n'; // 3
    cout << CountMinSteps({16, 16, 16}) << '\n'; // 7
    cout << CountMinSteps({2, 5}) << '\n'; // 6
}
