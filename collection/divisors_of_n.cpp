#include "../template.hpp"

vi FindDivisors(int n) {
    vi ans;
    for (int i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
        }
    }
    for (int i = n; i >= sqrt(n); --i) {
        if (n % i == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << FindDivisors(2) << endl;
    cout << FindDivisors(3) << endl;
}
