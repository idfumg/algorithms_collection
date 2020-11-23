#include "../../template.hpp"

int GCDOfArray(vi arr) {
    int n = arr.size();
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        if (ans == 1) {
            return 1;
        }
        ans = std::gcd(ans, arr[i]);
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << GCDOfArray({1, 2, 3}) << endl; // 1
    cout << GCDOfArray({2, 4, 6, 8}) << endl; // 2
}
