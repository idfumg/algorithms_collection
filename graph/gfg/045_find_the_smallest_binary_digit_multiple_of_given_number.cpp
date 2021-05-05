#include "../../template.hpp"

int SmallestBinary(int n) {
    qi q;
    q.push(1);

    while (not q.empty()) {
        int at = q.front(); q.pop();
        if (at % n == 0) return at;
        q.push(at * 10 + 0);
        q.push(at * 10 + 1);
    }

    return -1;
}

int main() { TimeMeasure _;
    cout << SmallestBinary(2) << endl; // 10
    cout << SmallestBinary(17) << endl; // 11101
}
