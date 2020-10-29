#include "../../template.hpp"

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

int MinimumOpsToTransfrom2(int x, int y) {
    qi q;
    q.push(x);

    unordered_map<int, int> dist;
    dist[x] = 0;

    while (not q.empty()) {
        int at = q.front(); q.pop();

        for (int adj : {at - 1, at * 2}) {
            if (adj >= 0 and adj <= 2 * y and not dist.count(adj)) {
                dist[adj] = dist[at] + 1;
                q.push(adj);
            }
        }
    }
    return dist[y];
}

int main() { TimeMeasure _;
    cout << MinimumOpsToTransfrom(4, 7) << '\n'; // 2
    cout << MinimumOpsToTransfrom(2, 5) << '\n'; // 4
    cout << MinimumOpsToTransfrom2(4, 7) << '\n'; // 2
    cout << MinimumOpsToTransfrom2(2, 5) << '\n'; // 4
}
