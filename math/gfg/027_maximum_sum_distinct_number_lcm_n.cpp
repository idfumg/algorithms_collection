#include "../../template.hpp"

int brute(int n) {
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        if (n % i == 0) {
            ans += i;
        }
    }
    return ans;
}

int fast(int n ) {
    int ans = 0;
    for (int i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ans += i;
        }
    }
    for (int i = n; i >= sqrt(n); --i) {
        if (n % i == 0) {
            ans += i;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << brute(12) << endl; // 28 // O(n)
    cout << brute(15) << endl; // 24
    cout << endl;
    cout << fast(12) << endl; // 28 O(sqrt(n))
    cout << fast(15) << endl; // 24
}
