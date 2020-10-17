#include "../../template.hpp"

static vi denoms = {2000, 500, 200, 100, 50, 20, 10, 5, 1};

int MinNumberOfNotes(int n) {
    int ans = 0;
    for (int denom : denoms) {
        int count = n / denom;
        ans += count;
        n -= count * denom;
        if (n == 0) break;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << MinNumberOfNotes(800) << '\n';
    cout << MinNumberOfNotes(2456) << '\n';
}
