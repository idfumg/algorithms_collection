#include "../../template.hpp"

bool CheckIfDivisibleBy3(const string& s) {
    ll sum = 0;
    for (char ch : s) {
        sum += ch - '0';
    }
    return sum % 3 == 0;
}

int main() { TimeMeasure _;
    cout << CheckIfDivisibleBy3("769452") << endl; // 1
    cout << CheckIfDivisibleBy3("123456758933312") << endl; // 0
    cout << CheckIfDivisibleBy3("3635883959606670431112222") << endl; // 1
}
