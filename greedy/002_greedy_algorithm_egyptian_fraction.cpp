#include "../template.hpp"

void EgyptianFraction(int nr, int dr) {
    if (nr == 0 or dr == 0) {
        return;
    }
    if (dr % nr == 0) {
        cout << '1' << '/' << dr / nr;
        return;
    }
    if (nr % dr == 0) {
        cout << nr / dr;
        return;
    }
    if (nr > dr) {
        cout << nr / dr << '+';
        EgyptianFraction(nr % dr, dr);
        return;
    }
    int n = dr / nr + 1;
    cout << '1' << '/' << n << '+';
    EgyptianFraction(nr * n - dr, dr * n);
}

int main() { TimeMeasure _;
    EgyptianFraction(2, 3); cout << '\n';
    EgyptianFraction(6, 14); cout << '\n';
    EgyptianFraction(12, 13); cout << '\n';
}
