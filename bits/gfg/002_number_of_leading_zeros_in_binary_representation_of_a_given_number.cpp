#include "../../template.hpp"

void CountLeadingZeroes(size_t num) {
    static constexpr int n = sizeof(num) * 8 - 1;
    int count = 0;
    for (size_t i = (1ULL << n); i > 0; i /= 2) {
        if (num & i) {
            break;
        }
        else {
            ++count;
        }
    }
    cout << count << '\n';
}

int main() { TimeMeasure _;
    CountLeadingZeroes(131); // 0000000000000000000000000000000000000000000000000000000010000011
    CountLeadingZeroes(7); // 0000000000000000000000000000000000000000000000000000000000000111
    CountLeadingZeroes(8); // 0000000000000000000000000000000000000000000000000000000000001000
    CountLeadingZeroes(-7); // 1111111111111111111111111111111111111111111111111111111111111001
}
