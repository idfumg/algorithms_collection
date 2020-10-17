#include "../../template.hpp"

int ChooseDigit(int sum, int count) {
    int remainingSum = count * 9, digit = 1;
    while (remainingSum < sum - digit) {
        ++digit;
    }
    return digit;
}

void SmallestNumWithDigitsAndSum(int sum, int d) {
    if (9 * d < sum) {
        cout << -1 << '\n';
        return;
    }
    while (d-- > 0) {
        int digit = ChooseDigit(sum, d);
        sum -= digit;
        cout << digit;
    }
    cout << '\n';
}

int main() { TimeMeasure _; __x();
     SmallestNumWithDigitsAndSum(9, 2); // 18
     SmallestNumWithDigitsAndSum(20, 3); // 299
     SmallestNumWithDigitsAndSum(28, 3); // -1
}
