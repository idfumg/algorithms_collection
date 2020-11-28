#include "../../template.hpp"

void OpenClosed(int n) {
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((j + 1) % (i + 1) == 0) {
                arr[j] = !arr[j];
            }
        }
    }
    cout << arr << endl;
}

bool HasEvenNumberOfFactors(int n) {
    // if it's a perfect square the number has odd number of divisors
    int x = sqrt(n);
    return x * x == n;
}

void OpenClosedFast(int n) {
    for (int i = 1; i <= n; ++i) {
        if (HasEvenNumberOfFactors(i)) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    OpenClosed(3); // 1 0 0
    OpenClosed(5); // 1 0 0 1 0
    cout << endl;
    OpenClosedFast(3); // 1 0 0
    OpenClosedFast(5); // 1 0 0 1 0
}
