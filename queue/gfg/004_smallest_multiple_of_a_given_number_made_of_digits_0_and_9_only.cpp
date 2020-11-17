#include "../../template.hpp"

int FindSmallestMultiple(int n) {
    queue<int> q;
    q.push(9);
    while (not q.empty()) {
        int at = q.front(); q.pop();
        if (at % n == 0) {
            return at;
        }
        for (int adj : {0, 9}) {
            q.push(at * 10 + adj);
        }
    }
    return - 1;
}

int main() { TimeMeasure _;
    cout << FindSmallestMultiple(5) << endl; // 90 // O(n)
    cout << FindSmallestMultiple(7) << endl; // 9009
}
