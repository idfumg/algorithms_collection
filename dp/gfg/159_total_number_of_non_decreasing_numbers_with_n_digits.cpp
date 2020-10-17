#include "../../template.hpp"

bool IsIncreasing(int n) {
    int prev = n % 10;
    n /= 10;
    while (n > 0) {
        if (prev < n % 10) {
            return false;
        }
        prev = n % 10;
        n /= 10;
    }
    return true;
}

int naive(int n) {
    int count = 0, to = pow(10, n) - 1;
    for (int i = 0; i <= to; ++i) {
        if (IsIncreasing(i)) {
            ++count;
        }
    }
    return count;
}

int rec(int n, int prev) {
    if (n == 0) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i <= prev; ++i) {
        count += rec(n - 1, i);
    }
    return count;
}

int rec(int n) {
    int count = 0;
    for (int i = 0; i <= 9; ++i) {
        count += rec(n - 1, i);
    }
    return count;
}

int main() { TimeMeasure _; __x();
    cout << naive(1) << endl; // 10
    cout << naive(2) << endl; // 55
    cout << naive(3) << endl; // 220
    cout << '\n';
    cout << rec(1) << endl;
    cout << rec(2) << endl;
    cout << rec(3) << endl;
}
