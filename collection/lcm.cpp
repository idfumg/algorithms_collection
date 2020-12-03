#include "../template.hpp"

int lcm(int a, int b) {
    return (a * b) / std::gcd(a, b);
}

int lcm2(int a, int b) {
    return std::lcm(a, b);
}

int main() { TimeMeasure _;
    cout << lcm(15, 20) << endl; // 60
    cout << lcm(5, 7) << endl; // 35
    cout << endl;
    cout << lcm2(15, 20) << endl; // 60
    cout << lcm2(5, 7) << endl; // 35
}
