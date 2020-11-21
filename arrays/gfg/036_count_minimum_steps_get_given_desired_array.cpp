#include "../../template.hpp"

int CountMinSteps(vi arr) {
    int mini = *min_element(arr.begin(), arr.end());
    if (mini == 1) {
        return accumulate(arr.begin(), arr.end(), 0);
    }
    int n = arr.size();
    int ans = n + log2(mini);
    for (int i = 0; i < n; ++i) {
        ans += arr[i] - (mini & 1 ? mini - 1 : mini);
    }
    return ans;
}

int CountMinSteps2(vi arr) {
    int mini = *min_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (mini == 1) {
        return sum;
    }
    return
        arr.size() +
        log2(mini) +
        sum -
        (mini & 1 ? mini - 1 : mini) * arr.size();
}

int main() { TimeMeasure _;
    cout << CountMinSteps({2, 3}) << '\n'; // 4
    cout << CountMinSteps({2, 1}) << '\n'; // 3
    cout << CountMinSteps({16, 16, 16}) << '\n'; // 7
    cout << CountMinSteps({2, 5}) << '\n'; // 6
    cout << CountMinSteps({5, 3}) << '\n'; // 7
    cout << CountMinSteps({5, 1}) << '\n'; // 6
    cout << endl;
    cout << CountMinSteps2({2, 3}) << '\n'; // 4
    cout << CountMinSteps2({2, 1}) << '\n'; // 3
    cout << CountMinSteps2({16, 16, 16}) << '\n'; // 7
    cout << CountMinSteps2({2, 5}) << '\n'; // 6
    cout << CountMinSteps2({5, 3}) << '\n'; // 7
    cout << CountMinSteps2({5, 1}) << '\n'; // 6
}
