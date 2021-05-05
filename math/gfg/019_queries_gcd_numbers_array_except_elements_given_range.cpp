#include "../../template.hpp"

int GcdInRange(vi arr, int a, int b) {
    int n = arr.size();
    vi prefix(n + 1);
    vi suffix(n + 2);
    for (int i = 1; i < n; ++i) {
        prefix[i] = gcd(prefix[i - 1], arr[i - 1]);
    }
    for (int i = n; i >= 1; --i) {
        suffix[i] = gcd(suffix[i + 1], arr[i - 1]);
    }
    if (a == 0) return suffix[2];
    if (b == n - 1) return prefix[a + 1];
    return gcd(prefix[a], suffix[b]);
}

int main() { TimeMeasure _;
    cout << GcdInRange({2, 6, 9}, 0, 0) << endl; // 3
    cout << GcdInRange({2, 6, 9}, 1, 1) << endl; // 1
    cout << GcdInRange({2, 6, 9}, 1, 2) << endl; // 2
}
