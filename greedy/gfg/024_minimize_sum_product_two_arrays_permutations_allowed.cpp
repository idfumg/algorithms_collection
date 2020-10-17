#include "../../template.hpp"

int naive(vi arr1, vi arr2, vb& visited, int i) {
    int n = arr1.size();
    if (i == n) {
        return 0;
    }
    int ans = INF;
    for (int j = 0; j < n; ++j) {
        if (not visited[j]) {
            visited[j] = true;
            int prod = arr1[i] * arr2[j];
            ans = min(ans, naive(arr1, arr2, visited, i + 1) + prod);
            visited[j] = false;
        }
    }
    return ans;
}

int naive(vi arr1, vi arr2) {
    vb visited(arr1.size());
    return naive(arr1, arr2, visited, 0);
}

int MinSumOfProduct(vi arr1, vi arr2) {
    sort(arr1);
    sort(arr2.begin(), arr2.end(), [](int a, int b){return a > b;});
    int ans = 0, n = arr1.size();
    for (int i = 0; i < n; ++i) {
        ans += arr1[i] * arr2[i]; // the bigger multiply on the smaller
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << naive({3,1,1}, {6,5,4}) << '\n'; // 23
    cout << naive({6,1,9,5,4}, {3,4,8,2,4}) << '\n'; // 80
    cout << '\n';
    cout << MinSumOfProduct({3,1,1}, {6,5,4}) << '\n'; // 23
    cout << MinSumOfProduct({6,1,9,5,4}, {3,4,8,2,4}) << '\n'; // 80
}
