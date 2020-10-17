#include "../../template.hpp"

void tab2(int w, int m, int n) {
    int smalln = w / m, largen = w / n;
    int anssmall = 0, anslarge = -INF, answ = INF;
    for (int j = smalln; j >= 0; --j) {
        for (int k = largen; k >= 0; --k) {
            int occupied = j * m + k * n;
            int space = w - occupied;
            if (space >= 0) {
                if (space < answ or (space == answ and anslarge < k)) {
                    answ = space;
                    anssmall = j;
                    anslarge = k;
                }
            }
        }
    }
    cout << anssmall << ' ' << anslarge << ' ' << answ << '\n';
}

int main() { TimeMeasure _;
    tab2(24, 3, 5); // 3 3 0
    tab2(29, 3, 9); // 0 3 2
    tab2(24, 4, 7); // 6 0 0
    tab2(28, 4, 7); // 0 4 0
    tab2(7, 3, 5); // 2 0 1
}
