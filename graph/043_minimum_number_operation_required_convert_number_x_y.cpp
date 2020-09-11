#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

struct Cell {
    int num;
    int dist;
};

int MinimumOpsToTransfrom(int from, int to) {
    unordered_set<int> visited;
    deque<Cell> q; q.push_back(Cell{from, 0});

    while (not q.empty()) {
        Cell at = q.front(); q.pop_front();
        if (at.num == to) return at.dist;
        visited.insert(at.num);
        if (not visited.count(at.num * 2)) {
            q.push_back(Cell{at.num * 2, at.dist + 1});
        }
        if (at.num - 1 >= 0 and not visited.count(at.num - 1)) {
            q.push_back(Cell{at.num - 1, at.dist + 1});
        }
    }
    return -1;
}

int main() { TimeMeasure _;
    cout << MinimumOpsToTransfrom(4, 7) << endl; // 2
    cout << MinimumOpsToTransfrom(2, 5) << endl; // 4
}
