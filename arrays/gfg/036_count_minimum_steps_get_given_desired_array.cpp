#include "../../template.hpp"

int CountMinSteps(vi arr) {
    if (count(arr.begin(), arr.end(), 0) != 0) return reduce(arr.begin(), arr.end(), 0);
    if (count(arr.begin(), arr.end(), 1) != 0) return reduce(arr.begin(), arr.end(), 0);
    int n = arr.size();
    int ans = arr.size(); // change all numbers into 1's with a cost of size of the array
    int maxi = -INF;
    int mini = +INF;
    for (int i = 0; i < n; ++i) {
        if (arr[i] & 1) {
            ++ans; // reduce into an even number with a cost of 1
            maxi = max(maxi, arr[i] - 1);
            mini = min(mini, arr[i] - 1);
        }
        else {
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
    }
    ans += log2(mini); // multiply 1s on 2 several times while we are below the minimum value
    for (int i = 0; i < n; ++i) { // remove minimum value from the array and add remaining values
        if (arr[i] & 1) ans += arr[i] - 1 - mini;
        else ans += arr[i] - mini;
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
    cout << CountMinSteps({5, 1, 0}) << '\n'; // 6
}
