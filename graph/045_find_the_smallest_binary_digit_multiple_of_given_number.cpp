#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int SmallestBinary(int number) {
    deque<int> q; q.push_back(1);
    while (not q.empty()) {
        int n = q.front(); q.pop_front();
        if (n % number == 0) return n;
        q.push_back(n * 10);
        q.push_back(n * 10 + 1);
    }
    return -1;
}

int main() { TimeMeasure _;
    cout << SmallestBinary(2) << endl;
    cout << SmallestBinary(17) << endl;
}
