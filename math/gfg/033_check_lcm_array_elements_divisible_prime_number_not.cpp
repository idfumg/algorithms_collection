#include "../../template.hpp"

bool brute(vi arr, int k) {
    int lcm = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        lcm = std::lcm(lcm, arr[i]);
    }
    return lcm % k == 0;
}

bool fast(vi arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr[i] % k == 0) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    cout << brute({10, 20, 15, 25}, 3) << endl; // 1
    cout << brute({24, 21, 45, 57, 36}, 23) << endl; // 0
    cout << endl;
    cout << fast({10, 20, 15, 25}, 3) << endl; // 1
    cout << fast({24, 21, 45, 57, 36}, 23) << endl; // 0
}
