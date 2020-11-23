#include "../../template.hpp"

double GcdOfFloatingPointNumbers(double a, double b) {
    if (a < b) return GcdOfFloatingPointNumbers(b, a);
    if (fabs(b) < 0.001) return a;
    return GcdOfFloatingPointNumbers(b, a - floor(a / b) * b);
}

int main() { TimeMeasure _; __x();
    cout << GcdOfFloatingPointNumbers(0.3, 0.9) << endl; // 0.3
    cout << GcdOfFloatingPointNumbers(0.48, 0.108) << endl; // 0.012
}
