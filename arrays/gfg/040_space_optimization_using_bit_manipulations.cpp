#include "../../template.hpp"

void SetBit(vi& digits, int idx) {
    digits[idx / 32] |= (1 << (idx & 31));
}

bool CheckBit(vi& digits, int idx) {
    return digits[idx / 32] & (1 << (idx & 31));
}

void MultipliesOf2And5(int a, int b) {
    int n = ceil(abs(b - a) / 32);
    vi digits(n + 1);

    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0 or i % 5 == 0) {
            SetBit(digits, i - a);
        }
    }

    for (int i = a; i <= b; ++i) {
        if (CheckBit(digits, i - a)) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    MultipliesOf2And5(2, 10); // 2 3 4 5 6 7 8 9 10
    MultipliesOf2And5(60, 95); // 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95
}
