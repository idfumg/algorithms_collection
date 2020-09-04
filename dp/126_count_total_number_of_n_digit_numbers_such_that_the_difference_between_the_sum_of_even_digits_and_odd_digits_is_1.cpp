#include "../../template.hpp"

using CurrentEven = int;
using CurrentOdd = int;
using IsEven = bool;

int rec(int n, CurrentEven even, CurrentOdd odd, IsEven isEven, int digits) {
    if (digits == n) return (even - odd == 1);
    int count = 0;
    for (const int number : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        if (isEven) count += rec(n, even + number, odd, false, digits + 1);
        else count += rec(n, even, odd + number, true, digits + 1);
    }
    return count;
}

int rec(int n) {
    int count = 0;
    for (const int number : {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        count += rec(n, number, 0, IsEven{false}, 1);
    }
    return count;
}

int main() { TimeMeasure _; __x();
    cout << rec(2) << endl;
    cout << rec(3) << endl;
}
